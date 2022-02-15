/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#if __has_include("YandexMobileMetrica.h")
    #import "YMMYandexMetrica.h"
    #import "YMMCompletionBlocks+Extended.h"
#else
    #import <YandexMobileMetrica/YMMYandexMetrica.h>
    #import <YandexMobileMetrica/YMMCompletionBlocks+Extended.h>
#endif

@class YMMReporterConfiguration;
@class YMMUserInfo;
@class YMMCrash;
@class YMMPulseConfiguration;
@protocol YMMReporting;

NS_ASSUME_NONNULL_BEGIN

@interface YMMYandexMetrica ()

/** Activating pulse
 Activates pulse. Does nothing if it has been already activated.
 
 @param pulseConfiguration Configuration combines all Pulse settings in one place.
 */
+ (void)activatePulseWithConfiguration:(YMMPulseConfiguration *)pulseConfiguration;

/** Setting user info to metrica.
 Record user identifier.
 After the value is set, each following event refers to that user.
 If nil is set, user info will no longer be sent.

 @param userInfo Application user information.
 @param onFailure Block to be executed if an error occurres while setting user info. 
 The error is passed as block argument.
 */
+ (void)setUserInfo:(nullable YMMUserInfo *)userInfo
          onFailure:(nullable void (^)(NSError *error))onFailure;

/** Getting all identifiers

 @param queue Queue for the block to be dispatched to. If nil, main queue is used.
 @param block Block will be dispatched upon identifiers becoming available or in a case of error.
 If they are available at the moment of call - block is dispatched immediately. See definition
 of YMMIdentifiersCompletionBlock for more detailed information on returned types.
 */
+ (void)requestStartupIdentifiersWithCompletionQueue:(nullable dispatch_queue_t)queue
                                     completionBlock:(YMMIdentifiersCompletionBlock)block;

/** Getting identifiers for specific keys

 @param keys Array of identifier keys to request. See YMMCompletionBlocks+Extended.h.
 @param queue Queue for the block to be dispatched to. If nil, main queue is used.
 @param block Block will be dispatched upon identifiers becoming available or in a case of error.
 If they are available at the moment of call - block is dispatched immediately. Some keys may require
 a network request to startup. See definition of YMMIdentifiersCompletionBlock for more detailed
 information on returned types.
 */
+ (void)requestStartupIdentifiersWithKeys:(NSArray *)keys
                          completionQueue:(nullable dispatch_queue_t)queue
                          completionBlock:(YMMIdentifiersCompletionBlock)block;

/** Retrieves current UUID.

 @return UUID string. If it is not available at the moment of call nil is returned.
 */
+ (nullable NSString *)uuid;

/** Retrieves current device ID.

 @return Device ID string. If it is not available at the moment of call nil is returned.
 */
+ (nullable NSString *)deviceID;

/** Returns id<YMMReporting> that can send events to specific API key.

 @param apiKey Api key to send events to.
 @return id<YMMReporting> that conforms to YMMReporting and handles sending events to specified apikey
 */
+ (nullable id<YMMReporting>)extendedReporterForApiKey:(NSString *)apiKey;

/** Enabling/disabling accurate location retrieval for internal location manager.

 @param accurateLocationEnabled Indicates whether accurate location retrieval should be enabled.
 Has effect only when locationTrackingEnabled is 'YES', and location is not set manually.
 */
+ (void)setAccurateLocationTracking:(BOOL)accurateLocationEnabled;

/** Enable/disable background location updates tracking.

 Disabled by default.
 @param allowsBackgroundLocationUpdates Indicates whether background location updating should be enabled.
 @see https://developer.apple.com/reference/corelocation/cllocationmanager/1620568-allowsbackgroundlocationupdates
 */
+ (void)setAllowsBackgroundLocationUpdates:(BOOL)allowsBackgroundLocationUpdates;

/** Reporting statbox event with a string as value.
 
 @param value Any string to be sent to server.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
+ (void)reportStatboxEvent:(NSString *)value
                 onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting statbox report with provided data.

 @param name event name to send
 @param value event value to send
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
+ (void)reportStatboxEventWithName:(nullable NSString *)name
                             value:(NSString *)value
                         onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting statbox report with provided parameters.
 Parameters should be valid for serialization in JSON.

 @param name event name to send
 @param parameters event parameters to send as JSON-string
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
+ (void)reportStatboxEventWithName:(nullable NSString *)name
                        parameters:(NSDictionary *)parameters
                         onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting user info event.

 @param userInfo User information to be sent to server once.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
+ (void)reportUserInfoEvent:(YMMUserInfo *)userInfo
                  onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting diagnostic event with additional parameters.

 @param name Short name or description of the event.
 @param parameters Dictionary of name/value pairs that must be sent to the server.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
+ (void)reportDiagnosticEvent:(NSString *)name
                   parameters:(NSDictionary *)parameters
                    onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting diagnostic statbox event with value.

 @param name Short name or description of the event.
 @param value String value of event.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
+ (void)reportDiagnosticStatboxEvent:(NSString *)name
                               value:(NSString *)value
                           onFailure:(nullable void (^)(NSError *error))onFailure;

/** Setting key - value data to be used as additional information, associated with all future events.
 If value is nil, previously set key-value is removed. Does nothing if key hasn't been added.

 @param value The app environment value.
 @param key The app environment key.
 */
+ (void)setAppEnvironmentValue:(nullable NSString *)value forKey:(NSString *)key;

/** Clearing app environment, e.g. removes all key - value data associated with all future events.
 */
+ (void)clearAppEnvironment;

/** Reporting custom crash

 @param crash The crash to report.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
+ (void)reportCrash:(YMMCrash *)crash
          onFailure:(nullable void (^)(NSError *error))onFailure;

/** Requests crash reporting state

 @param completionQueue Queue for the block to be dispatched to. If nil, main queue is used.

 @param completionBlock Block will be dispatched upon crash state becoming available.
 If it is available at the moment of call - block is dispatched immediately. See definition
 of YMMCrashReportingStateCompletionBlock for more detailed information on returned types.
 */
+ (void)requestCrashReportingStateWithCompletionQueue:(nullable dispatch_queue_t)completionQueue
                                      completionBlock:(YMMCrashReportingStateCompletionBlock)completionBlock;

/** Enable ANR monitoring with default parameters.
 
 Default parameters:
 - `watchdog` interval 4 seconds,
 - `ping` intercal 0.1 second.
 
 @note Use this method to enable ANR monitoring only after the activation.
 Use the applicationNotRespondingDetection property of YMMYandexMetricaConfiguration if you want to enable
 ANR monitoring at the time of activation.
 */
+ (void)enableANRMonitoring;

/** Enable ANR monitoring.
 Use this method to enable ANR monitoring only after the activation.
 
 @param watchdog Time interval the watchdog queue would wait for the main queue response before report ANR.
 @param ping Time interval the watchdog queue would ping the main queue.
 
 @note Use the `applicationNotRespondingDetection` property of `YMMYandexMetricaConfiguration` if you want to enable
 ANR monitoring during the activation.
 @warning A small `ping` value can lead to poor performance.
 */
+ (void)enableANRMonitoringWithWatchdogInterval:(NSTimeInterval)watchdog pingInterval:(NSTimeInterval)ping;

@end

NS_ASSUME_NONNULL_END
