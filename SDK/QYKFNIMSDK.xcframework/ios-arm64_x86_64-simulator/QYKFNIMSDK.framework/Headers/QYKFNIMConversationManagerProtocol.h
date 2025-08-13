//
//  QYKFNIMConversationManager.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMSession.h"

NS_ASSUME_NONNULL_BEGIN

@class QYKFNIMMessage;
//@class QYKFNIMSession;
@class QYKFNIMRecentSession;
@class QYKFNIMRecentSessionOption;
@class QYKFNIMHistoryMessageSearchOption;
@class QYKFNIMMessageSearchOption;
@class QYKFNIMDeleteMessageOption;
@class QYKFNIMDeleteMessagesOption;
@class QYKFNIMImportedRecentSession;
@class QYKFNIMMessageReceipt;
@class QYKFNIMTeamMessageReceiptDetail;
@class QYKFNIMClearMessagesOption;
@class QYKFNIMDeleteRecentSessionOption;
@class QYKFNIMBatchDeleteMessagesOption;
@class QYKFNIMFetchServerSessionOption;
@class QYKFNIMMessageServerRetrieveOption;
@class QYKFNIMIncompleteSessionInfo;
@class QYKFNIMSessionDeleteAllRemoteMessagesOptions;
@class QYKFNIMSessionDeleteAllRemoteMessagesInfo;
@class QYKFNIMAddEmptyRecentSessionBySessionOption;
@class QYKFNIMMessageFullKeywordSearchOption;
@class QYKFNIMMessageFullKeywordSearchOrderByTimeOption;
@class QYKFNIMGetMessagesDynamicallyParam;
@class QYKFNIMMessagesInSessionOption;

/**
 *  读取服务器消息记录block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param messages 读取的消息列表
 */
typedef void(^QYKFNIMFetchMessageHistoryBlock)(NSError * __nullable error,NSArray<QYKFNIMMessage *> * __nullable messages);

/**
 *  服务器消息检索记录block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param messages 读取的消息列表
 */
typedef void(^QYKFNIMRetrieveServerMessagesBlock)(NSError * __nullable error,NSArray<QYKFNIMMessage *> * __nullable messages);

/**
 *  删除本地消息记录block
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void (^QYKFNIMBatchDeleteMessagesBlock)(NSError * __nullable error);

/**
 *  更新本地消息 Block
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^QYKFNIMUpdateMessageBlock)(NSError * __nullable error);

/**
 *  导入本地最近会话 Block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param failedImportedRecentSessions  导入失败的最近会话
 */
typedef void(^QYKFNIMImportRecentSessionsBlock)(NSError * __nullable error, NSArray<QYKFNIMImportedRecentSession *> * __nullable failedImportedRecentSessions);


/**
 *  导入服务端拉取的最近会话 Block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param failedImportedRecentSessions  导入失败的最近会话
 */
typedef void(^QYKFNIMImportServerRecentSessionsBlock)(NSError * __nullable error, NSArray<QYKFNIMRecentSession *> * __nullable failedRecentSessions);


/**
 *  标记远端会话Block
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^QYKFNIMRemoveRemoteMessageBlock)(NSError * __nullable error);

/**
 *  删除某个会话的所有消息Block
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^QYKFNIMRemoveRemoteSessionBlock)(NSError * __nullable error);


/**
 *  删除指定多个会话的所有消息
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^QYKFNIMDeleteAllMessagesInSessionsBlock)(NSError * __nullable error, NSArray<QYKFNIMSession *> * __nullable sessions);



/**
 *  标记远端会话Block
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^QYKFNIMDeleteAllMessagesInSessionBlock)(NSError * __nullable error);


/**
 * 清空历史消息block
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^QYKFNIMSessionDeleteAllRemoteMessagesCompletionBlock)(NSError * _Nullable error);

/**
 * 批量单向删除消息的回调block
 */
typedef void(^QYKFNIMDeleteRemoteMessagesCompletionBlock)(NSError * _Nullable error);

/**
 *  搜索本地消息记录Block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param messages 读取的消息列表
 *  @discussion 只有在传入参数错误时才会有error产生
 */
typedef void(^QYKFNIMSearchMessageBlock)(NSError * __nullable error,NSArray<QYKFNIMMessage *> * __nullable messages);

/**
 *  全局搜索本地消息记录Block
 *
 *  @param error      错误,如果成功则error为nil
 *  @param messages   读取的消息列表
 */
typedef void(^QYKFNIMGlobalSearchMessageBlock)(NSError * __nullable error,NSDictionary<QYKFNIMSession *,NSArray<QYKFNIMMessage *> *> * __nullable messages);

/**
 导出历史消息进度回调

 @param progress 进度 0-100
 */
typedef void(^QYKFNIMExportMessageProgress)(float progress);

/**
 导出历史消息完成回调

 @param error 错误，如果成功则为 nil
 @param resultFilePath 如果成功，则为结果文件路径
 */
