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
        [SessionM sharedInstance].logLevel = SMLogLevelInfo;
        [[SessionM sharedInstance] startSessionWithAppID:appId];
        [SessionM sharedInstance].delegate = self;
        // Comment the line below to stop auto presenting activities
        self.shouldAutoPresent = YES;
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];

}

- (void) startCustomSession:(CDVInvokedUrlCommand*)command
{
    
    CDVPluginResult* pluginResult;
    
    if(command.arguments.count < 2) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        NSString* serverURL = [command.arguments objectAtIndex:0];
        NSString* appId = [command.arguments objectAtIndex:1];
        NSLog(@"Starting SessionM Session with server %@ key %@", serverURL, appId);
        [SessionM sharedInstance].logLevel = SMLogLevelInfo;
        SM_SET_SERVER_URL(serverURL);
        [[SessionM sharedInstance] startSessionWithAppID:appId];
        [SessionM sharedInstance].delegate = self;
        // Comment the line below to stop auto presenting activities
        self.shouldAutoPresent = YES;
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

- (void) getUnclaimedAchievementCount: (CDVInvokedUrlCommand *)command {
    
    NSString *unclaimedAchievementCount = [NSString stringWithFormat:@"%d", [SessionM sharedInstance].user.unclaimedAchievementCount];
 
    NSDictionary *jsonObj = [ [NSDictionary alloc]
                             initWithObjectsAndKeys :
                             unclaimedAchievementCount, @"unclaimedAchievementCount",
                             @"true", @"success",
                             nil
                             ];
    
    CDVPluginResult *pluginResult = [ CDVPluginResult
                                     resultWithStatus    : CDVCommandStatus_OK
                                     messageAsDictionary : jsonObj
                                     ];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) getUnclaimedAchievementValue: (CDVInvokedUrlCommand *)command {
    
    NSString *unclaimedAchievementValue = [NSString stringWithFormat:@"%d", [SessionM sharedInstance].user.unclaimedAchievementValue];
    
    NSDictionary *jsonObj = [ [NSDictionary alloc]
                             initWithObjectsAndKeys :
                             unclaimedAchievementValue, @"unclaimedAchievementValue",
                             @"true", @"success",
                             nil
                             ];
    
    CDVPluginResult *pluginResult = [ CDVPluginResult
                                     resultWithStatus    : CDVCommandStatus_OK
                                     messageAsDictionary : jsonObj
                                     ];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) logInUserWithEmail:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;
    
    if(command.arguments.count < 2) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        NSString* email = [command.arguments objectAtIndex:0];
        NSString* password = [command.arguments objectAtIndex:1];
        NSLog(@"Log in user: email %@", email);
        [[SessionM sharedInstance] logInUserWithEmail:email password:password];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) signUpUserWithData:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;
    
    if(command.arguments.count < 5) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_INVALID_ACTION];
    } else {
        NSMutableDictionary *userData = [NSMutableDictionary dictionary];
        NSString* email = [command.arguments objectAtIndex:0];
        NSString* password = [command.arguments objectAtIndex:1];
        NSString* yearOfBirth = [command.arguments objectAtIndex:2];
        NSString* gender = [command.arguments objectAtIndex:3];
        NSString* zipcode = [command.arguments objectAtIndex:4];

        [userData setObject:email forKey:SMUserDataEmailKey];
        [userData setObject:password forKey:SMUserDataPasswordKey];
        [userData setObject:yearOfBirth forKey:SMUserDataBirthYearKey];
        [userData setObject:gender forKey:SMUserDataGenderKey];
        [userData setObject:zipcode forKey:SMUserDataZipcodeKey];
        NSLog(@"Sign up user: email %@ year of birth %@ gender %@ zipcode %@", email, yearOfBirth, gender, zipcode);
        [[SessionM sharedInstance] signUpUserWithData:userData];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) logOutUser:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult;

    NSLog(@"Log out user");
    [[SessionM sharedInstance] logOutUser];
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    
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
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.stateTransitionCallbackId = command.callbackId;

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


- (void) setUnclaimedAchievementCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.unclaimedAchievementCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setUpdateUserCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.updateUserCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setActivityUnavailableCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.activityUnavailableCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setWillPresentActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.willPresentActivityCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setDidPresentActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.didDismissActivityCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setWillDismissActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.willDismissActivityCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setDidDismissActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.didDismissActivityCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setWillStartPlayingMediaForActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.willStartPlayingMediaForActivityCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setDidFinishPlayingMediaForActivityCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.didFinishPlayingMediaForActivityCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setUserActionCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.userActionCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void) setFailureCallback:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_NO_RESULT];
    [pluginResult setKeepCallbackAsBool:YES];
    self.failureCallbackId = command.callbackId;
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
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
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.unclaimedAchievementCallbackId];
}

- (void)sessionM:(SessionM *)sessionM didTransitionToState:(SessionMState)state
{
    if(!self.stateTransitionCallbackId) {
        return;
    }
    NSLog(@"didTransitionToState: %d", state);
    
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:state];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.stateTransitionCallbackId];
}

- (void)sessionM:(SessionM *)sessionM didFailWithError:(NSError *)error
{
    if(!self.failureCallbackId) { 
        return; 
    }
    NSLog(@"didFailWithError: %@", error);
    NSDictionary *failureMessage = @{@"error" : [NSString stringWithFormat:@"%@", error]};
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:failureMessage];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.failureCallbackId];
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
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.updateUserCallbackId];
}

- (void)sessionM:(SessionM *)sessionM didUpdateUserRegistrationResult:(SMUserRegistrationResultType)result errorMessages:(NSArray *)errorMessages
{
    if(!self.updateUserCallbackId) {
        return;
    }
    NSDictionary *callbackDict;
    if (sessionM.userRegistrationResult == SMUserRegistrationResultTypeFailure) {
        if ([errorMessages count] > 1)
            callbackDict = @{ @"errorMessage": [errorMessages objectAtIndex:1]};
    }
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:callbackDict];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.updateUserCallbackId];
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
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.activityUnavailableCallbackId];
}

- (void)sessionM:(SessionM *)sessionM willPresentActivity:(SMActivity *)activity
{
    if(!self.willPresentActivityCallbackId) {
        return;
    }
    NSLog(@"willPresetActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.willPresentActivityCallbackId];
}

- (void)sessionM:(SessionM *)sessionM didPresentActivity:(SMActivity *)activity
{
    if(!self.didPresentActivityCallbackId) {
        return;
    }
    NSLog(@"didPresentActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.didPresentActivityCallbackId];
}

- (void)sessionM:(SessionM *)sessionM didDismissActivity:(SMActivity *)activity
{
    if(!self.didDismissActivityCallbackId) {
        return;
    }
    NSLog(@"didDismissActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.didDismissActivityCallbackId];
}

- (void)sessionM:(SessionM *)sessionM willDismissActivity:(SMActivity *)activity
{
    if(!self.willDismissActivityCallbackId) {
        return;
    }
    NSLog(@"willDismissActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.willDismissActivityCallbackId];
}

- (void)sessionM:(SessionM *)sessionM willStartPlayingMediaForActivity:(SMActivity *)activity
{
    if(!self.willStartPlayingMediaForActivityCallbackId) {
        return;
    }
    NSLog(@"willStartPlayingMediaForActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.willStartPlayingMediaForActivityCallbackId];
}

- (void)sessionM:(SessionM *)sessionM didFinishPlayingMediaForActivity:(SMActivity *)activity
{
    if(!self.didFinishPlayingMediaForActivityCallbackId) {
        return;
    }
    NSLog(@"didFinishPlayingMediaForActivity: %@", activity);
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:activity.activityType];
    [pluginResult setKeepCallbackAsBool:YES];
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.didFinishPlayingMediaForActivityCallbackId];
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
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.userActionCallbackId];
}


@end
