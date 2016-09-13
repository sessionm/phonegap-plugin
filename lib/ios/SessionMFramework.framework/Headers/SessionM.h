//
//  SessionM.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SESSIONM__
#define __SESSIONM__
#define __SESSIONM_SDK_VERSION__ @"2.1.0"
#define __SESSIONM_SDK_MIN_SUPPORTED_DEVICE_VERSION__ 8.0f

#import <UIKit/UIKit.h>
#import "SMAchievementData.h"
#import "SMMessage.h"
#import "SMDefaultMessageView.h"
#import "SMNotificationMessage.h"
#import "SMLoaderController.h"
#import "SMCampaignsManager.h"
#import "SMContentManager.h"
#import "SMInboxManager.h"
#import "SMIdentityManager.h"
#import "SMLoyaltyCardsManager.h"
#import "SMPlacesManager.h"
#import "SMReceiptsManager.h"
#import "SMReferralsManager.h"
#import "SMRewardsManager.h"
#import "SMTransactionsManager.h"


/*!
 @defined SMStart
 @param appId Application identifier.
 @abstract Starts session.
 */
#define SMStart(appId) [[SessionM sharedInstance] startSessionWithAppID:appId];

/*!
 @defined SMAction
 @param action Action name.
 @abstract Logs action.
 */
#define SMAction(action) [[SessionM sharedInstance] logAction:action];

/*!
 @defined SM_SetServiceRegion_Japan
 @abstract Sets the service region to Japan.
 */
#define SM_SetServiceRegion_Japan() [SessionM setServiceRegion:SMServiceRegionJapan];

/*!
 @defined SM_SetServiceRegion_USA
 @abstract Sets the service region to USA.
 */
#define SM_SetServiceRegion_USA() [SessionM setServiceRegion:SMServiceRegionUSA];

/*!
 @defined SM_SET_SERVER_URL
 @param serverURL The server URL that will be used for the developer's custom service region.
 @abstract Sets the service region to a custom region defined by the developer, using the provided server URL.
 */
#define SM_SET_SERVER_URL(serverURL) [SessionM setCustomServiceRegionWithServerURL:serverURL];




/*!
 @typedef SessionMState
 @abstract Session state enum.

 @constant SessionMStateStopped SessionM service is stopped.
 @constant SessionMStateStartedOnline SessionM service is started and is working in online state, i.e. connected to the network.
 @constant SessionMStateStartedOffline SessionM service is started and is working in offline state, i.e. without network connection. Unlike online state, some operations, e.g. activity display may not be available in this state. SessionM tries to reconnect automatically and will transition to @link SessionMStateStartedOnline @/link state once it is able to do so.
 */
typedef enum SessionMState {
    SessionMStateStopped,
    SessionMStateStartedOnline,
    SessionMStateStartedOffline
} SessionMState;



/*!
 @typedef SMActivityType
 @abstract SessionM service UI activity type enum.

 @constant SMActivityTypeAchievement Achievement notification UI activity.
 @constant SMActivityTypePortal User portal UI activity.
 @constant SMActivityTypeIntroduction SessionM service introduction UI activity.
 @constant SMActivityTypeInterstitial Interstitial activity.
 */
typedef enum SMActivityType {
    SMActivityTypeAchievement = 1,
    SMActivityTypePortal,
    /*! @deprecated <code>SMActivityTypeIntroduction</code> is deprecated. Use @link SMActivityTypePortal @/link instead. */
    SMActivityTypeIntroduction  __attribute__((deprecated)),
    SMActivityTypeInterstitial
} SMActivityType;



/*!
 @typedef SMActivityUserAction
 @abstract User action within SessionM UI activity. Identifies events such as user engaging with achievement prompt, etc.

 @constant SMAchievementViewAction User viewed an achievement.
 @constant SMAchievementEngagedAction User engaged with achievement prompt.
 @constant SMAchievementDismissedAction User dismissed an achievement.
 @constant SMSponsorContentViewedAction User viewed sponsored content.
 @constant SMSponsorContentEngagedAction User engaged with sponsored content.
 @constant SMSponsorContentDismissedAction User dismissed sponsored content.
 @constant SMPortalViewedAction User viewed a section of the user portal.
 @constant SMSignInAction User signed into the user portal.
 @constant SMSignOutAction User signed out of the user portal.
 @constant SMRegisteredAction User registered in the user portal.
 @constant SMPortalDismissedAction User dismissed the portal.
 @constant SMRedeemedRewardAction User claimed a reward.
 @constant SMCheckinCompletedAction User checked into an mPLUS Places location. Action dictionary data includes properties with the following keys: venue - venue name, lat - latitude, long - longitude, distance - distance from venue in meters.
 @constant SMVirtualItemRewardAction Virtual item reward. Action dictionary data includes properties with the following keys: name - reward name, # - reward amount, token - ad ID.
 */
typedef enum SMActivityUserAction {
    SMAchievementViewAction = 100,
    SMAchievementEngagedAction = 101,
    SMAchievementDismissedAction = 102,
    SMSponsorContentViewedAction = 103,
    SMSponsorContentEngagedAction = 104,
    SMSponsorContentDismissedAction = 105,
    SMPortalViewedAction = 106,
    SMSignInAction = 107,
    SMSignOutAction = 108,
    SMRegisteredAction = 109,
    SMPortalDismissedAction = 110,
    SMRedeemedRewardAction = 111,
    SMCheckinCompletedAction = 112,
    SMVirtualItemRewardAction = 113
} SMActivityUserAction;



/*!
 @typedef SMActivityAutoDismissStyle
 @abstract Activity auto dismiss style.

 @constant SMActivityAutoDismissStyleBackground Activity is automatically dismissed when application is backgrounded. This is the default.
 @constant SMActivityAutoDismissStyleResignActive Activity is automatically dismissed when application loses focus which may be due to temporary interruptions such as notification or system alert or application backgrounding.
 */
typedef enum SMActivityAutoDismissStyle {
    SMActivityAutoDismissStyleBackground,
    SMActivityAutoDismissStyleResignActive
} SMActivityAutoDismissStyle;



/*!
 @typedef SMServiceRegion
 @abstract SessionM service region.

 @constant SMServiceRegionUnknown Value before service region is set or session is started.
 @constant SMServiceRegionJapan Japan service region.
 @constant SMServiceRegionUSA United States service region (default value if service region is not set before starting session).
 @constant SMServiceRegionCustom Custom service region (use this value to set custom server URLs).
 */
typedef enum SMServiceRegion {
    SMServiceRegionUnknown,
    SMServiceRegionJapan,
    SMServiceRegionUSA,
    SMServiceRegionCustom
} SMServiceRegion;



/*!
 @typedef SMUserRegistrationResultType
 @abstract Result of most recent attempt to log a user in or out.

 @constant SMUserRegistrationResultTypeUnavailable Service is unavailable or result is not yet available. This is the default value.
 @constant SMUserRegistrationResultTypeSuccess Successfully processed user registration request.
 @constant SMUserRegistrationResultTypeFailure Received network or processing error response from server for user registration request.
 @constant SMUserRegistrationResultTypeServerFailure Received error response from server for user registration request.
 @constant SMUserRegistrationResultTypeProcessingFailure Received error when processing the server response. Possible processing errors include receiving a blank password or an unknown email.
 */
