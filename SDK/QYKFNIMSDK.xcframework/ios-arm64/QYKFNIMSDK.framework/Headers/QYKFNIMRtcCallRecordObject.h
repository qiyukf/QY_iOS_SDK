//
//  QYKFNIMRtcCallRecordObject.h
//  NIMLib
//
//  Created by Wenchao Ding on 2020/11/5.
//  Copyright © 2020 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMMessageObjectProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, QYKFNIMRtcCallType) {
    QYKFNIMRtcCallTypeAudio = 1,
    QYKFNIMRtcCallTypeVideo
};

typedef NS_ENUM(NSUInteger, QYKFNIMRtcCallStatus) {
    QYKFNIMRtcCallStatusComplete = 1,    // 通话完成
    QYKFNIMRtcCallStatusCanceled,        // 通话取消
    QYKFNIMRtcCallStatusRejected,        // 通话拒绝
    QYKFNIMRtcCallStatusTimeout,         // 超时未接听
    QYKFNIMRtcCallStatusBusy             // 对方忙线
};

@interface QYKFNIMRtcCallRecordObject : NSObject<QYKFNIMMessageObject>

/**
 通话类型，音频/视频
 */
@property (nonatomic, assign) QYKFNIMRtcCallType callType;

/**
 频道ID
 */
@property (nonatomic, copy) NSString *channelID;

/**
 通话状态
 */
@property (nonatomic, assign) QYKFNIMRtcCallStatus callStatus;

/**
 时长Map {"accid1": 10, "accid2": 20}
 */
@property (nonatomic, copy) NSDictionary<NSString *, NSNumber *> *durations;

@end

NS_ASSUME_NONNULL_END
