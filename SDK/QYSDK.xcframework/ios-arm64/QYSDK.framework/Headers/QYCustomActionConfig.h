
/**
 * @file QYCustomActionConfig.h
 * @brief 自定义行为配置入口。
 * @details 提供了所有自定义行为的接口;每个接口对应一个自定义行为的处理，如果设置了，则使用设置的处理，如果不设置，则采用默认处理。
 * @defgroup QYUIConfig 界面与行为配置
 */

@class QYAction;
@class QYSelectedCommodityInfo;

/**
 * @brief 退出排队结果类型。
 * @ingroup QYUIConfig
 */
typedef NS_ENUM(NSInteger, QYQuitWaitingType) {
    QYQuitWaitingTypeNone,     //! 当前不是在排队状态
    QYQuitWaitingTypeContinue, //! 继续排队
    QYQuitWaitingTypeQuit,     //! 退出排队
    QYQuitWaitingTypeCancel,   //! 取消操作
};

typedef NS_ENUM(NSInteger, QYAvatarType) {
    QYAvatarTypeHumanStaff,     //! 人工客服
    QYAvatarTypeRobotStaff,     //! 机器人客服
    QYAvatarTypeCorp,           //! 企业
    QYAvatarTypeCustomer,       //! 访客
};

typedef NS_ENUM(NSInteger, QYLinkClickActionPolicy) {
    QYLinkClickActionPolicyCancel,    //! 不使用默认 WebView 打开链接
    QYLinkClickActionPolicyOpen,      //! 使用默认 WebView 打开链接
};

/**
 * @brief action 事件回调。
 * @param action 触发的动作。
 */
typedef void (^QYActionBlock)(QYAction *action);

/**
 * @brief 客服会话链接点击事件回调。
 * @param linkAddress 链接地址。
 * @return 链接处理策略。
 */
typedef QYLinkClickActionPolicy (^QYSessionLinkClickBlock)(NSString *linkAddress);

/**
 * @brief push 链接点击事件回调。
 * @param linkAddress 链接地址。
 */
typedef void (^QYLinkClickBlock)(NSString *linkAddress);

/**
 * @brief bot 点击事件回调。
 * @param target 目标。
 * @param params 参数。
 */
typedef void (^QYBotClickBlock)(NSString *target, NSString *params);

/**
 * @brief 退出排队回调。
 * @param quitType 退出类型。
 */
typedef void (^QYQuitWaitingBlock)(QYQuitWaitingType quitType);

/**
 * @brief 显示 bot 自定义信息回调。
 * @param array 自定义信息数组。
 */
typedef void (^QYShowBotCustomInfoBlock)(NSArray *array);

/**
 * @brief bot 商品卡片按钮点击事件回调。
 * @param commodityInfo 商品信息。
 */
typedef void (^QYSelectedCommodityActionBlock)(QYSelectedCommodityInfo *commodityInfo);

/**
 * @brief 扩展视图点击回调。
 * @param extInfo 附带信息。
 */
typedef void (^QYExtraViewClickBlock)(NSString *extInfo);

/**
 * @brief 系统消息点击回调。
 * @param message 消息对象。
 */
typedef void (^QYSystemNotificationClickBlock)(id message);

/**
 * @brief 消息内事件点击回调。
 * @param eventName 事件名称。
 * @param eventData 数据。
 * @param messageId 消息ID。
 */
typedef void (^QYEventBlock)(NSString *eventName, NSString *eventData, NSString *messageId);

/**
 * @brief 自定义事件按钮点击回调。
 * @param dict 按钮信息。
 */
typedef void (^QYCustomButtonBlock)(NSDictionary *dict);

/**
 * @brief 消息头像点击回调。
 * @param type 头像类型，具体类型参考QYAvatarType。
 * @param accountID 帐号ID。
 */
typedef void (^QYAvatarClickBlock)(QYAvatarType type, NSString *accountID);

/**
 * @brief 权限请求回调。
 */
typedef void (^QYPermissionBlock)(void);