typedef enum SMUserRegistrationResultType {
    SMUserRegistrationResultTypeUnavailable,
    SMUserRegistrationResultTypeSuccess,
    SMUserRegistrationResultTypeFailure,
    /*! @deprecated <code>SMUserRegistrationResultTypeServerFailure</code> is deprecated. Use @link SMUserRegistrationResultTypeFailure @/link instead. */
    SMUserRegistrationResultTypeServerFailure __attribute__((deprecated)),
    /*! @deprecated <code>SMUserRegistrationResultTypeProcessingFailure</code> is deprecated. Use @link SMUserRegistrationResultTypeFailure @/link instead. */
    SMUserRegistrationResultTypeProcessingFailure __attribute__((deprecated))
} SMUserRegistrationResultType;



/*!
 @typedef SMPortalPage
 @abstract Page in portal that can be linked to from app.

 @constant SMPortalPageHome Portal home feed.
 @constant SMPortalPageAchievements User's achievements list.
 @constant SMPortalPageFeatured Featured sweepstakes, rewards, and charities.
 @constant SMPortalPageSweepstakes Sweepstakes page.
 @constant SMPortalPageRewards Rewards page.
 @constant SMPortalPageCharities Charities page.
 @constant SMPortalPageSignUp Sign up page.
 */
typedef enum SMPortalPage {
    SMPortalPageHome,
    SMPortalPageAchievements,
    SMPortalPageFeatured,
    SMPortalPageSweepstakes,
    SMPortalPageRewards,
    SMPortalPageCharities,
    SMPortalPageSignUp
} SMPortalPage;



/*!
 @const SessionMErrorDomain
 @abstract SessionM error domain.
 */
extern NSString * const SessionMErrorDomain;

/*!
 @typedef SessionMSessionErrorType
 @abstract SessionM service error type.

 @constant SessionMServiceUnavailable Indicates that SessionM service is not available, i.e. denied by SessionM service.
 @constant SessionMIneligibleError Indicates that user is ineligible for SessionM service.
 @constant SessionMInvalidAppIdError Indicates invalid application ID.
 */
typedef enum SessionMSessionErrorType {
    SessionMServiceUnavailable = 100,
    /*! @deprecated <code>SessionMIneligibleError</code> is deprecated. Use @link SessionMServiceUnavailable @/link instead. */
    SessionMIneligibleError __attribute__((deprecated)) = 101,
    /*! @deprecated <code>SessionMInvalidAppIdError</code> is deprecated. Use @link SessionMServiceUnavailable @/link instead. */
    SessionMInvalidAppIdError __attribute__((deprecated)) = 102
} SessionMSessionErrorType;



@class SessionM;
@class SMActivity;
@class SMUser;

/*!
 @protocol SessionMDelegate
 @abstract @link SessionM @/link service delegate interface.
 @discussion Defines notifications about session state changes, UI activity and other @link SessionM @/link service events.
 */
@protocol SessionMDelegate <NSObject> 

@optional

/*!
 @abstract Notifies about @link SessionM @/link state transition.
 @param sessionM SessionM service object.
 @param state SessionM state.
 */
- (void)sessionM:(SessionM *)sessionM didTransitionToState:(SessionMState)state;
/*!
 @abstract Notifies that @link SessionM @/link service is permanently unavailable.
 @discussion This method indicates permanent failure to start SessionM service. This can be the case when invalid application ID is supplied by the application or when SessionM service is not available in current device locale or
 session has been refused for security or other reasons. Application should use this method to remove or disable SessionM related UI elements. 
 @param sessionM SessionM service object.
 @param error Error object.
 */
- (void)sessionM:(SessionM *)sessionM didFailWithError:(NSError *)error;
/*!
 @abstract Notifies that the @link userRegistrationResult @/link property has been updated.
 @discussion This method is called after the server response for a signup, login or token authentication request is processed. These requests can be made by calling the @link signUpUserWithData: @/link, @link logInUserWithEmail:password: @/link and @link authenticateWithToken:provider: @/link methods.
 @param sessionM SessionM service object.
 @param result @link SMUserRegistrationResultType @/link the new value for the @link userRegistrationResult @/link property.
 @deprecated This method is deprecated. Use @link sessionM:didUpdateUserRegistrationResult:errorMessages: @/link instead.
 */
- (void)sessionM:(SessionM *)sessionM didUpdateUserRegistrationResult:(SMUserRegistrationResultType)result __attribute__((deprecated));
/*!
 @abstract Notifies that the @link userRegistrationResult @/link property has been updated.
 @discussion This method is called after the server response for a signup, login or token authentication request is processed. These requests can be made by calling the @link signUpUserWithData: @/link, @link logInUserWithEmail:password: @/link and @link authenticateWithToken:provider: @/link methods.
 @param sessionM SessionM service object.
 @param result @link SMUserRegistrationResultType @/link the new value for the @link userRegistrationResult @/link property.
 @param errorMessages <code>NSArray</code> of error messages (value will be <code>nil</code> for successful registration).
 */
- (void)sessionM:(SessionM *)sessionM didUpdateUserRegistrationResult:(SMUserRegistrationResultType)result errorMessages:(NSArray *)errorMessages;
/*!
 @abstract Indicates if newly earned achievement UI activity should be presented.
 @discussion This method is called when achievement is earned and will occur when application calls @link logAction: @/link or starts a session.
 By default, SessionM displays the achievement UI immediately after it is earned. Application can customize this behavior to defer the display until appropriate application state is reached.
 @param sessionM SessionM service object.
 @param achievement Achievement data object.
 @result <code>BOOL</code> indicating if achievement activity should be presented.
 */
- (BOOL)sessionM:(SessionM *)sessionM shouldAutopresentAchievement:(SMAchievementData *)achievement;
/*!
 @abstract Returns <code>UIView</code> object to use as a superview for SessionM view objects.
 @param sessionM SessionM service object.
 @param type Activity type.
 @result <code>UIView</code> object.
 */
- (UIView *)sessionM:(SessionM *)session viewForActivity:(SMActivityType)type;
/*!
 @abstract Returns <code>UIViewController</code> object to use as a presenting controller for SessionM view controller.
 @discussion This method is only called when application's root view controller is <code>nil</code>. In this case SessionM tries to determine appropriate view controller in the view hierarchy to use as a 'presenting controller'.
 This method provides a mechanism for the application to explicitely specify which view controller should be used in this case. It is recommended that application implement this method when root view controller is not set.
 Note, that <code>UIViewController</code> based presentation is only applicable for full screen activities, e.g. user portal.
 @param sessionM SessionM service object.
 @param type Activity type.
 @result <code>UIViewController</code> object.
 */
 - (UIViewController *)sessionM:(SessionM *)session viewControllerForActivity:(SMActivityType)type;
/*!
 @abstract Notifies that UI activity will be presented.
 @param sessionM SessionM service object.
 @param activity Activity object.
 */
