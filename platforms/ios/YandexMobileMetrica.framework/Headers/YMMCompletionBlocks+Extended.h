/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

#if __has_include("YandexMobileMetrica.h")
    #import "YMMCompletionBlocks.h"
#else
    #import <YandexMobileMetrica/YMMCompletionBlocks.h>
#endif

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kYMMUUIDKey;
extern NSString *const kYMMDeviceIDKey;
extern NSString *const kYMMGetAdHostKey;
extern NSString *const kYMMDeviceIDHashKey;

extern NSString *const kYMMCrashReportingStateEnabledKey;
extern NSString *const kYMMCrashReportingStateCrashedLastLaunchKey;

/** Identifiers callback block

 @param identifiers Contains any combination of following identifiers on success:
     kYMMUUIDKey
     kYMMDeviceIDKey
     kYMMGetAdHostKey (requires startup request)
     kYMMDeviceIDHashKey (requires startup request)
 Empty dictionary may be returned if server by any reason did not provide any of above listed
 identifiers.

 @param error Error of NSURLErrorDomain. In a case of error identifiers param is nil.
 */
typedef void(^YMMIdentifiersCompletionBlock)(NSDictionary * _Nullable identifiers, NSError * _Nullable error);

/** Crash reporting state callback block

 @param state Contains any combination of following identifiers on success:
 kYMMCrashReportingStateEnabledKey - (NSNumber with bool) Is crash reporting enabled?
 kYMMCrashReportingStateCrashedLastLaunchKey - (NSNumber with bool) Has application crashed last launch?
 */
typedef void(^YMMCrashReportingStateCompletionBlock)(NSDictionary * _Nullable state);

NS_ASSUME_NONNULL_END
