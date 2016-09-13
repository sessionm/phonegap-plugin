//
//  SMOrder.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_ORDER__
#define __SM_ORDER__

#import "SMAddress.h"

/*!
 @typedef SMOrderStatus
 @abstract Order redemption status.

 @constant SMOrderStatusUnknown Order status is unknown.
 @constant SMOrderStatusApproved Order is approved.
 @constant SMOrderStatusRejected Order redemption was rejected by Customer Care Team (e.g. due to Terms of Service violation).
 @constant SMOrderStatusPending Order is pending review.
 @constant SMOrderStatusRedemptionError Error was received while attempting to redeem order.
 */
typedef enum SMOrderStatus {
    SMOrderStatusUnknown,
    SMOrderStatusApproved,
    SMOrderStatusRejected,
    SMOrderStatusPending,
    SMOrderStatusRedemptionError
} SMOrderStatus;


/*!
 @class SMOrderUser
 @abstract Defines the data associated with a user who made an offer order.
 */
@interface SMOrderUser : NSObject

/*!
 @property userID
 @abstract ID of user who made the order.
 */
@property(nonatomic, strong, readonly) NSString *userID;
/*!
 @property availablePoints
 @abstract User's current loyalty points balance.
 */
@property(nonatomic, assign, readonly) int availablePoints;
/*!
 @property testPoints
 @abstract The number of loyalty points that the user has earned from apps that are in development mode.
 */
@property(nonatomic, assign, readonly) int testPoints;

@end


/*!
 @class SMOrder
 @abstract Defines the data associated with an offer order made by a user.
 */
@interface SMOrder : NSObject

/*!
 @property orderID
 @abstract Unique ID for order.
 */
@property(nonatomic, strong, readonly) NSString *orderID;
/*!
 @property offerID
 @abstract ID of offer that was redeemed.
 */
@property(nonatomic, strong, readonly) NSString *offerID;
/*!
 @property user
 @abstract Data associated with the user who made the order.
 */
@property(nonatomic, strong, readonly) SMOrderUser *user;
/*!
 @property quantity
 @abstract Amount of items redeemed in the order.
 */
@property(nonatomic, assign, readonly) int quantity;
/*!
 @property points
 @abstract Amount of points spent in the order.
 */
@property(nonatomic, assign, readonly) int points;
/*!
 @property createdTime
 @abstract Indicates when the order was created.
 */
@property(nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property name
 @abstract Name of offer redeemed in the order.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property logoURL
 @abstract URL to image associated with the offer redeemed in the order.
 */
@property(nonatomic, strong, readonly) NSString *logoURL;
/*!
 @property descriptionText
 @abstract Description of offer redeemed in the order.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText;
/*!
 @property shippingAddress
 @abstract Where physical items will be shipped after the order is processed.
 */
@property(nonatomic, strong, readonly) SMAddress *shippingAddress;
/*!
 @property data
 @abstract Contains voucher data associated with order.
 */
@property(nonatomic, strong, readonly) NSDictionary *data;
/*!
 @property status
 @abstract Order redemption status.
 */
@property(nonatomic, assign, readonly) SMOrderStatus status;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Converts current order status to the corresponding string value.
 @result <code>NSString</code> value.
 */
- (NSString *)stringForCurrentStatus;

/*!
 @abstract Converts specified string value to the corresponding @link SMOrderStatus @/link enum value.
 @param string String to convert.
 @result @link SMOrderStatus @/link enum value.
 */
+ (SMOrderStatus)statusForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMOrderStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMOrderStatus)status;

@end

#endif /* __SM_ORDER__ */
