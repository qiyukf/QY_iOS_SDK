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
#import "AWSModel.h"

FOUNDATION_EXPORT NSString *const QYKFAWSNetworkingErrorDomain;
typedef NS_ENUM(NSInteger, QYKFAWSNetworkingErrorType) {
    QYKFAWSNetworkingErrorUnknown,
    QYKFAWSNetworkingErrorCancelled,
    QYKFAWSNetworkingErrorSessionInvalid
};

typedef NS_ENUM(NSInteger, QYKFAWSNetworkingRetryType) {
    QYKFAWSNetworkingRetryTypeUnknown,
    QYKFAWSNetworkingRetryTypeShouldNotRetry,
    QYKFAWSNetworkingRetryTypeShouldRetry,
    QYKFAWSNetworkingRetryTypeShouldRefreshCredentialsAndRetry,
    QYKFAWSNetworkingRetryTypeShouldCorrectClockSkewAndRetry,
    QYKFAWSNetworkingRetryTypeResetStreamAndRetry
};

/** UserInfo dictionary key for response errors */
FOUNDATION_EXPORT NSString *const QYKFAWSResponseObjectErrorUserInfoKey;

@class QYKFAWSNetworkingConfiguration;
@class QYKFAWSNetworkingRequest;
@class QYKFTask<__covariant ResultType>;

typedef void (^QYKFAWSNetworkingUploadProgressBlock) (int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend);
typedef void (^QYKFAWSNetworkingDownloadProgressBlock) (int64_t bytesWritten, int64_t totalBytesWritten, int64_t totalBytesExpectedToWrite);

#pragma mark - QYKFAWSHTTPMethod

typedef NS_ENUM(NSInteger, QYKFAWSHTTPMethod) {
    QYKFAWSHTTPMethodUnknown,
    QYKFAWSHTTPMethodGET,
    QYKFAWSHTTPMethodHEAD,
    QYKFAWSHTTPMethodPOST,
    QYKFAWSHTTPMethodPUT,
    QYKFAWSHTTPMethodPATCH,
    QYKFAWSHTTPMethodDELETE
};

@interface NSString (QYKFAWSHTTPMethod)

+ (instancetype)QYKF_stringWithHTTPMethod:(QYKFAWSHTTPMethod)HTTPMethod;

@end

#pragma mark - QYKFAWSNetworking

@interface QYKFAWSNetworking : NSObject

- (instancetype)initWithConfiguration:(QYKFAWSNetworkingConfiguration *)configuration;

- (QYKFTask *)sendRequest:(QYKFAWSNetworkingRequest *)request;

@end

#pragma mark - Protocols

@protocol QYKFAWSURLRequestSerializer <NSObject>

@required
- (QYKFTask *)validateRequest:(NSURLRequest *)request;
- (QYKFTask *)serializeRequest:(NSMutableURLRequest *)request
                     headers:(NSDictionary *)headers
                  parameters:(NSDictionary *)parameters;

@end

@protocol QYKFAWSNetworkingRequestInterceptor <NSObject>

@required
- (QYKFTask *)interceptRequest:(NSMutableURLRequest *)request;

@end

@protocol QYKFAWSNetworkingHTTPResponseInterceptor <NSObject>

@required
- (QYKFTask *)interceptResponse:(NSHTTPURLResponse *)response
                         data:(id)data
              originalRequest:(NSURLRequest *)originalRequest
               currentRequest:(NSURLRequest *)currentRequest;

@end

@protocol QYKFAWSHTTPURLResponseSerializer <NSObject>

@required

- (BOOL)validateResponse:(NSHTTPURLResponse *)response
             fromRequest:(NSURLRequest *)request
                    data:(id)data
                   error:(NSError *__autoreleasing *)error;
- (id)responseObjectForResponse:(NSHTTPURLResponse *)response
                originalRequest:(NSURLRequest *)originalRequest
                 currentRequest:(NSURLRequest *)currentRequest
                           data:(id)data
                          error:(NSError *__autoreleasing *)error;

@end

@protocol QYKFAWSURLRequestRetryHandler <NSObject>

