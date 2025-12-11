
/**
 * @file QYCustomEvent.h
 * @brief 自定义视图交互事件。
 * @details 在 `onCatchEvent:` 回调中通过事件名进行分发处理，事件可扩展。
 * @defgroup QYCustomMsg 自定义消息
 */

#import <Foundation/Foundation.h>

/**
 * @brief 可自行扩展事件名称。
 * @details 可在 `onCatchEvent:` 中通过eventName判断。
 */
extern NSString * const QYCustomEventTapAvatar;
/**
 * @brief 内置事件名：消息体长按。
 * @details 可在 `onCatchEvent:` 中通过事件名判断。
 */
extern NSString * const QYCustomEventLongPressCell;

@class QYCustomMessage;

/**
 * @brief 自定义消息事件载体。
 * @details 承载事件名、关联消息与扩展数据。
 * @ingroup QYCustomMsg
 */
@interface QYCustomEvent : NSObject
/**
 * @brief 事件名称。
 */
@property (nonatomic, copy) NSString *eventName;
/**
 * @brief 关联的消息体。
 */
@property (nonatomic, strong) QYCustomMessage *message;
/**
 * @brief 扩展数据。
 * @details 可传递任意需要的业务数据。
 */
@property (nonatomic, strong) id data;
@end
