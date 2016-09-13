//
//  SMIdentityManager.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_IDENTITY_MANAGER__
#define __SM_IDENTITY_MANAGER__

#import "SMBaseDelegate.h"
#import "SMMMCUser.h"
#import "SMMMCUserUpdate.h"
#import "SMSVerification.h"

/*!
 @const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION;
/*!
 @const SM_IDENTITY_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Identity API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION;

/*!
 @const SM_IDENTITY_MANAGER_DID_SEND_SMS_VERIFICATION_MESSAGE_NOTIFICATION
 @abstract Notifies observers that an SMS verification message was sent via phone number.
 @discussion An @link SMSVerification @/link object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_SEND_SMS_VERIFICATION_MESSAGE_NOTIFICATION;
/*!
 @const SM_IDENTITY_MANAGER_DID_CHECK_SMS_VERIFICATION_CODE_NOTIFICATION
 @abstract Notifies observers that an SMS verification code was checked.
 @discussion An @link SMSVerification @/link object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_CHECK_SMS_VERIFICATION_CODE_NOTIFICATION;
/*!
 @const SM_IDENTITY_MANAGER_DID_FETCH_VERIFICATION_NOTIFICATION
 @abstract Notifies observers that the current user's SMS verification status was fetched.
 @discussion An @link SMSVerification @/link object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_FETCH_VERIFICATION_NOTIFICATION;

/*!
 @const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER
 @abstract Notifies observers that account data for the current user was fetched.
 @discussion An @link SMMMCUser @/link object containing information about the current user's account can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER;
/*!
 @const SM_CAMPAIGNS_MANAGER_DID_FETCH_FEED_MESSAGES_NOTIFICATION
 @abstract Notifies observers that account data for the current user was updated.
 @discussion An @link SMMMCUser @/link object containing information about the current user's account can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_UPDATE_MMC_USER;

/*!
 @protocol SMIdentityDelegate
 @abstract Defines callbacks for @link SMIdentityManager @/link methods.
 */
@protocol SMIdentityDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that the current user's data was fetched.
 @discussion This method is called in response to @link fetchMMCUser @/link.
 @param user The current user's data.
 @deprecated Use block methods instead.
 */
- (void)didFetchMMCUser:(SMMMCUser *)user __attribute__((deprecated("Use block methods instead")));
/*!
 @abstract Notifies delegate that the current user's data was updated.
 @discussion This method is called in response to @link updateMMCUser: @/link.
 @param user The current user's data.
 @deprecated Use block methods instead.
 */
- (void)didUpdateMMCUser:(SMMMCUser *)user __attribute__((deprecated("Use block methods instead")));

/*!
 @abstract Notifies delegate that the SMS message was successfully sent.
 @discussion This method is called in response to @link sendSMSVerificationMessageToPhoneNumber: @/link.
 @param verification The verification data.
 @deprecated Use block methods instead.
 */
- (void)didSendSMSVerificationMessage:(SMSVerification *)verification __attribute__((deprecated("Use block methods instead")));
/*!
 @abstract Notifies delegate that the verification code validation was completed.
 @discussion This method is called in response to @link checkSMSVerificationCode: @/link.
 @param verification The verification data.
 @deprecated Use block methods instead.
 */
- (void)didCheckSMSVerificationCode:(SMSVerification *)verification __attribute__((deprecated("Use block methods instead")));
/*!
 @abstract Notifies delegate that the current user's verification data was fetched.
 @discussion This method is called in response to @link fetchSMSVerification @/link.
 @param verification The verification data.
 @deprecated Use block methods instead.
 */
- (void)didFetchSMSVerification:(SMSVerification *)verification __attribute__((deprecated("Use block methods instead")));

@end

/*!
 @typedef didFetchMMCUser
 @abstract Completion handler block type for @link fetchMMCUserWithCompletionHandler: @/link.
 */
