//
//  NSData+HPBase64Additions.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-21.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSData (NSData_HPBase64Additions)
+ (id)dataWithBase64EncodedString:(NSString *)string;
- (NSString *)base64EncodedString;
@end
