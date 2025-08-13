//
//  QYKFNIMQChatChannelManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "QYKFNIMQChatAPIDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMQChatChannel;

@class QYKFNIMQChatCreateChannelParam;
@class QYKFNIMQChatDeleteChannelParam;
@class QYKFNIMQChatUpdateChannelParam;
@class QYKFNIMQChatGetChannelsParam;
@class QYKFNIMQChatGetChannelsByPageParam;
@class QYKFNIMQChatGetChannelMembersByPageParam;
@class QYKFNIMQChatGetChannelBlackWhiteRolesByPageParam;
@class QYKFNIMQChatGetChannelBlackWhiteMembersByPageParam;
@class QYKFNIMQChatUpdateChannelBlackWhiteRoleParam;
@class QYKFNIMQChatUpdateChannelBlackWhiteMembersParam;
@class QYKFNIMQChatGetExistingChannelBlackWhiteRolesParam;
@class QYKFNIMQChatGetExistingChannelBlackWhiteMembersParam;

@class QYKFNIMQChatGetChannelsResult;
@class QYKFNIMQChatGetChannelMembersByPageResult;
@class QYKFNIMQChatGetChannelBlackWhiteRolesByPageResult;
@class QYKFNIMQChatGetChannelBlackWhiteMembersByPageResult;

@class QYKFNIMQChatSubscribeChannelParam;
@class QYKFNIMQChatGetChannelUnreadInfosParam;
@class QYKFNIMQChatGetChannelUnreadInfosResult;
@class QYKFNIMQChatGetChannelsByPageResult;
@class QYKFNIMQChatGetExistingChannelBlackWhiteRolesResult;
@class QYKFNIMQChatGetExistingChannelBlackWhiteMembersResult;

@class QYKFNIMQChatServerRole;
@class QYKFNIMQChatServerMember;
@class QYKFNIMQChatChannelMember;

// 频道分组
@class QYKFNIMQChatCreateChannelCategoryParam;
@class QYKFNIMQChatUpdateChannelCategoryParam;
@class QYKFNIMQChatDeleteChannelCategoryParam;
@class QYKFNIMQChatGetChannelCategoriesParam;
@class QYKFNIMQChatGetChannelCategoryBlackWhiteRolesByPageParam;
@class QYKFNIMQChatGetChannelCategoryBlackWhiteMembersByPageParam;
@class QYKFNIMQChatUpdateChannelCategoryBlackWhiteRoleParam;
@class QYKFNIMQChatUpdateChannelCategoryBlackWhiteMembersParam;
@class QYKFNIMQChatGetExistingChannelCategoryBlackWhiteRolesParam;
@class QYKFNIMQChatGetExistingChannelCategoryBlackWhiteMembersParam;
@class QYKFNIMQChatGetChannelsInCategoryByPageParam;
@class QYKFNIMQChatGetCategoriesInServerByPageParam;
@class QYKFNIMQChatGetUncategorizedChannelsByPageParam;

@class QYKFNIMQChatGetChannelCategoriesResult;
@class QYKFNIMQChatGetChannelCategoryMembersByPageResult;
@class QYKFNIMQChatGetChannelCategoryBlackWhiteRolesByPageResult;
@class QYKFNIMQChatGetChannelCategoryBlackWhiteMembersByPageResult;
@class QYKFNIMQChatGetUncategorizedChannelsByPageResult;

@class QYKFNIMQChatGetExistingChannelCategoryBlackWhiteRolesResult;
@class QYKFNIMQChatGetExistingChannelCategoryBlackWhiteMembersResult;
@class QYKFNIMQChatGetChannelsInCategoryByPageResult;
@class QYKFNIMQChatGetCategoriesInServerByPageResult;
@class QYKFNIMQChatUpdateCategoryInfoOfChannelParam;

@class QYKFNIMQChatChannelCategory;
@class QYKFNIMQChatSearchChannelByPageResult;
@class QYKFNIMQChatSearchChannelByPageParam;
@class QYKFNIMQChatSubscribeChannelResult;
@class QYKFNIMQChatSubscribeChannelAsVisitorResult;
@class QYKFNIMQChatSubscribeChannelAsVisitorParam;

@class QYKFNIMQChatChannelMuteParam;
@class QYKFNIMQChatMuteResult;
@class QYKFNIMQChatGetChannelMuteMemberByPageParam;
@class QYKFNIMQChatGetChannelMuteMemberByPageResult;

