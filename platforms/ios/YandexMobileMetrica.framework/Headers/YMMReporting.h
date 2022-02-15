/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

#if __has_include("YandexMobileMetrica.h")
    #import "YMMYandexMetricaReporting.h"
#else
    #import <YandexMobileMetrica/YMMYandexMetricaReporting.h>
#endif

@class YMMUserInfo;
@class YMMCrashMatchingRule;
@class YMMCrash;

NS_ASSUME_NONNULL_BEGIN

/** YMMReporting protocol groups methods that are used by custom reporting objects.
 */
@protocol YMMReporting <YMMYandexMetricaReporting>

/** Reporting user info event.

 @param user YMMUserInfo object.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
- (void)reportUserInfoEvent:(YMMUserInfo *)user
                  onFailure:(nullable void (^)(NSError *error))onFailure;

- (void)reportUserInfoEvent:(YMMUserInfo *)user
                 parameters:(nullable NSDictionary *)parameters
                  onFailure:(nullable void (^)(NSError *error))onFailure;

- (void)reportStatboxEvent:(NSString *)value
                 onFailure:(nullable void (^)(NSError *error))onFailure;

- (void)reportStatboxEventWithName:(nullable NSString *)name
                             value:(NSString *)value
                         onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting statbox report with provided parameters.
 Parameters should be valid for serialization in JSON.

 @param name event name to send
 @param parameters event parameters to send as JSON-string
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
- (void)reportStatboxEventWithName:(nullable NSString *)name
                        parameters:(NSDictionary *)parameters
                         onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting diagnostic event with additional parameters.

 @param name Short name or description of the event.
 @param parameters Dictionary of name/value pairs that must be sent to the server.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
- (void)reportDiagnosticEvent:(NSString *)name
                   parameters:(NSDictionary *)parameters
                    onFailure:(nullable void (^)(NSError *error))onFailure;

/** Reporting diagnostic statbox event with value.

 @param name Short name or description of the event.
 @param value String value of event.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
- (void)reportDiagnosticStatboxEvent:(NSString *)name
                               value:(NSString *)value
                           onFailure:(nullable void (^)(NSError *error))onFailure;

/** Setting key - value data to be used as additional information, associated with all future events.
 If value is nil previously set key-value is removed, does nothing if key hasn't been added.

 @param value The app environment value.
 @param key The app environment key.
 */
- (void)setAppEnvironmentValue:(nullable NSString *)value forKey:(NSString *)key;

/** Clearing app environment, e.g. removes all key - value data associated with all future events.
 */
- (void)clearAppEnvironment;

/** Registering crash matching rule. If classes from rule are found in a crashed thread backtrace,
 crash will be sent to this reporter API key.

 @warning THIS FUNCTIONALITY IS CURRENTLY DISABLED DUE TO CRASHES. SEE METRIKALIB-4743.

 @param rule The rule for crashes matching.
 */
- (void)registerCrashesMatchingRule:(YMMCrashMatchingRule *)rule;

/** Reporting crash event.

 @param crash Object with description of crash.
 @param onFailure Block to be executed if an error occurres while reporting, the error is passed as block argument.
 */
- (void)reportCrash:(YMMCrash *)crash
          onFailure:(nullable void (^)(NSError *error))onFailure;

/** Setting user info to metrica.
 Record user identifier.
 After the value is set, each following event refers to that user.
 If nil is set, user info will no longer be sent.
 
 @param userInfo Application user information.
 */
- (void)setUserInfo:(nullable YMMUserInfo *)userInfo;

@end

NS_ASSUME_NONNULL_END
