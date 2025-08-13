//
//  QYSessionViewController.h
//  QYSDK
//
//  Created by Netease on 12/21/15.
//  Copyright (c) 2017 Netease. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "QYEvaluation.h"

@class QYSource;
@class QYStaffInfo;
@class QYCommodityInfo;
@class QYSelectedCommodityInfo;
@class QYMessageCardModel;


/**
 *  QYSessionViewDelegate：右上角入口以及聊天内容区域按钮点击回调
 */
@protocol QYSessionViewDelegate <NSObject>

/**
 *  点击右上角按钮回调（对于平台电商来说，这里可以考虑放“商铺入口”）
 */
- (void)onTapShopEntrance;

/**
 *  点击聊天内容区域的按钮回调（对于平台电商来说，这里可以考虑放置“会话列表入口“）
 */
- (void)onTapSessionListEntrance;

@end


/**
 *  输入区域上方工具栏内按钮信息类：QYButtonInfo
 *  注: actionType及index为button点击事件传递信息，仅可读
 *  actionType为1表示发送文本消息title，2表示openURL或是自定义行为；index表示该button位置
 */
@interface QYButtonInfo : NSObject

@property (nonatomic, strong) id buttonId;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) id userData;
@property (nonatomic, assign, readonly) NSUInteger actionType;
@property (nonatomic, assign, readonly) NSUInteger index;

@end


/**
 *  通用完成回调
 */
typedef void (^QYCompletion)(BOOL success, NSError *error);

/**
 *  工具栏内按钮点击回调定义
 */
typedef void (^QYButtonClickBlock)(QYButtonInfo *action);

/**
 *  拍摄视频完成回调
 *  @param filePath 视频存储路径
 */
typedef void (^QYVideoCompletion)(NSString *filePath);

/**
 *  选择文件完成回调
 *  @param filePath 文件存储路径
 */
typedef void (^QYFileCompletion)(NSString *fileName, NSString *filePath);


/**
 *  会话类：QYSessionViewController
 *  客服会话ViewController,必须嵌入到UINavigationcontroller中
 */
@interface QYSessionViewController : UIViewController

/**
 *  会话窗口标题
 */
@property (nonatomic, copy) NSString *sessionTitle;

/**
 *  访客分流 分组Id
 */
@property (nonatomic, assign) int64_t groupId;

/**
 *  访客分流 客服Id
 */
@property (nonatomic, assign) int64_t staffId;

/**
 *  机器人Id
 */
@property (nonatomic, assign) int64_t robotId;

/**
 *  vip等级
 */
@property (nonatomic, assign) NSInteger vipLevel;

/**
 *  访客分流 是否开启机器人
 *  @discussion 仅设置staffId/groupId时生效
 */
@property (nonatomic, assign) BOOL openRobotInShuntMode;

/**
 *  常见问题 模板Id
 */
@property (nonatomic, assign) int64_t commonQuestionTemplateId;

/**
 *  机器人欢迎语 模板Id
 */
@property (nonatomic, assign) int64_t robotWelcomeTemplateId;
/**
 *  常见快捷入口 模板Id
 */
@property (nonatomic, assign) long long shortcutTemplateId;

/**
 *  多入口分流 模板Id
 */
@property (nonatomic, assign) int64_t shuntTemplateId;

/**
 *  会话窗口来源
 */
@property (nonatomic, strong) QYSource *source;

/**
 *  商品信息展示
 */
@property (nonatomic, strong) QYCommodityInfo *commodityInfo;

/**
 *  商品消息是否支持长按复制urlString信息，默认为YES
 */
@property (nonatomic, assign) BOOL canCopyCommodityInfo;

/**
 *  卡片消息展示
 */
@property (nonatomic, strong) QYMessageCardModel *cardInfo;

/**
 *  人工客服信息
 */
@property (nonatomic, strong) QYStaffInfo *staffInfo;

/**
 *  输入区域上方工具栏内的按钮信息
 */
@property (nonatomic, copy) NSArray<QYButtonInfo *> *buttonInfoArray;