/**
 * @brief 自定义行为配置类（单例）。
 * @ingroup QYUIConfig
 */
@interface QYCustomActionConfig : NSObject

+ (instancetype)sharedInstance;

/**
 * @brief action 事件。
 */
@property (nonatomic, copy) QYActionBlock actionBlock;

/**
 * @brief 所有消息中的链接回调处理。
 * @details 包含自定义商品消息、文本消息、机器人答案消息的链接。
 */
@property (nonatomic, copy) QYSessionLinkClickBlock linkClickBlock;

/**
 * @brief bot 相关点击。
 */
@property (nonatomic, copy) QYBotClickBlock botClick;

/**
 * @brief 推送消息相关点击。
 */
@property (nonatomic, copy) QYLinkClickBlock pushMessageClick;

/**
 * @brief 显示 bot 自定义信息。
 */
@property (nonatomic, copy) QYShowBotCustomInfoBlock showBotCustomInfoBlock;

/**
 * @brief bot 商品卡片按钮点击事件。
 */
@property (nonatomic, copy) QYSelectedCommodityActionBlock commodityActionBlock;

/**
 * @brief 扩展视图点击。
 */
@property (nonatomic, copy) QYExtraViewClickBlock extraClickBlock;

/**
 * @brief 系统消息点击。
 */
@property (nonatomic, copy) QYSystemNotificationClickBlock notificationClickBlock;

/**
 * @brief 消息内点击。
 */
@property (nonatomic, copy) QYEventBlock eventClickBlock;

/**
 * @brief 自定义事件按钮点击（快捷入口按钮及 + 扩展按钮）。
 */
@property (nonatomic, copy) QYCustomButtonBlock customButtonClickBlock;

/**
 * @brief 消息头像点击事件。
 * @details 若点击机器人客服头像，accountID=QIYU_ROBOT；若点击某些企业消息头像，accountID=-1
 */
@property (nonatomic, copy) QYAvatarClickBlock avatarClickBlock;


/**
 * @brief 相册权限请求回调。
 * @details 请求权限被拒绝后，再次请求权限时会回调，如果实现该回调，则UI和跳转效果完全由用户自己实现。默认使用七鱼的弹框效果，默认文案：请在iPhone的“设置-隐私-照片”选项中，允许访问你的相册。
 */
@property (nonatomic, copy) QYPermissionBlock photoPermissionBlock;

/**
 * @brief 相机权限请求回调。
 * @details 请求权限被拒绝后，再次请求权限时会回调，如果实现该回调，则UI和跳转效果完全由用户自己实现。默认使用七鱼的弹框效果，默认文案：请在iPhone的“设置-隐私-相机”选项中，允许访问你的相册。
 */
@property (nonatomic, copy) QYPermissionBlock cameraPermissionBlock;

/**
 * @brief 麦克风权限请求回调。
 * @details 请求权限被拒绝后，再次请求权限时会回调，如果实现该回调，则UI和跳转效果完全由用户自己实现。默认使用七鱼的弹框效果，默认文案：请在iPhone的“设置-隐私-麦克风”选项中，允许访问你的相册。
 */
@property (nonatomic, copy) QYPermissionBlock microPermissionBlock;


/**
 * @brief 帐号登录后是否拉取漫游消息。
 */
@property (nonatomic, assign) BOOL pullRoamMessage;
/**
 * @brief 拉取漫游消息条数。
 * @details 默认 20，最大 100。
 */
@property (nonatomic, assign) NSUInteger roamMessageLimit;


/**
 * @brief 设置录/播语音完成后是否自动 deactivate `AVAudioSession`。
 * @param deactivate 是否自动 deactivate，默认为 YES。
 */
- (void)setDeactivateAudioSessionAfterComplete:(BOOL)deactivate;

/**
 * @brief 显示退出排队提示。
 * @param quitWaitingBlock 选择结果回调。
 */
- (void)showQuitWaitingAlert:(QYQuitWaitingBlock)quitWaitingBlock;

@end



