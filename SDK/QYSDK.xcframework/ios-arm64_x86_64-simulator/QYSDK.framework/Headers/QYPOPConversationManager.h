
/**
 * @file QYPOPConversationManager.h
 * @brief 平台电商会话管理扩展。
 * @details 提供 POP 会话委托与会话管理分类，支持清空未读、删除会话等操作。
 * @ingroup QYPOP
 */

#import "QYConversationManager.h"

/**
 * @brief 平台电商会话委托。
 * @details 提供 POP 会话列表变更与消息接收的回调。
 * @ingroup QYPOP
 */
@protocol QYPOPConversationManagerDelegate <NSObject>
/**
 * @brief 会话列表发生变化。
 */
- (void)onSessionListChanged;
/**
 * @brief 收到消息。
 * @param message 消息信息。
 */
- (void)onReceiveMessage:(QYMessageInfo *)message;
@end

/**
 * @brief 平台电商会话管理分类。
 * @details 在默认会话管理基础上扩展 POP 相关接口。
 * @ingroup QYPOP
 */
@interface QYConversationManager (POP)
/**
 * @brief 清空会话的未读数。
 * @param shopId 商铺 ID。
 */
- (void)clearUnreadCount:(NSString *)shopId;
/**
 * @brief 删除会话列表中的会话。
 * @param shopId 商铺 ID。
 * @param isDelete 是否同时删除消息记录（YES 删除，NO 不删除）。
 */
- (void)deleteRecentSessionByShopId:(NSString *)shopId deleteMessages:(BOOL)isDelete;
@end