- (void)sessionM:(SessionM *)sessionM willPresentActivity:(SMActivity *)activity;
/*!
 @abstract Notifies that UI activity was presented.
 @param sessionM SessionM service object.
 @param activity Activity object.
 */
- (void)sessionM:(SessionM *)sessionM didPresentActivity:(SMActivity *)activity;
/*!
 @abstract Notifies that UI activity will be dismissed.
 @param sessionM SessionM service object.
 @param activity Activity object.
 */
- (void)sessionM:(SessionM *)sessionM willDismissActivity:(SMActivity *)activity;
/*!
 @abstract Notifies that UI activity was dismissed.
 @param sessionM SessionM service object.
 @param activity Activity object.
 */
- (void)sessionM:(SessionM *)sessionM didDismissActivity:(SMActivity *)activity;
/*!
 @abstract Notifies that user info was updated.
 @discussion User info is updated when earned achievement count, opt out status or other user relevant state changes. 
 @param sessionM SessionM service object.
 @param user User object.
 */
- (void)sessionM:(SessionM *)sessionM didUpdateUser:(SMUser *)user;
/*!
 @abstract Notifies that media (typically video) will start playing.
 @discussion Application should use this method to suspend its own media playback if any.
 @param sessionM SessionM service object.
 @param activity Activity object.
 */
- (void)sessionM:(SessionM *)sessionM willStartPlayingMediaForActivity:(SMActivity *)activity;
/*!
 @abstract Notifies that media (typically video) finished playing
 @discussion Application should use this method to resume its own media playback if any.
 @param sessionM SessionM service object.
 @param activity Activity object.
 */
- (void)sessionM:(SessionM *)sessionM didFinishPlayingMediaForActivity:(SMActivity *)activity;
/*!
 @abstract Notifies that user performed an action in currently presented UI activity.
 @param sessionM SessionM service object.
 @param user User object.
 @param action User action type. 
 @param activity Activity object.
 @param data <code>NSDictionary</code> object with action specific data.
 */
- (void)sessionM:(SessionM *)sessionM user:(SMUser *)user didPerformAction:(SMActivityUserAction)action forActivity:(SMActivity *)activity withData:(NSDictionary *)data;
/*!
 * @abstract Returns center point to use when presenting built-in achievement alert <code>UIView</code>.
 * @discussion Application can use this method to refine the positioning of achievement alert <code>UIView</code>. The default layout is specified in the developer portal as part of achievement configuration.
 * However, this method provides additional flexibility if application interface is dynamic and requires adjustments to alert positioning in order to ensure it does not cover important UI elements. 
 * @param sessionM SessionM service object.
 * @param activity Activity object.
 * @param size Activity <code>UIView</code> size.
 * @result <code>CGPoint</code> <code>UIView</code> center.
 */
- (CGPoint)sessionM:(SessionM *)sessionM centerForActivity:(SMActivity *)activity withSize:(CGSize)size;

/*!
 @abstract Deprecated. Notifies that UI activity is not available for presentation.
 @discussion This method is called in response to @link presentActivity: @/link call when activity of specified type cannot be presented.
 @param sessionM SessionM service object.
 @param type Activity type.
 @deprecated This method is deprecated. Use boolean value returned from @link presentActivity: @/link as an indicator if activity will be presented or not.
 */
- (void)sessionM:(SessionM *)sessionM activityUnavailable:(SMActivityType)type __attribute__((deprecated));
/*!
 @abstract Deprecated. Notifies that unclaimed achievement is available or not, if <code>nil</code>, for presentation.
 @discussion This method should be used by application to customize an achievement presentation. SessionM service invokes this method when new achievement is earned or to notify about one of the previously earned
 unclaimed achievements. Achievement object supplied by this method is also available via SessionM @link unclaimedAchievement @/link property.
 This notification, in conjunction with @link unclaimedAchievement @/link property, allows application to present user achievements at convenient time during application lifecycle.
 @param sessionM SessionM service object.
 @param achievement Achievement data object or <code>nil</code> if no unclaimed achievement is available.
 @deprecated This method is deprecated. Use @link sessionM:shouldAutopresentAchievement: @/link to get notified about new achievements.
 */
- (void)sessionM:(SessionM *)sessionM didUpdateUnclaimedAchievement:(SMAchievementData *)achievement __attribute__((deprecated));
/*!
 @abstract Deprecated. Indicates if newly earned achievement UI activity should be presented.
 @param sessionM SessionM service object.
 @param type Activity type.
 @result <code>BOOL</code> indicating if achievement activity should be presented.
 @deprecated This method is deprecated - use @link sessionM:shouldAutopresentAchievement: @/link instead.
 */
- (BOOL)sessionM:(SessionM *)sessionM shouldAutopresentActivity:(SMActivityType)type __attribute__((deprecated));

/*!
 @abstract Notifies the developer a deep link url was receieved.
 @discussion If an in-app message or push notification was configured to have a deep link action, this method returns the deep link string that was setup in the SessionM Mobile Marketing Cloud.
 @param sessionM SessionM service object.
 @param deepLink The deepLink string configured in the SessionM Mobile Marketing Cloud portal.
 */
- (void)sessionM:(SessionM *)sessionM handleDeepLinkString:(NSString*)deepLink;

/*!
 @abstract Notifies the developer an ad or deep link action from a notification is ready.
 @discussion If a notification was recieved whose action was to show an ad or have a SessionM deep link action, this method will be fired to inform the developer. Perform any functions needed, then call @link executePendingNotification @/link.
 @param sessionM SessionM service object. You can call @link hasPendingNotification @/link at any time to see if a pending action is available.
 @param notification SMNotificationMessage object that represents the data sent in the notification.
 */
- (void)sessionM:(SessionM *)sessionM didReceiveNotification:(SMNotificationMessage *)notification;

/*!
 @abstract Notifies the developer of the CLCircularRegions being monitored.
 @discussion When the SMLocationManager is told to monitor regions, it will call this method to send to the developer all the CLCircularRegions currently being monitored. This is purely for developer custom UI they may wish to display. Will never be called unless SessionMLocation library is used and region monitoring started.
 @param sessionM SessionM service object. 
 @param regions As <code>NSArray</code> of all CLCircularRegions being monitored.
 */
- (void)sessionM:(SessionM*)sessionM didStartMonitoringRegions:(NSArray<__kindof CLRegion *> *)regions;
@end



/*!
 @typedef SMLogLevel
 @abstract Log level.

 @constant SMLogLevelOff Disables logging.
 @constant SMLogLevelInfo Enables logging of key API events such as action logging, achievement display, etc.
 @constant SMLogLevelDebug Enables logging of detailed information about SDK operations such as, for example, network activity in addition to basic API tracing. This level should be used when diagnosing SDK integration problems.
 */
typedef enum SMLogLevel {
    SMLogLevelOff,
    SMLogLevelInfo,
    SMLogLevelDebug
} SMLogLevel;


/*!
 @typedef SMLogCategory
 @abstract Log category.

 @constant SMLogCategoryAll Receive logging for all categories.
 @constant SMLogCategoryAPI Receive logging for key API activity.
 @constant SMLogCategoryUI Receive logging for UI activity.
 @constant SMLogCategoryNetwork Receive logging for network activity.
 @constant SMLogCategorySession Receive logging for session state changes.
 @constant SMLogCategoryCPI Receive logging for CPI activity.
 */
