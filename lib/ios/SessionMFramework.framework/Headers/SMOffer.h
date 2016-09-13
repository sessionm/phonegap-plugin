//
//  SMOffer.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_OFFER__
#define __SM_OFFER__

#import <Foundation/Foundation.h>

/*!
 @typedef SMOfferStatus
 @abstract Offer eligibility status.

 @constant SMOfferStatusUnknown Offer status is unknown.
 @constant SMOfferStatusAvailable Offer is available for redemption.
 @constant SMOfferStatusVerificationRequired Offer requires verification.
 @constant SMOfferStatusNotQualified User is not qualified for offer.
 @constant SMOfferStatusInsufficientPoints User doesn't have enough points.
 @constant SMOfferStatusUserRequired Session needs to have a user active.
 @constant SMOfferStatusRegistrationRequired User needs to be registered.
 */
typedef enum SMOfferStatus {
    SMOfferStatusUnknown,
    SMOfferStatusAvailable,
    SMOfferStatusVerificationRequired,
    SMOfferStatusNotQualified,
    SMOfferStatusInsufficientPoints,
    SMOfferStatusUserRequired,
    SMOfferStatusRegistrationRequired
} SMOfferStatus;


/*!
 @class SMOffer
 @abstract Defines the data associated with an offer order made by a user.
 */
@interface SMOffer : NSObject

/*!
 @property offerID
 @abstract Unique ID for offer.
 */
@property(nonatomic, strong, readonly) NSString           *offerID;
/*!
 @property name
 @abstract Offer name.
 */
@property(nonatomic, strong, readonly) NSString           *name;
/*!
 @property type
 @abstract Reward type (e.g. "offer" or "coupon").
 */
@property(nonatomic, strong, readonly) NSString           *type;
/*!
 @property descriptionText
 @abstract Offer description.
 */
@property(nonatomic, strong, readonly) NSString           *descriptionText;
/*!
 @property points
 @abstract Amount of points needed to redeem offer.
 */
@property(nonatomic, assign, readonly) int                 points;
/*!
 @property startTime
 @abstract Indicates when the offer became available for redemption.
 */
@property(nonatomic, strong, readonly) NSString           *startTime;
/*!
 @property endTime
 @abstract Indicates when the offer will no longer be available for redemption.
 */
@property(nonatomic, strong, readonly) NSString           *endTime;
/*!
 @property weight
 @abstract Developer-defined numerical value that can be used to sort offers.
 */
@property(nonatomic, assign, readonly) int                 weight;
/*!
 @property isFeatured
 @abstract Defines whether the offer is in the rewards system's list of featured offers.
 */
@property(nonatomic, assign, readonly) BOOL                isFeatured;
/*!
 @property isSkillChallengeRequired
 @abstract Defines whether a user must pass a skill challenge to redeem the offer.
 */
@property(nonatomic, assign, readonly) BOOL                isSkillChallengeRequired;
/*!
 @property tier
 @abstract If tiers are enabled in the rewards system, defines what tier a user must reach to redeem the offer.
 */
@property(nonatomic, strong, readonly) NSString           *tier;
/*!
 @property logoURL
 @abstract URL to image associated with the offer.
 */
@property(nonatomic, strong, readonly) NSString           *logoURL;
/*!
 @property status
 @abstract Offer eligibility status.
 */
@property(nonatomic, assign, readonly) SMOfferStatus       status;
/*!
 @property data
 @abstract Custom developer-defined data associated with the offer.
 */
@property(nonatomic, strong, readonly) NSDictionary       *data;
/*!
 @property options
 @abstract List of variants for the offer that differ in some aspect (e.g. additional sizes for a shirt).
 */
@property(nonatomic, strong, readonly) NSArray<SMOffer *> *options;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary       *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMOfferStatus @/link enum value.
 @param string String to convert.
 @result @link SMOfferStatus @/link enum value.
 */
+ (SMOfferStatus)statusForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMOfferStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMOfferStatus)status;

@end

#endif /* __SM_OFFER__ */
