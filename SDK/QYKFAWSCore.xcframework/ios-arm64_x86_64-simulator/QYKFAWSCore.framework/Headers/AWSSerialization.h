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

// defined domain for errors from AWSRuntime.
FOUNDATION_EXPORT NSString *const QYKFAWSXMLBuilderErrorDomain;

/* NSError codes in AWSErrorDomain. */
typedef NS_ENUM(NSInteger, QYKFAWSXMLBuilderErrorType) {
    // AWSJSON Validation related errors
    QYKFAWSXMLBuilderUnknownError = 900, // Unknown Error found
    QYKFAWSXMLBuilderDefinitionFileIsEmpty = 901,
    QYKFAWSXMLBuilderUndefinedXMLNamespace = 902,
    QYKFAWSXMLBuilderUndefinedActionRule = 903,
    QYKFAWSXMLBuilderMissingRequiredXMLElements = 904,
    QYKFAWSXMLBuilderInvalidXMLValue = 905,
    QYKFAWSXMLBuilderUnCatchedRuleTypeInDifinitionFile = 906,
};

// defined domain for errors from AWSRuntime.
FOUNDATION_EXPORT NSString *const QYKFAWSXMLParserErrorDomain;

/* NSError codes in AWSErrorDomain. */
typedef NS_ENUM(NSInteger, QYKFAWSXMLParserErrorType) {
    // AWSJSON Validation related errors
    QYKFAWSXMLParserUnknownError, // Unknown Error found
    QYKFAWSXMLParserNoTypeDefinitionInRule, // Unknown Type in JSON Definition (rules) file
    QYKFAWSXMLParserUnHandledType, //Unhandled Type
    QYKFAWSXMLParserUnExpectedType, //Unexpected type
    QYKFAWSXMLParserDefinitionFileIsEmpty, //the rule is empty.
    QYKFAWSXMLParserUnexpectedXMLElement,
    QYKFAWSXMLParserXMLNameNotFoundInDefinition, //can not find the 'xmlname' key in definition file for unflattened xml list
    QYKFAWSXMLParserMissingRequiredXMLElements,
    QYKFAWSXMLParserInvalidXMLValue,
};

//defined domain for errors from AWSRuntime.
FOUNDATION_EXPORT NSString *const QYKFAWSQueryParamBuilderErrorDomain;

/* NSError codes in AWSErrorDomain. */
typedef NS_ENUM(NSInteger, QYKFAWSQueryParamBuilderErrorType) {
    QYKFAWSQueryParamBuilderUnknownError,
    QYKFAWSQueryParamBuilderDefinitionFileIsEmpty,
    QYKFAWSQueryParamBuilderUndefinedActionRule,
    QYKFAWSQueryParamBuilderInternalError,
    QYKFAWSQueryParamBuilderInvalidParameter,
};

//defined domain for errors from AWSRuntime.
FOUNDATION_EXPORT NSString *const QYKFAWSEC2ParamBuilderErrorDomain;

/* NSError codes in AWSErrorDomain. */
typedef NS_ENUM(NSInteger, QYKFAWSEC2ParamBuilderErrorType) {
    QYKFAWSEC2ParamBuilderUnknownError,
    QYKFAWSEC2ParamBuilderDefinitionFileIsEmpty,
    QYKFAWSEC2ParamBuilderUndefinedActionRule,
    QYKFAWSEC2ParamBuilderInternalError,
    QYKFAWSEC2ParamBuilderInvalidParameter,
};

//defined domain for errors from AWSRuntime.
FOUNDATION_EXPORT NSString *const QYKFAWSJSONBuilderErrorDomain;

/* NSError codes in AWSErrorDomain. */
typedef NS_ENUM(NSInteger, QYKFAWSJSONBuilderErrorType) {
    QYKFAWSJSONBuilderUnknownError,
    QYKFAWSJSONBuilderDefinitionFileIsEmpty,
    QYKFAWSJSONBuilderUndefinedActionRule,
    QYKFAWSJSONBuilderInternalError,
    QYKFAWSJSONBuilderInvalidParameter,
};

//defined domain for errors from AWSRuntime.
FOUNDATION_EXPORT NSString *const QYKFAWSJSONParserErrorDomain;

/* NSError codes in AWSErrorDomain. */
typedef NS_ENUM(NSInteger, QYKFAWSJSONParserErrorType) {
    QYKFAWSJSONParserUnknownError,
    QYKFAWSJSONParserDefinitionFileIsEmpty,
    QYKFAWSJSONParserUndefinedActionRule,
    QYKFAWSJSONParserInternalError,
    QYKFAWSJSONParserInvalidParameter,

};

@interface QYKFAWSJSONDictionary : NSDictionary

- (instancetype)initWithDictionary:(NSDictionary *)otherDictionary
                JSONDefinitionRule:(NSDictionary *)rule;
- (NSUInteger)count;
- (id)objectForKey:(id)aKey;

@end

@interface QYKFAWSXMLBuilder : NSObject

+ (NSData *)xmlDataForDictionary:(NSDictionary *)params
                      actionName:(NSString *)actionName
           serviceDefinitionRule:(NSDictionary *)serviceDefinitionRule
                           error:(NSError *__autoreleasing *)error;

+ (NSString *)xmlStringForDictionary:(NSDictionary *)params
                          actionName:(NSString *)actionName
               serviceDefinitionRule:(NSDictionary *)serviceDefinitionRule
                               error:(NSError *__autoreleasing *)error;

@end

@interface QYKFAWSXMLParser : NSObject

+ (QYKFAWSXMLParser *)sharedInstance;

- (NSMutableDictionary *)dictionaryForXMLData:(NSData *)data
                                   actionName:(NSString *)actionName
                        serviceDefinitionRule:(NSDictionary *)serviceDefinitionRule
                                        error:(NSError *__autoreleasing *)error;

@end

@interface QYKFAWSQueryParamBuilder : NSObject

+ (NSDictionary *)buildFormattedParams:(NSDictionary *)params
                            actionName:(NSString *)actionName
                 serviceDefinitionRule:(NSDictionary *)serviceDefinitionRule
                                 error:(NSError *__autoreleasing *)error;

@end

@interface QYKFAWSEC2ParamBuilder : NSObject

+ (NSDictionary *)buildFormattedParams:(NSDictionary *)params
                            actionName:(NSString *)actionName
                 serviceDefinitionRule:(NSDictionary *)serviceDefinitionRule
                                 error:(NSError *__autoreleasing *)error;

@end

@interface QYKFAWSJSONBuilder : NSObject

+ (NSData *)jsonDataForDictionary:(NSDictionary *)params
                       actionName:(NSString *)actionName
            serviceDefinitionRule:(NSDictionary *)serviceDefinitionRule
                            error:(NSError *__autoreleasing *)error;

@end

@interface QYKFAWSJSONParser : NSObject

+ (NSDictionary *)dictionaryForJsonData:(NSData *)data
                               response:(NSHTTPURLResponse *)response
                             actionName:(NSString *)actionName
                  serviceDefinitionRule:(NSDictionary *)serviceDefinitionRule
                                  error:(NSError *__autoreleasing *)error;

@end




