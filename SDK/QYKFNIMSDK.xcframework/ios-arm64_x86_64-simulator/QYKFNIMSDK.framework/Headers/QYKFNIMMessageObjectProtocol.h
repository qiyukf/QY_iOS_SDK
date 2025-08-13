//
//  QYKFNIMMessageObjectProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMGlobalDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMMessage;
@class QYKFNIMQChatMessage;

/**
 *  消息体协议
 */
@protocol QYKFNIMMessageObject <NSObject>

/**
 *  消息体所在的消息对象
 */
@property (nullable,nonatomic, weak) QYKFNIMMessage *message;

/**
 *  消息体所在的消息对象（圈组消息）
 */
@property (nullable,nonatomic, weak) QYKFNIMQChatMessage *qchatMessage;

/**
 *  消息内容类型
 *
 *  @return 消息内容类型
 */
- (QYKFNIMMessageType)type;


@end

NS_ASSUME_NONNULL_END
