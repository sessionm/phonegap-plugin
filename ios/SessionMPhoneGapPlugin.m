//
//  SessionMPhoneGapPlugin.m
//
//

#import "SessionMPhoneGapPlugin.h"

@interface SessionMPhoneGapPlugin ()

@property(nonatomic,assign) BOOL shouldAutoPresentMode;

//Callbacks
@property(nonatomic,copy) NSString *unclaimedAchievementCallbackId;
@property(nonatomic,copy) NSString *stateTransitionCallbackId;
@property(nonatomic,copy) NSString *failureCallbackId;
@property(nonatomic,copy) NSString *updateUserCallbackId;
@property(nonatomic,copy) NSString *activityUnavailableCallbackId;
@property(nonatomic,copy) NSString *willPresentActivityCallbackId;
@property(nonatomic,copy) NSString *didPresentActivityCallbackId;
@property(nonatomic,copy) NSString *willDismissActivityCallbackId;
@property(nonatomic,copy) NSString *didDismissActivityCallbackId;
@property(nonatomic,copy) NSString *willStartPlayingMediaForActivityCallbackId;
@property(nonatomic,copy) NSString *didFinishPlayingMediaForActivityCallbackId;
@property(nonatomic,copy) NSString *userActionCallbackId;

//Custom achievement
@property(nonatomic,retain) SMAchievementActivity *achievementActivity;
@property(nonatomic,assign) BOOL shouldAutoPresent;

@end

@implementation SessionMPhoneGapPlugin

- (void) startSession:(CDVInvokedUrlCommand*)command
{
    
    CDVPluginResult* pluginResult;

    if(command.arguments.count < 1) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        NSString* appId = [command.arguments objectAtIndex:0];
        NSLog(@"Starting SessionM Session with key %@", appId);
        [SessionM sharedInstance].logLevel = SMLogLevelDebug;
        [[SessionM sharedInstance] startSessionWithAppID:appId];
        [SessionM sharedInstance].delegate = self;
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];

}

- (void) logAction:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;

    if(command.arguments.count < 1) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        NSString* action = [command.arguments objectAtIndex:0];
        NSLog(@"Logging Action %@", action);
        [[SessionM sharedInstance] logAction:action];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) presentActivity:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;
    if(command.arguments.count < 1) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        NSNumber* activityType = [command.arguments objectAtIndex:0];
        NSLog(@"present activity type %@", activityType);
        [[SessionM sharedInstance] presentActivity:[activityType intValue]];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)setAutoPresentMode:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;
    
    if(command.arguments.count < 1) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        NSNumber* autoPresentMode = [command.arguments objectAtIndex:0];
        NSLog(@"auto present mode %@", autoPresentMode);
        self.shouldAutoPresent = [autoPresentMode boolValue];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

#pragma mark - Custom Achievements

- (void) notifyCustomAchievementPresented:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;
        
    if(!self.achievementActivity) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        [self.achievementActivity notifyPresented];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) notifyCustomAchievementCancelled:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;
    
    if(!self.achievementActivity) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        [self.achievementActivity notifyDismissed:SMAchievementDismissTypeCanceled];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) notifyCustomAchievementClaimed:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;
    
    if(!self.achievementActivity) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        [self.achievementActivity notifyDismissed:SMAchievementDismissTypeClaimed];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}



#pragma mark - Callbacks Setters

- (void) setStateTransitionCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.stateTransitionCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}


- (void) setUnclaimedAchievementCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.unclaimedAchievementCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setUpdateUserCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.updateUserCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setActivityUnavailableCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.activityUnavailableCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setWillPresentActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.willPresentActivityCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setDidPresentActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.didDismissActivityCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setWillDissmissActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.willDismissActivityCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setDidDissmissActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.didDismissActivityCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setWillStartPlayingMediaForActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.willStartPlayingMediaForActivityCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setDidFinishPlayingMediaForActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.didFinishPlayingMediaForActivityCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setUserActionCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.userActionCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

- (void) setFailureCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* javaScript = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.failureCallbackId = command.callbackId;
    
    javaScript = [pluginResult toSuccessCallbackString:command.callbackId];
    [self writeJavascript:javaScript];
}

#pragma mark - SessionMDelegate

- (UIViewController*)sessionM:(SessionM *)session viewControllerForActivity:(SMActivityType)type
{
    return self.viewController;
}

- (UIView *)sessionM:(SessionM *)session viewForActivity:(SMActivityType)type
{
    return self.webView;
}


