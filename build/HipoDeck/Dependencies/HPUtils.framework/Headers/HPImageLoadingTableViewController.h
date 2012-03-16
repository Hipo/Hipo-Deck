//
//  HPImageLoadingTableViewController.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-18.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//

#import "HPLoadingViewController.h"


@interface HPImageLoadingTableViewController : HPLoadingViewController <UITableViewDelegate, UITableViewDataSource> {
@private
    UITableView *_tableView;
    UITableViewStyle _tableStyle;
}

@property (nonatomic, retain, readonly) UITableView *tableView;

- (id)initWithStyle:(UITableViewStyle)style;

@end
