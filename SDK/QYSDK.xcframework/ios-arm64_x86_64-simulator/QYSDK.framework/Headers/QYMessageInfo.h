

/**
 * @file QYMessageInfo.h
 * @brief 消息模型与相关接口的声明文件。
 * @details 为开发者提供收到的消息类型枚举与消息模型的属性说明，便于上层进行展示与处理。
 *
 * @defgroup message 消息相关模块
 */
#import <Foundation/Foundation.h>

/**
 *  消息类型
 */
/**
 * @brief 消息类型枚举。
 * @details 表示消息的类型。
 * @see QYMessageInfo
 */
typedef NS_ENUM(NSInteger, QYMessageType) {
    QYMessageTypeText,      //! 文本消息；
    QYMessageTypeImage,     //! 图片消息；
    QYMessageTypeAudio,     //! 语音消息；
    QYMessageTypeVideo,     //! 视频消息；
    QYMessageTypeFile,      //! 文件消息；
    QYMessageTypeCustom     //! 自定义消息；用于扩展场景（客户端/业务自定义）
};

/**
 * @brief 消息对象模型。
 * @details 封装一条消息的基础信息（文本、类型、时间戳），用于列表展示与业务处理。
 * @ingroup message
 */
@interface QYMessageInfo : NSObject

/**
 * @brief 消息文本内容。
 * @details 根据type值返回不同的内容：
 * - QYMessageTypeText，消息文本内容；
 * - QYMessageTypeImage，[图片]；
 * - QYMessageTypeAudio，[语音]；
 * - QYMessageTypeVideo，[视频]；
 * - QYMessageTypeFile，[文件]；
 * - QYMessageTypeCustom，根据自定内容返回文案
 */
@property (nonatomic, copy) NSString *text;

/**
 * @brief 消息类型。
 * @details 表示消息的类别；详见 QYMessageType。
 * @see QYMessageType
 */
@property (nonatomic, assign) QYMessageType type;

/**
 * @brief 消息时间戳。
 * @details 消息发送的时间。
 */
@property (nonatomic, assign) NSTimeInterval timeStamp;

@end