typedef void(^QYKFNIMExportMessageComletion)(NSError * __nullable error, NSString * __nullable resultFilePath);

/**
 导入历史消息进度回调

 @param progress 进度 0-100
 */
typedef void(^QYKFNIMImportMessageProgress)(float progress);

/**
 导入历史消息完成回调

 @param error 错误，如果成功则为 nil
 */
typedef void(^QYKFNIMImportMessageCompletion)(NSError * __nullable error);

/**
 更新服务器历史备份文件结果回调

 @param error 错误，如果成功则为 nil
 */
typedef void(^QYKFNIMUpdateMigrateMessageCompletion)(NSError * __nullable error);

/**
 获取历史备份文件结果回调

 @param error 错误，如果成功则为 nil
 @param remoteFilePath 备份文件远端路径
 @param secureKey 备份文件解密的 key
 */
typedef void(^QYKFNIMFetchMigrateMessageCompletion)(NSError * __nullable error, NSString * __nullable remoteFilePath, NSString * __nullable secureKey);


/**
 *  读取服务器会话列表block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param recentSessions 读取的消息列表
 *  @param hasMore 最小时间戳只有请求第一页时会返回这个参数，表示下一次增量同步时带在请求参数里
 */
typedef void(^QYKFNIMFetchRecentSessionsHistoryBlock)(NSError * __nullable error,
                                                 NSArray<QYKFNIMRecentSession *> * __nullable recentSessions,
                                                 BOOL hasMore);

/**
 *  读取服务器会话block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param recentSession 结果会话
 */
typedef void(^QYKFNIMFetchRecentSessionHistoryBlock)(NSError * __nullable error,
                                                 QYKFNIMRecentSession * _Nullable  recentSession);

/**
*  更新服务端端会话扩展
*
*  @param error  错误,如果成功则error为nil
*/
typedef void(^QYKFNIMRemoteRecentSessionBlock)(NSError * __nullable error);



/**
 *  批量更新未完整会话列表
 *
 *  @param error  错误,如果成功则error为nil
 *  @param faileds  更新失败的会话
 */
typedef void(^QYKFNIMUpdateIncompleteSessionsBlock)(NSError * __nullable error, NSArray<QYKFNIMImportedRecentSession *> * __nullable faileds);

/**
 *  未完整会话信息
 *
 *  @param error  错误,如果成功则error为nil
 *  @param result  更新失败的会话
 */
typedef void(^QYKFNIMIncompleteSessionsBlock)(NSError * __nullable error, NSArray<QYKFNIMIncompleteSessionInfo *> * __nullable result);

/**
 *  批量发送会话已读回调
 *
 *  @param error  错误,如果成功则error为nil
 *  @param result  发送失败的会话
 */
typedef void(^QYKFNIMBatchSendACKSessionsBlock)(NSError * __nullable error, NSArray <QYKFNIMSession * > * _Nullable sessions);

/**
 *  发送会话已读回调
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^QYKFNIMSendACKSessionsBlock)(NSError * __nullable error);

/**
 *  动态获取消息的回调
 *
 *  @param error  错误,如果成功则error为nil
 *  @param isReliable 是否可靠（是否一定符合输入条件的）
 *  @param messages 消息
 */
typedef void(^QYKFNIMGetMessagesDynamicallyBlock)(NSError * __nullable error, BOOL isReliable, NSArray<QYKFNIMMessage *> * __nullable messages);
/**
 清空会话消息完成时状态回调
 */
typedef NS_ENUM(NSUInteger, QYKFNIMClearMessagesStatus)
{
    QYKFNIMClearMessagesStatusLocalCleared = 0,
    QYKFNIMClearMessagesStatusServerCleared,
    QYKFNIMClearMessagesStatusServerFailed,
};

/**
 *  会话管理器回调
 */
@protocol QYKFNIMConversationManagerDelegate <NSObject>

@optional

/**
*  最近会话数据库读取完成
*
*  @discussion 所有最近会话读取完成。设置QYKFNIMSDKConfig中的asyncLoadRecentSessionEnabled属性为YES时，且本地数目大于1000条时，此回调会执行。
*              该回调执行表示最近会话全部加载完毕可以通过allRecentSessions来取全部对话。
*/
- (void)didLoadAllRecentSessionCompletion;


/**
 *  增加最近会话的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 *  @discussion 当新增一条消息，并且本地不存在该消息所属的会话时，会触发此回调。
 */
- (void)didAddRecentSession:(QYKFNIMRecentSession *)recentSession
           totalUnreadCount:(NSInteger)totalUnreadCount;

///**
// *  增加最近会话的回调
// *
// *  @param recentSession    最近会话
// *  @param totalUnreadCount 目前总未读数
// *  @discussion 当新增一条消息，并且本地不存在该消息所属的会话时，会触发此回调。
// */
//- (void)didAddRecentSession:(NSDictionary <NSNumber *, QYKFNIMRecentSession *> *)recentSessions
//           totalUnreadCount:(NSDictionary <NSNumber *, NSNumber *> *)unreadCounts;

