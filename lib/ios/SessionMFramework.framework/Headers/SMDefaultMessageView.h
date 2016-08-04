//
//  SMDefaultMessageView.h
//  SessionM
//
//  Copyright (c) 2016 SessionM. All rights reserved.
//

#ifndef __SM_DEFAULT_MESSAGE_VIEW__
#define __SM_DEFAULT_MESSAGE_VIEW__

#import "SMMessageView.h"

/*!
 @class SMDefaultMessageView
 @abstract Standard implementation of @link SMMessageView @/link.
 @discussion This class offers a standard implementation for presenting messages. In addition, it automatically notifies the SDK when a message view is presented or tapped.
 */
@interface SMDefaultMessageView : SMMessageView

/*!
 @abstract Presents the message and notifies the SDK of the presentation.
 @discussion Message view is presented as a pop-up that includes the app icon, a dismiss button and the message header and text.
 */
- (void)present;
/*!
 @abstract Dismisses the message.
 @discussion Message view can be dismissed manually by tapping the dismiss button, or programmatically by calling this method. In addition, this method is automatically called if the user does not interact with the message view in a set amount of time.
 */
- (void)dismiss;

@end

#endif /* __SM_DEFAULT_MESSAGE_VIEW__ */
