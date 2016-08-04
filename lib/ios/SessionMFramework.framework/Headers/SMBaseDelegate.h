//
//  SMBaseDelegate.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_BASE_DELEGATE__
#define __SM_BASE_DELEGATE__

#import "SMError.h"

/*!
 @protocol SMBaseDelegate
 @abstract Defines callbacks to be implemented by delegates of the SessionM Mobile Marketing Cloud SDK API Manager classes.
 */
@protocol SMBaseDelegate <NSObject>

/*!
 @abstract Notifies delegate that an API request failed.
 @param error An @link SMError @/link object containing information about why the request failed.
 */
- (void)requestDidFail:(SMError *)error;

@end

#endif /* __SM_BASE_DELEGATE__ */
