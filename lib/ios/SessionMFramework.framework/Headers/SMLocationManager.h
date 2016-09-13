//
//  SMLocationManager.h
//  SessionM
//
//  Copyright © 2016 SessionM. All rights reserved.
//

#ifndef __SM_LOCATION_MANAGER__
#define __SM_LOCATION_MANAGER__

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "SMLocationEvent.h"

/*!
 @const SMLocationManagerUpdateNotification
 @abstract This notification is sent when the location is updated.
 @discussion The notification's <code>userInfo</code> will have the <code>\@"location"</code> key set to the current location.
 */
extern NSString *const SMLocationManagerUpdateNotification;
/*!
 @const SMLocationManagerLocationServicesDisabled
 @abstract This notification is sent when location services are disabled.
 @discussion Whenever the location service has been started but the device does not have permission to use location services, this notification is fired.
 */
extern NSString *const SMLocationManagerLocationServicesDisabled;
/*!
 @const SMLocationManagerMonitorRegionsDidFailWithErrorNotification
 @abstract This notification is sent when region monitoring fails.
 @discussion When this notification is recieved, region monitoring did not start. Simply call @link startGeofenceService @/link to try again. The notification's <code>userInfo</code> will have the <code>\@"error"</code> key set to the error.
 */
extern NSString *const SMLocationManagerMonitorRegionsDidFailWithErrorNotification;
/*!
 @const SMLocationManagerAlwaysOnLocationServicesDisabled
 @abstract This notification is sent when region monitoring fails due to not having always on permission.
 @discussion When this notification is recieved, region monitoring did not start because always on permission was not granted. Simply call @link startGeofenceService @/link to try again. The notification's <code>userInfo</code> will have the <code>\@"error"</code> key set to the error.
 */
extern NSString *const SMLocationManagerAlwaysOnLocationServicesDisabled;

/*!
 @const SMLocationManagerMonitoredEventLimit
 @abstract The default maximum size for the amount of monitored location events in the @link locationEvents @/link array.
 */
extern NSUInteger const SMLocationManagerMonitoredEventLimit;


/*!
 @class SMLocationManager
 @abstract SessionM Location service interface. This is the main class in SessionM Location iOS SDK. It defines methods for all location based operations such as location and region monitoring.
 */
@interface SMLocationManager : NSObject<CLLocationManagerDelegate>

/*!
 @property isStarted
 @abstract <code>BOOL</code> indicating whether location updates have started or not.
 */
@property(nonatomic, readonly) BOOL isStarted;
/*!
 @property isGeofenceServiceStarted
 @abstract <code>BOOL</code> indicating whether geofence updates have started or not.
 */
@property(nonatomic, readonly) BOOL isGeofenceServiceStarted;
/*!
 @property currentGeoLocation
 @abstract Most current CLLocation returned by location services.
 */
@property(nonatomic, strong, readonly) CLLocation *currentGeoLocation;
/*!
 @property locationEvents
 @abstract Currently monitored events that can be triggered by entering or exiting a geofence.
 */
@property(nonatomic, strong, readonly) NSArray<SMLocationEvent *> *locationEvents;

/*!
 @abstract Returns singleton <code>SMLocationManger</code> service instance with a monitored location event limit of @link SMLocationManagerMonitoredEventLimit @/link.
 @result <code>SMLocationManger</code> service object.
 */
+ (SMLocationManager *)sharedInstance;
/*!
 @abstract Returns <code>SMLocationManger</code> service instance with the specified monitored location event limit.
 @param limit Maximum amount of location events that will be monitored at any given time.
 @result <code>SMLocationManger</code> service object.
 */
- (id)initWithEventLimit:(NSUInteger)limit;
/*!
 @abstract Starts location services.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will start location updates. If permission is denied a @link SMLocationManagerLocationServicesDisabled @/link notification will be fired. This method looks for the Cocoa Key <code>NSLocationAlwaysUsageDescription</code> to determine whether to start always-on or while-in-use monitoring.
 */
- (void)start;
/*!
 @abstract Stops location services.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will stop location updates. This does not clear monitored regions that persist across app launches.
 */
- (void)stop;
/*!
 @abstract Starts region monitoring based on SessionM Mobile Marketing Cloud portal configurations.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will start monitoring regions based on configurations setup by the developer in the SessionM Mobile Marketing Cloud portal. Regions monitored persist across app launches and are only cleared via @link stopGeofenceService @/link. Required always-on location permission to work.
 */
- (void)startGeofenceService;
/*!
 @abstract Refreshes region monitoring based on SessionM Mobile Marketing Cloud portal configurations.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will refresh monitoring regions based on configurations setup by the developer in the SessionM Mobile Marketing Cloud portal. Regions monitored persist across app launches and are only cleared via @link stopGeofenceService @/link. Required always-on location permission to work.
 */
- (void)refreshGeofenceService;
/*!
 @abstract Stops all region monitoring.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will stop monitoring all regions.
 */
- (void)stopGeofenceService;

@end

#endif /* __SM_LOCATION_MANAGER__ */
