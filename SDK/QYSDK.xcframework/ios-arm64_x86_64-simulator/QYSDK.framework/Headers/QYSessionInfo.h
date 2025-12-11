/**
 * @file QYSessionInfo.h
 * @brief 会话详情模型声明。
 * @details 提供会话的最后消息、未读数与状态等信息，用于会话列表展示。
 *
 * @defgroup conversation 会话管理模块
 */

#import <Foundation/Foundation.h>
#import "QYMessageInfo.h"

@class QYKFNIMMessage;

/**
 * @brief 会话状态类型。
 * @details 表示会话的当前状态。
 */
typedef NS_ENUM(NSInteger, QYSessionStatus) {
    QYSessionStatusNone,        //! 无状态
    QYSessionStatusWaiting,     //! 排队中
    QYSessionStatusInSession    //! 会话中
};

/**
 * @brief 会话详情信息模型。
 * @details 用于会话列表展示与未读数统计等。
 * @ingroup conversation
 */
@interface QYSessionInfo : NSObject

/**
 * @brief 最后一条消息的摘要文本。
 */
@property (nonatomic, copy) NSString *lastMessageText;

/**
 * @brief 最后一条消息对象。
 */
@property (nullable,nonatomic,strong) QYKFNIMMessage  *lastMessage;

/**
 * @brief 最后一条消息的类型。
 * @see QYMessageType
 */
@property (nonatomic, assign) QYMessageType lastMessageType;

/**
 * @brief 会话未读数。
 */
@property (nonatomic, assign) NSInteger unreadCount;

/**
 * @brief 会话状态。
 * @see QYSessionStatus
 */
@property (nonatomic, assign) QYSessionStatus status;

/**
 * @brief 最后一条消息的时间戳。
 */
@property (nonatomic, assign) NSTimeInterval lastMessageTimeStamp;

/**
 * @brief 是否存在垃圾词汇。
 * @details 可用于展示额外状态或做业务处理。
 */
@property (nonatomic, assign) BOOL hasTrashWords;

@end
