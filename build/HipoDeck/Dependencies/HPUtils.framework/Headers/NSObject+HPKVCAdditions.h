//
//  NSObject+HPKVCAdditions.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//

/** NSObject category for adding utility methods that can fetch the proper
 * data types from any NSObject subclass
 */
@interface NSObject (NSObject_HPKVCAdditions)

/** Fetches a non-null value for the given key. If the key exists but is set
 * to an NSNull instance, it's converted to nil
 * 
 * @param aKey Key to be fetched
 */
- (id)nonNullValueForKey:(NSString *)aKey;

/** Fetches a non-nil value for the given key. If the value for the given key 
 * is nil, it's converted to NSNull
 * 
 * @param aKey Key to be fetched
 */
- (id)nonNilValueForKey:(NSString *)aKey;

/** Fetches the value for the given key and converts it to an NSURL instance
 * 
 * @param aKey Key to be fetched
 */
- (NSURL *)URLValueForKey:(NSString *)aKey;

/** Fetches the value for the given key and converts it to NSInteger
 * 
 * @param aKey Key to be fetched
 */
- (NSInteger)integerValueForKey:(NSString *)aKey;

/** Fetches the value for the given key and converts it to CGFloat
 * 
 * @param aKey Key to be fetched
 */
- (CGFloat)CGFloatValueForKey:(NSString *)aKey;

/** Fetches the value for the given key and converts it to NSTimeInterval
 * 
 * @param aKey Key to be fetched
 */
- (NSTimeInterval)timeIntervalValueForKey:(NSString *)aKey;

/** Fetches the value for the given key and converts it to an NSDate instance
 * using the default date format Fri, 10 Sep 2010 07:44:06 -0000
 * 
 * @param aKey Key to be fetched
 */
- (NSDate *)dateValueForKey:(NSString *)aKey;

/** Fetches the value for the given key and converts it to an NSDate instance
 * using the given time format
 * 
 * @param aKey Key to be fetched
 * @param dateFormat Date format
 */
- (NSDate *)timeValueForKey:(NSString *)aKey 
             withDateFormat:(NSString *)dateFormat;

/** Fetches the value for the given key and converts it to an NSDate instance
 * using the given date format
 * 
 * @param aKey Key to be fetched
 * @param dateFormat Date format
 */
- (NSDate *)dateValueForKey:(NSString *)aKey 
             withDateFormat:(NSString *)dateFormat;

/** Converts the given string value to an NSDate instance using the given 
 * date format
 * 
 * @param string String to be converted
 * @param dateFormat Date format
 */
- (NSDate *)dateValueFromString:(NSString *)string 
                 withDateFormat:(NSString *)dateFormat;

/** Fetches the NSTimeInterval value for the given key and converts it to an 
 * NSDate instance using the UNIX epoch
 * 
 * @param aKey Key to be fetched
 */
- (NSDate *)dateValueForTimeIntervalKey:(NSString *)aKey;

/** Fetches the hex value for the given key and converts it to a UIColor instance
 * 
 * @param aKey Key to be fetched
 */
- (UIColor *)colorValueWithHexStringForKey:(NSString *)aKey;

@end
