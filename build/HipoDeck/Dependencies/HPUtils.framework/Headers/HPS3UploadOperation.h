//
//  HPS3UploadOperation.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-21.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@interface HPS3UploadOperation : NSOperation {
@private
    NSMutableSet *_completionBlocks;
	NSURLConnection *_connection;
    NSMutableData *_loadedData;
	NSURLResponse *_response;
	NSString *_MIMEType;

	BOOL _isExecuting;
	BOOL _isCancelled;
	BOOL _isFinished;

    id (^_parserBlock)(NSData *, NSString *);
}

@property (nonatomic, copy) id (^parserBlock)(NSData *, NSString *);

+ (HPS3UploadOperation *)uploadOperationWithData:(NSData *)fileData 
                                        MIMEType:(NSString *)MIMEType 
                                       forBucket:(NSString *)bucket 
                                            path:(NSString *)path 
                                   withAccessKey:(NSString *)accessKey 
                                          secret:(NSString *)secret;

- (id)initWithData:(NSData *)fileData 
          MIMEType:(NSString *)MIMEType 
         forBucket:(NSString *)bucket 
              path:(NSString *)path 
     withAccessKey:(NSString *)accessKey 
            secret:(NSString *)secret;

- (void)addCompletionBlock:(void(^)(id resources, NSError *error))block;

@end
