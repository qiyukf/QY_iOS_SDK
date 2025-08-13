//
//  QYKFNIMRobotManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
@class QYKFNIMRobot;

NS_ASSUME_NONNULL_BEGIN

/**
 *  机器人获取 block
 *
 *  @param error   错误,如果成功则error为nil
 *  @param robots  成功的机器人列表,内部为 QYKFNIMRobot
 */
typedef void(^QYKFNIMRobotsHandler)(NSError * __nullable error, NSArray<QYKFNIMRobot *> * __nullable robots);

/**
 *  机器人管理器
 */
@protocol QYKFNIMRobotManager <NSObject>

/**
 *  获取所有的机器人
 *  @return 所有机器人信息
 */
- (nullable NSArray<QYKFNIMRobot *> *)allRobots;

/**
 *  是否是有效的机器人
 *
 *  @param userId 用户Id (机器人在云信的id)
 *  @return 是否是机器人
 */
- (BOOL)isValidRobot:(NSString *)userId;


/**
 *  获取机器人信息
 *  @param userId 用户Id (机器人在云信的id)
 *  @return 机器人信息
 */
- (nullable QYKFNIMRobot *)robotInfo:(NSString *)userId;



/**
 *  远程获取机器人信息
 *  @param completion 机器人获取回调
 */
- (void)fetchAllRobotsFromServer:(nullable QYKFNIMRobotsHandler)completion;


@end

NS_ASSUME_NONNULL_END
