//
//  SMPlace.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_PLACE__
#define __SM_PLACE__

#import <Foundation/Foundation.h>

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

@interface SMPlace : NSObject

@property(nonatomic, strong, readonly) NSString        *placeID;
@property(nonatomic, strong, readonly) NSString        *name;
@property(nonatomic, assign, readonly) int              distance;
@property(nonatomic, strong, readonly) NSString        *distanceLabel;
@property(nonatomic, assign, readonly) int              acceptedDistance;
@property(nonatomic, assign, readonly) BOOL             isPromoted;
@property(nonatomic, assign, readonly) int              points;
@property(nonatomic, strong, readonly) NSString        *iconURL;
@property(nonatomic, assign, readonly) double           latitude;
@property(nonatomic, assign, readonly) double           longitude;
@property(nonatomic, strong, readonly) NSString        *address;
@property(nonatomic, strong, readonly) NSString        *city;
@property(nonatomic, strong, readonly) NSString        *state;
@property(nonatomic, assign, readonly) SMCheckinStatus  checkinStatus;
@property(nonatomic, assign, readonly) long             unlockTime;
@property(nonatomic, strong, readonly) NSDictionary *extras;


@end

#endif /* __SM_PLACE__ */
