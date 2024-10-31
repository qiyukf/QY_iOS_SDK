//
//  QYMessageCardModel.h
//  QYKit
//
//  Created by zhongzhida on 2024/3/18.
//  Copyright © 2024 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, QYCardStageType) {
    QYCardStageTypePreSale = 10000,//售前
    QYCardStageTypePreDelivery = 20000,//发货前
    QYCardStageTypeAfterDelivery = 30000,//发货后
    QYCardStageTypeAfterSale = 40000,//售后
};
@interface QYMessageCardModel : NSObject

/**
 *  机器人会话是否发送卡片消息
 *  1 机器人阶段和人工阶段都发送卡片，0 仅人工会话中发送
 *  默认 0
 */
@property (nonatomic, assign) NSInteger autoSendInRobot;

/**
 *  留言阶段是否发送卡片消息
 *  仅对留言样式位消息的情况生效
 *  1 发送，0 不发送
 *  默认 0
 */
@property (nonatomic, assign) NSInteger autoSendInLeave;
/**
 *  0 进线自动发送, 1 手动发送。默认0
 */
@property (nonatomic, assign) NSInteger sendByUser;

/**
 *  订单状态分类
 */

@property (nonatomic, assign) QYCardStageType stageType;
/**
 *  意图名称
 *  透传参数
 */
@property (nonatomic, copy) NSString *intent;


/**
 *  一触即达流程参数
 *  透传参数
 */
@property (nonatomic, copy) NSString *params;

/**
 *  发送按钮标题
 */
@property (nonatomic, copy) NSString *actionText;

/**
 *  发送按钮文字颜色
 */
@property (nonatomic, copy) UIColor *actionTextColor;

/**
 *  卡片消息内容，共9种模板类型，可以重复添加
 *  支持的类型：标题、副标题、图片、操作按钮、订单、商品、富文本、跳转链接、节点流程、标签
 */

@property (nonatomic, strong) NSArray<NSDictionary *> *cards;

/**
 *  浮动卡片消息内容，共2种模板类型，可以重复添加
 *  此数组中的效果与cards展示不同，此数组的为浮动效果
 *  类型：操作按钮、商品
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
