//
//  QYKFNIMCustomizedAPIManagerProtocol.h
//  QYKFNIMSDK
//
//  Created by cqu227hk on 2022/12/08.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMGenericTypeAPIDefine.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  定制化api调用统一入口协议定义
 */
@protocol QYKFNIMCustomizedAPIManager <NSObject>

/**
 *  调用定制化api
 *
 *  @param param    api调用参数,包括 api name/param等信息 详见NIMGenericTypeAPICallParam定义
 *  @param completion  api扫行结果回调,包括error/result等信息 详见NIMNIMGenericTypeAPICallInvokeCallback定义
 */
- (void)invokeAPI:(QYKFNIMGenericTypeAPICallParam* __nonnull)param
             completion:(nullable QYKFNIMGenericTypeAPICallInvokeCallback)completion;

@end

NS_ASSUME_NONNULL_END
