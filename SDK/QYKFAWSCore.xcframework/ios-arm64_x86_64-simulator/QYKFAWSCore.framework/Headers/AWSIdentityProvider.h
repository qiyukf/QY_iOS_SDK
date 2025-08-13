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

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const QYKFAWSCognitoIdentityIdChangedNotification;
FOUNDATION_EXPORT NSString *const QYKFAWSCognitoNotificationPreviousId;
FOUNDATION_EXPORT NSString *const QYKFAWSCognitoNotificationNewId;

FOUNDATION_EXPORT NSString *const QYKFAWSIdentityProviderApple;
FOUNDATION_EXPORT NSString *const QYKFAWSIdentityProviderDigits;
FOUNDATION_EXPORT NSString *const QYKFAWSIdentityProviderFacebook;
FOUNDATION_EXPORT NSString *const QYKFAWSIdentityProviderGoogle;
FOUNDATION_EXPORT NSString *const QYKFAWSIdentityProviderLoginWithAmazon;
FOUNDATION_EXPORT NSString *const QYKFAWSIdentityProviderTwitter;

FOUNDATION_EXPORT NSString *const QYKFAWSIdentityProviderAmazonCognitoIdentity;

FOUNDATION_EXPORT NSString *const QYKFAWSCognitoCredentialsProviderHelperErrorDomain;
typedef NS_ENUM(NSInteger, QYKFAWSCognitoCredentialsProviderHelperErrorType) {
    QYKFAWSCognitoCredentialsProviderHelperErrorTypeIdentityIsNil,
    QYKFAWSCognitoCredentialsProviderHelperErrorTypeTokenRefreshTimeout,
};

@class QYKFTask<__covariant ResultType>;

/**
 QYKFAWSIdentityProvider provides an interface for acquiring an identity token from a provider.
 */
@protocol QYKFAWSIdentityProvider <NSObject>

/**
 The name of the identity provider. e.g. graph.facebook.com.
 */
@property (nonatomic, readonly) NSString *identityProviderName;

/**
 Returns the token associated with this provider. If the token is cached and invalid, should refresh and return the valid token.
 */
- (QYKFTask<NSString *> *)token;

@end

/**
 `QYKFAWSIdentityProviderManager` provides an interface for creating the `logins` dictionary for Amazon Cognito Identity.
 */
@protocol QYKFAWSIdentityProviderManager <NSObject>

/**
 Each entry in logins represents a single login with an identity provider. The key is the domain of the login provider (e.g. 'graph.facebook.com') and the value is the OAuth/OpenId Connect token that results from an authentication with that login provider.
 */
- (QYKFTask<NSDictionary<NSString *, NSString *> *> *)logins;

@optional
/**
 * If the token contains the role arn and there are multiple roles, return the custom role to assume.  This is currently only supported for SAML identity providers.
 */
@property (nonatomic, readonly) NSString *customRoleArn;

@end

/**
 QYKFAWSCognitoCredentialsProviderHelper provides a Cognito specific identity provider. Cognito Identity providers are associated with an identity pool. If the identity pool supports authenticated access, multiple logins may be added to link to the Cognito identity.
 */
@protocol QYKFAWSCognitoCredentialsProviderHelper <QYKFAWSIdentityProvider, QYKFAWSIdentityProviderManager>

/**
 The identity pool for this provider. Used to when making calls to the Amazon Cognito service
 */
@property (nonatomic, strong, readonly) NSString *identityPoolId;

/**
 The identity id as determined by the Amazon Cognito service
 */
@property (atomic, strong, nullable) NSString *identityId;

/**
 */
@property (nonatomic, strong, readonly, nullable) id<QYKFAWSIdentityProviderManager> identityProviderManager;

/**
 Get/retrieve the identity id for this provider. If an identity id is already set on this provider, no remote call is made and the identity will be returned as a result of the QYKFTask (the identityId is also available as a property). If no identityId is set on this provider, one will be retrieved from the service.
 */
- (QYKFTask<NSString *> *)getIdentityId;

/**
 Is this provider considered 'authenticated'. By default, only returns YES if logins is set.
 */
- (BOOL)isAuthenticated;

/**
 Clear saved values for identityId, token, and logins.
 */
- (void)clear;

@end

/**
 An abstract implementation of the QYKFAWSCognitoCredentialsProviderHelper.
 */
@interface QYKFAWSAbstractCognitoCredentialsProviderHelper : NSObject <QYKFAWSCognitoCredentialsProviderHelper>

/**
 The identity pool for this provider. Used to when making calls to the Amazon Cognito service
 */
@property (nonatomic, strong, readonly) NSString *identityPoolId;

/**
 The identity id as determined by the Amazon Cognito service
 */
@property (atomic, strong, nullable) NSString *identityId;

/**
 The identity provider manager that asynchronously returns `logins`.
 */
@property (nonatomic, strong, readonly, nullable) id<QYKFAWSIdentityProviderManager> identityProviderManager;

@end

@class QYKFAWSServiceConfiguration;
/**
 An abstract implementation of the QYKFAWSCognitoCredentialsProviderHelper. Developers should extend this class when they want to implement developer authenticated identities and want to support the basic Amazon Cognito authflow in the same application.
 */
@interface QYKFAWSCognitoCredentialsProviderHelper : QYKFAWSAbstractCognitoCredentialsProviderHelper

@property (nonatomic, assign) BOOL useEnhancedFlow;

- (instancetype)initWithRegionType:(AWSRegionType)regionType
                    identityPoolId:(NSString *)identityPoolId
                   useEnhancedFlow:(BOOL)useEnhancedFlow
           identityProviderManager:(nullable id<QYKFAWSIdentityProviderManager>)identityProviderManager;

- (instancetype)initWithRegionType:(AWSRegionType)regionType
                    identityPoolId:(NSString *)identityPoolId
                   useEnhancedFlow:(BOOL)useEnhancedFlow
           identityProviderManager:(nullable id<QYKFAWSIdentityProviderManager>)identityProviderManager
         identityPoolConfiguration:(QYKFAWSServiceConfiguration *)configuration;
@end

NS_ASSUME_NONNULL_END
