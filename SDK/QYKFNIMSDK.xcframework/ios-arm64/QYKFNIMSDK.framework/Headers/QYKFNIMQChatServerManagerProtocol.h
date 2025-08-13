//
//  QYKFNIMQChatServerManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "QYKFNIMQChatAPIDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMQChatServerMember;

@class QYKFNIMQChatCreateServerParam;
@class QYKFNIMQChatDeleteServerParam;
@class QYKFNIMQChatUpdateServerParam;
@class QYKFNIMQChatGetServersParam;
@class QYKFNIMQChatGetServersByPageParam;
@class QYKFNIMQChatInviteServerMembersParam;
@class QYKFNIMQChatAcceptServerInviteParam;
@class QYKFNIMQChatRejectServerInviteParam;
@class QYKFNIMQChatApplyServerJoinParam;
@class QYKFNIMQChatAcceptServerApplyParam;
@class QYKFNIMQChatRejectServerApplyParam;
@class QYKFNIMQChatKickServerMembersParam;
@class QYKFNIMQChatLeaveServerParam;
@class QYKFNIMQChatUpdateMyMemberInfoParam;
@class QYKFNIMQChatUpdateServerMemberInfoParam;
@class QYKFNIMQChatGetServerMembersParam;
@class QYKFNIMQChatGetServerMembersByPageParam;
@class QYKFNIMQChatUpdateServerMemberBanParam;
@class QYKFNIMQChatGetServerBanedMembersByPageParam;

@class QYKFNIMQChatCreateServerResult;
@class QYKFNIMQChatUpdateServerResult;
@class QYKFNIMQChatGetServersResult;
@class QYKFNIMQChatGetServersByPageResult;
@class QYKFNIMQChatGetServerMembersResult;
@class QYKFNIMQChatGetServerMemberListByPageResult;
@class QYKFNIMQChatSubscribeServerParam;
@class QYKFNIMQChatGetServerBanedMembersByPageResult;
@class QYKFNIMQChatInviteServerMembersResult;
@class QYKFNIMQChatSearchServerByPageResult;
@class QYKFNIMQChatSearchServerMemberByPageResult;
@class QYKFNIMQChatSearchServerByPageParam;
@class QYKFNIMQChatSearchServerMemberByPageParam;
@class QYKFNIMQChatSubsribeServerResult;
@class QYKFNIMQChatGenerateInviteCodeParam;
@class QYKFNIMQChatJoinByInviteCodeParam;
@class QYKFNIMQChatGetInviteApplyRecordOfServerParam;
@class QYKFNIMQChatGetInviteApplyRecordOfSelfParam;
@class QYKFNIMQChatGenerateInviteCodeResult;
@class QYKFNIMQChatGetInviteApplyHistoryByServerResult;
@class QYKFNIMQChatGetInviteApplyHistorySelfResult;
@class QYKFNIMQChatApplyServerJoinResult;
@class QYKFNIMQChatSubscribeAllChannelParam;
@class QYKFNIMQChatSubscribeAllChannelResult;
@class QYKFNIMQChatMarkServerReadResult;
@class QYKFNIMQChatMarkServerReadParam;
@class QYKFNIMQChatSearchServerChannelMemberParam;
@class QYKFNIMQChatSearchServerChannelMemberResult;
@class QYKFNIMQChatEnterServerAsVisitorParam;
@class QYKFNIMQChatEnterServerAsVisitorResult;
@class QYKFNIMQChatLeaveServerAsVisitorParam;
@class QYKFNIMQChatLeaveServerAsVisitorResult;
@class QYKFNIMQChatSubscribeServerAsVisitorParam;
@class QYKFNIMQChatSubscribeServerAsVisitorResult;
@class QYKFNIMQChatServerMuteParam;
@class QYKFNIMQChatGetServerMuteMemberByPageParam;
@class QYKFNIMQChatMuteResult;
@class QYKFNIMQChatGetServerMuteMemberByPageResult;

