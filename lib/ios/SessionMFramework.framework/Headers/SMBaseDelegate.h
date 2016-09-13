//
//  SMBaseDelegate.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_BASE_DELEGATE__
#define __SM_BASE_DELEGATE__

#import "SMError.h"

/*!
 @const SM_MANAGER_NOTIFICATION_DATA_KEY
 @abstract Used to access relevant data from an Mobile Marketing Cloud API notification's <code>userInfo</code> property.
 */
extern NSString *const SM_MANAGER_NOTIFICATION_DATA_KEY;

/*!
 @protocol SMBaseDelegate
 @abstract Defines callbacks to be implemented by delegates of the SessionM Mobile Marketing Cloud SDK API Manager classes.
 */
@protocol SMBaseDelegate <NSObject>

@optional

/*!
 @abstract Notifies delegate that an API request failed.
 @param error An @link SMError @/link object containing information about why the request failed.
 @deprecated Use API methods with block-based completion handlers instead.
 */
- (void)requestDidFail:(SMError *)error __attribute__((deprecated("Use API methods with block-based completion handlers instead")));

@end

#endif /* __SM_BASE_DELEGATE__ */
