//
//  SMCampaignsManager.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_CAMPAIGNS_MANAGER__
#define __SM_CAMPAIGNS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMFeedMessage.h"

/*!
 @const SM_CAMPAIGNS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION;
/*!
 @const SM_CAMPAIGNS_MANAGER_DID_FETCH_FEED_MESSAGES_NOTIFICATION
 @abstract Notifies observers that campaign feed messages were fetched.
 @discussion An <code>NSArray</code> of @link SMFeedMessage @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_DID_FETCH_FEED_MESSAGES_NOTIFICATION;

/*!
 @protocol SMCampaignsDelegate
 @abstract Defines callbacks for @link SMCampaignsManager @/link methods.
 */
@protocol SMCampaignsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that promotional campaigns were fetched.
 @discussion This method is called in response to @link fetchFeedMessages @/link and @link fetchFeedMessagesWithLocale: @/link.
 @param messages The promotional campaigns.
 @deprecated Use block methods instead.
 */
- (void)didFetchFeedMessages:(NSArray<SMFeedMessage *> *)messages __attribute__((deprecated("Use block methods instead")));

@end

/*!
 @typedef didFetchFeedMessages
 @abstract Completion handler block type for @link fetchFeedMessagesWithCompletionHandler: @/link and @link fetchFeedMessagesWithLocale:completionHandler: @/link.
 */
typedef void (^didFetchFeedMessages)(NSArray<SMFeedMessage *>*messages, SMError *error);


/*!
 @class SMCampaignsManager
 @abstract This API manager contains methods for fetching promotional campaign data.
 */
@interface SMCampaignsManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMCampaignsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMCampaignsDelegate> delegate;

/*!
 @property feedMessages
 @abstract Promotional campaigns.
 @discussion This property is updated in response to a successful @link fetchFeedMessagesWithCompletionHandler: @/link or @link fetchFeedMessagesWithLocale:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMFeedMessage *> *feedMessages;

/*!
 @abstract Makes a request to update @link feedMessages @/link with promotional campaigns targeted to the current user's locale.
 @discussion @link didFetchFeedMessages: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchFeedMessagesWithCompletionHandler: @/link.
 */
- (BOOL)fetchFeedMessages __attribute__((deprecated("Use fetchFeedMessagesWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link feedMessages @/link with promotional campaigns targeted to the current user's locale.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchFeedMessagesWithCompletionHandler:(didFetchFeedMessages)onCompletion;

/*!
 @abstract Makes a request to update @link feedMessages @/link with promotional campaigns targeted to the specified locale.
 @discussion @link didFetchFeedMessages: @/link is called in response to this method.
 @param locale The locale in which the fetch will be restricted (optional - default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchFeedMessagesWithLocale:completionHandler: @/link.
 */
- (BOOL)fetchFeedMessagesWithLocale:(NSLocale *)locale __attribute__((deprecated("Use fetchFeedMessagesWithLocale:completionHandler:")));
/*!
 @abstract Makes a request to update @link feedMessages @/link with a number of promotional campaigns targeted to the specified locale.
 @param locale The locale in which the fetch will be restricted (optional - default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchFeedMessagesWithLocale:(NSLocale *)locale completionHandler:(didFetchFeedMessages)onCompletion;

@end

#endif /* __SM_CAMPAIGNS_MANAGER__ */
