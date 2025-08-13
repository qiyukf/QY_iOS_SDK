//
// Copyright 2010-2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#import "AWSModel.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const QYKFAWSCognitoIdentityErrorDomain;

typedef NS_ENUM(NSInteger, QYKFAWSCognitoIdentityErrorType) {
    QYKFAWSCognitoIdentityErrorUnknown,
    QYKFAWSCognitoIdentityErrorConcurrentModification,
    QYKFAWSCognitoIdentityErrorDeveloperUserAlreadyRegistered,
    QYKFAWSCognitoIdentityErrorExternalService,
    QYKFAWSCognitoIdentityErrorInternalError,
    QYKFAWSCognitoIdentityErrorInvalidIdentityPoolConfiguration,
    QYKFAWSCognitoIdentityErrorInvalidParameter,
    QYKFAWSCognitoIdentityErrorLimitExceeded,
    QYKFAWSCognitoIdentityErrorNotAuthorized,
    QYKFAWSCognitoIdentityErrorResourceConflict,
    QYKFAWSCognitoIdentityErrorResourceNotFound,
    QYKFAWSCognitoIdentityErrorTooManyRequests,
};

typedef NS_ENUM(NSInteger, QYKFAWSCognitoIdentityAmbiguousRoleResolutionType) {
    QYKFAWSCognitoIdentityAmbiguousRoleResolutionTypeUnknown,
    QYKFAWSCognitoIdentityAmbiguousRoleResolutionTypeAuthenticatedRole,
    QYKFAWSCognitoIdentityAmbiguousRoleResolutionTypeDeny,
};

typedef NS_ENUM(NSInteger, QYKFAWSCognitoIdentityErrorCode) {
    QYKFAWSCognitoIdentityErrorCodeUnknown,
    QYKFAWSCognitoIdentityErrorCodeAccessDenied,
    QYKFAWSCognitoIdentityErrorCodeInternalServerError,
};

typedef NS_ENUM(NSInteger, QYKFAWSCognitoIdentityMappingRuleMatchType) {
    QYKFAWSCognitoIdentityMappingRuleMatchTypeUnknown,
    QYKFAWSCognitoIdentityMappingRuleMatchTypeEquals,
    QYKFAWSCognitoIdentityMappingRuleMatchTypeContains,
    QYKFAWSCognitoIdentityMappingRuleMatchTypeStartsWith,
    QYKFAWSCognitoIdentityMappingRuleMatchTypeNotEqual,
};

typedef NS_ENUM(NSInteger, QYKFAWSCognitoIdentityRoleMappingType) {
    QYKFAWSCognitoIdentityRoleMappingTypeUnknown,
    QYKFAWSCognitoIdentityRoleMappingTypeToken,
    QYKFAWSCognitoIdentityRoleMappingTypeRules,
};

