/**
 * @file QYCustomContentView.h
 * @brief 自定义消息视图基类。
 * @details 针对需要自定义的消息视图，编写子类继承 QYCustomContentView，并实现初始化与刷新方法，本分组包含自定义消息的模型定义、视图基类、协议、事件以及会话扩展接口。
 * @defgroup QYCustomMsg 自定义消息
 */
#import <UIKit/UIKit.h>

@class QYCustomModel;
@protocol QYCustomContentViewDelegate;

/**
 * @brief 自定义消息视图基类。
 * @details 使用子类实现 `initCustomContentView` 与 `refreshData:` 来完成视图搭建与刷新。
 * @ingroup QYCustomMsg
 */
@interface QYCustomContentView : UIView
/**
 * @brief 数据模型。
 * @details 传入的 `QYCustomModel`，用于驱动视图展示。
 */
@property (nonatomic, strong, readonly) QYCustomModel *model;
/**
 * @brief 事件代理。
 * @details 通过 `addCustomContentViewDelegate:` 方法设置。
 */
@property (nonatomic, weak, readonly) id<QYCustomContentViewDelegate> delegate;
/**
 * @brief 视图初始化方法。
 * @details 一般在此方法中添加子视图。
 * @return 视图实例。
 */
- (instancetype)initCustomContentView;
/**
 * @brief 刷新视图数据。
 * @details 当模型变更时自动触发，需要在子类中重写以更新视图。
 * @param model 数据模型。
 */
- (void)refreshData:(QYCustomModel *)model;
@end
