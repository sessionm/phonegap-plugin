//
//  SessionMPhoneGapPlugin.h
//
//

#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>
#import "SessionM.h"

@interface SessionMPhoneGapPlugin : CDVPlugin<SessionMDelegate> {
    
}

typedef enum PresentType{
    ACHIEVEMENT = 1,
    PORTAL = 2,
    INTERSTITIAL = 3
} PresentType;

@end
