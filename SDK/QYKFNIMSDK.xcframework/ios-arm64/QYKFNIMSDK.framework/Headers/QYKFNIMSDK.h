//
//  QYKFNIMSDK.h
//  QYKFNIMSDK
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

/**
 *  平台相关定义
 */
#import "QYKFNIMPlatform.h"

/**
 *  全局枚举和结构体定义
 */
#import "QYKFNIMGlobalDefs.h"

/**
 *  配置项
 */
#import "QYKFNIMSDKOption.h"
#import "QYKFNIMSDKConfig.h"

/**
 *  会话相关定义
 */
#import "QYKFNIMSession.h"
#import "QYKFNIMRecentSession.h"
#import "QYKFNIMMessageSearchOption.h"
#import "QYKFNIMIncompleteSessionInfo.h"
#import "QYKFNIMMessagesInSessionOption.h"


/**
 *  用户定义
 */
#import "QYKFNIMUser.h"
#import "QYKFNIMUserSearchOption.h"

/**
 *  群相关定义
 */
#import "QYKFNIMTeamDefs.h"
#import "QYKFNIMTeam.h"
#import "QYKFNIMTeamMember.h"
#import "QYKFNIMCreateTeamOption.h"
#import "QYKFNIMCreateTeamExOption.h"
#import "QYKFNIMTeamManagerDelegate.h"
#import "QYKFNIMTeamFetchMemberOption.h"
#import "QYKFNIMTeamSearchOption.h"
#import "QYKFNIMTeamMemberSearchOption.h"
#import "QYKFNIMTeamMemberSearchResult.h"

/**
 *  聊天室相关定义
 */
#import "QYKFNIMChatroom.h"
#import "QYKFNIMChatroomEnterRequest.h"
#import "QYKFNIMMessageChatroomExtension.h"
#import "QYKFNIMChatroomMember.h"
#import "QYKFNIMChatroomMemberRequest.h"
#import "QYKFNIMChatroomTagRequest.h"
#import "QYKFNIMChatroomUpdateRequest.h"
#import "QYKFNIMChatroomQueueRequest.h"
#import "QYKFNIMChatroomBeKickedResult.h"
#import "QYKFNIMChatroomCdnTrackInfo.h"
#import "QYKFNIMGetMessagesByTagsParam.h"
#import "QYKFNIMChatroomTagsUpdateEvent.h"

/**
 *  消息定义
 */
#import "QYKFNIMMessage.h"
#import "QYKFNIMAddEmptyRecentSessionBySessionOption.h"
#import "QYKFNIMSystemNotification.h"
#import "QYKFNIMRevokeMessageNotification.h"
#import "QYKFNIMDeleteMessagesOption.h"
#import "QYKFNIMDeleteMessageOption.h"
#import "QYKFNIMBroadcastMessage.h"
#import "QYKFNIMImportedRecentSession.h"
#import "QYKFNIMClearMessagesOption.h"
#import "QYKFNIMDeleteRecentSessionOption.h"
#import "QYKFNIMBatchDeleteMessagesOption.h"
#import "QYKFNIMRevokeMessageOption.h"
#import "QYKFNIMSessionDeleteAllRemoteMessagesOptions.h"
#import "QYKFNIMSessionDeleteAllRemoteMessagesInfo.h"
#import "QYKFNIMMessageRobotInfo.h"
#import "QYKFNIMMessageAIConfig.h"

/**
 *  推送定义
 */
#import "QYKFNIMPushNotificationSetting.h"

/**
 *  登录定义
 */
#import "QYKFNIMLoginClient.h"
#import "QYKFNIMLoginKickoutResult.h"

/**
 *  文档转码信息
 */
#import "QYKFNIMDocTranscodingInfo.h"

/**
 *  事件订阅
 */
#import "QYKFNIMSubscribeEvent.h"
#import "QYKFNIMSubscribeRequest.h"
#import "QYKFNIMSubscribeOnlineInfo.h"
#import "QYKFNIMSubscribeResult.h"

/**
 *  智能机器人
 */
#import "QYKFNIMRobot.h"

/**
 *  缓存管理
 */
#import "QYKFNIMCacheQuery.h"

/**
 *  通用音视频信令
 */
#import "QYKFNIMSignalingMemberInfo.h"
#import "QYKFNIMSignalingRequest.h"
#import "QYKFNIMSignalingResponse.h"


/**
 *  各个对外接口协议定义
 */
