//
//  SMPlacesManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_PLACES_MANAGER__
#define __SM_PLACES_MANAGER__

#import <CoreLocation/CLLocation.h>
#import "SMBaseDelegate.h"
#import "SMPlace.h"
#import "SMPlaceCheckinResult.h"

extern const float SM_PLACES_MANAGER_DEFAULT_FETCH_RADIUS;
extern const int SM_PLACES_MANAGER_DEFAULT_FETCH_LIMIT;

@protocol SMPlacesDelegate <SMBaseDelegate>

@optional

- (void)didFetchPlaces:(NSArray<SMPlace *> *)places;
- (void)didCheckIn:(SMPlaceCheckinResult *)checkin;

@end


@interface SMPlacesManager : NSObject

@property(nonatomic, weak) id<SMPlacesDelegate> delegate;
@property(nonatomic, strong, readonly) NSArray<SMPlace *> *places;

- (void)fetchPlacesAroundLocation:(CLLocation *)location;
- (void)fetchPlacesAroundLocation:(CLLocation *)location withRadius:(float)radius limit:(int)limit adUnitID:(NSString *)adUnitID;
- (void)checkInPlace:(SMPlace *)place;

@end

#endif /* __SM_PLACES_MANAGER__ */
