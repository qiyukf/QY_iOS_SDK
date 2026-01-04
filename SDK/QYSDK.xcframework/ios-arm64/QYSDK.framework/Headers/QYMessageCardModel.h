//
//  QYMessageCardModel.h
//  QYKit
//
//  Created by zhongzhida on 2024/3/18.
//  Copyright © 2024 Netease. All rights reserved.
//
/**
 * @file QYMessageCardModel.h
 * @brief 卡片消息模型与模板说明。
 * @details 定义卡片消息的自动发送策略、阶段分类、按钮文案与样式，以及卡片/浮动卡片的模板内容。
 *
 * @defgroup QYCardMsg 卡片消息
 */

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 订单状态分类阶段。
 * @details 用户所处服务阶段，用于定制不同阶段的卡片内容展示与交互。
 * @ingroup QYCardMsg
 */
typedef NS_ENUM(NSUInteger, QYCardStageType) {
    QYCardStageTypePreSale = 10000,      //! 售前
    QYCardStageTypePreDelivery = 20000,  //! 发货前
    QYCardStageTypeAfterDelivery = 30000,//! 发货后
    QYCardStageTypeAfterSale = 40000,    //! 售后
};
/**
 * @brief 卡片消息模型。
 * @details 配置卡片消息的发送时机、阶段类型、按钮文案与样式，以及卡片/浮动卡片内容列表。
 * @ingroup QYCardMsg
 */
@interface QYMessageCardModel : NSObject


/**
 * @brief 机器人会话是否发送卡片消息。
 * @details 1 表示机器人阶段与人工阶段都发送；0 表示仅在人工会话中发送。
 * @note 默认值为 0。
 */
@property (nonatomic, assign) NSInteger autoSendInRobot;

/**
 * @brief 留言阶段是否发送卡片消息。
 * @details 仅对留言样式的消息生效；1 发送，0 不发送。
 * @note 默认值为 0。
 */
@property (nonatomic, assign) NSInteger autoSendInLeave;

/**
 * @brief 发送方式。
 * @details 0 表示进线自动发送；1 表示手动发送。
 * @note 默认值为 0。
 */
@property (nonatomic, assign) NSInteger sendByUser;

/**
 * @brief 订单状态分类。
 * @details 用于区分售前、发货前、发货后、售后四个阶段。
 */
@property (nonatomic, assign) QYCardStageType stageType;

/**
 * @brief 意图名称。
 * @details 作为会话的透传参数，用于后端或机器人识别业务意图。
 */
@property (nonatomic, copy) NSString *intent;

/**
 * @brief 一触即达流程参数。
 * @details 作为会话的透传参数，用于配置特定业务流程。
 */
@property (nonatomic, copy) NSString *params;

/**
 * @brief 发送按钮标题。
 */
@property (nonatomic, copy) NSString *actionText;

/**
 * @brief 发送按钮文字颜色。
 */
@property (nonatomic, copy) UIColor *actionTextColor;

/**
 * @brief 发送按钮字体大小。
 */
@property (nonatomic, assign) CGFloat actionFontSize;

/**
 * @brief 卡片消息内容列表。
 * @details 共 9 种模板类型，可重复添加。支持类型：标题、副标题、图片、操作按钮、订单、商品、富文本、跳转链接、节点流程、标签。
 * @note 请按官网字段规范构造各模板数据项。
 * @see 官网字段说明
 */
@property (nonatomic, strong) NSArray<NSDictionary *> *cards;

/**
 * @brief 浮动卡片消息内容列表。
 * @details 共 2 种模板类型，可重复添加；展示效果与 `cards` 不同，为浮动样式。支持类型：操作按钮、商品。
 * @note 请按官网字段规范构造各模板数据项。
 * @see 官网字段说明
 */
@property (nonatomic, strong) NSArray<NSDictionary *> *floatCards;

/**以下内容为cards字段和floatCards字段中NSDictionary需要携带的字段示例*/
/**示例及字段说明以官网为准*/
/**
 pl 左边距，
 pr 右边距，
 pt 上边距，
 pb 下边距，
 divider    是否有分割线，
 fontSize   字体大小，
 fontColor  字体颜色，
 subFontSize    副标题字体大小，
 subFontColor   副标题字体颜色
 
/**
    标题
 {
     "img": "https://res.qiyukf.net/operation/a233f8653cabd00ca9f2ad89b14c22e6",
     "style": {
         "pb": 10,
         "pr": 20,
         "pt": 10,
         "divider": 1,
         "fontSize": "28px",
         "pl": 20,
         "fontColor": "#26c952"
     },
     "type": "title",
     "content": "Card标题模板",
     "url": "跳转链接"
 }
 */

