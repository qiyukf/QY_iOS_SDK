/**
 * @file QYPushMessage.h
 * @brief 推送消息模型声明。
 * @details 定义推送消息类型与展示内容，监听到新消息时会回调。
 *
 * @defgroup push 推送模块
 */

typedef NS_ENUM(NSInteger, QYPushMessageType) {
    QYPushMessageTypeText,      //! 文本
    QYPushMessageTypeRichText,  //! 富文本
    QYPushMessageTypeImage,     //! 图片
};

/**
 * @brief 推送消息。
 * @ingroup push
 */
@interface QYPushMessage : NSObject

@property (nonatomic, assign) QYPushMessageType type;   //! 消息类型
@property (nonatomic, copy) NSString *headImageUrl;     //! 发送方头像 URL
@property (nonatomic, copy) NSString *actionText;       //! 按钮文本
@property (nonatomic, copy) NSString *actionUrl;        //! 按钮 URL
@property (nonatomic, copy) NSString *text;             //! 文本内容
@property (nonatomic, copy) NSString *richText;         //! 富文本内容
@property (nonatomic, copy) NSString *imageUrl;         //! 图片 URL
@property (nonatomic, assign) NSTimeInterval time;      //! 接收时间戳（秒）

@end



