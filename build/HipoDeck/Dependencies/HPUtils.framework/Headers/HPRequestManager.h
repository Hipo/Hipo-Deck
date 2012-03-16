//
//  HPAPIManager.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//

#import "HPImageOperation.h"
#import "HPRequestOperation.h"
#import "HPS3UploadOperation.h"


extern NSString * const HPNetworkStatusChangeNotification;


@class HPReachabilityManager;

/** Common manager class that handles all network communication, reachability 
 and image processing tasks. Contains two operation queues that execute 
 [HPImageOperation](HPImageOperation) and [HPRequestOperation](HPRequestOperation) 
 subclasses.
 */
@interface HPRequestManager : NSObject {
@private
    NSOperationQueue *_requestQueue;
    NSOperationQueue *_processQueue;
    
    HPReachabilityManager *_reachabilityManager;
    
    BOOL _networkConnectionAvailable;
}

/** Returns the shared instance of the request manager
 
 You should always use this call and never instantiate the HPRequestManager.
 
 @returns HPRequestManager shared instance
 */
+ (HPRequestManager *)sharedManager;

/** Returns network availability info
 
 @returns Boolean that determines whether a network connection is available
 */
- (BOOL)isNetworkConnectionAvailable;

/** Cancels all running and queued operations
 */
- (void)cancelAllOperations;

/** Cancels all running and queued operations that match an identifier
 
 You can use this call to cancel a subset of active and queued operations. This 
 method will check both the request and process queues and cancel all operations 
 that match the identifier. You can use [HPRequestOperation](HPRequestOperation)'s 
 identifier attribute determine an identifier when you are creating a request.
 
 @param identifier NSString that will be used to identify operations
 */
- (void)cancelOperationsWithIdentifier:(NSString *)identifier;

/** Returns all running and queued request operations
 
 @returns An array of active [HPRequestOperation](HPRequestOperation) subclasses
 */
- (NSArray *)activeRequestOperations;

/** Returns all running and queued process operations
 
 @returns An array of active [HPImageOperation](HPImageOperation) subclasses
 */
- (NSArray *)activeProcessOperations;

- (void)loadImageAtURL:(NSString *)imageURL 
		 withIndexPath:(NSIndexPath *)indexPath 
	   completionBlock:(void (^)(id, NSError *))block 
			scaleToFit:(CGSize)targetSize 
		   contentMode:(UIViewContentMode)contentMode;

- (void)loadImageAtURL:(NSString *)imageURL 
		 withIndexPath:(NSIndexPath *)indexPath 
			scaleToFit:(CGSize)targetSize 
		   contentMode:(UIViewContentMode)contentMode
	   completionBlock:(void (^)(id, NSError *))block;

/** Loads an image from the given URL and calls the completion block
 
 This method can be used to load a remote image resource at the given URL and 
 to scale it to fit the given dimensions.
 
 @param imageURL NSString URL for the image resource
 @param indexPath An optional indexPath identifier for the operation
 @param identifier An optional NSString identifier for the operation
 @param targetSize Target dimensions for image processing. To disable image 
 resizing, pass CGSizeZero. Values will be automatically converted for 
 retina display.
 @param contentMode Scaling strategy for image processing. Options are:

 * UIViewContentModeScaleAspectFit: Scale to fit into the dimensions, this 
 approach might leave empty areas around the image
 * UIViewContentModeScaleAspectFill: Scale to fill the target dimensions, this 
 approach might crop the image
 
 @param block Completion block that will get called with the final image resource 
    and an NSError instance
 */
- (void)loadImageAtURL:(NSString *)imageURL 
		 withIndexPath:(NSIndexPath *)indexPath 
            identifier:(NSString *)identifier 
			scaleToFit:(CGSize)targetSize 
		   contentMode:(UIViewContentMode)contentMode
	   completionBlock:(void (^)(id resource, NSError *error))block;

- (void)loadStoredImageWithKey:(NSString *)storageKey 
                     indexPath:(NSIndexPath *)indexPath 
               completionBlock:(void (^)(id, NSError *))block 
                    scaleToFit:(CGSize)targetSize 
                   contentMode:(UIViewContentMode)contentMode;

