//
//  SMPortalButton.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_PORTAL_BUTTON__
#define __SM_PORTAL_BUTTON__

#import <UIKit/UIKit.h>

/*!
 @typedef SMPortalButtonBadgePosition
 @abstract Portal button badge position.
 */
typedef enum SMPortalButtonBadgePosition {
    /*! Top left corner. */
    SMPortalButtonBadgePositionLeft,
    /*! Top right corner. Default. */
    SMPortalButtonBadgePositionRight,
    /*! Custom. Use badgeCenter property to position a badge. */
    SMPortalButtonBadgePositionCustom
} SMPortalButtonBadgePosition;


/*!
 @class SMPortalButton
 @abstract Portal button
 @discussion This class creates a view that contains a button to open the user portal as well as a badge for the button that displays the number of unclaimed achievements.
 The button will enable/disable itself in accordance with the session state. The badge will adjust its count as the number of unclaimed achievements changes. If the achievement count reaches zero the badge is removed.
 */
@interface SMPortalButton : UIView
/*!
 Returns a button view with predefined size of 70 x 46. This method will return nil on unsupported platform.
 @result New SMPortalButton object
 */
+ (SMPortalButton *)buttonWithType:(UIButtonType)buttonType;
/*!
 @property button
 @discussion A stateful button that will be enabled/disabled depending on the session state. Customize this as needed.
 */
@property(nonatomic, strong, readonly) UIButton *button;
/*!
 @property shouldDisplayBadge
 @discussion This property is used to toggle the display of the unclaimed achievement badge.
 */
@property(nonatomic) BOOL shouldDisplayBadge;
/*!
 @property shouldDisableOnOptOut
 @discussion This property is used to determine whether the portal button will be disabled when the user is opted out. Default value is YES, but setting this property to NO is recommended if you want to allow users to opt back in through the portal button.
 */
@property(nonatomic) BOOL shouldDisableOnOptOut;
/*!
 @property badgePosition
 */
@property(nonatomic) SMPortalButtonBadgePosition badgePosition;
/*!
 @property badgeCenter
 @discussion Setting this property takes effect only if badge position is SMPortalButtonPositionCustom.
 @deprecated Use badge property instead.
 */
@property(nonatomic) CGPoint badgeCenter;
/*!
 @property badge
 @discussion Badge label is used to customize properties such as font, font size, the badge size, etc. Setting badge position to custom value
    takes effect only if badge position is SMPortalButtonPositionCustom. After changing the badge property application should call @link layoutBadge @/link
    method to ensure that the badge circle is properly sized.
 */
@property (nonatomic, strong, readonly) UILabel *badge;
/*!
 @property presentingController
 @discussion UIViewController object to use as presenting controller for portal view controller. 
 */
@property(nonatomic, strong) UIViewController *presentingController;

/*!
 @abstract Resizes badge after one of its properties was updated via @link badge @/link property.
 */
- (void)layoutBadge;

@end

#endif /* __SM_PORTAL_BUTTON__ */
