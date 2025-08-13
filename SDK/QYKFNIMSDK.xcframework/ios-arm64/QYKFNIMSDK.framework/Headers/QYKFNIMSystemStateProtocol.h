//
//  QYKFNIMSystemStateProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2024 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol QYKFNIMSystemStateDelegate;

/**
 *  系统状态委托
 */
@protocol QYKFNIMSystemStateManager <NSObject>

/**
 *  添加系统状态委托
 *
 *  @param delegate 系统状态委托
 */
- (void)addDelegate:(id<QYKFNIMSystemStateDelegate>)delegate;

/**
 *  移除系统状态委托
 *
 *  @param delegate 系统状态委托
 */
- (void)removeDelegate:(id<QYKFNIMSystemStateDelegate>)delegate;

@end

/**
 *  系统状态委托
 */
@protocol QYKFNIMSystemStateDelegate <NSObject>

@optional

/**
 *  磁盘空间已满
 *
 *  @param error 错误对象
 *  @discussion 此委托方法在app生命周期内仅会调用一次
 */
- (void)onDiskFull:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
