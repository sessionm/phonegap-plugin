//
//  SMLoyaltyCardTransaction.h
//  SessionM
//
//  Created by Paul Mattheis on 6/7/16.
//
//

#import <Foundation/Foundation.h>

#ifndef __SM_LOYALTY_CARD_TRANSACTION__
#define __SM_LOYALTY_CARD_TRANSACTION__

@interface SMLoyaltyCardTransaction : NSObject

@property(nonatomic, strong, readonly) NSString     *transactionID;
@property(nonatomic, strong, readonly) NSString     *name;
@property(nonatomic, strong, readonly) NSString     *descriptionText;
@property(nonatomic, assign, readonly) double        price;
@property(nonatomic, assign, readonly) int           quantity;
@property(nonatomic, assign, readonly) int           points;
@property(nonatomic, strong, readonly) NSString     *transactionTime;
@property(nonatomic, strong, readonly) NSString     *createdAt;
@property(nonatomic, strong, readonly) NSString     *updatedAt;
@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_LOYALTY_CARD_TRANSACTION__ */
