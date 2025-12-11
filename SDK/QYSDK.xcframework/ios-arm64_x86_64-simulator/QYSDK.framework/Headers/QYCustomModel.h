
/**
 * @file QYCustomModel.h
 * @brief 自定义消息数据源基类与布局协议。
 * @details 针对需自定义的消息数据源，编写子类继承 QYCustomModel，并实现布局协议以驱动消息列表刷新。
 * @defgroup QYCustomMsg 自定义消息
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class QYCustomMessage;

/**
 * @brief Model 布局协议。
 * @details 标准化自定义消息的 cell 标识与布局参数。
 * @ingroup QYCustomMsg
 */
@protocol QYCustomModelLayoutDataSource <NSObject>
@required
/**
 * @brief 对应的 cell 复用标识。
 * @details 必须实现
 * @return 复用标识字符串。
 */
- (NSString *)cellReuseIdentifier;
@optional
/**
 * @brief 内容视图大小。
 * @details
 * 1. 显示气泡时，`contentView` 位于气泡内部，气泡最大宽度为 `bubbleMaxWidth`。
 * 2. 不显示气泡，仅显示头像时，`contentView` 位于头像另一侧。
 * 3. 不显示头像与气泡时，`contentView` 为整个 cell，宽度固定为 table 宽度。
 * @param bubbleMaxWidth 气泡最大宽度。
 * @return 内容视图尺寸。
 */
- (CGSize)contentSizeForBubbleMaxWidth:(CGFloat)bubbleMaxWidth;
/**
 * @brief 是否显示头像。
 * @return YES 显示，NO 不显示。默认显示。
 */
- (BOOL)needShowAvatar;
/**
 * @brief 是否显示气泡。
 * @return YES 显示，NO 不显示。默认显示。
 */
- (BOOL)needShowBubble;
/**
 * @brief 内容视图距离气泡的内间距。
 * @return 边距，默认 `UIEdgeInsetsZero`。
 */
- (UIEdgeInsets)contentViewInsets;
/**
 * @brief 气泡与整个 cell 的内间距。
 * @return 边距，默认 `UIEdgeInsetsZero`。
 */
- (UIEdgeInsets)bubbleViewInsets;
/**
 * @brief 头像与气泡间距。
 * @return 间距，默认 5pt。
 */
- (CGFloat)avatarBubbleSpace;
@end

/**
 * @brief 自定义消息数据源基类。
 * @details 用于消息列表的刷新数据源，子类需继承QYCustomModel，并实现QYCustomModelLayoutDataSource协议。
 * @ingroup QYCustomMsg
 */
@interface QYCustomModel : NSObject <QYCustomModelLayoutDataSource>
/**
 * @brief 消息数据。
 */
@property (nonatomic, strong, readonly) QYCustomMessage *message;
@end
