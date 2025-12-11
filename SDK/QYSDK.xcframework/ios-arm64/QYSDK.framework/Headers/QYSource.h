/**
 * @file QYSource.h
 * @brief 会话来源信息。
 * @details 标记入口页面标题与链接，以及自定义信息。
 *
 * @defgroup session 会话页面模块
 */

#import <Foundation/Foundation.h>

/**
 * @brief 会话来源信息。
 * @ingroup session
 */
@interface QYSource : NSObject
@property (nonatomic, copy) NSString *title;     //! 来源标题（title可对应管理后台“App核心页面列表”中“页面名称”（）
@property (nonatomic, copy) NSString *urlString; //! 来源链接（urlString可对应管理后台“App核心页面列表”中“页面链接”，此处不做链接相关校验，可传任意字符串）
@property (nonatomic, copy) NSString *customInfo; //! 来源自定义信息
@end