/**
 * 创建服务器的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatCreateServerHandler)(NSError *__nullable error, QYKFNIMQChatCreateServerResult *__nullable result);

/**
 * 修改服务器信息
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateServerHandler)(NSError *__nullable error, QYKFNIMQChatUpdateServerResult *__nullable result);

/**
 * 查询服务器信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServersHandler)(NSError *__nullable error, QYKFNIMQChatGetServersResult *__nullable result);

/**
 * 查询服务器信息列表的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServersByPageHandler)(NSError *__nullable error, QYKFNIMQChatGetServersByPageResult *__nullable result);

/**
 * 查询服务器成员信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServerMembersHandler)(NSError *__nullable error, QYKFNIMQChatGetServerMembersResult *__nullable result);
/**
 * 分页查询服务器成员信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServerMembersByPageHandler)(NSError *__nullable error, QYKFNIMQChatGetServerMemberListByPageResult *__nullable result);
/**
 * 更新服务器成员信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateServerMemberHandler)(NSError *__nullable error, QYKFNIMQChatServerMember *__nullable result);

/**
 * 邀请服务器成员的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatInviteServerMembersHandler)(NSError *__nullable error, QYKFNIMQChatInviteServerMembersResult *__nullable result);

typedef QYKFNIMQChatHandler QYKFNIMQChatUpdateServerMemberBanHandler;

/**
 *  分页查询封禁人员的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServerBanedMembersByPageHandler)(NSError *__nullable error, QYKFNIMQChatGetServerBanedMembersByPageResult *__nullable result);

/**
 *  分页检索服务器信息回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSearchServerByPageHandler)(NSError *__nullable error, QYKFNIMQChatSearchServerByPageResult *__nullable result);

/**
 *  检索服务器用户信息回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSearchServerMemberByPageHandler)(NSError *__nullable error, QYKFNIMQChatSearchServerMemberByPageResult *__nullable result);

/**
 *  检索服务器频道用户信息回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSearchServerChannelMemberHandler)(NSError *__nullable error, QYKFNIMQChatSearchServerChannelMemberResult *__nullable result);


/**
 *  订阅服务器的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSubsribeServerHandler)(NSError *__nullable error, QYKFNIMQChatSubsribeServerResult *__nullable result);

/**
 * 生成邀请码回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGenerateInviteCodeHandler)(NSError *__nullable error, QYKFNIMQChatGenerateInviteCodeResult *__nullable result);

/**
 * 通过邀请码加入服务器回调
 */
typedef QYKFNIMQChatHandler QYKFNIMQChatJoinByInviteCodeHandler;

/**
 * 查询服务器下的申请邀请记录回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetInviteApplyRecordOfServerHandler)(NSError *__nullable error, QYKFNIMQChatGetInviteApplyHistoryByServerResult *__nullable result);

/**
 * 查询我的申请邀请记录回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetInviteApplyRecordOfSelfHandler)(NSError *__nullable error, QYKFNIMQChatGetInviteApplyHistorySelfResult *__nullable result);

/**
 * 申请加入服务器的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatApplyServerJoinHandler)(NSError *__nullable error, QYKFNIMQChatApplyServerJoinResult *__nullable result);

/**
 * 订阅服务器下所有频道的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSubscribeAllChannelHandler)(NSError *__nullable error, QYKFNIMQChatSubscribeAllChannelResult *__nullable result);

/**
 * 标记服务器下所有未读的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatMarkServerReadHandler)(NSError *__nullable error, QYKFNIMQChatMarkServerReadResult *__nullable result);


/**
 * 以游客身份订阅服务器
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSubscribeServerAsVisitorHandler)(NSError *__nullable error, QYKFNIMQChatSubscribeServerAsVisitorResult *__nullable result);

/**
 * 以游客身份加入服务器的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatEnterServerAsVisitorHandler)(NSError *__nullable error, QYKFNIMQChatEnterServerAsVisitorResult *__nullable result);

/**
 * 以游客身份退出服务器的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatLeaveServerAsVisitorHandler)(NSError *__nullable error, QYKFNIMQChatLeaveServerAsVisitorResult *__nullable result);

/**
 *  临时禁言操作的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatServerMuteHandler)(NSError *__nullable error, QYKFNIMQChatMuteResult *__nullable result);

/**
 *  分页查询在指定服务器被禁言的成员的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServerMuteMemberByPageHandler)(NSError *__nullable error, QYKFNIMQChatGetServerMuteMemberByPageResult *__nullable result);


/**
 *   圈组服务器管理器回调
 */
