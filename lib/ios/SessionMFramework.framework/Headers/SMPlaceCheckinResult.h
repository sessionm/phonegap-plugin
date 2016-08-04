//
//  SMPlaceCheckinResult.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_PLACE_CHECKIN_RESULT__
#define __SM_PLACE_CHECKIN_RESULT__

#import <Foundation/Foundation.h>
#import "SMFeedMessage.h"

@interface SMPlaceCheckinResult : NSObject

@property(nonatomic, strong, readonly) SMFeedMessage *message;

@property(nonatomic, strong, readonly)NSString *placeID;
@property(nonatomic, strong, readonly)NSString *state;
@property(nonatomic, assign, readonly)NSString *canCheckinAgainAt;
@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_PLACE_CHECKIN_RESULT__ */
