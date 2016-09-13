//
//  SMLoyaltyCard.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_LOYALTY_CARD__
#define __SM_LOYALTY_CARD__

#import "SMRetailer.h"

/*!
 @class SMLoyaltyCard
 @abstract Defines the data associated with a loyalty card that has been linked with a user's account.
 */
@interface SMLoyaltyCard : NSObject

/*!
 @property cardID
 @abstract Unique ID for loyalty card.
 */
@property(nonatomic, strong, readonly) NSString *cardID;
/*!
 @property cardNumber
 @abstract Number associated with loyalty card (issued by retailer).
 */
@property(nonatomic, strong, readonly) NSString *cardNumber;
/*!
 @property retailer
 @abstract Retailer associated with loyalty card.
 */
@property(nonatomic, strong, readonly) SMRetailer *retailer;
/*!
 @property isLinked
 @abstract Indicates whether the current user has linked a loyalty card issued by the associated retailer.
 */
@property(nonatomic, assign, readonly) BOOL isLinked;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_LOYALTY_CARD__ */
