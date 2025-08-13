//
//  NIMThreadTalkManagerProtocol.h
//  NIMLib
//
//  Created by He on 2020/3/27.
//  Copyright © 2020 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMChatManagerProtocol.h"

@class QYKFNIMMessage;
@class QYKFNIMSession;
@class QYKFNIMRecentSession;
@class QYKFNIMThreadTalkFetchOption;
@class QYKFNIMThreadTalkFetchResult;
@class QYKFNIMChatExtendBasicInfo;
@class QYKFNIMQuickComment;
@class QYKFNIMCollectInfo;
@class QYKFNIMCollectQueryOptions;
@class QYKFNIMAddCollectParams;
@class QYKFNIMSyncMessagePinResponse;
@class QYKFNIMMessagePinItem;
@class QYKFNIMStickTopSessionInfo;
@class QYKFNIMSyncStickTopSessionResponse;
@class QYKFNIMAddStickTopSessionParams;
@class QYKFNIMSyncMessagePinRequest;
@class QYKFNIMLoadRecentSessionsOptions;

NS_ASSUME_NONNULL_BEGIN

/**
 *  获取Thread Talk子消息回调
 *
 *  @param error    请求结果
 *  @param result   请求结果数据
 */
typedef void (^QYKFNIMThreadTalkFetchMessages) (NSError * _Nullable  error, QYKFNIMThreadTalkFetchResult * _Nullable result);

/**
 *  获取Thread Talk子消息回调
 *
 *  @param error    错误结果
 *  @param result   子消息列表
 */
typedef void (^QYKFNIMFetchHistoryMessagesByIds) (NSError * _Nullable  error, NSMapTable<QYKFNIMChatExtendBasicInfo *, QYKFNIMMessage *> * _Nullable result);

/**
 *  完成回调
 *
 *  @param error 错误码
 */
typedef void (^QYKFNIMQuickCommentHandler) (NSError * _Nullable error);

/**
 *  本地获取快捷评论结果
 *
 *  @param error 错误结果
 *  @param result 获取结果
 */
typedef void (^QYKFNIMGetQuickCommentsByMsgHandler) (NSError * _Nullable error, NSMapTable<NSNumber *, NSArray<QYKFNIMQuickComment *> *> * _Nullable result);

/**
 *  批量获取
 *
 *  @param error 结果
 *  @param result 评论列表
 *  @param failedMessages 查询失败的列表

 */
typedef void (^QYKFNIMFetchCommentsByMsgsHandler) (NSError * _Nullable  error, NSMapTable<QYKFNIMMessage *, NSArray<QYKFNIMQuickComment *> * > * _Nullable result, NSArray<QYKFNIMMessage *> * _Nullable failedMessages);

/**
 *  读取收藏列表回调block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param collectInfos 读取的消息列表
 *  @param totalCount 收藏总条数，用来判断是否还有更多
 */
typedef void(^QYKFNIMCollectQueryBlock)(NSError * _Nullable error,
                                              NSArray<QYKFNIMCollectInfo *> * _Nullable collectInfos,
                                              NSInteger totalCount);

/**
 *  添加收藏回调block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param collectInfo 添加的收藏
 */
typedef void(^QYKFNIMAddCollectBlock)(NSError * _Nullable error, QYKFNIMCollectInfo * _Nullable collectInfo);

/**
 *  更新收藏回调block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param total_removed 删除的数量
 */
typedef void(^QYKFNIMRemoveCollectBlock)(NSError * _Nullable error, NSInteger total_removed);

/**
 *  移除收藏回调block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param collectInfo 更新后的收藏
 */
typedef void(^QYKFNIMUpdateCollectBlock)(NSError * _Nullable error, QYKFNIMCollectInfo * _Nullable collectInfo);

/**
 *  添加置顶会话回调block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param newInfo 被添加的置顶会话
 */
typedef void(^QYKFNIMAddStickTopSessionCompletion)(NSError * _Nullable error, QYKFNIMStickTopSessionInfo * _Nullable newInfo);

/**
 *  移除置顶会话回调block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param removedInfo 被删除的置顶信息
 */
typedef void(^QYKFNIMRemoveStickTopSessionCompletion)(NSError * _Nullable error, QYKFNIMStickTopSessionInfo * _Nullable removedInfo);

/**
 *  更新置顶会话回调block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param updatedInfo 更新后的置顶会话
 */
typedef void(^QYKFNIMUpdateStickTopSessionCompletion)(NSError * _Nullable error, QYKFNIMStickTopSessionInfo * _Nullable updatedInfo);


