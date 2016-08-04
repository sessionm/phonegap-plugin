//
//  SMReferralsManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_REFERRALS_MANAGER__
#define __SM_REFERRALS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMReferral.h"

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
 */
- (void)didSendReferrals:(NSArray<SMReferral *> *)referrals;
/*!
 @abstract Notifies delegate that the current user's sent referrals were fetched.
 @discussion This method is called in response to @link fetchReferrals @/link and @link fetchReferralWithID: @/link.
 @param referrals Referrals that have been sent by the current user.
 */
- (void)didFetchReferrals:(NSArray<SMReferral *> *)referrals;

@end


/*!
 @class SMReferralRequest
 @abstract Defines the data associated with a registration referral request.
 */
@interface SMReferralRequest : NSObject

/*!
 @property email
 @abstract Referee's email address.
 */
@property(nonatomic, strong, readonly) NSString *email;
/*!
 @property name
 @abstract Name of person being referred.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property phoneNumber
 @abstract Referee's phone number.
 */
@property(nonatomic, strong, readonly) NSString *phoneNumber;
/*!
 @property origin
 @abstract Referral origin.
 */
@property(nonatomic, strong, readonly) NSString *origin;
/*!
 @property source
 @abstract Referral source.
 */
@property(nonatomic, strong, readonly) NSString *source;
/*!
 @property clientData
 @abstract Opaque developer-defined data.
 */
@property(nonatomic, strong, readonly) id clientData;

/*!
 @abstract Creates a new instance of <code>SMReferralRequest</code> with the specified parameters.
 @param email Referee's email address.
 @param name Name of person being referred (optional).
 @param phoneNumber Referee's phone number (optional).
 @param origin Referral origin (optional).
 @param source Referral source (optional).
 @param clientData Opaque developer-defined data (optional).
 @result <code>SMReferralRequest</code> instance.
 */
- (instancetype)initWithEmail:(NSString *)email name:(NSString *)name phoneNumber:(NSString *)phoneNumber origin:(NSString *)origin source:(NSString *)source clientData:(id)clientData;
/*!
 @abstract Returns referral request data in a dictionary format.
 @result <code>NSDictionary</code> respresentation of referral request data.
 */
- (NSDictionary *)asDictionary;

@end


/*!
 @class SMReferralsRequest
 @abstract Encapsulates an array of referral requests.
 */
@interface SMReferralsRequest : NSObject

/*!
 @property requests
 @abstract The referral requests to be sent.
 */
@property(nonatomic, strong, readonly) NSArray<SMReferralRequest *> *requests;
/*!
 @property referrer
 @abstract Name of user sending referrals.
 */
@property(nonatomic, strong, readonly) NSString *referrer;

/*!
 @abstract Creates a new instance of <code>SMReferralsRequest</code> with the specified parameters.
 @param requests The referral requests to be sent.
 @param referrer Name of user sending referrals (optional).
 @result <code>SMReferralsRequest</code> instance.
 */
- (instancetype)initWithRequests:(NSArray<SMReferralRequest *> *)requests referrer:(NSString *)referrer;

@end


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
 @discussion This property is updated in response to a successful @link fetchReferrals @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMReferral *> *referrals;

/*!
 @abstract Sends the specified referrals request.
 @discussion @link didSendReferrals: @/link is called in response to this method.
 @param referrals The referrals request to be sent.
 */
- (void)sendReferrals:(SMReferralsRequest *)referrals;
/*!
 @abstract Makes a request to update @link referrals @/link with the current user's referrals.
 @discussion @link didFetchReferrals: @/link is called in response to this method.
 */
- (void)fetchReferrals;
/*!
 @abstract Makes a request to fetch the referral with the specified identifier.
 @discussion @link didFetchReferrals: @/link is called in response to this method.
 @param referralID The identifier of the referral to be fetched.
 */
- (void)fetchReferralWithID:(NSString *)referralID;

@end

#endif /* __SM_REFERRALS_MANAGER__ */
