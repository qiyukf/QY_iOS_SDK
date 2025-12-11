/**
 * @file QYSDKOption.h
 * @brief 七鱼 SDK 注册选项。
 * @details 封装 SDK 注册所需的关键参数（AppKey、App 名称、推送配置、模板ID 等）。
 *
 * @defgroup config 配置模块
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief SDK 注册选项。
 * @details 通过该模型集中配置 SDK 初始化所需的选项。
 * @ingroup config
 */
@interface QYSDKOption : NSObject

/**
 * @brief AppKey。
 * @details 对应七鱼管理后台分配的 AppKey。
 */
@property (nonatomic, copy) NSString *appKey;

/**
 * @brief App 名称。
 * @details 七鱼管理后台添加 App 时填写的名称；对应云信的 Apns 推送证书名 `apnsCername`。
 */
@property (nonnull, nonatomic, copy) NSString *appName;

/**
 * @brief PushKit 推送证书名。
 * @details 对应云信的 `pkCername`。
 */
@property (nullable, nonatomic, copy) NSString *pkCerName;

/**
 * @brief APNS 推送是否显示具体消息内容，默认 YES。
 * @details 设为 NO 时显示“你收到一条新消息”，并根据系统语言自动翻译。
 */
@property (nonatomic, assign) BOOL showAPNSDetail;

/**
 * @brief 后台模板 ID。
 * @details 优先级：
 * - 后台样式开关打开：代码指定的后台模板 ID > 后台设置的 App > 后台默认模板 > SDK 代码设置 > 默认；
 * - 后台样式开关关闭：仅 SDK 代码设置 > 默认。
 */
@property (nonatomic, assign) long templateId;

/**
 * @brief 构造注册选项。
 * @param[in] appKey 企业 AppKey。
 * @return `QYSDKOption` 实例。
 */
+ (instancetype)optionWithAppKey:(NSString *)appKey;

@end

NS_ASSUME_NONNULL_END
