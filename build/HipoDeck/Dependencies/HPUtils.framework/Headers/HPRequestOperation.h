//
//  HPRequestOperation.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


typedef enum {
	HPRequestMethodGet,
	HPRequestMethodPost,
	HPRequestMethodPut,
	HPRequestMethodDelete
} HPRequestMethod;

typedef enum {
    HPRequestOperationPostTypeForm,
    HPRequestOperationPostTypeJSON,
    HPRequestOperationPostTypeFile,
} HPRequestOperationPostType;


extern NSString * const HPRequestOperationMultiPartFormBoundary;


/** A request operation that gets queued and run by [HPRequestManager](HPRequestManager)
 
 This class is an NSOperation wrapper around NSURLConnection that uses blocks 
 to communicate with its delegates. Provides easy access to all kinds of HTTP 
 calls, authentication methods, custom parsing, progress and completion handling.
 It can also be identified and cancelled very easily.
 */
@interface HPRequestOperation : NSOperation {
@private
	HPRequestMethod _requestMethod;
    HPRequestOperationPostType _postType;
    
    NSMutableSet *_cookies;
    NSMutableSet *_completionBlocks;
	NSURLConnection *_connection;
    NSMutableData *_loadedData;
	NSURLResponse *_response;
    NSIndexPath *_indexPath;
    NSString *_identifier;
	NSData *_requestData;
	NSString *_MIMEType;
	NSURL *_requestURL;
	
	long long _expectedSize;
	
	BOOL _isCached;
	BOOL _isExecuting;
	BOOL _isCancelled;
	BOOL _isFinished;
    
    id (^_parserBlock)(NSData *, NSString *);
    void (^_uploadProgressBlock)(float progress);
    void (^_progressBlock)(float);
}

/** NSString identifier for this operation
 
 This property can be used to cancel load operations for specific actions.
 */
@property (nonatomic, copy) NSString *identifier;

/** NSIndexPath identifier for this operation
 
 This can be used to cancel load operations for specific UITableView rows as 
 the scroll view is moving.
 */
@property (nonatomic, copy) NSIndexPath *indexPath;

/** Type of POST operation attached to this request
 
 Value of this property determines the Content-Type header for the request. 
 Available options are:
 
 * HPRequestOperationPostTypeForm: Form post type, uses Content-Type 
 application/x-www-form-urlencoded
 * HPRequestOperationPostTypeJSON: JSON post type, uses Content-Type 
 application/json
 * HPRequestOperationPostTypeFile: File post type, uses Content-Type 
 multipart/form-data
 
 Default value is HPRequestOperationPostTypeForm.
 */
@property (nonatomic, assign) HPRequestOperationPostType postType;

/** Parser block for this request operation
 
 This can be any piece of code that takes the loadedData and its MIMEType, and 
 returns an object parsed from the incoming data. By default, 
 [HPRequestManager](HPRequestManager) will set this property to a JSON parser 
 block that will convert the data to a JSON object.
 */
@property (nonatomic, copy) id (^parserBlock)(NSData *loadedData, NSString *MIMEType);

/** Upload progress block for this request operation
 
 If set, this block will get called with the progress of the upload operation 
 whenever the NSURLConnection reports an update. Value of the progress parameter 
 will be between 0.0 and 1.0
 */
@property (nonatomic, copy) void (^uploadProgressBlock)(float progress);

/** Progress block for this request operation
 
 If set, this block will get called with the progress of the download operation 
 whenever the NSURLConnection reports an update. Value of the progress parameter 
 will be between 0.0 and 1.0
 */
@property (nonatomic, copy) void (^progressBlock)(float progress);

/** Returns an autoreleased request operation
 
 See initWithURL:data:method:cached: for more details.

 @param url NSURL that determines the target URL
 @param data Optional NSData attribute for uploading data with the request
 @param method Method type for this request, available options are:
 
 * HPRequestMethodGet: Request method GET
 * HPRequestMethodPost: Request method POST
 * HPRequestMethodPut: Request method PUT
 * HPRequestMethodDelete: Request method DELETE
 
 @param cached Boolean that determines whether the response to this request 
 should be cached. Passing YES to this parameter will also make the operation 
 check for an available cached item for this request before starting.
 */
+ (HPRequestOperation *)requestForURL:(NSURL *)url 
                             withData:(NSData *)data 
                               method:(HPRequestMethod)method 
                               cached:(BOOL)cached;

/** Initializes a request operation
 
 @param url NSURL that determines the target URL
 @param data Optional NSData attribute for uploading data with the request
 @param method Method type for this request, available options are:

 * HPRequestMethodGet: Request method GET
 * HPRequestMethodPost: Request method POST
 * HPRequestMethodPut: Request method PUT
 * HPRequestMethodDelete: Request method DELETE
 
 @param cached Boolean that determines whether the response to this request 
 should be cached. Passing YES to this parameter will also make the operation 
 check for an available cached item for this request before starting.
 */
- (id)initWithURL:(NSURL *)url 
             data:(NSData *)data 
           method:(HPRequestMethod)method 
           cached:(BOOL)cached;

/** Adds a completion block for this operation
 
 Request operations can have more than one completion block. A block that will 
 be called when this operation is complete can be added using this method.
 
 @param block A completion block that receives the resource object and an 
 NSError instance
 */
- (void)addCompletionBlock:(void(^)(id resources, NSError *error))block;

/** Adds a cookie for this request
 
 In rare cases when cookies are required for authentication or for other 
 purposes, this method can be used to add an NSString cookie header to the request
 
 @param cookie A valid HTTP cookie that will get appended to the Cookie header
 */
- (void)addCookie:(NSString *)cookie;

@end