typedef enum SMLogCategory {
    SMLogCategoryAll = 0xFF,
    SMLogCategoryAPI = 0x01,
    SMLogCategoryUI = 0x02,
    SMLogCategoryNetwork = 0x04,
    SMLogCategorySession = 0x08,
    /*! @deprecated SMLogCategoryCPI is deprecated. */
    SMLogCategoryCPI __attribute__((deprecated)) = 0x10
} SMLogCategory;


/*!
 @typedef SMLocationCoordinate2D
 @abstract Location coordinate struct.

 @field latitude Coordinate latitude value.
 @field longitude Coordinate longitude value.
 */
typedef struct SMLocationCoordinate2D {
	CLLocationDegrees latitude;
	CLLocationDegrees longitude;
} SMLocationCoordinate2D; 



/*!
 @class SessionM
 @abstract SessionM service interface. This is main class in SessionM iOS SDK. It defines methods for all main operations such as logging an action and displaying an achievement or a user portal, etc.
 
 <b>Basic API usage</b>

 Following is the simplest way of integrating SessionM service within your application code. It assumes that you have registered your application in SessionM developer portal and configured achievements.
 <ol>
 <li>Start the service by calling @link SMStart @/link macro.</li>
 <li>Log action in appropriate places in your code log user action by calling @link SMAction @/link. When new achievement is earned it will be displayed automatically using the style chosen in the developer portal.</li>
 </ol>
 
 When minimal API described before is not sufficient application can obtain SessionM instance by calling @link sharedInstance @/link and, optionally, implementing and registering @link SessionMDelegate @/link instance. 
 
 For example, to override automatic achievement display do the following:
 <ol>
 <li>Implement @link SessionMDelegate @/link and, specifically, @link sessionM:shouldAutopresentAchievement: @/link method to get notified that new achievement is earned and is ready for display. Return <code>NO</code> to suppress achievement display.</li>
 <li>At appropriate place in your application call @link presentActivity: @/link to display the achievement UI.</li>
 </ol>
 
 <b>UI Activity</b>

 Application user engages with SessionM service via UI activity or flow. UI activity starts with an initial view which can be partial- (e.g. achievement alert) or full-screen (e.g. user portal). 
 A UI activity can be comprised on multiple views. Partial-screen view can transition to full-screen view.
 
 Application is notified by SessionM UI display by implementing the following methods of @link SessionMDelegate @/link: @link sessionM:willPresentActivity: @/link, @link sessionM:didPresentActivity: @/link, @link sessionM:willDismissActivity: @/link and @link sessionM:didDismissActivity: @/link.
 
 To present the UI SessionM adds its <code>UIView</code> and/or <code>UIViewController</code> objects to application's view and view controller hierarchy. By default, the following algorithm is to find appropriate superview or presenting controller:
 <ol>
 <li>Traverse <code>UIViewController</code> chain starting with root view controller and, if set, find top-most <code>UIViewController</code> object.</li>
 <li>If view controller cannot be determined in step 1, iterate through <code>UIWindow</code> subviews finding the top-most visible <code>UIView</code>. If not found, use key <code>UIWindow</code> object.</li>
 </ol>
 When SessionM presents a <code>UIView</code> it adds it to the <code>UIView</code> found in steps above. When SessionM presents a <code>UIViewController</code> it uses the controller found in step 1 or, if not available, adds its view to the view found in step 2.
 
 Application can instruct SessionM to use specific view and controller objects by implementing the following @link SessionMDelegate @/link methods: @link sessionM:viewForActivity: @/link and @link sessionM:viewControllerForActivity: @/link.

 Special consideration is taken when presenting SessionM UI activity when keyboard is displayed - the activity display is delayed until keyboard is dismissed. This applies to both when activity is auto-presented as a result of action logging or
 when application is explicitly presenting it by invoking @link presentActivity: @/link method.
 
 <b>Achievement UI Customization</b>
 
 Application can customize achievement presentation to suit its style and UI flow by implementing the following steps:
 <ol>
 <li>Configure achievements as "custom" in the development portal</li>
 <li>Obtain an achievement data object by calling @link unclaimedAchievement @/link property and, optionally, implementing @link sessionM:didUpdateUnclaimedAchievement: @/link delegate method to get notified about available achievements.</li>
 <li>Extend @link SMAchievementActivity @/link class or use its instance as a callback object in conjunction with @link SMAchievementData @/link object to present the achievement UI and notify SessionM about relevant lifecycle events.</li>
 </ol>
 
 For more information about using custom achievement API see Development Guide. 
 
 <b>Session state</b>

 SessionM service, once started, is operational regardless of whether network connection is available or not. In online (connected) state the activity UI is available for display.
 In offline (disconnected) state actions logged through the service are captured but UI is not available. Upon re-connection the actions are synchronized with SessionM service.
 Application can be notified by SessionM state transitions via @link sessionM:didTransitionToState: @/link delegate callbacks.
 SessionM service is stopped when application is backgrounded and re-started upon foregrounding.

 <b>Threading</b>

 Almost all SessionM API methods are asynchronous. Implement and register @link SessionMDelegate @/link to get notified about the outcome of the method calls and other SessionM service events.
 Delegate calls are made on the main thread.

 <b>Location capture</b>

 To capture the location information you will need to start CCLocationManager and register for its notifications as described in Apple Location Awareness Programming Guide.
 As part of location notification processing update SessionM @link locationCoordinate @/link property.

 <b>Logging</b>
 
 To diagnose problems and ensure proper SDK integration SessionM service implements basic logging which can be controlled using @link logLevel @/link property. For basic output capturing all major SDK events use @link SMLogLevelInfo @/link level. 
 For more detailed, low level output use @link SMLogLevelDebug @/link level. 
 It is highly recommended to capture and provide debug output when reporting a problem to SessionM technical support.
*/

@interface SessionM : NSObject 

/*!
 @property campaignsManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Campaigns API.
 */
@property(nonatomic, strong, readonly) SMCampaignsManager    *campaignsManager;
/*!
 @property contentManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Content API.
 */
@property(nonatomic, strong, readonly) SMContentManager      *contentManager;
/*!
 @property identityManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Identity API.
 */
@property(nonatomic, strong, readonly) SMIdentityManager     *identityManager;
/*!
 @property inboxManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Inbox API.
 */
@property(nonatomic, strong, readonly) SMInboxManager        *inboxManager;
/*!
 @property loyaltyCardsManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Loyalty Card API.
 */
@property(nonatomic, strong, readonly) SMLoyaltyCardsManager *loyaltyCardsManager;
/*!
 @property placesManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Places API.
 */
@property(nonatomic, strong, readonly) SMPlacesManager       *placesManager;
/*!
 @property receiptsManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Image Validation API.
 */
@property(nonatomic, strong, readonly) SMReceiptsManager     *receiptsManager;
/*!
 @property referralsManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Referrals API.
 */