/**
 * 创建圈组频道的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatCreateChannelHandler)(NSError *__nullable error,
                                            QYKFNIMQChatChannel *__nullable result);

/**
 * 查询圈组频道信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelsHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelsResult *__nullable result);

/**
 * 分页查询圈组频道信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelsByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelsByPageResult *__nullable result);

/**
 * 更新圈组频道信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateChannelHandler)(NSError *__nullable error,
                                            QYKFNIMQChatChannel *__nullable result);

/**
 * 更新圈组频道中所属频道分组信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateCategoryInfoOfChannelHandler)(NSError *__nullable error,
                                            QYKFNIMQChatChannel *__nullable result);

/**
 * 分页查询圈组频道成员的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelMembersByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelMembersByPageResult *__nullable result);
/**
 * 分页查询频道黑白名单身份组列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelBlackWhiteRolesByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelBlackWhiteRolesByPageResult *__nullable result);

/**
 * 分页查询频道黑白名单成员列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelBlackWhiteMembersByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelBlackWhiteMembersByPageResult *__nullable result);
/**
 * 批量查询频道黑白名单身份组列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingChannelBlackWhiteRolesHandler)(NSError *__nullable error,
                                                         QYKFNIMQChatGetExistingChannelBlackWhiteRolesResult *__nullable result);
/**
 * 批量查询频道黑白名单成员列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingChannelBlackWhiteMembersHandler)(NSError *__nullable error,
                                                           QYKFNIMQChatGetExistingChannelBlackWhiteMembersResult *__nullable result);
/**
 * 查询未读信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelUnreadInfosHandler)(NSError *__nullable error,
                                                    QYKFNIMQChatGetChannelUnreadInfosResult *__nullable result);
/**
 * 创建圈组频道分组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatCreateChannelCategoryHandler)(NSError *__nullable error,
                                            QYKFNIMQChatChannelCategory *__nullable result);

/**
 * 更新圈组频道分组信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateChannelCategoryHandler)(NSError *__nullable error,
                                            QYKFNIMQChatChannelCategory *__nullable result);

/**
 * 查询圈组频道分组信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelCategoriesHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelCategoriesResult *__nullable result);

/**
 * 分页查询频道分组黑白名单身份组列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelCategoryBlackWhiteRolesByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelCategoryBlackWhiteRolesByPageResult *__nullable result);

/**
 * 分页查询频道分组黑白名单成员列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelCategoryBlackWhiteMembersByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelCategoryBlackWhiteMembersByPageResult *__nullable result);
/**
 * 批量查询频道分组黑白名单身份组列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingChannelCategoryBlackWhiteRolesHandler)(NSError *__nullable error,
                                                         QYKFNIMQChatGetExistingChannelCategoryBlackWhiteRolesResult *__nullable result);
/**
 * 批量查询频道分组黑白名单成员列表的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingChannelCategoryBlackWhiteMembersHandler)(NSError *__nullable error,
                                                           QYKFNIMQChatGetExistingChannelCategoryBlackWhiteMembersResult *__nullable result);

/**
 * 分页查询频道分组中频道信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelsInCategoryByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetChannelsInCategoryByPageResult *__nullable result);

/**
 * 分页查询服务器内频道分组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetCategoriesInServerByPageHandler)(NSError *__nullable error,
                                          QYKFNIMQChatGetCategoriesInServerByPageResult *__nullable result);

/**
 * 分页查询没有频道分组的频道的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetUncategorizedChannelsByPageHandler)(NSError *__nullable error,
                                                             QYKFNIMQChatGetUncategorizedChannelsByPageResult *__nullable result);

/**
 *  分页检索频道信息回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSearchChannelByPageHandler)(NSError *__nullable error, QYKFNIMQChatSearchChannelByPageResult *__nullable result);

/**
 *  订阅频道的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSubscribeChannelHandler)(NSError *__nullable error, QYKFNIMQChatSubscribeChannelResult *__nullable result);

/**
 *  以游客身份订阅频道的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSubscribeChannelAsVisitorHandler)(NSError *__nullable error, QYKFNIMQChatSubscribeChannelAsVisitorResult *__nullable result);

/**
 *  临时禁言操作的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatChannelMuteHandler)(NSError *__nullable error, QYKFNIMQChatMuteResult *__nullable result);

/**
 *  分页查询在指定频道被禁言的成员的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelMuteMemberByPageHandler)(NSError *__nullable error, QYKFNIMQChatGetChannelMuteMemberByPageResult *__nullable result);

/**
 *   圈组频道管理器回调
 */
