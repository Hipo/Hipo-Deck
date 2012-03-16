//
//  HPInteractiveView.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-21.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@interface HPInteractiveView : UIView {
@private
    CGAffineTransform _originalTransform;
    CFMutableDictionaryRef _touchBeginPoints;
}

@end
