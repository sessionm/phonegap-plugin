//
//  SMInboxManager.h
//  SessionM
//
//
//

#ifndef __SM_INBOX_MANAGER__
#define __SM_INBOX_MANAGER__

#import <Foundation/Foundation.h>
#import "SMBaseDelegate.h"
#import "SMInboxMessage.h"

/*!
 @const SM_INBOX_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_INBOX_MANAGER_REQUEST_DID_FAIL_NOTIFICATION;
/*!
 @const SM_INBOX_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Inbox API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_INBOX_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION;
/*!
 @const SM_INBOX_MANAGER_DID_FETCH_INBOX_MESSAGES_NOTIFICATION
 @abstract Notifies observers that the current user's inbox messages were fetched.
 @discussion An <code>NSArray</code> of @link SMInboxMessage @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_INBOX_MANAGER_DID_FETCH_INBOX_MESSAGES_NOTIFICATION;
/*!
 @const SM_INBOX_MANAGER_DID_UPDATE_INBOX_MESSAGES_NOTIFICATION
 @abstract Notifies observers that inbox message states were updated by the current user.
 @discussion An <code>NSArray</code> of @link SMInboxMessage @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_INBOX_MANAGER_DID_UPDATE_INBOX_MESSAGES_NOTIFICATION;

/*!
 @typedef didFetchInboxMessages
 @abstract Completion handler block type for @link fetchInboxMessagesWithCompletionHandler: @/link.
 */
typedef void (^didFetchInboxMessages)(NSArray<SMInboxMessage *> *messages, SMError *error);
/*!
 @typedef didUpdateInboxMessages
 @abstract Completion handler block type for @link updateInboxMessage:state:completionHandler: @/link, @link updateInboxMessageID:state:completionHandler: @/link and @link updateInboxMessageIDs:state:completionHandler: @/link.
 */
typedef void (^didUpdateInboxMessages)(NSArray<SMInboxMessage *> *messages, SMError *error);


/*!
 @class SMInboxManager
 @abstract This API manager contains methods for fetching and updating message data that can be organized into a user inbox.
 */
@interface SMInboxManager : NSObject

/*!
 @property inboxMessages
 @abstract The current user's inbox messages.
 @discussion This property is updated in response to a successful @link fetchInboxMessagesWithCompletionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMInboxMessage *> *inboxMessages;

/*!
 @abstract Makes a request to update @link inboxMessages @/link with the current user's inbox messages.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchInboxMessagesWithCompletionHandler:(didFetchInboxMessages)onCompletion;
/*!
 @abstract Makes a request to update the specified message with the specified state.
 @param message The message to be updated.
 @param state The new message state.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)updateInboxMessage:(SMInboxMessage *)message state:(SMInboxMessageState)state completionHandler:(didUpdateInboxMessages)onCompletion;
/*!
 @abstract Makes a request to update the message with the specified identifier with the specified state.
 @param messageID The identifier of the message to be updated.
 @param state The new message state.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)updateInboxMessageID:(NSString *)messageID state:(SMInboxMessageState)state completionHandler:(didUpdateInboxMessages)onCompletion;
/*!
 @abstract Makes a request to update the messages with the specified identifiers with the specified state.
 @param messageIDs The identifiers of the messages to be updated.
 @param state The new message state.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)updateInboxMessageIDs:(NSArray<NSString *>*)messageIDs state:(SMInboxMessageState)state completionHandler:(didUpdateInboxMessages)onCompletion;

@end

#endif /* __SM_INBOX_MANAGER__ */