@class QYKFAWSCognitoIdentityCognitoIdentityProvider;
@class QYKFAWSCognitoIdentityCreateIdentityPoolInput;
@class QYKFAWSCognitoIdentityCredentials;
@class QYKFAWSCognitoIdentityDeleteIdentitiesInput;
@class QYKFAWSCognitoIdentityDeleteIdentitiesResponse;
@class QYKFAWSCognitoIdentityDeleteIdentityPoolInput;
@class QYKFAWSCognitoIdentityDescribeIdentityInput;
@class QYKFAWSCognitoIdentityDescribeIdentityPoolInput;
@class QYKFAWSCognitoIdentityGetCredentialsForIdentityInput;
@class QYKFAWSCognitoIdentityGetCredentialsForIdentityResponse;
@class QYKFAWSCognitoIdentityGetIdInput;
@class QYKFAWSCognitoIdentityGetIdResponse;
@class QYKFAWSCognitoIdentityGetIdentityPoolRolesInput;
@class QYKFAWSCognitoIdentityGetIdentityPoolRolesResponse;
@class QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityInput;
@class QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityResponse;
@class QYKFAWSCognitoIdentityGetOpenIdTokenInput;
@class QYKFAWSCognitoIdentityGetOpenIdTokenResponse;
@class QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapInput;
@class QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapResponse;
@class QYKFAWSCognitoIdentityIdentityDescription;
@class QYKFAWSCognitoIdentityIdentityPool;
@class QYKFAWSCognitoIdentityIdentityPoolShortDescription;
@class QYKFAWSCognitoIdentityListIdentitiesInput;
@class QYKFAWSCognitoIdentityListIdentitiesResponse;
@class QYKFAWSCognitoIdentityListIdentityPoolsInput;
@class QYKFAWSCognitoIdentityListIdentityPoolsResponse;
@class QYKFAWSCognitoIdentityListTagsForResourceInput;
@class QYKFAWSCognitoIdentityListTagsForResourceResponse;
@class QYKFAWSCognitoIdentityLookupDeveloperIdentityInput;
@class QYKFAWSCognitoIdentityLookupDeveloperIdentityResponse;
@class QYKFAWSCognitoIdentityMappingRule;
@class QYKFAWSCognitoIdentityMergeDeveloperIdentitiesInput;
@class QYKFAWSCognitoIdentityMergeDeveloperIdentitiesResponse;
@class QYKFAWSCognitoIdentityRoleMapping;
@class QYKFAWSCognitoIdentityRulesConfigurationType;
@class QYKFAWSCognitoIdentitySetIdentityPoolRolesInput;
@class QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapInput;
@class QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapResponse;
@class QYKFAWSCognitoIdentityTagResourceInput;
@class QYKFAWSCognitoIdentityTagResourceResponse;
@class QYKFAWSCognitoIdentityUnlinkDeveloperIdentityInput;
@class QYKFAWSCognitoIdentityUnlinkIdentityInput;
@class QYKFAWSCognitoIdentityUnprocessedIdentityId;
@class QYKFAWSCognitoIdentityUntagResourceInput;
@class QYKFAWSCognitoIdentityUntagResourceResponse;

/**
 <p>A provider representing an Amazon Cognito user pool and its client ID.</p>
 */
@interface QYKFAWSCognitoIdentityCognitoIdentityProvider : QYKFAWSModel


/**
 <p>The client ID for the Amazon Cognito user pool.</p>
 */
@property (nonatomic, strong) NSString * _Nullable clientId;

/**
 <p>The provider name for an Amazon Cognito user pool. For example, <code>cognito-idp.us-east-1.amazonaws.com/us-east-1_123456789</code>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable providerName;

/**
 <p>TRUE if server-side token validation is enabled for the identity provider’s token.</p><p>Once you set <code>ServerSideTokenCheck</code> to TRUE for an identity pool, that identity pool will check with the integrated user pools to make sure that the user has not been globally signed out or deleted before the identity pool provides an OIDC token or AWS credentials for the user.</p><p>If the user is signed out or deleted, the identity pool will return a 400 Not Authorized error.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable serverSideTokenCheck;

@end

/**
 <p>Input to the CreateIdentityPool action.</p>
 Required parameters: [IdentityPoolName, AllowUnauthenticatedIdentities]
 */
@interface QYKFAWSCognitoIdentityCreateIdentityPoolInput : QYKFAWSRequest


/**
 <p>Enables or disables the Basic (Classic) authentication flow. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/authentication-flow.html">Identity Pools (Federated Identities) Authentication Flow</a> in the <i>Amazon Cognito Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable allowClassicFlow;

/**
 <p>TRUE if the identity pool supports unauthenticated logins.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable allowUnauthenticatedIdentities;

/**
 <p>An array of Amazon Cognito user pools and their client IDs.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSCognitoIdentityCognitoIdentityProvider *> * _Nullable cognitoIdentityProviders;

/**
 <p>The "domain" by which Cognito will refer to your users. This name acts as a placeholder that allows your backend and the Cognito service to communicate about the developer provider. For the <code>DeveloperProviderName</code>, you can use letters as well as period (<code>.</code>), underscore (<code>_</code>), and dash (<code>-</code>).</p><p>Once you have set a developer provider name, you cannot change it. Please take care in setting this parameter.</p>
 */
