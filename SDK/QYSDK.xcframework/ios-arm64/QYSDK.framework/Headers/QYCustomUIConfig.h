/**
 * @file QYCustomUIConfig.h
 * @brief 自定义 UI 配置入口。
 * @details 包含输入项、主题色、头像与气泡、消息布局、提示条、平台电商入口等配置。
 *
 * @ingroup QYUIConfig
 */

/**
 * @brief 工具栏自定义配置项。
 * @details 输入框下方“更多”配置项点击回调。
 */
typedef void (^QYCustomInputItemBlock)(void);

/**
 * @brief 输入框下方“更多”配置项。
 * @details 为达到最佳效果，配置项图片最佳尺寸为 64pt x 64pt。
 * @ingroup QYUIConfig
 */
@interface QYCustomInputItem : NSObject

@property (nonatomic, strong) UIImage *normalImage;
@property (nonatomic, strong) UIImage *selectedImage;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) QYCustomInputItemBlock block;

@end

/**
 *  @brief 访客分流展示模式
 */
typedef NS_ENUM(NSInteger, QYBypassDisplayMode) {
    QYBypassDisplayModeNone,    //! 无
    QYBypassDisplayModeCenter,  //! 中间
    QYBypassDisplayModeBottom   //! 底部
};

/**
 *  @brief 消息下拉加载状态
 */
typedef NS_ENUM(NSInteger, QYMessagesLoadState) {
    QYMessagesLoadStateIdle,      //! 默认
    QYMessagesLoadStateWillLoad,  //! 即将加载
    QYMessagesLoadStateLoading,   //! 加载中
};

/**
 *  @brief 工单附件后缀
 */
typedef NS_ENUM(NSInteger, QYAttachmentSuffixType) {
    QYAttachmentSuffixTypeJPG = 0,      //! 默认 JPG后缀
    QYAttachmentSuffixTypePNG,      //! PNG后缀
};
/**
 * @brief 自定义 UI 配置（单例）。
 * @details 若需替换图片素材，自行创建 `QYCustomResource.bundle` 并与 `QYResource.bundle` 同名素材即可覆盖。SDK会优先使用QYCustomResource.bundle中的图片素材，若QYCustomResource.bundle中没有，才会使用QYResource.bundle中的图片素材。
 * @ingroup QYUIConfig
 */
@interface QYCustomUIConfig : NSObject

+ (instancetype)sharedInstance;
/**
 * @brief 恢复默认设置。
 */
- (void)restoreToDefault;


//聊天背景设置

/**
 * @brief 消息tableview的背景图片。
 */
@property (nonatomic, strong) UIImageView *sessionBackground;


//主题色设置

/**
 * @brief 聊天页面主题色。
 * @details 包括访客气泡填充色、按钮填充色、默认头像填充色、“+”按钮填充色等；默认蓝色。设置主题色会修改部分属性，例如访客默认头像、访客消息气泡等，后续再次修改这些属性会覆盖主题色设置。
 */
@property (nonatomic, strong) UIColor *themeColor;

/**
 *  是否允许旋转
 *  默认YES
 */
@property (nonatomic, assign) BOOL allowAutoRotate;
//导航栏相关设置（人工/评价按钮可后台关闭显示）

/**
 * @brief 导航栏右侧按钮是否使用后台样式颜色，默认NO。
 */
@property (nonatomic, assign) BOOL rightItemStyleFllowSetting;

/**
 * @brief 导航栏右侧按钮风格，默认灰色风格，NO为白色风格。
 */
@property (nonatomic, assign) BOOL rightItemStyleGrayOrWhite;

/**
 * @brief 导航栏右侧退出会话按钮是否显示，默认为NO。
 */
@property (nonatomic, assign) BOOL showCloseSessionEntry;

/**
 * @brief 是否显示消息流头像,仅在后台样式开关关闭时生效。
 */
@property (nonatomic, assign) BOOL showHeadImage;

/**
 * @brief 是否显示导航栏客服头像。
 */
@property (nonatomic, assign) BOOL showTopHeadImage;

/**
 * @brief 是否显示客服阶段的昵称  默认NO 不展示
 */
@property (nonatomic, assign) BOOL showServiceNickName;

//访客相关设置

/**
 * @brief 访客头像
 */
@property (nonatomic, strong) UIImage *customerHeadImage;
@property (nonatomic, copy) NSString *customerHeadImageUrl;

/**
 * @brief 访客消息气泡normal图片
 */
@property (nonatomic, strong) UIImage *customerMessageBubbleNormalImage;

