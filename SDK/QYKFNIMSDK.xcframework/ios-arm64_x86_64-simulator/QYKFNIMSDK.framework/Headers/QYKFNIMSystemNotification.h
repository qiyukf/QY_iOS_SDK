//
//  QYKFNIMSystemNotification.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMSession.h"
#import "QYKFNIMUser.h"
#import "QYKFNIMCustomSystemNotificationSetting.h"
#import "QYKFNIMAntiSpamOption.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  系统通知类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMSystemNotificationType){
    /**
     *  申请入群
     */
    QYKFNIMSystemNotificationTypeTeamApply              = 0,
    /**
     *  拒绝入群
     */
    QYKFNIMSystemNotificationTypeTeamApplyReject        = 1,
    /**
     *  邀请入群
     */
    QYKFNIMSystemNotificationTypeTeamInvite             = 2,
    /**
     *  拒绝入群邀请
     */
    QYKFNIMSystemNotificationTypeTeamIviteReject        = 3,
    
    /**
     *  添加好友
     */
    QYKFNIMSystemNotificationTypeFriendAdd              = 5,
    /**
     *  删除好友
     */
    QYKFNIMSystemNotificationTypeDeleteFriend           = 6,
    /**
     *  p2p消息撤回通知
     */
    QYKFNIMSystemNotificationTypeRevokeP2PMsg           = 7,
    /**
     *  team消息撤回
     */
    QYKFNIMSystemNotificationTypeRevokeTeamMsg          = 8,
    /**
     *  superteam消息撤回
     */
    QYKFNIMSystemNotificationTypeRevokeSuperTeamMsg     = 12,
    /**
     *  p2p消息单向删除，发送方无感知，接收方消息会被清掉
     */
    QYKFNIMSystemNotificationTypeDeleteP2PMsg           = 13,
    /**
     *  team消息单向删除，发送方无感知，接收方消息会被清掉
     */
    QYKFNIMSystemNotificationTypeDeleteTeamMsg          =  14,
    /**
     *  申请入超大群
     */
    QYKFNIMSystemNotificationTypeSuperTeamApply         = 15,
    /**
     *  拒绝入超大群
     */
    QYKFNIMSystemNotificationTypeSuperTeamApplyReject   = 16,
    /**
     *  邀请入超大群
     */
    QYKFNIMSystemNotificationTypeSuperTeamInvite        = 17,
    /**
     *  拒绝入超大群邀请
     */
    QYKFNIMSystemNotificationTypeSuperTeamIviteReject   = 18,
    
};

#pragma mark - 系统通知
/**
 *  系统通知
 */
@interface QYKFNIMSystemNotification : NSObject

/**
 *  通知 ID
 */
@property (nonatomic,assign,readonly)      int64_t notificationId;

/**
 *  通知类型
 */
@property (nonatomic,assign,readonly)       QYKFNIMSystemNotificationType type;

/**
 *  时间戳
 */
@property (nonatomic,assign,readonly)       NSTimeInterval timestamp;

/**
 *  操作者
 */
@property (nullable,nonatomic,copy,readonly)         NSString *sourceID;

/**
 *  目标ID,群ID或者是用户ID
 */
@property (nullable,nonatomic,copy,readonly)         NSString *targetID;

/**
 *  附言
 */
@property (nullable,nonatomic,copy,readonly)         NSString *postscript;

/**
 *  是否已读
 *  @discussion 修改这个属性并不会修改 db 中的数据
 */
@property (nonatomic,assign)                BOOL read;

/**
 *  消息处理状态
 *  @discussion 修改这个属性,后台会自动更新 db 中对应的数据,SDK 调用者可以使用这个值来持久化他们对消息的处理结果,默认为 0
 */
@property (nonatomic,assign)                NSInteger handleStatus;


/**
 *  系统通知下发的自定义扩展信息
 */
@property (nullable,nonatomic,readonly)   NSString *notifyExt;

/**
 *  附件
 *  @discussion 额外信息,只有 好友添加 这个通知有附件
 *              好友添加的 attachment 为 QYKFNIMUserAddAttachment
 */
@property (nullable,nonatomic,strong,readonly)       id attachment;

@end


/**
 *  添加好友附件
 */
@interface QYKFNIMUserAddAttachment : NSObject

/**
 *  好友操作类型
 */
@property (nonatomic,assign,readonly)   QYKFNIMUserOperation    operationType;

/**
 *  服务器扩展字段
 */
@property (nullable,nonatomic,copy,readonly)   NSString  *serverExt;

@end


/**
 *  系统通知过滤器
 */
@interface QYKFNIMSystemNotificationFilter : NSObject
/**
 *  类型列表,取值范围为: QYKFNIMSystemNotificationType 枚举类型
 */
@property (nonatomic,copy)    NSArray<NSNumber *>     *notificationTypes;
@end


#pragma mark - 自定义系统通知
/**
 *  自定义系统通知
 */
@interface QYKFNIMCustomSystemNotification : NSObject

/**
 *  通知 ID
 *  @discussion 只有收到的自定义系统通知才有通知 ID
 */
@property (nonatomic,assign,readonly)       int64_t notificationId;

/**
 *  时间戳
 */
@property (nonatomic,assign,readonly)       NSTimeInterval timestamp;

/**
 *  通知发起者id
 */
@property (nullable,nonatomic,copy,readonly)         NSString *sender;

/**
 *  通知接受者id
 */
@property (nullable,nonatomic,copy,readonly)         NSString *receiver;


/**
 *  通知接受者类型
 */
@property (nonatomic,assign,readonly)       QYKFNIMSessionType  receiverType;

/**
 *  透传的消息体内容
 */
@property (nullable,nonatomic,copy,readonly)         NSString    *content;

/**
 *  是否只发送给在线用户
 *  @discussion 默认为YES 如果这个值为NO,通知接受者如果在通知投递时不在线,那么他会在下次登录时收到这个通知
 */
@property (nonatomic,assign)                BOOL sendToOnlineUsersOnly;

/**
 *  apns推送文案，长度限制500字
 *  @discussion 默认为nil,用户可以设置当前通知的推送文案
 */
@property (nullable,nonatomic,copy)                  NSString *apnsContent;


/**
 *  apns推送Payload
 *  @discussion 可以通过这个字段定义自定义通知的推送Payload,支持字段参考苹果技术文档,最多支持2K
 */
@property (nullable,nonatomic,copy)                  NSDictionary *apnsPayload;

/**
 *  自定义系统通知设置
 *  @discussion 可以通过这个字段制定当前通知的各种设置,如是否需要计入推送未读，是否需要带推送前缀等等
 */
@property (nullable,nonatomic,strong)                QYKFNIMCustomSystemNotificationSetting *setting;


/**
 *  反垃圾选项
 */
@property (nullable,nonatomic,strong)                QYKFNIMAntiSpamOption *antiSpamOption;

/**
*  环境变量，用于指向不同的抄送、第三方回调等配置
*/
@property (nullable,nonatomic,copy)                  NSString *env;

/**
 *  自定义系统通知初始化方法
 *
 *  @param content 自定义系统通知内容
 *
 *  @return 自定义系统通知实例
 */
- (instancetype)initWithContent:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