#import "QYKFNIMLoginManagerProtocol.h"
#import "QYKFNIMChatManagerProtocol.h"
#import "QYKFNIMConversationManagerProtocol.h"
#import "QYKFNIMMediaManagerProtocol.h"
#import "QYKFNIMUserManagerProtocol.h"
#import "QYKFNIMTeamManagerProtocol.h"
#import "QYKFNIMSuperTeamManagerProtocol.h"
#import "QYKFNIMSystemNotificationManagerProtocol.h"
#import "QYKFNIMApnsManagerProtocol.h"
#import "QYKFNIMResourceManagerProtocol.h"
#import "QYKFNIMChatroomManagerProtocol.h"
#import "QYKFNIMDocTranscodingManagerProtocol.h"
#import "QYKFNIMEventSubscribeManagerProtocol.h"
#import "QYKFNIMRobotManagerProtocol.h"
#import "QYKFNIMRedPacketManagerProtocol.h"
#import "QYKFNIMBroadcastManagerProtocol.h"
#import "QYKFNIMAntispamManagerProtocol.h"
#import "QYKFNIMSignalManagerProtocol.h"
#import "QYKFNIMPassThroughManagerProtocol.h"
#import "QYKFNIMChatExtendManagerProtocol.h"
#import "QYKFNIMIndexManagerProtocol.h"
#import "QYKFNIMQChatManagerProtocol.h"
#import "QYKFNIMQChatApnsManagerProtocol.h"
#import "QYKFNIMQChatServerManagerProtocol.h"
#import "QYKFNIMQChatChannelManagerProtocol.h"
#import "QYKFNIMQChatRoleManagerProtocol.h"
#import "QYKFNIMQChatMessageManagerProtocol.h"
#import "QYKFNIMQChatMessageExtendManagerProtocol.h"
#import "QYKFNIMQChatRTCChannelManagerProtocol.h"
#import "QYKFNIMCustomizedAPIManagerProtocol.h"
#import "QYKFNIMSystemStateProtocol.h"
#import "QYKFNIMAIManagerProtocol.h"

/**
 *  SDK业务类
 */
#import "QYKFNIMServerSetting.h"
#import "QYKFNIMSDKHeader.h"

/**
 * 数据库
 */
#import "QYKFNIMDatabaseException.h"

/**
 *  资源
 */
#import "QYKFNIMResourceExtraInfo.h"

/**
 *  透传代理定义
 */
#import "QYKFNIMPassThroughOption.h"


/**
 *  Thread Talk & 快捷回复
 */
#import "QYKFNIMThreadTalkFetchOption.h"
#import "QYKFNIMChatExtendBasicInfo.h"
#import "QYKFNIMQuickComment.h"
#import "QYKFNIMThreadTalkFetchResult.h"

/**
 * 收藏
 */
#import "QYKFNIMCollectInfo.h"
#import "QYKFNIMCollectQueryOptions.h"
#import "QYKFNIMAddCollectParams.h"

/**
 * 置顶会话
 */
#import "QYKFNIMStickTopSessionInfo.h"
#import "QYKFNIMAddStickTopSessionParams.h"
#import "QYKFNIMSyncStickTopSessionResponse.h"
#import "QYKFNIMLoadRecentSessionsOptions.h"

/**
 * PIN
 */
#import "QYKFNIMMessagePinItem.h"
#import "QYKFNIMSyncMessagePinRequest.h"
#import "QYKFNIMSyncMessagePinResponse.h"

/**
 * 圈组
 */
#import "QYKFNIMQChatConfig.h"
#import "QYKFNIMQChatOption.h"
#import "QYKFNIMQChatAPIDefs.h"

/**
* 日志
*/
# import "QYKFNIMLogDesensitizationConfig.h"

#import "QYKFNIMCustomSystemNotificationSetting.h"
#import "QYKFNIMUnsupportedNotificationContent.h"
#import "QYKFNIMCustomObject.h"
#import "QYKFNIMMessageApnsMemberOption.h"
#import "QYKFNIMChatroomNotificationContent.h"
#import "QYKFNIMSuperTeamNotificationContent.h"
#import "QYKFNIMNotificationContent.h"
#import "QYKFNIMTipObject.h"
#import "QYKFNIMLocationObject.h"
#import "QYKFNIMTeamMessageReceipt.h"
#import "QYKFNIMRobotObject.h"
#import "QYKFNIMEncryptionConfig.h"
#import "QYKFNIMRedPacketRequest.h"
#import "QYKFNIMAudioObject.h"
#import "QYKFNIMVideoObject.h"
#import "QYKFNIMAntiSpamOption.h"
#import "QYKFNIMImageObject.h"
#import "QYKFNIMTeamNotificationContent.h"
#import "QYKFNIMNetCallNotificationContent.h"
#import "QYKFNIMMessageReceipt.h"
#import "QYKFNIMTeamMessageReceiptDetail.h"
#import "QYKFNIMMessageObjectProtocol.h"
#import "QYKFNIMRtcCallRecordObject.h"
#import "QYKFNIMAsymEncryptionOption.h"
#import "QYKFNIMNotificationObject.h"
#import "QYKFNIMGenericTypeAPIDefine.h"
#import "QYKFNIMFileObject.h"
#import "QYKFNIMMessageSetting.h"
