//
//  QYKFNIMQChatRoleManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "QYKFNIMQChatAPIDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMQChatCreateServerRoleParam;
@class QYKFNIMQChatDeleteServerRoleParam;
@class QYKFNIMQChatUpdateServerRoleParam;
@class QYKFNIMQChatGetServerRolesParam;
@class QYKFNIMQChatAddChannelRoleParam;
@class QYKFNIMQChatRemoveChannelRoleParam;
@class QYKFNIMQChatUpdateChannelRoleParam;
@class QYKFNIMQChatGetChannelRolesParam;
@class QYKFNIMQChatAddMemberRoleParam;
@class QYKFNIMQChatRemoveMemberRoleParam;
@class QYKFNIMQChatUpdateMemberRoleParam;
@class QYKFNIMQChatGetMemberRolesParam;
@class QYKFNIMQChatAddServerRoleMembersParam;
@class QYKFNIMQChatRemoveServerRoleMemberParam;
@class QYKFNIMQChatGetServerRoleMembersParam;
@class QYKFNIMQChatGetServerRolesByAccidParam;
@class QYKFNIMQChatGetExistingAccidsInServerRoleParam;
@class QYKFNIMQChatGetExistingChannelRolesByServerRoleIdsParam;
@class QYKFNIMQChatGetExistingAccidsOfMemberRolesParam;
@class QYKFNIMQChatupdateServerRolePrioritiesParam;
@class QYKFNIMQChatGetExistingServerRoleMembersByAccidsParam;
@class QYKFNIMQChatCheckPermissionParam;
@class QYKFNIMQChatCheckPermissionsParam;

@class QYKFNIMQChatServerRole;
@class QYKFNIMQChatGetServerRolesResult;
@class QYKFNIMQChatChannelRole;
@class QYKFNIMQChatGetChannelRolesResult;
@class QYKFNIMQChatMemberRole;
@class QYKFNIMQChatGetMemberRolesResult;
@class QYKFNIMQChatGetServerRoleMembersResult;
@class QYKFNIMQChatAddServerRoleMembersResult;
@class QYKFNIMQChatRemoveServerRoleMembersResult;
@class QYKFNIMQChatGetServerRolesByAccidResult;
@class QYKFNIMQChatGetExistingAccidsInServerRoleResult;
@class QYKFNIMQChatGetExistingAccidsInServerRoleResult;
@class QYKFNIMQChatGetExistingChannelRolesByServerRoleIdsResult;
@class QYKFNIMQChatGetExistingAccidsOfMemberRolesResult;
@class QYKFNIMQChatupdateServerRolePrioritiesResult;
@class QYKFNIMQChatGetExistingServerRoleMembersByAccidsResult;
@class QYKFNIMQChatCheckPermissionsResult;



typedef QYKFNIMQChatHandler QYKFNIMQChatDeleteServerRoleHandler;
typedef QYKFNIMQChatHandler QYKFNIMQChatRemoveChannelRoleHandler;
typedef QYKFNIMQChatHandler QYKFNIMQChatRemoveMemberRoleHandler;


@class QYKFNIMQChatAddChannelCategoryRoleParam;
@class QYKFNIMQChatRemoveChannelCategoryRoleParam;
@class QYKFNIMQChatUpdateChannelCategoryRoleParam;
@class QYKFNIMQChatGetChannelCategoryRolesParam;
@class QYKFNIMQChatAddChannelCategoryMemberRoleParam;
@class QYKFNIMQChatRemoveChannelCategoryMemberRoleParam;
@class QYKFNIMQChatUpdateChannelCategoryMemberRoleParam;
@class QYKFNIMQChatGetChannelCategoryMemberRolesParam;

@class QYKFNIMQChatChannelCategoryRole;
@class QYKFNIMQChatChannelCategoryMemberRole;
@class QYKFNIMQChatGetChannelCategoryRolesResult;
@class QYKFNIMQChatGetChannelCategoryMemberRolesResult;

typedef QYKFNIMQChatHandler QYKFNIMQChatRemoveChannelCategoryRoleHandler;
typedef QYKFNIMQChatHandler QYKFNIMQChatRemoveChannelCategoryMemberRoleHandler;