typedef void (^didFetchMMCUser)(SMMMCUser *user, SMError *error);
/*!
 @typedef didUpdateMMCUser
 @abstract Completion handler block type for @link updateMMCUser:completionHandler: @/link.
 */
typedef void (^didUpdateMMCUser)(SMMMCUser *user, SMError *error);
/*!
 @typedef didXYZSMS
 @abstract Completion handler block type for @link sendSMSVerificationMessageToPhoneNumber:completionHandler: @/link, @link checkSMSVerificationCode:completionHandler: @/link and @link fetchSMSVerificationWithCompletionHandler: @/link.
 */
typedef void (^didXYZSMS)(SMSVerification *verification, SMError *error);


/*!
 @class SMIdentityManager
 @abstract This API manager contains methods for fetching user data, sending SMS messages with verification codes, validating verification codes, and fetching verification data.
 */
@interface SMIdentityManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMIdentityDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMIdentityDelegate> delegate;

/*!
 @abstract Makes a request to fetch the current user's data.
 @discussion @link didFetchMMCUser: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchMMCUserWithCompletionHandler: @/link.
 */
- (BOOL)fetchMMCUser __attribute__((deprecated("Use fetchMMCUserWithCompletionHandler:")));
/*!
 @abstract Makes a request to fetch the current user's data.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchMMCUserWithCompletionHandler:(didFetchMMCUser)onCompletion;
/*!
 @abstract Makes a request to update the current user's data.
 @discussion @link didUpdateMMCUser: @/link is called in response to this method.
 @param updates Data changes to make.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link updateMMCUser:completionHandler: @/link.
 */
- (BOOL)updateMMCUser:(SMMMCUserUpdate *)updates __attribute__((deprecated("Use updateMMCUser:completionHandler:")));
/*!
 @abstract Makes a request to update the current user's data.
 @param updates Data changes to make.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)updateMMCUser:(SMMMCUserUpdate *)updates completionHandler:(didUpdateMMCUser)onCompletion;
/*!
 @abstract Makes a request to send an SMS verification message to the specified phone number.
 @discussion @link didSendSMSVerificationMessage: @/link is called in response to this method.
 @param phoneNumber The phone number to which the SMS message will be sent.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link sendSMSVerificationMessageToPhoneNumber:completionHandler: @/link.
 */
- (BOOL)sendSMSVerificationMessageToPhoneNumber:(NSString *)phoneNumber __attribute__((deprecated("Use sendSMSVerificationMessageToPhoneNumber:completionHandler:")));
/*!
 @abstract Makes a request to send an SMS verification message to the specified phone number.
 @param phoneNumber The phone number to which the SMS message will be sent.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)sendSMSVerificationMessageToPhoneNumber:(NSString *)phoneNumber completionHandler:(didXYZSMS)onCompletion;
/*!
 @abstract Makes a request to validate the specified verification code.
 @discussion @link didCheckSMSVerificationCode: @/link is called in response to this method.
 @param code The verification code to validate.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link checkSMSVerificationCode:completionHandler: @/link.
 */
- (BOOL)checkSMSVerificationCode:(NSString *)code __attribute__((deprecated("Use checkSMSVerificationCode:completionHandler:")));
/*!
 @abstract Makes a request to validate the specified verification code.
 @param code The verification code to validate.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)checkSMSVerificationCode:(NSString *)code completionHandler:(didXYZSMS)onCompletion;
/*!
 @abstract Makes a request to fetch the current user's verification data.
 @discussion @link didFetchSMSVerification: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchSMSVerificationWithCompletionHandler: @/link.
 */
- (BOOL)fetchSMSVerification __attribute__((deprecated("Use fetchSMSVerificationWithCompletionHandler:")));
/*!
 @abstract Makes a request to fetch the current user's verification data.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchSMSVerificationWithCompletionHandler:(didXYZSMS)onCompletion;

@end

#endif /* SM_IDENTITY_MANAGER */
