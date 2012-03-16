//
//  HPWebViewController.h
//  HPUtils
//
//  Created by Taylan Pince on 11-04-26.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@protocol HPWebViewControllerDelegate;

@interface HPWebViewController : UIViewController <UIWebViewDelegate> {
@private
	NSURL *_url;
    UIWebView *_webView;
    UIActivityIndicatorView *_loadIndicator;
    
    BOOL _loadInProgress;
	
	id <HPWebViewControllerDelegate> delegate;
}

@property (nonatomic, assign) id <HPWebViewControllerDelegate> delegate;

- (id)initWithURL:(NSURL *)url;

@end


@protocol HPWebViewControllerDelegate
- (void)webViewControllerDidClose:(HPWebViewController *)controller;
@end