/**
 *  最近会话修改的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 *  @discussion 触发条件包括: 1.当新增一条消息，并且本地存在该消息所属的会话。
 *                          2.所属会话的未读清零。
 *                          3.所属会话的最后一条消息的内容发送变化。(例如成功发送后，修正发送时间为服务器时间)
 *                          4.删除消息，并且删除的消息为当前会话的最后一条消息。
 */
- (void)didUpdateRecentSession:(QYKFNIMRecentSession *)recentSession
              totalUnreadCount:(NSInteger)totalUnreadCount;
///**
// *  最近会话修改的回调
// *
// *  @param recentSession    最近会话
// *  @param totalUnreadCount 目前根据sessionType 划分的未读数
// *  @discussion 触发条件包括: 1.当新增一条消息，并且本地存在该消息所属的会话。
// *                          2.所属会话的未读清零。
// *                          3.所属会话的最后一条消息的内容发送变化。(例如成功发送后，修正发送时间为服务器时间)
// *                          4.删除消息，并且删除的消息为当前会话的最后一条消息。
// */
//- (void)didUpdateRecentSession:(NSDictionary <NSNumber *, QYKFNIMRecentSession *> *)recentSessions
//                   unreadCount:(NSDictionary <NSNumber *, NSNumber *> *)unreadCounts;

/**
 *  删除最近会话的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 */
- (void)didRemoveRecentSession:(QYKFNIMRecentSession *)recentSession
              totalUnreadCount:(NSInteger)totalUnreadCount;

/**
 *  未读数更新的回调 (markRead不会走此回调)
 *
 *  @param unreadCountDic 各类型未读数的字典: [@(QYKFNIMSessionType): @(条数)]
 */
- (void)didUpdateUnreadCountDic:(NSDictionary *)unreadCountDic;

/**
 *  单个会话里所有消息被删除的回调
 *
 *  @param session 消息所属会话
 */
- (void)messagesDeletedInSession:(QYKFNIMSession *)session;

/**
 *  所有消息被删除的回调
 */
- (void)allMessagesDeleted;

/**
 *  单个会话所有消息在本地和服务端都被清空
 *  @param session 消息所属会话
 */
- (void)allMessagesClearedInSession:(QYKFNIMSession *)session step:(QYKFNIMClearMessagesStatus)step;

/**
 *  所有消息已读的回调
 */
- (void)allMessagesRead;

/**
 *  消息已读的回调
 *
 *  @param type 消息所属会话类型
 */
- (void)messagesReadOfType:(QYKFNIMSessionType)type;

/**
 *  会话服务，会话更新
 *
 *  @param recentSession 最近会话
 */
- (void)didServerSessionUpdated:(nullable QYKFNIMRecentSession *)recentSession;

/**
 *  消息单向删除通知
 *  @deprecated 请使用 - onRecvMessagesDeleted: exts:
 *
 *  @param message 被删除消息
 *  @param ext     扩展消息
 */
- (void)onRecvMessageDeleted:(QYKFNIMMessage *)message ext:(nullable NSString *)ext __attribute__((deprecated("请使用 - onRecvMessagesDeleted: exts:")));

/**
 *  消息单向删除通知
 *
 *  @param message 被删除消息
 *  @param exts     删除时的扩展字段字典，key: messageId，value: ext
 */
- (void)onRecvMessagesDeleted:(NSArray<QYKFNIMMessage *> *)messages exts:(nullable NSDictionary<NSString *, NSString *> *)exts;

/**
 *  未漫游完整会话列表回调
 *  @param infos 未漫游完整的会话信息
 */
- (void)onRecvIncompleteSessionInfos:(nullable NSArray<QYKFNIMIncompleteSessionInfo *> *)infos;

/**
 *  标记已读回调
 *  @param session session
 *  @param error 失败原因
 */
- (void)onMarkMessageReadCompleteInSession:(QYKFNIMSession *)session error:(nullable NSError *)error;

/**
 *  批量标记已读的回调
 *  @param session session
*/
- (void)onBatchMarkMessagesReadInSessions:(NSArray<QYKFNIMSession *> *)sessions;

/**
 * 远端消息清空的通知
 * @param info 清空会话的信息
 */
- (void)onRecvAllRemoteMessagesInSessionDeleted:(QYKFNIMSessionDeleteAllRemoteMessagesInfo *)info;

@end

/**
 导出历史消息过程 delegate，可用于处理自定义消息
 */
@protocol QYKFNIMExportMessageDelegate <NSObject>

@optional

/**
 是否导出消息，YES - 导出，NO -不导出

 @param message 消息体
 @return YES / NO
 */
- (BOOL)shouldExportMessage:(QYKFNIMMessage *)message;

