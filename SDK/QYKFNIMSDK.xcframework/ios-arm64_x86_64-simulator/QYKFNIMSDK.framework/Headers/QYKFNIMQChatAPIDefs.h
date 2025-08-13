//
//  QYKFNIMQChatAPIDefs.h
//  QYKFNIMSDK
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#ifndef QYKFNIMQChatAPIDefs_h
#define QYKFNIMQChatAPIDefs_h

#import <Foundation/Foundation.h>


/**
 *  圈组网络请求回调
 *
 *  @param error 错误信息
 */
typedef void(^QYKFNIMQChatHandler)(NSError *__nullable error);


/**
 *  消息引用类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMQChatMessageReferType) {
    /**
     *  回复的
     *  @discussion
     */
    QYKFNIMQChatMessageReferTypeReply       =   1,
    
    /**
     *  Thread
     *  @discussion
     */
    QYKFNIMQChatMessageReferTypeThread      =   2,

    /**
     *  所有
     *  @discussion
     */
    QYKFNIMQChatMessageReferTypeAll         =   3,
};

#endif /* QYKFNIMQChatAPIDefs_h */
