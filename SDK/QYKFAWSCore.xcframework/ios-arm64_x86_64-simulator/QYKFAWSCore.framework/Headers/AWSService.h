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
#import "AWSNetworking.h"
#import "AWSCredentialsProvider.h"
#import "AWSServiceEnum.h"

//! SDK version for AWS Core
FOUNDATION_EXPORT NSString *const QYKFAWSiOSSDKVersion;

FOUNDATION_EXPORT NSString *const QYKFAWSServiceErrorDomain;

typedef NS_ENUM(NSInteger, QYKFAWSServiceErrorType) {
    QYKFAWSServiceErrorUnknown,
    QYKFAWSServiceErrorRequestTimeTooSkewed,
    QYKFAWSServiceErrorInvalidSignatureException,
    QYKFAWSServiceErrorSignatureDoesNotMatch,
    QYKFAWSServiceErrorRequestExpired,
    QYKFAWSServiceErrorAuthFailure,
    QYKFAWSServiceErrorAccessDeniedException,
    QYKFAWSServiceErrorUnrecognizedClientException,
    QYKFAWSServiceErrorIncompleteSignature,
    QYKFAWSServiceErrorInvalidClientTokenId,
    QYKFAWSServiceErrorMissingAuthenticationToken,
    QYKFAWSServiceErrorAccessDenied,
    QYKFAWSServiceErrorExpiredToken,
    QYKFAWSServiceErrorInvalidAccessKeyId,
    QYKFAWSServiceErrorInvalidToken,
    QYKFAWSServiceErrorTokenRefreshRequired,
    QYKFAWSServiceErrorAccessFailure,
    QYKFAWSServiceErrorAuthMissingFailure,
    QYKFAWSServiceErrorThrottling,
    QYKFAWSServiceErrorThrottlingException,
};

@class QYKFAWSEndpoint;

#pragma mark - QYKFAWSService

/**
 An abstract representation of AWS services.
 */
@interface QYKFAWSService : NSObject

+ (NSDictionary<NSString *, NSNumber *> *)errorCodeDictionary;

@end

#pragma mark - AWSServiceManager

@class QYKFAWSServiceConfiguration;

/**
 The service manager class that manages the default service configuration.
 */
@interface QYKFAWSServiceManager : NSObject

/**
 The default service configuration object. This property can be set only once, and any subsequent setters are ignored.
 */
@property (nonatomic, copy) QYKFAWSServiceConfiguration *defaultServiceConfiguration;

/**
 Returns a default singleton object. You should use this singleton method instead of creating an instance of the service manager.

 @return The default service manager. This is a singleton object.
 */
+ (instancetype)defaultServiceManager;

@end

#pragma mark - QYKFAWSServiceConfiguration

/**
 A service configuration object.
 */
@interface QYKFAWSServiceConfiguration : QYKFAWSNetworkingConfiguration

@property (nonatomic, assign, readonly) AWSRegionType regionType;
@property (nonatomic, strong, readonly) id<QYKFAWSCredentialsProvider> credentialsProvider;
@property (nonatomic, strong, readonly) QYKFAWSEndpoint *endpoint;
@property (nonatomic, readonly) NSString *userAgent;
@property (nonatomic, readonly) BOOL localTestingEnabled;

+ (NSString *)baseUserAgent;

+ (void)addGlobalUserAgentProductToken:(NSString *)productToken;

- (instancetype)initWithRegion:(AWSRegionType)regionType
           credentialsProvider:(id<QYKFAWSCredentialsProvider>)credentialsProvider;

- (instancetype)initWithRegion:(AWSRegionType)regionType
                   serviceType:(AWSServiceType)serviceType
           credentialsProvider:(id<QYKFAWSCredentialsProvider>)credentialsProvider
           localTestingEnabled:(BOOL)localTestingEnabled;

- (instancetype)initWithRegion:(AWSRegionType)regionType
                      endpoint:(QYKFAWSEndpoint *)endpoint
           credentialsProvider:(id<QYKFAWSCredentialsProvider>)credentialsProvider;

- (instancetype)initWithRegion:(AWSRegionType)regionType
                      endpoint:(QYKFAWSEndpoint *)endpoint
           credentialsProvider:(id<QYKFAWSCredentialsProvider>)credentialsProvider
           localTestingEnabled:(BOOL)localTestingEnabled;

- (void)addUserAgentProductToken:(NSString *)productToken;

@end

#pragma mark - AWSEndpoint

@interface QYKFAWSEndpoint : NSObject

@property (nonatomic, readonly) AWSRegionType regionType;
@property (nonatomic, readonly) NSString *regionName;
@property (nonatomic, readonly) AWSServiceType serviceType;
@property (nonatomic, readonly) NSString *serviceName;
@property (nonatomic, readonly) NSString *signingName;
@property (nonatomic, readonly) NSURL *URL;
@property (nonatomic, readonly) NSString *hostName;
@property (nonatomic, readonly) BOOL useUnsafeURL;
@property (nonatomic, readonly) NSNumber *portNumber;

+ (NSString *)regionNameFromType:(AWSRegionType)regionType;

- (instancetype)initWithRegion:(AWSRegionType)regionType
                       service:(AWSServiceType)serviceType
                  useUnsafeURL:(BOOL)useUnsafeURL;

- (instancetype)initWithRegion:(AWSRegionType)regionType
                       service:(AWSServiceType)serviceType
                           URL:(NSURL *)URL;

- (instancetype)initWithRegion:(AWSRegionType)regionType
                   serviceName:(NSString *)serviceName
                           URL:(NSURL *)URL;

- (instancetype)initWithURL:(NSURL *)URL;

- (instancetype)initWithURLString:(NSString *)URLString;

- (instancetype)initLocalEndpointWithRegion:(AWSRegionType)regionType
                                    service:(AWSServiceType)serviceType
                               useUnsafeURL:(BOOL)useUnsafeURL;

@end