/**
 消息导出前的通知回调

 @param message 将导出的消息
 */
- (void)onMessageWillExport:(QYKFNIMMessage *)message;

@end

/**
 导入历史消息过程 delegate,可用于处理自定义消息
 */
@protocol QYKFNIMImportMessageDelegate <NSObject>

@optional

/**
 是否导入消息，YES - 导入，NO -不导入
 
 @param message 消息体
 @return YES / NO
 */
- (BOOL)shouldImportMessage:(QYKFNIMMessage *)message;

/**
 消息导入前的通知回调

 @param message 消息体
 */
- (void)onMessageWillImport:(QYKFNIMMessage *)message;

@end

/**
 *  会话管理器
 */
@protocol QYKFNIMConversationManager <NSObject>

/**
 *  删除某条消息
 *
 *  @param message 待删除的聊天消息
 */
- (void)deleteMessage:(QYKFNIMMessage *)message;

/**
*  删除某条消息
*
*  @param message 待删除的聊天消息
*  @param option 删除消息选项
*/
- (void)deleteMessage:(QYKFNIMMessage *)message
               option:(nullable QYKFNIMDeleteMessageOption *)option;

/**
 *  删除本地某条消息，同时删除服务端历史、漫游
 *
 *  @param message  待删除的聊天消息
 *  @param ext      扩展字段
 *  @param block    完成回调
 */
- (void)deleteMessageFromServer:(QYKFNIMMessage *)message
                            ext:(nullable NSString *)ext
                     completion:(nullable QYKFNIMRemoveRemoteMessageBlock)block;

/**
 *  删除某个会话的所有消息
 *
 *  @param session 待删除会话
 *  @param option 删除消息选项
 */
- (void)deleteAllmessagesInSession:(QYKFNIMSession *)session
                            option:(nullable QYKFNIMDeleteMessagesOption *)option;

/**
 *  删除某个会话的所有消息
 *
 *  @param session 待删除会话
 *  @param option 删除消息选项
 */
- (void)deleteAllMessagesInSession:(QYKFNIMSession *)session
                            option:(nullable QYKFNIMDeleteMessagesOption *)option
                        completion:(nullable QYKFNIMDeleteAllMessagesInSessionBlock)block;

/**
 *  删除指定多个会话的所有消息
 *
 *  @param sessions 待删除会话
 *  @param option 删除消息选项
 */
- (void)deleteAllMessagesInSessions:(nonnull NSArray<QYKFNIMSession *> *)sessions
                            option:(nullable QYKFNIMDeleteMessagesOption *)option
                        completion:(nullable QYKFNIMDeleteAllMessagesInSessionsBlock)block;

/**
 *  删除所有会话消息
 *
 *  @param option 删除消息选项
 *  @discussion 调用这个接口只会触发allMessagesDeleted这个回调，其他针对单个recentSession的回调都不会被调用
 */
- (void)deleteAllMessages:(nullable QYKFNIMDeleteMessagesOption *)option;


/**
 *  删除指定范围内的消息，如指定时间范围
 *
 *  @param session 目标会话
 *  @param option 删除消息选项
 *  @param block 完成回调
 */
- (void)deleteMessagesInSession:(QYKFNIMSession *)session
                         option:(nullable QYKFNIMBatchDeleteMessagesOption *)option
                     completion:(nullable QYKFNIMBatchDeleteMessagesBlock)block;

/**
 * 删除某个会话的所有本地和云端的历史消息。删除后，查询云端消息历史的接口将不能返回这些消息。
 *
 * @param session 目标会话
 * @param options 清空消息历史的可选项
 * @param block 清空完成后的回调
 */
- (void)deleteAllRemoteMessagesInSession:(QYKFNIMSession *)session
                                 options:(QYKFNIMSessionDeleteAllRemoteMessagesOptions *)options
                              completion:(QYKFNIMSessionDeleteAllRemoteMessagesCompletionBlock)completion;

/**
 * 批量删除消息，同时删除服务端和本地。所有传入的消息必需属于同一个会话。
 *
 * @param messages 消息数组
 * @param exts key为消息id，value为删除该消息所对应的扩展信息
 * @param completion 删除完成的回调
 */
- (void)deleteRemoteMessages:(NSArray<QYKFNIMMessage *> *)messages
                        exts:(nullable NSDictionary<NSString *,NSString *> *)exts
                  completion:(nullable QYKFNIMDeleteRemoteMessagesCompletionBlock)completion;

/**
 *  增加某个最近会话
 *
 *  @param session 待增加的最近会话
 *  @discussion 异步方法
 */
- (void)addEmptyRecentSessionBySession:(QYKFNIMSession *)session;

/**
 *  增加某个最近会话
 *
 *  @param session 待增加的最近会话
 *  @param option 配置项
 *  @discussion 异步方法
 */
- (void)addEmptyRecentSessionBySession:(QYKFNIMSession *)session
                                option:(QYKFNIMAddEmptyRecentSessionBySessionOption *) option;

