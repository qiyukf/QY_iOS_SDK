/**
 * @file QYAction.h
 * @brief 自定义动作与回调定义。
 * @details 统一声明请求客服前/后与会话分配等动作及对应回调。
 *
 * @defgroup action 自定义动作模块
 */

#import <Foundation/Foundation.h>

/**
 * @brief 动作类型。
 */
typedef NS_ENUM(NSInteger, QYActionType) {
    QYActionTypeNone = 0,                 //! 无
    QYActionTypeRequestStaffBefore,       //! 请求客服前
    QYActionTypeRequestStaffAfter,        //! 请求客服后
    QYActionTypeSessionAllocation         //! 会话分配
};

/**
 * @brief 通用回调，指示是否继续后续操作。
 * @details 例如：设置了请求客服前回调后，通过调用此QYCallback来继续或是中断请求客服
 * @param[in] continueIfNeeded YES 继续；NO 中断。
 */
typedef void (^QYCallback)(BOOL continueIfNeeded);


// QYActionTypeRequestStaffBefore 定义
/**
 * @brief 请求客服场景。
 */
typedef NS_ENUM(NSInteger, QYRequestStaffBeforeScene) {
    QYRequestStaffBeforeSceneNone,               //无需关心的请求客服场景
    QYRequestStaffBeforeSceneInit,               //进入会话页面，初次请求客服
    QYRequestStaffBeforeSceneRobotUnable,        //机器人模式下告知无法解答，点击消息中人工客服按钮请求
    QYRequestStaffBeforeSceneNavHumanButton,     //机器人模式下，点击右上角人工按钮
    QYRequestStaffBeforeSceneActiveRequest,      //主动请求人工客服
    QYRequestStaffBeforeSceneChangeStaff,        //切换人工客服
    QYRequestStaffBeforeSceneReconnect,          //重新连接客服
    QYRequestStaffBeforeSceneRobotTransfer,      //机器人会话中转接至另一个机器人
    QYRequestStaffBeforeSceneCompanyTransfer,    //平台板主企业转接给子企业
};

/**
 * @brief 请求客服前回调。
 * @param[in] scene 请求客服场景。
 * @param[in] onlyHuman 是否仅请求人工客服。
 * @param[in] callback 处理完成回调；继续请求则 `callback(YES)`；停止请求则 `callback(NO)`。
 */
typedef void (^QYRequestStaffBeforeBlock)(QYRequestStaffBeforeScene scene, BOOL onlyHuman, QYCallback callback);

// QYActionTypeRequestStaffAfter 定义
/**
 * @brief 请求客服后回调。
 * @param[in] info 会话相关信息。
 * @param[in] error 错误信息。
 */
typedef void (^QYRequestStaffAfterBlock)(NSDictionary *info, NSError *error);


/**
 * @brief 动作定义。
 * @details QYAction定义了部分动作，通过type区分不同情形，并调用各自对应的回调,若需要获取这部分动作，请在QYCustomActionConfig单例中设置QYAction属性
 * @ingroup action
 */
@interface QYAction : NSObject
@property (nonatomic, assign) QYActionType type;                         //! 动作类型
@property (nonatomic, copy) QYRequestStaffBeforeBlock requestStaffBeforeBlock; //! 请求客服前回调
@property (nonatomic, copy) QYRequestStaffAfterBlock requestStaffAfterBlock;   //! 请求客服后回调
@end

