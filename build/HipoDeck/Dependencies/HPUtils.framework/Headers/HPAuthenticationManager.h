//
//  HPAuthenticationManager.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-20.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//

extern NSString * const HPAuthenticationManagerUsernameKey;
extern NSString * const HPAuthenticationManagerPasswordKey;


@class HPKeychainItem;

/** An authentication manager for storing user credentials
 
 This utility class is a wrapper around the keychain management API provided by 
 Apple. It allows secure storage of a username/password pair and provides an 
 easy way of determining whether the system has an authenticated user or not.
 
 To be able to use this utility, identifiers unique to the application should be 
 set in the Info.plist document for the project:
 
 * HPKeychainIdentifier: Required keychain identifier
 * HPKeychainAccessGroup: Optional access group identifier (for multiple app access)
 
 HPAuthenticationManager is also used by [HPRequestManager](HPRequestManager) to 
 automatically authenticate remote requests using BasicAuth.
 */
@interface HPAuthenticationManager : NSObject {
@private
    HPKeychainItem *_keychainItem;
    
    BOOL _isAuthenticated;
}

/** Returns the shared instance of the authenticated manager
 
 @returns HPAuthenticationManager shared instance
 */
+ (HPAuthenticationManager *)sharedManager;

/** Determines whether an authenticated user is stored
 
 @returns Boolean that indicates whether credentials are stored or not
 */
- (BOOL)isAuthenticated;

/** Returns the authenticated user credentials
 
 @returns Dictionary of user credentials
 */
- (NSDictionary *)userCredentials;

/** Removes the stored credentials
 */
- (void)removeUserCredentials;

/** Saves the given user credentials
 
 @param credentials NSDictionary that contains username/password pair that will 
 be stored. These should be identified with the following keys:
 
 * HPAuthenticationManagerUsernameKey: Username
 * HPAuthenticationManagerPasswordKey: Password
 */
- (void)saveUserCredentials:(NSDictionary *)credentials;

/** Updates the stored username
 
 @param username New username that should be stored
 */
- (void)updateUsername:(NSString *)username;

@end
