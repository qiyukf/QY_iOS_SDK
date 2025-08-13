//
//  QYKFNIMChatroomUpdateRequest.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室信息修改字段
 *  @discussion 等级枚举见 `QYKFNIMChatroomQueueModificationLevel`
 */
typedef NS_ENUM(NSInteger, QYKFNIMChatroomUpdateTag){
    /**
     *  聊天室名称
     */
        QYKFNIMChatroomUpdateTagName         = 3,
    /**
     *  聊天室公告
     */
        QYKFNIMChatroomUpdateTagAnnouncement = 4,
    /**
     *  聊天室直播拉流地址
     */
        QYKFNIMChatroomUpdateTagBroadcastUrl = 5,
    /**
     *  聊天室扩展字段
     */
        QYKFNIMChatroomUpdateTagExt          = 12,
    /**
     *  聊天室队列修改等级，只有管理员和房主可以修改
     */
        QYKFNIMChatroomUpdateTagQueueModificationLevel = 16
    
};


/**
 *  聊天室信息更新请求
 */
@interface QYKFNIMChatroomUpdateRequest : NSObject

/**
 *  聊天室ID
 */
@property (nonatomic,copy)   NSString *roomId;

/**
 *  修改信息字段,修改传入的数据键值对是 {@(NIMChatroomUpdateTag) : NSString 或 NSNumber},无效数据将被过滤
 */
@property (nonatomic,copy)   NSDictionary *updateInfo;

/**
 *  是否需要通知, 默认NO
 */
@property (nonatomic,assign) BOOL needNotify;

/**
 *  放到事件通知里的扩展字段
 */
@property (nullable,nonatomic,copy)   NSString *notifyExt;

/**
 * 对某些资料内容另外的反垃圾的业务ID
 */
@property (nonatomic,strong)    NSString *antispamBusinessId;

@end

NS_ASSUME_NONNULL_END
