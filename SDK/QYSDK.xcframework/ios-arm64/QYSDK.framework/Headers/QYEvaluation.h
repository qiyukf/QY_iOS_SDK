/**
 * @file QYEvaluation.h
 * @brief 满意度评价数据模型与枚举。
 * @details 提供评价模式、选项与结果结构，支持人工与机器人评价。
 *
 * @defgroup evaluation 满意度评价模块
 */

#import <Foundation/Foundation.h>


/**
 * @brief 满意度评价模式。
 * @details 二级/三级/四级/五级评价模式。
 */
typedef NS_ENUM(NSUInteger, QYEvaluationMode) {
    QYEvaluationModeTwoLevel = 2,       //! 模式一（二级满意度）：满意/不满意
    QYEvaluationModeThreeLevel = 3,     //! 模式二（三级满意度）：满意/一般/不满意
    QYEvaluationModeFourLevel = 4,      //! 模式三（四级满意度）：非常满意/满意/不满意/非常不满意
    QYEvaluationModeFiveLevel = 5,      //! 模式四（五级满意度）：非常满意/满意/一般/不满意/非常不满意
};

/**
 * @brief 满意度选项数据。
 * @ingroup evaluation
 */
typedef NS_ENUM(NSUInteger, QYEvaluationOption) {
    QYEvaluationOptionVerySatisfied = 1,   //! 非常满意
    QYEvaluationOptionSatisfied,           //! 满意
    QYEvaluationOptionOrdinary,            //! 一般
    QYEvaluationOptionDissatisfied,        //! 不满意
    QYEvaluationOptionVeryDissatisfied,    //! 非常不满意
};

/**
 * @brief 满意度评价结果。
 * @ingroup evaluation
 */
typedef NS_ENUM(NSInteger, QYEvaluationState) {
    QYEvaluationStateSuccessFirst = 1,  //! 成功-首次评价
    QYEvaluationStateSuccessRevise,     //! 成功-修改评价
    QYEvaluationStateFailParamError,    //! 失败-发送参数错误
    QYEvaluationStateFailNetError,      //! 失败-网络错误
    QYEvaluationStateFailNetTimeout,    //! 失败-网络超时
    QYEvaluationStateFailTimeout,       //! 失败-评价超时
    QYEvaluationStateFailUnknown,       //! 失败-未知原因不可评价
};
/**
 * @brief 满意度评价是否解决选择项。
 * @ingroup evaluation
 */

typedef NS_ENUM(NSInteger, QYEvaluationResolveStatus) {
    QYEvaluationResolveStatusNone = 0,      //! 无
    QYEvaluationResolveStatusResolved = 1,  //! 已解决
    QYEvaluationResolveStatusUnsolved = 2,  //! 未解决
};

/**
 * @brief 满意度选项数据。
 * @ingroup evaluation
 */

@interface QYEvaluationOptionData : NSObject
@property (nonatomic, assign) QYEvaluationOption option;     //! 选项类型
@property (nonatomic, copy) NSString *name;                  //! 选项名称
@property (nonatomic, assign) NSInteger score;               //! 选项分值
@property (nonatomic, strong) NSArray <NSString *> *tagList; //! 标签列表
@property (nonatomic, assign) BOOL tagRequired;              //! 标签是否必填
@property (nonatomic, assign) BOOL remarkRequired;           //! 备注是否必填
@end
/**
 * @brief 满意度评价结果。
 * @ingroup evaluation
 */
@interface QYEvaluactionResult : NSObject
@property (nonatomic, assign) long long sessionId;                 //! 会话ID（不可为空）
@property (nonatomic, assign) long long  messageId;                //! 消息ID（来源于 QYEvaluactionData）
@property (nonatomic, assign) QYEvaluationMode mode;               //! 评价模式（机器人评价必须）
@property (nonatomic, strong) QYEvaluationOptionData *selectOption;//! 选中的选项（不可为空）
@property (nonatomic, strong) NSArray <NSString *> *selectTags;    //! 选中的标签，若selectOption的tagRequired必填，则selectTags不可为空
@property (nonatomic, copy) NSString *remarkString;                //! 备注，若selectOption的remarkRequired必填，则remarkString不可为空
@property (nonatomic, assign) QYEvaluationResolveStatus resolveStatus; //! 是否解决，若resolvedRequired必填，则resolveStatus不可为None
@end

/**
 *  @brief 满意度评价数据
 *  @ingroup evaluation
 */
@interface QYEvaluactionData : NSObject
@property (nonatomic, copy) NSString *urlString;               //! 评价页面 URL（后台配置）
@property (nonatomic, assign) long long sessionId;             //! 会话ID（提交结果透传）
@property (nonatomic, assign) QYEvaluationMode mode;           //! 评价模式
@property (nonatomic, strong) NSArray <QYEvaluationOptionData *> *optionList; //! 选项数据
@property (nonatomic, assign) BOOL resolvedEnabled;            //! 是否收集“您的问题是否解决”
@property (nonatomic, assign) BOOL resolvedRequired;           //! “是否解决”是否必填
@property (nonatomic, strong) QYEvaluactionResult *lastResult; //! 上次评价结果
@end

