//
//  SMReferralRequest.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//
//

#ifndef __SM_REFERRAL_REQUEST__
#define __SM_REFERRAL_REQUEST__

#import <Foundation/Foundation.h>

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
 @abstract Referral requests to be sent (see @link //apple_ref/occ/instm/SMReferralsManager/sendReferrals:completionHandler: @/link).
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

#endif /* __SM_REFERRAL_REQUEST__ */
