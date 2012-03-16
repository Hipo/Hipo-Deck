//
//  UIDevice+HPCapabilityAdditions.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


typedef enum {
    HPDeviceTypeUnknown,
    HPDeviceTypeiPhone1G,
    HPDeviceTypeiPhone3G,
    HPDeviceTypeiPhone3GS,
    HPDeviceTypeiPhone4G,
    HPDeviceTypeiPhone4GS,
    HPDeviceTypeiPodTouch1G,
    HPDeviceTypeiPodTouch2G,
    HPDeviceTypeiPodTouch3G,
    HPDeviceTypeiPodTouch4G,
    HPDeviceTypeiPad1G,
    HPDeviceTypeiPad2G,
    HPDeviceTypeSimulator,
} HPDeviceType;


@interface UIDevice (UIDevice_HPCapabilityAdditions)
- (HPDeviceType)deviceType;
- (NSString *)platformCode;
- (BOOL)canMakePhoneCalls;
- (BOOL)canScanBarcodes;
- (BOOL)isTablet;
@end
