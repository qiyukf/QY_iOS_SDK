//
//  QYKFNIMPushNotificationSetting.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  推送消息显示类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMPushNotificationDisplayType){
    /**
     *  显示详情
     */
    QYKFNIMPushNotificationDisplayTypeDetail = 1,
    /**
     *  不显示详情
     */
    QYKFNIMPushNotificationDisplayTypeNoDetail = 2,
};

/**
 *  推送消息等级配置类型
 *  @discussion 低等级消息：普通消息等（没有具体目标、没有@意愿）。中等级消息：@所有人等（没有具体目标、有@意愿）。高等级消息： @某些人等（有具体目标、有@意愿）
 */
typedef NS_ENUM(NSInteger, QYKFNIMPushNotificationProfile){
    /**
     *  未指定
     */
    QYKFNIMPushNotificationProfileNotSet = 0,

    /**
     *  全部消息都收
     */
    QYKFNIMPushNotificationProfileEnableAll = 1,

    /**
     *  只收高、中等级消息
     */
    QYKFNIMPushNotificationProfileOnlyHighAndMediumLevel = 2,

    /**
     *  只收高等级消息
     */
    QYKFNIMPushNotificationProfileOnlyHighLevel = 3,

    /**
     *  全部消息都不收
     */
    QYKFNIMPushNotificationProfileDisableAll = 4,

    /**
     *  使用平台默认配置
     */
    QYKFNIMPushNotificationProfilePlatformDefault = 5,
};

/**
 *  消息推送免打扰参数设置
 */
@interface QYKFNIMPushNotificationSetting : NSObject<NSCopying>
/**
 *  推送消息显示类型
 */
@property (nonatomic,assign)    QYKFNIMPushNotificationDisplayType     type;

/**
 *  推送消息是否开启免打扰 YES表示开启免打扰
 */
@property (nonatomic,assign)    BOOL    noDisturbing;

/**
 *  免打扰开始时间:小时
 */
@property (nonatomic,assign) NSUInteger noDisturbingStartH;

/**
 *  免打扰开始时间:分
 */
@property (nonatomic,assign) NSUInteger noDisturbingStartM;

/**
 *  免打扰结束时间:小时
 */
@property (nonatomic,assign) NSUInteger noDisturbingEndH;

/**
 *  免打扰结束时间:分
 */
@property (nonatomic,assign) NSUInteger noDisturbingEndM;

/**
 *  推送消息等级配置（当前仅在圈组中设置有效）
 */
@property (nonatomic,assign)    QYKFNIMPushNotificationProfile  profile;

@end


/**
 *  自定义消息多端推送策略配置项
 */
@interface QYKFNIMPushNotificationMultiportConfig : NSObject

/**
 *  桌面端在线时是否需要发送推送给手机端
 *  @discussion 默认为 YES，即需要推送,桌面端包括 PC，web , macOS 等...
 */
@property (nonatomic,assign)    BOOL    shouldPushNotificationWhenPCOnline;

@end


NS_ASSUME_NONNULL_END