@protocol QYKFNIMQChatServerManagerDelegate <NSObject>

@optional


@end

/**
 *  圈组服务器管理器
 */
@protocol QYKFNIMQChatServerManager <NSObject>
/**
 * 创建服务器
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)createServer:(nonnull QYKFNIMQChatCreateServerParam *)param
          completion:(nullable QYKFNIMQChatCreateServerHandler)completion;

/**
 * 删除服务器
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)deleteServer:(nonnull QYKFNIMQChatDeleteServerParam *)param
          completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 修改服务器信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateServer:(nonnull QYKFNIMQChatUpdateServerParam *)param
          completion:(nullable QYKFNIMQChatUpdateServerHandler)completion;

/**
 * 查询服务器信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServers:(nonnull QYKFNIMQChatGetServersParam *)param
        completion:(nullable QYKFNIMQChatGetServersHandler)completion;

/**
 * 查询服务器信息列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServersByPage:(nonnull QYKFNIMQChatGetServersByPageParam *)param
              completion:(nullable QYKFNIMQChatGetServersByPageHandler)completion;

/**
 * 邀请服务器成员
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)inviteServerMembers:(nonnull QYKFNIMQChatInviteServerMembersParam *)param
                 completion:(nullable QYKFNIMQChatInviteServerMembersHandler)completion;

/**
 * 接受邀请
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)acceptServerInvite:(nonnull QYKFNIMQChatAcceptServerInviteParam *)param
                completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 拒绝邀请
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)rejectServerInvite:(nonnull QYKFNIMQChatRejectServerInviteParam *)param
                completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 申请加入服务器
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)applyServerJoin:(nonnull QYKFNIMQChatApplyServerJoinParam *)param
             completion:(nullable QYKFNIMQChatApplyServerJoinHandler)completion;

/**
 * 接受申请
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)acceptServerApply:(nonnull QYKFNIMQChatAcceptServerApplyParam *)param
               completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 拒绝申请
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)rejectServerApply:(nonnull QYKFNIMQChatRejectServerApplyParam *)param
               completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 踢除服务器成员
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)kickServerMembers:(QYKFNIMQChatKickServerMembersParam *)param
               completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 主动离开服务器
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)leaveServer:(QYKFNIMQChatLeaveServerParam *)param
         completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 修改服务器成员信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateMyMemberInfo:(QYKFNIMQChatUpdateMyMemberInfoParam *)param
                completion:(nullable QYKFNIMQChatUpdateServerMemberHandler)completion;

/**
 * 修改他人服务器成员信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateServerMemberInfo:(QYKFNIMQChatUpdateServerMemberInfoParam *)param
                    completion:(nullable QYKFNIMQChatUpdateServerMemberHandler)completion;

/**
 * 查询服务器成员信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServerMembers:(QYKFNIMQChatGetServerMembersParam *)param
              completion:(nullable QYKFNIMQChatGetServerMembersHandler)completion;

/**
 * 分页查询服务器成员信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServerMembersByPage:(QYKFNIMQChatGetServerMembersByPageParam *)param
                    completion:(nullable QYKFNIMQChatGetServerMembersByPageHandler)completion;

/**
 * 订阅服务器请求
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)subscribeServer:(QYKFNIMQChatSubscribeServerParam *)param
            completion:(nullable QYKFNIMQChatSubsribeServerHandler)completion;

/**
 * 对服务器成员进行封禁操作
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)banServerMember:(QYKFNIMQChatUpdateServerMemberBanParam *)param
             completion:(nullable QYKFNIMQChatUpdateServerMemberBanHandler)completion;

/**
 * 对服务器成员进行解封操作
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)unbanServerMember:(QYKFNIMQChatUpdateServerMemberBanParam *)param
             completion:(nullable QYKFNIMQChatUpdateServerMemberBanHandler)completion;
/**
 *  分页获取封禁成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServerBanedMembersByPage:(QYKFNIMQChatGetServerBanedMembersByPageParam *)param completion:(nullable QYKFNIMQChatGetServerBanedMembersByPageHandler)completion;

/**
 * 检索服务器列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)searchServerByPage:(QYKFNIMQChatSearchServerByPageParam *)param completion:(nullable QYKFNIMQChatSearchServerByPageHandler) completion;

/**
 * 检索服务器成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)searchServerMemberByPage:(QYKFNIMQChatSearchServerMemberByPageParam *)param completion:(nullable QYKFNIMQChatSearchServerMemberByPageHandler) completion;

/**
 * 检索频道内成员
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)searchServerChannelMember:(QYKFNIMQChatSearchServerChannelMemberParam *)param completion:(nullable QYKFNIMQChatSearchServerChannelMemberHandler) completion;


/**
 * 生成邀请码
 * @param param 传入参数
 * @param completion 结果回调
 */
