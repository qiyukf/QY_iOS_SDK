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
#import <QYKFAWSCore/AWSNetworking.h>
#import <QYKFAWSCore/AWSModel.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const QYKFAWSS3ErrorDomain;

typedef NS_ENUM(NSInteger, QYKFAWSS3ErrorType) {
    QYKFAWSS3ErrorUnknown,
    QYKFAWSS3ErrorBucketAlreadyExists,
    QYKFAWSS3ErrorBucketAlreadyOwnedByYou,
    QYKFAWSS3ErrorNoSuchBucket,
    QYKFAWSS3ErrorNoSuchKey,
    QYKFAWSS3ErrorNoSuchUpload,
    QYKFAWSS3ErrorObjectAlreadyInActiveTier,
    QYKFAWSS3ErrorObjectNotInActiveTier,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3BucketAccessStyle) {
    QYKFAWSS3BucketAccessStyleVirtualHosted,
    QYKFAWSS3BucketAccessStylePath
};

typedef NS_ENUM(NSInteger, QYKFAWSS3EncodingType) {
    QYKFAWSS3EncodingTypeUnknown,
    QYKFAWSS3EncodingTypeURL,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3JSONType) {
    QYKFAWSS3JSONTypeUnknown,
    QYKFAWSS3JSONTypeDocument,
    QYKFAWSS3JSONTypeLines,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3ObjectCannedACL) {
    QYKFAWSS3ObjectCannedACLUnknown,
    QYKFAWSS3ObjectCannedACLPrivate,
    QYKFAWSS3ObjectCannedACLPublicRead,
    QYKFAWSS3ObjectCannedACLPublicReadWrite,
    QYKFAWSS3ObjectCannedACLAuthenticatedRead,
    QYKFAWSS3ObjectCannedACLAwsExecRead,
    QYKFAWSS3ObjectCannedACLBucketOwnerRead,
    QYKFAWSS3ObjectCannedACLBucketOwnerFullControl,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3ObjectLockLegalHoldStatus) {
    QYKFAWSS3ObjectLockLegalHoldStatusUnknown,
    QYKFAWSS3ObjectLockLegalHoldStatusOn,
    QYKFAWSS3ObjectLockLegalHoldStatusOff,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3ObjectLockMode) {
    QYKFAWSS3ObjectLockModeUnknown,
    QYKFAWSS3ObjectLockModeGovernance,
    QYKFAWSS3ObjectLockModeCompliance,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3ObjectStorageClass) {
    QYKFAWSS3ObjectStorageClassUnknown,
    QYKFAWSS3ObjectStorageClassStandard,
    QYKFAWSS3ObjectStorageClassReducedRedundancy,
    QYKFAWSS3ObjectStorageClassGlacier,
    QYKFAWSS3ObjectStorageClassStandardIa,
    QYKFAWSS3ObjectStorageClassOnezoneIa,
    QYKFAWSS3ObjectStorageClassIntelligentTiering,
    QYKFAWSS3ObjectStorageClassDeepArchive,
    QYKFAWSS3ObjectStorageClassOutposts,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3ReplicationStatus) {
    QYKFAWSS3ReplicationStatusUnknown,
    QYKFAWSS3ReplicationStatusComplete,
    QYKFAWSS3ReplicationStatusPending,
    QYKFAWSS3ReplicationStatusFailed,
    QYKFAWSS3ReplicationStatusReplica,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3RequestCharged) {
    QYKFAWSS3RequestChargedUnknown,
    QYKFAWSS3RequestChargedRequester,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3RequestPayer) {
    QYKFAWSS3RequestPayerUnknown,
    QYKFAWSS3RequestPayerRequester,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3ServerSideEncryption) {
    QYKFAWSS3ServerSideEncryptionUnknown,
    QYKFAWSS3ServerSideEncryptionAES256,
    QYKFAWSS3ServerSideEncryptionAwsKms,
};

typedef NS_ENUM(NSInteger, QYKFAWSS3StorageClass) {
    QYKFAWSS3StorageClassUnknown,
    QYKFAWSS3StorageClassStandard,
    QYKFAWSS3StorageClassReducedRedundancy,
    QYKFAWSS3StorageClassStandardIa,
    QYKFAWSS3StorageClassOnezoneIa,
    QYKFAWSS3StorageClassIntelligentTiering,
    QYKFAWSS3StorageClassGlacier,
    QYKFAWSS3StorageClassDeepArchive,
    QYKFAWSS3StorageClassOutposts,
};

@class QYKFAWSS3AbortIncompleteMultipartUpload;
@class QYKFAWSS3AbortMultipartUploadOutput;
@class QYKFAWSS3AbortMultipartUploadRequest;
@class QYKFAWSS3CommonPrefix;
@class QYKFAWSS3CompleteMultipartUploadOutput;
@class QYKFAWSS3CompleteMultipartUploadRequest;
@class QYKFAWSS3CompletedMultipartUpload;
@class QYKFAWSS3CompletedPart;
@class QYKFAWSS3ReplicatePartResult;
@class QYKFAWSS3CreateMultipartUploadOutput;
@class QYKFAWSS3CreateMultipartUploadRequest;
@class QYKFAWSS3DeleteObjectOutput;
@class QYKFAWSS3DeleteObjectRequest;
@class QYKFAWSS3Error;
@class QYKFAWSS3ErrorDocument;
@class QYKFAWSS3GetObjectOutput;
@class QYKFAWSS3GetObjectRequest;
@class QYKFAWSS3HeadObjectOutput;
@class QYKFAWSS3HeadObjectRequest;
@class QYKFAWSS3Initiator;
@class QYKFAWSS3JSONInput;
@class QYKFAWSS3JSONOutput;
@class QYKFAWSS3ListMultipartUploadsOutput;
@class QYKFAWSS3ListMultipartUploadsRequest;
@class QYKFAWSS3ListPartsOutput;
@class QYKFAWSS3ListPartsRequest;
@class QYKFAWSS3MultipartUpload;
@class QYKFAWSS3Object;
@class QYKFAWSS3Owner;
@class QYKFAWSS3Part;
@class QYKFAWSS3PutObjectOutput;
@class QYKFAWSS3PutObjectRequest;
@class QYKFAWSS3UploadPartCopyOutput;
@class QYKFAWSS3UploadPartCopyRequest;
@class QYKFAWSS3UploadPartOutput;
@class QYKFAWSS3UploadPartRequest;

/**
 <p>Specifies the days since the initiation of an incomplete multipart upload that Amazon S3 will wait before permanently removing all parts of the upload. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config"> Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@interface QYKFAWSS3AbortIncompleteMultipartUpload : QYKFAWSModel


/**
 <p>Specifies the number of days after which Amazon S3 aborts an incomplete multipart upload.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable daysAfterInitiation;

@end

/**
 
 */
@interface QYKFAWSS3AbortMultipartUploadOutput : QYKFAWSModel


/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

@end

/**
 
 */
@interface QYKFAWSS3AbortMultipartUploadRequest : QYKFAWSRequest


/**
 <p>The bucket name to which the upload was taking place. </p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Key of the object for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Upload ID that identifies the multipart upload.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

/**
 <p>Container for all (if there are any) keys between Prefix and the next occurrence of the string specified by a delimiter. CommonPrefixes lists keys that act like subdirectories in the directory specified by Prefix. For example, if the prefix is notes/ and the delimiter is a slash (/) as in notes/summer/july, the common prefix is notes/summer/. </p>
 */
@interface QYKFAWSS3CommonPrefix : QYKFAWSModel


/**
 <p>Container for the specified common prefix.</p>
 */
@property (nonatomic, strong) NSString * _Nullable prefix;

@end

/**
 
 */
@interface QYKFAWSS3CompleteMultipartUploadOutput : QYKFAWSModel


/**
 <p>The name of the bucket that contains the newly created object.</p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Entity tag that identifies the newly created object's data. Objects with different object data will have different entity tags. The entity tag is an opaque string. The entity tag may or may not be an MD5 digest of the object data. If the entity tag is not an MD5 digest of the object data, it will contain one or more nonhexadecimal characters and/or will consist of less than 32 or more than 32 hexadecimal digits.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>If the object expiration is configured, this will contain the expiration date (expiry-date) and rule ID (rule-id). The value of rule-id is URL encoded.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expiration;

/**
 <p>The object key of the newly created object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>The URI that identifies the newly created object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable location;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>If you specified server-side encryption either with an Amazon S3-managed encryption key or an AWS KMS customer master key (CMK) in your initiate multipart upload request, the response includes this header. It confirms the encryption algorithm that Amazon S3 used to encrypt the object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

/**
 <p>Version ID of the newly created object, in case the bucket has versioning turned on.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

@end

/**
 
 */
