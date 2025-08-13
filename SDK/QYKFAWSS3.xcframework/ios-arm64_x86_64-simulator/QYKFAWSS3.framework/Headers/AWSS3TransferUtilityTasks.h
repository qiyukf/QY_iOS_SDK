//
// Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

NS_ASSUME_NONNULL_BEGIN

@class QYKFAWSS3TransferUtilityTask;
@class QYKFAWSS3TransferUtilityUploadTask;
@class QYKFAWSS3TransferUtilityMultiPartUploadTask;
@class QYKFAWSS3TransferUtilityUploadSubTask;
@class QYKFAWSS3TransferUtilityDownloadTask;
@class QYKFAWSS3TransferUtilityExpression;
@class QYKFAWSS3TransferUtilityUploadExpression;
@class QYKFAWSS3TransferUtilityMultiPartUploadExpression;
@class QYKFAWSS3TransferUtilityDownloadExpression;

typedef NS_ENUM(NSInteger, QYKFAWSS3TransferUtilityTransferStatusType) {
    QYKFAWSS3TransferUtilityTransferStatusUnknown,
    QYKFAWSS3TransferUtilityTransferStatusInProgress,
    QYKFAWSS3TransferUtilityTransferStatusPaused,
    QYKFAWSS3TransferUtilityTransferStatusCompleted,
    QYKFAWSS3TransferUtilityTransferStatusWaiting,
    QYKFAWSS3TransferUtilityTransferStatusError,
    QYKFAWSS3TransferUtilityTransferStatusCancelled
};

/**
 The upload completion handler.
 
 @param task  The upload task object.
 @param error Returns the error object when the download failed.
 */
typedef void (^QYKFAWSS3TransferUtilityUploadCompletionHandlerBlock) (QYKFAWSS3TransferUtilityUploadTask *task,
                                                                  NSError * _Nullable error);

/**
 The upload completion handler for MultiPart.
 
 @param task  The upload task object.
 @param error Returns the error object when the download failed.
 */
typedef void (^QYKFAWSS3TransferUtilityMultiPartUploadCompletionHandlerBlock) (QYKFAWSS3TransferUtilityMultiPartUploadTask *task,
                                                                           NSError * _Nullable error);

/**
 The download completion handler.
 
 @param task     The download task object.
 @param location When downloading an Amazon S3 object to a file, returns a file URL of the returned object. Otherwise, returns `nil`.
 @param data     When downloading an Amazon S3 object as an `NSData`, returns the returned object as an instance of `NSData`. Otherwise, returns `nil`.
 @param error    Returns the error object when the download failed. Returns `nil` on successful downlaod.
 */
typedef void (^QYKFAWSS3TransferUtilityDownloadCompletionHandlerBlock) (QYKFAWSS3TransferUtilityDownloadTask *task,
                                                                    NSURL * _Nullable location,
                                                                    NSData * _Nullable data,
                                                                    NSError * _Nullable error);

/**
 The transfer progress feedback block.
 
 @param task                     The upload task object.
 @param progress                 The progress object.
 
 @note Refer to `- URLSession:task:didSendBodyData:totalBytesSent:totalBytesExpectedToSend:` in `NSURLSessionTaskDelegate` for more details on upload progress and `- URLSession:downloadTask:didWriteData:totalBytesWritten:totalBytesExpectedToWrite:` in `NSURLSessionDownloadDelegate` for more details on download progress.
 */
typedef void (^QYKFAWSS3TransferUtilityProgressBlock) (QYKFAWSS3TransferUtilityTask *task,
                                                   NSProgress *progress);

/**
 The multi part transfer progress feedback block.
 
 @param task                     The upload task object.
 @param progress                 The progress object.
 */
typedef void (^QYKFAWSS3TransferUtilityMultiPartProgressBlock) (QYKFAWSS3TransferUtilityMultiPartUploadTask *task,
                                                            NSProgress *progress);

// added by hzsusu@corp.netease.com
/**
 The transfer error feedback block.
 
 @param task                     The upload task object.
 @param error                   The error object.
 */
typedef void (^QYKFAWSS3TransferUtilityUploadTransferErrorBlock) (QYKFAWSS3TransferUtilityTask *task,
                                                                 NSError *error);

