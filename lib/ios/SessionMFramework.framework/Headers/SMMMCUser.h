//
//  SMMMCUser.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_MMC_USER__
#define __SM_MMC_USER__

#import <Foundation/Foundation.h>

/*!
 @typedef SMAccountStatus
 @abstract User account status.
 */
typedef enum SMAccountStatus {
    /*! Account status is unknown. */
    SMAccountStatusUnknown,                                                                    /* unknown */
    /*! User is in good standing. */
    SMAccountStatusGood,                                                                       /* good */
    /*! User has been blocked due to having multiple accounts. */
    SMAccountStatusMultipleAccountsViolation,                                                  /* multi */
    /*! User has been reported as violating the Terms of Service agreement. */
    SMAccountStatusReportedViolation,                                                          /* reported */
    /*! User has requested that their account be suspended. */
    SMAccountStatusRequestedSuspension,                                                        /* vol */
    /*! User's reported Terms of Service agreement violation has been reviewed by an admin. */
    SMAccountStatusReviewedReport,                                                             /* rev */
    /*! User has been blocked due to violating the Terms of Service agreement. */
    SMAccountStatusTOSViolation,                                                               /* tos */
    /*! User's account has not been verified. */
    SMAccountStatusUnverified,                                                                 /* unverified */
    /*! User has been warned for violating the Terms of Service agreement. */
    SMAccountStatusWarned                                                                      /* warn */
} SMAccountStatus;


/*!
 @class SMMMCUser
 @abstract Defines the data associated with a user in the SessionM Mobile Marketing Cloud.
 */
@interface SMMMCUser : NSObject

/*!
 @property userID
 @abstract Unique ID for user.
 */
@property(nonatomic, strong, readonly) NSString *userID;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the user.
 */
@property(nonatomic, strong, readonly) NSString *externalID;
/*!
 @property proxyIDs
 @abstract IDs defined by third-party organizations that are associated with the user.
 */
@property(nonatomic, strong, readonly) NSArray<NSString *> *proxyIDs;
/*!
 @property createdTime
 @abstract Denotes when user data was created.
 */
@property(nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property updatedTime
 @abstract Denotes when user data was last updated.
 */
@property(nonatomic, strong, readonly) NSString *updatedTime;
/*!
 @property firstName
 @abstract User's first name.
 */
@property(nonatomic, strong, readonly) NSString *firstName;
/*!
 @property lastName
 @abstract User's last name.
 */
@property(nonatomic, strong, readonly) NSString *lastName;
/*!
 @property email
 @abstract User's email address.
 */
@property(nonatomic, strong, readonly) NSString *email;
/*!
 @property dateOfBirth
 @abstract User's date of birth.
 */
@property(nonatomic, strong, readonly) NSString *dateOfBirth;
/*!
 @property gender
 @abstract User's gender.
 */
@property(nonatomic, strong, readonly) NSString *gender;
/*!
 @property zipCode
 @abstract User's home zip code.
 */
@property(nonatomic, strong, readonly) NSString *zipCode;
/*!
 @property DMA
 @abstract User's home designated market area.
 */
@property(nonatomic, strong, readonly) NSString *DMA;
/*!
 @property state
 @abstract User's state or province of residence.
 */
@property(nonatomic, strong, readonly) NSString *state;
/*!
 @property country
 @abstract User's country of residence.
 */
@property(nonatomic, strong, readonly) NSString *country;
/*!
 @property latitude
 @abstract User's current latitude.
 */
@property(nonatomic, assign, readonly) double latitude;
/*!
 @property longitude
 @abstract User's current longitude.
 */
@property(nonatomic, assign, readonly) double longitude;
/*!
 @property currentZipCode
 @abstract User's current zip code.
 */
@property(nonatomic, strong, readonly) NSString *currentZipCode;
/*!
 @property currentDMA
 @abstract User's current designated market area.
 */
@property(nonatomic, strong, readonly) NSString *currentDMA;
/*!
 @property currentState
 @abstract User's current state or province.
 */
@property(nonatomic, strong, readonly) NSString *currentState;
/*!
 @property currentCountry
 @abstract User's current country.
 */
@property(nonatomic, strong, readonly) NSString *currentCountry;
/*!
 @property userProfile
 @abstract Developer-defined attributes that can be used for analytics, targeting ads, etc.
 */
@property(nonatomic, strong, readonly) NSDictionary *userProfile;
/*!
 @property availablePoints
 @abstract User's current loyalty points balance.
 */
@property(nonatomic, assign, readonly) int availablePoints;
/*!
 @property testPoints
 @abstract The number of loyalty points that the user has earned from apps that are in development mode.
 */
@property(nonatomic, assign, readonly) int testPoints;
/*!
 @property unclaimedAchievementCount
 @abstract The number of achievements that the user has earned, but not claimed.
 */
@property(nonatomic, assign, readonly) int unclaimedAchievementCount;
/*!
 @property nextTierPercentage
 @abstract User's progress towards the next rewards tier.
 */
@property(nonatomic, assign, readonly) double nextTierPercentage;
/*!
 @property accountStatus
 @abstract User's account status.
 */
@property(nonatomic, assign, readonly) SMAccountStatus accountStatus;
/*!
 @property isSuspended
 @abstract Denotes whether the user's account is suspended.
 */
@property(nonatomic, assign, readonly) BOOL isSuspended;
/*!
 @property isTestAccount
 @abstract Denotes whether the user's account is a test account.
 */
@property(nonatomic, assign, readonly) BOOL isTestAccount;

@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Returns user data in a formatted string.
 @result Formatted <code>NSString</code> representation of user data.
 */
- (NSString *)asString;

/*!
 @abstract Returns user data in a dictionary format.
 @result <code>NSDictionary</code> representation of user data.
 */
- (NSDictionary *)asDictionary;

/*!
 @abstract Converts specified string value to the corresponding @link SMAccountStatus @/link enum value.
 @param string String to convert.
 @result @link SMAccountStatus @/link enum value.
 */
+ (SMAccountStatus)statusForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMAccountStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMAccountStatus)status;

@end

#endif /* __SM_MMC_USER__ */