@property(nonatomic, strong, readonly) SMReferralsManager    *referralsManager;
/*!
 @property rewardsManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Rewards API.
 */
@property(nonatomic, strong, readonly) SMRewardsManager      *rewardsManager;
/*!
 @property transactionsManager
 @abstract Singleton that interfaces with the SessionM Mobile Marketing Cloud Points Transactions API.
 */
@property(nonatomic, strong, readonly) SMTransactionsManager *transactionsManager;

/*!
 @property delegate
 @abstract SessionMDelegate object.
 */
@property(nonatomic, weak) id<SessionMDelegate> delegate;
/*!
 @property sessionState
 @abstract SessionM state.
 */
@property(nonatomic,readonly) SessionMState sessionState;
/*!
 @property sessionID
 @abstract The current session ID. Returns <code>nil</code> if the session is not online.
 */
@property(nonatomic, readonly) NSString *sessionID;
/*!
 @property currentActivity
 @abstract Current UI activity.
 */
@property(nonatomic, readonly) SMActivity *currentActivity;
/*!
 @property activityAutoDismissStyle
 @abstract Auto-dismiss style.
 */
@property(nonatomic) SMActivityAutoDismissStyle activityAutoDismissStyle;
/*!
 @property logLevel
 @abstract Log level.
 */
@property(nonatomic) SMLogLevel logLevel;
/*!
 @property logCategories
 @abstract Log category.
 */
@property(nonatomic) int logCategories;

/*!
 @property displayInAppWelcomeFlow
 @abstract when to display in-app welcome flow
 */
@property(nonatomic) NSInteger displayInAppWelcomeFlow;
/*!
 @property inAppPromotionTile
 @abstract in-app promotion tile.
 */
@property(nonatomic, strong, readwrite) NSDictionary *inAppPromotionTile;
/*!
 @property locationCoordinate
 @abstract Location coordinate info.
 */
@property(nonatomic) SMLocationCoordinate2D locationCoordinate;
/*!
 @property user
 @abstract User object.
 */
@property(nonatomic, readonly) SMUser *user;
/*!
 @property userRegistrationResult
 @abstract The result of the most recent attempt to sign up, log in, or log out a user. Note: should be accessed in the @link sessionM:didUpdateUserRegistrationResult:errorMessages: @/link delegate.
 */
@property(nonatomic, readonly) SMUserRegistrationResultType userRegistrationResult;
/*!
 @property operationQueue
 @abstract Operation queue to use to perform SDK work on.
 @discussion By default SDK creates internal operation queue to perform its work on. Application can use this property to supply its own operation queue object. This can be useful in cases when application allocates
 a queue to perform certain types of background operations by its own components or 3rd party SDK in order to manage resources more efficiently. SessionM SDK sets maxConcurrentOperationCount property of supplied operation queue to 1. 
 Note that setting this property only takes effect when SDK is in SessionMStateStopped state.
 */
@property(nonatomic, strong) NSOperationQueue *operationQueue;
/*!
 @property unclaimedAchievement
 @abstract Last earned unclaimed achievement object or <code>nil</code> if not available.
 */
@property(nonatomic, readonly) SMAchievementData *unclaimedAchievement;
/*!
 @property sessionCount
 @abstract Number of sessions started by the app.
 */
@property(nonatomic, readonly) NSInteger sessionCount;
/*!
 @property statusBarBackgroundColor
 @abstract Color to put behind the status bar. Used when portal is in UITabBarController.
 */
@property(nonatomic,strong) UIColor *statusBarBackgroundColor;
/*!
 @property pluginSDK
 @abstract The name of the plug-in SDK.
 */
@property(nonatomic, strong) NSString *pluginSDK;
/*!
 @property pluginSDKVersion
 @abstract The version number of the plug-in SDK being used.
 */
@property(nonatomic, strong) NSString *pluginSDKVersion;
/*!
 @property shouldAutoUpdateAchievementsList
 @abstract Determines whether achievement list is updated automatically when user's unclaimed achievement count changes, or only when requested by calling @link updateAchievementsList @/link (default behavior).
 */
@property(nonatomic) BOOL shouldAutoUpdateAchievementsList;
/*!
 @property currentLoaderController
 @abstract Current view controller presented when loading the portal.
 @discussion This property can be used to access the view that is displayed when loading portal content. Set the property using @link addCustomLoaderController: @/link to use a custom load screen. If @link removeCustomLoader @/link is called or if this property is not set manually, the standard load screen will be used.
 */
@property(nonatomic, strong, readonly) SMLoaderController *currentLoaderController;
/*!
 @property isDebugMode
 @abstract Returns whether the app scheme is Debug (the default value is <code>NO</code>).
 @discussion Before starting a session, set this property based on the <code>DEBUG</code> preprocessor macro. This property is used to notify our servers whether the development or production environment should be used for the Apple Push Notification service.
 */
@property(nonatomic) BOOL isDebugMode;
/*!
 @property customLocale
 @abstract Determines the default locale to use when making API calls (<code>[NSLocale currentLocale]</code> is used as the default locale when this property is set to <code>nil</code>).
 @discussion This property can only be set when the session is stopped.
 */
@property(nonatomic, strong, readwrite) NSLocale *customLocale;

/*!
 @abstract Returns singleton SessionM service instance. If the server is not supported on the current platform (as indicated by @link isSupportedPlatform @/link) <code>nil</code> is returned.
 @result SessionM service object.
 */
+ (SessionM *)sharedInstance;
/*!
 @abstract Returns <code>YES</code> if SessionM SDK supports this platform or OS version, <code>NO</code> - otherwise.
 @discussion Application can examine this property to determine if SessionM service is available on its platform. Currently, SessionM service is fully functional on iOS 6.0 and later.
 On older OS SessionM service is a no-op, i.e. methods can still safely be called but they do not do anything.
 @result <code>BOOL</code> indicating if platform is supported.
 */
+ (BOOL)isSupportedPlatform;
/*!
 @abstract Sets the service region (defaults to @link SMServiceRegionUSA @/link if not set before session is started).
 @discussion Use this method or call @link SM_SetServiceRegion_Japan @/link or @link SM_SetServiceRegion_USA @/link before calling @link startSessionWithAppID: @/link to set the service region. Once set, the service region cannot be changed.
 @param region The service region that will be used.
 */
+ (void)setServiceRegion:(SMServiceRegion)region;
/*!
 @abstract Sets the service region to a custom region defined by the developer using the given server URL name.
 @discussion Use this method or call @link SM_SET_SERVER_URL @/link before calling @link startSessionWithAppID: @/link to set the service region. Once set, the service region cannot be changed.
 @param serverURL The server URL that will be used for your custom service region.
 */
+ (void)setCustomServiceRegionWithServerURL:(NSString *)serverURL;
/*!
 @abstract Starts session with specified application ID. 
 @discussion This method is executed asynchronously with outcome communicated via @link sessionM:didTransitionToState: @/link or @link sessionM:didFailWithError: @/link delegate callbacks. 
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param appId Application identifier. The identifier is generated when application is registered in the developer portal.
 */