-(void)generateInviteCode:(QYKFNIMQChatGenerateInviteCodeParam *)param completion:(nullable  QYKFNIMQChatGenerateInviteCodeHandler) completion;

/**
 * 通过邀请码加入服务器
 * @param param 传入参数
 * @param completion 结果回调
 */
-(void)joinByInviteCode:(QYKFNIMQChatJoinByInviteCodeParam *)param completion:(nullable  QYKFNIMQChatJoinByInviteCodeHandler) completion;

/**
 * 查询服务器下的申请邀请记录
 * @param param 传入参数
 * @param completion 结果回调
 */
-(void)getInviteApplyRecordOfServer:(QYKFNIMQChatGetInviteApplyRecordOfServerParam *)param completion:(nullable  QYKFNIMQChatGetInviteApplyRecordOfServerHandler) completion;

/**
 * 查询我的申请邀请记录
 * @param param 传入参数
 * @param completion 结果回调
 */
-(void)getInviteApplyRecordOfSelf:(QYKFNIMQChatGetInviteApplyRecordOfSelfParam *)param completion:(nullable  QYKFNIMQChatGetInviteApplyRecordOfSelfHandler) completion;

/**
 * 订阅服务器下所有频道
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)subscribeAllChannel:(QYKFNIMQChatSubscribeAllChannelParam *)param
                      completion:(nullable QYKFNIMQChatSubscribeAllChannelHandler)completion;
/**
 * 清除服务器已读
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)markServerRead:(QYKFNIMQChatMarkServerReadParam *)param
               completion:(nullable QYKFNIMQChatMarkServerReadHandler)completion;

/**
 * 以游客身份订阅服务器
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)subscribeAsVisitor:(nonnull QYKFNIMQChatSubscribeServerAsVisitorParam*)param
                completion:(nullable QYKFNIMQChatSubscribeServerAsVisitorHandler)completion;

/**
 * 以游客身份加入服务器
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)enterAsVisitor:(nonnull QYKFNIMQChatEnterServerAsVisitorParam *)param
            completion:(nullable QYKFNIMQChatEnterServerAsVisitorHandler)completion;

/**
 * 以游客身份退出服务器
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)leaveAsVisitor:(nonnull QYKFNIMQChatLeaveServerAsVisitorParam *)param
            completion:(nullable QYKFNIMQChatLeaveServerAsVisitorHandler)completion;

/**
 * 临时禁言相关操作。
 *  支持在频道层面对指定成员列表进行禁言和解除禁言操作。
 *  禁言操作有预设时间，到期自动解除禁言，也可以中途通过此接口实现解除禁言。
 *  多次重复禁言时，新的一次禁言会覆盖老的禁言。
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)mute:(QYKFNIMQChatServerMuteParam*)param
  completion:(nullable QYKFNIMQChatServerMuteHandler)completion;

/**
 * 分页查询在指定服务器被禁言的成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getMuteMemberByPage:(QYKFNIMQChatGetServerMuteMemberByPageParam*)param
                 completion:(nullable QYKFNIMQChatGetServerMuteMemberByPageHandler)completion;

/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<QYKFNIMQChatServerManagerDelegate>)delegate;

/**
 *  移除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<QYKFNIMQChatServerManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
