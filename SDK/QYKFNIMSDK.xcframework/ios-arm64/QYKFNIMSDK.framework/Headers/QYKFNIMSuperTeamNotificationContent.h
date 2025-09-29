//
//  QYKFNIMSuperTeamNotificationContent.h
//  QYKFNIMSDK
//
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMNotificationContent.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  群操作类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMSuperTeamOperationType){
    // default
    QYKFNIMSuperTeamOperationTypeUnknown         = -1,
    
    /**
     *  邀请成员
     */
    QYKFNIMSuperTeamOperationTypeInvite          = 401,
    /**
     *  移除成员
     */
    QYKFNIMSuperTeamOperationTypeKick            = 402,
    /**
     *  离开群
     */
    QYKFNIMSuperTeamOperationTypeLeave           = 403,
    /**
     *  更新群信息
     */
    QYKFNIMSuperTeamOperationTypeUpdate          = 404,
    /**
     *  解散群
     */
    QYKFNIMSuperTeamOperationTypeDismiss         = 405,
    /**
     *  群主转移群主身份
     */
    QYKFNIMSuperTeamOperationTypeTransferOwner   = 406,
    /**
     *  添加管理员
     */
    QYKFNIMSuperTeamOperationTypeAddManager      = 407,
    /**
     *  移除管理员
     */
    QYKFNIMSuperTeamOperationTypeRemoveManager   = 408,
    
    /**
     *  群内禁言/解禁
     */
    QYKFNIMSuperTeamOperationTypeMute            = 409,
    
    /**
     *  申请成功进群
     */
    QYKFNIMSuperTeamOperationTypeApplyPass       = 410,
    
    /**
     *  接受邀请进群
     */
    QYKFNIMSuperTeamOperationTypeAcceptInvitation = 411,
};

/**
 *  群信息更新字段
 */
typedef NS_ENUM(NSInteger, QYKFNIMSuperTeamUpdateTag){
    /**
     *  群名
     */
    QYKFNIMSuperTeamUpdateTagName            = 3,
    /**
     *  群简介
     */
    QYKFNIMSuperTeamUpdateTagIntro           = 14,
    /**
     *  群公告
     */
    QYKFNIMSuperTeamUpdateTagAnouncement     = 15,
    /**
     *  群验证方式
     */
    QYKFNIMSuperTeamUpdateTagJoinMode        = 16,
    /**
     *  客户端自定义拓展字段
     */
    QYKFNIMSuperTeamUpdateTagClientCustom    = 18,
    
    /**
     *  服务器自定义拓展字段
     *  @discussion SDK 无法直接修改这个字段, 请调用服务器接口
     */
    QYKFNIMSuperTeamUpdateTagServerCustom    = 19,
    
    /**
     *  头像
     */
    QYKFNIMSuperTeamUpdateTagAvatar          = 20,
    
    /**
     *  被邀请模式
     */
    QYKFNIMSuperTeamUpdateTagBeInviteMode    = 21,
    
    /**
     *  群全体禁言
     *  @discussion SDK 无法直接修改这个字段, 请调用服务器接口
     */
    QYKFNIMSuperTeamUpdateTagMuteMode       = 101,

    /**
     * 对某些资料内容另外的反垃圾的业务ID
     */
    QYKFNIMSuperTeamUpdateTagAntispamBusinessId = 102,
};

/**
 * 超大群通知内容
 */
@interface QYKFNIMSuperTeamNotificationContent : QYKFNIMNotificationContent
/**
 *  操作发起者ID
 */
@property (nullable,nonatomic,copy,readonly)     NSString    *sourceID;

/**
 *  操作类型
 */
@property (nonatomic,assign,readonly)   QYKFNIMSuperTeamOperationType  operationType;

/**
 *  被操作者ID列表
 */
@property (nullable,nonatomic,copy,readonly)   NSArray<NSString *> *targetIDs;

/**
 *  群通知下发的自定义扩展信息
 */
@property (nullable,nonatomic,readonly)   NSString *notifyExt;

/**
 *  额外信息
 *  @discussion 群更新时 attachment 为 NIMUpdateTeamInfoAttachment，
 *              禁言时 attachment 为  QYKFNIMMuteTeamMemberAttachment
 */
@property (nullable,nonatomic,strong,readonly)   id attachment;
@end

/**
 *  更新群信息的额外信息
 */
@interface QYKFNIMUpdateSuperTeamInfoAttachment : NSObject

/**
 *  群内修改的信息键值对
 *  @discussion NSNumebr 取值范围为 QYKFNIMSuperTeamUpdateTag 枚举类型
 */
@property (nullable,nonatomic,copy,readonly)   NSDictionary<NSNumber *,NSString *>    *values;
@end

/**
 *  禁言通知的额外信息
 */
@interface QYKFNIMMuteSuperTeamMemberAttachment : NSObject

/**
 *  是否被禁言
 *  @discussion YES 为禁言，NO 为 解除禁言
 */
@property (nonatomic,assign,readonly)   BOOL    flag;

@end

NS_ASSUME_NONNULL_END