/**
 *  删除某个最近会话
 *
 *  @param recentSession 待删除的最近会话
 *  @discussion 异步方法，删除最近会话，但保留会话内消息
 */
- (void)deleteRecentSession:(QYKFNIMRecentSession *)recentSession;

/**
*  删除某个最近会话
*
*  @param recentSession 待删除的最近会话
*  @param option 是否删除漫游选项，isDeleteRoamMessage默认为NO
*  @param completion 结果回调
*  @discussion 异步方法，删除最近会话，但保留会话内消息
*/
- (void)deleteRecentSession:(QYKFNIMRecentSession *)recentSession option:(QYKFNIMDeleteRecentSessionOption *)option completion:(QYKFNIMRemoveRemoteSessionBlock)completion;

/**
 *  设置所有会话消息为已读
 *
 *  @discussion 异步方法，消息会标记为设置的状态。不会触发单条 recentSession 更新的回调，但会触发回调 - (void)allMessagesRead
 */
- (void)markAllMessagesRead;

/**
 *  设置会话消息为已读
 *
 *  @param type 会话类型
 *  @discussion 异步方法，消息会标记为设置的状态。不会触发单条 recentSession 更新的回调，但会触发回调 - (void)messagesReadOfType:
 */
- (void)markMessagesReadOfType:(QYKFNIMSessionType)type;

/**
 *  批量设置多个会话消息已读
 *
 *  @discussion 异步方法。不会触发单条 recentSession 更新的回调，但会触发回调 - onBatchMarkMessagesReadInSessions:
*/
- (void)batchMarkMessagesReadInSessions:(NSArray<QYKFNIMSession *> *)sessions;

/**
 *  批量设置多个会话消息已读
 *
 *  @param completion 结果回调。部分成功时，可以从QYKFNIMBatchSendACKSessionsBlock的sessions参数得到失败的会话
 *  @discussion 异步方法。不会触发单条 recentSession 更新的回调，但会触发回调 - onBatchMarkMessagesReadInSessions:
*/
- (void)batchMarkMessagesReadInSessions:(NSArray<QYKFNIMSession *> *)sessions completion:(QYKFNIMBatchSendACKSessionsBlock)completion;

/**
 *  设置一个会话里所有消息置为已读
 *
 *  @param session 需设置的会话
 *  @discussion 异步方法，消息会标记为设置的状态
 */
- (void)markAllMessagesReadInSession:(QYKFNIMSession *)session;

/**
 *  设置一个会话里所有消息置为已读
 *
 *  @param session 需设置的会话
 *  @param session 结果回调
 *  @discussion 异步方法，消息会标记为设置的状态
 */
- (void)markAllMessagesReadInSession:(QYKFNIMSession *)session completion:(QYKFNIMSendACKSessionsBlock)completion;



/**
 *  更新本地已存的消息记录
 *
 *  @param message 需要更新的消息
 *  @param session 需要更新的会话
 *  @param completion 完成后的回调
 *  @discussion 为了保证存储消息的完整性,提供给上层调用的消息更新接口只允许更新如下字段:所有消息的本地拓展字段(LocalExt)和自定义消息的消息对象(messageObject)
 */
- (void)updateMessage:(QYKFNIMMessage *)message
           forSession:(QYKFNIMSession *)session
           completion:(nullable QYKFNIMUpdateMessageBlock)completion;


/**
 *  写入消息
 *
 *  @param message 需要更新的消息
 *  @param session 需要更新的会话
 *  @param completion 完成后的回调
 *  @discussion 当保存消息成功之后，会收到 QYKFNIMChatManagerDelegate 中的 onRecvMessages: 回调。不允许插入已存在的消息
 */
- (void)saveMessage:(QYKFNIMMessage *)message
         forSession:(QYKFNIMSession *)session
         completion:(nullable QYKFNIMUpdateMessageBlock)completion;



/**
 *  导入最近会话
 *
 *  @param importedRecentSession 待导入的会话集合
 *  @param completion 完成后的回调
 *  @discussion 当导入最近会话成功之后，不会收到 QYKFNIMChatManagerDelegate 中的 recentSession 变化的回调，请直接在 completion 中做处理。不允许插入已经存在的最近会话。
 */
- (void)importRecentSessions:(NSArray<QYKFNIMImportedRecentSession *> *)importedRecentSession
                  completion:(nullable QYKFNIMImportRecentSessionsBlock)completion;


/**
 *  导入最近会话
 *
 *  @param recentSessions 待导入的会话集合
 *  @param completion 完成后的回调
 *  @discussion 当导入最近会话成功之后，不会收到 QYKFNIMChatManagerDelegate 中的 recentSession 变化的回调，请直接在 completion 中做处理。不允许插入已经存在的最近会话。
 */
