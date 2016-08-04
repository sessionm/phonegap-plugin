//
//  SMTransaction.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_TRANSACTION__
#define __SM_TRANSACTION__

#import <Foundation/Foundation.h>

/*!
 @typedef SMTransactionKind
 @abstract Transaction kind.
 */
typedef enum SMTransactionKind {
    /*! Transaction kind is unknown. */
    SMTransactionKindUnknown,                        /* unknown */
    /*! User earned points from the transaction. */
    SMTransactionKindCredit,                         /* credit */
    /*! User lost points from the transaction. */
    SMTransactionKindDebit                           /* debit */
} SMTransactionKind;

/*!
 @typedef SMTransactionSource
 @abstract Transaction source.
 */
typedef enum SMTransactionSource {
    /*! Transaction source is unknown. */
    SMTransactionSourceUnknown,                                                    /* unknown */
    /*! Points were earned by claiming an achievement. */
    SMTransactionSourceAchievement,                                                /* achievement */
    /*! Points were earned or lost from a contest. */
    SMTransactionSourceContest,                                                    /* contest */
    /*! Points were earned by engaging with sponsored content. */
    SMTransactionSourceSponsor,                                                    /* sponsor */
    /*! Points were earned or lost from a loyalty rewards program transaction. */
    SMTransactionSourceMerchantRewards,                                            /* merchant_rewards */
    /*! Points were earned through a server-to-server API call. */
    SMTransactionSourceEnterprise,                                                 /* enterprise */
    /*! Points were given to user as compensation. */
    SMTransactionSourceComp,                                                       /* comp */
    /*! Points were lost from making a rewards store purchase. */
    SMTransactionSourceUsed                                                        /* used */
} SMTransactionSource;

/*!
 @typedef SMTransactionPointsType
 @abstract Transaction points type.
 */
typedef enum SMTransactionPointsType {
    /*! Transaction points type is unknown. */
    SMTransactionPointsTypeUnknown,                                   /* unknown */
    /*! A donation was made. */
    SMTransactionPointsTypeDonation,                                  /* donation */
    /*! A sweepstakes was won or entered. */
    SMTransactionPointsTypeSweepstakes,                               /* sweepstakes */
    /*! Merchandise from a loyalty rewards program was purchased. */
    SMTransactionPointsTypeMerchandise,                               /* merchandise */
    /*! A digital reward was purchased from the rewards store. */
    SMTransactionPointsTypeDigital,                                   /* digital */
    /*! A physical reward was purchased from the rewards store. */
    SMTransactionPointsTypePhysical,                                  /* physical */
    /*! Points were earned from a receipt capture campaign. */
    SMTransactionPointsTypeReceipt,                                   /* receipt */
    /*! Points were earned from a loyalty card transaction. */
    SMTransactionPointsTypeLoyaltyCard,                               /* loyalty_card */
    SMTransactionPointsTypeHistorical                                 /* historical */
} SMTransactionPointsType;


/*!
 @class SMTransaction
 @abstract Defines the data associated with a loyalty points transaction.
 */
@interface SMTransaction : NSObject

/*!
 @property recordID
 @abstract Unique ID for transaction record.
 */
@property(nonatomic, strong, readonly) NSString *recordID;
/*!
 @property balance
 @abstract User's loyalty points balance after the transaction was made.
 */
@property(nonatomic, assign, readonly) int balance;
/*!
 @property date
 @abstract Date of transaction.
 */
@property(nonatomic, strong, readonly) NSString *date;
/*!
 @property descriptionText
 @abstract Transaction details.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText;
/*!
 @property points
 @abstract Amount of points earned or lost from the transaction.
 */
@property(nonatomic, assign, readonly) int points;
/*!
 @property recordModelID
 @abstract Associated ID for corresponding receipt submission result or loyalty card transaction.
 */
@property(nonatomic, strong, readonly) NSString *recordModelID;
/*!
 @property transaction
 @abstract Kind of transaction.
 */
@property(nonatomic, assign, readonly) SMTransactionKind transaction;
/*!
 @property source
 @abstract Source that initialized the transaction.
 */
@property(nonatomic, assign, readonly) SMTransactionSource source;
/*!
 @property type
 @abstract Type of points earned or lost from the transaction.
 */
@property(nonatomic, assign, readonly) SMTransactionPointsType type;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMTransactionKind @/link enum value.
 @param string String to convert.
 @result @link SMTransactionKind @/link enum value.
 */
+ (SMTransactionKind)transactionKindForString:(NSString *)string;
/*!
 @abstract Converts specified string value to the corresponding @link SMTransactionSource @/link enum value.
 @param string String to convert.
 @result @link SMTransactionSource @/link enum value.
 */
+ (SMTransactionSource)transactionSourceForString:(NSString *)string;
/*!
 @abstract Converts specified string value to the corresponding @link SMTransactionPointsType @/link enum value.
 @param string String to convert.
 @result @link SMTransactionPointsType @/link enum value.
 */
+ (SMTransactionPointsType)transactionPointsTypeForString:(NSString *)string;

/*!
 @abstract Converts specified @link SMTransactionKind @/link enum value to the corresponding string value.
 @param kind Transaction kind to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForTransactionKind:(SMTransactionKind)kind;
/*!
 @abstract Converts specified @link SMTransactionSource @/link enum value to the corresponding string value.
 @param source Transaction source to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForTransactionSource:(SMTransactionSource)source;
/*!
 @abstract Converts specified @link SMTransactionPointsType @/link enum value to the corresponding string value.
 @param type Transaction points type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForTransactionPointsType:(SMTransactionPointsType)type;

@end

#endif /* __SM_TRANSACTION__ */
