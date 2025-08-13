//
//  QYKFNIMQChatMessageManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "QYKFNIMQChatAPIDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMQChatMessage;
@class QYKFNIMSession;

@class QYKFNIMQChatSendSystemNotificationParam;
@class QYKFNIMQChatSendSystemNotificationResult;
@class QYKFNIMQChatReceiveSystemNotificationResult;
@class QYKFNIMQChatUpdateSystemNotificationParam;
@class QYKFNIMQChatUpdateSystemNotificationResult;
@class QYKFNIMQChatSystemNotificationUpdateResult;
@class QYKFNIMQChatMarkSystemNotificationsReadParam;

@class QYKFNIMQChatGetMessageHistoryParam;
@class QYKFNIMQChatGetMessageHistoryByIdsParam;
@class QYKFNIMQChatMessageServerIdInfo;
@class QYKFNIMQChatGetMessageHistoryResult;
@class QYKFNIMQChatGetMessageCacheParam;
@class QYKFNIMQChatGetMessageCacheResult;
@class QYKFNIMQChatUpdateMessageParam;
@class QYKFNIMQChatRevokeMessageParam;
@class QYKFNIMQChatDeleteMessageParam;
@class QYKFNIMQChatUpdateMessageResult;
@class QYKFNIMQChatUpdateMessageEvent;

@class QYKFNIMQChatMarkMessageReadParam;
@class QYKFNIMQChatUnreadInfoChangedEvent;
@class QYKFNIMQChatResendSystemNotificationParam;
@class QYKFNIMQChatMessageTypingEvent;
@class QYKFNIMQChatGetLastMessageOfChannelsParam;
@class QYKFNIMQChatGetLastMessageOfChannelsResult;
@class QYKFNIMQChatServerUnreadInfo;
@class QYKFNIMQChatSearchMsgByPageParam;
@class QYKFNIMQChatSearchMsgByPageResult;
@class QYKFNIMQChatGetMentionedMeMessagesParam;
@class QYKFNIMQChatGetMentionedMeMessagesResult;
@class QYKFNIMQChatMarkServerReadResult;
@class QYKFNIMQChatAreMentionedMeMessagesParam;
@class QYKFNIMQChatAreMentionedMeMessagesResult;

/**
 * 发送自定义通知消息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSendSystemNotificationHandler)(NSError *__nullable error, QYKFNIMQChatSendSystemNotificationResult *__nullable result);

/**
 * 拉取聊天消息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetMessageHistoryHandler)(NSError *__nullable error, QYKFNIMQChatGetMessageHistoryResult *__nullable result);

/**
 * 更新圈组消息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateMessageHandler)(NSError *__nullable error, QYKFNIMQChatUpdateMessageResult *__nullable result);

/**
 * 更新系统通知的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatUpdateSystemNotificationHandler)(NSError *__nullable error, QYKFNIMQChatUpdateSystemNotificationResult *__nullable result);

/**
 * 拉取缓存消息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetMessageCacheHandler)(NSError *__nullable error, QYKFNIMQChatGetMessageCacheResult *__nullable result);

/**
 * 发送消息正在输入事件的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSendMessageTypingEventHandler)(NSError *__nullable error, QYKFNIMQChatMessageTypingEvent *__nullable result);

/**
 * 批量查询频道最后一条消息的回调
 *
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetLastMessageOfChannelsHandler)(NSError *__nullable error, QYKFNIMQChatGetLastMessageOfChannelsResult *__nullable result);

/**
 * 分页搜索圈组消息的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatSearchMsgByPageHandler)(NSError *__nullable error, QYKFNIMQChatSearchMsgByPageResult *__nullable result);

/**
 * 分页搜索圈组 @ 我的消息的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatGetMentionedMeMessagesHandler)(NSError *__nullable error, QYKFNIMQChatGetMentionedMeMessagesResult *__nullable result);

/**
 * 批量查询消息是否 @ 当前用户的回调
 * @param error 错误信息
 * @param result 回调结果
 */
typedef void(^QYKFNIMQChatAreMentionedMeMessagesHandler)(NSError *__nullable error, QYKFNIMQChatAreMentionedMeMessagesResult *__nullable result);