- (void)sessionM:(SessionM *)sessionM didUpdateUnclaimedAchievement:(SMAchievementData *)achievement
{
    if(!self.unclaimedAchievementCallbackId) {
        return;
    }
    NSLog(@"didUpdateUnclaimed achievement: %@", achievement);
    
    self.achievementActivity = [[SMAchievementActivity alloc] initWithAchievmentData:achievement];
    
    NSDictionary *callbackDict = @{ @"iconURL": achievement.achievementIconURL,
                                    @"name" : achievement.name,
                                    @"message" : achievement.message,
                                    @"points" : [NSString stringWithFormat:@"%d", achievement.mpointValue],
                                    @"isCustom" : [NSNumber numberWithBool:achievement.isCustom],
                                    @"action" : achievement.action };
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:callbackDict];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.unclaimedAchievementCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM didTransitionToState:(SessionMState)state
{
    if(!self.stateTransitionCallbackId) {
        return;
    }
    NSLog(@"didTransitionToState: %d", state);
    
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:state];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.stateTransitionCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM didFailWithError:(NSError *)error
{
    if(!self.stateTransitionCallbackId) {
        return;
    }
    NSLog(@"didFailWithError: %@", error);
    NSDictionary *failureMessage = @{@"error" : [NSString stringWithFormat:@"%@", error]};
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:failureMessage];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.failureCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM didUpdateUser:(SMUser *)user
{
    if(!self.updateUserCallbackId) {
        return;
    }
    NSLog(@"didUpdateUser: %@", user);
    NSDictionary *callbackDict = @{ @"optedOut": [NSNumber numberWithBool:user.isOptedOut],
                                    @"unclaimedAchievementCount" : [NSNumber numberWithInt:user.unclaimedAchievementCount],
                                    @"unclaimedAchievementValue" : [NSNumber numberWithInt:user.unclaimedAchievementValue],
                                    @"pointBalance" :  [NSNumber numberWithInt:user.pointBalance]};
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:callbackDict];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.updateUserCallbackId];
    [self writeJavascript:javascript];
}

- (BOOL)sessionM:(SessionM *)sessionM shouldAutopresentActivity:(SMActivityType)type
{
    return self.shouldAutoPresent;
}

- (void)sessionM:(SessionM *)sessionM activityUnavailable:(SMActivityType)type
{
    if(!self.activityUnavailableCallbackId) {
        return;
    }
    NSLog(@"activityUnavailable: %d", type);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:type];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.activityUnavailableCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM willPresentActivity:(SMActivity *)activity
{
    if(!self.willPresentActivityCallbackId) {
        return;
    }
    NSLog(@"willPresetActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.willPresentActivityCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM didPresentActivity:(SMActivity *)activity
{
    if(!self.didPresentActivityCallbackId) {
        return;
    }
    NSLog(@"didPresentActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.didPresentActivityCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM didDismissActivity:(SMActivity *)activity
{
    if(!self.didDismissActivityCallbackId) {
        return;
    }
    NSLog(@"didDismissActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.didDismissActivityCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM willDismissActivity:(SMActivity *)activity
{
    if(!self.willDismissActivityCallbackId) {
        return;
    }
    NSLog(@"willDismissActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.willDismissActivityCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM willStartPlayingMediaForActivity:(SMActivity *)activity
{
    if(!self.willStartPlayingMediaForActivityCallbackId) {
        return;
    }
    NSLog(@"willStartPlayingMediaForActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.willStartPlayingMediaForActivityCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM didFinishPlayingMediaForActivity:(SMActivity *)activity
{
    if(!self.didFinishPlayingMediaForActivityCallbackId) {
        return;
    }
    NSLog(@"didFinishPlayingMediaForActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.didFinishPlayingMediaForActivityCallbackId];
    [self writeJavascript:javascript];
}

- (void)sessionM:(SessionM *)sessionM user:(SMUser *)user didPerformAction:(SMActivityUserAction)action forActivity:(SMActivity *)activity withData:(NSDictionary *)data
{
    if(!self.didFinishPlayingMediaForActivityCallbackId) {
        return;
    }
    NSLog(@"user didPerformAction: %d, %@", action, data);
    
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] initWithDictionary:data];
    dict[@"_action"] = [NSNumber numberWithInt:action];
    
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:dict];
    [pluginResult setKeepCallbackAsBool:YES];
    
    NSString* javascript = [pluginResult toSuccessCallbackString:self.userActionCallbackId];
    [self writeJavascript:javascript];
}


@end
