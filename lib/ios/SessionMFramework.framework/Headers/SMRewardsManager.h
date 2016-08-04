//
//  SMRewardsManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_REWARDS_MANAGER__
#define __SM_REWARDS_MANAGER__

#import <Foundation/Foundation.h>
#import "SMAddress.h"
#import "SMBaseDelegate.h"
#import "SMOffer.h"
#import "SMOrder.h"
#import "SMSkillChallenge.h"

@protocol SMRewardsDelegate <SMBaseDelegate>

@optional

-(void)didFetchOffers:(NSArray<SMOffer *> *)offers;

-(void)didFetchOrders:(NSArray<SMOrder *> *)orders;
-(void)didPlaceOrder:(SMOrder *)order;

-(void)didFetchSkillQuestion:(SMSkillQuestion *)question;
-(void)didAnswerSkillQuestion:(SMSkillChallenge *)challenge;

@end

@interface SMOrderRequest : NSObject

@property (nonatomic, strong)NSString *offerID;
@property (nonatomic, strong)NSNumber *quantity;
@property (nonatomic, strong)NSString *email;
@property (nonatomic, strong)NSString *ip;
@property (nonatomic, strong)SMAddress *shippingAddress;
@property (nonatomic, strong)NSString *challengeID;

-(instancetype)initWithOfferID:(NSString *)offerID quantity:(NSNumber *)quantity;
-(NSDictionary *)asDictionary;
@end

@interface SMRewardsManager : NSObject

@property (nonatomic, weak)id<SMRewardsDelegate>delegate;
@property (nonatomic, strong, readonly)NSArray<SMOffer *>*offers;
@property (nonatomic, strong, readonly)NSArray<SMOrder *>*orders;

-(instancetype)init;

-(void)fetchOffers;
-(void)fetchOffersWithLocale:(NSLocale *)locale;

-(void)placeOrder:(SMOrderRequest *)request;
-(void)fetchOrders;

-(void)fetchSkillQuestion;
-(void)answerSkillQuestionForOfferID:(NSString *)offerID questionID:(NSString *)questionID answer:(NSString *)answer;

@end

#endif /* __SM_REWARDS_MANAGER__ */