/**
 * 创建服务器身份组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatCreateServerRoleHandler)(NSError *__nullable error, QYKFNIMQChatServerRole *__nullable result);

/**
 * 更新服务器身份组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateServerRoleHandler)(NSError *__nullable error, QYKFNIMQChatServerRole *__nullable result);

/**
 * 查询服务器下身份组列表的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServerRolesHandler)(NSError *__nullable error, QYKFNIMQChatGetServerRolesResult *__nullable result);

/**
 * 将某身份组加入某频道的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatAddChannelRoleHandler)(NSError *__nullable error, QYKFNIMQChatChannelRole *__nullable result);

/**
 * 更新某身份组加入某频道的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateChannelRoleHandler)(NSError *__nullable error, QYKFNIMQChatChannelRole *__nullable result);

/**
 * 查询某频道下的身份组信息列表的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelRolesHandler)(NSError *__nullable error, QYKFNIMQChatGetChannelRolesResult *__nullable result);

/**
 * 为某个人定制某频道的权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatAddMemberRoleHandler)(NSError *__nullable error, QYKFNIMQChatMemberRole *__nullable result);

/**
 * 更新某个人定制某频道的权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateMemberRoleHandler)(NSError *__nullable error, QYKFNIMQChatMemberRole *__nullable result);

/**
 * 查询channel下人的定制权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetMemberRolesHandler)(NSError *__nullable error, QYKFNIMQChatGetMemberRolesResult *__nullable result);

/**
 * 查询某服务器下某身份组下的成员列表的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServerRoleMembersHandler)(NSError *__nullable error, QYKFNIMQChatGetServerRoleMembersResult *__nullable result);

/**
 * 通过accid查询自定义身份组列表的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetServerRolesByAccidHandler)(NSError *__nullable error, QYKFNIMQChatGetServerRolesByAccidResult *__nullable result);

/**
 * 将某些人加入某服务器身份组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatAddServerRoleMembersHandler)(NSError *__nullable error, QYKFNIMQChatAddServerRoleMembersResult *__nullable result);

/**
 * 将某些人移除某服务器身份组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatRemoveServerRoleMembersHandler)(NSError *__nullable error, QYKFNIMQChatRemoveServerRoleMembersResult *__nullable result);

/**
 * 查询一批accids的自定义身份组列表的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingAccidsInServerRoleHandler)(NSError *__nullable error, QYKFNIMQChatGetExistingAccidsInServerRoleResult *__nullable result);

/**
 * 查询一批服务器身份组在频道中的身份组信息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingChannelRolesByServerRoleIdsHandler)(NSError *__nullable error, QYKFNIMQChatGetExistingChannelRolesByServerRoleIdsResult *__nullable result);

/**
 * 查询一批accids在频道中配置了权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingAccidsOfMemberRolesHandler)(NSError *__nullable error, QYKFNIMQChatGetExistingAccidsOfMemberRolesResult *__nullable result);

/**
 * 批量更新服务器身份组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatupdateServerRolePrioritiesHandler)(NSError *__nullable error, QYKFNIMQChatupdateServerRolePrioritiesResult *__nullable result);

/**
 * 查询一批accids是否在某个服务器身份组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetExistingServerRoleMembersByAccidsHandler)(NSError *__nullable error, QYKFNIMQChatGetExistingServerRoleMembersByAccidsResult *__nullable result);
/**
 * 查询自己是否有某个权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatCheckPermissionHandler)(NSError *__nullable error, BOOL result);


#pragma mark - 频道分组
/**
 * 将某身份组加入某频道分组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatAddChannelCategoryRoleHandler)(NSError *__nullable error, QYKFNIMQChatChannelCategoryRole *__nullable result);

/**
 * 更新某身份组加入某频道分组的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateChannelCategoryRoleHandler)(NSError *__nullable error, QYKFNIMQChatChannelCategoryRole *__nullable result);

/**
 * 查询某频道分组下的身份组信息列表的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelCategoryRolesHandler)(NSError *__nullable error, QYKFNIMQChatGetChannelCategoryRolesResult *__nullable result);

/**
 * 为某个人定制某频道分组的权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatAddChannelCategoryMemberRoleHandler)(NSError *__nullable error, QYKFNIMQChatChannelCategoryMemberRole *__nullable result);

/**
 * 更新某个人定制某频道分组的权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateChannelCategoryMemberRoleHandler)(NSError *__nullable error, QYKFNIMQChatChannelCategoryMemberRole *__nullable result);

/**
 * 获取channel分组下人的定制权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetChannelCategoryMemberRolesHandler)(NSError *__nullable error, QYKFNIMQChatGetChannelCategoryMemberRolesResult *__nullable result);
/**
 * 查询自己是否有某些权限的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatCheckPermissionsHandler)(NSError *__nullable error, QYKFNIMQChatCheckPermissionsResult *__nullable result);
/**
 *   圈组身份组管理器回调
 */
