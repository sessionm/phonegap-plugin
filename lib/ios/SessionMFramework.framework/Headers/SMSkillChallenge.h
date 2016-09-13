//
//  SMSkillChallenge.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_SKILL_CHALLENGE__
#define __SM_SKILL_CHALLENGE__

/*!
 @class SMSkillChallenge
 @abstract Defines the data associated with the server-side response for a user's answer to a skill testing question (see @link //apple_ref/occ/cl/SMSkillTestQuestion @/link).
 */
@interface SMSkillChallenge : NSObject

/*!
 @property challengeID
 @abstract Unique ID for skill challenge.
 */
@property(nonatomic, strong, readonly) NSString *challengeID;
/*!
 @property status
 @abstract Response status for the answered skill testing question (e.g. "valid" or "invalid").
 */
@property(nonatomic, strong, readonly) NSString *status;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_SKILL_CHALLENGE__ */
