//
//  UITouch+HPTouchSorting.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-21.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UITouch (UITouch_HPTouchSorting)
- (NSComparisonResult)compareAddress:(id)obj;
@end
