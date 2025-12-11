
/**
 * @file QYPOPMessageInfo.h
 * @brief 平台电商消息信息扩展。
 * @details 为消息信息扩展商铺 ID、头像 URL 与发送者字段。
 * @ingroup QYPOP
 */
#import <Foundation/Foundation.h>

/**
 * @brief 平台电商消息信息。
 * @details 扩展 POP 场景下的消息关联信息。
 * @ingroup QYPOP
 */
@interface QYMessageInfo (POP)
/**
 * @brief 平台电商店铺 ID。
 * @details 非平台电商场景可忽略该字段。
 */
@property (nonatomic, copy) NSString *shopId;
/**
 * @brief 会话头像 URL。
 */
@property (nonatomic, copy) NSString *avatarImageUrlString;
/**
 * @brief 发送者。
 */
@property (nonatomic, copy) NSString *sender;
@end

