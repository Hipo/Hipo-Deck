//
//  HPCacheManager.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


/** Cache item object stored by the [HPCacheManager](HPCacheManager)
 
 This is a wrapper around the cache data stored by the cache manager. It also 
 includes info on its MIME type and exact path in the file system.
 */
@interface HPCacheItem : NSObject {
@private
	NSData *_cacheData;
	NSDate *_timeStamp;
	NSString *_MIMEType;
	NSString *_cachePath;
}

/** NSData instance with the contents of the cache
 */
@property (nonatomic, retain, readonly) NSData *cacheData;

/** Time stamp for the storage time of the cache object
 */
@property (nonatomic, retain, readonly) NSDate *timeStamp;

/** MIME type for the stored file
 */
@property (nonatomic, retain, readonly) NSString *MIMEType;

/** Path for the cache object
 */
@property (nonatomic, retain, readonly) NSString *cachePath;

/** Generates a cache item from an NSDictionary
 
 @param pickle NDictionary that contains cache parameters
 
 @returns An autoreleased HPCacheItem instance
 */
+ (HPCacheItem *)cacheItemWithPickledObject:(NSDictionary *)pickle;

/** Generates a cache item from components
 
 @param data NSData with cache contents
 @param path File system path for the cache file
 @param type MIME type for the cached file
 @param stamp Timestamp of storage
 
 @returns An autoreleased HPCacheItem instance
 */
+ (HPCacheItem *)cacheItemWithCacheData:(NSData *)data 
                                   path:(NSString *)path 
                               MIMEType:(NSString *)type 
                                  stamp:(NSDate *)stamp;

- (id)initWithPickledObject:(NSDictionary *)pickle;
- (id)initWithCacheData:(NSData *)data 
                   path:(NSString *)path 
               MIMEType:(NSString *)type 
                  stamp:(NSDate *)stamp;

/** Generates an NSDictionary object with cache item parameters
 
 @returns An NSDictionary instance that can be used for file system storage
 */
- (NSDictionary *)pickledObjectForArchive;

@end


/** Custom cache manager for storing cached items on disk
 
 This is an alternative cache manager that injects itself into the shared URL 
 cache routines to store some responses on disk instead of live memory. This 
 allows images and other long-term data to be stored in a temporary directory 
 so they can persist across app launches and memory warnings.
 
 [HPRequestManager](HPRequestManager) uses HPCacheManager behind the scenes and 
 no direct interaction is necessary unless access to the cache database is 
 necessary.
 */
@interface HPCacheManager : NSObject {
@private
	NSString *_cacheDirectoryPath;
	NSString *_storageDirectoryPath;
	NSOperationQueue *_saveQueue;
}

/** Returns the shared instance of the cache manager
 
 You should always use this call and never instantiate the HPCacheManager.
 
 @returns HPCacheManager shared instance
 */
+ (HPCacheManager *)sharedManager;

/** Finds the permanently stored cache item associated with a given storage key
 
 @param storageKey Storage key to search for
 
 @returns HPCacheItem instance for the storage key
 */
- (HPCacheItem *)storedItemForStorageKey:(NSString *)storageKey;

/** Permanently stores an NSData and MIMEType combination for a given storage key
 
 @param storageData NSData to be stored
 @param storageKey Storage key for identification
 @param MIMEType MIME type of the stored file
 */
- (void)storeData:(NSData *)storageData 
    forStorageKey:(NSString *)storageKey 
     withMIMEType:(NSString *)MIMEType;

/** Finds a temporary cache item associated with a given cache key
 
 @param cacheKey Cache key to search for
 
 @returns HPCacheItem instance for the cache key
 */
- (HPCacheItem *)cachedItemForCacheKey:(NSString *)cacheKey;

/** Temporarily caches an NSData and MIMEType combination for a given cache key
 
 @param cacheData NSData to be cached
 @param cacheKey Cache key for identification
 @param MIMEType MIME type of the cached file
 */
- (void)cacheData:(NSData *)cacheData 
      forCacheKey:(NSString *)cacheKey 
     withMIMEType:(NSString *)MIMEType;

/** Finds a temporary cache item associated with a given URL
 
 @param url URL to search for
 
 @returns HPCacheItem instance for the URL
 */
- (HPCacheItem *)cachedItemForURL:(NSURL *)url;

/** Temporarily caches an NSData and MIMEType combination for a given URL
 
 @param cacheData NSData to be cached
 @param url URL for identification
 @param MIMEType MIME type of the cached file
 */
- (void)cacheData:(NSData *)cacheData 
           forURL:(NSURL *)url 
     withMIMEType:(NSString *)MIMEType;

/** Clears a cached item for a given cache key

 @param cacheKey Cache key to clear
 */
- (void)clearCacheForCacheKey:(NSString *)cacheKey;

/** Clears a cached item for a given URL
 
 @param url URL to clear
 */
- (void)clearCacheForURL:(NSURL *)url;

@end
