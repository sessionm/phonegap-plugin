//
//  SMSVerification.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SMS_VERIFICATION__
#define __SMS_VERIFICATION__

#import <Foundation/Foundation.h>

/*!
 @typedef SMSVerificationStatus
 @abstract User verification status.

 @constant SMSVerificationStatusUnknown Verification status is unknown.
 @constant SMSVerificationStatusValid Verification code was approved and user is verified.
 @constant SMSVerificationStatusPending Verification code is pending validation.
 @constant SMSVerificationStatusInvalid Verification code was rejected.
 @constant SMSVerificationStatusExpired Verification code is expired, need to re-issue.
 */
typedef enum SMSVerificationStatus {
    SMSVerificationStatusUnknown,
    SMSVerificationStatusValid,
    SMSVerificationStatusPending,
    SMSVerificationStatusInvalid,
    SMSVerificationStatusExpired
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
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
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
