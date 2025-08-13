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

#import "AWSS3TransferUtilityTasks.h"

NS_ASSUME_NONNULL_BEGIN

@interface QYKFAWSS3TransferUtilityBlocks : NSObject

@property (nonatomic, nullable, strong, readonly) QYKFAWSS3TransferUtilityProgressBlock uploadProgressBlock;
@property (nonatomic, nullable, strong, readonly) QYKFAWSS3TransferUtilityMultiPartProgressBlock multiPartUploadProgressBlock;
@property (nonatomic, nullable, strong, readonly) QYKFAWSS3TransferUtilityProgressBlock downloadProgressBlock;
@property (nonatomic, nullable, strong, readonly) QYKFAWSS3TransferUtilityUploadCompletionHandlerBlock uploadCompletedBlock;
@property (nonatomic, nullable, strong, readonly) QYKFAWSS3TransferUtilityMultiPartUploadCompletionHandlerBlock multiPartUploadCompletedBlock;
@property (nonatomic, nullable, strong, readonly) QYKFAWSS3TransferUtilityDownloadCompletionHandlerBlock downloadCompletedBlock;

- (instancetype)initWithUploadProgress:(nullable QYKFAWSS3TransferUtilityProgressBlock)uploadProgressBlock
               multiPartUploadProgress:(nullable QYKFAWSS3TransferUtilityMultiPartProgressBlock)multiPartUploadProgressBlock
                      downloadProgress:(nullable QYKFAWSS3TransferUtilityProgressBlock)downloadProgressBlock
                       uploadCompleted:(nullable QYKFAWSS3TransferUtilityUploadCompletionHandlerBlock)uploadCompletedBlock
              multiPartUploadCompleted:(nullable QYKFAWSS3TransferUtilityMultiPartUploadCompletionHandlerBlock)multiPartUploadCompletedBlock
                     downloadCompleted:(nullable QYKFAWSS3TransferUtilityDownloadCompletionHandlerBlock)downloadCompletedBlock;

@end

NS_ASSUME_NONNULL_END
