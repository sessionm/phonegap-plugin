//
//  SMSkillQuestion.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_SKILL_QUESTION__
#define __SM_SKILL_QUESTION__

@interface SMSkillQuestion : NSObject

@property (nonatomic, strong, readonly) NSString *questionID;
@property (nonatomic, strong, readonly) NSString *question;
@property (nonatomic, strong, readonly) NSDictionary *extras;
@end

#endif /* __SM_SKILL_QUESTION__ */
