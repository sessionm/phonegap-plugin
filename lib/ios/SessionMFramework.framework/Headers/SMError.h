//
//  SMError.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_ERROR__
#define __SM_ERROR__

#import <Foundation/Foundation.h>

/*!
 @typedef SMErrorType
 @abstract Indicates how error occurred.

 @constant SMErrorTypeUnknown Error type is unknown.
 @constant SMErrorTypeNetwork API request failed due to network connection loss.
 @constant SMErrorTypeValidation Input to method was invalid.
 @constant SMErrorTypeServerError Server returned an error.
 */
typedef enum SMErrorType {
    SMErrorTypeUnknown,
    SMErrorTypeNetwork,
    SMErrorTypeValidation,
    SMErrorTypeServerError
} SMErrorType;


/*!
 @class SMError
 @abstract Defines the data associated with an error received from a SessionM Mobile Marketing Cloud SDK API method.
 */
@interface SMError : NSObject

/*!
 @property type
 @abstract Error type.
 */
@property(nonatomic, assign, readonly) SMErrorType type;
/*!
 @property message
 @abstract Error message text.
 */
@property(nonatomic, strong, readonly) NSString *message;
/*!
 @property code
 @abstract Error code from server.
 */
@property(nonatomic, strong, readonly) NSString *code;
/*!
 @property raw
 @abstract Raw error data returned by the server.
 */
@property(nonatomic, strong, readonly) NSDictionary *raw;

/*!
 @abstract Creates an instance of <code>SMError</code> with the specified error type and message text.
 @param type Error type.
 @param message Error message text.
 @result <code>SMError</code> instance.
 */
- (instancetype)initWithType:(SMErrorType)type code:(NSString *)code message:(NSString *)message;
/*!
 @abstract Creates an instance of <code>SMError</code> with the specified error type and message text.
 @param type Error type.
 @param result Entire result given to handler.
 @param makeMessage Block that is called to convert error into a message.
 @result <code>SMError</code> instance.
 */
- (instancetype)initWithType:(SMErrorType)type result:(NSDictionary *)result makeMessage:(NSString *(^)(NSDictionary *error))makeMessage;

/*!
 @abstract Converts specified string value to the corresponding @link SMErrorType @/link enum value.
 @param string String to convert.
 @result @link SMErrorType @/link enum value.
 */
+ (SMErrorType)errorTypeForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMErrorType @/link enum value to the corresponding string value.
 @param type Error type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForErrorType:(SMErrorType)type;

extern NSString * const SMErrorServerIssue;
extern NSString * const SMErrorServerNoRequest;
extern NSString * const SMErrorServerBadJson;

extern NSString * const SMErrorValidation;
extern NSString * const SMErrorValidationNoUpdates;
extern NSString * const SMErrorValidationNoPhone;
extern NSString * const SMErrorValidationNoCode;
extern NSString * const SMErrorValidationNoCardNumber;
extern NSString * const SMErrorValidationNoCardID;
extern NSString * const SMErrorValidationNoRetailerID;
extern NSString * const SMErrorValidationNoLocation;
extern NSString * const SMErrorValidationNoPlace;
extern NSString * const SMErrorValidationNoPlaceID;
extern NSString * const SMErrorValidationNoPaths;
extern NSString * const SMErrorValidationNoCampaignID;
extern NSString * const SMErrorValidationNoAssetIDs;
extern NSString * const SMErrorValidationBadGroupID;
extern NSString * const SMErrorValidationNoGroupID;
extern NSString * const SMErrorValidationBadUploadData;
extern NSString * const SMErrorValidationInvalidEmail;
extern NSString * const SMErrorValidationDuplicateEmail;
extern NSString * const SMErrorValidationNoReferral;
extern NSString * const SMErrorValidationNoReferralID;
extern NSString * const SMErrorValidationNoOfferID;
extern NSString * const SMErrorValidationNoQuestionID;
extern NSString * const SMErrorValidationNoAnswer;
extern NSString * const SMErrorValidationBadDates;
extern NSString * const SMErrorValidationNoContentID;
extern NSString * const SMErrorValidationNoExternalID;
extern NSString * const SMErrorValidationNoZipCode;
extern NSString * const SMErrorValidationNoMessageID;

@end

#endif /* __SM_ERROR__ */
