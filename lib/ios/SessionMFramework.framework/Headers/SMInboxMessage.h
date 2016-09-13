//
//  SMInboxMessage.h
//  SessionM
//

#ifndef __SM_INBOX_MESSAGE__
#define __SM_INBOX_MESSAGE__

#import <Foundation/Foundation.h>

/*! 
 @typedef SMInboxMessageState
 @abstract Indicates how the user has interacted with a message.

 @constant SMInboxMessageStateUnknown Message state is unknown.
 @constant SMInboxMessageStateNew Message has not been read.
 @constant SMInboxMessageStateRead Message has been read.
 @constant SMInboxMessageStateDeleted Message has been deleted.
 */
typedef enum SMInboxMessageState {
    SMInboxMessageStateUnknown,
    SMInboxMessageStateNew,
    SMInboxMessageStateRead,
    SMInboxMessageStateDeleted
} SMInboxMessageState;


/*!
 @class SMInboxMessage
 @abstract Defines the data associated with promotional messages that can be displayed in a user's inbox.
 */
@interface SMInboxMessage : NSObject

/*!
 @property messageID
 @abstract Unique ID for message.
 */
@property(nonatomic, strong, readonly) NSString *messageID;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the message.
 */
@property(nonatomic, strong, readonly) NSString *externalID;
/*!
 @property createdTime
 @abstract Indicates when message was created.
 */
@property(nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property expiresTime
 @abstract Indicates when message will exipre.
 */
@property(nonatomic, strong, readonly) NSString *expiresTime;
/*!
 @property state
 @abstract Message state.
 */
@property(nonatomic, assign, readonly) SMInboxMessageState state;
/*!
 @property type
 @abstract Message type.
 */
@property(nonatomic, strong, readonly) NSString *type;
/*!
 @property subject
 @abstract Message subject.
 */
@property(nonatomic, strong, readonly) NSString *subject;
/*!
 @property body
 @abstract Message body.
 */
@property(nonatomic, strong, readonly) NSString *body;
/*!
 @property imageURL
 @abstract URL to image associated with the message.
 */
@property(nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property metadata
 @abstract Metadata associated with the message.
 */
@property(nonatomic, strong, readonly) NSString *metadata;
/*!
 @property data
 @abstract Custom, developer-defined data associated with the message.
 */
@property(nonatomic, strong, readonly) NSDictionary *data;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMInboxMessageState @/link enum value.
 @param string String to convert.
 @result @link SMInboxMessageState @/link enum value.
 */
+ (SMInboxMessageState)stateForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMInboxMessageState @/link enum value to the corresponding string value.
 @param state State to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForState:(SMInboxMessageState)state;

@end

#endif /* __SM_INBOX_MESSAGE__ */