/**
 * @brief 访客消息气泡pressed图片
 */
@property (nonatomic, strong) UIImage *customerMessageBubblePressedImage;

/**
 * @brief 访客文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *customMessageTextColor;

/**
 * @brief 访客文本消息中的链接字体颜色
 */
@property (nonatomic, strong) UIColor *customMessageHyperLinkColor;

/**
 * @brief 访客文本消息字体大小
 */
@property (nonatomic, assign) CGFloat customMessageTextFontSize;


//客服相关设置

/**
 * @brief 客服头像
 * @details 若avatarUrlString为nil，则显示serviceHeadImage;若avatarUrlString不为nil，则将serviceHeadImage当做占位图，下载完成后显示头像url指定的图片
 */
@property (nonatomic, strong) UIImage *serviceHeadImage;
@property (nonatomic, copy) NSString *serviceHeadImageUrl;
/**
 * @brief 客服头像优先级
 * @brief YES 管理端配置优先   NO 代码配置优先
 * @brief 默认：NO
 */
@property (nonatomic, assign) BOOL isWebFirst;

/**
 * @brief 客服消息气泡normal图片
 */
@property (nonatomic, strong) UIImage *serviceMessageBubbleNormalImage;

/**
 * @brief 客服消息气泡pressed图片
 */
@property (nonatomic, strong) UIImage *serviceMessageBubblePressedImage;

/**
 * @brief 客服文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *serviceMessageTextColor;

/**
 * @brief 客服文本消息中的链接字体颜色
 */
@property (nonatomic, strong) UIColor *serviceMessageHyperLinkColor;

/**
 * @brief 客服文本消息字体大小
 */
@property (nonatomic, assign) CGFloat serviceMessageTextFontSize;


//提示消息相关设置（例：***为你服务）

/**
 * @brief 提示文本消息字体颜色；提示文本消息有很多种，比如“***为你服务”就是一种
 */
@property (nonatomic, strong) UIColor *tipMessageTextColor;

/**
 * @brief 提示文本消息字体大小；提示文本消息有很多种，比如“***为你服务”就是一种
 */
@property (nonatomic, assign) CGFloat tipMessageTextFontSize;


//消息相关设置

/**
 * @brief 访客分流展示模式。
 * @ingroup QYUIConfig
 */
@property (nonatomic, assign) QYBypassDisplayMode bypassDisplayMode;

/**
 * @brief 消息竖直方向间距。
 * @ingroup QYUIConfig
 */
@property (nonatomic, assign) CGFloat sessionMessageSpacing;

/**
 * @brief 头像与消息气泡间距，默认为4pt
 */
@property (nonatomic, assign) CGFloat headMessageSpacing;

/**
 * @brief 消息内强提示按钮文字颜色，例如"立即评价"按钮，默认白色
 */
@property (nonatomic, strong) UIColor *messageButtonTextColor;

/**
 * @brief 消息内强提示按钮底色，例如"立即评价"按钮，默认蓝色
 */
@property (nonatomic, strong) UIColor *messageButtonBackColor;

/**
 * @brief 富文本内容，默认行高倍数。通过此属性，可以控制行间距
 */
@property (nonatomic, assign) CGFloat lineHeightMultiple;
//输入栏上方操作按钮设置

/**
 * @brief 输入框上方操作按钮文字颜色。
 */
@property (nonatomic, strong) UIColor *actionButtonTextColor;

/**
 * @brief 输入框上方操作按钮边框颜色。
 */
@property (nonatomic, strong) UIColor *actionButtonBorderColor;


//输入栏设置

/**
 * @brief 输入框字体颜色。
 */
@property (nonatomic, strong) UIColor *inputTextColor;

/**
 * @brief 输入框字体大小。
 */
@property (nonatomic, assign) CGFloat inputTextFontSize;

/**
 * @brief 输入框占位文案。
 */
@property (nonatomic, copy) NSString *inputTextPlaceholder;

/**
 * @brief 输入栏语音按钮，人工模式下是否显示，默认为YES。
 */
@property (nonatomic, assign) BOOL showAudioEntry;

/**
 * @brief 输入栏语音按钮，机器人模式下是否显示，默认为YES。
 */
@property (nonatomic, assign) BOOL showAudioEntryInRobotMode;

/**
 * @brief 输入栏表情按钮是否显示，默认为YES。
 */
@property (nonatomic, assign) BOOL showEmoticonEntry;