- (void)startSessionWithAppID:(NSString *)appId;
/*!
 @abstract Restarts session with specified application ID.
 @discussion This method is executed asynchronously with outcome communicated via @link sessionM:didTransitionToState: @/link or @link sessionM:didFailWithError: @/link delegate callbacks.
 This method has no effect if session is not started or if the specified application ID is equal to the current session's application ID.
 @param appId Application identifier. The identifier is generated when application is registered in the developer portal.
 @result <code>BOOL</code> indicating whether session restart will be requested.
 */
- (BOOL)restartSessionWithAppID:(NSString *)appId;
/*!
 @abstract Stops the current session.
 @discussion This method is executed asynchronously with outcome communicated via @link sessionM:didTransitionToState: @/link or @link sessionM:didFailWithError: @/link delegate callbacks.
 This method has no effect if session is not started.
 */
- (void)stopSession;
/*!
 @abstract Indicates if UI activity is available for presentation.
 @param type Activity type.
 @result <code>BOOL</code> indicating if activity available for presentation, false - otherwise
 */
- (BOOL)isActivityAvailable:(SMActivityType)type;
/*!
 @abstract Presents activity of specified type. e.g. user portal or achievement.
 @discussion If activity is not available the @link SessionMDelegate @/link method @link sessionM:activityUnavailable: @/link is called to notify the application. An activity may not be available for display when, for example, session is in @link SessionMStateStartedOffline @/link state or, in case of achievement, the new achievement has not been earned. 
 When presenting an achievement this should be used in conjunction with delegate method @link sessionM:shouldAutopresentAchievement: @/link returning <code>NO</code> to control the timing of achievement presentation.
 Activity is presented using <code>UIViewController</code> or <code>UIView</code> as determined by SessionM service. If activity has already been presented at a time of this call this method does nothing.
 If an activity is already presented this method cancels new activity display, notifies application via @link sessionM:activityUnavailable: @/link and returns. 
 When new activity does get presented the delegate methods @link sessionM:willPresentActivity: @/link and @link sessionM:didPresentActivity: @/link will be invoked if implemented.
 If this method is not called from the main thread, it will return <code>NO</code> and the activity will not be presented.
 @param type Activity type.
 @result <code>BOOL</code> indicating if activity will be presented, false - otherwise
 */
- (BOOL)presentActivity:(SMActivityType)type;
/*!
 @abstract Presents activity of specified type with the specified URL.
 @discussion Presents a portal activity with the content pointed to by the specified URL. Use this method to link to a particular page or ad in our portal. This method cannot be used to present achievement activities.
 @param type Activity type.
 @param url Path to content.
 @result <code>BOOL</code> indicating whether activity will be presented. Returns <code>NO</code> if type is not @link SMActivityTypePortal @/link or if url is <code>nil</code>.
 */
- (BOOL)presentActivity:(SMActivityType)type withURL:(NSString *)url;
/*!
 @abstract Dismisses currently presented activity.
 @discussion Delegate methods @link sessionM:willDismissActivity: @/link and @link sessionM:didDismissActivity: @/link will be invoked if implemented.
 */
- (void)dismissActivity;
/*!
 @abstract Logs action and presents an achievement activity if new achievement is earned.
 @discussion If new achievement is earned as a result of the action delegate method @link sessionM:shouldAutopresentAchievement: @/link, if implemented, is called to determine if achievement alert should be presented.
 @param action Action name.
 */
- (void)logAction:(NSString *)action;
/*!
 @abstract Logs specified number of actions and presents an achievement activity if new achievement is earned.
 @discussion If activity becomes available as a result of the action delegate method @link sessionM:shouldAutopresentActivity: @/link, if implemented, is called to determine if activity should be presented.
 @param action Action name.
 @param count Number of actions.
 */
- (void)logAction:(NSString *)action withCount:(NSUInteger)count;
/*!
 @abstract Logs specified number of actions and presents an achievement activity if new achievement is earned.
 @discussion If activity becomes available as a result of the action delegate method @link sessionM:shouldAutopresentActivity: @/link, if implemented, is called to determine if activity should be presented.
 @param action Action name.
 @param count Number of actions.
 @param payloads Any additional developer-defined data associated with the action.
 */
- (void)logAction:(NSString *)action withCount:(NSUInteger)count payloads:(NSDictionary *)payloads;
/*!
 @abstract Claims the specified achievement and presents an ad.
 @discussion The specified achievement cannot be claimed if the session is not online, if the achievement is not in the @link claimableAchievements @/link array, or if another activity is already presented.
 @param achievement Achievement to claim.
 @result <code>BOOL</code> representing whether the achievement can be claimed.
 */
- (BOOL)claimAchievement:(SMAchievementData *)achievement;
/*!
 @abstract Sends meta data to SessionM. 
 @discussion Please refer to the documentation for more information on common keys. Data should only be supplied in accordance with your applications terms of service and privacy policy.
 @param data Meta data value.
 @param key Meta data key.
 */
- (void)setMetaData:(NSString *)data forKey:(NSString *)key;
/*!
 @abstract Sets the SessionM plug-in SDK name and version number.
 @discussion This method should be called from the plug-in SDK before a session is started.
 @param sdk The plug-in SDK name
 @param version The plug-in SDK version number
 */
- (void)setPluginSDK:(NSString *)sdk version:(NSString *)version;
/*!
 @abstract Handles application launch URL.
 @discussion Your application can be configured to launch the portal using the application URL scheme mechanism. In order to enable this feature, follow the steps below:
 <ol>
 <li>Add to your application configuration plist the URL scheme 'sessionmYourAppId' where YourAppId is your application ID as listed in the SessionM developer portal</li>
 <li>In the application delegate method <code>application:openURL:sourceApplication:annotation:</code> add a call to @link handleURL: @/link, passing the URL from the application delegate call. Alternatively, handleURL can be called directly without implementing this delegate.</li>
 </ol>
 @param url App launch URL.
 @result <code>BOOL</code> indicating whether the URL was handled by the SDK.
 */
- (BOOL)handleURL:(NSURL *)url;
/*!
 @abstract Opens the deep link to the specified page in the portal.
 @discussion Use this method to deep link to one of the pages listed under @link SMPortalPage @/link.
 @param page Portal page to open.
 @result <code>BOOL</code> indicating whether the URL was handled by the SDK.
 */
- (BOOL)openURLForPortalPage:(SMPortalPage)page;


/*!
 @abstract Deprecated. Logs application error and/or exception.
 @discussion This method should be used as part of application exception handling logic, for example, in uncaught exception handler implementation (see NSSetUncaughtExceptionHandler in Apple developer documentation).
 @param errorName Error name.
 @param message Error message.
 @param exception Exception object.
 @deprecated This method is deprecated. 
 */
- (void)logError:(NSString *)errorName message:(NSString *)message exception:(NSException *)exception __attribute__((deprecated));

