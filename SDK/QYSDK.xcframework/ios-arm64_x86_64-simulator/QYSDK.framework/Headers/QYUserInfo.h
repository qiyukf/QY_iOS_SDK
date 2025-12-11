/**
 * @file QYUserInfo.h
 * @brief 用户信息模型声明。
 * @details 封装访客的唯一标识与详细资料，用于账户绑定与上报。
 *
 * @defgroup user 用户模型
 */

#import <Foundation/Foundation.h>

/**
 * @brief 用户信息模型。
 * @details 用于设置/上报用户身份与资料。
 * @ingroup user
 */
@interface QYUserInfo : NSObject

/**
 * @brief 个人帐号 ID。
 * @details 作为访客的唯一标识，用于与底层 IM 帐号映射。
 */
@property (nonatomic, copy) NSString *userId;

/**
 * @brief 用户详细信息 JSON 数据。
 * @details 字符串形式的 JSON；可包含昵称、头像、扩展字段等，具体键由业务约定。
 */
@property (nonatomic, copy) NSString *data;

@end
