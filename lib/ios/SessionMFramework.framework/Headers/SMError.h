//
//  SMError.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_ERROR__
#define __SM_ERROR__

#import <Foundation/Foundation.h>

/*!
 @typedef SMErrorType
 @abstract Error type.
 */
typedef enum SMErrorType {
    /*! Error type is unknown. */
    SMErrorTypeUnknown,
    /*! API request failed due to network connection loss. */
    SMErrorTypeNetwork,
    /*! Input to method was invalid. */
    SMErrorTypeValidation,
    /*! Server returned an error. */
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
- (instancetype)initWithType:(SMErrorType)type message:(NSString *)message;
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

@end

#endif /* __SM_ERROR__ */
