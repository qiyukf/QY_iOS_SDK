
/**
 * @file QYConversationManager.h
 * @brief 会话管理入口与委托定义。
 * @details 提供未读数、会话列表、委托设置等核心接口。
 * @defgroup QYConversation 会话管理
 */
#import <Foundation/Foundation.h>

@class QYMessageInfo;
@class QYSessionInfo;

/**
 * @brief 会话委托。
 * @details 提供未读数变化、会话列表变化、接收消息的监听。
 * @ingroup QYConversation
 */
@protocol QYConversationManagerDelegate <NSObject>

@optional

/**
 * @brief 会话未读数变化。
 * @param count 未读数。
 */
- (void)onUnreadCountChanged:(NSInteger)count;

/**
 * @brief 会话列表变化。
 * @details 非平台电商只有一个会话项；平台电商有多个会话项。
 * @param sessionList 会话列表。
 */
- (void)onSessionListChanged:(NSArray<QYSessionInfo *> *)sessionList;

/**
 * @brief 接收消息。
 * @param message 消息信息。
 */
- (void)onReceiveMessage:(QYMessageInfo *)message;

@end


/**
 * @brief 会话管理类。
 * @details 负责会话数据的获取与状态维护。
 * @ingroup QYConversation
 */
@interface QYConversationManager : NSObject
/**
 * @brief 所有的未读数。
 * @return 未读数。
 */
- (NSInteger)allUnreadCount;

/**
 * @brief 清空未读数。
 * @details 平台版企业会清空所有会话的未读消息，包括子企业。
 */
- (void)clearUnreadCount;

/**
 * @brief 清空某个子企业的未读数。
 * @param shopId 子企业商铺 ID。
 */
- (void)clearUnreadCountWithShopId:(NSString *)shopId;

/**
 * @brief 获取所有会话的列表。
 * @details 非平台电商用户只有一个会话项；平台电商用户有多个会话项。
 * @return 包含 `QYSessionInfo` 的数组。
 */
- (NSArray<QYSessionInfo *> *)getSessionList;

/**
 * @brief 设置会话委托。
 * @param delegate 会话委托对象。
 */
- (void)setDelegate:(id<QYConversationManagerDelegate>)delegate;

@end

