
/**
 * @file QYWorkOrderListViewController.h
 * @brief 工单列表视图控制器。
 * @details 支持根据模板 ID、可催单标识与商户 ID 初始化并查询工单。
 * @defgroup QYWorkOrder 工单
 */

#import <UIKit/UIKit.h>

/**
 * @brief 工单错误码。
 * @ingroup QYWorkOrder
 */
typedef NS_ENUM(NSInteger, QYWorkOrderErrorCode) {
    QYWorkOrderErrorCodeUnknown         = 0,    //! 未知错误
    QYWorkOrderErrorCodeInvalidAccount  = 1,    //! 无效帐号，当前帐号未登录
    QYWorkOrderErrorCodeInvalidParam    = 2,    //! 错误参数，一般是 templateIDList 错误
};


/**
 * @brief 工单列表视图控制器。
 * @ingroup QYWorkOrder
 */
@interface QYWorkOrderListViewController : UIViewController

/**
 * @brief 校验结果。
 * @details 使用方法：调用初始化方法创建 VC 后，若为 nil 可 push/present 进入 VC。
 * @note 常见错误：
 * 1. `QYWorkOrderErrorCodeInvalidAccount`：当前访客帐号未登录；
 * 2. `QYWorkOrderErrorCodeInvalidParam`：`templateIDList` 有误，必须是元素为 `NSNumber` 的数组。
 */
@property (nonatomic, strong, readonly) NSError *verifyError;

/**
 * @brief 初始化方法。
 * @param templateIDList 查询工单限制条件：模板 ID 列表。
 * @param canReminder 访客是否可催单。
 * @param shopId 商户 ID；非平台企业可不传；平台子商户需传商户 ID；主商户可不传。
 * @return 控制器实例。
 */
- (instancetype)initWithTemplateIDList:(NSArray <NSNumber *> *)templateIDList
                           canReminder:(BOOL)canReminder
                                shopId:(NSString *)shopId;

@end

