//
//  HPEditableTableViewCell.h
//  HPUtils
//
//  Created by Taylan Pince on 11-03-20.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@protocol HPEditableTableViewCellDelegate;

@interface HPEditableTableViewCell : UITableViewCell <UITextFieldDelegate> {
@private
	UITextField *_textField;
	
	id <HPEditableTableViewCellDelegate> delegate;
}

@property (nonatomic, retain, readonly) UITextField *textField;

@property (nonatomic, assign) id <HPEditableTableViewCellDelegate> delegate;

@end


@protocol HPEditableTableViewCellDelegate <NSObject>
@optional
- (void)editableTableViewCell:(HPEditableTableViewCell *)cell didChangeValue:(NSString *)value;
- (void)editableTableViewCellDidBeginEditing:(HPEditableTableViewCell *)cell;
- (void)editableTableViewCellDidEndEditing:(HPEditableTableViewCell *)cell;
- (void)editableTableViewCellDidReturn:(HPEditableTableViewCell *)cell;
- (void)editableTableViewCellDidClear:(HPEditableTableViewCell *)cell;
@end
