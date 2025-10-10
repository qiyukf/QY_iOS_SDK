//
//  QYCommodityInfo.h
//  QYSDK
//
//  Created by Netease on 16/5/26.
//  Copyright (c) 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  QYCommodityTag：自定义商品信息卡片按钮信息
 */
@interface QYCommodityTag : NSObject

@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *focusIframe;
@property (nonatomic, copy) NSString *data;

@end

typedef NS_ENUM(NSUInteger, QYOrderStageType) {
    QYOrderStageTypePreSale = 10000,//售前
    QYOrderStageTypePreDelivery = 20000,//发货前
    QYOrderStageTypeAfterDelivery = 30000,//发货后
    QYOrderStageTypeAfterSale = 40000,//售后
};

/**
 *  商品信息类：QYCommodityInfo
 */
@interface QYCommodityInfo : NSObject

/**
 *  商品图片链接，字符数要求小于1000
 */
@property (nonatomic, copy) NSString *pictureUrlString;

/**
 *  商品标题，字符数要求小于100
 */
@property (nonatomic, copy) NSString *title;

/**
 *  商品描述，字符数要求小于300
 */
@property (nonatomic, copy) NSString *desc;

/**
 *  备注信息，可以显示价格，订单号等，字符数要求小于100
 */
@property (nonatomic, copy) NSString *note;

/**
 *  跳转url，字符数要求小于1000
 */
@property (nonatomic, copy) NSString *urlString;

/**
 *  标签数据，数组类型
 */
@property (nonatomic, copy) NSArray<QYCommodityTag *> *tagsArray;

/**
 *  标签数据，字符串类型，与数组类型二选一
 */
@property (nonatomic, copy) NSString *tagsString;

/**
 *  发送时是否在访客端隐藏，默认隐藏
 */
@property (nonatomic, assign) BOOL show;

/**
 *  是否仅显示商品图片，默认否 (V5.5.0, 为避免歧义由isCustom修改为isPictureLink)
 */
@property (nonatomic, assign) BOOL isPictureLink;

/**
 *  是否由访客主动发送，默认否；设置为YES，消息下方新增发送按钮 (v4.4.0)
 */
@property (nonatomic, assign) BOOL sendByUser;

/**
 *  发送按钮文案 (v4.4.0)
 */
@property (nonatomic, copy) NSString *actionText;

/**
 *  发送按钮文案颜色 (v4.4.0)
 */
@property (nonatomic, strong) UIColor *actionTextColor;

/**
 *  一般用户不需要填这个字段，这个字段仅供特定用户使用
 */
@property (nonatomic, copy) NSString *ext;

/**
 *  卡片类型
 * 商品卡片标识，填写后有助于机器人识别商品和后续业务。共三种类型：商品、订单、自定义卡片，分别传0 1 2
 */
@property (nonatomic, assign) NSInteger cardType;

/**
 *  商品类目ID
 *  最多100字符，商品所属类目ID，填写后有助于机器人识别商品和后续业务
 */
@property (nonatomic, copy) NSString *goodsCId;

/**
 *  商品类目名称
 *  最多10字，商品所属类目名称
 */
@property (nonatomic, copy) NSString *goodsCName;

/**
 *  商品ID
 *  最多100字符，商品唯一标识符，填写后有助于机器人识别商品和后续业务
 */
@property (nonatomic, copy) NSString *goodsId;


/**
 *  订单ID
 *  交易订单号（父订单的交易编号），当卡片类型为订单时，推荐必填
 */
@property (nonatomic, copy) NSString *orderId;

/**
 *  支持商品卡片带参数给一触即达
 *
 */
@property (nonatomic, copy) NSString *intent;

/**
 *  卡片附加信息，信息不展示在UI中,长度限制为100字符，超过自动截断
 *
 */
@property (nonatomic, copy) NSString *info;

/**
 *  AgentId，用于指定机器人接待的大模型
 *
 */
@property (nonatomic, assign) long long agentId;

/**
 *  订单状态
 *
 */
@property (nonatomic, assign) QYOrderStageType orderStageType;
@end


/**
 *  自定义商品信息类：QYSelectedCommodityInfo，用于机器人模式下发送商品/订单等场景
 */
@interface QYSelectedCommodityInfo : NSObject

@property (nonatomic, copy) NSString *target;
@property (nonatomic, copy) NSString *params;
@property (nonatomic, copy) NSString *p_status;
@property (nonatomic, copy) NSString *p_img;
@property (nonatomic, copy) NSString *p_name;
@property (nonatomic, copy) NSString *p_price;
@property (nonatomic, copy) NSString *p_count;
@property (nonatomic, copy) NSString *p_stock;
@property (nonatomic, copy) NSString *p_action;
@property (nonatomic, copy) NSString *p_url;
@property (nonatomic, copy) NSString *p_userData;

@end