- (void)importServerRecentSessions:(NSArray<QYKFNIMRecentSession *> *)recentSessions
                  completion:(nullable QYKFNIMImportServerRecentSessionsBlock)completion;


/**
 *  从本地db读取一个会话里某条消息之前的若干条的消息
 *
 *  @param session 消息所属的会话
 *  @param message 当前最早的消息,没有则传入nil
 *  @param limit   个数限制
 *
 *  @return 消息列表，按时间从小到大排列
 */
- (nullable NSArray<QYKFNIMMessage *> *)messagesInSession:(QYKFNIMSession *)session
                                              message:(nullable QYKFNIMMessage *)message
                                                limit:(NSInteger)limit;

/**
 *  从本地db读取一个会话里某条消息之前的若干条的消息
 *
 *  @param session 消息所属的会话
 *  @param message 当前最早的消息,没有则传入nil
 *  @param limit   个数限制
 *  @param completion 完成后的回调
 */
- (void)messagesInSession:(QYKFNIMSession *)session
                  message:(nullable QYKFNIMMessage *)message
                    limit:(NSInteger)limit
               completion:(QYKFNIMFetchMessageHistoryBlock)completion;

/**
 * 从本地db读取一个会话里某条消息之前的若干条的消息
 *
 * @param option 参数配置
 * @param completion 回调
 */
- (void)messagesInSession:(QYKFNIMMessagesInSessionOption *)option
               completion:(QYKFNIMFetchMessageHistoryBlock)completion;

/**
 *  动态途径获取消息，默认回调错误码403，动态能力需要开通功能，并在同步完成后生效
 *
 *  @param param
 *  @param completion 完成后的回调
 */
- (void)getMessagesDynamically:(nonnull QYKFNIMGetMessagesDynamicallyParam *)param
                    completion:(QYKFNIMGetMessagesDynamicallyBlock)completion;

/**
 *  根据消息Id获取消息
 *
 *  @param session    消息所属会话结合
 *
 *  @param messageIds 消息Id集合
 *
 *  @return 消息列表,按时间从小到大排列
 */
- (nullable NSArray<QYKFNIMMessage *> *)messagesInSession:(QYKFNIMSession *)session
                                           messageIds:(NSArray<NSString *> *)messageIds;

/**
 *  获取所有未读数
 *  @discussion 只能在主线程调用,包括忽略提醒的会话
 *  @return 未读数
 */
- (NSInteger)allUnreadCount;

/**
 *  按 SessionType 获取未读数
 *  @discussion  只能在主线程调用,包括忽略提醒的会话
 *  @param type   会话类型
 *  @return 未读数
 */
- (NSInteger)unreadCountOfType:(QYKFNIMSessionType)type;

/**
 *  获取所有需要通知/不需要通知的最近会话未读数
 *  @param notify 是否需要通知
 *  @return 未读数
 *  @discussion 群只有 notify state != QYKFNIMTeamNotifyStateNone 才算是不允许通知
 */
- (NSInteger)allUnreadCount:(BOOL)notify;


- (NSArray *)allUnreadMessagesInSession: (QYKFNIMSession *)session;

- (void)allUnreadMessagesInSession: (QYKFNIMSession *)session completion:(QYKFNIMFetchMessageHistoryBlock)completion;

/**
 *  获取所有最近会话。
 *  @return 最近会话列表
 *  @discussion SDK 以 map 的形式保存 sessions，调用这个方法时将进行排序，数据量较大 (上万) 时会比较耗时。
 *              该方法默认是同步查询所有sessions，当数据量较大（上万）会比较耗时，可能会卡主线程，这种情况下
 *              用户可以配置QYKFNIMSDKConfig中的asyncLoadRecentSessionEnabled属性为YES，此时该接口可以先返回
 *              100条最近会话，等全部加载完会回调didLoadAllRecentSessionCompletion，此后再调用该接口可以全量返回
 *              所有会话，用户需要在didLoadAllRecentSessionCompletion回调中及时更新UI展示。
 */
- (nullable NSArray<QYKFNIMRecentSession *> *)allRecentSessions;

/**
 *  获取所有最近会话
 *  @return 最近会话列表
 *  @discussion SDK 以 map 的形式保存 sessions，调用这个方法时将进行排序，数据量较大 (上万) 时会比较耗时。
 *  通过该接口获取的最近会话列表与allRecentSessions接口不同，是基于allRecentSessions接口筛选类型之后重新生成的新对象
 *  需要用户自行在外部管理，所有回调不回回调该接口查询的任何会话
 */
- (nullable NSArray<QYKFNIMRecentSession *> *)allRecentSessionsWithOption:(QYKFNIMRecentSessionOption *)option;

/**
 *  获取指定数量的最近会话
 *
 *  @param limit 本次查询最近会话数量上限。最大可设置到100，超过100则默认为100。
 *
 *  @return 最近会话列表
 */
- (nullable NSArray<QYKFNIMRecentSession *> *)queryRecentSessionsWithLimit:(NSInteger)limit;

