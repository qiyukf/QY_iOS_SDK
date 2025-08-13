//
//  QYKFNIMSubscribeEvent.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017 Netease. All rights reserved.
//

#import "QYKFNIMLoginClient.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  预定义事件列表
 */
typedef NS_ENUM(NSInteger,QYKFNIMSubscribeSystemEventType){
    /**
     *  在线状态事件
     */
    QYKFNIMSubscribeSystemEventTypeOnline = 1,
};


/**
 *  预定义在线事件值
 */
typedef NS_ENUM(NSInteger,QYKFNIMSubscribeEventOnlineValue){
    /**
     *  登录
     */
    QYKFNIMSubscribeEventOnlineValueLogin  = 1,
    /**
     *  登出
     */
    QYKFNIMSubscribeEventOnlineValueLogout = 2,
    /**
     *  断开连接
     */
    QYKFNIMSubscribeEventOnlineValueDisconnected = 3,
};



/**
 *  订阅事件
 */
@interface QYKFNIMSubscribeEvent : NSObject

/**
 *  事件 Id, 发布时无需填写
 */
@property (nonatomic, copy, readonly) NSString *eventId;


/**
 *  事件发布者，发布时无须填写
 */
@property (nullable, nonatomic, copy, readonly) NSString *from;


/**
 *  事件发布的时间，发布时无须填写
 */
@property (nonatomic, assign, readonly) NSTimeInterval timestamp;


/**
 *  事件类型，1～99999 为云信保留类型，目前只支持预定义事件, 见 QYKFNIMSubscribeSystemEventType
 */
@property (nonatomic, assign) NSInteger type;


/**
 *  事件的状态值,预定义事件值可以是内置 QYKFNIMSubscribeEventOnlineValue 枚举, 也可以是用户自定义
 */
@property (nonatomic, assign) NSInteger value;


/**
 *  事件的有效期，范围为 60 秒到 7 天， 数值单位为秒，默认为 7 天
 */
@property (nonatomic, assign) NSTimeInterval expiry;


/**
 *  事件是否只广播给在线用户
 *  @discussion 默认为YES 如果这个值为NO,事件会在订阅者登录后同步
 */
@property (nonatomic, assign)  BOOL sendToOnlineUsersOnly;


/**
 *  事件是否支持多端同步
 *  @discussion 默认为YES。
 */
@property (nonatomic, assign)  BOOL syncEnabled;


/**
 *  订阅事件的额外信息，当订阅事件为 QYKFNIMSubscribeSystemEventTypeOnline 时，为 QYKFNIMSubscribeOnlineInfo
 */
@property (nonatomic, strong, readonly)  id subscribeInfo;

/**
 *  预定义事件的扩展字段，发布时无须填写
 */
@property (nonatomic, copy, readonly) NSString *nimConfig;


/**
 *  事件扩展字段，最大长度为 4K, 写方法
 *
 *  @param ext 扩展字符串
 */
- (void)setExt:(NSString *)ext;


/**
 *  事件扩展字段，读取方法
 *
 *  @param type 客户端类型
 *
 *  @return 扩展字段
 */
- (nullable NSString *)ext:(QYKFNIMLoginClientType)type;


@end

NS_ASSUME_NONNULL_END