/**
 *  本地查找置顶会话回调block
 *
 *  @param infos 所有本地置顶会话信息
 */
typedef void(^QYKFNIMLoadStickTopSessionInfosCompletion)(NSError * _Nullable error, NSDictionary<QYKFNIMSession*,QYKFNIMStickTopSessionInfo *> * _Nullable infos);

/**
 * 添加PIN记录的回调
 *  @param error  错误,如果成功则error为nil
 *  @param item 新增的PIN记录
 */
typedef void(^QYKFNIMAddMessagePinCompletion)(NSError * _Nullable error, QYKFNIMMessagePinItem * _Nullable item);

/**
 * 移除Pin的回调
 *  @param error  错误,如果成功则error为nil
 *  @param item 被移除的PIN记录
 */
typedef void(^QYKFNIMRemoveMessagePinCompletion)(NSError * _Nullable error, QYKFNIMMessagePinItem * _Nullable item);

/**
 * 更新PIN记录的回调
 *  @param error  错误,如果成功则error为nil
 *  @param item 被更新的PIN记录
 */
typedef void(^QYKFNIMUpdateMessagePinCompletion)(NSError * _Nullable error, QYKFNIMMessagePinItem * _Nullable item);

/**
 * 增量更新PIN记录的回调
 *  @param error  错误,如果成功则error为nil
 *  @param response 更新成功后的响应对象
 */
typedef void(^QYKFNIMSyncMessagePinCompletion)(NSError * _Nullable error, QYKFNIMSyncMessagePinResponse * _Nullable response);

/**
 * 加载PIN记录的回调
 *  @param error  错误,如果成功则error为nil
 *  @param items 更新成功后的所有pin消息
 */
typedef void(^QYKFNIMLoadMessagePinsCompletion)(NSError * _Nullable error, NSArray<QYKFNIMMessagePinItem *> * _Nullable items);

/**
 * 查找最近会话回调
 * @param recentSessions 最近会话列表
 */
typedef void(^QYKFNIMLoadRecentSessionsCompletion)(NSError * _Nullable error, NSArray<QYKFNIMRecentSession *> * _Nullable recentSessions);

/**
 *  Thread Talk 回调
 */
@protocol QYKFNIMChatExtendManagerDelegate <NSObject>


#pragma mark - 快捷回复
@optional

/**
 *  新增快捷评论
 *
 *  @param comment 评论
 */
- (void)onRecvQuickComment:(QYKFNIMQuickComment *)comment;

/**
 *  移除快捷评论
 *
 *  @param comment 被删评论
 */
- (void)onRemoveQuickComment:(QYKFNIMQuickComment *)comment;

/**
 * 一条PIN被增加的在线通知
 * @param item 新增的PIN记录
 */
- (void)onNotifyAddMessagePin:(QYKFNIMMessagePinItem *)item;

/**
 * 一条PIN被移除的在线通知
 * @param item 被移除的PIN记录
 */
- (void)onNotifyRemoveMessagePin:(QYKFNIMMessagePinItem *)item;

/**
 * 一条PIN被更新的在线通知
 * @param item 被更新的PIN记录
 */
- (void)onNotifyUpdateMessagePin:(QYKFNIMMessagePinItem *)item;

/**
 * 置顶会话同步完成的在线通知
 * @param response 置顶信息全量同步后的响应对象
 */
- (void)onNotifySyncStickTopSessions:(QYKFNIMSyncStickTopSessionResponse *)response;

/**
 * 一条置顶信息被增加的在线通知
 * @param newInfo 新增的置顶信息
 */
- (void)onNotifyAddStickTopSession:(QYKFNIMStickTopSessionInfo *)newInfo;

/**
 * 一条置顶信息被移除的在线通知
 * @param removedInfo 被移除的置顶信息
 */
- (void)onNotifyRemoveStickTopSession:(QYKFNIMStickTopSessionInfo *)removedInfo;

/**
 * 一条置顶会话被更新的在线通知
 * @param updatedInfo 被更新的置顶信息
 */
- (void)onNotifyUpdateStickTopSession:(QYKFNIMStickTopSessionInfo *)updatedInfo;

@end


/**
 *   聊天扩展
 */
@protocol QYKFNIMChatExtendManager <NSObject>

#pragma mark - Thread Talk

/**
 *  回复消息
 *
 *  @param message 新生成的消息
 *  @param target  被回复的消息
 *  @param error   错误 如果在准备发送消息阶段发生错误,这个error会被填充相应的信息
 *
 *  @return 是否调用成功,这里返回的 result 只是表示当前这个函数调用是否成功,需要后续的回调才能够判断消息是否已经发送至服务器
 */
