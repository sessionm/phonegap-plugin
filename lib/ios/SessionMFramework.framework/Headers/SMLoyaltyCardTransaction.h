//
//  SMLoyaltyCardTransaction.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef __SM_LOYALTY_CARD_TRANSACTION__
#define __SM_LOYALTY_CARD_TRANSACTION__

/*!
 @class SMLoyaltyCardTransaction
 @abstract Defines the purchase data for an item purchased with a loyalty card linked to a user's account.
 */
@interface SMLoyaltyCardTransaction : NSObject

/*!
 @property transactionID
 @abstract Unique ID for transaction.
 @discussion This ID will be equal to @link //apple_ref/occ/instp/SMTransaction/recordModelID @/link in the corresponding transaction record.
 */
@property(nonatomic, strong, readonly) NSString     *transactionID;
/*!
 @property name
 @abstract Item name.
 */
@property(nonatomic, strong, readonly) NSString     *name;
/*!
 @property descriptionText
 @abstract Item description.
 */
@property(nonatomic, strong, readonly) NSString     *descriptionText;
/*!
 @property price
 @abstract Individual item price.
 */
@property(nonatomic, assign, readonly) double        price;
/*!
 @property quantity
 @abstract Amount of items purchased.
 */
@property(nonatomic, assign, readonly) int           quantity;
/*!
 @property points
 @abstract Amount of points user earned for the transaction.
 */
@property(nonatomic, assign, readonly) int           points;
/*!
 @property transactionTime
 @abstract Indicates when the transaction took place.
 */
@property(nonatomic, strong, readonly) NSString     *transactionTime;
/*!
 @property createdTime
 @abstract Indicates when the transaction record was created.
 */
@property(nonatomic, strong, readonly) NSString     *createdTime;
/*!
 @property updatedTime
 @abstract Indicates when the transaction record was last updated.
 */
@property(nonatomic, strong, readonly) NSString     *updatedTime;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_LOYALTY_CARD_TRANSACTION__ */