/**
 *   圈组消息管理器回调
 */
@protocol QYKFNIMQChatMessageManagerDelegate <NSObject>

@optional

/**
 *  即将发送消息回调
 *  @discussion 因为发消息之前可能会有个准备过程,所以需要在收到这个回调时才将消息加入到 Datasource 中
 *  @param message 当前发送的消息
 */
- (void)willSendMessage:(QYKFNIMQChatMessage *)message;


/**
 *  上传资源文件成功的回调
 *  @discussion 对于需要上传资源的消息(图片，视频，音频等)，SDK 将在上传资源成功后通过这个接口进行回调，上层可以在收到该回调后进行推送信息的重新配置 (APNS payload)
 *  @param urlString 当前消息资源获得的 url 地址
 *  @param message 当前发送的消息
 */
- (void)uploadAttachmentSuccess:(NSString *)urlString
                     forMessage:(QYKFNIMQChatMessage *)message;

/**
 *  发送消息进度回调
 *
 *  @param message  当前发送的消息
 *  @param progress 进度
 */
- (void)sendMessage:(QYKFNIMQChatMessage *)message
           progress:(float)progress;


/**
 *  发送消息完成回调
 *
 *  @param message 当前发送的消息
 *  @param error   失败原因,如果发送成功则error为nil
 */
- (void)sendMessage:(QYKFNIMQChatMessage *)message
    didCompleteWithError:(nullable NSError *)error;

/**
 *  收取消息附件回调
 *  @param message  当前收取的消息
 *  @param progress 进度
 *  @discussion 附件包括:图片,视频的缩略图,语音文件
 */
- (void)fetchMessageAttachment:(QYKFNIMQChatMessage *)message
                      progress:(float)progress;


/**
 *  收取消息附件完成回调
 *
 *  @param message 当前收取的消息
 *  @param error   错误返回,如果收取成功,error为nil
 */
- (void)fetchMessageAttachment:(QYKFNIMQChatMessage *)message
          didCompleteWithError:(nullable NSError *)error;

/**
 *  收到消息回调
 *
 *  @param messages 消息列表,内部为QYKFNIMQChatMessage
 */
- (void)onRecvMessages:(NSArray<QYKFNIMQChatMessage *> *)messages;

/**
 * 圈组消息更新事件回调
 *
 * @param event 事件详情
 */
- (void)onMessageUpdate:(QYKFNIMQChatUpdateMessageEvent *)event;

/**
 * 圈组未读信息变更事件回调(频道)
 *
 * @param event 事件详情
 */
- (void)unreadInfoChanged:(QYKFNIMQChatUnreadInfoChangedEvent *)event;

/**
 * 圈组服务器未读信息变更事件回调
 *
 * @param serverUnreadInfoDic 事件详情, key为@(serverId)（服务器ID的NSNumber），value 为QYKFNIMQChatServerUnreadInfo
 */
- (void)serverUnreadInfoChanged:(NSDictionary <NSNumber *, QYKFNIMQChatServerUnreadInfo *> *)serverUnreadInfoDic;

/**
 * 圈组系统通知接收事件回调
 *
 * @param result 结果详情
 */
- (void)onRecvSystemNotification:(QYKFNIMQChatReceiveSystemNotificationResult *)result;

/**
 * 圈组类消息typing事件回调
 *
 * @param result 结果详情
 */
- (void)onRecvTypingEvent:(QYKFNIMQChatMessageTypingEvent *)event;

/**
 * 圈组系统通知更新事件回调
 *
 * @param result 结果详情
 */
- (void)onSystemNotificationUpdate:(QYKFNIMQChatSystemNotificationUpdateResult *)result;



@end

/**
 *  圈组消息管理器
 */
@protocol QYKFNIMQChatMessageManager <NSObject>

/**
 *  发送消息
 *
 *  @param message 消息
 *  @param session 接受方
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)sendMessage:(QYKFNIMQChatMessage *)message
          toSession:(QYKFNIMSession *)session
              error:(NSError * __nullable *)error;

/**
 *  异步发送消息
 *
 *  @param message 消息
 *  @param session 接收方
 *  @param completion 发送完成后的回调，这里的回调完成只表示当前这个函数调用完成，需要后续的回调才能判断消息是否已经发送至服务器
 */