/**
 The multi part transfer error feedback block.

 @param task                     The upload task object.
 @param subTask               The upload sub task object.
 @param error                   The error object.
 */
typedef void (^QYKFAWSS3TransferUtilityMultiPartUploadTransferErrorBlock) (QYKFAWSS3TransferUtilityMultiPartUploadTask *task,
                                                                          QYKFAWSS3TransferUtilityUploadSubTask * _Nullable subTask,                                                                           NSError *error);


#pragma mark - QYKFAWSS3TransferUtilityTasks

/**
 The task object to represent a upload or download task.
 */
@interface QYKFAWSS3TransferUtilityTask : NSObject

/**
 An identifier uniquely identifies the transferID.
 */

@property (readonly) NSString *transferID;

/**
 An identifier uniquely identifies the task within a given `QYKFAWSS3TransferUtility` instance.
 */
@property (readonly) NSUInteger taskIdentifier;

/**
 The Amazon S3 bucket name associated with the transfer.
 */
@property (readonly) NSString *bucket;

/**
 The Amazon S3 object key name associated with the transfer.
 */
@property (readonly) NSString *key;

/**
 The transfer progress.
 */
@property (readonly) NSProgress *progress;

/**
 the status of the Transfer.
 */
@property (readonly) QYKFAWSS3TransferUtilityTransferStatusType status;

/**
 The underlying `NSURLSessionTask` object.
 */
@property (readonly) NSURLSessionTask *sessionTask;

/**
 The HTTP request object.
 */
@property (nullable, readonly) NSURLRequest *request;

/**
 The HTTP response object. May be nil if no response has been received.
 */
@property (nullable, readonly) NSHTTPURLResponse *response;

/**
 Cancels the task.
 */
- (void)cancel;

/**
 Resumes the task, if it is suspended.
 */
- (void)resume;

/**
 Temporarily suspends a task.
 */
- (void)suspend;

@end

/**
 The task object to represent a upload task.
 */
@interface QYKFAWSS3TransferUtilityUploadTask : QYKFAWSS3TransferUtilityTask

/**
 set completion handler for task
 **/

- (void) setCompletionHandler: (QYKFAWSS3TransferUtilityUploadCompletionHandlerBlock)completionHandler;

/**
 Set the progress Block
 */
- (void) setProgressBlock: (QYKFAWSS3TransferUtilityProgressBlock) progressBlock;

// added by hzsusu@corp.netease.com
/**
 Set the transfer error Block
 */
- (void)setTransferErrorBlock:(QYKFAWSS3TransferUtilityUploadTransferErrorBlock) transferErrorBlock;

@end

/**
 The task object to represent a multipart upload task.
 */
@interface QYKFAWSS3TransferUtilityMultiPartUploadTask: QYKFAWSS3TransferUtilityTask

/**
 set completion handler for task
 **/

- (void) setCompletionHandler: (QYKFAWSS3TransferUtilityMultiPartUploadCompletionHandlerBlock)completionHandler;

/**
 Set the progress Block
 */
- (void) setProgressBlock: (QYKFAWSS3TransferUtilityMultiPartProgressBlock) progressBlock;

// added by hzsusu@corp.netease.com
/**
 Set the transfer error Block
 */
- (void)setTransferErrorBlock:(QYKFAWSS3TransferUtilityMultiPartUploadTransferErrorBlock) transferErrorBlock;

@end


/**
 The task object to represent a download task.
 */
@interface QYKFAWSS3TransferUtilityDownloadTask : QYKFAWSS3TransferUtilityTask
/**
 set completion handler for task
 **/
- (void) setCompletionHandler: (QYKFAWSS3TransferUtilityDownloadCompletionHandlerBlock)completionHandler;

/**
 Set the progress Block
 */
- (void) setProgressBlock: (QYKFAWSS3TransferUtilityProgressBlock) progressBlock;

@end

@interface QYKFAWSS3TransferUtilityUploadSubTask: NSObject
@end

#pragma mark - QYKFAWSS3TransferUtilityExpressions

/**
 The expression object for configuring a upload or download task.
 */
@interface QYKFAWSS3TransferUtilityExpression : NSObject

