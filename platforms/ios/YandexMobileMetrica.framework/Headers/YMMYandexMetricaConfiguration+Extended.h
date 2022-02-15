/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

#if __has_include("YandexMobileMetrica.h")
    #import "YMMYandexMetricaConfiguration.h"
    #import "YMMYandexMetricaExtendedConfigurationDelegate.h"
#else
    #import <YandexMobileMetrica/YMMYandexMetricaConfiguration.h>
    #import <YandexMobileMetrica/YMMYandexMetricaExtendedConfigurationDelegate.h>
#endif

@class YMMPulseConfiguration;

@interface YMMYandexMetricaConfiguration ()

/** Set/get arbitrary application build number for AppMetrica to report.

 If not set, AppMetrica will use the application build number set in the app configuration file Info.plist (CFBundleVersion).
 Build number value should be a numeric string that can be converted to an positive integer.
 */
@property (nonatomic, copy, nullable) NSString *appBuildNumber;

/** Set/get proxy urls for AppMetrica to use for startup requests.
 */
@property (nonatomic, copy, nullable) NSArray *startupHosts;

/** Set/get delegate to provide extra information to SDK during application lifecycle.
 */
@property (nonatomic, weak, nullable) id<YMMYandexMetricaExtendedConfigurationDelegate> delegate;

/** Enable/disable accurate location retrieval for internal location manager.
 Has effect only when locationTrackingEnabled is 'YES', and location is not set manually.
 */
@property (nonatomic, assign) BOOL accurateLocationTracking;

/** Set/get custom dispatch period. Interval in seconds between sending events to the server.
 By default, 90 seconds. Setting to 0 seconds prevents library from sending events automatically using timer.
 */
@property (nonatomic, assign) NSUInteger dispatchPeriod;

/** Set/get the maximum number of stored events. Minimum number of cached events that causes reports to be automatically sent.
 By default, events are sent automatically when there are at least 7 items in the storage.
 Setting to 0 value prevents library from sending events automatically upon reaching specified number of events in the storage.
 */
@property (nonatomic, assign) NSUInteger maxReportsCount;

/** Set/get Pulse SDK configuration.

 To activate Pulse you should provide this configuration.
 Pulse will not be activated in extensions.
 For more information about Pulse SDK see https://wiki.yandex-team.ru/pulse/Pulse.Production-Metrics/
 */
@property (nonatomic, copy, nullable) YMMPulseConfiguration *pulseConfiguration;

/** Enable/disable probably unhandled crashes (like Out Of Memory) tracking.

 Disabled by default.
 To enable probably unhandled crash tracking, set the property value to YES.
 */
@property (nonatomic, assign) BOOL probablyUnhandledCrashReporting;

/** Crash reports will not be sent if crash is caused by signal from ignoredCrashSignals array.
 Array should contain NSNumber objects configured with signal values defined in <sys/signal.h>.
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *ignoredCrashSignals;

/** Crashes will be reported as errors if crash is caused by signal from errorSignals array.
 Array should contain NSNumber objects configured with signal values defined in <sys/signal.h>.
 This parameter is not processed since 3.7.0
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *errorSignals DEPRECATED_ATTRIBUTE;

/** Enable/disable background location updates tracking.

 Disabled by default.
 To enable background location updates tracking, set the property value to YES.
 @see https://developer.apple.com/reference/corelocation/cllocationmanager/1620568-allowsbackgroundlocationupdates
 */
@property (nonatomic, assign) BOOL allowsBackgroundLocationUpdates;

/** Enable/disable ANR detection.
 Detects blocked the main thread and reports it. Tries to submit block on the main queue and waits for the response.
 ANR detection automatically paused as the application enters background mode and vice versa.
 
 @note Disabled by default.
 To enable ANR detection, set the property value to YES.
 */
@property (nonatomic, assign) BOOL applicationNotRespondingDetection;

/** Sets/gets time interval the watchdog queue would wait for the main queue response before report ANR.
 
 @note The default value is 4 seconds.
 Takes effect only after the activation and enabling `allowsBackgroundLocationUpdates` flag.
 */
@property (nonatomic, assign) NSTimeInterval applicationNotRespondingWatchdogInterval;

/** Sets/gets time interval the watchdog queue would ping the main queue.
 
 @note The default value is 0.1 second.
 Takes effect only after activation and enabling allowsBackgroundLocationUpdates flag.
 @warning A small value can lead to poor performance.
 */
@property (nonatomic, assign) NSTimeInterval applicationNotRespondingPingInterval;

@end
