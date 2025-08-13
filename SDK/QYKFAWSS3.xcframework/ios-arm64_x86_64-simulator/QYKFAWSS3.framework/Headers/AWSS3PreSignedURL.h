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

#import <QYKFAWSCore/AWSCore.h>
#import "QYKFAWSS3Model.h"

NS_ASSUME_NONNULL_BEGIN

static NSString *const QYKFAWSS3PresignedURLVersionID = @"versionId";
static NSString *const QYKFAWSS3PresignedURLTorrent = @"torrent";

static NSString *const QYKFAWSS3PresignedURLServerSideEncryption = @"x-amz-server-side-encryption";
static NSString *const QYKFAWSS3PresignedURLServerSideEncryptionCustomerAlgorithm = @"x-amz-server-side-encryption-customer-algorithm";
static NSString *const QYKFAWSS3PresignedURLServerSideEncryptionCustomerKey = @"x-amz-server-side-encryption-customer-key";
static NSString *const QYKFAWSS3PresignedURLServerSdieEncryptionCustomerKeyMD5 = @"x-amz-server-side-encryption-customer-key-MD5";


FOUNDATION_EXPORT NSString *const QYKFAWSS3PresignedURLErrorDomain;
typedef NS_ENUM(NSInteger, QYKFAWSS3PresignedURLErrorType) {
    QYKFAWSS3PresignedURLErrorUnknown,
    QYKFAWSS3PresignedURLErrorAccessKeyIsNil,
    QYKFAWSS3PresignedURLErrorSecretKeyIsNil,
    QYKFAWSS3PresignedURLErrorBucketNameIsNil,
    QYKFAWSS3PresignedURLErrorKeyNameIsNil,
    QYKFAWSS3PresignedURLErrorInvalidExpiresDate,
    QYKFAWSS3PresignedURLErrorUnsupportedHTTPVerbs,
    QYKFAWSS3PresignedURLErrorEndpointIsNil,
    QYKFAWSS3PresignedURLErrorInvalidServiceType,
    QYKFAWSS3PresignedURLErrorCredentialProviderIsNil,
    QYKFAWSS3PresignedURLErrorInternalError,
    QYKFAWSS3PresignedURLErrorInvalidRequestParameters,
    QYKFAWSS3PresignedURLErrorInvalidBucketName,
    QYKFAWSS3PresignedURLErrorInvalidBucketNameForAccelerateModeEnabled,
    QYKFAWSS3PresignedURLErrorInvalidAccessStyleForAccelerateModeEnabled,
};

@class QYKFAWSS3GetPreSignedURLRequest;

@interface QYKFAWSS3PreSignedURLBuilder : QYKFAWSService

/**
 Returns the singleton service client. If the singleton object does not exist, the SDK instantiates the default service client with `defaultServiceConfiguration` from `[QYKFAWSServiceManager defaultServiceManager]`. The reference to this object is maintained by the SDK, and you do not need to retain it manually.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
         let credentialProvider = QYKFAWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
         let configuration = QYKFAWSServiceConfiguration(region: .USEast1, credentialsProvider: credentialProvider)
         QYKFAWSServiceManager.defaultServiceManager().defaultServiceConfiguration = configuration

         return true
     }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
          QYKFAWSCognitoCredentialsProvider *credentialsProvider = [[QYKFAWSCognitoCredentialsProvider alloc] initWithRegionType:QYKFAWSRegionUSEast1
                                                                                                          identityPoolId:@"YourIdentityPoolId"];
          QYKFAWSServiceConfiguration *configuration = [[QYKFAWSServiceConfiguration alloc] initWithRegion:QYKFAWSRegionUSEast1
                                                                               credentialsProvider:credentialsProvider];
          [QYKFAWSServiceManager defaultServiceManager].defaultServiceConfiguration = configuration;

          return YES;
      }

 Then call the following to get the default service client:

 *Swift*

     let S3PreSignedURLBuilder = QYKFAWSS3PreSignedURLBuilder.defaultS3PreSignedURLBuilder()

 *Objective-C*

     QYKFAWSS3PreSignedURLBuilder *S3PreSignedURLBuilder = [QYKFAWSS3PreSignedURLBuilder defaultS3PreSignedURLBuilder];

 @return The default service client.
 */
