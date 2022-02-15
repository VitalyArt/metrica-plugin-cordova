/*
 * Version for iOS
 * © 2012–2019 YANDEX
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * https://yandex.com/legal/appmetrica_sdk_agreement/
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** Contains data which describes current application user. */
@interface YMMUserInfo : NSObject <NSCopying, NSMutableCopying>

/** Unique user identifier. User-sensitive data should not be used as user ID (e.g. passwords, emails). */
@property (nonatomic, copy, readonly) NSString *userID;

/** Optional user type. */
@property (nonatomic, copy, nullable, readonly) NSString *type;

/** One-level JSON-compatible dictionary of data associated with user. */
@property (nonatomic, copy, nullable, readonly) NSDictionary *options;

/** Returns user info for particular user ID.

 @param userID Unique user identifier.
 @return User info configured with particular user ID.
 */
- (nullable instancetype)initWithUserID:(NSString *)userID;

@end

/** Mutable version of YMMUser. */
@interface YMMMutableUserInfo : YMMUserInfo

/** Optional user type. */
@property (nonatomic, nullable, copy) NSString *type;

/** One-level JSON-compatible dictionary of data associated with user. */
@property (nonatomic, nullable, copy) NSDictionary *options;

@end

NS_ASSUME_NONNULL_END
