//
//  QYKFNIMGlobalDefs.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#ifndef NIMLib_NIMGlobalDefs_h
#define NIMLib_NIMGlobalDefs_h

#import <Foundation/Foundation.h>

/**
 *  消息内容类型枚举
 */
typedef NS_ENUM(NSInteger, QYKFNIMMessageType){
    /**
     *  文本类型消息
     */
        QYKFNIMMessageTypeText          = 0,
    /**
     *  图片类型消息
     */
        QYKFNIMMessageTypeImage         = 1,
    /**
     *  声音类型消息
     */
        QYKFNIMMessageTypeAudio         = 2,
    /**
     *  视频类型消息
     */
        QYKFNIMMessageTypeVideo         = 3,
    /**
     *  位置类型消息
     */
        QYKFNIMMessageTypeLocation      = 4,
    /**
     *  通知类型消息
     */
        QYKFNIMMessageTypeNotification  = 5,
    /**
     *  文件类型消息
     */
        QYKFNIMMessageTypeFile          = 6,
    /**
     *  提醒类型消息
     */
        QYKFNIMMessageTypeTip           = 10,
    /**
     *  机器人类型消息
     */
        QYKFNIMMessageTypeRobot         = 11,
    /**
     *  Rtc通话单
     */
        QYKFNIMMessageTypeRtcCallRecord = 12,
    /**
     *  自定义类型消息
     */
        QYKFNIMMessageTypeCustom        = 100
};

/**
 *  网络通话类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMNetCallType){
    /**
     *  音频通话
     */
    QYKFNIMNetCallTypeAudio = 1,
    /**
     *  视频通话
     */
    QYKFNIMNetCallTypeVideo = 2,
};

/**
 *  NIM本地Error Domain
 */
extern NSString *const QYKFNIMLocalErrorDomain;

/**
 *  NIM服务器Error Domain
 */
extern NSString *const QYKFNIMRemoteErrorDomain;



/**
 *  本地错误码 (IM 和通用) Domain QYKFNIMLocalErrorDomain
 */
typedef NS_ENUM(NSInteger, QYKFNIMLocalErrorCode) {
    /**
     *  错误的参数
     */
    QYKFNIMLocalErrorCodeInvalidParam                 = 1,
    /**
     *  多媒体文件异常
     */
    QYKFNIMLocalErrorCodeInvalidMedia                 = 2,
    /**
     *  图片异常
     */
    QYKFNIMLocalErrorCodeInvalidPicture               = 3,
    /**
     *  url异常
     */
    QYKFNIMLocalErrorCodeInvalidUrl                   = 4,
    /**
     *  读取/写入文件失败
     */
    QYKFNIMLocalErrorCodeIOError                      = 5,
    /**
     *  无效的token
     */
    QYKFNIMLocalErrorCodeInvalidToken                 = 6,
    /**
     *  Http请求失败
     */
    QYKFNIMLocalErrorCodeHttpReqeustFailed            = 7,
    /**
     *  无录音权限
     */
    QYKFNIMLocalErrorCodeAudioRecordErrorNoPermission = 8,
    /**
     *  录音初始化失败
     */
    QYKFNIMLocalErrorCodeAudioRecordErrorInitFailed   = 9,
    /**
     *  录音失败
     */
    QYKFNIMLocalErrorCodeAudioRecordErrorRecordFailed   = 10,
    /**
     *  播放初始化失败
     */
    QYKFNIMLocalErrorCodeAudioPlayErrorInitFailed     = 11,
    /**
     *  SQL语句执行失败
     */
    QYKFNIMLocalErrorCodeSQLFailed                    = 12,
    /**
     *  用户信息缺失 (未登录 或 未提供用户资料)
     */
    QYKFNIMLocalErrorCodeUserInfoNeeded               = 13,
    
    /**
     *  AppKey 缺失，未注册 AppKey 就进行登录行为之类的接口
     */
    QYKFNIMLocalErrorCodeAppKeyNeed                   = 14,
    
    /**
     *  自动登录超过次数限制，一般情况下都是当前网络有问题引起，如当前网络可以连接，但无法自由收发包等
     */
    
    QYKFNIMLocalErrorCodeAutoLoginRetryLimit          = 15,
    
    /**
     *  相同的操作正在执行，请不要多次调用
     */
    QYKFNIMLocalErrorCodeSameOperationInProgress      = 16,
    
    /**
     *  独立模式下获取聊天室服务器地址失败
     */
    QYKFNIMLocalErrorCodeRequestChatroomAddressesFailed= 17,
    
    /**
     *  群已读回执功能未开启，请使用 QYKFNIMSDKConfig 进行开启
     */
    QYKFNIMLocalErrorCodeTeamReceiptDisabled            = 18,
    
    /**
     *  主动取消任务
     */
    QYKFNIMLocalErrorCodeManualCancelTask = 19,
    /**
     *  资源过期
     */
    QYKFNIMLocalErrorCodeResourcesOverdue = 20,
    /**
     *  场景未注册
     */
    QYKFNIMLocalErrorCodeSceneUnregistered = 21,
    /**
     *  Database 读写异常
     */
    QYKFNIMLocalErrorCodeDatabaseError = 22,
    /**
     *  重复加入白板会议
     */
    QYKFNIMLocalErrorCodeJoinSameRTSConference = 23,
    
    /**
     *  功能不支持
     */
    QYKFNIMLocalErrorCodeNotSupported = 24,

    /**
     *  未知问题
     */
    QYKFNIMLocalErrorCodeUnknownError = 25,

    /**
     *  保存文件失败
     */
    QYKFNIMLocalErrorCodeSaveFileError = 26,
    /**
     *  接口调用过于频繁
     */
    QYKFNIMLocalErrorCodeFrequentCallError = 27,
    /**
     *   和设置冲突
     */
    QYKFNIMLocalErrorCodeSettingConflictError = 28,
};




