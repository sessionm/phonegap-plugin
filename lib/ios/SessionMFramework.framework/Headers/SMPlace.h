//
//  SMPlace.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_PLACE__
#define __SM_PLACE__

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*!
 @typedef SMCheckinStatus
 @abstract Indicates checkin availability.

 @constant SMCheckinStatusNotCheckable User cannot check into the venue.
 @constant SMCheckinStatusCheckable User is within range of the venue.
 @constant SMCheckinStatusAlreadyCheckedInCheckable User is within range of the venue, but cannot check in because they have recently checked in.
 @constant SMCheckinStatusAlreadyCheckedInTooFar User is too far to check into the venue, and have recently checked in.
 @constant SMCheckinStatusBlockedCheckable User is within range of the venue, but cannot check in because they have reached the checkin limit for the venue's brand or category.
 @constant SMCheckinStatusBlockedTooFar User is too far to check into the venue, and has reached the checkin limit for the venue's brand or category.
 @constant SMCheckinStatusBlockedLimitHit User has reached the daily checkin limit.
 @constant SMCheckinStatusTooFar User is too far to check into the venue.
 */
typedef enum SMCheckinStatus {
    SMCheckinStatusNotCheckable,
    SMCheckinStatusCheckable,
    SMCheckinStatusAlreadyCheckedInCheckable,
    SMCheckinStatusAlreadyCheckedInTooFar,
    SMCheckinStatusBlockedCheckable,
    SMCheckinStatusBlockedTooFar,
    SMCheckinStatusBlockedLimitHit,
    SMCheckinStatusTooFar
} SMCheckinStatus;


/*!
 @class SMPlace
 @abstract Defines the data associated with a sponsored venue that can be checked into.
 */
@interface SMPlace : NSObject

/*!
 @property placeID
 @abstract Unique ID for place.
 */
@property(nonatomic, strong, readonly) NSString        *placeID;
/*!
 @property name
 @abstract Place name.
 */
@property(nonatomic, strong, readonly) NSString        *name;
/*!
 @property distance
 @abstract User's distance to place.
 */
@property(nonatomic, assign, readonly) int              distance;
/*!
 @property distanceLabel
 @abstract User's distance to place (includes units for distance).
 */
@property(nonatomic, strong, readonly) NSString        *distanceLabel;
/*!
 @property acceptedDistance
 @abstract Maximum value for @link distance @/link for which the user can check in.
 */
@property(nonatomic, assign, readonly) int              acceptedDistance;
/*!
 @property isPromoted
 @abstract Indicates whether there is a promotional campaign for the place.
 */
@property(nonatomic, assign, readonly) BOOL             isPromoted;
/*!
 @property points
 @abstract Amount of points received for a successful checkin.
 */
@property(nonatomic, assign, readonly) int              points;
/*!
 @property iconURL
 @abstract URL to image associated with the place.
 */
@property(nonatomic, strong, readonly) NSString        *iconURL;
/*!
 @property latitude
 @abstract Latitude value for place.
 */
@property(nonatomic, assign, readonly) CLLocationDegrees latitude;
/*!
 @property longitude
 @abstract Longitude value for place.
 */
@property(nonatomic, assign, readonly) CLLocationDegrees longitude;
/*!
 @property address
 @abstract Address where place is located.
 */
@property(nonatomic, strong, readonly) NSString        *address;
/*!
 @property city
 @abstract City the place is located in.
 */
@property(nonatomic, strong, readonly) NSString        *city;
/*!
 @property state
 @abstract State the place is located in.
 */
@property(nonatomic, strong, readonly) NSString        *state;
/*!
 @property checkinStatus
 @abstract Checkin result status.
 */
@property(nonatomic, assign, readonly) SMCheckinStatus  checkinStatus;
/*!
 @property unlockTime
 @abstract Indicates when place can be checked into again.
 */
@property(nonatomic, assign, readonly) long             unlockTime;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMCheckinStatus @/link enum value.
 @param string String to convert.
 @result @link SMCheckinStatus @/link enum value.
 */
+ (SMCheckinStatus)statusForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMCheckinStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMCheckinStatus)status;

@end

#endif /* __SM_PLACE__ */
