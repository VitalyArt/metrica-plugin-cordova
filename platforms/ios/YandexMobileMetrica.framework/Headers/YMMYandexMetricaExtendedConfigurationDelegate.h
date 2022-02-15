/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

@class UIViewController;

@protocol YMMYandexMetricaExtendedConfigurationDelegate <NSObject>

@optional

/** Returns UIViewController to insert hidden view controller into.
 This is needed to increase quality of attribution and statistics.
 If this method is not implemented SDK uses root view controller of application.
 If this method returns nil SDK will make several more tries with few-seconds-delay.
 */
- (UIViewController *)yandexMetricaRootViewController;

@end
