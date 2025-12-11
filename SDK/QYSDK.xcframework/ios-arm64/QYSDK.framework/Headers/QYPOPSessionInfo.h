
/**
 * @file QYPOPSessionInfo.h
 * @brief 平台电商会话详情扩展。
 * @details 在会话列表的会话详情中扩展商铺 ID、头像 URL 与会话名称。
 * @ingroup QYPOP
 */

#import "QYSessionInfo.h"

/**
 * @brief 会话列表中的会话详情信息（平台电商专用）
 * @details 为会话详情增加 POP 专用字段。
 * @ingroup QYPOP
 */
@interface QYSessionInfo (POP)
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
 * @brief 会话名称。
 */
@property (nonatomic, copy) NSString *sessionName;
@end
