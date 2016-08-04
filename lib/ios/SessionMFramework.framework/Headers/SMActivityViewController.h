//
//  SMActivityViewController.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_ACTIVITY_VIEW_CONTROLLER__
#define __SM_ACTIVITY_VIEW_CONTROLLER__

#import <UIKit/UIKit.h>
#import "SessionM.h"

@class SMActivityViewController;

/*!
 @protocol SMActivityViewControllerDelegate
 @abstract Activity view controller delegate
 */
@protocol SMActivityViewControllerDelegate<NSObject>

@optional

/*!
 @abstract Notifies that controller will start media playback.
 @param controller Activity controller object.
 */
- (void)activityControllerWillStartMedia:(SMActivityViewController *)controller;
/*!
 @abstract Notifies that controller will finish media playback.
 @param controller Activity controller object.
 */
- (void)activityControllerDidFinishMedia:(SMActivityViewController *)controller;
/*!
 @abstract Notifies that controller will be dismissed by the user.
 @param controller Activity controller object.
 */
- (void)activityViewControllerWillDismiss:(SMActivityViewController *)controller;
/*!
 @abstract Notifies that controller has been dismissed by the user. 
 @param controller Activity controller object.
 */
- (void)activityViewControllerDidDismiss:(SMActivityViewController *)controller;

@end


/*!
 @class SMActivityViewController
 @abstract Activity view controller. 
 @discussion Allows presentaton of portal or introduction content using standard UIViewController object. This presentation methods should be used as an alternative to calling @link presentActivity: @/link on @link SessionM @/link instance if desired. 
 The following restrictions apply when using activity view controller:
 <ol>
 <li>The integration with UITabBarController is currently not supported because activity controller content requires full screen.</li>
 <li>Achievement activity cannot be presented as a view controller.</li>
 </ol>
 */
@interface SMActivityViewController : UIViewController 

/*!
 @property delegate
 @abstract SMActivityViewControllerDelegate object.
 */
@property(nonatomic, weak) id<SMActivityViewControllerDelegate> delegate;
/*!
 @property activityType
 @abstract Activity type. By default, it is set to @link SMActivityTypePortal @/link.
 @deprecated Use method @link newInstanceWithActivityType: @/link instead.
 */
@property(nonatomic) SMActivityType activityType __attribute__((deprecated));
/*!
 @abstract Returns new activity controller object. 
 @discussion By default, controller object is configured to display user portal, @link SMActivityTypePortal @/link. To display different content application should set property @link activityType @/link before presenting the controller. 
 @deprecated Use method @link newInstanceWithActivityType: @/link instead.
 @result SMActivityViewController object.
 */
+ (SMActivityViewController *)newInstance __attribute__((deprecated));
/*!
 @abstract Returns new activity controller object with specified type or nil if content for specified type not available. Activity will be presented in the specified navigation controller.
 @result SMActivityViewController object.
 */
+ (SMActivityViewController *)newInstanceWithActivityType:(SMActivityType)type;
+ (SMActivityViewController *)newInstanceWithActivityType:(SMActivityType)type inNavigationController:(UINavigationController *)navigationController;
+ (SMActivityViewController *)newInstanceWithActivityType:(SMActivityType)type inTabBarController:(UITabBarController *)tabBarController;
+ (SMActivityViewController *)newInstanceWithActivityType:(SMActivityType)type inNavigationController:(UINavigationController *)navigationController inTabBarController:(UITabBarController*)tabBarController;


@end

#endif /* __SM_ACTIVITY_VIEW_CONTROLLER__ */