/**
 *  根据当前 session 返回对应的最近会话信息
 *
 *  @param session 会话
 *
 *  @return 最近会话信息，如果找不到则返回 nil
 */
- (nullable QYKFNIMRecentSession *)recentSessionBySession:(QYKFNIMSession *)session;


/**
*  从服务端分页获取历史会话列表
*
*  @param option 分页查询选项，可为空，空时默认全量获取
*
*  @param completion 完成回调
*/
- (void)fetchServerSessions:(nullable QYKFNIMFetchServerSessionOption *)option
                 completion:(nullable QYKFNIMFetchRecentSessionsHistoryBlock)completion;


/**
 *  从服务端获取会话信息
 *
 *  @param session 目标会话
 *
 *  @param completion 完成回调
 */
- (void)fetchServerSessionBySession:(QYKFNIMSession *)session
                         completion:(nullable QYKFNIMFetchRecentSessionHistoryBlock)completion;


/**
*  更新服务端获取会话扩展信息
*
*  @param ext        扩展信息
*
*  @param session    目标最近会话
*
*  @param completion 完成回调
*/
- (void)updateServerSessionExt:(NSString *)ext
                       session:(QYKFNIMSession *)session
                    completion:(nullable QYKFNIMRemoteRecentSessionBlock)completion;

/**
*  删除服务端
*
*  @param sessions 目标会话
*
*  @param completion 完成回调
*/
- (void)deleteServerSessions:(NSArray<QYKFNIMSession *> *)sessions
                  completion:(nullable QYKFNIMRemoteRecentSessionBlock)completion;
                        

/**
 *  从服务器上获取一个会话里某条消息之前的若干条的消息
 *
 *  @param session 消息所属的会话
 *  @param option  搜索选项
 *  @param result  读取的消息列表结果
 *  @discussion    此接口不支持查询聊天室消息，聊天室请参考 QYKFNIMChatroomManagerProtocol 中的查询消息接口。
 *
 */
- (void)fetchMessageHistory:(QYKFNIMSession *)session
                     option:(QYKFNIMHistoryMessageSearchOption *)option
                     result:(nullable QYKFNIMFetchMessageHistoryBlock)result;




/**
 *  根据关键字从服务器上检索消息
 *
 *  @param session 消息所属的会话
 *  @param option  检索选项
 *  @param result  读取的消息列表结果
 *  @discussion    检索消息内容，大小写不敏感；此接口不支持查询聊天室消息，聊天室请参考 QYKFNIMChatroomManagerProtocol 中的消息接口。
 *
 */
- (void)retrieveServerMessages:(QYKFNIMSession *)session
                        option:(QYKFNIMMessageServerRetrieveOption *)option
                        result:(nullable QYKFNIMRetrieveServerMessagesBlock)result;




/**
 *  根据关键字从服务器上全量检索消息
 *
 *  @param option  检索选项
 *  @param result  读取的消息列表结果
 *  @discussion    检索消息内容，此接口仅支持查询P2P和群聊消息，不支持聊天室和超大群
 *
 */
- (void)retrieveServerMessages:(QYKFNIMMessageFullKeywordSearchOption *)option
                        result:(nullable QYKFNIMRetrieveServerMessagesBlock)result;

/**
 * 云端历史消息全文检索（按时间排序，不按会话分组）
 *
 * @param option 检索选项，其中sessionLimit为无效变量
 * @param result  读取的消息列表结果
 * @discussion    检索消息内容
 */
- (void)retrieveServerMessagesOrderByTime:(QYKFNIMMessageFullKeywordSearchOrderByTimeOption *)option
                                   result:(nullable QYKFNIMRetrieveServerMessagesBlock)result;

/**
 *  搜索本地会话内消息
 *
 *  @param session 消息所属的会话
 *  @param option  搜索选项
 *  @param result  读取的消息列表结果
 *
 */
- (void)searchMessages:(QYKFNIMSession *)session
                option:(QYKFNIMMessageSearchOption *)option
                result:(nullable QYKFNIMSearchMessageBlock)result;

/**
 *  全局搜索本地消息
 *
 *  @param option 搜索选项
 *  @param result 读取的消息内容
 */
- (void)searchAllMessages:(QYKFNIMMessageSearchOption *)option
                   result:(nullable QYKFNIMGlobalSearchMessageBlock)result;



/**
 *  删除服务器端最近会话
 *
 *  @param sessions   需要删除的会话列表，内部只能是QYKFNIMSession
 *  @param completion 完成的回调
 *  @discussion       调用这个接口成功后，当前会话之前的消息都不会漫游到其他端
 */
- (void)deleteRemoteSessions:(NSArray<QYKFNIMSession *> *)sessions
                  completion:(nullable QYKFNIMRemoveRemoteSessionBlock)completion;

