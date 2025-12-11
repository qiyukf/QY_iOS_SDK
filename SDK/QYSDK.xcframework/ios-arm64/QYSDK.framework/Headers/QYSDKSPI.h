/**
 * @file QYSDKSPI.h
 * @brief SDK Service Provider Interface 聚合。
 * @details 聚合视频服务协议以扩展客服能力。
 *
 * @defgroup spi SPI 扩展模块
 */

#import <Foundation/Foundation.h>
#import "QYVideoServiceProtocol.h"


/**
 * @brief SDK SPI 协议。
 * @ingroup spi
 */
@protocol QYSDKSPI <QYVideoServiceProtocol>
@end

