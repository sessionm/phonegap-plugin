//
//  SMPortalBarButtonItem.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_PORTAL_BAR_BUTTON_ITEM__
#define __SM_PORTAL_BAR_BUTTON_ITEM__

#import <UIKit/UIKit.h>

/*!
 @class SMPortalBarButtonItem
 @abstract Portal bar button item.
 */
@interface SMPortalBarButtonItem : UIBarButtonItem

/*!
 @property presentingController
 @discussion UIViewController object to use as presenting controller for portal view controller.
 */
@property(nonatomic, strong) UIViewController *presentingController;

/*!
 Returns new instance.
 @result New <code>SMPortalBarButtonItem<code> object
 */
+ (SMPortalBarButtonItem *)newInstance;

@end

#endif /* __SM_PORTAL_BAR_BUTTON_ITEM__ */
