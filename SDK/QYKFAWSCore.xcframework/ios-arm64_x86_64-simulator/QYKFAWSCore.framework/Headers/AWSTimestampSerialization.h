//
// Copyright 2010-2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const QYKFAWSTimestampSerializationErrorDomain;

typedef NS_ENUM(NSInteger, QYKFAWSTimestampSerializationError) {
    QYKFAWSTimestampParserError
};

@interface QYKFAWSTimestampSerialization: NSObject

+ (nullable NSString *)serializeTimestamp:(NSDictionary *)rules
                                    value:(NSDate *)value
                                    error:(NSError *__autoreleasing *)error;

+ (nullable NSDate *)parseTimestamp:(id)value;

@end

@interface QYKFAWSJSONTimestampSerialization: QYKFAWSTimestampSerialization
@end

@interface QYKFAWSXMLTimestampSerialization: QYKFAWSTimestampSerialization
@end

@interface QYKFAWSQueryTimestampSerialization: QYKFAWSTimestampSerialization
@end

@interface QYKFAWSEC2TimestampSerialization: QYKFAWSTimestampSerialization
@end

NS_ASSUME_NONNULL_END
