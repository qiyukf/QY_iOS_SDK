
/**
 * @file QYCustomMessageProtocol.h
 * @brief 自定义消息相关委托协议。
 * @details 包含消息增删改查过程的回调委托与自定义视图交互事件委托。
 * @defgroup QYCustomMsg 自定义消息
 */

@class QYCustomMessage;
@class QYCustomEvent;

/**
 * @brief 自定义消息事件委托协议。
 * @ingroup QYCustomMsg
 */
@protocol QYCustomMessageDelegate <NSObject>
@optional
/**
 * @brief 追加消息回调。
 * @details 消息已持久化（若需），尚未刷新界面。
 * @param message 新增的消息。
 */
- (void)onAddMessageBeforeReload:(QYCustomMessage *)message;
/**
 * @brief 插入消息回调。
 * @details 消息已持久化（若需），尚未刷新界面。
 * @param message 插入的消息。
 */
- (void)onInsertMessageBeforeReload:(QYCustomMessage *)message;
/**
 * @brief 更新消息回调。
 * @details 消息已持久化（若需），尚未刷新界面。
 * @param message 更新后的消息。
 */
- (void)onUpdateMessageBeforeReload:(QYCustomMessage *)message;
/**
 * @brief 删除消息回调。
 * @details 消息已持久化（若需），尚未刷新界面。
 * @param message 被删除的消息。
 */
- (void)onDeleteMessageBeforeReload:(QYCustomMessage *)message;
@end

/**
 * @brief 自定义视图点击事件委托协议。
 * @details 视图事件可通过 `onCatchEvent:` 抛出以便消息与视图更新。
 * @ingroup QYCustomMsg
 */
@protocol QYCustomContentViewDelegate <NSObject>
@optional
/**
 * @brief 自定义事件。
 * @details 通过QYCustomContentView的delegate去调用onCatchEvent:事件，若事件涉及到更新消息及视图则尽量使用onCatchEvent:抛出，若未涉及消息及视图更新，可直接响应事件，无需使用该方法抛出。
 * @param event 事件载体。
 */
- (void)onCatchEvent:(QYCustomEvent *)event;
/**
 * @brief 头像点击事件。
 * @param event 事件载体。
 */
- (void)onTapAvatar:(QYCustomEvent *)event;
/**
 * @brief 消息体长按事件。
 * @param event 事件载体。
 */
- (void)onLongPressCell:(QYCustomEvent *)event;
@end
