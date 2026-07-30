/**
 * @file QYConsultationContent.h
 * @brief 客服会话咨询内容弹层的数据模型。
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief 咨询内容 Tab 类型。
 * @discussion 仅支持订单和商品两种类型；同一类型可以配置多个 Tab。
 */
typedef NS_ENUM(NSUInteger, QYConsultationContentType) {
    QYConsultationContentTypeOrder = 1,   //! 订单 Tab，数据从 orders 读取
    QYConsultationContentTypeProduct = 2, //! 商品 Tab，数据从 products 读取
};

/**
 * @brief 商品条目。
 * @discussion 可用于商品 Tab，也可作为订单中的商品明细。
 */
@interface QYConsultationContentItem : NSObject

@property (nonatomic, copy, nullable) NSString *pictureUrlString; //! 商品图片地址；为空或加载失败时显示 SDK 占位图
@property (nonatomic, copy, nullable) NSString *title;            //! 商品标题；为空时保留标题布局但不显示文案
@property (nonatomic, copy, nullable) NSString *subtitle;         //! 第一行辅助描述
@property (nonatomic, copy, nullable) NSString *detail;           //! 第二行辅助描述
@property (nonatomic, copy, nullable) NSString *price;            //! 价格展示文案，例如“¥ 98.50”；SDK 不解析或计算价格
@property (nonatomic, copy, nullable) NSString *count;            //! 数量展示文案，例如“x1”
@property (nonatomic, copy, nullable) NSString *urlString;        //! 商品或订单卡点击跳转地址

@end

/**
 * @brief 订单卡片。
 */
@interface QYConsultationOrder : NSObject

@property (nonatomic, copy, nullable) NSString *orderText;   //! 订单信息文案，例如“订单编号：VX20260709001”
@property (nonatomic, copy, nullable) NSString *timeText;    //! 时间文案
@property (nonatomic, copy, nullable) NSArray<QYConsultationContentItem *> *items; //! 订单商品明细；非法对象会被 SDK 过滤
@property (nonatomic, copy, nullable) NSString *amountTitle; //! 金额标题，例如“应付金额”
@property (nonatomic, copy, nullable) NSString *amount;      //! 订单合计金额展示文案，例如“¥ 118.40”
@property (nonatomic, copy, nullable) NSString *statusText;  //! 订单状态文案，例如“待收货”
@property (nonatomic, strong, nullable) UIColor *statusColor; //! 订单状态文字颜色

@end

/**
 * @brief 咨询内容 Tab。
 * @discussion type 决定 SDK 使用的数据字段：订单类型只读取 orders，
 * 商品类型只读取 products；另一类数据会被忽略。
 */
@interface QYConsultationContentTab : NSObject

@property (nonatomic, copy, nullable) NSString *title; //! Tab 标题
@property (nonatomic, assign) QYConsultationContentType type; //! Tab 类型；非订单/商品类型的 Tab 会被过滤
@property (nonatomic, copy, nullable) NSArray<QYConsultationOrder *> *orders; //! 订单类型数据，仅 type 为 Order 时生效
@property (nonatomic, copy, nullable) NSArray<QYConsultationContentItem *> *products; //! 商品类型数据，仅 type 为 Product 时生效

@end

/**
 * @brief 咨询内容弹层配置。
 * @discussion SDK 在展示前会对配置做快照复制和逐层类型校验，
 * 调用方后续修改原数组不会影响已提交的弹层数据。
 */
@interface QYConsultationContentConfig : NSObject

@property (nonatomic, copy, nullable) NSString *title;             //! 页面标题
@property (nonatomic, copy, nullable) NSString *bottomButtonTitle; //! 底部关闭按钮文案
@property (nonatomic, copy, nullable) NSArray<QYConsultationContentTab *> *tabs; //! Tab 数据；没有有效 Tab 时 SDK 不展示弹层
@property (nonatomic, strong, nullable) UIColor *priceColor;       //! 商品价格与订单合计金额颜色，默认红色
@property (nonatomic, strong, nullable) UIColor *headerBackgroundColor; //! 标题区与 Tab 区背景色，默认白色
@property (nonatomic, assign) NSUInteger selectedIndex;            //! 默认选中 Tab；越界或指向非法 Tab 时回退至第一个有效 Tab

@end

NS_ASSUME_NONNULL_END
