/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

#if __has_include("YandexMobileMetrica.h")
    #import "YMMCrash.h"
#else
    #import <YandexMobileMetrica/YMMCrash.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/**  YMMCrash contains crash description.
 */
@interface YMMCrash ()

/** Additional information, associated with event.
 */
@property (nonatomic, copy, nullable, readonly) NSDictionary *appEnvironment;

/** Initialize crash with specified raw report content, date, error and app environment.

    @param rawData Full crash report encoded with protobuf.
    @param date Date and time of crash.
    @param errorEnvironment Additional information, associated with crash.
    @param appEnvironment Additional information, associated with event.
 */
- (instancetype)initWithRawData:(nullable NSData *)rawData
                           date:(nullable NSDate *)date
               errorEnvironment:(nullable NSDictionary *)errorEnvironment
                 appEnvironment:(nullable NSDictionary *)appEnvironment;

/** Create crash object with specified raw report content, date, error and app environment.

    @param rawData Full crash report encoded with protobuf.
    @param date Date and time of crash.
    @param errorEnvironment Additional information, associated with crash.
    @param appEnvironment Additional information, associated with event.
 */
+ (instancetype)crashWithRawData:(nullable NSData *)rawData
                            date:(nullable NSDate *)date
                errorEnvironment:(nullable NSDictionary *)errorEnvironment
                  appEnvironment:(nullable NSDictionary *)appEnvironment;

/** Initialize crash with specified raw report content, date, error and app environment.

    @param rawContent Full crash report in standard Apple format.
    @param date Date and time of crash.
    @param errorEnvironment Additional information, associated with crash.
    @param appEnvironment Additional information, associated with event.
 */
- (instancetype)initWithRawContent:(nullable NSString *)rawContent
                              date:(nullable NSDate *)date
                  errorEnvironment:(nullable NSDictionary *)errorEnvironment
                    appEnvironment:(nullable NSDictionary *)appEnvironment
DEPRECATED_MSG_ATTRIBUTE("initWithRawContent:date:errorEnvironment:appEnvironment: has been deprecated. "
                         "Use initWithRawData:date:errorEnvironment:appEnvironment: instead");

/** Create crash object with specified raw report content, date, error and app environment.

    @param rawContent Full crash report in standard Apple format.
    @param date Date and time of crash.
    @param errorEnvironment Additional information, associated with crash.
    @param appEnvironment Additional information, associated with event.
 */
+ (instancetype)crashWithRawContent:(nullable NSString *)rawContent
                               date:(nullable NSDate *)date
                   errorEnvironment:(nullable NSDictionary *)errorEnvironment
                     appEnvironment:(nullable NSDictionary *)appEnvironment
DEPRECATED_MSG_ATTRIBUTE("crashWithRawContent:date:errorEnvironment:appEnvironment has been deprecated. "
                         "Use crashWithRawData:date:errorEnvironment:appEnvironment instead");

@end

NS_ASSUME_NONNULL_END
