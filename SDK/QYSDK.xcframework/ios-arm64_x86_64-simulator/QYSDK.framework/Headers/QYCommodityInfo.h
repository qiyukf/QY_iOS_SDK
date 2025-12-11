/**
 * @file QYCommodityInfo.h
 * @brief 商品信息卡片与订单信息模型。
 * @details 提供商品卡片展示、行为按钮、订单关联与卡片参数等。
 *
 * @defgroup commodity 商品与订单模块
 */

#import <Foundation/Foundation.h>

/**
 * @brief 商品信息卡片按钮。
 * @ingroup commodity
 */
@interface QYCommodityTag : NSObject
@property (nonatomic, copy) NSString *label;       //! 按钮文案
@property (nonatomic, copy) NSString *url;         //! 跳转 URL
@property (nonatomic, copy) NSString *focusIframe; //! 聚焦 iframe
@property (nonatomic, copy) NSString *data;        //! 附加数据
@end

/**
 * @brief 订单阶段类型。
 */
typedef NS_ENUM(NSUInteger, QYOrderStageType) {
    QYOrderStageTypePreSale = 10000,     //! 售前
    QYOrderStageTypePreDelivery = 20000, //! 发货前
    QYOrderStageTypeAfterDelivery = 30000, //! 发货后
    QYOrderStageTypeAfterSale = 40000,   //! 售后
};

/**
 * @brief 商品信息模型。
 * @details 用于会话中展示商品/订单信息卡片。
 * @ingroup commodity
 */
@interface QYCommodityInfo : NSObject

@property (nonatomic, copy) NSString *pictureUrlString; //! 商品图片链接（<1000 字符）
@property (nonatomic, copy) NSString *title;            //! 商品标题（<100 字符）
@property (nonatomic, copy) NSString *desc;             //! 商品描述（<300 字符）
@property (nonatomic, copy) NSString *note;             //! 备注信息（价格/订单号等，<100 字符）
@property (nonatomic, copy) NSString *urlString;        //! 跳转 URL（<1000 字符）
@property (nonatomic, copy) NSArray<QYCommodityTag *> *tagsArray; //! 标签数组
@property (nonatomic, copy) NSString *tagsString;       //! 标签数据，字符串类型，与数组类型二选一
@property (nonatomic, assign) BOOL show;                //! 发送时是否在访客端隐藏（默认隐藏）
@property (nonatomic, assign) BOOL isPictureLink;       //! 是否仅显示图片链接（默认否）
@property (nonatomic, assign) BOOL sendByUser;          //! 是否由访客主动发送（默认否）
@property (nonatomic, copy) NSString *actionText;       //! 发送按钮文案
@property (nonatomic, strong) UIColor *actionTextColor; //! 发送按钮文案颜色
@property (nonatomic, copy) NSString *ext;              //! 特定用户使用的扩展字段
@property (nonatomic, assign) NSInteger cardType;       //! 卡片类型：商品/订单/自定义（0/1/2）
@property (nonatomic, copy) NSString *goodsCId;         //! 商品类目 ID（最多 100 字符，最多100字符，商品所属类目ID，填写后有助于机器人识别商品和后续业务）
@property (nonatomic, copy) NSString *goodsCName;       //! 商品类目名称（最多 10 字符）
@property (nonatomic, copy) NSString *goodsId;          //! 商品 ID（最多 100 字符，最多100字符，商品唯一标识符，填写后有助于机器人识别商品和后续业务）
@property (nonatomic, copy) NSString *orderId;          //! 订单 ID，交易订单号（父订单的交易编号），当卡片类型为订单时，推荐必填
@property (nonatomic, copy) NSString *intent;           //! 支持商品卡片带参数给一触即达
@property (nonatomic, copy) NSString *info;             //! 卡片附加信息，信息不展示在UI中,长度限制为100字符，超过自动截断
@property (nonatomic, assign) long long agentId;        //! 指定机器人接待的大模型 AgentId
@property (nonatomic, assign) QYOrderStageType orderStageType; //! 订单状态
@end

/**
 * @brief 机器人模式下选中的商品/订单信息。
 * @ingroup commodity
 */
@interface QYSelectedCommodityInfo : NSObject
@property (nonatomic, copy) NSString *target;      //! 目标标识
@property (nonatomic, copy) NSString *params;      //! 参数
@property (nonatomic, copy) NSString *p_status;    //! 状态
@property (nonatomic, copy) NSString *p_img;       //! 图片
@property (nonatomic, copy) NSString *p_name;      //! 名称
@property (nonatomic, copy) NSString *p_price;     //! 价格
@property (nonatomic, copy) NSString *p_count;     //! 数量
@property (nonatomic, copy) NSString *p_stock;     //! 库存
@property (nonatomic, copy) NSString *p_action;    //! 动作
@property (nonatomic, copy) NSString *p_url;       //! URL
@property (nonatomic, copy) NSString *p_userData;  //! 用户数据
@end
