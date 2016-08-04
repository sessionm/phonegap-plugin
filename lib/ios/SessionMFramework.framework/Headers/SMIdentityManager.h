//
//  SMIdentityManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_IDENTITY_MANAGER__
#define __SM_IDENTITY_MANAGER__

#import "SMBaseDelegate.h"
#import "SMMMCUser.h"
#import "SMMMCUserUpdate.h"
#import "SMSVerification.h"

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
 */
- (void)didFetchMMCUser:(SMMMCUser *)user;
/*!
 @abstract Notifies delegate that the current user's data was updated.
 @discussion This method is called in response to @link updateMMCUser: @/link.
 @param user The current user's data.
 */
- (void)didUpdateMMCUser:(SMMMCUser *)user;

/*!
 @abstract Notifies delegate that the SMS message was successfully sent.
 @discussion This method is called in response to @link sendSMSVerificationMessageToPhoneNumber: @/link.
 @param verification The verification data.
 */
- (void)didSendSMSVerificationMessage:(SMSVerification *)verification;
/*!
 @abstract Notifies delegate that the verification code validation was completed.
 @discussion This method is called in response to @link checkSMSVerificationCode: @/link.
 @param verification The verification data.
 */
- (void)didCheckSMSVerificationCode:(SMSVerification *)verification;
/*!
 @abstract Notifies delegate that the current user's verification data was fetched.
 @discussion This method is called in response to @link fetchSMSVerification @/link.
 @param verification The verification data.
 */
- (void)didFetchSMSVerification:(SMSVerification *)verification;

@end


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
 */
- (void)fetchMMCUser;
/*!
 @abstract Makes a request to update the current user's data.
 @discussion @link didUpdateMMCUser: @/link is called in response to this method.
 */
- (void)updateMMCUser:(SMMMCUserUpdate *)updates;
/*!
 @abstract Sends an SMS verification message to the specified phone number.
 @discussion @link didSendSMSVerificationMessage: @/link is called in response to this method.
 @param phoneNumber The phone number to which the SMS message will be sent.
 */
- (void)sendSMSVerificationMessageToPhoneNumber:(NSString *)phoneNumber;
/*!
 @abstract Validates the specified verification code.
 @discussion @link didCheckSMSVerificationCode: @/link is called in response to this method.
 @param code The verification code to validate.
 */
- (void)checkSMSVerificationCode:(NSString *)code;
/*!
 @abstract Makes a request to fetch the current user's verification data.
 @discussion @link didFetchSMSVerification: @/link is called in response to this method.
 */
- (void)fetchSMSVerification;

@end

#endif /* SM_IDENTITY_MANAGER */