- (void)sendMessage:(QYKFNIMQChatMessage *)message
          toSession:(QYKFNIMSession *)session
         completion:(nullable QYKFNIMQChatHandler)completion;

/**
 *  取消正在发送的消息
 *
 *  @param message 目标消息
 *  @return 是否调用成功
 */
- (BOOL)cancelSendingMessage:(QYKFNIMQChatMessage *)message;

/**
 *  重发消息
 *
 *  @param message 重发消息
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)resendMessage:(QYKFNIMQChatMessage *)message
                error:(NSError * __nullable *)error;

/**
 *  生成转发消息
 *  得到转发消息后，开发者需自己再调用sendForwardMessage:toSession:error: 进行发送， 和 直接调用forwardMessage:toSession:error:效果一样，但是这样可以得到转发消息的进度方法回调和是否转发成功方法回调
 *
 *  @param message 要转发的消息
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 生成的需要转发的消息
 */
- (nullable QYKFNIMQChatMessage *)makeForwardMessage:(QYKFNIMQChatMessage *)message
                                           error:(NSError * __nullable *)error;

/**
 *  发送生成的转发消息
 *
 *  @param message 转发的消息
 *  @param session 接受方
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)sendForwardMessage:(QYKFNIMQChatMessage *)message
                 toSession:(QYKFNIMSession *)session
                     error:(NSError * __nullable *)error;

/**
 *  转发消息
 *
 *  @param message 消息
 *  @param session 接收方
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)forwardMessage:(QYKFNIMQChatMessage *)message
             toSession:(QYKFNIMSession *)session
                 error:(NSError * __nullable *)error;

/**
 *  消息是否正在传输 (发送/接受附件)
 *
 *  @param message 消息
 *
 *  @return 是否正在传输
 */
- (BOOL)messageInTransport:(QYKFNIMQChatMessage *)message;

/**
 *  传输消息的进度 (发送/接受附件)
 *
 *  @param message 消息
 *
 *  @return 正在传输的消息进度,如果消息不在传输,则返回0
 */
- (float)messageTransportProgress:(QYKFNIMQChatMessage *)message;

/**
 *  收取消息附件
 *
 *  @param message 需要收取附件的消息
 *  @param error   错误
 *
 *  @return 是否调用成功
 *  @discussion 附件包括：图片消息的图片缩略图，视频消息的视频缩略图，音频消息的音频文件，文件消息的文件以及自定义消息中的自定义文件
 */
- (BOOL)fetchMessageAttachment:(QYKFNIMQChatMessage *)message
                         error:(NSError * __nullable *)error;

/**
 *  取消收取消息附件
 *
 *  @param message 需要取消收取附件的消息
 *
 *  @discussion 附件包括：图片消息的图片缩略图，视频消息的视频缩略图，音频消息的音频文件，文件消息的文件以及自定义消息中的自定义文件
 */
- (void)cancelFetchingMessageAttachment:(QYKFNIMQChatMessage *)message;

/**
 * 更新圈组消息
 * @discussion 支持文本，服务器扩展，自定义消息状态
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)updateMessage:(QYKFNIMQChatUpdateMessageParam *)param
           completion:(nullable QYKFNIMQChatUpdateMessageHandler)completion;

/**
 * 撤回圈组消息
 * @discussion
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)revokeMessage:(QYKFNIMQChatRevokeMessageParam *)param
           completion:(nullable QYKFNIMQChatUpdateMessageHandler)completion;

/**
 * 删除圈组消息
 * @discussion
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)deleteMessage:(QYKFNIMQChatDeleteMessageParam *)param
           completion:(nullable QYKFNIMQChatUpdateMessageHandler)completion;

/**
 * 标记消息已读
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)markMessageRead:(QYKFNIMQChatMarkMessageReadParam *)param
             completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 从服务端查询历史消息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getMessageHistory:(QYKFNIMQChatGetMessageHistoryParam *)param
               completion:(nullable QYKFNIMQChatGetMessageHistoryHandler)completion;

/**
 * 从服务端按ID查询历史消息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getMessageHistoryByIds:(QYKFNIMQChatGetMessageHistoryByIdsParam *)param
                    completion:(nullable QYKFNIMQChatGetMessageHistoryHandler)completion;

/**
 * 发送自定义系统通知
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)sendSystemNotification:(QYKFNIMQChatSendSystemNotificationParam *)param
                    completion:(nullable QYKFNIMQChatSendSystemNotificationHandler)completion;

/**
 * 重发自定义系统通知
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)resendSystemNotification:(QYKFNIMQChatResendSystemNotificationParam *)param
                    completion:(nullable QYKFNIMQChatSendSystemNotificationHandler)completion;

/**
 * 更新系统通知（可以更新状态、也可以更新内容）
 */