@protocol QYKFNIMQChatChannelManagerDelegate <NSObject>

@optional

@end

/**
 *  圈组频道管理器
 */
@protocol QYKFNIMQChatChannelManager <NSObject>
/**
 * 创建圈组频道
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)createChannel:(QYKFNIMQChatCreateChannelParam *)param
           completion:(nullable QYKFNIMQChatCreateChannelHandler)completion;

/**
 * 删除圈组频道
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)deleteChannel:(QYKFNIMQChatDeleteChannelParam *)param
           completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 修改圈组频道信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateChannel:(QYKFNIMQChatUpdateChannelParam *)param
           completion:(nullable QYKFNIMQChatUpdateChannelHandler)completion;

/**
 * 修改圈组频道中所属分组相关信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateCategoryInfoOfChannel:(QYKFNIMQChatUpdateCategoryInfoOfChannelParam *)param
           completion:(nullable QYKFNIMQChatUpdateCategoryInfoOfChannelHandler)completion;

/**
 * 查询圈组频道信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannels:(QYKFNIMQChatGetChannelsParam *)param
         completion:(nullable QYKFNIMQChatGetChannelsHandler)completion;

/**
 * 分页查询圈组频道信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelsByPage:(QYKFNIMQChatGetChannelsByPageParam *)param
               completion:(nullable QYKFNIMQChatGetChannelsByPageHandler)completion;

/**
 * 订阅频道请求
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)subscribeChannel:(QYKFNIMQChatSubscribeChannelParam *)param
             completion:(nullable QYKFNIMQChatSubscribeChannelHandler)completion;

/**
 * 查询未读信息
 */
- (void)getChannelUnreadInfos:(QYKFNIMQChatGetChannelUnreadInfosParam *)param
                   completion:(nullable QYKFNIMQChatGetChannelUnreadInfosHandler)completion;