- (void)loadStoredImageWithKey:(NSString *)storageKey 
                     indexPath:(NSIndexPath *)indexPath 
               completionBlock:(void (^)(id, NSError *))block 
                  outputFormat:(HPImageOperationOutputFormat)outputFormat 
                    scaleToFit:(CGSize)targetSize 
                   contentMode:(UIViewContentMode)contentMode;

/** Loads a stored image resource from the local file cache
 
 This method can be used to load an image from the local file cache, while 
 processing it to be resized.
 
 @param storageKey Unique storage identifier for the file
 @param indexPath An optional indexPath identifier for the operation
 @param outputFormat Format for the outputted resource. Options are:
 
 * HPImageOperationOutputFormatImage: UIImage instance
 * HPImageOperationOutputFormatRawData: NSData instance
 
 @param targetSize Target dimensions for image processing. To disable image 
 resizing, pass CGSizeZero. Values will be automatically converted for 
 retina display.
 @param contentMode Scaling strategy for image processing. Options are:
 
 * UIViewContentModeScaleAspectFit: Scale to fit into the dimensions, this 
 approach might leave empty areas around the image
 * UIViewContentModeScaleAspectFill: Scale to fill the target dimensions, this 
 approach might crop the image
 
 @param block Completion block that will get called with the final image resource 
 and an NSError instance
 */
- (void)loadStoredImageWithKey:(NSString *)storageKey 
                     indexPath:(NSIndexPath *)indexPath 
                  outputFormat:(HPImageOperationOutputFormat)outputFormat 
                    scaleToFit:(CGSize)targetSize 
                   contentMode:(UIViewContentMode)contentMode 
               completionBlock:(void (^)(id, NSError *))block;

- (void)resizeImage:(UIImage *)sourceImage 
	   toTargetSize:(CGSize)targetSize 
	   withCacheKey:(NSString *)cacheKey 
	completionBlock:(void (^)(id, NSError *))block;

- (void)resizeImage:(UIImage *)sourceImage 
	   toTargetSize:(CGSize)targetSize 
	   withCacheKey:(NSString *)cacheKey 
       outputFormat:(HPImageOperationOutputFormat)outputFormat 
	completionBlock:(void (^)(id, NSError *))block;

/** Resizes a source image to a target size
 
 This method can be used to resize a given UIImage instance to a target size and 
 optionally cache it with an NSString cache key.
 
 @param sourceImage UIImage instance to be stored
 @param targetSize Target dimensions for image processing. To disable image 
 resizing, pass CGSizeZero. Values will be automatically converted for 
 retina display.
 @param cacheKey NSString key to identify the stored image with
 @param outputFormat Format for the outputted resource. Options are:
 
 * HPImageOperationOutputFormatImage: UIImage instance
 * HPImageOperationOutputFormatRawData: NSData instance

 @param storePermanently Boolean that determines whether the image should be 
 stored in a temporary directory or permanently
 @param block Completion block that will get called with the final image resource 
 and an NSError instance
 */
- (void)resizeImage:(UIImage *)sourceImage 
	   toTargetSize:(CGSize)targetSize 
	   withCacheKey:(NSString *)cacheKey 
       outputFormat:(HPImageOperationOutputFormat)outputFormat 
   storePermanently:(BOOL)storePermanently 
	completionBlock:(void (^)(id, NSError *))block;

/** Utility method for uploading a UIImage instance to an Amazon S3 Bucket
 
 Uploads a UIImage to the specified Amazon S3 bucket, at the given path. Needs 
 S3 access key and secret values.
 
 @param image UIImage instance to be uploaded
 @param bucket S3 bucket name
 @param path Absolute path to upload to inside the S3 bucket
 @param accessKey Amazon S3 access key
 @param secret Amazon S3 access secret
 @param block Completion block that will get called with the final response 
 and an NSError instance
 */
- (void)uploadImageToS3:(UIImage *)image 
               toBucket:(NSString *)bucket 
                 atPath:(NSString *)path 
          withAccessKey:(NSString *)accessKey 
                 secret:(NSString *)secret 
        completionBlock:(void (^)(id, NSError *))block;

- (id)parseJSONData:(NSData *)loadedData;
- (id)parseImageData:(NSData *)loadedData;
- (id)parseStringData:(NSData *)loadedData;

/** Uploads generated crash reports to the Hippo Foundry crash log server
 
 This method should be called at the end of the application:didFinishLaunchingWithOptions: 
 method of the UIApplicationDelegate to upload any available crash reports to the 
 Hippo Foundry crash log center.
 */
