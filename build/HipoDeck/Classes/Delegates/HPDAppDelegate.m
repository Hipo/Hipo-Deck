//
//  HPDAppDelegate.m
//  HipoDeck
//
//  Created by Taylan Pinçe on 12-03-16.
//  Copyright (c) 2012 Hipo. All rights reserved.
//

#import "HPDAppDelegate.h"
#import "HPDGalleryViewControllerViewController.h"


@implementation HPDAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    _window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    _galleryController = [[HPDGalleryViewControllerViewController alloc] initWithTotalNumberOfImages:25];

    [_window addSubview:_galleryController.view];
    [_window setBackgroundColor:[UIColor whiteColor]];
    [_window makeKeyAndVisible];

    return YES;
}

- (void)dealloc {
    [_window release], _window = nil;
    [_galleryController release], _galleryController = nil;

    [super dealloc];
}

@end