/**
 * @brief 输入栏机器人阶段相机按钮是否显示，默认为NO。
 */
@property (nonatomic, assign) BOOL showRobotImageEntry;
/**
 * @brief 输入栏机器人阶段相机按钮展示样式
 * @details 0（默认）展示相机图标;1 展示“+”图标;此配置依赖showRobotImageEntry为YES时生效
 */
@property (nonatomic, assign) NSInteger robotImageStyle;
/**
 * @brief 输入栏人工阶段相机按钮是否显示，默认为YES
 */
@property (nonatomic, assign) BOOL showImageEntry;
/**
 * 照片/视频选择页面主题颜色，默认为蓝色
 */
@property (nonatomic, strong) UIColor *imagePickerColor;

/**
 * @brief 进入聊天界面是否自动弹出键盘，默认为YES
 */
@property (nonatomic, assign) BOOL autoShowKeyboard;

/**
 * @brief 表示聊天组件离界面底部的间距，默认是0；比较典型的是底部有tabbar，这时候设置为tabbar的高度即可
 */
@property (nonatomic, assign) CGFloat bottomMargin;


//平台电商相关设置

/**
 * @brief 导航栏右侧商铺入口按钮是否显示，默认为NO
 */
@property (nonatomic, assign) BOOL showShopEntrance;

/**
 * @brief 聊天内容区域的按钮（对于平台电商来说，这里可以考虑放置“会话列表入口“）显示，默认不显示
 */
@property (nonatomic, assign) BOOL showSessionListEntrance;

/**
 * @brief 会话列表入口icon
 */
@property (nonatomic, strong) UIImage *sessionListEntranceImage;

/**
 * @brief 聊天内容区域的按钮（对于平台电商来说，这里可以考虑放置“会话列表入口“）在聊天页面的位置，YES代表在右上角，NO代表在左上角，默认在右上角
 */
@property (nonatomic, assign) BOOL sessionListEntrancePosition;


//会话窗口上方提示条相关设置

/**
 * @brief 会话窗口上方提示条中的文本字体颜色
 */
@property (nonatomic, strong) UIColor *sessionTipTextColor;

/**
 * @brief 会话窗口上方提示条中的文本字体大小
 */
@property (nonatomic, assign) CGFloat sessionTipTextFontSize;

/**
 * @brief 会话窗口上方提示条中的背景颜色
 */
@property (nonatomic, strong) UIColor *sessionTipBackgroundColor;


/**
 * @brief 输入框下方“完全自定义”配置项
 */
@property (nonatomic, strong) NSArray<QYCustomInputItem *> *customInputItems;


/**
 * @brief url地址是否关闭encoding
 * @details 默认是NO，即url地址会进行encoding
 */
@property (nonatomic, assign) BOOL disableWebLinkEncoding;

/**
 * @brief 附件上传的图片后缀类型
 * @details 默认是jpg后缀，也可以修改为png
 */
@property (nonatomic, assign) QYAttachmentSuffixType suffixType;
/**
 * @brief 消息下拉刷新loading图片设置，区分不同state状态
 */
- (void)setMessagesLoadImages:(NSArray *)images duration:(NSTimeInterval)duration forState:(QYMessagesLoadState)state;

/**
 * @brief 注册自定义商品卡片消息的model与 contentView。
 * @details 若要使用自定义商品卡片功能，需在卡片消息渲染前设置映射关系。
 * @param modelClass `QYCustomCommodityInfo` 对应的数据模型类，`QYCustomModel` 子类。
 * @param contentViewClass `QYCustomCommodityInfo` 对应的视图类，`QYCustomContentView` 子类。
 */
- (void)registerCustomCommodityInfoModelClass:(Class)modelClass contentViewClass:(Class)contentViewClass;


//因访客端体验升级，以下属性在v5.1.0版本废弃
/**
 * @brief 导航栏右侧按钮文案颜色,默认是灰色,优先级高于rightItemStyleGrayOrWhite
 */
//@property (nonatomic, strong) UIColor *rightItemTextColor;

/**
 * @brief 人工按钮文案
 */
//@property (nonatomic, copy) NSString *humanButtonText;

/**
 * @brief 聊天窗口右上角按钮（对于平台电商来说，这里可以考虑放“商铺入口”）文本
 */
//@property (nonatomic, copy) NSString *shopEntranceText;

/**
 * @brief 聊天窗口右上角按钮（对于平台电商来说，这里可以考虑放“商铺入口”）icon
 */
//@property (nonatomic, strong) UIImage *shopEntranceImage;

@end



