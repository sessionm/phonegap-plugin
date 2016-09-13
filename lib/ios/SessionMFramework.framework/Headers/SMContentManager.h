//
//  SMContentManager.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_CONTENT_MANAGER__
#define __SM_CONTENT_MANAGER__

#import <Foundation/Foundation.h>
#import "SMBaseDelegate.h"
#import "SMContent.h"

/*!
 @const SM_CONTENT_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CONTENT_MANAGER_REQUEST_DID_FAIL_NOTIFICATION;
/*!
 @const SM_CONTENT_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Content API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CONTENT_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION;
/*!
 @const SM_CONTENT_MANAGER_DID_FETCH_CONTENTS_NOTIFICATION
 @abstract Notifies observers that content records were fetched.
 @discussion An <code>NSArray</code> of @link SMContent @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CONTENT_MANAGER_DID_FETCH_CONTENTS_NOTIFICATION;
/*!
 @const SM_CONTENT_MANAGER_DID_FETCH_SINGLE_CONTENT_NOTIFICATION
 @abstract Notifies observers that a content record was fetched.
 @discussion An @link SMContent @/link object representing the content data can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key. */
extern NSString *const SM_CONTENT_MANAGER_DID_FETCH_SINGLE_CONTENT_NOTIFICATION;

/*!
 @typedef didFetchContents
 @abstract Completion handler block type for @link fetchContentsWithCompletionHandler: @/link and @link fetchContentsForPlacement:limit:page:completionHandler: @/link.
 */
typedef void (^didFetchContents)(NSArray<SMContent *> *contents, NSString *placement, SMError *error);
/*!
 @typedef didFetchSingleContent
 @abstract Completion handler block type for @link fetchSingleContentWithID:completionHandler: @/link and @link fetchSingleContentWithExternalID:completionHandler: @/link.
 */
typedef void (^didFetchSingleContent)(SMContent *content, SMError *error);


/*!
 @class SMContentManager
 @abstract This API manager contains methods for fetching promotional content data records.
 */
@interface SMContentManager : NSObject

/*!
 @property contents
 @abstract Promotional content data records.
 @discussion This property is updated in response to a successful @link fetchContentsWithCompletionHandler: @/link or @link fetchContentsForPlacement:limit:page:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMContent *> *contents;

/*!
 @abstract Makes a request to update @link contents @/link with content records.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchContentsWithCompletionHandler:(didFetchContents)onCompletion;
/*!
 @abstract Makes a request to update @link contents @/link with a limited number of content records that have the specified content feed placement value.
 @param placement Filters the fetched content records based on where the containing content feed is displayed (e.g. "front_page") (optional).
 @param limit The maximum amount of content records to fetch (optional).
 @param page <code>limit * (page-1)</code> most recent content records will be skipped for the fetch (optional).
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchContentsForPlacement:(NSString *)placement limit:(int)limit page:(int)page completionHandler:(didFetchContents)onCompletion;
/*!
 @abstract Makes a request to fetch the content record with the specified identifier.
 @param contentID The identifier of the content record to be fetched.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchSingleContentWithID:(NSString *)contentID completionHandler:(didFetchSingleContent)onCompletion;
/*!
 @abstract Makes a request to fetch the content record with the specified external (developer-defined) identifier.
 @param externalID The external identifier of the content record to be fetched.
 @param onCompletion The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchSingleContentWithExternalID:(NSString *)externalID completionHandler:(didFetchSingleContent)onCompletion;

@end

#endif /* __SM_CONTENT_MANAGER__ */
