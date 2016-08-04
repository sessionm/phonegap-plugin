//
//  SMOffer.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_OFFER__
#define __SM_OFFER__

#import <Foundation/Foundation.h>

typedef enum SMOfferStatus {
    /*! Offer status is unknown. */
    SMOfferStatusUnknown = 0,                            /* unknown */
    /*! Offer is available for redemption. */
    SMOfferStatusAvailable,                              /* available */
    /*! Offer requires verification. */
    SMOfferStatusVerificationRequired,                   /* verification_required */
    /*! User is not qualified for offer. */
    SMOfferStatusNotQualified,                           /* not_qualified */
    /*! User doesn't have enough points. */
    SMOfferStatusInsufficientPoints,                     /* insufficient_points */
    /*! Session needs to have a user active. */
    SMOfferStatusUserRequired,                           /* user_required */
    /*! User needs to be registered. */
    SMOfferStatusRegistrationRequired                    /* registration_required */
} SMOfferStatus;

@interface SMOffer : NSObject

@property (nonatomic, strong, readonly)NSString *offerID;
@property (nonatomic, strong, readonly)NSString *name;
@property (nonatomic, strong, readonly)NSString *type;
@property (nonatomic, strong, readonly)NSString *descriptionText;
@property (nonatomic, assign, readonly)int       points;
@property (nonatomic, strong, readonly)NSString *startTime;
@property (nonatomic, strong, readonly)NSString *endTime;
@property (nonatomic, assign, readonly)int       weight;
@property (nonatomic, assign, readonly)BOOL      isFeatured;
@property (nonatomic, assign, readonly)BOOL      isSkillChallengeRequired;
@property (nonatomic, strong, readonly)NSString *tier;
@property (nonatomic, strong, readonly)NSString *logoURL;

@property (nonatomic, assign, readonly)SMOfferStatus status;
@property (nonatomic, strong, readonly)NSDictionary *data;
@property (nonatomic, strong, readonly)NSArray<SMOffer *> *options;

@property (nonatomic, strong, readonly) NSDictionary *extras;

+ (SMOfferStatus)statusForString:(NSString *)string;
+ (NSString *)stringForStatus:(SMOfferStatus)status;

@end

#endif /* __SM_OFFER__ */