@interface QYKFAWSS3CompleteMultipartUploadRequest : QYKFAWSRequest


/**
 <p>Name of the bucket to which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Object key for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>The container for the multipart upload request information.</p>
 */
@property (nonatomic, strong) QYKFAWSS3CompletedMultipartUpload * _Nullable multipartUpload;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>ID for the initiated multipart upload.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

/**
 <p>The container for the completed multipart upload details.</p>
 */
@interface QYKFAWSS3CompletedMultipartUpload : QYKFAWSModel


/**
 <p>Array of CompletedPart data types.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSS3CompletedPart *> * _Nullable parts;

@end

/**
 <p>Details of the parts that were uploaded.</p>
 */
@interface QYKFAWSS3CompletedPart : QYKFAWSModel


/**
 <p>Entity tag returned when the part was uploaded.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>Part number that identifies the part. This is a positive integer between 1 and 10,000.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumber;

@end

/**
 <p>Container for all response elements.</p>
 */
@interface QYKFAWSS3ReplicatePartResult : QYKFAWSModel


/**
 <p>Entity tag of the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>Date and time at which the object was uploaded.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable lastModified;

@end

/**
 
 */
@interface QYKFAWSS3CreateMultipartUploadOutput : QYKFAWSModel


/**
 <p>If the bucket has a lifecycle rule configured with an action to abort incomplete multipart uploads and the prefix in the lifecycle rule matches the object name in the request, the response includes this header. The header indicates when the initiated multipart upload becomes eligible for an abort operation. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config"> Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a>.</p><p>The response also includes the <code>x-amz-abort-rule-id</code> header that provides the ID of the lifecycle configuration rule that defines this action.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable abortDate;

/**
 <p>This header is returned along with the <code>x-amz-abort-date</code> header. It identifies the applicable lifecycle configuration rule that defines the action to abort incomplete multipart uploads.</p>
 */
@property (nonatomic, strong) NSString * _Nullable abortRuleId;

/**
 <p>The name of the bucket to which the multipart upload was initiated. </p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Object key for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>If present, specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSEncryptionContext;

/**
 <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

/**
 <p>ID for the initiated multipart upload.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

/**
 
 */
@interface QYKFAWSS3CreateMultipartUploadRequest : QYKFAWSRequest


/**
 <p>The canned ACL to apply to the object.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectCannedACL ACL;

/**
 <p>The name of the bucket to which to initiate the upload</p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Specifies caching behavior along the request/reply chain.</p>
 */
@property (nonatomic, strong) NSString * _Nullable cacheControl;

/**
 <p>Specifies presentational information for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentDisposition;

/**
 <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentEncoding;

/**
 <p>The language the content is in.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentLanguage;

/**
 <p>A standard MIME type describing the format of the object data.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentType;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>The date and time at which the object is no longer cacheable.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable expires;

/**
 <p>Gives the grantee READ, READ_ACP, and WRITE_ACP permissions on the object.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantFullControl;

/**
 <p>Allows grantee to read the object data and its metadata.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantRead;

/**
 <p>Allows grantee to read the object ACL.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantReadACP;

/**
 <p>Allows grantee to write the ACL for the applicable object.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantWriteACP;

/**
 <p>Object key for which the multipart upload is to be initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>A map of metadata to store with the object in S3.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable metadata;

/**
 <p>Specifies whether you want to apply a Legal Hold to the uploaded object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockLegalHoldStatus objectLockLegalHoldStatus;

/**
 <p>Specifies the Object Lock mode that you want to apply to the uploaded object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockMode objectLockMode;

/**
 <p>Specifies the date and time when you want the Object Lock to expire.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable objectLockRetainUntilDate;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKey;

/**
 <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>Specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSEncryptionContext;

/**
 <p>Specifies the ID of the symmetric customer managed AWS KMS CMK to use for object encryption. All GET and PUT requests for an object protected by AWS KMS will fail if not made via SSL or using SigV4. For information about configuring using any of the officially supported AWS SDKs and AWS CLI, see <a href="https://docs.aws.amazon.com/http:/docs.aws.amazon.com/AmazonS3/latest/dev/UsingAWSSDK.html#specify-signature-version">Specifying the Signature Version in Request Authentication</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

/**
 <p>By default, Amazon S3 uses the STANDARD Storage Class to store newly created objects. The STANDARD storage class provides high durability and high availability. Depending on performance needs, you can specify a different Storage Class. Amazon S3 on Outposts only uses the OUTPOSTS Storage Class. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a> in the <i>Amazon S3 Service Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3StorageClass storageClass;

/**
 <p>The tag-set for the object. The tag-set must be encoded as URL Query parameters.</p>
 */
@property (nonatomic, strong) NSString * _Nullable tagging;

/**
 <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata.</p>
 */
@property (nonatomic, strong) NSString * _Nullable websiteRedirectLocation;

@end

/**
 
 */
@interface QYKFAWSS3DeleteObjectOutput : QYKFAWSModel


/**
 <p>Specifies whether the versioned object that was permanently deleted was (true) or was not (false) a delete marker.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable deleteMarker;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>Returns the version ID of the delete marker created as a result of the DELETE operation.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

@end

/**
 
 */
@interface QYKFAWSS3DeleteObjectRequest : QYKFAWSRequest


/**
 <p>The bucket name of the bucket containing the object. </p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Indicates whether S3 Object Lock should bypass Governance-mode restrictions to process this operation.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable bypassGovernanceRetention;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Key name of the object to delete.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>The concatenation of the authentication device's serial number, a space, and the value that is displayed on your authentication device. Required to permanently delete a versioned object if versioning is configured with MFA delete enabled.</p>
 */
@property (nonatomic, strong) NSString * _Nullable MFA;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>VersionId used to reference a specific version of the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

@end

/**
 <p>Container for all error elements.</p>
 */
@interface QYKFAWSS3Error : QYKFAWSModel


