//
//  NIMNIMQChatManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "QYKFNIMQChatAPIDefs.h"

#import "QYKFNIMLoginManagerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMLoginClient;
@class QYKFNIMLoginKickoutResult;

@class QYKFNIMQChatLoginParam;
@class QYKFNIMQChatLoginResult;
@class QYKFNIMQChatOnlineStatusResult;

/**
 * 进入圈组的回调
 */
typedef void(^QYKFNIMQChatLoginHandler)(NSError *__nullable error, QYKFNIMQChatLoginResult *__nullable result);

/**
 *  圈组管理器回调
 */
@protocol QYKFNIMQChatManagerDelegate <NSObject>

@optional
/**
 * 被踢出圈组回调
 *
 * @param result 结果详情
 */
- (void)qchatKickedOut:(QYKFNIMLoginKickoutResult *)result;

/**
 * 圈组多端登录发生变化
 * 当有其他端登录或者注销时，会通过此接口通知到UI
 * 登录成功后，如果有其他端登录着，也会发出通知
 *
 * @param type 多端登录变化类型
 */
- (void)qchatMultiSpotLogin:(QYKFNIMMultiLoginType)type;

/**
 * 圈组在线状态/登录状态回调
 *
 * @param result 结果详情
 */
- (void)qchatOnlineStatus:(QYKFNIMQChatOnlineStatusResult *)result;

/**
 *  圈组自动登录出错
 *
 *  @param error  自动登录出错原因
 */
- (void)qchatAutoLoginFailed:(NSError *)error;

/**
 * 圈组自动退出
 *  @discussion 当前圈组需要依赖IM功能，当IM账号退出，或登录账号与圈组不同时，圈组自动退出
 */
- (void)qchatAutoLogout;

@end

/**
 * 圈组管理器
 */
@protocol QYKFNIMQChatManager <NSObject>

/**
 * 进入圈组
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)login:(nullable QYKFNIMQChatLoginParam *)param
   completion:(nullable QYKFNIMQChatLoginHandler)completion;

/**
 * 退出圈组
 *
 * @param completion 结果回调
 */
- (void)logout:(nullable QYKFNIMQChatHandler)completion;

/**
 * 踢掉多端在线的其他端
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)kickOtherClient:(QYKFNIMLoginClient *)client
             completion:(nullable QYKFNIMQChatHandler)completion;

/**
 *  返回当前登录帐号
 *
 *  @return 当前登录帐号
 */
- (nullable NSString *)currentAccount;

/**
 *  获取当前登录圈组的设备列表
 *
 *  @return 当前登录设备列表 内部是QYKFNIMLoginClient,不包括自己
 */
- (nullable NSArray<QYKFNIMLoginClient *> *)currentLoginClients;

/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<QYKFNIMQChatManagerDelegate>)delegate;

/**
 *  移除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<QYKFNIMQChatManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
