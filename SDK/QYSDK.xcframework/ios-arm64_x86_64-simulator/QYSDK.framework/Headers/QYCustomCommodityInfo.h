
/**
 * @file QYCustomCommodityInfo.h
 * @brief 自定义商品卡片消息模型。
 * @details 收到客服发来的自定义商品卡片消息时，数据库会插入一条 QYCustomCommodityInfo 类型消息；通过注册接口注入 model 和 view 以配置 UI 显示。
 * @defgroup QYCustomMsg 自定义消息
 */

#import <Foundation/Foundation.h>
#import "QYCustomMessage.h"

/**
 * @brief 自定义商品卡片消息。
 * @details 对应客服发来的商品卡片消息，客户端持久化为 QYCustomCommodityInfo。
 * @ingroup QYCustomMsg
 */
@interface QYCustomCommodityInfo : QYCustomMessage
/**
 * @brief 服务端透传的 JSON 数据。
 * @details 原始 JSON 字符串，可由业务方自行解析。
 */
@property (nonatomic, copy, readonly) NSString *jsonData;
@end

