//
//  HPDGalleryViewControllerViewController.h
//  HipoDeck
//
//  Created by Taylan Pinçe on 12-03-16.
//  Copyright (c) 2012 Hipo. All rights reserved.
//

#import <HPUtils/HPUtils.h>


@interface HPDGalleryViewControllerViewController : UIViewController <HPScrollViewDataSource> {
@private
    NSInteger _totalImages;
    HPScrollView *_scrollView;
    NSNumberFormatter *_numberFormatter;
}

- (id)initWithTotalNumberOfImages:(NSInteger)totalImages;

@end
