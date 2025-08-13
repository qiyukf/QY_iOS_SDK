//
//  QYKFNIMSubscribeOnlineInfo.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  订阅的在线事件额外信息
 */
@interface QYKFNIMSubscribeOnlineInfo : NSObject

/**
 *  事件发布者当前登录的所有客户端类型，为 QYKFNIMLoginClientType 数组
 */
@property (nonatomic, copy, readonly)  NSArray *senderClientTypes;

@end
