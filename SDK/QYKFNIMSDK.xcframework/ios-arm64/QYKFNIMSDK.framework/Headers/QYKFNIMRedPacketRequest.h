//
//  QYKFNIMRedPacketRequest.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  红包服务类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMRedPacketServiceType)
{
    /**
     *  金融魔方红包
     */
    QYKFNIMRedPacketServiceTypeJRMF = 1,
};


/**
 *  红包Token请求
 */
@interface QYKFNIMRedPacketTokenRequest : NSObject

/**
 *  红包服务类型
 */
@property (nonatomic, assign) QYKFNIMRedPacketServiceType type;


@end

NS_ASSUME_NONNULL_END
