//
//  SMContent.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_CONTENT__
#define __SM_CONTENT__

#import <Foundation/Foundation.h>

/*!
 @typedef SMContentState
 @abstract Content development state.

 @constant SMContentStateUnknown Content state is unknown.
 @constant SMContentStateLive Content is live and should be made visible to users.
 @constant SMContentStatePreview Content is in development and should not be made visible to users.
 */
typedef enum SMContentState {
    SMContentStateUnknown,
    SMContentStateLive,
    SMContentStatePreview
} SMContentState;


/*!
 @class SMContent
 @abstract Defines the data associated with a promotional item in a content feed.
 */
@interface SMContent : NSObject

/*!
 @property contentID
 @abstract Unique ID for content.
 */
@property(nonatomic, strong, readonly) NSString *contentID;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the content.
 */
@property(nonatomic, strong, readonly) NSString *externalID;
/*!
 @property name
 @abstract Content name.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property type
 @abstract Content type.
 */
@property(nonatomic, strong, readonly) NSString *type;
/*!
 @property contentState
 @abstract String value converted from @link state @/link.
 */
@property(nonatomic, strong, readonly) NSString *contentState;
/*!
 @property state
 @abstract Content state.
 */
@property(nonatomic, assign, readonly) SMContentState state;
/*!
 @property descriptionText
 @abstract Content description.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText;
/*!
 @property weight
 @abstract Developer-defined numerical value that can be used to sort contents.
 */
@property(nonatomic, assign, readonly) NSInteger weight;
/*!
 @property imageURL
 @abstract URL to image associated with the content.
 */
@property(nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property createdTime
 @abstract Indicates when content was created.
 */
@property(nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property updatedTime
 @abstract Indicates when content was updated.
 */
@property(nonatomic, strong, readonly) NSString *updatedTime;
/*!
 @property expiresTime
 @abstract Indicates when content will expire.
 */
@property(nonatomic, strong, readonly) NSString *expiresTime;
/*!
 @property metadata
 @abstract Metadata associated with the content.
 */
@property(nonatomic, strong, readonly) NSDictionary *metadata;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nonatomic, strong, readonly) NSDictionary *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMContentState @/link enum value.
 @param string String to convert.
 @result @link SMContentState @/link enum value.
 */
+ (SMContentState)stateForString:(NSString *)string;
/*!
 @abstract Converts specified @link SMContentState @/link enum value to the corresponding string value.
 @param state State to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForState:(SMContentState)state;

@end

#endif /* __SM_CONTENT__ */
