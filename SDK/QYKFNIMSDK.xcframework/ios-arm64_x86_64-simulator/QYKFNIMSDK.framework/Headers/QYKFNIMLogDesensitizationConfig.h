//
// Created by Netease on 2022/6/8.
// Copyright (c) 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QYKFNIMLogDesensitizationConfig : NSObject <NSCopying>

/**
 * 是否脱敏下载地址，包括上传成功后得到的下载地址，默认NO
 */
@property (nonatomic, assign) BOOL hideDownloadUrl;

+ (NSString *) getPrintTextOfDownloadUrl:(NSString *) url
                                  config:(QYKFNIMLogDesensitizationConfig *) config;
@end

NS_ASSUME_NONNULL_END
