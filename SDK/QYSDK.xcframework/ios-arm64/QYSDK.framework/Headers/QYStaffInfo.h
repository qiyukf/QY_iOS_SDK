/**
 * @file QYStaffInfo.h
 * @brief 人工客服信息。
 * @details 展示客服的昵称、头像、接入提示与信息描述。
 *
 * @defgroup session 会话页面模块
 */

#import <Foundation/Foundation.h>

/**
 * @brief 人工客服信息。
 * @ingroup session
 */
@interface QYStaffInfo : NSObject
@property (nonatomic, copy) NSString *staffId;  //! 客服 ID（<=20 字符）
@property (nonatomic, copy) NSString *nickName; //! 客服昵称（<=20 字符）
@property (nonatomic, copy) NSString *iconURL;  //! 客服头像 URL
@property (nonatomic, copy) NSString *accessTip; //! 接入提示（<=50 字符）
@property (nonatomic, copy) NSString *infoDesc; //! 客服信息描述
@end

