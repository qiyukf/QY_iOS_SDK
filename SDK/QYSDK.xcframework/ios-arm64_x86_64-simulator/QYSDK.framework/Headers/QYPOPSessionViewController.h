
/**
 * @file QYPOPSessionViewController.h
 * @brief 平台电商会话控制器扩展。
 * @details 在会话控制器上扩展 POP 专用字段与回调。
 * @ingroup QYPOP
 */
#import "QYSessionViewController.h"

/**
 * @brief 平台电商专用会话分类。
 * @details 添加商铺 ID 与会话窗口回调属性。
 * @ingroup QYPOP
 */
@interface QYSessionViewController (POP)
/**
 * @brief 平台电商店铺 ID。
 * @details 非平台电商场景可忽略该字段。
 */
@property (nonatomic, copy) NSString *shopId;
/**
 * @brief 会话窗口回调。
 */
@property (nonatomic, weak) id<QYSessionViewDelegate> delegate;
@end
