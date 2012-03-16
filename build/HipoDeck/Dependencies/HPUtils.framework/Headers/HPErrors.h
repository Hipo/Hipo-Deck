//
//  HPErrors.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


static NSString * const kHPErrorDomain = @"com.hippofoundry.HPUtils.ErrorDomain";

enum {
    kHPNetworkErrorCode = -1009,
    kHPLocationFailureErrorCode = 100,
    kHPRequestServerFailureErrorCode = 101,
    kHPRequestConnectionFailureErrorCode = 102,
    kHPRequestConnectionCancelledErrorCode = 103,
    kHPRequestParserFailureErrorCode = 104,
    kHPRequestAuthenticationFailureErrorCode = 105,
    kHPLocationDeniedErrorCode = 106,
};