+ (instancetype)defaultS3PreSignedURLBuilder;

/**
 Creates a service client with the given service configuration and registers it for the key.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
         let credentialProvider = QYKFAWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
         let configuration = QYKFAWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
         QYKFAWSS3PreSignedURLBuilder.registerS3PreSignedURLBuilderWithConfiguration(configuration, forKey: "USWest2S3PreSignedURLBuilder")

         return true
     }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         QYKFAWSCognitoCredentialsProvider *credentialsProvider = [[QYKFAWSCognitoCredentialsProvider alloc] initWithRegionType:QYKFAWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         QYKFAWSServiceConfiguration *configuration = [[QYKFAWSServiceConfiguration alloc] initWithRegion:QYKFAWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [QYKFAWSS3PreSignedURLBuilder registerS3PreSignedURLBuilderWithConfiguration:configuration forKey:@"USWest2S3PreSignedURLBuilder"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let S3PreSignedURLBuilder = QYKFAWSS3PreSignedURLBuilder(forKey: "USWest2S3PreSignedURLBuilder")

 *Objective-C*

     QYKFAWSS3PreSignedURLBuilder *S3PreSignedURLBuilder = [QYKFAWSS3PreSignedURLBuilder S3PreSignedURLBuilderForKey:@"USWest2S3PreSignedURLBuilder"];

 @warning After calling this method, do not modify the configuration object. It may cause unspecified behaviors.

 @param configuration A service configuration object.
 @param key           A string to identify the service client.
 */
+ (void)registerS3PreSignedURLBuilderWithConfiguration:(QYKFAWSServiceConfiguration *)configuration forKey:(NSString *)key;

/**
 Retrieves the service client associated with the key. You need to call `+ registerS3PreSignedURLBuilderWithConfiguration:forKey:` before invoking this method.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
         let credentialProvider = QYKFAWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
         let configuration = QYKFAWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
         QYKFAWSS3PreSignedURLBuilder.registerS3PreSignedURLBuilderWithConfiguration(configuration, forKey: "USWest2S3PreSignedURLBuilder")

         return true
     }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         QYKFAWSCognitoCredentialsProvider *credentialsProvider = [[QYKFAWSCognitoCredentialsProvider alloc] initWithRegionType:QYKFAWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         QYKFAWSServiceConfiguration *configuration = [[QYKFAWSServiceConfiguration alloc] initWithRegion:QYKFAWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [QYKFAWSS3PreSignedURLBuilder registerS3PreSignedURLBuilderWithConfiguration:configuration forKey:@"USWest2S3PreSignedURLBuilder"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let S3PreSignedURLBuilder = QYKFAWSS3PreSignedURLBuilder(forKey: "USWest2S3PreSignedURLBuilder")

 *Objective-C*

     QYKFAWSS3PreSignedURLBuilder *S3PreSignedURLBuilder = [QYKFAWSS3PreSignedURLBuilder S3PreSignedURLBuilderForKey:@"USWest2S3PreSignedURLBuilder"];

 @param key A string to identify the service client.

 @return An instance of the service client.
 */
+ (instancetype)S3PreSignedURLBuilderForKey:(NSString *)key;

/**
 Removes the service client associated with the key and release it.

 @warning Before calling this method, make sure no method is running on this client.

 @param key A string to identify the service client.
 */
+ (void)removeS3PreSignedURLBuilderForKey:(NSString *)key;

// modified by hzsusu@corp.netease.com
/**
 Build a time-limited pre-signed URL and header to get object from S3, return nil if build process failed.

 @param getPreSignedURLRequest The QYKFAWSS3PreSignedURLRequest that defines the parameters of the operation.
 @return A NSDictionary contains A pre-signed NSURL (key by "URL")and headers(key by "headers") for the resource. return nil if any errors occured.
 @see QYKFAWSS3GetPreSignedURLRequest
 */
- (QYKFTask<NSDictionary *> *)getPreSignedURL:(QYKFAWSS3GetPreSignedURLRequest *)getPreSignedURLRequest;