/**
 <p>The error code is a string that uniquely identifies an error condition. It is meant to be read and understood by programs that detect and handle errors by type. </p><p class="title"><b>Amazon S3 error codes</b></p><ul><li><ul><li><p><i>Code:</i> AccessDenied </p></li><li><p><i>Description:</i> Access Denied</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> AccountProblem</p></li><li><p><i>Description:</i> There is a problem with your AWS account that prevents the operation from completing successfully. Contact AWS Support for further assistance.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> AllAccessDisabled</p></li><li><p><i>Description:</i> All access to this Amazon S3 resource has been disabled. Contact AWS Support for further assistance.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> AmbiguousGrantByEmailAddress</p></li><li><p><i>Description:</i> The email address you provided is associated with more than one account.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> AuthorizationHeaderMalformed</p></li><li><p><i>Description:</i> The authorization header you provided is invalid.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>HTTP Status Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> BadDigest</p></li><li><p><i>Description:</i> The Content-MD5 you specified did not match what we received.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> BucketAlreadyExists</p></li><li><p><i>Description:</i> The requested bucket name is not available. The bucket namespace is shared by all users of the system. Please select a different name and try again.</p></li><li><p><i>HTTP Status Code:</i> 409 Conflict</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> BucketAlreadyOwnedByYou</p></li><li><p><i>Description:</i> The bucket you tried to create already exists, and you own it. Amazon S3 returns this error in all AWS Regions except in the North Virginia Region. For legacy compatibility, if you re-create an existing bucket that you already own in the North Virginia Region, Amazon S3 returns 200 OK and resets the bucket access control lists (ACLs).</p></li><li><p><i>Code:</i> 409 Conflict (in all Regions except the North Virginia Region) </p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> BucketNotEmpty</p></li><li><p><i>Description:</i> The bucket you tried to delete is not empty.</p></li><li><p><i>HTTP Status Code:</i> 409 Conflict</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> CredentialsNotSupported</p></li><li><p><i>Description:</i> This request does not support credentials.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> CrossLocationLoggingProhibited</p></li><li><p><i>Description:</i> Cross-location logging not allowed. Buckets in one geographic location cannot log information to a bucket in another location.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> EntityTooSmall</p></li><li><p><i>Description:</i> Your proposed upload is smaller than the minimum allowed object size.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> EntityTooLarge</p></li><li><p><i>Description:</i> Your proposed upload exceeds the maximum allowed object size.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> ExpiredToken</p></li><li><p><i>Description:</i> The provided token has expired.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> IllegalVersioningConfigurationException </p></li><li><p><i>Description:</i> Indicates that the versioning configuration specified in the request is invalid.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> IncompleteBody</p></li><li><p><i>Description:</i> You did not provide the number of bytes specified by the Content-Length HTTP header</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> IncorrectNumberOfFilesInPostRequest</p></li><li><p><i>Description:</i> POST requires exactly one file upload per request.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InlineDataTooLarge</p></li><li><p><i>Description:</i> Inline data exceeds the maximum allowed size.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InternalError</p></li><li><p><i>Description:</i> We encountered an internal error. Please try again.</p></li><li><p><i>HTTP Status Code:</i> 500 Internal Server Error</p></li><li><p><i>SOAP Fault Code Prefix:</i> Server</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidAccessKeyId</p></li><li><p><i>Description:</i> The AWS access key ID you provided does not exist in our records.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidAddressingHeader</p></li><li><p><i>Description:</i> You must specify the Anonymous role.</p></li><li><p><i>HTTP Status Code:</i> N/A</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidArgument</p></li><li><p><i>Description:</i> Invalid Argument</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidBucketName</p></li><li><p><i>Description:</i> The specified bucket is not valid.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidBucketState</p></li><li><p><i>Description:</i> The request is not valid with the current state of the bucket.</p></li><li><p><i>HTTP Status Code:</i> 409 Conflict</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidDigest</p></li><li><p><i>Description:</i> The Content-MD5 you specified is not valid.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidEncryptionAlgorithmError</p></li><li><p><i>Description:</i> The encryption request you specified is not valid. The valid value is AES256.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidLocationConstraint</p></li><li><p><i>Description:</i> The specified location constraint is not valid. For more information about Regions, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingBucket.html#access-bucket-intro">How to Select a Region for Your Buckets</a>. </p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidObjectState</p></li><li><p><i>Description:</i> The operation is not valid for the current state of the object.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidPart</p></li><li><p><i>Description:</i> One or more of the specified parts could not be found. The part might not have been uploaded, or the specified entity tag might not have matched the part's entity tag.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidPartOrder</p></li><li><p><i>Description:</i> The list of parts was not in ascending order. Parts list must be specified in order by part number.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidPayer</p></li><li><p><i>Description:</i> All access to this object has been disabled. Please contact AWS Support for further assistance.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidPolicyDocument</p></li><li><p><i>Description:</i> The content of the form does not meet the conditions specified in the policy document.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRange</p></li><li><p><i>Description:</i> The requested range cannot be satisfied.</p></li><li><p><i>HTTP Status Code:</i> 416 Requested Range Not Satisfiable</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Please use AWS4-HMAC-SHA256.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> SOAP requests must be made over an HTTPS connection.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Amazon S3 Transfer Acceleration is not supported for buckets with non-DNS compliant names.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Amazon S3 Transfer Acceleration is not supported for buckets with periods (.) in their names.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Amazon S3 Transfer Accelerate endpoint only supports virtual style requests.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Amazon S3 Transfer Accelerate is not configured on this bucket.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Amazon S3 Transfer Accelerate is disabled on this bucket.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Amazon S3 Transfer Acceleration is not supported on this bucket. Contact AWS Support for more information.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidRequest</p></li><li><p><i>Description:</i> Amazon S3 Transfer Acceleration cannot be enabled on this bucket. Contact AWS Support for more information.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>Code:</i> N/A</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidSecurity</p></li><li><p><i>Description:</i> The provided security credentials are not valid.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidSOAPRequest</p></li><li><p><i>Description:</i> The SOAP request body is invalid.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidStorageClass</p></li><li><p><i>Description:</i> The storage class you specified is not valid.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidTargetBucketForLogging</p></li><li><p><i>Description:</i> The target bucket for logging does not exist, is not owned by you, or does not have the appropriate grants for the log-delivery group. </p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidToken</p></li><li><p><i>Description:</i> The provided token is malformed or otherwise invalid.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> InvalidURI</p></li><li><p><i>Description:</i> Couldn't parse the specified URI.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> KeyTooLongError</p></li><li><p><i>Description:</i> Your key is too long.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MalformedACLError</p></li><li><p><i>Description:</i> The XML you provided was not well-formed or did not validate against our published schema.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MalformedPOSTRequest </p></li><li><p><i>Description:</i> The body of your POST request is not well-formed multipart/form-data.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MalformedXML</p></li><li><p><i>Description:</i> This happens when the user sends malformed XML (XML that doesn't conform to the published XSD) for the configuration. The error message is, "The XML you provided was not well-formed or did not validate against our published schema." </p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MaxMessageLengthExceeded</p></li><li><p><i>Description:</i> Your request was too big.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MaxPostPreDataLengthExceededError</p></li><li><p><i>Description:</i> Your POST request fields preceding the upload file were too large.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MetadataTooLarge</p></li><li><p><i>Description:</i> Your metadata headers exceed the maximum allowed metadata size.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MethodNotAllowed</p></li><li><p><i>Description:</i> The specified method is not allowed against this resource.</p></li><li><p><i>HTTP Status Code:</i> 405 Method Not Allowed</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MissingAttachment</p></li><li><p><i>Description:</i> A SOAP attachment was expected, but none were found.</p></li><li><p><i>HTTP Status Code:</i> N/A</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MissingContentLength</p></li><li><p><i>Description:</i> You must provide the Content-Length HTTP header.</p></li><li><p><i>HTTP Status Code:</i> 411 Length Required</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MissingRequestBodyError</p></li><li><p><i>Description:</i> This happens when the user sends an empty XML document as a request. The error message is, "Request body is empty." </p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MissingSecurityElement</p></li><li><p><i>Description:</i> The SOAP 1.1 request is missing a security element.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> MissingSecurityHeader</p></li><li><p><i>Description:</i> Your request is missing a required header.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NoLoggingStatusForKey</p></li><li><p><i>Description:</i> There is no such thing as a logging status subresource for a key.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NoSuchBucket</p></li><li><p><i>Description:</i> The specified bucket does not exist.</p></li><li><p><i>HTTP Status Code:</i> 404 Not Found</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NoSuchBucketPolicy</p></li><li><p><i>Description:</i> The specified bucket does not have a bucket policy.</p></li><li><p><i>HTTP Status Code:</i> 404 Not Found</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NoSuchKey</p></li><li><p><i>Description:</i> The specified key does not exist.</p></li><li><p><i>HTTP Status Code:</i> 404 Not Found</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NoSuchLifecycleConfiguration</p></li><li><p><i>Description:</i> The lifecycle configuration does not exist. </p></li><li><p><i>HTTP Status Code:</i> 404 Not Found</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NoSuchUpload</p></li><li><p><i>Description:</i> The specified multipart upload does not exist. The upload ID might be invalid, or the multipart upload might have been aborted or completed.</p></li><li><p><i>HTTP Status Code:</i> 404 Not Found</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NoSuchVersion </p></li><li><p><i>Description:</i> Indicates that the version ID specified in the request does not match an existing version.</p></li><li><p><i>HTTP Status Code:</i> 404 Not Found</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> NotImplemented</p></li><li><p><i>Description:</i> A header you provided implies functionality that is not implemented.</p></li><li><p><i>HTTP Status Code:</i> 501 Not Implemented</p></li><li><p><i>SOAP Fault Code Prefix:</i> Server</p></li></ul></li><li><ul><li><p><i>Code:</i> NotSignedUp</p></li><li><p><i>Description:</i> Your account is not signed up for the Amazon S3 service. You must sign up before you can use Amazon S3. You can sign up at the following URL: https://aws.amazon.com/s3</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> OperationAborted</p></li><li><p><i>Description:</i> A conflicting conditional operation is currently in progress against this resource. Try again.</p></li><li><p><i>HTTP Status Code:</i> 409 Conflict</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> PermanentRedirect</p></li><li><p><i>Description:</i> The bucket you are attempting to access must be addressed using the specified endpoint. Send all future requests to this endpoint.</p></li><li><p><i>HTTP Status Code:</i> 301 Moved Permanently</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> PreconditionFailed</p></li><li><p><i>Description:</i> At least one of the preconditions you specified did not hold.</p></li><li><p><i>HTTP Status Code:</i> 412 Precondition Failed</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> Redirect</p></li><li><p><i>Description:</i> Temporary redirect.</p></li><li><p><i>HTTP Status Code:</i> 307 Moved Temporarily</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> RestoreAlreadyInProgress</p></li><li><p><i>Description:</i> Object restore is already in progress.</p></li><li><p><i>HTTP Status Code:</i> 409 Conflict</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> RequestIsNotMultiPartContent</p></li><li><p><i>Description:</i> Bucket POST must be of the enclosure-type multipart/form-data.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> RequestTimeout</p></li><li><p><i>Description:</i> Your socket connection to the server was not read from or written to within the timeout period.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> RequestTimeTooSkewed</p></li><li><p><i>Description:</i> The difference between the request time and the server's time is too large.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> RequestTorrentOfBucketError</p></li><li><p><i>Description:</i> Requesting the torrent file of a bucket is not permitted.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> SignatureDoesNotMatch</p></li><li><p><i>Description:</i> The request signature we calculated does not match the signature you provided. Check your AWS secret access key and signing method. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/RESTAuthentication.html">REST Authentication</a> and <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/SOAPAuthentication.html">SOAP Authentication</a> for details.</p></li><li><p><i>HTTP Status Code:</i> 403 Forbidden</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> ServiceUnavailable</p></li><li><p><i>Description:</i> Reduce your request rate.</p></li><li><p><i>HTTP Status Code:</i> 503 Service Unavailable</p></li><li><p><i>SOAP Fault Code Prefix:</i> Server</p></li></ul></li><li><ul><li><p><i>Code:</i> SlowDown</p></li><li><p><i>Description:</i> Reduce your request rate.</p></li><li><p><i>HTTP Status Code:</i> 503 Slow Down</p></li><li><p><i>SOAP Fault Code Prefix:</i> Server</p></li></ul></li><li><ul><li><p><i>Code:</i> TemporaryRedirect</p></li><li><p><i>Description:</i> You are being redirected to the bucket while DNS updates.</p></li><li><p><i>HTTP Status Code:</i> 307 Moved Temporarily</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> TokenRefreshRequired</p></li><li><p><i>Description:</i> The provided token must be refreshed.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> TooManyBuckets</p></li><li><p><i>Description:</i> You have attempted to create more buckets than allowed.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> UnexpectedContent</p></li><li><p><i>Description:</i> This request does not support content.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> UnresolvableGrantByEmailAddress</p></li><li><p><i>Description:</i> The email address you provided does not match any account on record.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li><li><ul><li><p><i>Code:</i> UserKeyMustBeSpecified</p></li><li><p><i>Description:</i> The bucket POST must contain the specified field name. If it is specified, check the order of the fields.</p></li><li><p><i>HTTP Status Code:</i> 400 Bad Request</p></li><li><p><i>SOAP Fault Code Prefix:</i> Client</p></li></ul></li></ul><p/>
 */
