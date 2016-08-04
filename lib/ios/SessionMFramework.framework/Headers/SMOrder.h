//
//  SMOrder.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_ORDER__
#define __SM_ORDER__

#import <Foundation/Foundation.h>
#import "SMAddress.h"

/*!
 @typedef SMOrderStatus
 @abstract Order status.
 */
typedef enum SMOrderStatus {
    /*! Order status is unknown. */
    SMOrderStatusUnknown,                                                                                /* unknown */
    /*! Order is approved. */
    SMOrderStatusApproved,                                                                               /* approved */
    /*! Order redemption was rejected by Customer Care Team (e.g. due to Terms of Service violation). */
    SMOrderStatusRejected,                                                                               /* rejected */
    /*! Order is pending review. */
    SMOrderStatusPending,                                                                                /* pending_approval */
    /*! Error was received while attempting to redeem order. */
    SMOrderStatusRedemptionError                                                                         /* redemption_error */
} SMOrderStatus;


@interface SMOrderUser : NSObject

@property(nonatomic, strong, readonly) NSString *userID;
@property(nonatomic, assign, readonly) int availablePoints;
@property(nonatomic, assign, readonly) int testPoints;

@end

/*!
 @class SMOrder
 @abstract Defines the data associated with a reward order made by the user.
 */
@interface SMOrder : NSObject

/*!
 @property orderID
 @abstract Unique ID for order.
 */
@property(nonatomic, strong, readonly) NSString *orderID;
/*!
 @property offerID
 @abstract ID of offer associated with order.
 */
@property(nonatomic, strong, readonly) NSString *offerID;
/*!
 @property userID
 @abstract ID of user associated with order.
 */
@property(nonatomic, strong, readonly) SMOrderUser *user;
/*!
 @property quantity
 @quantity associated with order.
 */
@property(nonatomic, assign, readonly) int quantity;
/*!
 @property points
 @points associated with order.
 */
@property(nonatomic, assign, readonly) int points;
/*!
 @property createdTime
 @created time of Order associated with order.
 */
@property(nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property name
 @name of item associated with order.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property logoURL
 @logo icon URL associated with order.
 */
@property(nonatomic, strong, readonly) NSString *logoURL;
/*!
 @property descriptionText
 @description text associated with order.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText;
/*!
 @property shippingAddress
 @Shipping Address associated with order.
 */
@property(nonatomic, strong, readonly) SMAddress *shippingAddress;
/*!
 @property data
 @abstract Contains voucher data associated with order.
 */
@property(nonatomic, strong, readonly) NSDictionary *data;
/*!
 @property status
 @abstract Order status.
 */
@property(nonatomic, assign, readonly) SMOrderStatus status;

- (NSString *)stringForCurrentStatus;

+ (SMOrderStatus)statusForString:(NSString *)string;
+ (NSString *)stringForStatus:(SMOrderStatus)status;

@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_ORDER__ */
