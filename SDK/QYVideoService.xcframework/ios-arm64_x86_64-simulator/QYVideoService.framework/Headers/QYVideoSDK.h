//
//  QYVideoSDK.h
//  QYVideoService
//
//  Created by zhongzhida on 2022/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QYVideoSDK : NSObject

/**
 *  屏幕共享/视频客服 点击缩小按钮后的回调
 *  SDK内部仅隐藏屏幕共享界面，隐藏后触发此回调，涉及到界面跳转请在此回调中处理。
 *  主线程执行
 */
typedef void(^QYVideoZoomCompletionBlock)(void);

/**
 *  屏幕共享浮窗回调
 *  屏幕共享最小化后，点击浮窗时的回调
 *  SDK内部不处理点击后的界面跳转效果，push/present完全交给使用者自行决定
 *  主线程执行
 *  videoViewController:视频客服及屏幕共享控制器
 *  你可以在此回调中push/present对应的控制器，两个控制器不存在依赖关系
 *  如果仅需要重新打开屏幕共享界面，请push/present控制器videoViewController
 */
typedef void(^QYVideoZoomButtonClickBlock)(UIViewController *videoViewController);

//屏幕共享/视频客服 点击缩小按钮后的回调
@property (nonatomic, copy) QYVideoZoomCompletionBlock zoomBlock;
//屏幕共享浮窗回调
@property (nonatomic, copy) QYVideoZoomButtonClickBlock zoomClickBlock;

/**
 *  AppGroup设置
 *  必须和Broadcast App中设置一致，Host需要依赖AppGroup与Broadcast Extension进行通信
 *  AppGroup的相关设置可以参考文档：https://doc.yunxin.163.com/docs/jcyOTA0ODM/Tk2NDA0MTM?platformId=50192
 *  ⚠️⚠️⚠️注意：
 *  此处的appGroup、主工程扩展程序appGroup、主工程target勾选的appGroup三者需要保持统一
 */
@property (nonatomic, copy ,nonnull) NSString *appGroup;

+ (instancetype)sharedSDK;
@end

NS_ASSUME_NONNULL_END