@property (nonatomic, strong) NSString * _Nullable developerProviderName;

/**
 <p>A string that you provide.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolName;

/**
 <p>Tags to assign to the identity pool. A tag is a label that you can apply to identity pools to categorize and manage them in different ways, such as by purpose, owner, environment, or other criteria.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable identityPoolTags;

/**
 <p>The Amazon Resource Names (ARN) of the OpenID Connect providers.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable openIdConnectProviderARNs;

/**
 <p>An array of Amazon Resource Names (ARNs) of the SAML provider for your identity pool.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable samlProviderARNs;

/**
 <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable supportedLoginProviders;

@end

/**
 <p>Credentials for the provided identity ID.</p>
 */
@interface QYKFAWSCognitoIdentityCredentials : QYKFAWSModel


/**
 <p>The Access Key portion of the credentials.</p>
 */
@property (nonatomic, strong) NSString * _Nullable accessKeyId;

/**
 <p>The date at which these credentials will expire.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable expiration;

/**
 <p>The Secret Access Key portion of the credentials</p>
 */
@property (nonatomic, strong) NSString * _Nullable secretKey;

/**
 <p>The Session Token portion of the credentials</p>
 */
@property (nonatomic, strong) NSString * _Nullable sessionToken;

@end

/**
 <p>Input to the <code>DeleteIdentities</code> action.</p>
 Required parameters: [IdentityIdsToDelete]
 */
@interface QYKFAWSCognitoIdentityDeleteIdentitiesInput : QYKFAWSRequest


/**
 <p>A list of 1-60 identities that you want to delete.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable identityIdsToDelete;

@end

/**
 <p>Returned in response to a successful <code>DeleteIdentities</code> operation.</p>
 */
@interface QYKFAWSCognitoIdentityDeleteIdentitiesResponse : QYKFAWSModel


/**
 <p>An array of UnprocessedIdentityId objects, each of which contains an ErrorCode and IdentityId.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSCognitoIdentityUnprocessedIdentityId *> * _Nullable unprocessedIdentityIds;

@end

/**
 <p>Input to the DeleteIdentityPool action.</p>
 Required parameters: [IdentityPoolId]
 */
@interface QYKFAWSCognitoIdentityDeleteIdentityPoolInput : QYKFAWSRequest


/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

@end

/**
 <p>Input to the <code>DescribeIdentity</code> action.</p>
 Required parameters: [IdentityId]
 */
@interface QYKFAWSCognitoIdentityDescribeIdentityInput : QYKFAWSRequest


/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

@end

/**
 <p>Input to the DescribeIdentityPool action.</p>
 Required parameters: [IdentityPoolId]
 */
@interface QYKFAWSCognitoIdentityDescribeIdentityPoolInput : QYKFAWSRequest


/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

@end

/**
 <p>Input to the <code>GetCredentialsForIdentity</code> action.</p>
 Required parameters: [IdentityId]
 */
@interface QYKFAWSCognitoIdentityGetCredentialsForIdentityInput : QYKFAWSRequest


/**
 <p>The Amazon Resource Name (ARN) of the role to be assumed when multiple roles were received in the token from the identity provider. For example, a SAML-based identity provider. This parameter is optional for identity providers that do not support role customization.</p>
 */
@property (nonatomic, strong) NSString * _Nullable customRoleArn;

/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>A set of optional name-value pairs that map provider names to provider tokens. The name-value pair will follow the syntax "provider_name": "provider_user_identifier".</p><p>Logins should not be specified when trying to get credentials for an unauthenticated identity.</p><p>The Logins parameter is required when using identities associated with external identity providers such as Facebook. For examples of <code>Logins</code> maps, see the code examples in the <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/external-identity-providers.html">External Identity Providers</a> section of the Amazon Cognito Developer Guide.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable logins;