@property (nonatomic, strong) NSString * _Nullable code;

/**
 <p>The error key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>The error message contains a generic description of the error condition in English. It is intended for a human audience. Simple programs display the message directly to the end user if they encounter an error condition they don't know how or don't care to handle. Sophisticated programs with more exhaustive error handling and proper internationalization are more likely to ignore the error message.</p>
 */
@property (nonatomic, strong) NSString * _Nullable message;

/**
 <p>The version ID of the error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

@end

/**
 <p>The error information.</p>
 Required parameters: [Key]
 */
@interface QYKFAWSS3ErrorDocument : QYKFAWSModel


/**
 <p>The object key name to use when a 4XX class error occurs.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

@end

/**
 
 */
@interface QYKFAWSS3GetObjectOutput : QYKFAWSModel


/**
 <p>Indicates that a range of bytes was specified.</p>
 */
@property (nonatomic, strong) NSString * _Nullable acceptRanges;

/**
 <p>Object data.</p>
 */
@property (nonatomic, strong) id _Nullable body;

/**
 <p>Specifies caching behavior along the request/reply chain.</p>
 */
@property (nonatomic, strong) NSString * _Nullable cacheControl;

/**
 <p>Specifies presentational information for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentDisposition;

/**
 <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentEncoding;

/**
 <p>The language the content is in.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentLanguage;

/**
 <p>Size of the body in bytes.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
 <p>The portion of the object returned in the response.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentRange;

/**
 <p>A standard MIME type describing the format of the object data.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentType;

/**
 <p>Specifies whether the object retrieved was (true) or was not (false) a Delete Marker. If false, this response header does not appear in the response.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable deleteMarker;

/**
 <p>An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>If the object expiration is configured (see PUT Bucket lifecycle), the response includes this header. It includes the expiry-date and rule-id key-value pairs providing object expiration information. The value of the rule-id is URL encoded.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expiration;

/**
 <p>The date and time at which the object is no longer cacheable.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable expires;

/**
 <p>Last modified date of the object</p>
 */
@property (nonatomic, strong) NSDate * _Nullable lastModified;

/**
 <p>A map of metadata to store with the object in S3.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable metadata;

/**
 <p>This is set to the number of metadata entries not returned in <code>x-amz-meta</code> headers. This can happen if you create metadata using an API like SOAP that supports more flexible metadata than the REST API. For example, using SOAP, you can create metadata whose values are not legal HTTP headers.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable missingMeta;

/**
 <p>Indicates whether this object has an active legal hold. This field is only returned if you have permission to view an object's legal hold status. </p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockLegalHoldStatus objectLockLegalHoldStatus;

/**
 <p>The Object Lock mode currently in place for this object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockMode objectLockMode;

/**
 <p>The date and time when this object's Object Lock will expire.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable objectLockRetainUntilDate;

/**
 <p>The count of parts this object has.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partsCount;

/**
 <p>Amazon S3 can return this if your request involves a bucket that is either a source or destination in a replication rule.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ReplicationStatus replicationStatus;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>Provides information about object restoration operation and expiration time of the restored object copy.</p>
 */
@property (nonatomic, strong) NSString * _Nullable restore;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

/**
 <p>Provides storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p>
 */
@property (nonatomic, assign) QYKFAWSS3StorageClass storageClass;

/**
 <p>The number of tags, if any, on the object.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable tagCount;

/**
 <p>Version of the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

/**
 <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata.</p>
 */
@property (nonatomic, strong) NSString * _Nullable websiteRedirectLocation;

@end

/**
 
 */
@interface QYKFAWSS3GetObjectRequest : QYKFAWSRequest


/**
 <p>The bucket name containing the object. </p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Return the object only if its entity tag (ETag) is the same as the one specified, otherwise return a 412 (precondition failed).</p>
 */
@property (nonatomic, strong) NSString * _Nullable ifMatch;

/**
 <p>Return the object only if it has been modified since the specified time, otherwise return a 304 (not modified).</p>
 */
@property (nonatomic, strong) NSDate * _Nullable ifModifiedSince;

/**
 <p>Return the object only if its entity tag (ETag) is different from the one specified, otherwise return a 304 (not modified).</p>
 */
@property (nonatomic, strong) NSString * _Nullable ifNoneMatch;

/**
 <p>Return the object only if it has not been modified since the specified time, otherwise return a 412 (precondition failed).</p>
 */
@property (nonatomic, strong) NSDate * _Nullable ifUnmodifiedSince;

/**
 <p>Key of the object to get.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Part number of the object being read. This is a positive integer between 1 and 10,000. Effectively performs a 'ranged' GET request for the part specified. Useful for downloading just a part of an object.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumber;

/**
 <p>Downloads the specified range bytes of an object. For more information about the HTTP Range header, see <a href="https://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35">https://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35</a>.</p><note><p>Amazon S3 doesn't support retrieving multiple ranges of data per <code>GET</code> request.</p></note>
 */
