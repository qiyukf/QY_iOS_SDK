//
//  QYKFNIMQChatRTCChannelManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "QYKFNIMQChatAPIDefs.h"

NS_ASSUME_NONNULL_BEGIN


@class QYKFNIMQChatRTCChannelInfo;
@class QYKFNIMQChatRTCChannelOnlineMember;
@class QYKFNIMQChatChannelIdInfo;
@class QYKFNIMQChatRTCUpdateChannelInfoParam;
@class QYKFNIMQChatRequestTokenResult;
/**
 *  获取token的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatRequestRTCTokenHandler)(NSError *__nullable error, QYKFNIMQChatRequestTokenResult *__nullable result);

/**
 *  获取多媒体频道信息的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetRTCChannelHandler)(NSError *__nullable error, QYKFNIMQChatRTCChannelInfo *__nullable result);

/**
 *  获取多媒体频道在线成员的结果回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetRTCChannelOnlineMembersHandler)(NSError *__nullable error, NSArray <QYKFNIMQChatRTCChannelOnlineMember *> *__nullable result);


/**
 *  圈组频道管理器
 */
@protocol QYKFNIMQChatRTCChannelManager <NSObject>

/**
 *  获取token
 *
 * @param deviceId id
 * @param completion 结果回调
 */
- (void)requestTokenWithDeviceId:(NSString *)deviceId completion:(nullable QYKFNIMQChatRequestRTCTokenHandler)completion;

/**
 * 修改圈组多频道信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateRTCChannel:(nonnull QYKFNIMQChatRTCUpdateChannelInfoParam *)param
           completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 获取多媒体频道信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getRTCChannelInfo:(nonnull QYKFNIMQChatChannelIdInfo *)param
           completion:(nullable QYKFNIMQChatGetRTCChannelHandler)completion;

/**
 * 查询多媒体频道在线成员信息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getRTCChannelOnlineMembers:(nonnull QYKFNIMQChatChannelIdInfo *)param
         completion:(nullable QYKFNIMQChatGetRTCChannelOnlineMembersHandler)completion;
@end

NS_ASSUME_NONNULL_END