/**
 * 分页查询圈组频道成员
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelMembersByPage:(QYKFNIMQChatGetChannelMembersByPageParam *)param
               completion:(nullable QYKFNIMQChatGetChannelMembersByPageHandler)completion;

/**
 * 分页查询频道黑白名单成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getBlackWhiteMembersByPage:(QYKFNIMQChatGetChannelBlackWhiteMembersByPageParam *)param
               completion:(nullable QYKFNIMQChatGetChannelBlackWhiteMembersByPageHandler)completion;

/**
 * 更新频道黑白名单成员
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateBlackWhiteMembers:(QYKFNIMQChatUpdateChannelBlackWhiteMembersParam *)param
               completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 分页查询频道黑白名单身份组列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getBlackWhiteRolesByPage:(QYKFNIMQChatGetChannelBlackWhiteRolesByPageParam *)param
               completion:(nullable QYKFNIMQChatGetChannelBlackWhiteRolesByPageHandler)completion;

/**
 * 更新频道黑白名单身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateBlackWhiteRole:(QYKFNIMQChatUpdateChannelBlackWhiteRoleParam *)param
               completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 批量查询频道黑白名单身份组列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getExistingChannelBlackWhiteRoles:(QYKFNIMQChatGetExistingChannelBlackWhiteRolesParam *)param
               completion:(nullable QYKFNIMQChatGetExistingChannelBlackWhiteRolesHandler)completion;
/**
 * 批量查询频道黑白名单成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getExistingChannelBlackWhiteMembers:(QYKFNIMQChatGetExistingChannelBlackWhiteMembersParam *)param
               completion:(nullable QYKFNIMQChatGetExistingChannelBlackWhiteMembersHandler)completion;

#pragma mark -- 频道分组 --

/**
 * 创建圈组频道分组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)createChannelCategory:(QYKFNIMQChatCreateChannelCategoryParam *)param
           completion:(nullable QYKFNIMQChatCreateChannelCategoryHandler)completion;

/**
 * 删除圈组频道分组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)deleteChannelCategory:(QYKFNIMQChatDeleteChannelCategoryParam *)param
           completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 修改圈组频道分组信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateChannelCategory:(QYKFNIMQChatUpdateChannelCategoryParam *)param
           completion:(nullable QYKFNIMQChatUpdateChannelCategoryHandler)completion;

/**
 * 查询圈组频道分组信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelCategories:(QYKFNIMQChatGetChannelCategoriesParam *)param
         completion:(nullable QYKFNIMQChatGetChannelCategoriesHandler)completion;

/**
 * 分页查询频道分组黑白名单成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelCategoryBlackWhiteMembersByPage:(QYKFNIMQChatGetChannelCategoryBlackWhiteMembersByPageParam *)param
               completion:(nullable QYKFNIMQChatGetChannelCategoryBlackWhiteMembersByPageHandler)completion;

/**
 * 更新频道分组黑白名单成员
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateChannelCategoryBlackWhiteMembers:(QYKFNIMQChatUpdateChannelCategoryBlackWhiteMembersParam *)param
               completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 分页查询频道分组黑白名单身份组列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelCategoryBlackWhiteRolesByPage:(QYKFNIMQChatGetChannelCategoryBlackWhiteRolesByPageParam *)param
               completion:(nullable QYKFNIMQChatGetChannelCategoryBlackWhiteRolesByPageHandler)completion;

/**
 * 更新频道分组黑白名单身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateChannelCategoryBlackWhiteRole:(QYKFNIMQChatUpdateChannelCategoryBlackWhiteRoleParam *)param
               completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 批量查询频道分组黑白名单身份组列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getExistingChannelCategoryBlackWhiteRoles:(QYKFNIMQChatGetExistingChannelCategoryBlackWhiteRolesParam *)param
               completion:(nullable QYKFNIMQChatGetExistingChannelCategoryBlackWhiteRolesHandler)completion;
/**
 * 批量查询频道分组黑白名单成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getExistingChannelCategoryBlackWhiteMembers:(QYKFNIMQChatGetExistingChannelCategoryBlackWhiteMembersParam *)param
               completion:(nullable QYKFNIMQChatGetExistingChannelCategoryBlackWhiteMembersHandler)completion;
/**
 * 分页查询频道分组内频道信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelsInCategoryByPage:(QYKFNIMQChatGetChannelsInCategoryByPageParam *)param
               completion:(nullable QYKFNIMQChatGetChannelsInCategoryByPageHandler)completion;

 /**
 * 分页查询服务器内频道分组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getCategoriesInServerByPage:(QYKFNIMQChatGetCategoriesInServerByPageParam *)param
               completion:(nullable QYKFNIMQChatGetCategoriesInServerByPageHandler)completion;

/**
 * 分页查询没有频道分组的频道
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getUncategorizedChannelsByPage:(QYKFNIMQChatGetUncategorizedChannelsByPageParam *)param
                            completion:(nullable QYKFNIMQChatGetUncategorizedChannelsByPageHandler)completion;

/**
 * 检索频道列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)searchChannelByPage:(QYKFNIMQChatSearchChannelByPageParam *)param completion:(nullable QYKFNIMQChatSearchChannelByPageHandler) completion;

/**
 * 以游客身份订阅频道
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)subscribeAsVisitor:(QYKFNIMQChatSubscribeChannelAsVisitorParam*)param
                completion:(nullable QYKFNIMQChatSubscribeChannelAsVisitorHandler)completion;

/**
 * 临时禁言相关操作。
 *  支持在频道层面对指定成员列表进行禁言和解除禁言操作。
 *  禁言操作有预设时间，到期自动解除禁言，也可以中途通过此接口实现解除禁言。
 *  多次重复禁言时，新的一次禁言会覆盖老的禁言。
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)mute:(QYKFNIMQChatChannelMuteParam*)param
                completion:(nullable QYKFNIMQChatChannelMuteHandler)completion;

/**
 * 分页查询在指定频道被禁言的成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getMuteMemberByPage:(QYKFNIMQChatGetChannelMuteMemberByPageParam*)param
                completion:(nullable QYKFNIMQChatGetChannelMuteMemberByPageHandler)completion;

/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<QYKFNIMQChatChannelManagerDelegate>)delegate;

/**
 *  移除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<QYKFNIMQChatChannelManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