@property (nonatomic, strong) NSString * _Nullable range;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Sets the <code>Cache-Control</code> header of the response.</p>
 */
@property (nonatomic, strong) NSString * _Nullable responseCacheControl;

/**
 <p>Sets the <code>Content-Disposition</code> header of the response</p>
 */
@property (nonatomic, strong) NSString * _Nullable responseContentDisposition;

/**
 <p>Sets the <code>Content-Encoding</code> header of the response.</p>
 */
@property (nonatomic, strong) NSString * _Nullable responseContentEncoding;

/**
 <p>Sets the <code>Content-Language</code> header of the response.</p>
 */
@property (nonatomic, strong) NSString * _Nullable responseContentLanguage;

/**
 <p>Sets the <code>Content-Type</code> header of the response.</p>
 */
@property (nonatomic, strong) NSString * _Nullable responseContentType;

/**
 <p>Sets the <code>Expires</code> header of the response.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable responseExpires;

/**
 <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKey;

/**
 <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>VersionId used to reference a specific version of the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

@end

/**
 
 */
@interface QYKFAWSS3HeadObjectOutput : QYKFAWSModel


/**
 <p>Indicates that a range of bytes was specified.</p>
 */
@property (nonatomic, strong) NSString * _Nullable acceptRanges;

/**
 <p>Specifies caching behavior along the request/reply chain.</p>
 */
@property (nonatomic, strong) NSString * _Nullable cacheControl;

/**
 <p>Specifies presentational information for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentDisposition;

/**
 <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentEncoding;

/**
 <p>The language the content is in.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentLanguage;

/**
 <p>Size of the body in bytes.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
 <p>A standard MIME type describing the format of the object data.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentType;

/**
 <p>Specifies whether the object retrieved was (true) or was not (false) a Delete Marker. If false, this response header does not appear in the response.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable deleteMarker;

/**
 <p>An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>If the object expiration is configured (see PUT Bucket lifecycle), the response includes this header. It includes the expiry-date and rule-id key-value pairs providing object expiration information. The value of the rule-id is URL encoded.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expiration;

/**
 <p>The date and time at which the object is no longer cacheable.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable expires;

/**
 <p>Last modified date of the object</p>
 */
@property (nonatomic, strong) NSDate * _Nullable lastModified;

/**
 <p>A map of metadata to store with the object in S3.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable metadata;

/**
 <p>This is set to the number of metadata entries not returned in <code>x-amz-meta</code> headers. This can happen if you create metadata using an API like SOAP that supports more flexible metadata than the REST API. For example, using SOAP, you can create metadata whose values are not legal HTTP headers.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable missingMeta;

/**
 <p>Specifies whether a legal hold is in effect for this object. This header is only returned if the requester has the <code>s3:GetObjectLegalHold</code> permission. This header is not returned if the specified version of this object has never had a legal hold applied. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockLegalHoldStatus objectLockLegalHoldStatus;

/**
 <p>The Object Lock mode, if any, that's in effect for this object. This header is only returned if the requester has the <code>s3:GetObjectRetention</code> permission. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>. </p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockMode objectLockMode;

/**
 <p>The date and time when the Object Lock retention period expires. This header is only returned if the requester has the <code>s3:GetObjectRetention</code> permission.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable objectLockRetainUntilDate;

/**
 <p>The count of parts this object has.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partsCount;

/**
 <p>Amazon S3 can return this header if your request involves a bucket that is either a source or destination in a replication rule.</p><p>In replication, you have a source bucket on which you configure replication and destination bucket where Amazon S3 stores object replicas. When you request an object (<code>GetObject</code>) or object metadata (<code>HeadObject</code>) from these buckets, Amazon S3 will return the <code>x-amz-replication-status</code> header in the response as follows:</p><ul><li><p>If requesting an object from the source bucket — Amazon S3 will return the <code>x-amz-replication-status</code> header if the object in your request is eligible for replication.</p><p> For example, suppose that in your replication configuration, you specify object prefix <code>TaxDocs</code> requesting Amazon S3 to replicate objects with key prefix <code>TaxDocs</code>. Any objects you upload with this key name prefix, for example <code>TaxDocs/document1.pdf</code>, are eligible for replication. For any object request with this key name prefix, Amazon S3 will return the <code>x-amz-replication-status</code> header with value PENDING, COMPLETED or FAILED indicating object replication status.</p></li><li><p>If requesting an object from the destination bucket — Amazon S3 will return the <code>x-amz-replication-status</code> header with value REPLICA if the object in your request is a replica that Amazon S3 created.</p></li></ul><p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Replication</a>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ReplicationStatus replicationStatus;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>If the object is an archived object (an object whose storage class is GLACIER), the response includes this header if either the archive restoration is in progress (see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_RestoreObject.html">RestoreObject</a> or an archive copy is already restored.</p><p> If an archive copy is already restored, the header value indicates when Amazon S3 is scheduled to delete the object copy. For example:</p><p><code>x-amz-restore: ongoing-request="false", expiry-date="Fri, 23 Dec 2012 00:00:00 GMT"</code></p><p>If the object restoration is in progress, the header returns the value <code>ongoing-request="true"</code>.</p><p>For more information about archiving objects, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lifecycle-mgmt.html#lifecycle-transition-general-considerations">Transitioning Objects: General Considerations</a>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable restore;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>If the object is stored using server-side encryption either with an AWS KMS customer master key (CMK) or an Amazon S3-managed encryption key, the response includes this header with the value of the server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

/**
 <p>Provides storage class information of the object. Amazon S3 returns this header for all objects except for S3 Standard storage class objects.</p><p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3StorageClass storageClass;

/**
 <p>Version of the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

/**
 <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata.</p>
 */
@property (nonatomic, strong) NSString * _Nullable websiteRedirectLocation;

@end

/**
 
 */
@interface QYKFAWSS3HeadObjectRequest : QYKFAWSRequest


/**
 <p>The name of the bucket containing the object.</p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Return the object only if its entity tag (ETag) is the same as the one specified, otherwise return a 412 (precondition failed).</p>
 */
@property (nonatomic, strong) NSString * _Nullable ifMatch;

/**
 <p>Return the object only if it has been modified since the specified time, otherwise return a 304 (not modified).</p>
 */
@property (nonatomic, strong) NSDate * _Nullable ifModifiedSince;

/**
 <p>Return the object only if its entity tag (ETag) is different from the one specified, otherwise return a 304 (not modified).</p>
 */
@property (nonatomic, strong) NSString * _Nullable ifNoneMatch;

/**
 <p>Return the object only if it has not been modified since the specified time, otherwise return a 412 (precondition failed).</p>
 */
@property (nonatomic, strong) NSDate * _Nullable ifUnmodifiedSince;

/**
 <p>The object key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Part number of the object being read. This is a positive integer between 1 and 10,000. Effectively performs a 'ranged' HEAD request for the part specified. Useful querying about the size of the part and the number of parts in this object.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumber;

/**
 <p>Downloads the specified range bytes of an object. For more information about the HTTP Range header, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.35</a>.</p><note><p>Amazon S3 doesn't support retrieving multiple ranges of data per <code>GET</code> request.</p></note>
 */
@property (nonatomic, strong) NSString * _Nullable range;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKey;

/**
 <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>VersionId used to reference a specific version of the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

@end

/**
 <p>Container element that identifies who initiated the multipart upload. </p>
 */
@interface QYKFAWSS3Initiator : QYKFAWSModel


/**
 <p>Name of the Principal.</p>
 */
@property (nonatomic, strong) NSString * _Nullable displayName;

/**
 <p>If the principal is an AWS account, it provides the Canonical User ID. If the principal is an IAM User, it provides a user ARN value.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identifier;

@end

/**
 <p>Specifies JSON as object's input serialization format.</p>
 */
@interface QYKFAWSS3JSONInput : QYKFAWSModel


/**
 <p>The type of JSON. Valid values: Document, Lines.</p>
 */
@property (nonatomic, assign) QYKFAWSS3JSONType types;

@end

/**
 <p>Specifies JSON as request's output serialization format.</p>
 */
@interface QYKFAWSS3JSONOutput : QYKFAWSModel


/**
 <p>The value used to separate individual records in the output. If no value is specified, Amazon S3 uses a newline character ('\n').</p>
 */
