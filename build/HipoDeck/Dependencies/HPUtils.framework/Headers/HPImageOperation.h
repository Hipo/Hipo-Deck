//
//  HPImageOperation.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


typedef enum {
	HPImageFormatPNG,
	HPImageFormatJPEG,
} HPImageFormat;

typedef enum {
	HPImageOperationOutputFormatImage,
	HPImageOperationOutputFormatRawData,
} HPImageOperationOutputFormat;


/** An image operation that gets queued and run by [HPRequestManager](HPRequestManager)
 
 This is an NSOperation subclass that's capable of resizing a given image file 
 according to target dimensions and a scaling method, caching the resulting 
 image using [HPCacheManager](HPCacheManager) and returning it either as raw 
 data or as a UIImage instance.
 */
@interface HPImageOperation : NSOperation {
@private
	CGSize _targetSize;
	NSString *_cacheKey;
	UIImage *_sourceImage;
	NSIndexPath *_indexPath;
	HPImageFormat _imageFormat;
	UIViewContentMode _contentMode;
	NSMutableSet *_completionBlocks;	
	HPImageOperationOutputFormat _outputFormat;
    NSString *_identifier;
    NSString *_storageKey;
    
    BOOL _storePermanently;
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
@property (nonatomic, copy) NSString *storageKey;
@property (nonatomic, assign) HPImageOperationOutputFormat outputFormat;
@property (nonatomic, assign) BOOL storePermanently;

/** Generates a cache key with the given options
 
 Class method for generating a unique cache key for a URL hash, with the target 
 size, content mode and image format.
 
 @param hash A unique NSString hash that can be generated from the image URL
 @param targetSize Target dimensions for scaling
 @param contentMode Scaling mode, available options are:
 
 * UIViewContentModeScaleAspectFit: Scale to fit into the dimensions, this 
 approach might leave empty areas around the image
 * UIViewContentModeScaleAspectFill: Scale to fill the target dimensions, this 
 approach might crop the image
 
 @param format Image format, available options are:
 
 * HPImageFormatJPEG: JPEG
 * HPImageFormatPNG: PNG
 */
+ (NSString *)cacheKeyWithHash:(NSString *)hash 
                    targetSize:(CGSize)targetSize 
                   contentMode:(UIViewContentMode)contentMode 
                   imageFormat:(HPImageFormat)format;

/** Initializes an image operation
 
 Initializes the operation for scaling the given image.
 
 @param image UIImage instance to be processed
 @param targetSize Target dimensions for scaling
 @param contentMode Scaling mode, available options are:
 
 * UIViewContentModeScaleAspectFit: Scale to fit into the dimensions, this 
 approach might leave empty areas around the image
 * UIViewContentModeScaleAspectFill: Scale to fill the target dimensions, this 
 approach might crop the image
 
 @param cacheKey A unique cache key, if not nil, the image will be cached 
 using this key
 @param format Image format, available options are:
 
 * HPImageFormatJPEG: JPEG
 * HPImageFormatPNG: PNG
 */
- (id)initWithImage:(UIImage *)image 
         targetSize:(CGSize)targetSize 
        contentMode:(UIViewContentMode)contentMode 
           cacheKey:(NSString *)cacheKey 
        imageFormat:(HPImageFormat)format;

/** Adds a completion block for this operation
 
 Image operations can have more than one completion block. A block that will 
 be called when this operation is complete can be added using this method.
 
 @param block A completion block that receives the resource object and an 
 NSError instance
 */
- (void)addCompletionBlock:(void(^)(id resources, NSError *error))block;

@end