- (void)sendAvailableCrashReports;

/** URL encodes an NSString
 
 @param string String to be encoded
 */
- (NSString *)encodeURL:(NSString *)string;

/** Generates NSData from an NSDictionary
 
 Generates an NSData instance that can be used in POST or PUT operations from an 
 NSDictionary object.
 
 @param dict NSDictionary to be encoded
 */
- (NSData *)dataFromDict:(NSDictionary *)dict;

/** Generates multi part data from an NSDictionary
 
 Generates an NSData instance that can be used in a POST or PUT operation with a 
 file upload.
 
 @param dict NSDictionary to be encoded
 @param fileKey Key for the NSData file object that can be found in the dictionary
 @param contentType MIME type for the file
 */
- (NSData *)multiPartDataFromDict:(NSDictionary *)dict 
                      withFileKey:(NSString *)fileKey 
                  fileContentType:(NSString *)contentType;

/** Generates NSData from an NSArray
 
 Generates an NSData instance that can be used in POST or PUT operations from an 
 NSArray object.
 
 @param array NSArray to be encoded
 @param key Property key for the resulting object
 */
- (NSData *)dataFromArray:(NSArray *)array 
                  withKey:(NSString *)key;

/** Utility method for generating query parameters
 
 Generates a full path with URL encoded query parameters from an NSDictionary.
 
 @param basePath NSString path that will be used as the base for the URL
 @param options NSDictionary parameters that will be converted for the query
 */
- (NSString *)pathFromBasePath:(NSString *)basePath 
                   withOptions:(NSDictionary *)options;

/** Utility method for generating query parameters with special keys
 
 Generates a full path with URL encoded query parameters from an NSDictionary, 
 skips special keys during the URL encoding process
 
 @param basePath NSString path that will be used as the base for the URL
 @param options NSDictionary parameters that will be converted for the query
 @param specialKeys Keys to be skipped during the URL encoding process
 */
- (NSString *)pathFromBasePath:(NSString *)basePath 
                   withOptions:(NSDictionary *)options 
                   specialKeys:(NSArray *)specialKeys;

/** Adds an [HPRequestOperation](HPRequestOperation) to the queue
 
 Enqueues an [HPRequestOperation](HPRequestOperation) instance.
 
 @param request Operation to be queued
 */
- (void)enqueueRequest:(HPRequestOperation *)request;

/** Utility method for generating an [HPRequestOperation](HPRequestOperation) 
 that loads a remote image resource
 
 @param urlString Image URL
 */
- (HPRequestOperation *)imageRequestForURL:(NSString *)urlString;

/** Generates an [HPRequestOperation](HPRequestOperation) using a path and a 
 base URL
 
 Utility method for quickly generating an [HPRequestOperation](HPRequestOperation) 
 instance with the given parameters.
 
 @param path Path that will be appended to the base URL
 @param baseURL A base URL for the remote service
 @param data An optional NSData instance that will be sent with the request
 @param method Method type for this request. See [HPRequestOperation](HPRequestOperation)
 @param cached Boolean that determines whether the response to this request is cached
 */
- (HPRequestOperation *)requestForPath:(NSString *)path 
                           withBaseURL:(NSString *)baseURL 
                              withData:(NSData *)data 
                                method:(HPRequestMethod)method 
                                cached:(BOOL)cached;

/** Generates an [HPRequestOperation](HPRequestOperation) using a URL
 
 Utility method for quickly generating an [HPRequestOperation](HPRequestOperation) 
 instance with the given parameters.
 
 @param path Request URL
 @param data An optional NSData instance that will be sent with the request
 @param method Method type for this request. See [HPRequestOperation](HPRequestOperation)
 @param cached Boolean that determines whether the response to this request is cached
 */
- (HPRequestOperation *)requestForURL:(NSURL *)path 
                             withData:(NSData *)data 
                               method:(HPRequestMethod)method 
                               cached:(BOOL)cached;

- (HPS3UploadOperation *)S3UploadOperationWithData:(NSData *)fileData 
                                          MIMEType:(NSString *)MIMEType 
                                         forBucket:(NSString *)bucket 
                                              path:(NSString *)path 
                                     withAccessKey:(NSString *)accessKey 
                                            secret:(NSString *)secret;

@end