@end

/**
 <p>Returned in response to a successful <code>GetCredentialsForIdentity</code> operation.</p>
 */
@interface QYKFAWSCognitoIdentityGetCredentialsForIdentityResponse : QYKFAWSModel


/**
 <p>Credentials for the provided identity ID.</p>
 */
@property (nonatomic, strong) QYKFAWSCognitoIdentityCredentials * _Nullable credentials;

/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

@end

/**
 <p>Input to the GetId action.</p>
 Required parameters: [IdentityPoolId]
 */
@interface QYKFAWSCognitoIdentityGetIdInput : QYKFAWSRequest


/**
 <p>A standard AWS account ID (9+ digits).</p>
 */
@property (nonatomic, strong) NSString * _Nullable accountId;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>A set of optional name-value pairs that map provider names to provider tokens. The available provider names for <code>Logins</code> are as follows:</p><ul><li><p>Facebook: <code>graph.facebook.com</code></p></li><li><p>Amazon Cognito user pool: <code>cognito-idp.&lt;region&gt;.amazonaws.com/&lt;YOUR_USER_POOL_ID&gt;</code>, for example, <code>cognito-idp.us-east-1.amazonaws.com/us-east-1_123456789</code>. </p></li><li><p>Google: <code>accounts.google.com</code></p></li><li><p>Amazon: <code>www.amazon.com</code></p></li><li><p>Twitter: <code>api.twitter.com</code></p></li><li><p>Digits: <code>www.digits.com</code></p></li></ul>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable logins;

@end

/**
 <p>Returned in response to a GetId request.</p>
 */
@interface QYKFAWSCognitoIdentityGetIdResponse : QYKFAWSModel


/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

@end

/**
 <p>Input to the <code>GetIdentityPoolRoles</code> action.</p>
 Required parameters: [IdentityPoolId]
 */
@interface QYKFAWSCognitoIdentityGetIdentityPoolRolesInput : QYKFAWSRequest


/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

@end

/**
 <p>Returned in response to a successful <code>GetIdentityPoolRoles</code> operation.</p>
 */
@interface QYKFAWSCognitoIdentityGetIdentityPoolRolesResponse : QYKFAWSModel


/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>How users for a specific identity provider are to mapped to roles. This is a String-to-<a>RoleMapping</a> object map. The string identifies the identity provider, for example, "graph.facebook.com" or "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, QYKFAWSCognitoIdentityRoleMapping *> * _Nullable roleMappings;

/**
 <p>The map of roles associated with this pool. Currently only authenticated and unauthenticated roles are supported.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable roles;

@end

/**
 <p>Input to the <code>GetOpenIdTokenForDeveloperIdentity</code> action.</p>
 Required parameters: [IdentityPoolId, Logins]
 */
@interface QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityInput : QYKFAWSRequest


/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>A set of optional name-value pairs that map provider names to provider tokens. Each name-value pair represents a user from a public provider or developer provider. If the user is from a developer provider, the name-value pair will follow the syntax <code>"developer_provider_name": "developer_user_identifier"</code>. The developer provider is the "domain" by which Cognito will refer to your users; you provided this domain while creating/updating the identity pool. The developer user identifier is an identifier from your backend that uniquely identifies a user. When you create an identity pool, you can specify the supported logins.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable logins;

/**
 <p>Use this operation to configure attribute mappings for custom providers. </p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable principalTags;

/**
 <p>The expiration time of the token, in seconds. You can specify a custom expiration time for the token so that you can cache it. If you don't provide an expiration time, the token is valid for 15 minutes. You can exchange the token with Amazon STS for temporary AWS credentials, which are valid for a maximum of one hour. The maximum token duration you can set is 24 hours. You should take care in setting the expiration time for a token, as there are significant security implications: an attacker could use a leaked token to access your AWS resources for the token's duration.</p><note><p>Please provide for a small grace period, usually no more than 5 minutes, to account for clock skew.</p></note>
 */