@end

/** The GetPreSignedURLRequest contains the parameters used to create
 a pre signed URL.
 @see QYKFAWSS3PreSignedURLBuilder

 */
@interface QYKFAWSS3GetPreSignedURLRequest : NSObject
/**
 Returns whether the client has enabled accelerate mode for getting and putting objects. The default is `NO`.
 */
@property (nonatomic, assign, getter=isAccelerateModeEnabled) BOOL accelerateModeEnabled;

// added by hzsusu@corp.netease.com
/**
 Put signature in header instead of in query param. The default is `NO`.
 */
@property (nonatomic) BOOL signatureInHeader;

/**
 The name of the bucket
 */
@property (nonatomic, strong) NSString *bucket;

/**
 The preferred access style for the bucket. The default is `QYKFAWSS3BucketAccessStyleVirtualHosted`.
 
 Virtual-hosted-style requests require that the bucket name must be DNS-compliant and must not contain periods `(".")`.
 
 If virtual-hosted-style access is set as preferred but the bucket name does not meet these conditions, path-style access will be used instead.
 */
@property (nonatomic, assign) QYKFAWSS3BucketAccessStyle preferredAccessStyle;

/**
 The name of the S3 object
 */
@property (nonatomic, strong) NSString *key;

/**
 Specifies the verb used in the pre-signed URL. accepted QYKFAWSHTTPMethodGET, QYKFAWSHTTPMethodPUT, QYKFAWSHTTPMethodHEAD.
 */
@property (nonatomic, assign) QYKFAWSHTTPMethod HTTPMethod;

/**
 The time when the signature expires, specified as an NSDate object.
 */
@property (nonatomic, strong) NSDate *expires;

/**
 QYKFAWSS3GetPreSignedURLRequest will automatically refresh temporary credential if expiration duration in less than minimumCredentialsExpirationInterval. Only applied for credential provider using temporary token (e.g. CognitoIdentityProvider). Default value is 3000 seconds.
 */
@property (nonatomic, assign) NSTimeInterval minimumCredentialsExpirationInterval;

/**
 Expected content-type of the request. If set, the content-type will be included in the signature and future requests must include the same content-type header value to access the presigned URL. This parameter is ignored unless QYKFAWSHTTPMethod is equal to QYKFAWSHTTPMethodPUT. Default is nil.
 */
@property (nonatomic) NSString * _Nullable contentType;

/**
 Expected content-md5 header of the request. If set, this header value will be included when calculating the signature and future requests must include the same content-md5 header value to access the presigned URL. This parameter is ignored unless HTTPMethod is equal to QYKFAWSHTTPMethodPUT. Default is nil.
 */
@property (nonatomic) NSString * _Nullable contentMD5;

/**
 This NSDictionary can contains additional request headers to be included in the pre-signed URL. Default is emtpy.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *requestHeaders;

/**
 This NSDictionary can contains additional request parameters to be included in the pre-signed URL. Adding additional request parameters enables more advanced pre-signed URLs, such as accessing Amazon S3's torrent resource for an object, or for specifying a version ID when accessing an object. Default is emtpy.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *requestParameters;

/**
 Set an additional request header to be included in the pre-signed URL.

 @param value The value of the request parameter being added. Set to nil if parameter doesn't contains value.
 @param requestHeader The name of the request header.
 */
- (void)setValue:(NSString * _Nullable)value forRequestHeader:(NSString *)requestHeader;

/**
 Set an additional request parameter to be included in the pre-signed URL. Adding additional request parameters enables more advanced pre-signed URLs, such as accessing Amazon S3's torrent resource for an object, or for specifying a version ID when accessing an object.
 
 @param value The value of the request parameter being added. Set to nil if parameter doesn't contains value.
 @param requestParameter The name of the request parameter, as it appears in the URL's query string (e.g. QYKFAWSS3PresignedURLVersionID).
 */
- (void)setValue:(NSString * _Nullable)value forRequestParameter:(NSString *)requestParameter;

@end

NS_ASSUME_NONNULL_END
