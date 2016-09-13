//
//  SMPlaceCheckinResult.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_PLACE_CHECKIN_RESULT__
#define __SM_PLACE_CHECKIN_RESULT__

#import <Foundation/Foundation.h>
#import "SMFeedMessage.h"

/*!
 @class SMPlaceCheckinResult
 @abstract Defines the data associated with the server-side response for checking into a location.
 */
@interface SMPlaceCheckinResult : NSObject

/*!
 @property message
 @abstract Defines data associated with a bonus opportunity earned for a successful checkin.
 */
@property(nonatomic, strong, readonly) SMFeedMessage *message;
/*!
 @property placeID
 @abstract ID of place that was checked into.
 */
@property(nonatomic, strong, readonly) NSString *placeID;
/*!
 @property state
 @abstract Checkin state.
 */
@property(nonatomic, strong, readonly) NSString *state;
/*!
 @property canCheckInAgainAt
 @abstract Indicates when place can be checked into again.
 */
@property(nonatomic, assign, readonly) NSString *canCheckInAgainAt;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_PLACE_CHECKIN_RESULT__ */
