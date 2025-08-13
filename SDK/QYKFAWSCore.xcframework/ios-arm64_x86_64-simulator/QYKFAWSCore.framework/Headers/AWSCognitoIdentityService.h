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
#import "AWSCore.h"
#import "AWSCognitoIdentityModel.h"
#import "AWSCognitoIdentityResources.h"

NS_ASSUME_NONNULL_BEGIN

/**
 <fullname>Amazon Cognito Federated Identities</fullname><p>Amazon Cognito Federated Identities is a web service that delivers scoped temporary credentials to mobile devices and other untrusted environments. It uniquely identifies a device and supplies the user with a consistent identity over the lifetime of an application.</p><p>Using Amazon Cognito Federated Identities, you can enable authentication with one or more third-party identity providers (Facebook, Google, or Login with Amazon) or an Amazon Cognito user pool, and you can also choose to support unauthenticated access from your app. Cognito delivers a unique identifier for each user and acts as an OpenID token provider trusted by AWS Security Token Service (STS) to access temporary, limited-privilege AWS credentials.</p><p>For a description of the authentication flow from the Amazon Cognito Developer Guide see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/authentication-flow.html">Authentication Flow</a>.</p><p>For more information see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-identity.html">Amazon Cognito Federated Identities</a>.</p>
 */
@interface QYKFAWSCognitoIdentity : QYKFAWSService

/**
 The service configuration used to instantiate this service client.
 
 @warning Once the client is instantiated, do not modify the configuration object. It may cause unspecified behaviors.
 */
@property (nonatomic, strong, readonly) QYKFAWSServiceConfiguration *configuration;

/**
 Returns the singleton service client. If the singleton object does not exist, the SDK instantiates the default service client with `defaultServiceConfiguration` from `[AWSServiceManager defaultServiceManager]`. The reference to this object is maintained by the SDK, and you do not need to retain it manually.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`
 
 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = QYKFAWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USEast1, credentialsProvider: credentialProvider)
        AWSServiceManager.default().defaultServiceConfiguration = configuration
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
          QYKFAWSCognitoCredentialsProvider *credentialsProvider = [[QYKFAWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                          identityPoolId:@"YourIdentityPoolId"];
          AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSEast1
                                                                               credentialsProvider:credentialsProvider];
          [AWSServiceManager defaultServiceManager].defaultServiceConfiguration = configuration;

          return YES;
      }

 Then call the following to get the default service client:

 *Swift*

     let CognitoIdentity = QYKFAWSCognitoIdentity.default()

 *Objective-C*

     QYKFAWSCognitoIdentity *CognitoIdentity = [QYKFAWSCognitoIdentity defaultCognitoIdentity];

 @return The default service client.
 */
+ (instancetype)defaultCognitoIdentity;

/**
 Creates a service client with the given service configuration and registers it for the key.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = QYKFAWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
        QYKFAWSCognitoIdentity.register(with: configuration!, forKey: "USWest2CognitoIdentity")
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         QYKFAWSCognitoCredentialsProvider *credentialsProvider = [[QYKFAWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [QYKFAWSCognitoIdentity registerCognitoIdentityWithConfiguration:configuration forKey:@"USWest2CognitoIdentity"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let CognitoIdentity = QYKFAWSCognitoIdentity(forKey: "USWest2CognitoIdentity")

 *Objective-C*

     QYKFAWSCognitoIdentity *CognitoIdentity = [QYKFAWSCognitoIdentity CognitoIdentityForKey:@"USWest2CognitoIdentity"];

 @warning After calling this method, do not modify the configuration object. It may cause unspecified behaviors.

 @param configuration A service configuration object.
 @param key           A string to identify the service client.
 */
+ (void)registerCognitoIdentityWithConfiguration:(QYKFAWSServiceConfiguration *)configuration forKey:(NSString *)key;