- (BOOL)reply:(QYKFNIMMessage *)message
           to:(QYKFNIMMessage *)target
        error:(NSError * __nullable *)error;

/**
 *  异步回复消息
 *
 *  @param message  新生成的消息
 *  @param target   被回复的消息
 *  @param block    发送完成后的回调，这里的回调完成只表示当前这个函数调用完成，需要后续的回调才能判断消息是否已经发送至服务器
 */
- (void)reply:(QYKFNIMMessage *)message
           to:(QYKFNIMMessage *)target
   completion:(__nullable QYKFNIMChatManagerBlock)block;

/**
 *  本地获取Thread Talk的消息列表
 *
 *  @param  message 父消息
 *  @return 目标message的子消息列表
 */
- (NSArray<QYKFNIMMessage *> * _Nullable)subMessages:(QYKFNIMMessage *)message;

/**
 *  本地获取Thread Talk的消息列表
 *
 *  @param  message 父消息
 *  @return 目标message的子消息数目
 */
- (NSInteger)subMessagesCount:(QYKFNIMMessage *)message;

/**
 *  获取指定消息的Thread Talk子消息
 *
 *  @param info 目标消息
 *  @param option  查询分页选项
 *  @param block   完成回调
 */
- (void)fetchSubMessages:(QYKFNIMChatExtendBasicInfo *)info
                  option:(QYKFNIMThreadTalkFetchOption * _Nullable)option
              completion:(QYKFNIMThreadTalkFetchMessages)block;

/**
 *  获取指定消息的Thread Talk子消息
 *
 *  @param message 目标消息
 *  @param option  查询分页选项
 *  @param block   完成回调
 */
- (void)fetchSubMessagesFrom:(QYKFNIMMessage *)message
                      option:(QYKFNIMThreadTalkFetchOption * _Nullable)option
                  completion:(QYKFNIMThreadTalkFetchMessages)block;


/**
 *  根据MessageId等获取消息
 *
 *  @param infos    请求信息
 *  @param sync     是否同步到本地，注:DB标记状态删除的消息无法被同步覆盖
 *  @param block    完成回调
 */
- (void)fetchHistoryMessages:(NSArray<QYKFNIMChatExtendBasicInfo *> *)infos
                    syncToDB:(BOOL)sync
                  completion:(QYKFNIMFetchHistoryMessagesByIds)block;


#pragma mark - 快捷回复
/**
 *  发送快捷回复
 *
 *  @param comment      回复内容
 *  @param message      被回复消息
 *  @param completion   完成回调
 */
- (void)addQuickComment:(QYKFNIMQuickComment *)comment
              toMessage:(QYKFNIMMessage *)message
             completion:(QYKFNIMQuickCommentHandler _Nullable)completion;

/**
 *  从服务端删除一条评论
 *
 *  @param comment      目标评论
 *  @param completion   完成回调
 */
- (void)deleteQuickComment:(QYKFNIMQuickComment *)comment
                completion:(QYKFNIMQuickCommentHandler _Nullable)completion;

/**
 *  批量获取快捷评论
 *
 *  @param messages 目标消息, 最多批量20个
 *  @param completion 完成回调
 */
- (void)fetchQuickComments:(NSArray<QYKFNIMMessage *> *)messages
                completion:(QYKFNIMFetchCommentsByMsgsHandler)completion;

/**
 *  本地获取消息对应的快捷评论结果
 *
 *  @param message 目标消息
 *  @param completion 完成回调
 */
- (void)quickCommentsByMessage:(QYKFNIMMessage *)message
                    completion:(QYKFNIMGetQuickCommentsByMsgHandler)completion;


#pragma mark - 收藏
/**
 * 分页查询收藏列表
 * @param option 分页查询选项
 * @param completion 查询完成的回调
 */
- (void)queryCollect:(QYKFNIMCollectQueryOptions *)option completion:(nullable QYKFNIMCollectQueryBlock)completion;

/**
 * 添加一个收藏
 * @param info 添加收藏的参数，必须字段：type、data、ext
 * @param completion 添加完成的回调
 */
- (void)addCollect:(QYKFNIMAddCollectParams *)info completion:(nullable QYKFNIMAddCollectBlock)completion;

/**
 * 批量移除收藏
 * @param collectList 批量移除的收藏对象，必须字段：id、createTime
 * @param completion 移除完成的回调
 */
