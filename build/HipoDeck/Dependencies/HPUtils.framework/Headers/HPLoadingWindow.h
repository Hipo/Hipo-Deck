//
//  HPLoadingWindow.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-19.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


typedef enum {
	HPLoadingWindowStyleFullScreen,
	HPLoadingWindowStyleNonBlocking
} HPLoadingWindowStyle;


@interface HPLoadingWindow : UIWindow {
@private
	UILabel *_statusLabel;
	UIImageView *_statusIcon;
	UIActivityIndicatorView *_loadingIndicator;
	UIView *_shieldView;
	UIView *_backgroundView;
	
	BOOL _animating;
	
	HPLoadingWindowStyle _displayStyle;
}

+ (HPLoadingWindow *)sharedInstance;

- (void)startAnimatingWithMessage:(NSString *)message style:(HPLoadingWindowStyle)style;
- (void)stopAnimatingWithMessage:(NSString *)message success:(BOOL)success;
- (void)continueAnimatingWithMessage:(NSString *)message;
- (void)displayConfirmationWithMessage:(NSString *)message;
- (void)hideConfirmation;

@end
