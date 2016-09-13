//
//  SMMMCUserUpdate.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_MMC_USER_UPDATE__
#define __SM_MMC_USER_UPDATE__

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*!
 @class SMMMCUserUpdate
 @abstract Defines the data associated with a user data update request.
 */
@interface SMMMCUserUpdate : NSObject
/*!
 @property email
 @abstract User's email address.
 */
@property(nonatomic, strong, readwrite) NSString *email;
/*!
 @property firstName
 @abstract User's first name.
 */
@property(nonatomic, strong, readwrite) NSString *firstName;
/*!
 @property lastName
 @abstract User's last name.
 */
@property(nonatomic, strong, readwrite) NSString *lastName;
/*!
 @property gender
 @abstract User's gender.
 */
@property(nonatomic, strong, readwrite) NSString *gender;
/*!
 @property dateOfBirth
 @abstract User's date of birth.
 */
@property(nonatomic, strong, readwrite) NSString *dateOfBirth;
/*!
 @property zipCode
 @abstract User's zip code.
 */
@property(nonatomic, strong, readwrite) NSString *zipCode;
/*!
 @property DMA
 @abstract User's home designated market area.
 */
@property(nonatomic, strong, readwrite) NSString *DMA;
/*!
 @property state
 @abstract User's state.
 */
@property(nonatomic, strong, readwrite) NSString *state;
/*!
 @property country
 @abstract User's country.
 */
@property(nonatomic, strong, readwrite) NSString *country;
/*!
 @property locale
 @abstract User's locale.
 */
@property(nonatomic, strong, readwrite) NSString *locale;
/*!
 @property latitude
 @abstract User's latitude.
 */
@property(nonatomic, assign, readwrite) CLLocationDegrees latitude;
/*!
 @property longitude
 @abstract User's longitude.
 */
@property(nonatomic, assign, readwrite) CLLocationDegrees longitude;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the user.
 */
@property(nonatomic, strong, readwrite) NSString *externalID;
/*!
 @property ipAddress
 @abstract User's IP address.
 */
@property(nonatomic, strong, readwrite) NSString *ipAddress;
/*!
 @property userProfile
 @abstract User's user profile.
 */
@property(nonatomic, strong, readwrite) NSDictionary *userProfile;
/*!
 @property dictionary
 @abstract Returns user data in a dictionary format.
 */
@property(nonatomic, strong, readonly)  NSDictionary *dictionary;

@end

#endif