- (void)removeCollect:(NSArray<QYKFNIMCollectInfo *> *)collectList completion:(nullable QYKFNIMRemoveCollectBlock)completion;

/**
 * 更新收藏ext
 * @param collectInfo 需要更新的收藏对象，需要id、createTime、ext字段，如果ext不传，表示删除ext字段
 */
- (void)updateCollect:(QYKFNIMCollectInfo *)collectInfo completion:(nullable QYKFNIMUpdateCollectBlock)completion;

#pragma mark - 置顶

/**
 * 添加一条置顶记录
 * @param params 添加置顶的参数
 * @param completion 添加置顶记录完成的回调
 */
- (void)addStickTopSession:(QYKFNIMAddStickTopSessionParams *)params completion:(nullable QYKFNIMAddStickTopSessionCompletion)completion;

/**
 * 删除一条置顶记录
 * @param info 需要删除的置顶记录
 * @param completion 删除完成的回调
 */
- (void)removeStickTopSession:(QYKFNIMStickTopSessionInfo *)info completion:(nullable QYKFNIMRemoveStickTopSessionCompletion)completion;

/**
 * 更新一条置顶记录的扩展信息
 * @param info 需要更新的置顶记录
 * @param completion 删除完成的回调
 */
- (void)udpateStickTopSession:(QYKFNIMStickTopSessionInfo *)info completion:(nullable QYKFNIMUpdateStickTopSessionCompletion)completion;

/**
 * 查找所有的置顶记录
 * @param completion 查找完成的回调
 */
- (void)loadStickTopSessionInfos:(nullable QYKFNIMLoadStickTopSessionInfosCompletion)completion;

/**
 * 获取最近会话列表
 * @param options 查询选项（如按照置顶会话排序）
 */
- (void)loadRecentSessionsWithOptions:(QYKFNIMLoadRecentSessionsOptions *)options completion:(nullable QYKFNIMLoadRecentSessionsCompletion)completion;

/**
 * 根据置顶信息排序最近会话
 * @param recentSessions 需要排序的置顶会话，若传可变数组则进行in place排序
 * @param infos [会话：置顶信息] 映射
 * @return 排序后的最近会话列表，若传如可变数组，则返回其数组本身
 */
- (NSArray<QYKFNIMRecentSession *> *)sortRecentSessions:(NSArray<QYKFNIMRecentSession *> *)recentSessions withStickTopInfos:(NSDictionary<QYKFNIMSession *,QYKFNIMStickTopSessionInfo *> *)infos;

/**
 * 查询某个会话的置顶信息
 * @param session 需要查询的会话
 * @return 置顶信息
 */
- (QYKFNIMStickTopSessionInfo *)stickTopInfoForSession:(QYKFNIMSession *)session;

#pragma mark - Pin

/**
 * 添加一条PIN记录
 * @param item 需要添加的PIN记录
 * @param completion 添加完成的回调
 */
- (void)addMessagePin:(QYKFNIMMessagePinItem *)item completion:(nullable QYKFNIMAddMessagePinCompletion)completion;

/**
 * 删除一条PIN记录
 * @param item 需要删除的PIN记录
 * @param completion 删除完成的回调
 */
- (void)removeMessagePin:(QYKFNIMMessagePinItem *)item completion:(nullable QYKFNIMRemoveMessagePinCompletion)completion;

/**
 * 更新一条PIN记录的扩展字段(ext)
 * @param item 需要更新的PIN记录，ext不传为删除
 * @param completion 更新完成的回调
 */
- (void)updateMessagePin:(QYKFNIMMessagePinItem *)item completion:(nullable QYKFNIMUpdateMessagePinCompletion)completion;

/**
 * 查询全部PIN记录(登录后首次查询该会话会触发一次网络同步)
 * @param session 会话
 * @param completion 加载完成的回调
 */
- (void)loadMessagePinsForSession:(QYKFNIMSession *)session completion:(nullable QYKFNIMLoadMessagePinsCompletion)completion;

/**
 * 查询某条消息的PIN记录
 * @param message 消息
 * @return 记录
 */
- (QYKFNIMMessagePinItem *)pinItemForMessage:(QYKFNIMMessage *)message;

#pragma mark - 其他
/**

 *  添加Thread Talk委托
 *
 *  @param delegate 聊天委托
 */
- (void)addDelegate:(id<QYKFNIMChatExtendManagerDelegate>)delegate;

/**
 *  移除Thread Talk委托
 *
 *  @param delegate 聊天委托
 */
- (void)removeDelegate:(id<QYKFNIMChatExtendManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