/*!
 @abstract Signs user up for an account in the SessionM rewards program with specified user data.
 @discussion This method should be used by a developer to require a user to register for the SessionM rewards program.
 @param userData The userData to send to the server when creating an account for the user.<br />
 <ul><h5>Keys:</h5>
 <li>@link SMUserDataEmailKey @/link - User's email (required)</li>
 <li>@link SMUserDataPasswordKey @/link - User's password (required)</li>
 <li>@link SMUserDataBirthYearKey @/link - User's year of birth (required - should be in the format XXXX (e.g. 1976). Years of birth that put the user's age below 14 or above 120 years old are considered invalid.)</li>
 <li>@link SMUserDataGenderKey @/link - User's gender (required - accepts "m/f", "male/female". Case insensitive.)</li>
 <li>@link SMUserDataZipcodeKey @/link - User's zipcode (optional)</li>
 </ul>
 @result <code>BOOL</code> Returns <code>NO</code> if an input is invalid or if session has not been authenticated, and <code>YES</code> otherwise.
 */
- (BOOL)signUpUserWithData:(NSDictionary *)userData;
/*!
 @abstract Logs in the user associated with the provided email.
 @discussion Can be used for user accounts created with @link signUpUserWithData: @/link.
 @param email User's email.
 @param password User's password.
 @result <code>BOOL</code> Returns <code>NO</code> if an input is invalid or if session has not been authenticated, and <code>YES</code> otherwise.
 */
- (BOOL)logInUserWithEmail:(NSString *)email password:(NSString *)password;
/*!
 @abstract Logs out the current user.
 @discussion Can be used for user accounts created with @link signUpUserWithData: @/link.
 */
- (void)logOutUser;
/*!
 @abstract Authenticates user with the specified OAuth token received from the specified provider.
 @deprecated This method is deprecated - use @link authenticateWithToken:provider: @/link instead.
 */
- (BOOL)authenticateWithProvider:(NSString *)provider token:(NSString *)token __attribute__((deprecated));
/*!
 @abstract Authenticates user with the specified OAuth token received from the specified provider.
 @discussion The @link sessionM:didUpdateUserRegistrationResult:errorMessages: @/link delegate method is called when the authentication is finished.
 @param token The token string from the provider.
 @param provider OAuth token provider, such as "SessionM".
 @result <code>BOOL</code> indicating whether the SDK will attempt to authenticate the user. Returns <code>NO</code> if session is not online, or if either <code>token</code> or <code>provider</code> is <code>nil</code> or empty. Returns <code>YES</code> otherwise.
 */
- (BOOL)authenticateWithToken:(NSString *)token provider:(NSString *)provider;
/*!
 @abstract Updates user's @link achievementsList @/link property.
 @discussion The @link sessionM:didUpdateUser: @/link delegate method is called and the @link SMSessionMDidUpdateUserInfoNotification @/link notification is sent when the achievements list is updated.
 @result <code>BOOL</code> indicating whether the SDK can make a request to update the achievements list.
 */
- (BOOL)updateAchievementsList;
/*!
 @abstract Sets the specified controller as the value of @link currentLoaderController @/link.
 @discussion Use this method to display a custom load screen when presenting portal content. The developer should define a class that inherits from @link SMLoaderController @/link, and call this method with an instance of that class. If this method is called multiple times, the controller specified in the most recent call will be used.
 @param controller The developer's custom view controller that will display the portal load screen.
 */
- (void)addCustomLoaderController:(SMLoaderController *)controller;
/*!
 @abstract Sets the value of @link currentLoaderController @/link to the standard loader controller.
 @discussion Use this method to return to using the standard load screen after calling @link addCustomLoaderController: @/link.
 */
- (void)removeCustomLoader;
/*!
 @abstract Request user's permission to send remote notifications of all types.
 @discussion This method should be called from the developer's <code>application:didFinishLaunchingWithOptions:</code> delegate method.
 */
- (void)registerForRemoteNotifications;
/*!
 @abstract Handles a remote notification sent by the SessionM platform.
 @discussion This method should be called from the developer's <code>application:didReceiveRemoteNotification:</code> and <code>application:didFinishLaunchingWithOptions:</code> delegate methods with the given <code>NSDictionary</code> payload. If the launch option for the push notification is a deep_link or open_ad, the developer will be notified of a pending action via the @link sessionM:didReceiveNotification: @/link method.
 @param userInfo The <code>NSDictionary</code> payload data.
 @result <code>BOOL</code> indicating notification was handled by SessionM SDK.
 */
- (BOOL)handleRemoteNotification:(NSDictionary *)userInfo;
/*!
 @abstract Stores user's device token (required to send remote notifications).
 @discussion This method should be called from the developer's <code>application:didRegisterForRemoteNotificationsWithDeviceToken:</code> delegate method with the given device token.
 @param token The user's device token.
 */
- (void)storeDeviceToken:(NSData *)token;
/*!
 @abstract Tells SDK to act on pending notification action.
 @discussion Performs the pending notification action as specified by @link //apple_ref/occ/instp/SMMessage/actionType @/link. If the message has a deep link that is not recognized by the SDK, it is forwarded to the delegate call @link sessionM:handleDeepLinkString: @/link.
 */
- (void)executePendingNotification;
/*!
 @abstract Returns <code>YES</code> if the SDK has a notification action pending.
 @discussion If a notification with a deep link or show ad action was received, but not yet displayed, this method will return <code>YES</code>. Otherwise will return <code>NO</code>.
 */
- (BOOL)hasPendingNotification;
/*!
 @abstract Convienence method for creating a message view.
 @discussion This method will return a basic view that can be used to display the specified message data. Call @link //apple_ref/occ/instm/SMDefaultMessageView/present @/link on the returned @link SMDefaultMessageView @/link instance to display the UI.
 @param message The @link SMMessage @/link instance whose data will be displayed in the message view.
 @result @link SMDefaultMessageView @/link instance customized to the message data.
 */
- (SMDefaultMessageView *)viewForMessage:(SMMessage *)message;
/*!
 @abstract Tells SDK to act on the specified message's action.
 @param message The @link SMMessage @/link instance whose action will be executed.
 @discussion Performs the specified message's action as specified by @link //apple_ref/occ/instp/SMMessage/actionType @/link. If the message has a deep link that is not recognized by the SDK, it is forwarded to the delegate call @link sessionM:handleDeepLinkString: @/link.
 */
- (void)executeMessageAction:(SMMessage *)message;

@end



/*!
 @class SMActivity
 @abstract UI activity presented by SessionM service such as achievement alert, user portal, etc.
 */
@interface SMActivity : NSObject

/*!
 @property activityType
 @abstract Activity type.
 */
@property(nonatomic, readonly) SMActivityType activityType;

@end



/*!
 @typedef SMAchievementDismissType
 @abstract Custom achievement dismiss type.

 @constant SMAchievementDismissTypeClaimed Achievement was claimed.
 @constant SMAchievementDismissTypeCanceled Achievement was not claimed.
 */
typedef enum SMAchievementDismissType {
    SMAchievementDismissTypeClaimed,
    SMAchievementDismissTypeCanceled
} SMAchievementDismissType;