/**
 *  服务器错误码 (IM 和通用) Doamin QYKFNIMRemoteErrorDomain
 *  @discussion 更多错误详见 [服务器端状态码](http://dev.netease.im/docs?doc=nim_status_code#服务器端状态码)
 *  用户第三方回调自定义错误码范围 20000-20099
 */
typedef NS_ENUM(NSInteger, QYKFNIMRemoteErrorCode) {
    /**
     *  客户端版本错误
     */
    QYKFNIMRemoteErrorCodeInvalidVersion      = 201,
    /**
     *  密码错误
     */
    QYKFNIMRemoteErrorCodeInvalidPass         = 302,
    /**
     *  CheckSum校验失败
     */
    QYKFNIMRemoteErrorCodeInvalidCRC          = 402,
    /**
     *  非法操作或没有权限
     */
    QYKFNIMRemoteErrorCodeForbidden           = 403,
    /**
     *  请求的目标（用户或对象）不存在
     */
    QYKFNIMRemoteErrorCodeNotExist            = 404,
    /**
     *  对象只读
     */
    QYKFNIMRemoteErrorCodeReadOnly            = 406,
    /**
     *  请求过程超时
     */
    QYKFNIMRemoteErrorCodeTimeoutError        = 408,
    /**
     *  参数错误
     */
    QYKFNIMRemoteErrorCodeParameterError      = 414,
    /**
     *  网络连接出现错误
     */
    QYKFNIMRemoteErrorCodeConnectionError     = 415,
    /**
     *  操作太过频繁
     */
    QYKFNIMRemoteErrorCodeFrequently          = 416,
    /**
     *  对象已经存在
     */
    QYKFNIMRemoteErrorCodeExist               = 417,
    /**
     *  数量超限
     */
    QYKFNIMRemoteErrorCodeBeyondLimit         = 419,
    /**
     *  账号被禁用
     */
    QYKFNIMRemoteErrorAccountBlock            = 422,
    /**
     *  未知错误
     */
    QYKFNIMRemoteErrorCodeUnknownError        = 500,
    /**
     *  服务器数据错误
     */
    QYKFNIMRemoteErrorCodeServerDataError     = 501,
    /**
     *  不足
     */
    QYKFNIMRemoteErrorCodeNotEnough           = 507,
    /**
     *  超过期限
     */
    QYKFNIMRemoteErrorCodeDomainExpireOld     = 508,
    /**
     *  无效协议
     */
    QYKFNIMRemoteErrorCodeInvalidProtocol     = 509,
    /**
     *  用户不存在
     */
    QYKFNIMRemoteErrorCodeUserNotExist        = 510,
    /**
     *  服务不可用
     */
    QYKFNIMRemoteErrorCodeServiceUnavailable  = 514,
    /**
     *  群人数超过上限
     */
    QYKFNIMRemoteErrorCodeTeamMemberLimit     = 801,
    /**
     *  没有操作群的权限
     */
    QYKFNIMRemoteErrorCodeTeamAccessError     = 802,
    /**
     *  群组不存在
     */
    QYKFNIMRemoteErrorCodeTeamNotExists       = 803,
    /**
     *  用户不在兴趣组内
     */
    QYKFNIMRemoteErrorCodeNotInTeam           = 804,
    /**
     *  群类型错误
     */
    QYKFNIMRemoteErrorCodeTeamInvaildType     = 805,
    /**
     *  超出群个数限制
     */
    QYKFNIMRemoteErrorCodeTeamCountLimit      = 806,
    /**
     *  已经在群里
     */
    QYKFNIMRemoteErrorCodeTeamAlreadyIn       = 809,
    /**
     *   不是群成员
     */
    QYKFNIMRemoteErrorCodeTeamNotMember       = 810,
    /**
     *  在群黑名单中
     */
    QYKFNIMRemoteErrorCodeTeamBlackList       = 812,
    /**
     *  请求群信息列表部分成功
     */
    QYKFNIMRemoteErrorCodeTeamsPartialSuccess = 816,
    /**
     *  解包错误
     */
    QYKFNIMRemoteErrorCodeEUnpacket           = 998,
    /**
     *  打包错误
     */
    QYKFNIMRemoteErrorCodeEPacket             = 999,
    
    /**
     *  在对方的黑名单中
     */
    QYKFNIMRemoteErrorCodeInBlackList         = 7101,
    
    /**
     *  聊天室状态异常
     */
    QYKFNIMRemoteErrorCodeInvalidChatroom     = 13002,
    /**
     *  账号在黑名单中,不允许进入聊天室
     */
    QYKFNIMRemoteErrorCodeInChatroomBlackList = 13003,
    /**
     *  在禁言列表中,不允许发言
     */
    QYKFNIMRemoteErrorCodeInChatroomMuteList  = 13004,
    /**
     *  聊天室处于整体禁言状态,只有管理员能发言
     */
    QYKFNIMRemoteErrorCodeInChatroomAllMute   = 13006,
    /**
     *  通用音视频协议：对方云信不在线
     */
    QYKFNIMRemoteErrorCodeSignalResPeerNIMOffline = 10201,
    /**
     *  通用音视频协议：对方推送亦不可达
     */
    QYKFNIMRemoteErrorCodeSignalResPeerPushOffline = 10202,
    /**
     *  通用音视频协议：房间不存在
     */
    QYKFNIMRemoteErrorCodeSignalResRoomNotExists = 10404,
    /**
     *  通用音视频协议：房间已存在
     */
    QYKFNIMRemoteErrorCodeSignalResRoomHasExists = 10405,
    /**
     *  通用音视频协议：不在房间内
     */
    QYKFNIMRemoteErrorCodeSignalResRoomMemberNotExists = 10406,
    /**
     *  通用音视频协议：已经在房间内
     */
    QYKFNIMRemoteErrorCodeSignalResRoomMemberHasExists = 10407,
    /**
     *  通用音视频协议：邀请不存在或已过期
     */
    QYKFNIMRemoteErrorCodeSignalResInviteNotExists = 10408,
    /**
     *  通用音视频协议：邀请已经拒绝
     */
    QYKFNIMRemoteErrorCodeSignalResInviteHasReject = 10409,
    /**
     *  通用音视频协议：邀请已经接受了
     */
    QYKFNIMRemoteErrorCodeSignalResInviteHasAccept = 10410,
    /**
     *  通用音视频协议：uid冲突
     */
    QYKFNIMRemoteErrorCodeSignalResUidConflict = 10417,
    /**
     *  通用音视频协议：房间人数超限
     */
    QYKFNIMRemoteErrorCodeSignalResRoomMemberExceed = 10419,
};

/**
 *  用户资料场景（头像等）
 */
extern NSString *const QYKFNIMNOSSceneTypeAvatar;

/**
 *  IM 消息 （图片，文件，音频，视频消息发送）
 */
extern NSString *const QYKFNIMNOSSceneTypeMessage;

/**
*  用户资料场景（下载权限）
*/
extern NSString *const QYKFNIMNOSSceneTypeSecurity;

#endif
