//
//  HPLoadingViewController.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@class HPLoadingView;

@interface HPLoadingViewController : UIViewController {
@private
    HPLoadingView *_loadingView;
}

@property (nonatomic, retain, readonly) UIView *contentView;

- (void)startLoadingAnimated:(BOOL)animated;
- (void)endLoadingWithSuccess:(BOOL)success animated:(BOOL)animated;
- (void)endLoadingWithMessage:(NSString *)message animated:(BOOL)animated;

@end