/**
    副标题
 {
     "img": "https://res.qiyukf.net/operation/e32bbc516ee7c88031aeefd8261b3f8c",
     "style": {
         "backgroundColor": "#ea0a0a",
         "pb": 10,
         "pr": 20,
         "subFontSize": "14px",
         "pt": 10,
         "divider": 1,
         "subFontColor": "#08a81b",
         "fontSize": "20px",
         "pl": 20,
         "fontColor": "#d42fc9"
     },
     "type": "subtitle",
     "content": "subtitle模板",
     "subContent": "subtitle模板",
     "url": "https://qiyukf.com/"
 }
 */

/**
    图片
 {
     "img": "https://res.qiyukf.net/operation/e32bbc516ee7c88031aeefd8261b3f8c",
     "style": {
         "pb": 16,
         "pr": 24,
         "pt": 16,
         "divider": 1,
         "pl": 24
     },
     "type": "image",
     "url": "https://qiyukf.com/"
 }
 */

/**
    操作按钮
 {
     "type": "button",
     "numInRow": 4,
     "data": [
         {
             "action": 0,
             "title": "1跳转",
             "url": "https://qiyukf.com/",
             "content": "发送内容_cards_2023020_1"
         }
     ],
     "style": {
         "backgroundColor": "#bbe6f0",
         "pb": 16,
         "pr": 24,
         "pt": 16,
         "divider": 1,
         "fontSize": 16,
         "pl": 24,
         "fontColor": "#19e34f"
     }
 }
 */

/**
    商品
 {
     "type": "product",
     "data": [
         {
             "price": "￥111.11",
             "action": 0,
             "id": "cards_2023020_1",
             "title": "标题title1111",
             "picture": "https://res.qiyukf.net/operation/e32bbc516ee7c88031aeefd8261b3f8c",
             "url": "https://qiyukf.com/",
             "desc": "描述desc111111"
         },
         {
             "price": "$222.22",
             "action": 1,
             "id": "cards_2023020_2",
             "title": "标题title2222",
             "picture": "https://res.qiyukf.net/operation/a36b57015f609344d1ceebef413664c2",
             "url": "https://qiyukf.com/",
             "desc": "描述desc22222"
         }
     ],
     "style": {
         "pb": 16,
         "pr": 24,
         "pt": 16,
         "divider": 1,
         "pl": 24
     }
 }
 */

/**
    订单
 {
     "type": "order",
     "orderTime": "2024-02-01 12:34:56",
     "data": [
         {
             "payMoney": "￥1.1",
             "count": "x 111",
             "action": 0,
             "title": "标题_orderId",
             "sku": "sku_orderId_2023020_1",
             "picture": "https://res.qiyukf.net/operation/a36b57015f609344d1ceebef413664c2",
             "url": "https://qiyukf.com/",
             "desc": "描述_orderId_2",
             "status": "已发货"
         },
         {
             "payMoney": "￥222.22",
             "count": "x 222",
             "action": 1,
             "title": "标题_orderId",
             "sku": "sku_orderId_2023020_2",
             "picture": "https://res.qiyukf.net/operation/a36b57015f609344d1ceebef413664c2",
             "url": "https://qiyukf.com/",
             "desc": "描述_orderId"
         }
     ],
     "orderId": "orderId_2023020",
     "style": {
         "pb": 16,
         "pr": 24,
         "pt": 16,
         "divider": 1,
         "pl": 24
     }
 }
 */
/**
    富文本
 {
     "style": {
         "pb": 20,
         "pr": 20,
         "pt": 20,
         "divider": 1,
         "pl": 20
     },
     "type": "rich",
     "content": "<video class=\"ql-video\" width=\"1414\" height=\"2560\" src=\"https://jnncs43.qiyukf.net/f77dd537cfae7ad56e9c151b2c748f4f.mp4?download=3a20e612bd686300bd0e0968ef682d49.mp4\" controls=\"true\"></video><p>IOS</p>"
 }
 */
/**
    跳转链接
 {
     "type": "link",
     "content": "查看更多",
     "url": "https://res.qiyukf.net/operation/a36b57015f609344d1ceebef413664c2",
     "style": {
         "pb": 16,
         "pr": 24,
         "pt": 16,
         "divider": 0,
         "fontSize": 18,
         "pl": 24,
         "fontColor": "#0a40f2"
     }
 }
 */
/**
    节点流程
 
 {
     "data": [
         {
             "current": 0,
             "subtitle": "计划起飞时间",
             "id": 111,
             "title": "北京 -> 杭州"
         },
         {
             "current": 1,
             "subtitle": "subtitle_subtitle_subtitle_subtitle_subtitle",
             "id": 222,
             "title": "杭州杭州杭州 -> 北京北京北京"
         }
     ],
     "style": {
         "pb": 16,
         "pr": 24,
         "subFontSize": "14px",
         "pt": 16,
         "divider": 1,
         "sunFontColor": "#08a81b",
         "fontSize": "30px",
         "pl": 24,
         "fontColor": "#d42fc9"
     },
     "type": "flow"
 }

 */
@end

NS_ASSUME_NONNULL_END
