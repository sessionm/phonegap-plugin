//
//  SMSkillChallenge.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_SKILL_CHALLENGE__
#define __SM_SKILL_CHALLENGE__

#import "SMSkillQuestion.h"

@interface SMSkillChallenge : NSObject

@property(nonatomic, strong, readonly) NSString *challengeID;
@property(nonatomic, strong, readonly) NSString *status;
@property (nonatomic, strong, readonly) NSDictionary *extras;
@end

#endif /* __SM_SKILL_CHALLENGE__ */
