//
//  SMReferralsManager.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_REFERRALS_MANAGER__
#define __SM_REFERRALS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMReferralError.h"
#import "SMReferralRequest.h"
#import "SMReferral.h"

/*!
 @const SM_REFERRALS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION;
/*!
 @const SM_REFERRALS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Referrals API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION;

/*!
 @const SM_REFERRALS_MANAGER_DID_SEND_REFERRALS_NOTIFICATION
 @abstract Notifies observers that referrals were sent.
 @discussion An <code>NSArray</code> of @link SMReferral @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_DID_SEND_REFERRALS_NOTIFICATION;
/*!
 @const SM_REFERRALS_MANAGER_DID_FETCH_REFERRALS_NOTIFICATION
 @abstract Notifies observers that referrals sent by the current user were fetched.
 @discussion An <code>NSArray</code> of @link SMReferral @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_DID_FETCH_REFERRALS_NOTIFICATION;

/*!
 @protocol SMReferralsDelegate
 @abstract Defines callbacks for @link SMReferralsManager @/link methods.
 */
@protocol SMReferralsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that referral requests were created and sent.
 @discussion This method is called in response to @link sendReferrals: @/link.
 @param referrals The newly created referrals.
 @param referralErrors Errors for individual referrals.
 @param error Error for entire referral request.
 @deprecated Use block methods instead.
 */
- (void)didSendReferrals:(NSArray<SMReferral *> *)referrals referralErrors:(NSArray<SMReferralError *> *)referralErrors error:(SMError *)error __attribute__((deprecated("Use block methods instead")));
/*!
 @abstract Notifies delegate that the current user's sent referrals were fetched.
 @discussion This method is called in response to @link fetchReferrals @/link.
 @param referrals Referrals that have been sent by the current user.
 @deprecated Use block methods instead.
 */
- (void)didFetchReferrals:(NSArray<SMReferral *> *)referrals __attribute__((deprecated("Use block methods instead")));
/*!
 @abstract Notifies delegate that one of the current user's sent referrals was fetched.
 @discussion This method is called in response to @link fetchReferralWithID: @/link.
 @param referral A referral that has been sent by the current user.
 @deprecated Use block methods instead.
 */
- (void)didFetchSingleReferral:(SMReferral *)referral __attribute__((deprecated("Use block methods instead")));

@end

/*!
 @typedef didSendReferrals
 @abstract Completion handler block type for @link sendReferrals:completionHandler: @/link.
 */
typedef void (^didSendReferrals)(NSArray<SMReferral *>*successfulReferrals, NSArray<SMReferralError *>*referralErrors, SMError *error);
/*!
 @typedef didFetchReferrals
 @abstract Completion handler block type for @link fetchReferralsWithCompletionHandler: @/link.
 */
typedef void (^didFetchReferrals)(NSArray<SMReferral *>*referrals, SMError *error);
/*!
 @typedef didFetchSingleReferral
 @abstract Completion handler block type for @link fetchReferralWithID:completionHandler: @/link.
 */
typedef void (^didFetchSingleReferral)(SMReferral *referral, SMError *error);


/*!
 @class SMReferralsManager
 @abstract This API manager contains methods for fetching referral data.
 */
@interface SMReferralsManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMReferralsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMReferralsDelegate> delegate;
/*!
 @property referrals
 @abstract Referrals that have been sent by the current user.
 @discussion This property is updated in response to a successful @link fetchReferralsWithCompletionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMReferral *> *referrals;

/*!
 @abstract Makes a request to send the specified referrals.
 @discussion @link didSendReferrals:referralErrors:error: @/link is called in response to this method.
 @param referrals The referrals request to be sent.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link sendReferrals:completionHandler: @/link.
 */
- (BOOL)sendReferrals:(SMReferralsRequest *)referrals __attribute__((deprecated("Use sendReferrals:completionHandler:")));
/*!
 @abstract Makes a request to send the specified referrals.
 @param referrals The referrals request to be sent.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)sendReferrals:(SMReferralsRequest *)referrals completionHandler:(didSendReferrals)onCompletion;
/*!
 @abstract Makes a request to update @link referrals @/link with the current user's referrals.
 @discussion @link didFetchReferrals: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchReferralsWithCompletionHandler: @/link.
 */
- (BOOL)fetchReferrals __attribute__((deprecated("Use fetchReferralsWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link referrals @/link with the current user's referrals.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchReferralsWithCompletionHandler:(didFetchReferrals)onCompletion;
/*!
 @abstract Makes a request to fetch the referral with the specified identifier.
 @discussion @link didFetchReferrals: @/link is called in response to this method.
 @param referralID The identifier of the referral to be fetched.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchReferralWithID:completionHandler: @/link.
 */
- (BOOL)fetchReferralWithID:(NSString *)referralID __attribute__((deprecated("Use fetchReferralWithID:completionHandler:")));
/*!
 @abstract Makes a request to fetch the referral with the specified identifier.
 @param referralID The identifier of the referral to be fetched.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchReferralWithID:(NSString *)referralID completionHandler:(didFetchSingleReferral)onCompletion;

@end

#endif /* __SM_REFERRALS_MANAGER__ */
