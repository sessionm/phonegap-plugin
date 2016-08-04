//
//  SMLoyaltyCardsManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_LOYALTY_CARDS_MANAGER__
#define __SM_LOYALTY_CARDS_MANAGER__

#import "SMLoyaltyCard.h"
#import "SMLoyaltyCardTransaction.h"
#import "SMBaseDelegate.h"

/*!
 @protocol SMLoyaltyCardsDelegate
 @abstract Defines callbacks for @link SMLoyaltyCardsManager @/link methods.
 */
@protocol SMLoyaltyCardsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that the current user's linked loyalty cards were fetched.
 @discussion This method is called in response to @link fetchLinkedCards @/link.
 @param cards The linked loyalty cards.
 */
- (void)didFetchLoyaltyCards:(NSArray<SMLoyaltyCard *> *)cards;
/*!
 @abstract Notifies delegate that the current user's loyalty card transactions were fetched.
 @discussion This method is called in response to @link fetchLoyaltyCardTransactions @/link.
 @param transactions The user's cards transactions.
 */
- (void)didFetchLoyaltyCardTransactions:(NSArray<SMLoyaltyCardTransaction *> *)transactions;
/*!
 @abstract Notifies delegate that a loyalty card was linked.
 @discussion This method is called in response to @link linkLoyaltyCardNumber:retailer: @/link.
 @param cardNumber The card number of the linked loyalty card.
 */
- (void)didLinkLoyaltyCard:(NSString *)cardNumber;
/*!
 @abstract Notifies delegate that a loyalty card was unlinked.
 @discussion This method is called in response to @link unlinkLoyaltyCardID: @/link.
 */
- (void)didUnlinkLoyaltyCard;

/*!
 @abstract Notifies delegate that the available retailers were fetched.
 @discussion This method is called in response to @link fetchRetailers @/link and @link fetchRetailersWithZipCode: @/link.
 @param retailers The available retailers.
 */
- (void)didFetchRetailers:(NSArray<SMRetailer *> *)retailers;

@end


/*!
 @class SMLoyaltyCardsManager
 @abstract This API manager contains methods for linking and unlinking loyalty cards with a user's account, as well as fetching linked loyalty cards and supported retailers with loyalty programs.
 */
@interface SMLoyaltyCardsManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMLoyaltyCardsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMLoyaltyCardsDelegate> delegate;
/*!
 @property loyaltyCards
 @abstract The current user's linked loyalty cards.
 @discussion This property is updated in response to a successful @link fetchLinkedCards @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMLoyaltyCard *> *loyaltyCards;
/*!
 @property retailers
 @abstract The retailers for which a user can link a loyalty card.
 @discussion This property is updated in response to a successful @link fetchRetailersWithZipCode: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMRetailer *>    *retailers;

/*!
 @abstract Makes a request to update @link loyaltyCards @/link with the current user's linked loyalty cards.
 @discussion @link didFetchLoyaltyCards: @/link is called in response to this method.
 */
- (void)fetchLinkedCards;
/*!
 @abstract Makes a request to fetch transactions made with the current user's linked loyalty cards.
 @discussion @link didFetchLoyaltyCardTransactions: @/link is called in response to this method.
 */
-(void)fetchLoyaltyCardTransactions;
/*!
 @abstract Links a loyalty card issued by the specified retailer with the specified card number.
 @discussion @link didLinkLoyaltyCard: @/link is called in response to this method.
 @param cardNumber Loyalty card number.
 @param retailerID ID of retailer that issued the loyalty card.
 */
- (void)linkLoyaltyCardNumber:(NSString *)cardNumber retailer:(NSString *)retailerID;
/*!
 @abstract Unlinks the loyalty card with the specified loyalty card ID.
 @discussion @link didUnlinkLoyaltyCard @/link is called in response to this method.
 @param cardID The ID of the loyalty card to unlink.
 */
- (void)unlinkLoyaltyCardID:(NSString *)cardID;

/*!
 @abstract Makes a request to update @link retailers @/link with retailers for which a user can link a loyalty card.
 @discussion @link didFetchRetailers: @/link is called in response to this method.
 */
- (void)fetchRetailers;
/*!
 @abstract Makes a request to update @link retailers @/link with retailers in the specified zipcode for which a user can link a loyalty card.
 @discussion @link didFetchRetailers: @/link is called in response to this method.
 @param zipCode Zipcode in which to search for retailers (optional).
 */
- (void)fetchRetailersWithZipCode:(NSString *)zipCode;

@end

#endif /* __SM_LOYALTY_CARDS_MANAGER__ */
