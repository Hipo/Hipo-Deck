//
//  HPScrollView.h
//  HPUtils
//
//  Created by Taylan Pince on 11-04-17.
//  Copyright 2011 Hippo Foundry. All rights reserved.
//


@class HPScrollView;


/** Delegate protocol for [HPScrollView](HPScrollView)
 */
@protocol HPScrollViewDelegate <UIScrollViewDelegate>
@optional
/** Delegate call that gets made when a cell within the scroll view is removed
 
 @param scrollView Active scroll view
 @param pageIndex Index for the removed cell
 */
- (void)scrollView:(HPScrollView *)scrollView didRemovePageWithIndex:(NSInteger)pageIndex;
@end

/** Data source protocol for [HPScrollView](HPScrollView)
 */
@protocol HPScrollViewDataSource <NSObject>
@required
/** Required data source call that should return the total number of cells
 
 @param scrollView Active scroll view
 */
- (NSInteger)numberOfPagesInScrollView:(HPScrollView *)scrollView;

/** Required data source call that should return a UIView instance that will be 
 used for the cell at the given index. Data source object should properly 
 dequeue a recycled cell if possible.
 
 @param scrollView Active scroll view
 @param pageIndex Index for the requested cell
 */
- (UIView *)scrollView:(HPScrollView *)scrollView viewForPageWithIndex:(NSInteger)pageIndex;

/** Required data source call that should return the frame for the given cell index.
 
 @param scrollView Active scroll view
 @param pageIndex Index for the requested cell frame
 */
- (CGRect)scrollView:(HPScrollView *)scrollView frameForPageWithIndex:(NSInteger)pageIndex;
@end


/** Customized UIScrollView that can handle rendering paginated or free-scrolling
 content area with proper cell recycling for memory optimization.
 */
@interface HPScrollView : UIScrollView {
@private
	CGRect *_cellRects;
	NSInteger _totalCells;
	CGRect _visibleBounds;
	UIView *_cellContainer;
    NSIndexSet *_currentIndices;
    NSIndexSet *_insertedIndices;
    NSInteger _horizontalPageIndex;
    UIEdgeInsets _renderEdgeInsets;
    NSMutableSet *_reusablePages;
    NSInteger _identifier;
    
    id <HPScrollViewDataSource> dataSource;
}

/** Edge insets for the rendered area
 
 This property can be used to extend the rendering area outside the bounds of the 
 scroll view.
 */
@property (nonatomic, assign) UIEdgeInsets renderEdgeInsets;

/** Identifier for this scroll view
 */
@property (nonatomic, assign) NSInteger identifier;

/** Delegate for this scroll view
 */
@property (nonatomic, assign) id <HPScrollViewDelegate> delegate;

/** Data source for this scroll view
 */
@property (nonatomic, assign) id <HPScrollViewDataSource> dataSource;

/** Resets the contents of the scroll view by removing all cells
 */
- (void)resetData;

/** Reload the contents of the scroll view by first resetting, then asking the 
 data source for updated number of cells
 */
- (void)reloadData;

/** Removed cells that are not within the visible bounds of the scroll view
 */
- (void)removeHiddenCells;

/** Refreshes the frames for all cells without reloading them
 */
- (void)refreshCellLayout;

/** Refreshes the frames for all visible cells
 */
- (void)refreshVisibleCells;

/** Inserts new cells to the scroll view without reloading or refreshing
 
 @param cellCount Number of cells to insert
 */
- (void)insertCells:(NSInteger)cellCount;

/** Dequeues and returns a recyclable cell from the scroll view cache. If there 
 are no cells available, will return nil.
 */
- (UIView *)dequeueReusablePage;

/** Returns the index of the given cell view
 
 @param cellView Cell view to search
 */
- (NSInteger)indexOfCellView:(UIView *)cellView;

/** Returns the cell view that matches the given index
 
 @param cellIndex Cell index to search
 */
- (UIView *)cellViewWithIndex:(NSInteger)cellIndex;

@end
