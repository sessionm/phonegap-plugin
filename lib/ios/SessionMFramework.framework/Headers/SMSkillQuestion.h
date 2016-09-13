//
//  SMSkillQuestion.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_SKILL_QUESTION__
#define __SM_SKILL_QUESTION__

/*!
 @class SMSkillQuestion
 @abstract Defines the data associated with a skill testing question used to gate sweepstakes entries.
 */
@interface SMSkillQuestion : NSObject

/*!
 @property questionID
 @abstract Unique ID for skill question.
 */
@property(nonatomic, strong, readonly) NSString *questionID;
/*!
 @property question
 @abstract The question that must be answered correctly in order to enter the sweepstakes (e.g. a mathematical equation).
 */
@property(nonatomic, strong, readonly) NSString *question;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

@end

#endif /* __SM_SKILL_QUESTION__ */
