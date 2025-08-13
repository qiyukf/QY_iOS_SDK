//
//  QYKFNIMImportedRecentSession.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2018年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMSession;

/**
 *  待导入的最近会话模型
 */
@interface QYKFNIMImportedRecentSession : NSObject

/**
 *  会话
 *  @discussion 当前只支持 P2P 和 Team 会话类型
 */
@property (nonatomic,copy)   QYKFNIMSession  *session;

/**
 *  时间戳
 *  @discussion 最近会话的当前时间
 */
@property (nonatomic,assign)    NSTimeInterval  timestamp;

@end

NS_ASSUME_NONNULL_END
