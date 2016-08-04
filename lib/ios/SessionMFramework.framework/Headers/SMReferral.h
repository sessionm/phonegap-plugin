//
//  SMReferral.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_REFERRAL__
#define __SM_REFERRAL__

#import <Foundation/Foundation.h>

/*!
 @typedef SMReferralStatus
 @abstract Referral status.
 */
typedef enum SMReferralStatus {
    /*! Referral status is unknown */
    SMReferralStatusUnknown,                                                                                    /* unknown */
    /*! Referral is pending engagement by the referee. */
    SMReferralStatusPending,                                                                                    /* pending */
    /*! Referee engaged with the referral. */
    SMReferralStatusEngaged,                                                                                    /* engaged */
    /*! Referee registered an account. */
    SMReferralStatusRegistered,                                                                                 /* registered */
    /*! Referrer received loyalty points for the referral. */
    SMReferralStatusConverted,                                                                                  /* converted */
    /*! Referrer reached the referral limit for the current period - conversion will award 0 loyalty points. */
    SMReferralStatusLimitPeriod,                                                                                /* limit_period */
    /*! Referrer reached the lifetime referral limit - conversion will award 0 loyalty points. */
    SMReferralStatusLimitLifetime,                                                                              /* limit_lifetime */
    /*! Referral was voided due to referee registering for an account through other means. */
    SMReferralStatusVoided,                                                                                     /* voided */
} SMReferralStatus;


/*!
 @class SMReferral
 @abstract Defines the data associated with a registration referral.
 */
@interface SMReferral : NSObject

/*!
 @property referralID
 @abstract Unique ID for referral.
 */
@property(nonatomic, strong, readonly) NSString *referralID;
/*!
 @property referee
 @abstract Name of person being referred.
 */
@property(nonatomic, strong, readonly) NSString *referee;
/*!
 @property email
 @abstract Referee's email address.
 */
@property(nonatomic, strong, readonly) NSString *email;
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
 @property pendingTime
 @abstract Denotes when referral was created.
 */
@property(nonatomic, strong, readonly) NSString *pendingTime;
/*!
 @property engagedTime
 @abstract Denotes when referee engaged with the referral.
 */
@property(nonatomic, strong, readonly) NSString *engagedTime;
/*!
 @property registeredTime
 @abstract Denotes when referee registered for an account.
 */
@property(nonatomic, strong, readonly) NSString *registeredTime;
/*!
 @property convertedTime
 @abstract Denotes when referrer received loyalty points for the referral.
 */
@property(nonatomic, strong, readonly) NSString *convertedTime;
/*!
 @property voidedTime
 @abstract Denotes when referral was voided due to referee registering for an account through other means.
 */
@property(nonatomic, strong, readonly) NSString *voidedTime;
/*!
 @property clientData
 @abstract Opaque developer-defined data.
 */
@property(nonatomic, strong, readonly) id clientData;
/*!
 @property conversionPoints
 @abstract The number of points the referrer will or did receive when the referee registers for an account.
 */
@property(nonatomic, assign, readonly) int conversionPoints;
/*!
 @property status
 @abstract Referral status.
 */
@property(nonatomic, assign, readonly) SMReferralStatus status;
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMReferralStatus @/link enum value.
 @param string String to convert.
 @result @link SMReferralStatus @/link enum value.
 */
+ (SMReferralStatus)statusForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMReferralStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMReferralStatus)status;

@end

#endif /* __SM_REFERRAL__ */
