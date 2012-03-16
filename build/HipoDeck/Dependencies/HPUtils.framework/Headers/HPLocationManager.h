//
//  HPLocationManager.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>


/** A custom location manager for determining user coordinates
 
 This is a light wrapper around CLLocationManager that adds some caching 
 capabilities and intelligence to the way location results are reported. At a 
 very basic level, HPLocationManager allows different parts of a single app to 
 use the same location requests and get the most accurate data possible without 
 having to wait for too long. It also follows a graceful degradation routine in 
 order to fetch the most accurate location in as little time as possible.
 */
@interface HPLocationManager : NSObject <CLLocationManagerDelegate> {
@private
	NSDate *_queryStartTime;
	NSMutableSet *_executionBlocks;
	CLLocationManager *_locationManager;
    CLLocationAccuracy _desiredAccuracy;
    double _intervalModifier;
}

/** Desired accuracy for the location requests
 
 This value will be passed directly to the CLLocationManager instance for the 
 accuracy option. By default it's kCLLocationAccuracyNearestTenMeters.
 */
@property (nonatomic, assign) CLLocationAccuracy desiredAccuracy;
@property (nonatomic, assign) double intervalModifier;

/** Returns the shared instance of the location manager
 
 You should always use this method and never instantiate the manager yourself.
 
 @returns HPLocationManager shared instance
 */
+ (HPLocationManager *)sharedManager;

/** Refreshes the location cache without a completion block
 */
- (void)refreshLocation;

/** Cancels all ongoing location queries
 */
- (void)cancelLocationQuery;

/** Refreshes the location cache and calls the execution block when done
 
 @param block Execution block that will get called when the query is done
 */
- (void)getLocationWithExecutionBlock:(void (^)(CLLocation *, NSError *))block;

@end