@property (nonatomic, strong) NSNumber * _Nullable tokenDuration;

@end

/**
 <p>Returned in response to a successful <code>GetOpenIdTokenForDeveloperIdentity</code> request.</p>
 */
@interface QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityResponse : QYKFAWSModel


/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>An OpenID token.</p>
 */
@property (nonatomic, strong) NSString * _Nullable token;

@end

/**
 <p>Input to the GetOpenIdToken action.</p>
 Required parameters: [IdentityId]
 */
@interface QYKFAWSCognitoIdentityGetOpenIdTokenInput : QYKFAWSRequest


/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>A set of optional name-value pairs that map provider names to provider tokens. When using graph.facebook.com and www.amazon.com, supply the access_token returned from the provider's authflow. For accounts.google.com, an Amazon Cognito user pool provider, or any other OpenID Connect provider, always include the <code>id_token</code>.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable logins;

@end

/**
 <p>Returned in response to a successful GetOpenIdToken request.</p>
 */
@interface QYKFAWSCognitoIdentityGetOpenIdTokenResponse : QYKFAWSModel


/**
 <p>A unique identifier in the format REGION:GUID. Note that the IdentityId returned may not match the one passed on input.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>An OpenID token, valid for 10 minutes.</p>
 */
@property (nonatomic, strong) NSString * _Nullable token;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapInput : QYKFAWSRequest


/**
 <p>You can use this operation to get the ID of the Identity Pool you setup attribute mappings for.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>You can use this operation to get the provider name.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityProviderName;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapResponse : QYKFAWSModel


/**
 <p>You can use this operation to get the ID of the Identity Pool you setup attribute mappings for.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>You can use this operation to get the provider name.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityProviderName;

/**
 <p>You can use this operation to add principal tags. The <code>PrincipalTags</code>operation enables you to reference user attributes in your IAM permissions policy.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable principalTags;

/**
 <p>You can use this operation to list </p>
 */
@property (nonatomic, strong) NSNumber * _Nullable useDefaults;

@end

/**
 <p>A description of the identity.</p>
 */
@interface QYKFAWSCognitoIdentityIdentityDescription : QYKFAWSModel


/**
 <p>Date on which the identity was created.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable creationDate;

/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>Date on which the identity was last modified.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable lastModifiedDate;

/**
 <p>The provider names.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable logins;

@end

/**
 <p>An object representing an Amazon Cognito identity pool.</p>
 Required parameters: [IdentityPoolId, IdentityPoolName, AllowUnauthenticatedIdentities]
 */
@interface QYKFAWSCognitoIdentityIdentityPool : QYKFAWSRequest


/**
 <p>Enables or disables the Basic (Classic) authentication flow. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/authentication-flow.html">Identity Pools (Federated Identities) Authentication Flow</a> in the <i>Amazon Cognito Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable allowClassicFlow;

/**
 <p>TRUE if the identity pool supports unauthenticated logins.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable allowUnauthenticatedIdentities;

/**
 <p>A list representing an Amazon Cognito user pool and its client ID.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSCognitoIdentityCognitoIdentityProvider *> * _Nullable cognitoIdentityProviders;

/**
 <p>The "domain" by which Cognito will refer to your users.</p>
 */
@property (nonatomic, strong) NSString * _Nullable developerProviderName;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>A string that you provide.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolName;

/**
 <p>The tags that are assigned to the identity pool. A tag is a label that you can apply to identity pools to categorize and manage them in different ways, such as by purpose, owner, environment, or other criteria.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable identityPoolTags;

/**
 <p>The ARNs of the OpenID Connect providers.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable openIdConnectProviderARNs;

/**
 <p>An array of Amazon Resource Names (ARNs) of the SAML provider for your identity pool.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable samlProviderARNs;

/**
 <p>Optional key:value pairs mapping provider names to provider app IDs.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable supportedLoginProviders;

@end

/**
 <p>A description of the identity pool.</p>
 */