/**
 This NSDictionary can contains additional request headers to be included in the pre-signed URL. Default is emtpy.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *requestHeaders;

/**
 This NSDictionary can contains additional request parameters to be included in the pre-signed URL. Adding additional request parameters enables more advanced pre-signed URLs, such as accessing Amazon S3's torrent resource for an object, or for specifying a version ID when accessing an object. Default is emtpy.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *requestParameters;

/**
 The progress feedback block.
 */
@property (copy, nonatomic, nullable) QYKFAWSS3TransferUtilityProgressBlock progressBlock;

/**
 Set an additional request header to be included in the pre-signed URL.
 
 @param value The value of the request parameter being added. Set to nil if parameter doesn't contains value.
 @param requestHeader The name of the request header.
 */
- (void)setValue:(nullable NSString *)value forRequestHeader:(NSString *)requestHeader;

/**
 Set an additional request parameter to be included in the pre-signed URL. Adding additional request parameters enables more advanced pre-signed URLs, such as accessing Amazon S3's torrent resource for an object, or for specifying a version ID when accessing an object.
 
 @param value The value of the request parameter being added. Set to nil if parameter doesn't contains value.
 @param requestParameter The name of the request parameter, as it appears in the URL's query string (e.g. QYKFAWSS3PresignedURLVersionID).
 */
- (void)setValue:(nullable NSString *)value forRequestParameter:(NSString *)requestParameter;

@end

/**
 The expression object for configuring a upload task.
 */
@interface QYKFAWSS3TransferUtilityUploadExpression : QYKFAWSS3TransferUtilityExpression

/**
 The upload request header for `Content-MD5`.
 */
@property (nonatomic, nullable) NSString *contentMD5;

@end


/**
 The expression object for configuring a Multipart upload task.
 */
@interface QYKFAWSS3TransferUtilityMultiPartUploadExpression : NSObject

/**
 This NSDictionary can contains additional request headers to be included in the pre-signed URL. Default is emtpy.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *requestHeaders;

/**
 This NSDictionary can contains additional request parameters to be included in the pre-signed URL. Adding additional request parameters enables more advanced pre-signed URLs, such as accessing Amazon S3's torrent resource for an object, or for specifying a version ID when accessing an object. Default is emtpy.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *requestParameters;

/**
 The progress feedback block.
 */
@property (copy, nonatomic, nullable) QYKFAWSS3TransferUtilityMultiPartProgressBlock progressBlock;

/**
 If YES, generate and add `Content-MD5` headers to the chunk upload requests. If NO, don't (default).
 */
@property (nonatomic) BOOL useContentMD5;

/**
 Set an additional request header to be included in the pre-signed URL.
 
 
 @param value The value of the request parameter being added. Set to nil if parameter doesn't contains value.
 @param requestHeader The name of the request header.
 */
- (void)setValue:(nullable NSString *)value forRequestHeader:(NSString *)requestHeader;

/**
 Set an additional request parameter to be included in the pre-signed URL. Adding additional request parameters enables more advanced pre-signed URLs, such as accessing Amazon S3's torrent resource for an object, or for specifying a version ID when accessing an object.
 
 @param value The value of the request parameter being added. Set to nil if parameter doesn't contains value.
 @param requestParameter The name of the request parameter, as it appears in the URL's query string (e.g. QYKFAWSS3PresignedURLVersionID).
 */
- (void)setValue:(nullable NSString *)value forRequestParameter:(NSString *)requestParameter;



@end

/**
 The expression object for configuring a download task.
 */
@interface QYKFAWSS3TransferUtilityDownloadExpression : QYKFAWSS3TransferUtilityExpression

@end

// added by hzsusu@corp.netease.com
/**
 The timing handler.
 
 @return Returns opaque timing object.
  */
typedef id _Nonnull (^QYKFAWSS3TransferUtilityTaskTimingBlock)(void);

/**
 The timing class for  tasks.
 */
@interface QYKFAWSS3TransferUtilityTaskTiming : NSObject

/**
 The timing hander
 */
@property (class, strong) QYKFAWSS3TransferUtilityTaskTimingBlock timingBlock;

@end

NS_ASSUME_NONNULL_END

