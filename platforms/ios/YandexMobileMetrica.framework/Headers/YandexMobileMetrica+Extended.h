/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#if __has_include("YandexMobileMetrica.h")
    #import "YandexMobileMetrica.h"
    #import "YMMYandexMetrica+Extended.h"
    #import "YMMYandexMetricaConfiguration+Extended.h"
    #import "YMMReporterConfiguration+Extended.h"
    #import "YMMUserInfo.h"
    #import "YMMReporting.h"
    #import "YMMCrash.h"
    #import "YMMCrash+Extended.h"
    #import "YMMCrashMatchingRule.h"
    #import "YMMPulseConfiguration.h"
#else
    #import <YandexMobileMetrica/YandexMobileMetrica.h>
    #import <YandexMobileMetrica/YMMYandexMetrica+Extended.h>
    #import <YandexMobileMetrica/YMMYandexMetricaConfiguration+Extended.h>
    #import <YandexMobileMetrica/YMMReporterConfiguration+Extended.h>
    #import <YandexMobileMetrica/YMMUserInfo.h>
    #import <YandexMobileMetrica/YMMReporting.h>
    #import <YandexMobileMetrica/YMMCrash.h>
    #import <YandexMobileMetrica/YMMCrash+Extended.h>
    #import <YandexMobileMetrica/YMMCrashMatchingRule.h>
    #import <YandexMobileMetrica/YMMPulseConfiguration.h>
#endif