/**
 Retrieves the service client associated with the key. You need to call `+ registerCognitoIdentityWithConfiguration:forKey:` before invoking this method.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = QYKFAWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
        QYKFAWSCognitoIdentity.register(with: configuration!, forKey: "USWest2CognitoIdentity")
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         QYKFAWSCognitoCredentialsProvider *credentialsProvider = [[QYKFAWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [QYKFAWSCognitoIdentity registerCognitoIdentityWithConfiguration:configuration forKey:@"USWest2CognitoIdentity"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let CognitoIdentity = QYKFAWSCognitoIdentity(forKey: "USWest2CognitoIdentity")

 *Objective-C*

     QYKFAWSCognitoIdentity *CognitoIdentity = [QYKFAWSCognitoIdentity CognitoIdentityForKey:@"USWest2CognitoIdentity"];

 @param key A string to identify the service client.

 @return An instance of the service client.
 */
+ (instancetype)CognitoIdentityForKey:(NSString *)key;

/**
 Removes the service client associated with the key and release it.
 
 @warning Before calling this method, make sure no method is running on this client.
 
 @param key A string to identify the service client.
 */
+ (void)removeCognitoIdentityForKey:(NSString *)key;

/**
 <p>Creates a new identity pool. The identity pool is a store of user identity information that is specific to your AWS account. The keys for <code>SupportedLoginProviders</code> are as follows:</p><ul><li><p>Facebook: <code>graph.facebook.com</code></p></li><li><p>Google: <code>accounts.google.com</code></p></li><li><p>Amazon: <code>www.amazon.com</code></p></li><li><p>Twitter: <code>api.twitter.com</code></p></li><li><p>Digits: <code>www.digits.com</code></p></li></ul><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the CreateIdentityPool service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityIdentityPool`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorLimitExceeded`.
 
 @see QYKFAWSCognitoIdentityCreateIdentityPoolInput
 @see QYKFAWSCognitoIdentityIdentityPool
 */
- (QYKFTask<QYKFAWSCognitoIdentityIdentityPool *> *)createIdentityPool:(QYKFAWSCognitoIdentityCreateIdentityPoolInput *)request;

/**
 <p>Creates a new identity pool. The identity pool is a store of user identity information that is specific to your AWS account. The keys for <code>SupportedLoginProviders</code> are as follows:</p><ul><li><p>Facebook: <code>graph.facebook.com</code></p></li><li><p>Google: <code>accounts.google.com</code></p></li><li><p>Amazon: <code>www.amazon.com</code></p></li><li><p>Twitter: <code>api.twitter.com</code></p></li><li><p>Digits: <code>www.digits.com</code></p></li></ul><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the CreateIdentityPool service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorLimitExceeded`.
 
 @see QYKFAWSCognitoIdentityCreateIdentityPoolInput
 @see QYKFAWSCognitoIdentityIdentityPool
 */
- (void)createIdentityPool:(QYKFAWSCognitoIdentityCreateIdentityPoolInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityIdentityPool * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes identities from an identity pool. You can specify a list of 1-60 identities that you want to delete.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DeleteIdentities service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityDeleteIdentitiesResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDeleteIdentitiesInput
 @see QYKFAWSCognitoIdentityDeleteIdentitiesResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityDeleteIdentitiesResponse *> *)deleteIdentities:(QYKFAWSCognitoIdentityDeleteIdentitiesInput *)request;

/**
 <p>Deletes identities from an identity pool. You can specify a list of 1-60 identities that you want to delete.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DeleteIdentities service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDeleteIdentitiesInput
 @see QYKFAWSCognitoIdentityDeleteIdentitiesResponse
 */
