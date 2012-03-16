//
//  NSDate+HPTimeSinceAdditions.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


/** NSDate category for adding a utility method that generates a humanized
 * time difference string
 */
@interface NSDate (NSDate_HPTimeSinceAdditions)

/** Generates a humanized time difference string from an NSDate instance:
 * 2 years ago
 * A month ago
 * 5 days ago
 * An hour ago
 * 2 minutes ago
 * Just now
 */
- (NSString *)stringWithHumanizedTimeDifference;

@end
