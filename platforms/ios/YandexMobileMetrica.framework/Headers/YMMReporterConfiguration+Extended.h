/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#if __has_include("YandexMobileMetrica.h")
    #import "YMMReporterConfiguration.h"
#else
    #import <YandexMobileMetrica/YMMReporterConfiguration.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface YMMReporterConfiguration (Extended)

/** Time interval between events dispatch (in seconds).
 */
@property (nonatomic, assign, readonly) NSUInteger dispatchPeriod;

/** Events dispatch is triggered when events count reaches maxReportsCount.
 */
@property (nonatomic, assign, readonly) NSUInteger maxReportsCount;

@end

@interface YMMMutableReporterConfiguration (Extended)

/** Time interval between events dispatch (in seconds).
 */
@property (nonatomic, assign) NSUInteger dispatchPeriod;

/** Events dispatch is triggered when events count reaches maxReportsCount.
 */
@property (nonatomic, assign) NSUInteger maxReportsCount;

@end

NS_ASSUME_NONNULL_END
