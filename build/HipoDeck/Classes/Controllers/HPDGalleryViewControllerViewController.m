//
//  HPDGalleryViewControllerViewController.m
//  HipoDeck
//
//  Created by Taylan Pinçe on 12-03-16.
//  Copyright (c) 2012 Hipo. All rights reserved.
//

#import "HPDGalleryViewControllerViewController.h"


@interface HPDGalleryViewControllerViewController (Private)

@end


@implementation HPDGalleryViewControllerViewController

- (id)initWithTotalNumberOfImages:(NSInteger)totalImages {
    self = [super initWithNibName:nil bundle:nil];

    if (self) {
        _totalImages = totalImages;
        _numberFormatter = [[NSNumberFormatter alloc] init];
        
        [_numberFormatter setFormatWidth:3];
        [_numberFormatter setPaddingCharacter:@"0"];
    }
    
    return self;
}

- (void)dealloc {
    [_numberFormatter release], _numberFormatter = nil;
    [_scrollView release], _scrollView = nil;
    
    [super dealloc];
}

#pragma mark - View lifecycle

- (void)loadView {
    UIView *mainView = [[UIView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    [mainView setAutoresizingMask:(UIViewAutoresizingFlexibleWidth | 
                                   UIViewAutoresizingFlexibleHeight)];
    
    _scrollView = [[HPScrollView alloc] initWithFrame:mainView.bounds];
    
    [_scrollView setAutoresizingMask:mainView.autoresizingMask];
    [_scrollView setDataSource:self];
    
    [mainView addSubview:_scrollView];
    
    self.view = mainView;
    
    [mainView release];
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)viewDidUnload {
    [_scrollView release], _scrollView = nil;

    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
	return UIInterfaceOrientationIsLandscape(interfaceOrientation);
}

#pragma mark - Scroll view data source

- (NSInteger)numberOfPagesInScrollView:(HPScrollView *)scrollView {
    return _totalImages;
}

- (UIView *)scrollView:(HPScrollView *)scrollView viewForPageWithIndex:(NSInteger)pageIndex {
    UIImageView *imageView = (UIImageView *)[scrollView dequeueReusablePage];
    
    if (imageView == nil) {
        imageView = [[[UIImageView alloc] initWithFrame:CGRectZero] autorelease];
    }
    
    NSString *fileName = [NSString stringWithFormat:@"%@.png", 
                          [_numberFormatter stringFromNumber:
                           [NSNumber numberWithInteger:(pageIndex + 1)]]];
    NSLog(@"LOAD: %@", fileName);
    [imageView setImage:[UIImage imageNamed:fileName]];
    
    return imageView;
}

- (CGRect)scrollView:(HPScrollView *)scrollView frameForPageWithIndex:(NSInteger)pageIndex {
    CGSize imageSize = scrollView.bounds.size;
    
    return CGRectMake(imageSize.width * pageIndex, 0.0, imageSize.width, imageSize.height);
}

@end
