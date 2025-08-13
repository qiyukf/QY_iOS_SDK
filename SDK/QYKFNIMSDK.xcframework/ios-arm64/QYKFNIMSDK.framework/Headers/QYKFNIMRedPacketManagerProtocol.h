//
//  QYKFNIMRedPacketManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMRedPacketRequest.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  红包 Token 回调
 *
 *  @param error 错误信息,如果成功,error 为 nil
 *  @param token 红包服务 token 值
 */
typedef void(^QYKFNIMRedPacketTokenFetchBlock)(NSError * __nullable error, NSString * __nullable token);


/**
 *  红包管理类
 */
@protocol QYKFNIMRedPacketManager <NSObject>


/**
 *  获取红包服务 token 的回调
 *
 *  @param request    红包服务请求
 *  @param completion 获取红包 token 回调
 */
- (void)fetchTokenWithRedPacketRequest:(QYKFNIMRedPacketTokenRequest *)request
                            completion:(nullable QYKFNIMRedPacketTokenFetchBlock)completion;

@end


NS_ASSUME_NONNULL_END
