//
//  QYKFNIMChatroomNotificationContent.h
//  NIMLib
//
//  Created by Netease
//  Copyright © 2016年 Netease. All rights reserved.
//

#import "QYKFNIMNotificationContent.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室操作类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMChatroomEventType){
    /**
     *  成员进入聊天室
     */
    QYKFNIMChatroomEventTypeEnter         = 301,
    /**
     *  成员离开聊天室
     */
    QYKFNIMChatroomEventTypeExit          = 302,
    /**
     *  成员被拉黑
     */
    QYKFNIMChatroomEventTypeAddBlack      = 303,
    /**
     *  成员被取消拉黑
     */
    QYKFNIMChatroomEventTypeRemoveBlack   = 304,
    /**
     *  成员被设置禁言
     */
    QYKFNIMChatroomEventTypeAddMute       = 305,
    /**
     *  成员被取消禁言
     */
    QYKFNIMChatroomEventTypeRemoveMute    = 306,
    /**
     *  设置为管理员
     */
    QYKFNIMChatroomEventTypeAddManager    = 307,
    /**
     *  移除管理员
     */
    QYKFNIMChatroomEventTypeRemoveManager = 308,
    /**
     *  设置为固定成员
     */
    QYKFNIMChatroomEventTypeAddCommon     = 309,
    /**
     *  取消固定成员
     */
    QYKFNIMChatroomEventTypeRemoveCommon  = 310,
    /**
     *  聊天室被关闭
     */
    QYKFNIMChatroomEventTypeClosed        = 311,
    /**
     *  聊天室信息更新
     */
    QYKFNIMChatroomEventTypeInfoUpdated   = 312,
    /**
     *  聊天室成员被踢
     */
    QYKFNIMChatroomEventTypeKicked        = 313,
    /**
     *  聊天室成员被临时禁言
     */
    QYKFNIMChatroomEventTypeAddMuteTemporarily   = 314,
    /**
     *  聊天室成员被解除临时禁言
     */
    QYKFNIMChatroomEventTypeRemoveMuteTemporarily = 315,
    /**
     *  聊天室成员主动更新了聊天室的角色信息
     */
    QYKFNIMChatroomEventTypeMemberUpdateInfo = 316,
    /**
     *  聊天室通用队列变更的通知
     */
    QYKFNIMChatroomEventTypeQueueChange = 317,
    /**
     *  聊天室被禁言了，只有管理员可以发言,其他人都处于禁言状态
     */
    QYKFNIMChatroomEventTypeRoomMuted = 318,
    /**
     *  聊天室不在禁言状态
     */
    QYKFNIMChatroomEventTypeRoomUnMuted = 319,
    /**
     *  聊天室通用队列批量变更的通知
     */
    QYKFNIMChatroomEventTypeQueueBatchChange = 320,
    /**
     * 聊天室新增标签禁言，包括的字段是muteDuration、targetTag、operator、opeNick字段
     */
    QYKFNIMChatroomEventTypeTagTempMuteAdd = 321,
    /**
     * 聊天室移除标签禁言，包括的字段是muteDuration、targetTag、operator、opeNick字段
     */
    QYKFNIMChatroomEventTypeTagTempMuteRemove = 322,
    /**
     * 聊天室消息撤回，包括的字段是operator、target、msgTime、msgId、ext字段
     */
    QYKFNIMChatroomEventTypeRecall = 323,

    /**
     * 批量添加聊天室队列元素，包括的字段是ext、opeNick、operator、queueChange字段
     */
    QYKFNIMChatroomEventTypeQueueBatchAdd = 324,
    
    /**
     * 批量更新聊天室标签
     */
    QYKFNIMChatroomEventTypeUpdateTags = 325,
};

/**
 *  聊天室队列变更类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMChatroomQueueChangeType){
    /**
     *  无效或未知变更类型
     */
    QYKFNIMChatroomQueueChangeTypeInvalid = 0,
    /**
     *  新增元素
     */
    QYKFNIMChatroomQueueChangeTypeOffer = 1,
    /**
     *  取出元素
     */
    QYKFNIMChatroomQueueChangeTypePoll = 2,
    /**
     *  清空元素
     */
    QYKFNIMChatroomQueueChangeTypeDrop = 3,
    /**
     *  更新元素
     */
    QYKFNIMChatroomQueueChangeTypeUpdate = 5,

    /**
     * 批量新增或更新元素
     */
    QYKFNIMChatroomQueueChangeTypeBatchOffer = 6,
};

