//
//  SMSVerification.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SMS_VERIFICATION__
#define __SMS_VERIFICATION__

#import <Foundation/Foundation.h>

/*!
 @typedef SMSVerificationStatus
 @abstract User verification status.
 */
typedef enum SMSVerificationStatus {
    /*! Verification status is unknown. */
    SMSVerificationStatusUnknown,                                /* unknown */
    /*! Verification code was approved and user is verified. */
    SMSVerificationStatusValid,                                  /* valid */
    /*! Verification code is pending validation. */
    SMSVerificationStatusPending,                                /* pending */
    /*! Verification code was rejected. */
    SMSVerificationStatusInvalid,                                /* invalid */
    /*! Verification code is expired, need to re-issue. */
    SMSVerificationStatusExpired                                 /* expired */
} SMSVerificationStatus;


/*!
 @class SMSVerification
 @abstract Defines the data associated with a user's verification request.
 */
@interface SMSVerification : NSObject

/*!
 @property verificationID
 @abstract Unique ID for verification.
 */
@property(nonatomic, strong, readonly) NSString *verificationID;
/*!
 @property status
 @abstract User verification status.
 */
@property(nonatomic, assign, readonly) SMSVerificationStatus status;
/*!
 @property mode
 @abstract Medium used to send verification code to user (e.g. "sms").
 */
@property(nonatomic, strong, readonly) NSString *mode;
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Returns verification data in a formatted string.
 @result Formatted <code>NSString</code>.
 */
- (NSString *)asString;

/*!
 @abstract Converts specified string value to the corresponding @link SMSVerificationStatus @/link enum value.
 @param string String to convert.
 @result @link SMSVerificationStatus @/link enum value.
 */
+ (SMSVerificationStatus)statusForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMSVerificationStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMSVerificationStatus)status;

@end

#endif /* __SMS_VERIFICATION__ */
