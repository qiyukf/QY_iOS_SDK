
/**
 * @file QYCustomMessage.h
 * @brief 自定义消息基类与序列化协议。
 * @details 通过实现 `QYCustomMessageCoding` 来完成消息缩略、序列化与解码，以及消息来源类型描述。
 * @defgroup QYCustomMsg 自定义消息
 */
#import <Foundation/Foundation.h>

/**
 * @brief 消息来源类型。
 * @details 默认 `QYCustomMessageSourceTypeNone`。
 * @ingroup QYCustomMsg
 */
typedef NS_ENUM(NSInteger, QYCustomMessageSourceType) {
    QYCustomMessageSourceTypeNone = 0,  //! 无，不显示头像
    QYCustomMessageSourceTypeSend,      //! 发送方，显示访客头像
    QYCustomMessageSourceTypeReceive,   //! 接收方，显示客服头像
};


/**
 * @brief QYCustomMessage 序列化协议。
 * @details 定义消息的缩略文本、序列化与解码接口，以及来源类型。
 * @ingroup QYCustomMsg
 */
@protocol QYCustomMessageCoding <NSObject>
@optional
/**
 * @brief 缩略消息。
 * @details 用于会话列表展示的简短文本。
 * @return 缩略文本字符串。
 */
- (NSString *)thumbText;
/**
 * @brief 消息数据序列化。
 * @details 用于数据库存储。
 * @return 序列化字典。
 */
- (NSDictionary *)encodeMessage;
/**
 * @brief 消息数据解码。
 * @param content 业务内容字典。
 */
- (void)decodeMessage:(NSDictionary *)content;
/**
 * @brief 消息来源类型。
 * @return 来源枚举值。
 */
- (QYCustomMessageSourceType)messageSourceType;
@end


/**
 * @brief 自定义消息基类。
 * @details 自定义消息需继承该类并实现 `QYCustomMessageCoding` 协议。
 * @ingroup QYCustomMsg
 */
@interface QYCustomMessage : NSObject <QYCustomMessageCoding>
/**
 * @brief 消息唯一 ID。
 */
@property (nonatomic, copy, readonly) NSString *messageId;
@end
