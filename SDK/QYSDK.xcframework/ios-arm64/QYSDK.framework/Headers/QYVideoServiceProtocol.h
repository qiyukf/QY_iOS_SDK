/**
 * @file QYVideoServiceProtocol.h
 * @brief 视频客服服务协议。
 * @details 定义视频客服模块的能力接口，包括版本、排队、访客分流、隐私协议与屏幕旋转处理等。
 *
 * @defgroup video 视频客服模块
 */

#import <Foundation/Foundation.h>
@class YSFBypassEntrance;

typedef void (^VideoByPassCallback)(BOOL done, YSFBypassEntrance *byPassDict);
typedef void (^RulesCallBack)(BOOL isAgree);

/**
 *  @brief 视频客服服务协议
 */
@protocol QYVideoServiceProtocol <NSObject>

@optional

/**
 *  @brief 获取视频客服 SDK 版本号
 */
- (int)getVideoVersion;

/**
 *  @brief 解析视频客服模块的命令并处理
 */
- (void)vs_parseAndDealWithContent:(NSString *)content;

/**
 *  @brief 上报视频客服是否支持
 */
- (void)vs_reportSupportVideo:(long long)sessionId;

/**
 *  @brief 呼出视频时唤起隐私协议
 */
- (void)vs_openProtocolWithDeviceId:(NSString *)deviceId callBack:(RulesCallBack)callBack;

/**
 *  @brief 屏幕旋转时 UI 处理
 */
- (void)vs_viewDidRotate;

/**
 *  @brief 唤起视频客服
 */
- (void)vs_excuteQYVideoServiceWithVideoConfig:(id)config;

/**
 *  @brief 更新客服信息
 */
- (void)vs_updateStaffInfo:(id)staffInfo;

/**
 *  @brief 更新访客信息
 */
- (void)vs_updateCustomInfo:(id)customInfo;

/**
 *  @brief 视频客服初始化配置
 */
- (void)vs_setVideoConfig:(id)videoConfig;

/**
 *  @brief 视频客服访客分流
 */
- (void)vs_didReceiveByPass:(NSArray *)entranceList title:(NSString *)title callBack:(VideoByPassCallback)callBack;

/**
 *  @brief 视频客服排队数据刷新
 */
- (void)vs_updateWaitingQueueNumber:(NSInteger)videoCallQueueNum;

/**
 *  @brief 结束视频通话
 */
- (void)vs_exitVideoWithSessionId:(long long)sessionId closeReason:(NSInteger)closeReason;

@end
