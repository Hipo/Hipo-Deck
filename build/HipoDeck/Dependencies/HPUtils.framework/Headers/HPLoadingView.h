//
//  HPLoadingView.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@interface HPLoadingView : UIView {
@private
    UIView *_errorView;
    UIView *_contentView;
    UIActivityIndicatorView *_loadIndicator;
}

@property (nonatomic, retain, readonly) UIView *contentView;

- (void)startLoadingAnimated:(BOOL)animated;
- (void)endLoadingWithSuccess:(BOOL)success animated:(BOOL)animated;
- (void)endLoadingWithMessage:(NSString *)message animated:(BOOL)animated;

@end
