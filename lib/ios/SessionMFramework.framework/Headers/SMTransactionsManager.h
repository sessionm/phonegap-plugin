//
//  SMTransactionsManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_TRANSACTIONS_MANAGER__
#define __SM_TRANSACTIONS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMTransaction.h"

/*!
 @const SM_TRANSACTIONS_MANAGER_DEFAULT_FETCH_LIMIT
 @abstract The default maximum amount of transactions to fetch when calling @link fetchTransactions @/link and @link fetchTransactionsWithStartDate:endDate:limit: @/link.
 */
extern const int SM_TRANSACTIONS_MANAGER_DEFAULT_FETCH_LIMIT;
/*!
 @const SM_TRANSACTIONS_MANAGER_END_DATE_OFFSET
 @abstract The offset used to calculate <code>endDate</code> when calling @link fetchTransactions @/link and @link fetchTransactionsWithStartDate:endDate:limit: @/link.
 */
extern const NSTimeInterval SM_TRANSACTIONS_MANAGER_END_DATE_OFFSET;


/*!
 @protocol SMTransactionsDelegate
 @abstract Defines callbacks for @link SMTransactionsManager @/link methods.
 */
@protocol SMTransactionsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that points transactions were fetched.
 @discussion This method is called in response to @link fetchTransactions @/link, @link fetchTransactionsWithStartDate:endDate:limit: @/link and @link fetchMoreTransactions @/link.
 @param transactions The points transactions.
 @param hasMore Indicates whether there are more transactions that can be fetched by calling @link fetchMoreTransactions @/link .
 */
- (void)didFetchTransactions:(NSArray<SMTransaction *> *)transactions hasMore:(BOOL)hasMore;

@end


/*!
 @class SMTransactionsManager
 @abstract This API manager contains methods for fetching loyalty points transaction data.
 */
@interface SMTransactionsManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMTransactionsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMTransactionsDelegate> delegate;
/*!
 @property transactions
 @abstract The current user's points transactions.
 @discussion This property is updated in response to a successful @link fetchTransactions @/link, @link fetchTransactionsWithStartDate:endDate:limit: @/link or @link fetchMoreTransactions @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMTransaction *> *transactions;

/*!
 @abstract Makes a request to update @link transactions @/link with the current user's points transactions (limited to @link SM_TRANSACTIONS_MANAGER_DEFAULT_FETCH_LIMIT @/link transactions).
 @discussion @link didFetchTransactions:hasMore: @/link is called in response to this method.
 */
- (void)fetchTransactions;
/*!
 @abstract Makes a request to update @link transactions @/link with a limited number of the current user's points transactions that took place between the specified start and end dates.
 @discussion @link didFetchTransactions:hasMore: @/link is called in response to this method.
 @param startDate Transactions after this date will not be fetched (optional - default value is current date).
 @param endDate Transactions before this date will not be fetched (optional - default value is <code>startDate - @link SM_TRANSACTIONS_MANAGER_END_DATE_OFFSET @/link </code>).
 @param limit The maximum amount of transactions to fetch (optional - default value is @link SM_TRANSACTIONS_MANAGER_DEFAULT_FETCH_LIMIT @/link; maximum value is 1000).
 @param locale The locale of the user (optional).
 */
- (void)fetchTransactionsWithStartDate:(NSDate *)startDate endDate:(NSDate *)endDate limit:(int)limit;
/*!
 @abstract Makes a request to update @link transactions @/link with points transactions that were not included in the previous fetch (limited to @link SM_TRANSACTIONS_MANAGER_DEFAULT_FETCH_LIMIT @/link transactions).
 @discussion @link didFetchTransactions:hasMore: @/link is called in response to this method. This method should only be called if <code>hasMore</code> is set to <code>YES</code>.
 */
- (void)fetchMoreTransactions;

@end

#endif /* __SM_TRANSACTIONS_MANAGER__ */
