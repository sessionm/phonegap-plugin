//
//  SMLocationEvent.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*!
 @typedef SMLocationEventTriggerType
 @abstract Specifies how the location event is triggered.

 @constant SMLocationEventTriggerTypeExit Location event is triggered by exiting the associated geofence.
 @constant SMLocationEventTriggerTypeEnter Location event is triggered by entering the associated geofence.
 @constant SMLocationEventTriggerTypeDwell Location event is triggered by remaining in the associated geofence for the amount of time specified by @link delay @/link.
 */
typedef enum SMLocationEventTriggerType {
    SMLocationEventTriggerTypeExit,
    SMLocationEventTriggerTypeEnter,
    SMLocationEventTriggerTypeDwell
} SMLocationEventTriggerType;


/*!
 @class SMLocationEvent
 @abstract Defines the data associated with a location-based event and its associated geofence.
 @discussion Location event properties can be configured from the SessionM Mobile Marketing Cloud portal's Behaviors module.
 */
@interface SMLocationEvent : NSObject

/*!
 @property eventName
 @abstract Location event behavior name.
 */
@property(nonatomic, strong, readonly) NSString *eventName;
/*!
 @property latitude
 @abstract Latitude for the geofence center point.
 */
@property(nonatomic, assign, readonly) CLLocationDegrees latitude;
/*!
 @property longitude
 @abstract Longitude for the geofence center point.
 */
@property(nonatomic, assign, readonly) CLLocationDegrees longitude;
/*!
 @property radius
 @abstract Geofence radius of effect (in meters).
 */
@property(nonatomic, assign, readonly) int radius;
/*!
 @property triggerType
 @abstract Specifies how the location event is triggered.
 */
@property(nonatomic, assign, readonly) SMLocationEventTriggerType triggerType;
/*!
 @property delay
 @abstract Specifies how long a user must remain in the geofence to trigger the location event when @link triggerType @/link is set to <code>SMLocationEventTriggerTypeDwell</code>.
 @discussion <code>delay</code> is set to <code>0</code> for non-applicable values of @link triggerType @/link.
 */
@property(nonatomic, assign, readonly) NSTimeInterval delay;
/*!
 @property metaData
 @abstract Meta data associated with the location event.
 */
@property(nonatomic, strong, readonly) NSDictionary *metaData;
/*!
 @property distance
 @abstract Distance from @link //apple_ref/occ/instp/SMLocationManager/currentGeoLocation @/link to the geofence center point.
 */
@property(nonatomic, assign, readonly) CLLocationDistance distance;

@end
