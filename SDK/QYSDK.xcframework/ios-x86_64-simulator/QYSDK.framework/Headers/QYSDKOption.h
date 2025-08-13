//
//  QYSDKOption.h
//  QYBiz
//
//  Created by Netease on 2020/2/17.
//  Copyright © 2020 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 注册选项
 */
@interface QYSDKOption : NSObject

/**
 * AppKey
 */
@property (nonatomic, copy) NSString *appKey;

/**
 * App名称，即七鱼管理后台添加App时填写的App名称；对应云信的Apns推送证书名apnsCername
 */
@property (nonnull, nonatomic, copy) NSString *appName;

/**
 * PushKit推送证书名；对应云信的pkCername
 */
@property (nullable, nonatomic, copy) NSString *pkCerName;

/**
 * APNS推送消息是否显示具体的消息内容，默认YES
 * @discussion 设置成NO，显示成“你收到一条新消息”，并根据系统语言语种自动翻译
 *
 */
@property (nonatomic, assign) BOOL showAPNSDetail;

/**
 * 是否为融合SDK，默认NO；需同时使用QYKFNIMSDK和QYSDK的客户应配置为YES
 */
@property (nonatomic, assign) BOOL isFusion;

/**
 * 后台模板id
 * 优先级：
 * 后台样式开关打开后，代码指定后台模板id > 后台设置app > 后台默认模板 > SDK代码设置 > 默认
 * 后台样式开关关闭，仅  SDK代码设置 > 默认
 */
@property (nonatomic, assign) long templateId;

/**
 *  注册选项初始化方法
 *  @param appKey  企业AppKey
 */
+ (instancetype)optionWithAppKey:(NSString *)appKey;

@end

NS_ASSUME_NONNULL_END