@protocol QYKFNIMQChatRoleManagerDelegate <NSObject>

@optional

@end

/**
 *  圈组身份组管理器
 */
@protocol QYKFNIMQChatRoleManager <NSObject>
/**
 * 创建服务器身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)createServerRole:(QYKFNIMQChatCreateServerRoleParam *)param
                  completion:(nullable QYKFNIMQChatCreateServerRoleHandler)completion;

/**
 * 删除服务器身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)deleteServerRole:(QYKFNIMQChatDeleteServerRoleParam *)param
                  completion:(nullable QYKFNIMQChatDeleteServerRoleHandler)completion;

/**
 * 更新服务器身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateServerRole:(QYKFNIMQChatUpdateServerRoleParam *)param
                  completion:(nullable QYKFNIMQChatUpdateServerRoleHandler)completion;

/**
 * 获取服务器身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServerRoles:(QYKFNIMQChatGetServerRolesParam *)param
                 completion:(nullable QYKFNIMQChatGetServerRolesHandler)completion;

/**
 * 将某身份组加入某频道
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)addChannelRole:(QYKFNIMQChatAddChannelRoleParam *)param
                   completion:(nullable QYKFNIMQChatAddChannelRoleHandler)completion;

/**
 * 删除某频道下的某身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)removeChannelRole:(QYKFNIMQChatRemoveChannelRoleParam *)param
                   completion:(nullable QYKFNIMQChatRemoveChannelRoleHandler)completion;

/**
 * 修改频道下某身份组的权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateChannelRole:(QYKFNIMQChatUpdateChannelRoleParam *)param
                   completion:(nullable QYKFNIMQChatUpdateChannelRoleHandler)completion;

/**
 * 查询某频道下的身份组信息列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelRoles:(QYKFNIMQChatGetChannelRolesParam *)param
                  completion:(nullable QYKFNIMQChatGetChannelRolesHandler)completion;

/**
 * 为某个人定制某频道的权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)addMemberRole:(QYKFNIMQChatAddMemberRoleParam *)param
                completion:(nullable QYKFNIMQChatAddMemberRoleHandler)completion;

/**
 * 删除频道下某人的定制权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)removeMemberRole:(QYKFNIMQChatRemoveMemberRoleParam *)param
                completion:(nullable QYKFNIMQChatRemoveMemberRoleHandler)completion;

/**
 * 修改某人的定制权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateMemberRole:(QYKFNIMQChatUpdateMemberRoleParam *)param
                completion:(nullable QYKFNIMQChatUpdateMemberRoleHandler)completion;

/**
 * 查询channel下人的定制权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getMemberRoles:(QYKFNIMQChatGetMemberRolesParam *)param
               completion:(nullable QYKFNIMQChatGetMemberRolesHandler)completion;

#pragma mark - 频道分组
/**
 * 将某身份组加入某频道分组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)addChannelCategoryRole:(QYKFNIMQChatAddChannelCategoryRoleParam *)param
                   completion:(nullable QYKFNIMQChatAddChannelCategoryRoleHandler)completion;

/**
 * 删除某频道分组下的某身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)removeChannelCategoryRole:(QYKFNIMQChatRemoveChannelCategoryRoleParam *)param
                   completion:(nullable QYKFNIMQChatRemoveChannelCategoryRoleHandler)completion;

/**
 * 修改频道分组下某身份组的权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateChannelCategoryRole:(QYKFNIMQChatUpdateChannelCategoryRoleParam *)param
                   completion:(nullable QYKFNIMQChatUpdateChannelCategoryRoleHandler)completion;

/**
 * 查询某频道分组下的身份组信息列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelCategoryRoles:(QYKFNIMQChatGetChannelCategoryRolesParam *)param
                  completion:(nullable QYKFNIMQChatGetChannelCategoryRolesHandler)completion;

/**
 * 为某个人定制某频道分组的权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)addChannelCategoryMemberRole:(QYKFNIMQChatAddChannelCategoryMemberRoleParam *)param
                completion:(nullable QYKFNIMQChatAddChannelCategoryMemberRoleHandler)completion;

/**
 * 删除频道分组下某人的定制权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)removeChannelCategoryMemberRole:(QYKFNIMQChatRemoveChannelCategoryMemberRoleParam *)param
                completion:(nullable QYKFNIMQChatRemoveChannelCategoryMemberRoleHandler)completion;

/**
 * 修改频道分组某人的定制权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateChannelCategoryMemberRole:(QYKFNIMQChatUpdateChannelCategoryMemberRoleParam *)param
                completion:(nullable QYKFNIMQChatUpdateChannelCategoryMemberRoleHandler)completion;

/**
 * 查询频道分组下人的定制权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getChannelCategoryMemberRoles:(QYKFNIMQChatGetChannelCategoryMemberRolesParam *)param
               completion:(nullable QYKFNIMQChatGetChannelCategoryMemberRolesHandler)completion;

#pragma mark -服务器身份组
/**
 * 将某些人加入某服务器身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)addServerRoleMembers:(QYKFNIMQChatAddServerRoleMembersParam *)param
                        completion:(nullable QYKFNIMQChatAddServerRoleMembersHandler)completion;

/**
 * 将某些人移除某服务器身份组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)removeServerRoleMember:(QYKFNIMQChatRemoveServerRoleMemberParam *)param
                        completion:(nullable QYKFNIMQChatRemoveServerRoleMembersHandler)completion;

/**
 * 查询某服务器下某身份组下的成员列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServerRoleMembers:(QYKFNIMQChatGetServerRoleMembersParam *)param
                      completion:(nullable QYKFNIMQChatGetServerRoleMembersHandler)completion;

/**
 * 通过accid查询自定义身份组列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getServerRolesByAccid:(QYKFNIMQChatGetServerRolesByAccidParam *)param
                     completion:(nullable QYKFNIMQChatGetServerRolesByAccidHandler)completion;
/**
 * 查询一批accids的自定义身份组列表
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getExistingAccidsInServerRole:(QYKFNIMQChatGetExistingAccidsInServerRoleParam *)param
                     completion:(nullable QYKFNIMQChatGetExistingAccidsInServerRoleHandler)completion;

/**
 * 查询一批服务器身份组在频道中的身份组信息，只会返回存在的
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getExistingChannelRolesByServerRoleIds:(QYKFNIMQChatGetExistingChannelRolesByServerRoleIdsParam *)param
                     completion:(nullable QYKFNIMQChatGetExistingChannelRolesByServerRoleIdsHandler)completion;

/**
 * 查询一批accids在频道中配置了权限的，只会返回存在的
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getExistingAccidsOfMemberRoles:(QYKFNIMQChatGetExistingAccidsOfMemberRolesParam *)param
                     completion:(nullable QYKFNIMQChatGetExistingAccidsOfMemberRolesHandler)completion;

/**
 * 批量更新服务器身份组的权限优先级
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateServerRolePriorities:(QYKFNIMQChatupdateServerRolePrioritiesParam *)param
                     completion:(nullable QYKFNIMQChatupdateServerRolePrioritiesHandler)completion;
/**
* 查询一批accids是否在某个服务器身份组,返回在的成员信息
*
* @param param 传入参数
* @param completion 结果回调
*/
- (void)getExistingServerRoleMembersByAccids:(QYKFNIMQChatGetExistingServerRoleMembersByAccidsParam *)param
                    completion:(nullable QYKFNIMQChatGetExistingServerRoleMembersByAccidsHandler)completion;
/**
 * 查询自己是否有某个权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)checkPermission:(QYKFNIMQChatCheckPermissionParam *)param
                    completion:(nullable QYKFNIMQChatCheckPermissionHandler)completion;

/**
 * 查询自己是否拥有某些权限
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)checkPermissions:(QYKFNIMQChatCheckPermissionsParam *)param
                      completion:(nullable QYKFNIMQChatCheckPermissionsHandler)completion;
/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<QYKFNIMQChatRoleManagerDelegate>)delegate;

/**
 *  移除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<QYKFNIMQChatRoleManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
