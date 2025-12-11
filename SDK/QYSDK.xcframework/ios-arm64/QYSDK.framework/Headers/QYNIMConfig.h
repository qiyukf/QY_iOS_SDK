
/**
 * @file QYNIMConfig.h
 * @brief NIM 相关配置。
 * @details 提供环境与地址配置，包括国外环境标识、LBS 地址与 Link 地址获取。
 * @defgroup QYNIMConfig NIM配置
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief NIM 配置入口。
 * @ingroup QYNIMConfig
 */
@interface QYNIMConfig : NSObject
/**
 * @brief 单例实例。
 * @return `QYNIMConfig` 单例。
 */
+ (instancetype)shareInstance;
/**
 * @brief 是否为国外环境。
 * @return YES 为国外环境，NO 为国内环境。
 */
- (BOOL)isForeign;
/**
 * @brief NIM LBS 地址。
 * @return LBS 服务地址。
 */
- (NSString *)nimLbsAddress;
/**
 * @brief NIM Link 地址。
 * @return Link 服务地址。
 */
- (NSString *)nimLinkAddress;
@end

NS_ASSUME_NONNULL_END
