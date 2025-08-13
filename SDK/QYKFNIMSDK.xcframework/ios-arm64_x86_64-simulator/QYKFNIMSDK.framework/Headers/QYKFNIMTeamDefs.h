//
//  QYKFNIMTeamDefs.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#ifndef NIMLib_NIMTeamDefs_h
#define NIMLib_NIMTeamDefs_h

@class QYKFNIMTeam;
@class QYKFNIMTeamMember;
@class QYKFNIMTeamMemberSearchResult;

/**
 *  群类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamType){
    /**
     *  普通群
     */
    QYKFNIMTeamTypeNormal       = 0,
    /**
     *  高级群
     */
    QYKFNIMTeamTypeAdvanced     = 1,
    /**
     *  超大群
     */
    QYKFNIMTeamTypeSuper        = 2,
};

/**
 *  群验证方式
 */
typedef NS_ENUM(NSInteger, NIMTeamJoinMode) {
    /**
     *  允许所有人加入
     */
    NIMTeamJoinModeNoAuth    = 0,
    /**
     *  需要验证
     */
    NIMTeamJoinModeNeedAuth  = 1,
    /**
     *  不允许任何人加入
     */
    NIMTeamJoinModeRejectAll = 2,
};

/**
 *  邀请模式
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamInviteMode) {
    /**
     *  只有管理员/群主可以邀请他人入群
     */
    QYKFNIMTeamInviteModeManager    = 0,
    /**
     *   所有人可以邀请其他人入群
     */
    QYKFNIMTeamInviteModeAll        = 1,
};




/**
 *  被邀请模式
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamBeInviteMode) {
    /**
     *  需要被邀请方同意
     */
    QYKFNIMTeamBeInviteModeNeedAuth    = 0,
    /**
     *   不需要被邀请方同意
     */
    QYKFNIMTeamBeInviteModeNoAuth  = 1,
};


/**
 *  群信息修改权限
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamUpdateInfoMode) {
    /**
     *  只有管理员/群主可以修改
     */
    QYKFNIMTeamUpdateInfoModeManager    = 0,
    /**
     *  所有人可以修改
     */
    QYKFNIMTeamUpdateInfoModeAll  = 1,
};


/**
 *  修改群客户端自定义字段权限
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamUpdateClientCustomMode) {
    /**
     *  只有管理员/群主可以修改
     */
    QYKFNIMTeamUpdateClientCustomModeManager    = 0,
    /**
     *  所有人可以修改
     */
    QYKFNIMTeamUpdateClientCustomModeAll  = 1,
};


/**
 *  申请入群状态
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamApplyStatus) {
    /**
     *  无效状态
     */
    QYKFNIMTeamApplyStatusInvalid,
    /**
     *  已经在群里
     */
    QYKFNIMTeamApplyStatusAlreadyInTeam,
    /**
     *  申请等待通过
     */
    QYKFNIMTeamApplyStatusWaitForPass,
    
};


/**
 *  群成员类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamMemberType){
    /**
     *  普通群员
     */
    QYKFNIMTeamMemberTypeNormal = 0,
    /**
     *  群拥有者
     */
    QYKFNIMTeamMemberTypeOwner = 1,
    /**
     *  群管理员
     */
    QYKFNIMTeamMemberTypeManager = 2,
    /**
     *  申请加入用户
     */
    QYKFNIMTeamMemberTypeApply   = 3,
};


/**
 *  群消息接受状态
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamNotifyState) {
    /**
     *  接受任何群消息通知
     */
    QYKFNIMTeamNotifyStateAll         = 0,
    /**
     *  不接受任何群消息通知
     */
    QYKFNIMTeamNotifyStateNone        = 1,
    /**
     *  只接受管理员的群消息通知
     */
    QYKFNIMTeamNotifyStateOnlyManager = 2,
    
};

/**
 *  群全体禁言模式
 */
typedef NS_ENUM(NSInteger, QYKFNIMTeamAllMuteMode){
    /**
     *  取消全员禁言
     */
    QYKFNIMTeamAllMuteModeCancel         = 0,
    /**
     *  全员禁言，不包括管理员
     */
    QYKFNIMTeamAllMuteModeMuteNormal     = 1,
    /**
     *  全员禁言，包括群主和管理员
     */
    QYKFNIMTeamAllMuteModeMuteAll        = 3,
};

/**
 *  通用的群组操作block
 *
 *  @param error 错误,如果成功则error为nil
 */
typedef void(^QYKFNIMTeamHandler)(NSError * __nullable error);

/**
 *  创建群组block
 *
 *  @param error   错误,如果成功则error为nil
 *  @param teamId  群组ID
 *  @param failedUserIds 邀请失败的群成员ID
 */
typedef void(^QYKFNIMTeamCreateHandler)(NSError * __nullable error, NSString * __nullable teamId, NSArray<NSString *> * __nullable failedUserIds);

/**
*  群查询 block
*
*  @param error   错误,如果成功则error为nil
*  @param teams 查询的群信息
*/
typedef void(^QYKFNIMTeamSearchHandler)(NSError * __nullable error, NSArray<QYKFNIMTeam *> * __nullable teams);

/**
 *  群成员获取 block
 *
 *  @param error   错误,如果成功则error为nil
 *  @param members 成功的群成员列表,内部为QYKFNIMTeamMember
 */
typedef void(^QYKFNIMTeamMemberHandler)(NSError * __nullable error, NSArray<QYKFNIMTeamMember *> * __nullable members);

/**
 *  搜索结果 block
 *
 *  @param error 错误,如果成功则error为nil
 *  @param result 搜索成功结果
 */

typedef void (^QYKFNIMTeamMemberSearchResultHandler)(NSError * __nullable error, QYKFNIMTeamMemberSearchResult * __nullable result);

/**
 *  拉取群信息Block
 *
 *  @param error 错误,如果成功则error为nil
 *  @param team  群信息
 */
typedef void(^QYKFNIMTeamFetchInfoHandler)(NSError * __nullable error, QYKFNIMTeam * __nullable team);

/**
 *  群申请block
 *
 *  @param error       错误,如果成功则error为nil
 *  @param applyStatus 群申请状态
 */
typedef void(^QYKFNIMTeamApplyHandler)(NSError * __nullable error, QYKFNIMTeamApplyStatus applyStatus);

/**
 *  邀请人Accids
 *
 *  @param error       错误,如果成功则error为nil
 *  @param inviters    群成员与邀请人关系
 */
typedef void(^QYKFNIMTeamFetchInviterAccidsHandler)(NSError * __nullable error, NSDictionary<NSString *, NSString *> * __nullable inviters);

/**
 *  拉取所有群信息Block
 *
 *  @param error 错误,如果成功则error为nil
 *  @param teams  群信息
 */
typedef void(^QYKFNIMTeamFetchTeamsHandler)(NSError * __nullable error, NSArray<QYKFNIMTeam *> * __nullable teams);
/**
 *  根据群ID列表批量获取群信息block
 *
 *  @param error         错误,如果成功则error为nil
 *  @param teams         获取成功的群组信息列表
 *  @param failedUserIds 获取失败的群ID列表
 */
typedef void(^QYKFNIMTeamFetchTeamInfoListHandler)(NSError * __nullable error, NSArray<QYKFNIMTeam *> * __nullable teams, NSArray<NSString *> * __nullable failedTeamIds);

#endif