- (void)deleteIdentities:(QYKFAWSCognitoIdentityDeleteIdentitiesInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityDeleteIdentitiesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes an identity pool. Once a pool is deleted, users will not be able to authenticate with the pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DeleteIdentityPool service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDeleteIdentityPoolInput
 */
- (QYKFTask *)deleteIdentityPool:(QYKFAWSCognitoIdentityDeleteIdentityPoolInput *)request;

/**
 <p>Deletes an identity pool. Once a pool is deleted, users will not be able to authenticate with the pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DeleteIdentityPool service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDeleteIdentityPoolInput
 */
- (void)deleteIdentityPool:(QYKFAWSCognitoIdentityDeleteIdentityPoolInput *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Returns metadata related to the given identity, including when the identity was created and any associated linked logins.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DescribeIdentity service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityIdentityDescription`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDescribeIdentityInput
 @see QYKFAWSCognitoIdentityIdentityDescription
 */
- (QYKFTask<QYKFAWSCognitoIdentityIdentityDescription *> *)describeIdentity:(QYKFAWSCognitoIdentityDescribeIdentityInput *)request;

/**
 <p>Returns metadata related to the given identity, including when the identity was created and any associated linked logins.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DescribeIdentity service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDescribeIdentityInput
 @see QYKFAWSCognitoIdentityIdentityDescription
 */
- (void)describeIdentity:(QYKFAWSCognitoIdentityDescribeIdentityInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityIdentityDescription * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets details about a particular identity pool, including the pool name, ID description, creation date, and current number of users.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DescribeIdentityPool service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityIdentityPool`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDescribeIdentityPoolInput
 @see QYKFAWSCognitoIdentityIdentityPool
 */
- (QYKFTask<QYKFAWSCognitoIdentityIdentityPool *> *)describeIdentityPool:(QYKFAWSCognitoIdentityDescribeIdentityPoolInput *)request;

/**
 <p>Gets details about a particular identity pool, including the pool name, ID description, creation date, and current number of users.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the DescribeIdentityPool service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityDescribeIdentityPoolInput
 @see QYKFAWSCognitoIdentityIdentityPool
 */
- (void)describeIdentityPool:(QYKFAWSCognitoIdentityDescribeIdentityPoolInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityIdentityPool * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns credentials for the provided identity ID. Any provided logins will be validated against supported login providers. If the token is for cognito-identity.amazonaws.com, it will be passed through to AWS Security Token Service with the appropriate role for the token.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetCredentialsForIdentity service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityGetCredentialsForIdentityResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInvalidIdentityPoolConfiguration`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityGetCredentialsForIdentityInput
 @see QYKFAWSCognitoIdentityGetCredentialsForIdentityResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityGetCredentialsForIdentityResponse *> *)getCredentialsForIdentity:(QYKFAWSCognitoIdentityGetCredentialsForIdentityInput *)request;

/**
 <p>Returns credentials for the provided identity ID. Any provided logins will be validated against supported login providers. If the token is for cognito-identity.amazonaws.com, it will be passed through to AWS Security Token Service with the appropriate role for the token.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetCredentialsForIdentity service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInvalidIdentityPoolConfiguration`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityGetCredentialsForIdentityInput
 @see QYKFAWSCognitoIdentityGetCredentialsForIdentityResponse
 */
- (void)getCredentialsForIdentity:(QYKFAWSCognitoIdentityGetCredentialsForIdentityInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityGetCredentialsForIdentityResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Generates (or retrieves) a Cognito ID. Supplying multiple logins will create an implicit linked account.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetId service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityGetIdResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorLimitExceeded`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityGetIdInput
 @see QYKFAWSCognitoIdentityGetIdResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityGetIdResponse *> *)getId:(QYKFAWSCognitoIdentityGetIdInput *)request;

/**
 <p>Generates (or retrieves) a Cognito ID. Supplying multiple logins will create an implicit linked account.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetId service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorLimitExceeded`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityGetIdInput
 @see QYKFAWSCognitoIdentityGetIdResponse
 */
- (void)getId:(QYKFAWSCognitoIdentityGetIdInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityGetIdResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets the roles for an identity pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetIdentityPoolRoles service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityGetIdentityPoolRolesResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityGetIdentityPoolRolesInput
 @see QYKFAWSCognitoIdentityGetIdentityPoolRolesResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityGetIdentityPoolRolesResponse *> *)getIdentityPoolRoles:(QYKFAWSCognitoIdentityGetIdentityPoolRolesInput *)request;

/**
 <p>Gets the roles for an identity pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetIdentityPoolRoles service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityGetIdentityPoolRolesInput
 @see QYKFAWSCognitoIdentityGetIdentityPoolRolesResponse
 */
- (void)getIdentityPoolRoles:(QYKFAWSCognitoIdentityGetIdentityPoolRolesInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityGetIdentityPoolRolesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gets an OpenID token, using a known Cognito ID. This known Cognito ID is returned by <a>GetId</a>. You can optionally add additional logins for the identity. Supplying multiple logins creates an implicit link.</p><p>The OpenID token is valid for 10 minutes.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetOpenIdToken service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityGetOpenIdTokenResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityGetOpenIdTokenInput
 @see QYKFAWSCognitoIdentityGetOpenIdTokenResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityGetOpenIdTokenResponse *> *)getOpenIdToken:(QYKFAWSCognitoIdentityGetOpenIdTokenInput *)request;

/**
 <p>Gets an OpenID token, using a known Cognito ID. This known Cognito ID is returned by <a>GetId</a>. You can optionally add additional logins for the identity. Supplying multiple logins creates an implicit link.</p><p>The OpenID token is valid for 10 minutes.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetOpenIdToken service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityGetOpenIdTokenInput
 @see QYKFAWSCognitoIdentityGetOpenIdTokenResponse
 */
- (void)getOpenIdToken:(QYKFAWSCognitoIdentityGetOpenIdTokenInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityGetOpenIdTokenResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Registers (or retrieves) a Cognito <code>IdentityId</code> and an OpenID Connect token for a user authenticated by your backend authentication process. Supplying multiple logins will create an implicit linked account. You can only specify one developer provider as part of the <code>Logins</code> map, which is linked to the identity pool. The developer provider is the "domain" by which Cognito will refer to your users.</p><p>You can use <code>GetOpenIdTokenForDeveloperIdentity</code> to create a new identity and to link new logins (that is, user credentials issued by a public provider or developer provider) to an existing identity. When you want to create a new identity, the <code>IdentityId</code> should be null. When you want to associate a new login with an existing authenticated/unauthenticated identity, you can do so by providing the existing <code>IdentityId</code>. This API will create the identity in the specified <code>IdentityPoolId</code>.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetOpenIdTokenForDeveloperIdentity service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorDeveloperUserAlreadyRegistered`.
 
 @see QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityInput
 @see QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityResponse *> *)getOpenIdTokenForDeveloperIdentity:(QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityInput *)request;

/**
 <p>Registers (or retrieves) a Cognito <code>IdentityId</code> and an OpenID Connect token for a user authenticated by your backend authentication process. Supplying multiple logins will create an implicit linked account. You can only specify one developer provider as part of the <code>Logins</code> map, which is linked to the identity pool. The developer provider is the "domain" by which Cognito will refer to your users.</p><p>You can use <code>GetOpenIdTokenForDeveloperIdentity</code> to create a new identity and to link new logins (that is, user credentials issued by a public provider or developer provider) to an existing identity. When you want to create a new identity, the <code>IdentityId</code> should be null. When you want to associate a new login with an existing authenticated/unauthenticated identity, you can do so by providing the existing <code>IdentityId</code>. This API will create the identity in the specified <code>IdentityPoolId</code>.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the GetOpenIdTokenForDeveloperIdentity service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorDeveloperUserAlreadyRegistered`.
 
 @see QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityInput
 @see QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityResponse
 */
- (void)getOpenIdTokenForDeveloperIdentity:(QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityGetOpenIdTokenForDeveloperIdentityResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Use <code>GetPrincipalTagAttributeMap</code> to list all mappings between <code>PrincipalTags</code> and user attributes.</p>
 
 @param request A container for the necessary parameters to execute the GetPrincipalTagAttributeMap service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapInput
 @see QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapResponse *> *)getPrincipalTagAttributeMap:(QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapInput *)request;

/**
 <p>Use <code>GetPrincipalTagAttributeMap</code> to list all mappings between <code>PrincipalTags</code> and user attributes.</p>
 
 @param request A container for the necessary parameters to execute the GetPrincipalTagAttributeMap service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapInput
 @see QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapResponse
 */
- (void)getPrincipalTagAttributeMap:(QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityGetPrincipalTagAttributeMapResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the identities in an identity pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the ListIdentities service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityListIdentitiesResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityListIdentitiesInput
 @see QYKFAWSCognitoIdentityListIdentitiesResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityListIdentitiesResponse *> *)listIdentities:(QYKFAWSCognitoIdentityListIdentitiesInput *)request;

/**
 <p>Lists the identities in an identity pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the ListIdentities service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityListIdentitiesInput
 @see QYKFAWSCognitoIdentityListIdentitiesResponse
 */
- (void)listIdentities:(QYKFAWSCognitoIdentityListIdentitiesInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityListIdentitiesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists all of the Cognito identity pools registered for your account.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the ListIdentityPools service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityListIdentityPoolsResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityListIdentityPoolsInput
 @see QYKFAWSCognitoIdentityListIdentityPoolsResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityListIdentityPoolsResponse *> *)listIdentityPools:(QYKFAWSCognitoIdentityListIdentityPoolsInput *)request;

/**
 <p>Lists all of the Cognito identity pools registered for your account.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the ListIdentityPools service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityListIdentityPoolsInput
 @see QYKFAWSCognitoIdentityListIdentityPoolsResponse
 */
- (void)listIdentityPools:(QYKFAWSCognitoIdentityListIdentityPoolsInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityListIdentityPoolsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists the tags that are assigned to an Amazon Cognito identity pool.</p><p>A tag is a label that you can apply to identity pools to categorize and manage them in different ways, such as by purpose, owner, environment, or other criteria.</p><p>You can use this action up to 10 times per second, per account.</p>
 
 @param request A container for the necessary parameters to execute the ListTagsForResource service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityListTagsForResourceResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityListTagsForResourceInput
 @see QYKFAWSCognitoIdentityListTagsForResourceResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityListTagsForResourceResponse *> *)listTagsForResource:(QYKFAWSCognitoIdentityListTagsForResourceInput *)request;

/**
 <p>Lists the tags that are assigned to an Amazon Cognito identity pool.</p><p>A tag is a label that you can apply to identity pools to categorize and manage them in different ways, such as by purpose, owner, environment, or other criteria.</p><p>You can use this action up to 10 times per second, per account.</p>
 
 @param request A container for the necessary parameters to execute the ListTagsForResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityListTagsForResourceInput
 @see QYKFAWSCognitoIdentityListTagsForResourceResponse
 */
- (void)listTagsForResource:(QYKFAWSCognitoIdentityListTagsForResourceInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityListTagsForResourceResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Retrieves the <code>IdentityID</code> associated with a <code>DeveloperUserIdentifier</code> or the list of <code>DeveloperUserIdentifier</code> values associated with an <code>IdentityId</code> for an existing identity. Either <code>IdentityID</code> or <code>DeveloperUserIdentifier</code> must not be null. If you supply only one of these values, the other value will be searched in the database and returned as a part of the response. If you supply both, <code>DeveloperUserIdentifier</code> will be matched against <code>IdentityID</code>. If the values are verified against the database, the response returns both values and is the same as the request. Otherwise a <code>ResourceConflictException</code> is thrown.</p><p><code>LookupDeveloperIdentity</code> is intended for low-throughput control plane operations: for example, to enable customer service to locate an identity ID by username. If you are using it for higher-volume operations such as user authentication, your requests are likely to be throttled. <a>GetOpenIdTokenForDeveloperIdentity</a> is a better option for higher-volume operations for user authentication.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the LookupDeveloperIdentity service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityLookupDeveloperIdentityResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityLookupDeveloperIdentityInput
 @see QYKFAWSCognitoIdentityLookupDeveloperIdentityResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityLookupDeveloperIdentityResponse *> *)lookupDeveloperIdentity:(QYKFAWSCognitoIdentityLookupDeveloperIdentityInput *)request;

/**
 <p>Retrieves the <code>IdentityID</code> associated with a <code>DeveloperUserIdentifier</code> or the list of <code>DeveloperUserIdentifier</code> values associated with an <code>IdentityId</code> for an existing identity. Either <code>IdentityID</code> or <code>DeveloperUserIdentifier</code> must not be null. If you supply only one of these values, the other value will be searched in the database and returned as a part of the response. If you supply both, <code>DeveloperUserIdentifier</code> will be matched against <code>IdentityID</code>. If the values are verified against the database, the response returns both values and is the same as the request. Otherwise a <code>ResourceConflictException</code> is thrown.</p><p><code>LookupDeveloperIdentity</code> is intended for low-throughput control plane operations: for example, to enable customer service to locate an identity ID by username. If you are using it for higher-volume operations such as user authentication, your requests are likely to be throttled. <a>GetOpenIdTokenForDeveloperIdentity</a> is a better option for higher-volume operations for user authentication.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the LookupDeveloperIdentity service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityLookupDeveloperIdentityInput
 @see QYKFAWSCognitoIdentityLookupDeveloperIdentityResponse
 */
- (void)lookupDeveloperIdentity:(QYKFAWSCognitoIdentityLookupDeveloperIdentityInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityLookupDeveloperIdentityResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Merges two users having different <code>IdentityId</code>s, existing in the same identity pool, and identified by the same developer provider. You can use this action to request that discrete users be merged and identified as a single user in the Cognito environment. Cognito associates the given source user (<code>SourceUserIdentifier</code>) with the <code>IdentityId</code> of the <code>DestinationUserIdentifier</code>. Only developer-authenticated users can be merged. If the users to be merged are associated with the same public provider, but as two different users, an exception will be thrown.</p><p>The number of linked logins is limited to 20. So, the number of linked logins for the source user, <code>SourceUserIdentifier</code>, and the destination user, <code>DestinationUserIdentifier</code>, together should not be larger than 20. Otherwise, an exception will be thrown.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the MergeDeveloperIdentities service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityMergeDeveloperIdentitiesResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityMergeDeveloperIdentitiesInput
 @see QYKFAWSCognitoIdentityMergeDeveloperIdentitiesResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityMergeDeveloperIdentitiesResponse *> *)mergeDeveloperIdentities:(QYKFAWSCognitoIdentityMergeDeveloperIdentitiesInput *)request;

/**
 <p>Merges two users having different <code>IdentityId</code>s, existing in the same identity pool, and identified by the same developer provider. You can use this action to request that discrete users be merged and identified as a single user in the Cognito environment. Cognito associates the given source user (<code>SourceUserIdentifier</code>) with the <code>IdentityId</code> of the <code>DestinationUserIdentifier</code>. Only developer-authenticated users can be merged. If the users to be merged are associated with the same public provider, but as two different users, an exception will be thrown.</p><p>The number of linked logins is limited to 20. So, the number of linked logins for the source user, <code>SourceUserIdentifier</code>, and the destination user, <code>DestinationUserIdentifier</code>, together should not be larger than 20. Otherwise, an exception will be thrown.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the MergeDeveloperIdentities service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityMergeDeveloperIdentitiesInput
 @see QYKFAWSCognitoIdentityMergeDeveloperIdentitiesResponse
 */
- (void)mergeDeveloperIdentities:(QYKFAWSCognitoIdentityMergeDeveloperIdentitiesInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityMergeDeveloperIdentitiesResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Sets the roles for an identity pool. These roles are used when making calls to <a>GetCredentialsForIdentity</a> action.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the SetIdentityPoolRoles service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorConcurrentModification`.
 
 @see QYKFAWSCognitoIdentitySetIdentityPoolRolesInput
 */
- (QYKFTask *)setIdentityPoolRoles:(QYKFAWSCognitoIdentitySetIdentityPoolRolesInput *)request;

/**
 <p>Sets the roles for an identity pool. These roles are used when making calls to <a>GetCredentialsForIdentity</a> action.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the SetIdentityPoolRoles service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorConcurrentModification`.
 
 @see QYKFAWSCognitoIdentitySetIdentityPoolRolesInput
 */
- (void)setIdentityPoolRoles:(QYKFAWSCognitoIdentitySetIdentityPoolRolesInput *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>You can use this operation to use default (username and clientID) attribute or custom attribute mappings.</p>
 
 @param request A container for the necessary parameters to execute the SetPrincipalTagAttributeMap service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapInput
 @see QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapResponse *> *)setPrincipalTagAttributeMap:(QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapInput *)request;

/**
 <p>You can use this operation to use default (username and clientID) attribute or custom attribute mappings.</p>
 
 @param request A container for the necessary parameters to execute the SetPrincipalTagAttributeMap service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapInput
 @see QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapResponse
 */
- (void)setPrincipalTagAttributeMap:(QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentitySetPrincipalTagAttributeMapResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Assigns a set of tags to the specified Amazon Cognito identity pool. A tag is a label that you can use to categorize and manage identity pools in different ways, such as by purpose, owner, environment, or other criteria.</p><p>Each tag consists of a key and value, both of which you define. A key is a general category for more specific values. For example, if you have two versions of an identity pool, one for testing and another for production, you might assign an <code>Environment</code> tag key to both identity pools. The value of this key might be <code>Test</code> for one identity pool and <code>Production</code> for the other.</p><p>Tags are useful for cost tracking and access control. You can activate your tags so that they appear on the Billing and Cost Management console, where you can track the costs associated with your identity pools. In an IAM policy, you can constrain permissions for identity pools based on specific tags or tag values.</p><p>You can use this action up to 5 times per second, per account. An identity pool can have as many as 50 tags.</p>
 
 @param request A container for the necessary parameters to execute the TagResource service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityTagResourceResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityTagResourceInput
 @see QYKFAWSCognitoIdentityTagResourceResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityTagResourceResponse *> *)tagResource:(QYKFAWSCognitoIdentityTagResourceInput *)request;

/**
 <p>Assigns a set of tags to the specified Amazon Cognito identity pool. A tag is a label that you can use to categorize and manage identity pools in different ways, such as by purpose, owner, environment, or other criteria.</p><p>Each tag consists of a key and value, both of which you define. A key is a general category for more specific values. For example, if you have two versions of an identity pool, one for testing and another for production, you might assign an <code>Environment</code> tag key to both identity pools. The value of this key might be <code>Test</code> for one identity pool and <code>Production</code> for the other.</p><p>Tags are useful for cost tracking and access control. You can activate your tags so that they appear on the Billing and Cost Management console, where you can track the costs associated with your identity pools. In an IAM policy, you can constrain permissions for identity pools based on specific tags or tag values.</p><p>You can use this action up to 5 times per second, per account. An identity pool can have as many as 50 tags.</p>
 
 @param request A container for the necessary parameters to execute the TagResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityTagResourceInput
 @see QYKFAWSCognitoIdentityTagResourceResponse
 */
- (void)tagResource:(QYKFAWSCognitoIdentityTagResourceInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityTagResourceResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Unlinks a <code>DeveloperUserIdentifier</code> from an existing identity. Unlinked developer users will be considered new identities next time they are seen. If, for a given Cognito identity, you remove all federated identities as well as the developer user identifier, the Cognito identity becomes inaccessible.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the UnlinkDeveloperIdentity service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityUnlinkDeveloperIdentityInput
 */
- (QYKFTask *)unlinkDeveloperIdentity:(QYKFAWSCognitoIdentityUnlinkDeveloperIdentityInput *)request;

/**
 <p>Unlinks a <code>DeveloperUserIdentifier</code> from an existing identity. Unlinked developer users will be considered new identities next time they are seen. If, for a given Cognito identity, you remove all federated identities as well as the developer user identifier, the Cognito identity becomes inaccessible.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the UnlinkDeveloperIdentity service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityUnlinkDeveloperIdentityInput
 */
- (void)unlinkDeveloperIdentity:(QYKFAWSCognitoIdentityUnlinkDeveloperIdentityInput *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Unlinks a federated identity from an existing account. Unlinked logins will be considered new identities next time they are seen. Removing the last linked login will make this identity inaccessible.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the UnlinkIdentity service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityUnlinkIdentityInput
 */
- (QYKFTask *)unlinkIdentity:(QYKFAWSCognitoIdentityUnlinkIdentityInput *)request;

/**
 <p>Unlinks a federated identity from an existing account. Unlinked logins will be considered new identities next time they are seen. Removing the last linked login will make this identity inaccessible.</p><p>This is a public API. You do not need any credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the UnlinkIdentity service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorExternalService`.
 
 @see QYKFAWSCognitoIdentityUnlinkIdentityInput
 */
- (void)unlinkIdentity:(QYKFAWSCognitoIdentityUnlinkIdentityInput *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p>Removes the specified tags from the specified Amazon Cognito identity pool. You can use this action up to 5 times per second, per account</p>
 
 @param request A container for the necessary parameters to execute the UntagResource service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityUntagResourceResponse`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityUntagResourceInput
 @see QYKFAWSCognitoIdentityUntagResourceResponse
 */
- (QYKFTask<QYKFAWSCognitoIdentityUntagResourceResponse *> *)untagResource:(QYKFAWSCognitoIdentityUntagResourceInput *)request;

/**
 <p>Removes the specified tags from the specified Amazon Cognito identity pool. You can use this action up to 5 times per second, per account</p>
 
 @param request A container for the necessary parameters to execute the UntagResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`.
 
 @see QYKFAWSCognitoIdentityUntagResourceInput
 @see QYKFAWSCognitoIdentityUntagResourceResponse
 */
- (void)untagResource:(QYKFAWSCognitoIdentityUntagResourceInput *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityUntagResourceResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates an identity pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the UpdateIdentityPool service method.

 @return An instance of `QYKFTask`. On successful execution, `task.result` will contain an instance of `QYKFAWSCognitoIdentityIdentityPool`. On failed execution, `task.error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorConcurrentModification`, `QYKFAWSCognitoIdentityErrorLimitExceeded`.
 
 @see QYKFAWSCognitoIdentityIdentityPool
 @see QYKFAWSCognitoIdentityIdentityPool
 */
- (QYKFTask<QYKFAWSCognitoIdentityIdentityPool *> *)updateIdentityPool:(QYKFAWSCognitoIdentityIdentityPool *)request;

/**
 <p>Updates an identity pool.</p><p>You must use AWS Developer credentials to call this API.</p>
 
 @param request A container for the necessary parameters to execute the UpdateIdentityPool service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `QYKFAWSCognitoIdentityErrorDomain` domain and the following error code: `QYKFAWSCognitoIdentityErrorInvalidParameter`, `QYKFAWSCognitoIdentityErrorResourceNotFound`, `QYKFAWSCognitoIdentityErrorNotAuthorized`, `QYKFAWSCognitoIdentityErrorResourceConflict`, `QYKFAWSCognitoIdentityErrorTooManyRequests`, `QYKFAWSCognitoIdentityErrorInternalError`, `QYKFAWSCognitoIdentityErrorConcurrentModification`, `QYKFAWSCognitoIdentityErrorLimitExceeded`.
 
 @see QYKFAWSCognitoIdentityIdentityPool
 @see QYKFAWSCognitoIdentityIdentityPool
 */
- (void)updateIdentityPool:(QYKFAWSCognitoIdentityIdentityPool *)request completionHandler:(void (^ _Nullable)(QYKFAWSCognitoIdentityIdentityPool * _Nullable response, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