/**
 *  输入区域上方工具栏内的按钮点击回调
 */
@property (nonatomic, copy) QYButtonClickBlock buttonClickBlock;

/**
 *  机器人自动发送商品信息功能
 */
@property (nonatomic, assign) BOOL autoSendInRobot;

/**
 *  消息流留言自动发送商品信息功能
 */
@property (nonatomic, assign) BOOL autoSendInLeave;


/**
 *  每页消息加载的最大数量，默认为20条
 */
@property (nonatomic, assign) NSInteger messagePageLimit;

/**
 *  是否收起历史消息，默认为NO；若设置为YES，进入会话界面时若需创建新会话，则收起历史消息
 */
@property (nonatomic, assign) BOOL hideHistoryMessages;

/**
 *  历史消息提示文案，默认为“——以上为历史消息——”；仅在hideHistoryMessages为YES，首次下拉历史消息时展示
 */
@property (nonatomic, copy) NSString *historyMessagesTip;
/**
 *  是否发起视频客服
 */
@property (nonatomic, assign) BOOL isVideoServer;
/**
 *  是否支持屏幕共享
 *  如果需要使用屏幕共享功能，需要同时开启isVideoServer和isScreenShare
 */
@property (nonatomic, assign) BOOL isScreenShare;

/**
 *  客服成功连接之前，是否禁用输入框
 *  默认 NO，YES则开启，开启后进入客服页面，连接客服之前输入框将无法使用，键盘也无法弹起
 */
@property (nonatomic, assign) BOOL isForbiddenInput;
/*** 以下为商品详情页进入或订单详情页进入携带的参数,进线时会上报服务端*/
//用于会话与商品或订单的关联

//1.商品类型

/**
 * 商品类目 ID，长度限制 100 字符
 */
@property (nonatomic, copy) NSString *goodsCId;
/**
 * 商品类目名称
 */
@property (nonatomic, copy) NSString *goodsCName;
/**
 * 商品 Id，长度限制为 100 字符，商品唯一标识符。
 */
@property (nonatomic, copy) NSString *goodsId;

//2.订单类型

/**
 * 订单 ID
 */
@property (nonatomic, copy) NSString *orderId;

/**
 * 订单阶段类型
 * 售前阶段：10000
 * 发货前阶段：20000
 * 发货后阶段：30000
 * 售后阶段：40000
 */

@property (nonatomic, copy) NSString *orderStageType;

/** 以下为客服相关接口 **/

/**
 *  请求人工客服
 */
- (void)requestHumanStaff;

/**
 *  切换人工客服，客服ID、客服分组ID二者选择一种即可
 *
 *  @param staffId 客服ID
 *  @param groupId 客服分组ID
 *  @param closetip 切换提示语
 *  @param closeCompletion 退出旧会话完成的回调
 *  @param requestCompletion 请求新会话完成的回调
 */
- (void)changeHumanStaffWithStaffId:(int64_t)staffId
                            groupId:(int64_t)groupId
                           closetip:(NSString *)closetip
                    closeCompletion:(QYCompletion)closeCompletion
                  requestCompletion:(QYCompletion)requestCompletion;


/** 以下为发送相关接口 **/

/**
 *  发送文本消息
 */
- (void)sendText:(NSString *)text;

/**
 *  发送图片消息
 */
- (void)sendPicture:(UIImage *)picture;

/**
 *  发送视频消息
 */
- (void)sendVideo:(NSString *)filePath;

/**
 *  发送文件消息
 */
- (void)sendFileName:(NSString *)fileName filePath:(NSString *)filePath;

/**
 *  发送商品信息展示
 */
- (void)sendCommodityInfo:(QYCommodityInfo *)commodityInfo;

/**
 *  发送订单列表中选中的商品信息
 */
- (void)sendSelectedCommodityInfo:(QYSelectedCommodityInfo *)commodityInfo;

/**
 *  发送卡片消息
 */
- (void)sendCardInfo:(QYMessageCardModel *)cardInfo;

/** 以下为开放能力接口 **/

