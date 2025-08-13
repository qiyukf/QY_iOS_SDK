//
// Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License").
// You may not use this file except in compliance with the License.
// A copy of the License is located at
//
// http://aws.amazon.com/apache2.0
//
// or in the "license" file accompanying this file. This file is distributed
// on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied. See the License for the specific language governing
// permissions and limitations under the License.
//

#import <Foundation/Foundation.h>
#import "AWSServiceEnum.h"

FOUNDATION_EXPORT NSString *const QYKFDateRFC822DateFormat1;
FOUNDATION_EXPORT NSString *const QYKFDateISO8601DateFormat1;
FOUNDATION_EXPORT NSString *const QYKFDateISO8601DateFormat2;
FOUNDATION_EXPORT NSString *const QYKFDateISO8601DateFormat3;
FOUNDATION_EXPORT NSString *const QYKFDateShortDateFormat1;
FOUNDATION_EXPORT NSString *const QYKFDateShortDateFormat2;

@interface NSDate (QYKF)

+ (NSDate *)QYKF_clockSkewFixedDate;

+ (NSDate *)QYKF_dateFromString:(NSString *)string;
+ (NSDate *)QYKF_dateFromString:(NSString *)string format:(NSString *)dateFormat;
- (NSString *)QYKF_stringValue:(NSString *)dateFormat;

/**
 * Set the clock skew for the current device.  This clock skew will be used for calculating
 * signatures to AWS signatures and for parsing/converting date values from responses.
 *
 * @param clockskew the skew (in seconds) for this device.  If the clock on the device is fast, pass positive skew to correct.  If the clock on the device is slow, pass negative skew to correct.
 */
+ (void)QYKF_setRuntimeClockSkew:(NSTimeInterval)clockskew;

/**
 * Get the clock skew for the current device.
 *
 * @return the skew (in seconds) currently set for this device.  Positive clock skew implies the device is fast, negative implies the device is slow.
 */
+ (NSTimeInterval)QYKF_getRuntimeClockSkew;

@end

@interface NSDictionary (QYKF)

- (NSDictionary *)QYKF_removeNullValues;
- (id)QYKF_objectForCaseInsensitiveKey:(id)aKey;

@end

@interface NSJSONSerialization (QYKF)

+ (NSData *)QYKF_dataWithJSONObject:(id)obj
                           options:(NSJSONWritingOptions)opt
                             error:(NSError **)error;

@end

@interface NSNumber (QYKF)

+ (NSNumber *)QYKF_numberFromString:(NSString *)string;

@end

@interface NSObject (QYKF)

- (NSDictionary *)QYKF_properties;
- (void)QYKF_copyPropertiesFromObject:(NSObject *)object;

@end

@interface NSString (QYKF)

/// A convenience method for calculating an MD5 hash of `data`.
///
/// MD5 is not suited for cryptographically-sensitive operations. Usages of this
/// method in the AWS Mobile SDK are limited to calculating checksums for AWS S3
/// operations that require a `Content-MD5` HTTP header, and do not repesent a
/// security risk. We are exposing this method as a convenience API for
/// applications that need to calculate that value manually.
+ (NSString *)QYKF_base64md5FromData:(NSData *)data;

- (BOOL)QYKF_isBase64Data;
- (NSString *)QYKF_stringWithURLEncoding;
- (NSString *)QYKF_stringWithURLEncodingPath;
- (NSString *)QYKF_stringWithURLEncodingPathWithoutPriorDecoding;

@end

@interface NSString (QYKFAWS)

- (BOOL)QYKFaws_isVirtualHostedStyleCompliant;

- (AWSRegionType)QYKFaws_regionTypeValue;

@end

@interface NSFileManager (QYKF)

- (BOOL)QYKF_atomicallyCopyItemAtURL:(NSURL *)sourceURL
                              toURL:(NSURL *)destinationURL
                     backupItemName:(NSString *)backupItemName
                              error:(NSError **)outError;

@end
