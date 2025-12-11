
/**
 * @file QYCustomSessionViewController.h
 * @brief 会话控制器自定义消息分类。
 * @details 扩展自定义消息的注册、委托设置、消息的增删改查以及数据库/数据源的查询接口。
 * @defgroup QYCustomMsg 自定义消息
 */

#import "QYSessionViewController.h"

@protocol QYCustomMessageDelegate;
@protocol QYCustomContentViewDelegate;
/**
 * @brief 自定义消息错误码。
 * @details 表征自定义消息流程中发生的各类错误。
 * @ingroup QYCustomMsg
 */
typedef NS_ENUM(NSInteger, QYCustomMessageErrorCode) {
    QYCustomMessageErrorCodeUnknown         = 0,    //! 未知错误
    QYCustomMessageErrorCodeInvalidParam    = 1,    //! 错误参数
    QYCustomMessageErrorCodeInvalidMessage  = 2,    //! 无效消息体
    QYCustomMessageErrorCodeSQLFailed       = 3,    //! SQL 语句执行失败
};


/**
 * @brief 消息持久化结果回调。
 * @param error 错误信息，成功为 nil。
 */
typedef void(^QYCustomMessageCompletion)(NSError *error);


/**
 * @brief 会话控制器的自定义消息分类。
 * @details 扩展自定义消息相关接口的注册与操作。
 * @ingroup QYCustomMsg
 */
@interface QYSessionViewController (CustomMessage)
/**
 * @brief 注册message-model-contentView的映射关系。
 * @details 若要使用自定义消息，必须调用此方法设置消息类、模型类与视图类的对应关系。
 * @param messageClass 消息类。
 * @param modelClass 消息对应的数据模型类。
 * @param contentViewClass 消息对应的视图类。
 */
- (void)registerCustomMessageClass:(Class)messageClass
                        modelClass:(Class)modelClass
                  contentViewClass:(Class)contentViewClass;
/**
 * @brief 设置消息事件委托对象。
 * @param delegate 被委托对象。
 */
- (void)addCustomMessageDelegate:(id<QYCustomMessageDelegate>)delegate;
/**
 * @brief 设置消息视图委托对象。
 * @param delegate 被委托对象。
 */
- (void)addCustomContentViewDelegate:(id<QYCustomContentViewDelegate>)delegate;
/**
 * @brief 清除消息事件委托对象。
 * @param delegate 被清除的委托对象。
 */
- (void)removeCustomMessageDelegate:(id<QYCustomMessageDelegate>)delegate;
/**
 * @brief 清除消息视图委托对象。
 * @param delegate 被清除的委托对象。
 */
- (void)removeCustomContentViewDelegate:(id<QYCustomContentViewDelegate>)delegate;
/**
 * @brief 从尾部追加消息。
 * @param message 消息对象。
 * @param save 是否需要持久化消息数据。
 * @param reload 是否需要刷新界面。
 * @param completion 消息持久化结果回调。
 */
- (void)addCustomMessage:(QYCustomMessage *)message
            needSaveData:(BOOL)save
          needReloadView:(BOOL)reload
              completion:(QYCustomMessageCompletion)completion;
/**
 * @brief 从头部插入消息。
 * @details 插入消息不支持持久化。
 * @param message 消息对象。
 */
- (void)insertCustomMessage:(QYCustomMessage *)message;
/**
 * @brief 从中间插入消息。
 * @details 插入消息不支持持久化。
 * @param message 消息对象。
 * @param index 插入位置。
 */
- (void)insertCustomMessage:(QYCustomMessage *)message index:(NSInteger)index;
/**
 * @brief 刷新消息。
 * @param message 消息对象。
 * @param save 是否需要持久化消息数据。
 * @param reload 是否需要刷新界面。
 * @param completion 消息持久化结果回调。
 */
- (void)updateCustomMessage:(QYCustomMessage *)message
               needSaveData:(BOOL)save
             needReloadView:(BOOL)reload
                 completion:(QYCustomMessageCompletion)completion;
/**
 * @brief 删除消息。
 * @param message 消息对象。
 * @param save 删除记录是否同步至数据库。
 * @param reload 是否需要刷新界面。
 */
- (void)deleteCustomMessage:(QYCustomMessage *)message
               needSaveData:(BOOL)save
             needReloadView:(BOOL)reload;
/**
 * @brief 从数据库中取出消息。
 * @param messageId 消息唯一 ID。
 * @return 取出的消息体。
 */
- (QYCustomMessage *)fetchCustomMessageFromDatabaseForMessageId:(NSString *)messageId;
/**
 * @brief 从当前 table 的 dataSource 中取出消息。
 * @param messageId 消息唯一 ID。
 * @return 取出的消息体。
 */
- (QYCustomMessage *)fetchCustomMessageFromDataSourceForMessageId:(NSString *)messageId;
@end