@interface QYKFAWSCognitoIdentityIdentityPoolShortDescription : QYKFAWSModel


/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>A string that you provide.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolName;

@end

/**
 <p>Input to the ListIdentities action.</p>
 Required parameters: [IdentityPoolId, MaxResults]
 */
@interface QYKFAWSCognitoIdentityListIdentitiesInput : QYKFAWSRequest


/**
 <p>An optional boolean parameter that allows you to hide disabled identities. If omitted, the ListIdentities API will include disabled identities in the response.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable hideDisabled;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>The maximum number of identities to return.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable maxResults;

/**
 <p>A pagination token.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextToken;

@end

/**
 <p>The response to a ListIdentities request.</p>
 */
@interface QYKFAWSCognitoIdentityListIdentitiesResponse : QYKFAWSModel


/**
 <p>An object containing a set of identities and associated mappings.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSCognitoIdentityIdentityDescription *> * _Nullable identities;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>A pagination token.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextToken;

@end

/**
 <p>Input to the ListIdentityPools action.</p>
 Required parameters: [MaxResults]
 */
@interface QYKFAWSCognitoIdentityListIdentityPoolsInput : QYKFAWSRequest


/**
 <p>The maximum number of identities to return.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable maxResults;

/**
 <p>A pagination token.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextToken;

@end

/**
 <p>The result of a successful ListIdentityPools action.</p>
 */
@interface QYKFAWSCognitoIdentityListIdentityPoolsResponse : QYKFAWSModel


/**
 <p>The identity pools returned by the ListIdentityPools action.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSCognitoIdentityIdentityPoolShortDescription *> * _Nullable identityPools;

/**
 <p>A pagination token.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextToken;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityListTagsForResourceInput : QYKFAWSRequest


/**
 <p>The Amazon Resource Name (ARN) of the identity pool that the tags are assigned to.</p>
 */
@property (nonatomic, strong) NSString * _Nullable resourceArn;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityListTagsForResourceResponse : QYKFAWSModel


/**
 <p>The tags that are assigned to the identity pool.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable tags;

@end

/**
 <p>Input to the <code>LookupDeveloperIdentityInput</code> action.</p>
 Required parameters: [IdentityPoolId]
 */
@interface QYKFAWSCognitoIdentityLookupDeveloperIdentityInput : QYKFAWSRequest


/**
 <p>A unique ID used by your backend authentication process to identify a user. Typically, a developer identity provider would issue many developer user identifiers, in keeping with the number of users.</p>
 */
@property (nonatomic, strong) NSString * _Nullable developerUserIdentifier;

/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>The maximum number of identities to return.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable maxResults;

/**
 <p>A pagination token. The first call you make will have <code>NextToken</code> set to null. After that the service will return <code>NextToken</code> values as needed. For example, let's say you make a request with <code>MaxResults</code> set to 10, and there are 20 matches in the database. The service will return a pagination token as a part of the response. This token can be used to call the API again and get results starting from the 11th match.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextToken;

@end

/**
 <p>Returned in response to a successful <code>LookupDeveloperIdentity</code> action.</p>
 */
@interface QYKFAWSCognitoIdentityLookupDeveloperIdentityResponse : QYKFAWSModel


/**
 <p>This is the list of developer user identifiers associated with an identity ID. Cognito supports the association of multiple developer user identifiers with an identity ID.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable developerUserIdentifierList;

/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>A pagination token. The first call you make will have <code>NextToken</code> set to null. After that the service will return <code>NextToken</code> values as needed. For example, let's say you make a request with <code>MaxResults</code> set to 10, and there are 20 matches in the database. The service will return a pagination token as a part of the response. This token can be used to call the API again and get results starting from the 11th match.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextToken;

@end

/**
 <p>A rule that maps a claim name, a claim value, and a match type to a role ARN.</p>
 Required parameters: [Claim, MatchType, Value, RoleARN]
 */
