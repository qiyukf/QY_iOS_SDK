//
//  QYKFNIMPassThroughManagerProtocol.h
//  NIMLib
//
//  Created by Netease on 2019/12/19.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class QYKFNIMPassThroughHttpData;
@class QYKFNIMPassThroughMsgData;

NS_ASSUME_NONNULL_BEGIN

/**
 *  透传HTTP请求完成的回调block
 *  @param response     透传请求的响应,如果错误则为nil
 *  @param error        错误,如果成功则为nil
 */
typedef void(^QYKFNIMPassThroughCompletedBlock)(QYKFNIMPassThroughHttpData* __nullable response, NSError * __nullable error);

/**
 *  透传服务管理回调
 */
@protocol QYKFNIMPassThroughManagerDelegate <NSObject>

@optional

/**
*  收到透传消息
*
*  @param recvData   收到的透传消息数据
*/
- (void)didReceivedPassThroughMsg:(QYKFNIMPassThroughMsgData* __nullable)recvData;

@end

/**
 *  PassThrough接口
 */
@protocol QYKFNIMPassThroughManager  <NSObject>

/**
 *   透传HTTP请求到应用服务
 *
 *  @param reqData      透传的Http数据
 *  @param completion   经验操作完成后的回调
 *  @discussion         操作成功后，云信服务器会下发禁言的群通知消息
 */
- (void)passThroughHttpReq:(QYKFNIMPassThroughHttpData *)reqData
                completion:(nullable QYKFNIMPassThroughCompletedBlock)completion;


/**
 *  添加透传管理的委托
 *
 *  @param delegate 透传管理委托
 */
- (void)addDelegate:(id<QYKFNIMPassThroughManagerDelegate>)delegate;

/**
 *  移除透传管理的委托
 *
 *  @param delegate 透传管理委托
 */
- (void)removeDelegate:(id<QYKFNIMPassThroughManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
