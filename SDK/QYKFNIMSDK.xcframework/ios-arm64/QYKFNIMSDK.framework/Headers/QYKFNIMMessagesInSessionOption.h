//
// Created by 陈吉力 on 2023/3/8.
// Copyright (c) 2023 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMMessageSearchOption.h"

@class QYKFNIMSession;
@class QYKFNIMMessage;


@interface QYKFNIMMessagesInSessionOption : NSObject
/** 会话 */
@property(nonatomic, nonnull, copy) QYKFNIMSession *session;
/** 锚点消息 */
@property(nonatomic, nullable, copy) QYKFNIMMessage *message;
/** 数量限制 */
@property(nonatomic, assign) NSUInteger limit;
/** 类型限制 */
@property(nonatomic, nullable, copy)NSArray *filterTypes;
/** 结束时间 */
@property(nonatomic, assign) NSTimeInterval toTime;
/** 查询方向 */
@property(nonatomic, assign) NIMMessageSearchOrder order;
@end
