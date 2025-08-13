//
//  QYKFNIMQChatApnsManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMQChatAPIDefs.h"
#import "QYKFNIMApnsManagerProtocol.h"
#import "QYKFNIMPushNotificationSetting.h"

@class QYKFNIMQChatChannelIdInfo;
@class QYKFNIMQChatUserPushNotificationConfig;
@class QYKFNIMQChatChannelCategoryIdInfo;
NS_ASSUME_NONNULL_BEGIN

/**
 *  圈组获取用户推送配置回调
 *
 *  @param error 错误信息
 *  @param config 配置信息
 */
typedef void(^QYKFNIMQChatGetUserPushNotificationConfigHandler)(NSError *__nullable error,
                                                            NSArray<QYKFNIMQChatUserPushNotificationConfig *> *__nullable config);

/**
 *  推送委托
 */
@protocol QYKFNIMQChatApnsManagerDelegate <NSObject>

@optional

@end

/**
 *  推送协议
 */
@protocol QYKFNIMQChatApnsManager <NSObject>
/**
 *  获取当前的推送免打扰设置
 *
 *  @return 推送设置
 */
- (nullable QYKFNIMPushNotificationSetting *)currentSetting;

/**
 *  更新推送免打扰设置
 *
 *  @param setting    推送设置
 *  @param completion 完成的回调
 */
- (void)updateApnsSetting:(QYKFNIMPushNotificationSetting *)setting
               completion:(nullable QYKFNIMApnsHandler)completion;

/**
 *  注册获取 badge 数量的回调函数
 *
 *  @param handler 获取 badge 回调
 *  @discussion 默认场景下，云信会将所有未读数量统一汇报给服务器，包括需要提醒和不需要提醒的会话未读数，上层可以通过注册该接口进行调整
 */
- (void)registerBadgeCountHandler:(QYKFNIMBadgeHandler)handler;

/**
 *  更新服务器推送消息等级配置
 *
 *  @param profile    推送消息等级配置
 *  @param serverId    服务器ID
 *  @param completion 完成的回调
 */
- (void)updatePushNotificationProfile:(QYKFNIMPushNotificationProfile)profile
                               server:(unsigned long long)serverId
                           completion:(nullable QYKFNIMQChatHandler)completion;

/**
 *  更新频道推送消息等级配置
 *
 *  @param profile    推送消息等级配置
 *  @param channelIdInfo    频道ID信息
 *  @param completion 完成的回调
 */
- (void)updatePushNotificationProfile:(QYKFNIMPushNotificationProfile)profile
                              channel:(QYKFNIMQChatChannelIdInfo *)channelIdInfo
                           completion:(nullable QYKFNIMQChatHandler)completion;

/**
 *  更新频道分组推送消息等级配置
 *
 *  @param profile    推送消息等级配置
 *  @param categoryIdInfo    频道分组ID信息
 *  @param completion 完成的回调
 */
- (void)updatePushNotificationProfile:(QYKFNIMPushNotificationProfile)profile
                              channelCategory:(QYKFNIMQChatChannelCategoryIdInfo *)categoryIdInfo
                           completion:(nullable QYKFNIMQChatHandler)completion;

/**
 *  获取服务器维度用户推送配置
 *
 *  @param serverIds    服务器ID数组
 *  @param completion 完成的回调
 *  @discussion 限制单次查询服务器数量为10
 */
- (void)getUserPushNotificationConfigByServer:(NSArray<NSNumber *> *)serverIds
                                   completion:(nullable QYKFNIMQChatGetUserPushNotificationConfigHandler)completion;

/**
 *  获取频道维度用户推送配置
 *
 *  @param channelIdInfo    频道ID信息数组
 *  @param completion 完成的回调
 *  @discussion 限制单次查询频道数量为10
 */
- (void)getUserPushNotificationConfigByChannel:(NSArray<QYKFNIMQChatChannelIdInfo *> *)channelIdInfo
                                    completion:(nullable QYKFNIMQChatGetUserPushNotificationConfigHandler)completion;
/**
 *  获取频道分组维度用户推送配置
 *
 *  @param categoryIdInfo    频道分组ID信息数组
 *  @param completion 完成的回调
 *  @discussion 限制单次查询频道数量为10
 */
- (void)getUserPushNotificationConfigByChannelCategories:(NSArray<QYKFNIMQChatChannelCategoryIdInfo *> *)categoryIdInfos
                                    completion:(nullable QYKFNIMQChatGetUserPushNotificationConfigHandler)completion;
/**
 *  添加委托
 *
 *  @param delegate 委托
 */
- (void)addDelegate:(id<QYKFNIMQChatApnsManagerDelegate>)delegate;


/**
 *  移除委托
 *
 *  @param delegate 委托
 */
- (void)removeDelegate:(id<QYKFNIMQChatApnsManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