- (void)updateSystemNotification:(QYKFNIMQChatUpdateSystemNotificationParam *)param
             completion:(nullable QYKFNIMQChatUpdateSystemNotificationHandler)completion;

/**
 * 标记系统通知已读
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)markSystemNotificationsRead:(QYKFNIMQChatMarkSystemNotificationsReadParam *)param
                         completion:(nullable QYKFNIMQChatHandler)completion;

/**
 * 发送正在输入等自定义事件
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)sendMessageTypingEvent:(QYKFNIMQChatMessageTypingEvent *)param
                         completion:(nullable QYKFNIMQChatSendMessageTypingEventHandler)completion;

/**
 * 从本地缓存查询消息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getMessageCache:(QYKFNIMQChatGetMessageCacheParam *)param
             completion:(nullable QYKFNIMQChatGetMessageCacheHandler)completion;

/**
 * 批量查询频道最后一条消息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getLastMessageOfChannels:(QYKFNIMQChatGetLastMessageOfChannelsParam *)param
                      completion:(nullable QYKFNIMQChatGetLastMessageOfChannelsHandler)completion;

/**
 * 搜索圈组消息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)searchMsgByPage:(QYKFNIMQChatSearchMsgByPageParam *)param
                      completion:(nullable QYKFNIMQChatSearchMsgByPageHandler)completion;

/**
 * 搜索圈组 @ 我的消息
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)getMentionedMeMessages:(QYKFNIMQChatGetMentionedMeMessagesParam *)param
                      completion:(nullable QYKFNIMQChatGetMentionedMeMessagesHandler)completion;


/**
 * 批量查询消息是否 @ 当前用户
 *
 * @param param 传入参数
 * @param completion 结果回调
 */
- (void)areMentionedMeMessages:(QYKFNIMQChatAreMentionedMeMessagesParam *)param
                      completion:(nullable QYKFNIMQChatAreMentionedMeMessagesHandler)completion;

/**
 * 清理消息本地缓存
 */
- (void)clearMessageCache;

/**
 * 增加一条缓存数据，如果该频道下已经存在数据，则被新数据覆盖。
 *
 * @param serverId 服务器ID，大于0
 * @param channelId 频道ID，大于0
 * @param text 要增加的内容，不能是空指针
 * @return YES：成功添加或者替换；NO：其它
 */
- (BOOL)insertOrReplaceTextCache:(unsigned long long)serverId
                       channelId:(unsigned long long)channelId
                            value:(NSString *)value;

/**
 * 删除缓存数据。
 * serverId > 0 && channelId > 0：删除指定频道的数据
 * serverId > 0 && channelId == 0：删除指定服务器下所有频道的数据
 * serverId == 0 && channelId > 0：删除指定频道ID的数据
 * serverId == 0 && channelId == 0：清空数据
 *
 * @param serverId 服务器ID，大于等于0
 * @param channelId 频道ID，大于等于0
 * @return YES：完成删除操作，包括数据存在的删除和数据不存在的删除；NO：其它
 */
- (BOOL)deleteTextCache:(unsigned long long)serverId
              channelId:(unsigned long long)channelId;

/**
 * 查询指定频道的缓存数据。
 *
 * @param serverId
 * @param channelId
 * @return
 */
- (nullable NSString *)getTextCache:(unsigned long long)serverId
                 channelId:(unsigned long long)channelId;

/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<QYKFNIMQChatMessageManagerDelegate>)delegate;

/**
 *  移除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<QYKFNIMQChatMessageManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