@interface QYKFAWSCognitoIdentityMappingRule : QYKFAWSModel


/**
 <p>The claim name that must be present in the token, for example, "isAdmin" or "paid".</p>
 */
@property (nonatomic, strong) NSString * _Nullable claim;

/**
 <p>The match condition that specifies how closely the claim value in the IdP token must match <code>Value</code>.</p>
 */
@property (nonatomic, assign) QYKFAWSCognitoIdentityMappingRuleMatchType matchType;

/**
 <p>The role ARN.</p>
 */
@property (nonatomic, strong) NSString * _Nullable roleARN;

/**
 <p>A brief string that the claim must match, for example, "paid" or "yes".</p>
 */
@property (nonatomic, strong) NSString * _Nullable value;

@end

/**
 <p>Input to the <code>MergeDeveloperIdentities</code> action.</p>
 Required parameters: [SourceUserIdentifier, DestinationUserIdentifier, DeveloperProviderName, IdentityPoolId]
 */
@interface QYKFAWSCognitoIdentityMergeDeveloperIdentitiesInput : QYKFAWSRequest


/**
 <p>User identifier for the destination user. The value should be a <code>DeveloperUserIdentifier</code>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable destinationUserIdentifier;

/**
 <p>The "domain" by which Cognito will refer to your users. This is a (pseudo) domain name that you provide while creating an identity pool. This name acts as a placeholder that allows your backend and the Cognito service to communicate about the developer provider. For the <code>DeveloperProviderName</code>, you can use letters as well as period (.), underscore (_), and dash (-).</p>
 */
@property (nonatomic, strong) NSString * _Nullable developerProviderName;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>User identifier for the source user. The value should be a <code>DeveloperUserIdentifier</code>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable sourceUserIdentifier;

@end

/**
 <p>Returned in response to a successful <code>MergeDeveloperIdentities</code> action.</p>
 */
@interface QYKFAWSCognitoIdentityMergeDeveloperIdentitiesResponse : QYKFAWSModel


/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

@end

/**
 <p>A role mapping.</p>
 Required parameters: [Type]
 */
@interface QYKFAWSCognitoIdentityRoleMapping : QYKFAWSModel


/**
 <p>If you specify Token or Rules as the <code>Type</code>, <code>AmbiguousRoleResolution</code> is required.</p><p>Specifies the action to be taken if either no rules match the claim value for the <code>Rules</code> type, or there is no <code>cognito:preferred_role</code> claim and there are multiple <code>cognito:roles</code> matches for the <code>Token</code> type.</p>
 */
@property (nonatomic, assign) QYKFAWSCognitoIdentityAmbiguousRoleResolutionType ambiguousRoleResolution;

/**
 <p>The rules to be used for mapping users to roles.</p><p>If you specify Rules as the role mapping type, <code>RulesConfiguration</code> is required.</p>
 */
@property (nonatomic, strong) QYKFAWSCognitoIdentityRulesConfigurationType * _Nullable rulesConfiguration;

/**
 <p>The role mapping type. Token will use <code>cognito:roles</code> and <code>cognito:preferred_role</code> claims from the Cognito identity provider token to map groups to roles. Rules will attempt to match claims from the token to map to a role.</p>
 */
@property (nonatomic, assign) QYKFAWSCognitoIdentityRoleMappingType types;

@end

/**
 <p>A container for rules.</p>
 Required parameters: [Rules]
 */
@interface QYKFAWSCognitoIdentityRulesConfigurationType : QYKFAWSModel


/**
 <p>An array of rules. You can specify up to 25 rules per identity provider.</p><p>Rules are evaluated in order. The first one to match specifies the role.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSCognitoIdentityMappingRule *> * _Nullable rules;

@end

/**
 <p>Input to the <code>SetIdentityPoolRoles</code> action.</p>
 Required parameters: [IdentityPoolId, Roles]
 */
@interface QYKFAWSCognitoIdentitySetIdentityPoolRolesInput : QYKFAWSRequest