@required

@property (nonatomic, assign) uint32_t maxRetryCount;

- (QYKFAWSNetworkingRetryType)shouldRetry:(uint32_t)currentRetryCount
                      originalRequest:(QYKFAWSNetworkingRequest *)originalRequest
                             response:(NSHTTPURLResponse *)response
                                 data:(NSData *)data
                                error:(NSError *)error;

- (NSTimeInterval)timeIntervalForRetry:(uint32_t)currentRetryCount
                              response:(NSHTTPURLResponse *)response
                                  data:(NSData *)data
                                 error:(NSError *)error;

@optional

- (NSDictionary *)resetParameters:(NSDictionary *)parameters;

@end


#pragma mark - QYKFAWSNetworkingConfiguration

@interface QYKFAWSNetworkingConfiguration : NSObject <NSCopying>

@property (nonatomic, readonly) NSURL *URL;
@property (nonatomic, strong) NSURL *baseURL;
@property (nonatomic, strong) NSString *URLString;
@property (nonatomic, assign) QYKFAWSHTTPMethod HTTPMethod;
@property (nonatomic, strong) NSDictionary *headers;
@property (nonatomic, assign) BOOL allowsCellularAccess;
@property (nonatomic, strong) NSString *sharedContainerIdentifier;

@property (nonatomic, strong) id<QYKFAWSURLRequestSerializer> requestSerializer;
@property (nonatomic, strong) NSArray<id<QYKFAWSNetworkingRequestInterceptor>> *requestInterceptors;
@property (nonatomic, strong) id<QYKFAWSHTTPURLResponseSerializer> responseSerializer;
@property (nonatomic, strong) NSArray<id<QYKFAWSNetworkingHTTPResponseInterceptor>> *responseInterceptors;
@property (nonatomic, strong) id<QYKFAWSURLRequestRetryHandler> retryHandler;

/**
 The maximum number of retries for failed requests. The value needs to be between 0 and 10 inclusive. If set to higher than 10, it becomes 10.
 */
@property (nonatomic, assign) uint32_t maxRetryCount;

/**
 The timeout interval to use when waiting for additional data.
 */
@property (nonatomic, assign) NSTimeInterval timeoutIntervalForRequest;

/**
 The maximum amount of time that a resource request should be allowed to take.
 */
@property (nonatomic, assign) NSTimeInterval timeoutIntervalForResource;

@end

#pragma mark - QYKFNetworkingRequest

@interface QYKFAWSNetworkingRequest : QYKFAWSNetworkingConfiguration

@property (nonatomic, strong) NSDictionary *parameters;
@property (nonatomic, strong) NSURL *uploadingFileURL;
@property (nonatomic, strong) NSURL *downloadingFileURL;
@property (nonatomic, assign) BOOL shouldWriteDirectly;

@property (nonatomic, copy) QYKFAWSNetworkingUploadProgressBlock uploadProgress;
@property (nonatomic, copy) QYKFAWSNetworkingDownloadProgressBlock downloadProgress;

@property (readonly, nonatomic, strong) NSURLSessionTask *task;
@property (readonly, nonatomic, assign, getter = isCancelled) BOOL cancelled;

- (void)assignProperties:(QYKFAWSNetworkingConfiguration *)configuration;
- (void)cancel;
- (void)pause;

@end

@interface QYKFAWSRequest : QYKFAWSModel

@property (nonatomic, copy) QYKFAWSNetworkingUploadProgressBlock uploadProgress;
@property (nonatomic, copy) QYKFAWSNetworkingDownloadProgressBlock downloadProgress;
@property (nonatomic, assign, readonly, getter = isCancelled) BOOL cancelled;
@property (nonatomic, strong) NSURL *downloadingFileURL;

- (QYKFTask *)cancel;
- (QYKFTask *)pause;

@end

@interface QYKFAWSNetworkingRequestInterceptor : NSObject <QYKFAWSNetworkingRequestInterceptor>

@property (nonatomic, readonly) NSString *userAgent;

- (instancetype)initWithUserAgent:(NSString *)userAgent;

@end
