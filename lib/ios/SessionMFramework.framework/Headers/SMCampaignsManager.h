//
//  SMCampaignsManager.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_CAMPAIGNS_MANAGER__
#define __SM_CAMPAIGNS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMFeedMessage.h"

/*!
 @const SM_CAMPAIGNS_MANAGER_DEFAULT_FETCH_LIMIT
 @abstract The default maximum amount of campaigns to fetch when calling @link fetchFeedMessages @/link and @link fetchFeedMessagesWithLocale:limit: @/link.
 */
extern const int SM_CAMPAIGNS_MANAGER_DEFAULT_FETCH_LIMIT;


/*!
 @protocol SMCampaignsDelegate
 @abstract Defines callbacks for @link SMCampaignsManager @/link methods.
 */
@protocol SMCampaignsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that promotional campaigns were fetched.
 @discussion This method is called in response to @link fetchFeedMessages @/link and @link fetchFeedMessagesWithLocale:limit: @/link.
 @param messages The promotional campaigns.
 */
- (void)didFetchFeedMessages:(NSArray<SMFeedMessage *> *)messages;

@end


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
 @discussion This property is updated in response to a successful @link fetchFeedMessages @/link or @link fetchFeedMessagesWithLocale:limit: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMFeedMessage *> *feedMessages;

/*!
 @abstract Makes a request to update @link feedMessages @/link with promotional campaigns targeted to the current user's locale (limited to @link SM_CAMPAIGNS_MANAGER_DEFAULT_FETCH_LIMIT @/link campaigns).
 @discussion @link didFetchFeedMessages: @/link is called in response to this method.
 */
- (void)fetchFeedMessages;
/*!
 @abstract Makes a request to update @link feedMessages @/link with a limited number of promotional campaigns targeted to the specified locale.
 @discussion @link didFetchFeedMessages: @/link is called in response to this method.
 @param locale The locale in which the fetch will be restricted (optional - default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @param limit The maximum amount of campaigns to fetch (optional - default value is @link SM_CAMPAIGNS_MANAGER_DEFAULT_FETCH_LIMIT @/link).
 */
- (void)fetchFeedMessagesWithLocale:(NSLocale *)locale limit:(int)limit;

@end

#endif /* __SM_CAMPAIGNS_MANAGER__ */
