//
//  QYKFNIMCreateTeamOption.h
//  NIMLib
//
//  Created by Netease
//  Copyright © 2016 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMTeamDefs.h"

NS_ASSUME_NONNULL_BEGIN
/**
 *  创建群选项
 *  @deprecated 使用QYKFNIMCreateTeamExOption
 */
@interface QYKFNIMCreateTeamOption : NSObject
/**
 *  群名
 */
@property (nullable,nonatomic,copy)      NSString        *name;
/**
 *  群类型
 *  @discussion 默认为普通群
 */
@property (nonatomic,assign)    QYKFNIMTeamType     type;

/**
 *  群头像
 */
@property (nullable,nonatomic,copy)      NSString        *avatarUrl;

/**
 *  群简介
 */
@property (nullable,nonatomic,copy)      NSString        *intro;

/**
 *  群公告
 */
@property (nullable,nonatomic,copy)      NSString        *announcement;

/**
 *  客户端自定义信息
 */
@property (nullable,nonatomic,copy)      NSString        *clientCustomInfo;

/**
 *  邀请他人的附言
 *  @discussion 高级群有效，普通群无需附言
 */
@property (nullable,nonatomic,copy)      NSString        *postscript;

/**
 *  群验证模式
 *  @discussion 只有高级群有效，默认为 NIMTeamJoinModeNoAuth
 */
@property (nonatomic,assign)    NIMTeamJoinMode joinMode;

/**
 *  群邀请权限
 *  @discussion 只有高级群有效，默认为 QYKFNIMTeamInviteModeManager
 */
@property (nonatomic,assign)    QYKFNIMTeamInviteMode inviteMode;


/**
 *  被邀请模式
 *  @discussion 只有高级群有效，默认为 QYKFNIMTeamBeInviteModeNeedAuth
 */
@property (nonatomic,assign)    QYKFNIMTeamBeInviteMode beInviteMode;

/**
 *  修改群信息权限
 *  @discussion 只有高级群有效，默认为 QYKFNIMTeamUpdateInfoModeManager
 */
@property (nonatomic,assign)    QYKFNIMTeamUpdateInfoMode updateInfoMode;

/**
 *  修改群客户端自定义字段权限
 *  @discussion 只有高级群有效，默认为 QYKFNIMTeamUpdateClientCustomModeManager
 */
@property (nonatomic,assign)    QYKFNIMTeamUpdateClientCustomMode updateClientCustomMode;

/**
 *  设置群最大人数上限
 *  @discussion 默认为0，表示使用默认人数上限
 */
@property (nonatomic,assign)    NSUInteger maxMemberCountLimitation;

/**
 * 对某些资料内容另外的反垃圾的业务ID
 */
@property (nonatomic,strong)    NSString *antispamBusinessId;


@end

NS_ASSUME_NONNULL_END