@property (nonatomic, strong) NSString * _Nullable recordDelimiter;

@end

/**
 
 */
@interface QYKFAWSS3ListMultipartUploadsOutput : QYKFAWSModel


/**
 <p>The name of the bucket to which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>If you specify a delimiter in the request, then the result returns each distinct key prefix containing the delimiter in a <code>CommonPrefixes</code> element. The distinct key prefixes are returned in the <code>Prefix</code> child element.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSS3CommonPrefix *> * _Nullable commonPrefixes;

/**
 <p>Contains the delimiter you specified in the request. If you don't specify a delimiter in your request, this element is absent from the response.</p>
 */
@property (nonatomic, strong) NSString * _Nullable delimiter;

/**
 <p>Encoding type used by Amazon S3 to encode object keys in the response.</p><p>If you specify <code>encoding-type</code> request parameter, Amazon S3 includes this element in the response, and returns encoded key name values in the following response elements:</p><p><code>Delimiter</code>, <code>KeyMarker</code>, <code>Prefix</code>, <code>NextKeyMarker</code>, <code>Key</code>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3EncodingType encodingType;

/**
 <p>Indicates whether the returned list of multipart uploads is truncated. A value of true indicates that the list was truncated. The list can be truncated if the number of multipart uploads exceeds the limit allowed or specified by max uploads.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable isTruncated;

/**
 <p>The key at or after which the listing began.</p>
 */
@property (nonatomic, strong) NSString * _Nullable keyMarker;

/**
 <p>Maximum number of multipart uploads that could have been included in the response.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable maxUploads;

/**
 <p>When a list is truncated, this element specifies the value that should be used for the key-marker request parameter in a subsequent request.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextKeyMarker;

/**
 <p>When a list is truncated, this element specifies the value that should be used for the <code>upload-id-marker</code> request parameter in a subsequent request.</p>
 */
@property (nonatomic, strong) NSString * _Nullable nextUploadIdMarker;

/**
 <p>When a prefix is provided in the request, this field contains the specified prefix. The result contains only keys starting with the specified prefix.</p>
 */
@property (nonatomic, strong) NSString * _Nullable prefix;

/**
 <p>Upload ID after which listing began.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadIdMarker;

/**
 <p>Container for elements related to a particular multipart upload. A response can contain zero or more <code>Upload</code> elements.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSS3MultipartUpload *> * _Nullable uploads;

@end

/**
 
 */
@interface QYKFAWSS3ListMultipartUploadsRequest : QYKFAWSRequest


/**
 <p>The name of the bucket to which the multipart upload was initiated. </p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Character you use to group keys.</p><p>All keys that contain the same string between the prefix, if specified, and the first occurrence of the delimiter after the prefix are grouped under a single result element, <code>CommonPrefixes</code>. If you don't specify the prefix parameter, then the substring starts at the beginning of the key. The keys that are grouped under <code>CommonPrefixes</code> result element are not returned elsewhere in the response.</p>
 */
@property (nonatomic, strong) NSString * _Nullable delimiter;

/**
 <p>Requests Amazon S3 to encode the object keys in the response and specifies the encoding method to use. An object key may contain any Unicode character; however, XML 1.0 parser cannot parse some characters, such as characters with an ASCII value from 0 to 10. For characters that are not supported in XML 1.0, you can add this parameter to request that Amazon S3 encode the keys in the response.</p>
 */
@property (nonatomic, assign) QYKFAWSS3EncodingType encodingType;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Together with upload-id-marker, this parameter specifies the multipart upload after which listing should begin.</p><p>If <code>upload-id-marker</code> is not specified, only the keys lexicographically greater than the specified <code>key-marker</code> will be included in the list.</p><p>If <code>upload-id-marker</code> is specified, any multipart uploads for a key equal to the <code>key-marker</code> might also be included, provided those multipart uploads have upload IDs lexicographically greater than the specified <code>upload-id-marker</code>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable keyMarker;

/**
 <p>Sets the maximum number of multipart uploads, from 1 to 1,000, to return in the response body. 1,000 is the maximum number of uploads that can be returned in a response.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable maxUploads;

/**
 <p>Lists in-progress uploads only for those keys that begin with the specified prefix. You can use prefixes to separate a bucket into different grouping of keys. (You can think of using prefix to make groups in the same way you'd use a folder in a file system.)</p>
 */
@property (nonatomic, strong) NSString * _Nullable prefix;

/**
 <p>Together with key-marker, specifies the multipart upload after which listing should begin. If key-marker is not specified, the upload-id-marker parameter is ignored. Otherwise, any multipart uploads for a key equal to the key-marker might be included in the list only if they have an upload ID lexicographically greater than the specified <code>upload-id-marker</code>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadIdMarker;

@end

/**
 
 */
@interface QYKFAWSS3ListPartsOutput : QYKFAWSModel


/**
 <p>If the bucket has a lifecycle rule configured with an action to abort incomplete multipart uploads and the prefix in the lifecycle rule matches the object name in the request, then the response includes this header indicating when the initiated multipart upload will become eligible for abort operation. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/mpuoverview.html#mpu-abort-incomplete-mpu-lifecycle-config">Aborting Incomplete Multipart Uploads Using a Bucket Lifecycle Policy</a>.</p><p>The response will also include the <code>x-amz-abort-rule-id</code> header that will provide the ID of the lifecycle configuration rule that defines this action.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable abortDate;

/**
 <p>This header is returned along with the <code>x-amz-abort-date</code> header. It identifies applicable lifecycle configuration rule that defines the action to abort incomplete multipart uploads.</p>
 */
@property (nonatomic, strong) NSString * _Nullable abortRuleId;

/**
 <p>The name of the bucket to which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Container element that identifies who initiated the multipart upload. If the initiator is an AWS account, this element provides the same information as the <code>Owner</code> element. If the initiator is an IAM User, this element provides the user ARN and display name.</p>
 */
@property (nonatomic, strong) QYKFAWSS3Initiator * _Nullable initiator;

/**
 <p> Indicates whether the returned list of parts is truncated. A true value indicates that the list was truncated. A list can be truncated if the number of parts exceeds the limit returned in the MaxParts element.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable isTruncated;

/**
 <p>Object key for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Maximum number of parts that were allowed in the response.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable maxParts;

/**
 <p>When a list is truncated, this element specifies the last part in the list, as well as the value to use for the part-number-marker request parameter in a subsequent request.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable nextPartNumberMarker;

/**
 <p> Container element that identifies the object owner, after the object is created. If multipart upload is initiated by an IAM user, this element provides the parent account ID and display name.</p>
 */
@property (nonatomic, strong) QYKFAWSS3Owner * _Nullable owner;

/**
 <p>When a list is truncated, this element specifies the last part in the list, as well as the value to use for the part-number-marker request parameter in a subsequent request.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumberMarker;

/**
 <p> Container for elements related to a particular part. A response can contain zero or more <code>Part</code> elements.</p>
 */
@property (nonatomic, strong) NSArray<QYKFAWSS3Part *> * _Nullable parts;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>Class of storage (STANDARD or REDUCED_REDUNDANCY) used to store the uploaded object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3StorageClass storageClass;

/**
 <p>Upload ID identifying the multipart upload whose parts are being listed.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

/**
 
 */
@interface QYKFAWSS3ListPartsRequest : QYKFAWSRequest


/**
 <p>The name of the bucket to which the parts are being uploaded. </p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Object key for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Sets the maximum number of parts to return.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable maxParts;

/**
 <p>Specifies the part after which listing should begin. Only parts with higher part numbers will be listed.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumberMarker;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Upload ID identifying the multipart upload whose parts are being listed.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

/**
 <p>Container for the <code>MultipartUpload</code> for the Amazon S3 object.</p>
 */
@interface QYKFAWSS3MultipartUpload : QYKFAWSModel


/**
 <p>Date and time at which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable initiated;

/**
 <p>Identifies who initiated the multipart upload.</p>
 */
@property (nonatomic, strong) QYKFAWSS3Initiator * _Nullable initiator;

/**
 <p>Key of the object for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Specifies the owner of the object that is part of the multipart upload. </p>
 */
@property (nonatomic, strong) QYKFAWSS3Owner * _Nullable owner;