/**
 *  退出会话/退出排队
 *  @param popViewController 是否退出聊天界面，设置为YES，无论退出是否成功均退出聊天界面
 *  @param completion 退出完成回调
 */
- (void)closeSession:(BOOL)popViewController completion:(QYCompletion)completion;

/**
 *  拍摄视频
 *  自动发送
 */
- (void)shootVideoWithCompletion:(QYVideoCompletion)completion;

/**
 *  选择系统文件，调用系统控件UIDocumentPickerViewController，注意文件功能目前仅支持iOS11以上系统
 *  @param allowedUTIs 需增加支持的文件类型，已有部分默认类型，传nil时采用默认类型组；具体可参照UIDocumentPickerViewController的allowedUTIs参数
 *  @param completion 选择完成回调
 */
- (void)selectFileWithDocumentTypes:(NSArray <NSString *>*)allowedUTIs completion:(QYFileCompletion)completion;

/**
 *  弹出工单页面自助提工单
 *  @param templateID 工单模板ID
 */
- (void)presentWorkOrderViewControllerWithTemplateID:(long long)templateID;


/** 以下为自定义视图相关接口 **/

/**
 *  注册聊天界面顶部悬停视图
 *
 *  @param hoverView 顶部悬停视图
 *  @param height 视图高度
 *  @param insets 视图边距，默认UIEdgeInsetsZero；top表示视图与导航栏底部距离，bottom设置无效，left/right分别表示距离屏幕左右边距
 */
- (void)registerTopHoverView:(UIView *)hoverView height:(CGFloat)height marginInsets:(UIEdgeInsets)insets;

/**
 *  销毁聊天界面顶部悬停视图
 */
- (void)destroyTopHoverViewWithAnmation:(BOOL)animated duration:(NSTimeInterval)duration;


/** 以下为满意度评价相关接口 **/

/**
 *  满意度评价事件回调
 *
 *  @param data 评价数据，包括评价模式、选项及标签、上次评价结果等数据，据此构建评价界面
 */
typedef void (^QYEvaluationBlock)(QYEvaluactionData *data);

/**
 *  评价结果回调
 *
 *  @param state 结果
 */
typedef void (^QYEvaluationCompletion)(QYEvaluationState state);

/**
 *  会话前强制人工满意度评价事件，自定义视图写在此回调中（web端可配置关闭，默认关闭）
 */
@property (nonatomic, copy) QYEvaluationBlock preSessionEvaluationBlock;
/**
 *  人工满意度评价事件
 */
@property (nonatomic, copy) QYEvaluationBlock evaluationBlock;

/**
 *  机器人满意度评价事件
 */
@property (nonatomic, copy) QYEvaluationBlock robotEvaluationBlock;

/**
 *  发送人工满意度评价结果
 */
- (void)sendEvaluationResult:(QYEvaluactionResult *)result completion:(QYEvaluationCompletion)completion;
/**
 *  上报再次邀评功能，用户评价的结果 YES 成功评价  NO 放弃评价
 *  需要配合preSessionEvaluationBlock使用，会话中的评价弹框不需要调用此方法
 *  开启了再次邀评，不调用此方法会导致无法正常进线
 */
- (void)reportEvaluationResult:(BOOL)result data:(QYEvaluactionData *)data;
/**
 *  发送机器人满意度评价结果
 */
- (void)sendRobotEvaluationResult:(QYEvaluactionResult *)result completion:(QYEvaluationCompletion)completion;
/**
 *  导航栏左侧点击返回时，是否需要弹出满意度评价
 *
 *  人工会话功能：
 *  isOpenAlert:是否弹出弹框（确认退出对话？）
 *  isOpenEvaluation:点击结束会话时，是否需要弹出满意度评价
 *  注意：想要弹出评价的弹框，必须同时开启上述两个开关。
 *  机器人会话功能：
 *  会话强制邀评
 *  该方法需要在关闭页面的事件中调用，并且将popViewControllerAnimated放在complete中；
 */
- (void)showEvaluationAlert:(BOOL)isOpenAlert openEvaluation:(BOOL)isOpenEvaluation complete:(QYCompletion)complete;

@end


