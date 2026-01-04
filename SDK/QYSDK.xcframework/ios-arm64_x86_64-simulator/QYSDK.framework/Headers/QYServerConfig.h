/**
 * @file QYServerConfig.h
 * @brief 七鱼 SDK 全局环境配置。
 * @details 提供是否海外版的配置选项。
 *
 * @defgroup sdk SDK 主模块
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QYServerConfig : NSObject
/**
 * @brief 是否海外版，默认 NO。
 * @details 设为YES时，使用海外版配置。如果需要国内和海外AppKey的切换，使用海外版包+开启测配置；
 */
@property (nonatomic, assign) BOOL isMix;

/**
 * @brief 单例方法。
 * @return QYServerConfig单例。
 */
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