/**
 <p>The class of storage used to store the object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3StorageClass storageClass;

/**
 <p>Upload ID that identifies the multipart upload.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

/**
 <p>An object consists of data and its descriptive metadata.</p>
 */
@interface QYKFAWSS3Object : QYKFAWSModel


/**
 <p>The entity tag is a hash of the object. The ETag reflects changes only to the contents of an object, not its metadata. The ETag may or may not be an MD5 digest of the object data. Whether or not it is depends on how the object was created and how it is encrypted as described below:</p><ul><li><p>Objects created by the PUT Object, POST Object, or Copy operation, or through the AWS Management Console, and are encrypted by SSE-S3 or plaintext, have ETags that are an MD5 digest of their object data.</p></li><li><p>Objects created by the PUT Object, POST Object, or Copy operation, or through the AWS Management Console, and are encrypted by SSE-C or SSE-KMS, have ETags that are not an MD5 digest of their object data.</p></li><li><p>If an object is created by either the Multipart Upload or Part Copy operation, the ETag is not an MD5 digest, regardless of the method of encryption.</p></li></ul>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>The name that you assign to an object. You use the object key to retrieve the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>The date the Object was Last Modified</p>
 */
@property (nonatomic, strong) NSDate * _Nullable lastModified;

/**
 <p>The owner of the object</p>
 */
@property (nonatomic, strong) QYKFAWSS3Owner * _Nullable owner;

/**
 <p>Size in bytes of the object</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable size;

/**
 <p>The class of storage used to store the object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectStorageClass storageClass;

@end

/**
 <p>Container for the owner's display name and ID.</p>
 */
@interface QYKFAWSS3Owner : QYKFAWSModel


/**
 <p>Container for the display name of the owner.</p>
 */
@property (nonatomic, strong) NSString * _Nullable displayName;

/**
 <p>Container for the ID of the owner.</p>
 */
@property (nonatomic, strong) NSString * _Nullable identifier;

@end

/**
 <p>Container for elements related to a part.</p>
 */
@interface QYKFAWSS3Part : QYKFAWSModel


/**
 <p>Entity tag returned when the part was uploaded.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>Date and time at which the part was uploaded.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable lastModified;

/**
 <p>Part number identifying the part. This is a positive integer between 1 and 10,000.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumber;

/**
 <p>Size in bytes of the uploaded part data.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable size;

@end

/**
 
 */
@interface QYKFAWSS3PutObjectOutput : QYKFAWSModel


/**
 <p>Entity tag for the uploaded object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p> If the expiration is configured for the object (see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_PutBucketLifecycleConfiguration.html">PutBucketLifecycleConfiguration</a>), the response includes this header. It includes the expiry-date and rule-id key-value pairs that provide information about object expiration. The value of the rule-id is URL encoded.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expiration;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>If present, specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSEncryptionContext;

/**
 <p>If <code>x-amz-server-side-encryption</code> is present and has the value of <code>aws:kms</code>, this header specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object. </p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>If you specified server-side encryption either with an AWS KMS customer master key (CMK) or Amazon S3-managed encryption key in your PUT request, the response includes this header. It confirms the encryption algorithm that Amazon S3 used to encrypt the object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

/**
 <p>Version of the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable versionId;

@end

/**
 
 */
@interface QYKFAWSS3PutObjectRequest : QYKFAWSRequest


/**
 <p>The canned ACL to apply to the object. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/acl-overview.html#CannedACL">Canned ACL</a>.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectCannedACL ACL;

/**
 <p>Object data.</p>
 */
@property (nonatomic, strong) id _Nullable body;

/**
 <p>The bucket name to which the PUT operation was initiated. </p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p> Can be used to specify caching behavior along the request/reply chain. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9</a>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable cacheControl;

/**
 <p>Specifies presentational information for the object. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.5.1">http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.5.1</a>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentDisposition;

/**
 <p>Specifies what content encodings have been applied to the object and thus what decoding mechanisms must be applied to obtain the media-type referenced by the Content-Type header field. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.11">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.11</a>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentEncoding;

/**
 <p>The language the content is in.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentLanguage;

/**
 <p>Size of the body in bytes. This parameter is useful when the size of the body cannot be determined automatically. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.13">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.13</a>.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
 <p>The base64-encoded 128-bit MD5 digest of the message (without the headers) according to RFC 1864. This header can be used as a message integrity check to verify that the data is the same data that was originally sent. Although it is optional, we recommend using the Content-MD5 mechanism as an end-to-end integrity check. For more information about REST request authentication, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/RESTAuthentication.html">REST Authentication</a>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentMD5;

/**
 <p>A standard MIME type describing the format of the contents. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.17">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.17</a>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentType;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>The date and time at which the object is no longer cacheable. For more information, see <a href="http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.21">http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.21</a>.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable expires;

/**
 <p>Gives the grantee READ, READ_ACP, and WRITE_ACP permissions on the object.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantFullControl;

/**
 <p>Allows grantee to read the object data and its metadata.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantRead;

/**
 <p>Allows grantee to read the object ACL.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantReadACP;

/**
 <p>Allows grantee to write the ACL for the applicable object.</p><p>This action is not supported by Amazon S3 on Outposts.</p>
 */
@property (nonatomic, strong) NSString * _Nullable grantWriteACP;

/**
 <p>Object key for which the PUT operation was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>A map of metadata to store with the object in S3.</p>
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * _Nullable metadata;

/**
 <p>Specifies whether a legal hold will be applied to this object. For more information about S3 Object Lock, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lock.html">Object Lock</a>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockLegalHoldStatus objectLockLegalHoldStatus;

/**
 <p>The Object Lock mode that you want to apply to this object.</p>
 */
@property (nonatomic, assign) QYKFAWSS3ObjectLockMode objectLockMode;

/**
 <p>The date and time when you want this object's Object Lock to expire.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable objectLockRetainUntilDate;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKey;

/**
 <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>Specifies the AWS KMS Encryption Context to use for object encryption. The value of this header is a base64-encoded UTF-8 string holding JSON with the encryption context key-value pairs.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSEncryptionContext;

/**
 <p>If <code>x-amz-server-side-encryption</code> is present and has the value of <code>aws:kms</code>, this header specifies the ID of the AWS Key Management Service (AWS KMS) symmetrical customer managed customer master key (CMK) that was used for the object.</p><p> If the value of <code>x-amz-server-side-encryption</code> is <code>aws:kms</code>, this header specifies the ID of the symmetric customer managed AWS KMS CMK that will be used for the object. If you specify <code>x-amz-server-side-encryption:aws:kms</code>, but do not provide<code> x-amz-server-side-encryption-aws-kms-key-id</code>, Amazon S3 uses the AWS managed CMK in AWS to protect the data.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

/**
 <p>By default, Amazon S3 uses the STANDARD Storage Class to store newly created objects. The STANDARD storage class provides high durability and high availability. Depending on performance needs, you can specify a different Storage Class. Amazon S3 on Outposts only uses the OUTPOSTS Storage Class. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html">Storage Classes</a> in the <i>Amazon S3 Service Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3StorageClass storageClass;

/**
 <p>The tag-set for the object. The tag-set must be encoded as URL Query parameters. (For example, "Key1=Value1")</p>
 */
@property (nonatomic, strong) NSString * _Nullable tagging;

/**
 <p>If the bucket is configured as a website, redirects requests for this object to another object in the same bucket or to an external URL. Amazon S3 stores the value of this header in the object metadata. For information about object metadata, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/UsingMetadata.html">Object Key and Metadata</a>.</p><p>In the following example, the request header sets the redirect to an object (anotherPage.html) in the same bucket:</p><p><code>x-amz-website-redirect-location: /anotherPage.html</code></p><p>In the following example, the request header sets the object redirect to another website:</p><p><code>x-amz-website-redirect-location: http://www.example.com/</code></p><p>For more information about website hosting in Amazon S3, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/WebsiteHosting.html">Hosting Websites on Amazon S3</a> and <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/how-to-page-redirect.html">How to Configure Website Page Redirects</a>. </p>
 */
@property (nonatomic, strong) NSString * _Nullable websiteRedirectLocation;

@end

/**
 
 */
@interface QYKFAWSS3UploadPartCopyOutput : QYKFAWSModel


/**
 <p>Container for all response elements.</p>
 */
