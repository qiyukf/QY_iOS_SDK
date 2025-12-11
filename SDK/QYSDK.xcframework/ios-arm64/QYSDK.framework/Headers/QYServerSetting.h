/**
 * @file QYServerSetting.h
 * @brief 七鱼 SDK 服务器配置。
 * @details 提供服务域名与轨迹上报地址的自定义能力，支持环境读取。
 *
 * @defgroup config 配置模块
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @brief 环境枚举。
 * @details 表示当前运行环境；用于区分线上/测试等环境配置。
 */
typedef NS_ENUM(NSUInteger, YSFServerEnvironment) {
    YSFServerEnvironmentOnline = 0, //! 线上环境
    YSFServerEnvironmentTest,       //! 测试环境
    YSFServerEnvironmentPre,        //! 预发布环境
    YSFServerEnvironmentDev,        //! 开发环境
};

/**
 * @brief 服务器配置模型。
 * @details 可自定义七鱼服务与轨迹上报地址；在 SDK 注册前设置生效。
 * @ingroup config
 */
@interface QYServerSetting : NSObject

/**
 * @brief 七鱼服务器地址。
 * @details 设置为 `nil` 或空串时恢复默认配置。
 */
@property (nonatomic, copy) NSString *serverAddress;

/**
 * @brief 轨迹上报服务器地址。
 * @details 设置为 `nil` 或空串时恢复默认配置。
 */
@property (nonatomic, copy) NSString *trackAddress;

/**
 * @brief 当前服务器环境（只读）。
 */
@property (nonatomic, assign, readonly) YSFServerEnvironment serverEnvironment;

@end

NS_ASSUME_NONNULL_END