/*!
 @class SMAchievementActivity
 @abstract Custom achievement activity.
 @discussion Custom achievement activity class should be used when customizing achievement alert presentation. 
 The class defines callback interface which application should use to communicate back to SessionM service events such as achievement presentation, claim and dismissal. Applications can subclass this class or use the instance directly as part of its custom achievement UI implementation.
 Application must observe the following rules when using this class:
 <ol>
 <li>This class can only be used for custom achievement presentation. Achievements are marked as 'custom' in the developer portal.</li>
 <li>Application can only present one achievement UI alert at a a time.</li>
 <li>Application must call @link //apple_ref/occ/instm/SMAchievementActivity/notifyPresented @/link once achievement alert UI is displayed.</li>
 <li>Application must call @link notifyDismissed: @/link with argument @link SMAchievementDismissTypeCanceled @/link when user does not engage with the achievement</li>
 <li>Application must call @link notifyDismissed: @/link with argument @link SMAchievementDismissTypeClaimed @/link when user engages with the achievement. After calling this method application must remove an achievement alert and allow SessionM to display achievement claim UI flow.</li>
 </ol>
 */
@interface SMAchievementActivity : SMActivity

/*!
 @property data
 @abstract Achievement data object.
 */
@property(nonatomic, strong, readonly) SMAchievementData *data;
/*!
 @abstract Initializes achievement activity object with achievement data.
 @param data Custom achievement data object.
 */
- (id)initWithAchievmentData:(SMAchievementData *)data __attribute__((deprecated));
- (id)initWithAchievementData:(SMAchievementData *)data;
/*!
 @abstract Notifies that achievement alert has been presented.
 @result <code>BOOL</code> indicating if invocation was successful, <code>YES</code>, or not - <code>NO</code>.
 */
- (BOOL)notifyPresented;
/*!
 @abstract Notifies that achievement alert has been dismissed. 
 @param dismissType Reason for dismissal.
 @result <code>BOOL</code> indicating if invocation was successful, <code>YES</code>, or not - <code>NO</code>.
 */
- (BOOL)notifyDismissed:(SMAchievementDismissType)dismissType;

@end



/*!
 @class SMUser
 @abstract Provides information about user such as unclaimed achievement count, point balance, opt out status, etc.
 @discussion When user data is changed as a result of user earning a new achievement or opting out of the program @link SessionMDelegate @/link method @link sessionM:didUpdateUser: @/link is called to notify the application about this event.
 */
@interface SMUser : NSObject

/*!
 @property isOptedOut
 @abstract Returns or sets user opt out status.
 @discussion Use this property to programmatically opt-in or opt-out user or query for this status. When opted out tha application can still log actions
 but they would not trigger an achievement display. User portal can still be presented in opted out state and users can opt in into the propgram from it.
 */
@property(nonatomic) BOOL isOptedOut;
/*!
 @property isLoggedIn
 @abstract Returns user's logged in status. This value is set to true for a registered user who has also verified their password for the current session through the portal - or when either @link signUpUserWithData: @/link or @link logInUserWithEmail:password: @/link is called.
 */
@property(nonatomic, readonly) BOOL isLoggedIn;
/*!
 @property isRegistered
 @abstract Returns user's registered status. This value is set to true when the account corresponds to a registered user. The user can register for an account through the portal - or when either @link signUpUserWithData: @/link or @link logInUserWithEmail:password: @/link is called.
 */
@property(nonatomic, readonly) BOOL isRegistered;
/*!
 @property pointBalance
 @abstract Returns user's current points balance.
 */
@property(nonatomic, readonly) NSUInteger pointBalance;
/*!
 @property unclaimedAchievementCount
 @abstract Returns user's unclaimed achievement count.
 */
@property(nonatomic, readonly) NSUInteger unclaimedAchievementCount;
/*!
 @property unclaimedAchievementValue
 @abstract Returns user's unclaimed achievement value.
 */
@property(nonatomic, readonly) NSUInteger unclaimedAchievementValue;
/*!
 @property achievements
 @abstract Returns an array of @link SMAchievementData @/link objects.
 */
@property(nonatomic, strong, readonly) NSArray *achievements;
/*!
 @property achievementsList
 @abstract Returns an array of @link SMAchievementData @/link objects representing the user's achievement forecast.
 */
@property(nonatomic, strong, readonly) NSArray *achievementsList;
/*!
 @property claimableAchievements
 @abstract Returns the subarray of @link achievementsList @/link that contains all achievements that the user can currently claim.
 */
@property(nonatomic, strong, readonly) NSArray *claimableAchievements;

@end



/*!
 @group SessionM Notifications
 */

/*!
 @const SMSessionMDidTransitionToStateNotification
 @abstract This notification is sent when session changes its session state.
 */
extern NSString *const SMSessionMDidTransitionToStateNotification;
/*!
 @const SMSessionMStateNotificationKey
 @abstract Key for accessing the state in the @link SMSessionMDidTransitionToStateNotification @/link <code>userInfo</code> dictionary. State is sent as an <code>NSNumber</code>.
 */
extern NSString *const SMSessionMStateNotificationKey;
/*!
 @const SMSessionMDidUpdateUserInfoNotification
 @abstract This notification is sent when the user's unclaimed achievement count changes.
 */
extern NSString *const SMSessionMDidUpdateUserInfoNotification;



/*!
 @group User action meta data keys
 */

/*!
 @const SMUserActionAchievementNameKey
 @abstract Achievement name key.
 */
extern NSString *const SMUserActionAchievementNameKey;
/*!
 @const SMUserActionSponsorContentNameKey
 @abstract Sponsor content name key.
 */
extern NSString *const SMUserActionSponsorContentNameKey;
/*!
 @const SMUserActionPageNameKey
 @abstract User portal page name key.
 */
extern NSString *const SMUserActionPageNameKey;
/*!
 @const SMUserActionRewardNameKey
 @abstract Reward name key.
 */
extern NSString *const SMUserActionRewardNameKey;



/*!
 @group User data dictionary keys
 */

/*!
 @const SMUserDataEmailKey
 @abstract Email key.
 */
extern NSString *const SMUserDataEmailKey;
/*!
 @const SMUserDataPasswordKey
 @abstract Password key.
 */
extern NSString *const SMUserDataPasswordKey;
/*!
 @const SMUserDataYOBKey
 @abstract Year of birth key.
 */
extern NSString *const SMUserDataYOBKey;
/*!
 @const SMUserDataBirthYearKey
 @abstract Year of birth key.
 */
extern NSString *const SMUserDataBirthYearKey;
/*!
 @const SMUserDataAgeKey
 @abstract Age key.
 */
extern NSString *const SMUserDataAgeKey;
/*!
 @const SMUserDataGenderKey
 @abstract Gender key.
 */
extern NSString *const SMUserDataGenderKey;
/*!
 @const SMUserDataProfileImageURLKey
 @abstract Profile image URL key.
 */
extern NSString *const SMUserDataProfileImageURLKey;
/*!
 @const SMUserDataFirstNameKey
 @abstract First name key.
 */
extern NSString *const SMUserDataFirstNameKey;
/*!
 @const SMUserDataLastNameKey
 @abstract Last name key.
 */
extern NSString *const SMUserDataLastNameKey;
/*!
 @const SMUserDataZipcodeKey
 @abstract Zipcode key.
 */
extern NSString *const SMUserDataZipcodeKey;


#endif /* __SESSIONM__ */