@property (nonatomic, strong) QYKFAWSS3ReplicatePartResult * _Nullable replicatePartResult;

/**
 <p>The version of the source object that was copied, if you have enabled versioning on the source bucket.</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSourceVersionId;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) that was used for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

@end

/**
 
 */
@interface QYKFAWSS3UploadPartCopyRequest : QYKFAWSRequest


/**
 <p>The bucket name.</p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Specifies the source object for the copy operation. You specify the value in one of two formats, depending on whether you want to access the source object through an <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/access-points.html">access point</a>:</p><ul><li><p>For objects not accessed through an access point, specify the name of the source bucket and key of the source object, separated by a slash (/). For example, to copy the object <code>reports/january.pdf</code> from the bucket <code>awsexamplebucket</code>, use <code>awsexamplebucket/reports/january.pdf</code>. The value must be URL encoded.</p></li><li><p>For objects accessed through access points, specify the Amazon Resource Name (ARN) of the object as accessed through the access point, in the format <code>arn:aws:s3:&lt;Region&gt;:&lt;account-id&gt;:accesspoint/&lt;access-point-name&gt;/object/&lt;key&gt;</code>. For example, to copy the object <code>reports/january.pdf</code> through access point <code>my-access-point</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3:us-west-2:123456789012:accesspoint/my-access-point/object/reports/january.pdf</code>. The value must be URL encoded.</p><note><p>Amazon S3 supports copy operations using access points only when the source and destination buckets are in the same AWS Region.</p></note><p>Alternatively, for objects accessed through Amazon S3 on Outposts, specify the ARN of the object as accessed in the format <code>arn:aws:s3-outposts:&lt;Region&gt;:&lt;account-id&gt;:outpost/&lt;outpost-id&gt;/object/&lt;key&gt;</code>. For example, to copy the object <code>reports/january.pdf</code> through outpost <code>my-outpost</code> owned by account <code>123456789012</code> in Region <code>us-west-2</code>, use the URL encoding of <code>arn:aws:s3-outposts:us-west-2:123456789012:outpost/my-outpost/object/reports/january.pdf</code>. The value must be URL encoded. </p></li></ul><p>To copy a specific version of an object, append <code>?versionId=&lt;version-id&gt;</code> to the value (for example, <code>awsexamplebucket/reports/january.pdf?versionId=QUpfdndhfd8438MNFDN93jdnJFkdmqnh893</code>). If you don't specify a version ID, Amazon S3 copies the latest version of the source object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSource;

/**
 <p>Copies the object if its entity tag (ETag) matches the specified tag.</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSourceIfMatch;

/**
 <p>Copies the object if it has been modified since the specified time.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable replicateSourceIfModifiedSince;

/**
 <p>Copies the object if its entity tag (ETag) is different than the specified ETag.</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSourceIfNoneMatch;

/**
 <p>Copies the object if it hasn't been modified since the specified time.</p>
 */
@property (nonatomic, strong) NSDate * _Nullable replicateSourceIfUnmodifiedSince;

/**
 <p>The range of bytes to copy from the source object. The range value must use the form bytes=first-last, where the first and last are the zero-based byte offsets to copy. For example, bytes=0-9 indicates that you want to copy the first 10 bytes of the source. You can copy a range only if the source object is greater than 5 MB.</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSourceRange;

/**
 <p>Specifies the algorithm to use when decrypting the source object (for example, AES256).</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSourceSSECustomerAlgorithm;

/**
 <p>Specifies the customer-provided encryption key for Amazon S3 to use to decrypt the source object. The encryption key provided in this header must be one that was used when the source object was created.</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSourceSSECustomerKey;

/**
 <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable replicateSourceSSECustomerKeyMD5;

/**
 <p>The account id of the expected destination bucket owner. If the destination bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>The account id of the expected source bucket owner. If the source bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedSourceBucketOwner;

/**
 <p>Object key for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Part number of part being copied. This is a positive integer between 1 and 10,000.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumber;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm</code> header. This must be the same encryption key specified in the initiate multipart upload request.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKey;

/**
 <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>Upload ID identifying the multipart upload whose part is being copied.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

/**
 
 */
@interface QYKFAWSS3UploadPartOutput : QYKFAWSModel


/**
 <p>Entity tag for the uploaded object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

/**
 <p>If present, indicates that the requester was successfully charged for the request.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestCharged requestCharged;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header confirming the encryption algorithm used.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>If server-side encryption with a customer-provided encryption key was requested, the response will include this header to provide round-trip message integrity verification of the customer-provided encryption key.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>If present, specifies the ID of the AWS Key Management Service (AWS KMS) symmetric customer managed customer master key (CMK) was used for the object.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSEKMSKeyId;

/**
 <p>The server-side encryption algorithm used when storing this object in Amazon S3 (for example, AES256, aws:kms).</p>
 */
@property (nonatomic, assign) QYKFAWSS3ServerSideEncryption serverSideEncryption;

@end

/**
 
 */
@interface QYKFAWSS3UploadPartRequest : QYKFAWSRequest


/**
 <p>Object data.</p>
 */
@property (nonatomic, strong) id _Nullable body;

/**
 <p>The name of the bucket to which the multipart upload was initiated.</p><p>When using this API with an access point, you must direct requests to the access point hostname. The access point hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.s3-accesspoint.<i>Region</i>.amazonaws.com. When using this operation with an access point through the AWS SDKs, you provide the access point ARN in place of the bucket name. For more information about access point ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-access-points.html">Using Access Points</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p><p>When using this API with Amazon S3 on Outposts, you must direct requests to the S3 on Outposts hostname. The S3 on Outposts hostname takes the form <i>AccessPointName</i>-<i>AccountId</i>.<i>outpostID</i>.s3-outposts.<i>Region</i>.amazonaws.com. When using this operation using S3 on Outposts through the AWS SDKs, you provide the Outposts bucket ARN in place of the bucket name. For more information about S3 on Outposts ARNs, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/S3onOutposts.html">Using S3 on Outposts</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
 */
@property (nonatomic, strong) NSString * _Nullable bucket;

/**
 <p>Size of the body in bytes. This parameter is useful when the size of the body cannot be determined automatically.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
 <p>The base64-encoded 128-bit MD5 digest of the part data. This parameter is auto-populated when using the command from the CLI. This parameter is required if object lock parameters are specified.</p>
 */
@property (nonatomic, strong) NSString * _Nullable contentMD5;

/**
 <p>The account id of the expected bucket owner. If the bucket is owned by a different account, the request will fail with an HTTP <code>403 (Access Denied)</code> error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable expectedBucketOwner;

/**
 <p>Object key for which the multipart upload was initiated.</p>
 */
@property (nonatomic, strong) NSString * _Nullable key;

/**
 <p>Part number of part being uploaded. This is a positive integer between 1 and 10,000.</p>
 */
@property (nonatomic, strong) NSNumber * _Nullable partNumber;

/**
 <p>Confirms that the requester knows that they will be charged for the request. Bucket owners need not specify this parameter in their requests. For information about downloading objects from requester pays buckets, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/ObjectsinRequesterPaysBuckets.html">Downloading Objects in Requestor Pays Buckets</a> in the <i>Amazon S3 Developer Guide</i>.</p>
 */
@property (nonatomic, assign) QYKFAWSS3RequestPayer requestPayer;

/**
 <p>Specifies the algorithm to use to when encrypting the object (for example, AES256).</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerAlgorithm;

/**
 <p>Specifies the customer-provided encryption key for Amazon S3 to use in encrypting data. This value is used to store the object and then it is discarded; Amazon S3 does not store the encryption key. The key must be appropriate for use with the algorithm specified in the <code>x-amz-server-side-encryption-customer-algorithm header</code>. This must be the same encryption key specified in the initiate multipart upload request.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKey;

/**
 <p>Specifies the 128-bit MD5 digest of the encryption key according to RFC 1321. Amazon S3 uses this header for a message integrity check to ensure that the encryption key was transmitted without error.</p>
 */
@property (nonatomic, strong) NSString * _Nullable SSECustomerKeyMD5;

/**
 <p>Upload ID identifying the multipart upload whose part is being uploaded.</p>
 */
@property (nonatomic, strong) NSString * _Nullable uploadId;

@end

NS_ASSUME_NONNULL_END