/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>How users for a specific identity provider are to mapped to roles. This is a string to <a>RoleMapping</a> object map. The string identifies the identity provider, for example, "graph.facebook.com" or "cognito-idp.us-east-1.amazonaws.com/us-east-1_abcdefghi:app_client_id".</p><p>Up to 25 rules can be specified per identity provider.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, QYKFAWSCognitoIdentityRoleMapping *> * _Nullable roleMappings;

/**
 <p>The map of roles associated with this pool. For a given role, the key will be either "authenticated" or "unauthenticated" and the value will be the Role ARN.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable roles;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapInput : QYKFAWSRequest


/**
 <p>The ID of the Identity Pool you want to set attribute mappings for.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>The provider name you want to use for attribute mappings.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityProviderName;

/**
 <p>You can use this operation to add principal tags.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable principalTags;

/**
 <p>You can use this operation to use default (username and clientID) attribute mappings.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable useDefaults;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapResponse : QYKFAWSModel


/**
 <p>The ID of the Identity Pool you want to set attribute mappings for.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

/**
 <p>The provider name you want to use for attribute mappings.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityProviderName;

/**
 <p>You can use this operation to add principal tags. The <code>PrincipalTags</code>operation enables you to reference user attributes in your IAM permissions policy.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable principalTags;

/**
 <p>You can use this operation to select default (username and clientID) attribute mappings.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable useDefaults;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityTagResourceInput : QYKFAWSRequest


/**
 <p>The Amazon Resource Name (ARN) of the identity pool.</p>
 */
@property (nonatomic, strong) NSString * _Nullable resourceArn;

/**
 <p>The tags to assign to the identity pool.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable tags;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityTagResourceResponse : QYKFAWSModel


@end

/**
 <p>Input to the <code>UnlinkDeveloperIdentity</code> action.</p>
 Required parameters: [IdentityId, IdentityPoolId, DeveloperProviderName, DeveloperUserIdentifier]
 */
@interface QYKFAWSCognitoIdentityUnlinkDeveloperIdentityInput : QYKFAWSRequest


/**
 <p>The "domain" by which Cognito will refer to your users.</p>
 */
@property (nonatomic, strong) NSString * _Nullable developerProviderName;

/**
 <p>A unique ID used by your backend authentication process to identify a user.</p>
 */
@property (nonatomic, strong) NSString * _Nullable developerUserIdentifier;

/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>An identity pool ID in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityPoolId;

@end

/**
 <p>Input to the UnlinkIdentity action.</p>
 Required parameters: [IdentityId, Logins, LoginsToRemove]
 */
@interface QYKFAWSCognitoIdentityUnlinkIdentityInput : QYKFAWSRequest


/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

/**
 <p>A set of optional name-value pairs that map provider names to provider tokens.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable logins;

/**
 <p>Provider names to unlink from this identity.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable loginsToRemove;

@end

/**
 <p>An array of UnprocessedIdentityId objects, each of which contains an ErrorCode and IdentityId.</p>
 */
@interface QYKFAWSCognitoIdentityUnprocessedIdentityId : QYKFAWSModel


/**
 <p>The error code indicating the type of error that occurred.</p>
 */
@property (nonatomic, assign) QYKFAWSCognitoIdentityErrorCode errorCode;

/**
 <p>A unique identifier in the format REGION:GUID.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identityId;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityUntagResourceInput : QYKFAWSRequest


/**
 <p>The Amazon Resource Name (ARN) of the identity pool.</p>
 */
@property (nonatomic, strong) NSString * _Nullable resourceArn;

/**
 <p>The keys of the tags to remove from the user pool.</p>
 */
@property (nonatomic, strong) NSArray<NSString *> * _Nullable tagKeys;

@end

/**
 
 */
@interface QYKFAWSCognitoIdentityUntagResourceResponse : QYKFAWSModel


@end

NS_ASSUME_NONNULL_END
