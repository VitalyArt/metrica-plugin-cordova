/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, YMMPulseChannel) {
    YMMPulseChannelUnknown,
    YMMPulseChannelCanary,
    YMMPulseChannelDev,
    YMMPulseChannelBeta,
    YMMPulseChannelStable,
};

NS_ASSUME_NONNULL_BEGIN

@interface YMMPulseConfiguration : NSObject <NSCopying, NSMutableCopying>

/** Common prefix for histograms.

 The value you have set during registration in Pulse service.
 This value must not be empty, otherwise Pulse will not be activated.
 */
@property (nonatomic, copy, readonly) NSString *histogramPrefix;

/** Channel of the release.
 */
@property (nonatomic, assign, readonly) YMMPulseChannel channel;

/** Additional variations of the release.
 */
@property (nonatomic, copy, nullable, readonly) NSDictionary<NSString *, NSString *> *variations;

- (instancetype)init NS_UNAVAILABLE;

/** Creates an instance of Pulse configuration.

 Unknown channel and no variations will be used.
 @param histogramPrefix Common prefix for histograms. Should not be empty, otherwise Pulse will not be activated.
 @return An instance of Pulse configuration.
 */
- (instancetype)initWithHistogramPrefix:(NSString *)histogramPrefix;

/** Creates an instance of Pulse configuration.
 *
 * @param histogramPrefix Common prefix for histograms. Should not be empty, otherwise Pulse will not be activated.
 * @param channel Channel of the release.
 * @param variations Additional variations of the release.
 * @return An instance of Pulse configuration.
 */
- (instancetype)initWithHistogramPrefix:(NSString *)histogramPrefix
                                channel:(YMMPulseChannel)channel
                             variations:(nullable NSDictionary<NSString *, NSString *> *)variations NS_DESIGNATED_INITIALIZER;

@end

@interface YMMMutablePulseConfiguration : YMMPulseConfiguration

/** Channel of the release.
 */
@property (nonatomic, assign) YMMPulseChannel channel;

/** Additional variations of the release.
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *variations;

@end

NS_ASSUME_NONNULL_END