/**
 *  聊天室队列批量变更类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMChatroomQueueBatchChangeType){
    /**
     *  无效或未知变更类型
     */
    QYKFNIMChatroomQueueBatchChangeTypeInvalid = 0,
    /**
     *  部分批量清理操作(发生在提交元素的用户掉线时，清理这个用户对应的key)
     */
    QYKFNIMChatroomQueueBatchChangeTypePartClear = 4,
};

/**
 *  通知事件包含的聊天室成员
 */
@interface QYKFNIMChatroomNotificationMember : NSObject
/**
 *  聊天室成员ID
 */
@property (nullable,nonatomic,copy,readonly) NSString *userId;
/**
 *  聊天室成员昵称
 */
@property (nullable,nonatomic,copy,readonly) NSString *nick;

@end


/**
 *  聊天室通知内容
 */
@interface QYKFNIMChatroomNotificationContent : QYKFNIMNotificationContent

/**
 *  聊天室通知事件类型
 */
@property (nonatomic,assign,readonly) QYKFNIMChatroomEventType eventType;

/**
 *  操作者
 */
@property (nullable,nonatomic,copy,readonly) QYKFNIMChatroomNotificationMember *source;

/**
 *  被操作者
 */
@property (nullable,nonatomic,copy,readonly) NSArray<QYKFNIMChatroomNotificationMember *> *targets;

/**
 *  通知信息
 */
@property (nullable,nonatomic,copy,readonly) NSString *notifyExt;

/**
 * 标签
 */
@property (nullable,nonatomic,copy,readonly) NSArray<NSString *> *tags;

/**
 * 被撤回消息的ID
 */
 @property (nullable,nonatomic,copy,readonly) NSString *revokedMessageId;

/**
 * 被撤回消息的时间
 */
@property (nonatomic,readonly) NSTimeInterval revokedMessageTime;

/**
 *  拓展信息
 *  @discusssion 不同的聊天室通知有不同的扩展信息
 *               QYKFNIMChatroomEventTypeAddMuteTemporarily/QYKFNIMChatroomEventTypeRemoveMuteTemporarily 类型: 拓展信息为NSNumber，表示临时禁言时长
 *
 *               QYKFNIMChatroomEventTypeEnter 类型: 扩展信息为 NSDictionary , KEY 值为 NIMChatroomEventInfoMutedKey ，NIMChatroomEventInfoTempMutedKey, NIMChatroomEventInfoTempMutedDurationKey
 *
 *               QYKFNIMChatroomEventTypeQueueChange 类型: 扩展信息为 NSDictionary， KEY 值为 NIMChatroomEventInfoQueueChangeTypeKey , NIMChatroomEventInfoQueueChangeItemKey, NIMChatroomEventInfoQueueChangeItemValueKey
 */
@property (nullable,nonatomic,copy,readonly) id ext;

@end

/**
 *  是否是禁言状态
 */
extern NSString *const NIMChatroomEventInfoMutedKey;

/**
 *  是否为临时禁言状态
 */
extern NSString *const NIMChatroomEventInfoTempMutedKey;

/**
 *  临时禁言时长
 */
extern NSString *const NIMChatroomEventInfoTempMutedDurationKey;

/**
 *  聊天室变更类型
 */
extern NSString *const NIMChatroomEventInfoQueueChangeTypeKey;

/**
 *  聊天室变更元素
 */
extern NSString *const NIMChatroomEventInfoQueueChangeItemKey;

/**
 *  聊天室批量变更元素，为包含多个键值对的字典
 */
extern NSString *const NIMChatroomEventInfoQueueChangeItemsKey;


/**
 *  聊天室变更元素的值
 */
extern NSString *const NIMChatroomEventInfoQueueChangeItemValueKey;



NS_ASSUME_NONNULL_END
