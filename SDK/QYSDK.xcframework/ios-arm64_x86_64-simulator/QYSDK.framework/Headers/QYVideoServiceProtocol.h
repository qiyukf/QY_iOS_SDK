//
//  QYVideoServiceProtocol.h
//  QYSDK
//
//  Created by Netease on 2022/8/15.
//

#import <Foundation/Foundation.h>
@class YSFBypassEntrance;

typedef void (^VideoByPassCallback)(BOOL done, YSFBypassEntrance *byPassDict);
typedef void (^RulesCallBack)(BOOL isAgree);
@protocol QYVideoServiceProtocol <NSObject>

@optional
//获取视频客服SDK版本号
- (int)getVideoVersion;
//解析视频客服模块的命令并处理
- (void)vs_parseAndDealWithContent:(NSString *)content;
//上报服务端是否支持视频客服
- (void)vs_reportSupportVideo:(long long)sessionId;
//呼出视频时唤起隐私协议
- (void)vs_openProtocolWithDeviceId:(NSString *)deviceId callBack:(RulesCallBack)callBack;
//屏幕旋转时UI处理
- (void)vs_viewDidRotate;
//唤起视频客服
- (void)vs_excuteQYVideoServiceWithVideoConfig:(id)config;
//更新客服信息
- (void)vs_updateStaffInfo:(id)staffInfo;
//更新访客信息
- (void)vs_updateCustomInfo:(id)customInfo;
//视频客服初始化配置
- (void)vs_setVideoConfig:(id)videoConfig;
//视频客服访客分流
- (void)vs_didReceiveByPass:(NSArray *)entranceList title:(NSString *)title callBack:(VideoByPassCallback)callBack;
//视频客服排队数据刷新
- (void)vs_updateWaitingQueueNumber:(NSInteger)videoCallQueueNum;
//结束视频通话
- (void)vs_exitVideoWithSessionId:(long long)sessionId closeReason:(NSInteger)closeReason;
@end
