//
//  QYKFNIMNotificationObject.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import "QYKFNIMMessageObjectProtocol.h"
#import "QYKFNIMTeamNotificationContent.h"
#import "QYKFNIMNetCallNotificationContent.h"
#import "QYKFNIMChatroomNotificationContent.h"
#import "QYKFNIMUnsupportedNotificationContent.h"
#import "QYKFNIMSuperTeamNotificationContent.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  通知对象
 */
@interface QYKFNIMNotificationObject : NSObject<QYKFNIMMessageObject>
/**
 *  通知内容
 */
@property (nonatomic,strong,readonly)    QYKFNIMNotificationContent  *content;

/**
 *  通知类型
 */
@property (nonatomic,assign,readonly) QYKFNIMNotificationType notificationType;

@end

NS_ASSUME_NONNULL_END