/**
 *  清空点对点会话对应服务端的消息
 *
 *  @param session 目标会话列表
 *  @param option 清空消息选项
 *  @param completion 完成回调
 *  @discussion 只支持点对点，清空本用户的服务端消息，不影响对方；如果不设置清空选项，服务端默认会同时清空漫游消息；
 */
- (void)deleteSelfRemoteSession:(QYKFNIMSession *)session
                         option:(nullable QYKFNIMClearMessagesOption *)option
                     completion:(nullable QYKFNIMRemoveRemoteSessionBlock)completion;

/**
 *  更新最近会话的本地扩展
 *
 *  @param ext           扩展信息
 *  @param recentSession 要更新的最近会话
 *  @discussion          此扩展不会漫游到其他端,上层需要保证 NSDictionary 可以转换为 JSON。
 */
- (void)updateRecentLocalExt:(nullable NSDictionary *)ext
               recentSession:(QYKFNIMRecentSession *)recentSession;


/**
 *  更新最近会话的本地扩展
 *
 *  @param ext           扩展信息
 *  @param recentSession 要更新的最近会话
 *  @param notifyRecentUpdate 是否回调会话变更
 *  @discussion          此扩展不会漫游到其他端,上层需要保证 NSDictionary 可以转换为 JSON。
 */
- (void)updateRecentLocalExt:(nullable NSDictionary *)ext
               recentSession:(QYKFNIMRecentSession *)recentSession
          notifyRecentUpdate:(BOOL)notifyRecentUpdate;


/**
 导出历史消息到本地文件

 @param delegate 自定义消息的处理 delegate
 @param progress 导出进度更新回调
 @param completion 导出完成回调
 */
- (void)exportMeessageInfosWithDelegate:(id<QYKFNIMExportMessageDelegate>)delegate
                               progress:(QYKFNIMExportMessageProgress)progress
                             completion:(QYKFNIMExportMessageComletion)completion;


/**
 导入历史消息

 @param infoFilePath 已解码并序列化了的本地历史消息文件路径
 @param delegate 自定义消息的处理 delegate
 @param progress 导入进度更新回调
 @param completion 导入完成回调
 */
- (void)importMessageInfosAtPath:(NSString *)infoFilePath
                        delegate:(id<QYKFNIMImportMessageDelegate>)delegate
                        progress:(QYKFNIMImportMessageProgress)progress
                      completion:(QYKFNIMImportMessageCompletion)completion;


/**
 取消 导出/导入 历史消息操作
 */
- (void)cancelMigrateMessages;


/**
 更新历史消息备份信息

 @param URL 历史消息备份的 URL
 @param key 历史消息备份的加密 key
 @param completion 更新信息的完成回调
 */
- (void)updateMigrateMessageInfoWithURL:(NSString *)URL key:(NSString *)key completion:(QYKFNIMUpdateMigrateMessageCompletion)completion;


/**
 获取历史消息备份信息

 @param completion 获取历史消息备份的完成回调
 */
- (void)fetchMigrateMessageInfo:(QYKFNIMFetchMigrateMessageCompletion)completion;

/**
 反序列化消息数据

 @param encodeData 序列化的数据
 @return 消息对象
 @discussion  此接口用于反序列化消息的数据，请与encodeMessageToData配套使用，用于实现消息本地序列化
*/
- (QYKFNIMMessage *)decodeMessageFromData:(NSData *)encodeData;

/**
 序列化消息

 @param message 消息对象
 @return 序列化数据
 @discussion  此接口用于序列化消息，请与decodeMessageFromData配套使用，用于实现消息本地序列化
*/
- (NSData *)encodeMessageToData:(QYKFNIMMessage *)message;


#pragma mark - 漫游消息未完整会话接口

/**
 查询漫游消息未完整会话信息

 @param session 目标会话
 @param completion 结果完成回调
*/
- (void)incompleteSessionInfoBySession:(QYKFNIMSession *)session
                            completion:(nullable QYKFNIMIncompleteSessionsBlock)completion;
/**
 查询所有漫游消息未漫游完整会话信息

 @param completion 结果完成回调
*/
- (void)allIncompleteSessionInfos:(QYKFNIMIncompleteSessionsBlock)completion;

/**
 更新未漫游完整会话列表

 @param messages 消息对象，使用QYKFNIMMessage的会话、severId、timestamp、from等去更新b
 @param completion 结果完成回调
*/
- (void)updateIncompleteSessions:(NSArray<QYKFNIMMessage *> *)messages
                      completion:(nullable QYKFNIMUpdateIncompleteSessionsBlock)completion;

/**
 根据会话移除未漫游完整会话信息
 
 @param session 目标会话
 */
- (void)removeIncompleteSessionInfoBySession:(QYKFNIMSession *)session;

/**
 移除所有未完整会话信息
 */
- (void)removeAllIncompleteSessionInfos;


/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<QYKFNIMConversationManagerDelegate>)delegate;

/**
 *  删除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<QYKFNIMConversationManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END



