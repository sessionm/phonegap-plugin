//
//  SMMessage.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_MESSAGE__
#define __SM_MESSAGE__

#import <Foundation/Foundation.h>

/*!
 @typedef SMMessageActionType
 @abstract Determines how message content is displayed.

 @constant SMMessageActionTypeUnknown Unknown action type.
 @constant SMMessageActionTypeDeepLink Deep links into app.
 @constant SMMessageActionTypeFullScreen Presents full screen rich media message.
 @constant SMMessageActionTypeExternalLink Opens link in Safari.
 */
typedef enum SMMessageActionType {
    SMMessageActionTypeUnknown,
    SMMessageActionTypeDeepLink,
    SMMessageActionTypeFullScreen,
    SMMessageActionTypeExternalLink
} SMMessageActionType;


/*!
 @class SMMessage
 @abstract Defines the data associated with a message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Mobile Marketing Cloud portal.
 */
@interface SMMessage : NSObject

/*!
 @property messageID
 @abstract Unique ID for message.
 */
@property(nonatomic, copy, readonly) NSString *messageID;
/*!
 @property campaignID
 @abstract ID of promotional campaign associated with the message.
 */
@property(nonatomic, copy, readonly) NSString *campaignID;
/*!
 @property startTime
 @abstract Indicates when the promotion began.
 */
@property(nonatomic, copy, readonly) NSString *startTime;
/*!
 @property endTime
 @abstract Indicates when the promotion ends.
 */
@property(nonatomic, copy, readonly) NSString *endTime;
/*!
 @property type
 @abstract Message type.
 */
@property(nonatomic, copy, readonly) NSString *type;
/*!
 @property eventMetaData
 @abstract Metadata associated with the message from the @link //apple_ref/occ/instm/SessionM/logAction:withCount:payloads: @/link method.
 */
@property(nonatomic, copy, readonly) NSDictionary *eventMetaData;
/*!
 @property actionType
 @abstract Determines how the content pointed to by @link actionURL @/link is displayed when @link //apple_ref/occ/instm/SessionM/executeMessageAction: @/link is called with an instance of this class.
 */
@property(nonatomic, assign, readonly) SMMessageActionType actionType;
/*!
 @property header
 @abstract Message title.
 */
@property(nonatomic, copy, readonly) NSString *header;
/*!
 @property subheader
 @abstract Message subtitle.
 */
@property(nonatomic, copy, readonly) NSString *subheader;
/*!
 @property descriptionText
 @abstract Message text.
 */
@property(nonatomic, copy, readonly) NSString *descriptionText;
/*!
 @property actionURL
 @abstract URL for content that is displayed when @link //apple_ref/occ/instm/SessionM/executeMessageAction: @/link is called with an instance of this class.
 */
@property(nonatomic, copy, readonly) NSString *actionURL;
/*!
 @property data
 @abstract Custom, developer-defined data associated with the messsage.
 */
@property(nonatomic, copy, readonly) NSDictionary *data;
/*!
 @property points
 @abstract The amount of points that use can earn by interacting with the message.
 */
@property(nonatomic, assign, readonly) int points;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Notifies the SDK that the view containing the associated message data was presented to the user. Used for reporting purposes.
 */
- (void)notifyPresented;
/*!
 @abstract Notifies the SDK that the view containing the associated message data was seen by the user. Used for reporting purposes.
 */
- (void)notifySeen;
/*!
 @abstract Notifies the SDK that the user tapped on the view containing the associated message data. Used for reporting purposes.
 */
- (void)notifyTapped;

/*!
 @abstract Converts specified string value to the corresponding @link SMMessageActionType @/link enum value.
 @param string String to convert.
 @result @link SMMessageActionType @/link enum value.
 */
+ (SMMessageActionType)typeForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMMessageActionType @/link enum value to the corresponding string value.
 @param type Type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForType:(SMMessageActionType)type;

@end

#endif /* __SM_MESSAGE__ */
