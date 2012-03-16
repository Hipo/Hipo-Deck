//
//  NSString+HPHashAdditions.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@interface NSString (NSString_HPHashAdditions)
- (NSString *)SHA1Hash;
- (NSData *)HMACSHA1withKey:(NSString *)key;
- (NSString *)md5HexDigest;

+ (NSString *)stringWithUUID;
@end
