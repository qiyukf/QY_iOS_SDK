//
//  QYKFNIMIndexManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2021 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class QYKFNIMMessage;
@class QYKFNIMSession;

NS_ASSUME_NONNULL_BEGIN

/**
 *  索引类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMIndexType) {
    /**
     *  消息文本
     */
    QYKFNIMIndexTypeMsgText = 0,

    /**
     *  自定义索引类型起始
     */
    QYKFNIMIndexTypeCustomBase = 100,
};

/**
 *  索引文本
 */
@interface QYKFNIMIndexText : NSObject

/**
 *  索引文本
 */
@property (nonatomic, copy)     NSString *text;

/**
 *  索引类型
 */
@property (nonatomic, assign)   NSInteger type;

@end

/**
 *  消息索引记录结构
 */
@interface QYKFNIMMsgIndexRecord : NSObject<NSCopying>

/**
 *  消息ID
 */
@property (nullable, nonatomic, copy) NSString * messageId;

/**
 *  索引文本
 */
@property (nullable, nonatomic, copy) NSString * indexText;

/**
 *  索引类型
 */
@property (nonatomic, assign) NSInteger indexType;

/**
 *  会话
 */
@property (nonatomic, copy) QYKFNIMSession * session;

/**
 *  时间
 */
@property (nonatomic, assign) NSTimeInterval timestamp;

/**
 *  消息
 */
@property (nullable, nonatomic) QYKFNIMMessage * message;

@end

typedef NS_ENUM(NSInteger, QYKFNIMMsgIndexTimeOrder) {
    /**
     *  消息时间从新往旧
     */
    QYKFNIMMsgIndexTimeOrderDesc = 0,
    
    /**
     *  消息时间从旧往新
     */
    QYKFNIMMsgIndexTimeOrderAsc = 1,
};

@interface QYKFNIMMsgIndexQueryOption : NSObject

/**
 *  起始时间,默认为0
 */
@property (nonatomic, assign)               NSTimeInterval startTime;

/**
 *  结束时间,默认为0
 *  @discussion 搜索的结束时间,0 表示最大时间戳
 */
@property (nonatomic, assign)               NSTimeInterval endTime;

/**
 *  检索顺序
 */
@property (nonatomic, assign)               QYKFNIMMsgIndexTimeOrder timeOrder;

/**
 *  检索条数
 */
@property (nonatomic, assign)               NSUInteger limit;

@end

/**
 *  在消息索引结果基础上查询消息 Block
 *
 *  @param error 错误信息,如果成功,error 为 nil
 */
typedef void(^QYKFNIMMsgIndexQueryMsgBlock)(NSError * __nullable error);

@interface QYKFNIMMsgIndexQueryResult : NSObject

/**
 *  不包含任何结果
 */
@property (nonatomic, readonly) BOOL empty;

/**
 *  排序的会话列表
 */
@property (nonatomic, nullable, readonly) NSArray<QYKFNIMSession *> * sessions;

/**
 *  分会话索引记录
 */
@property (nonatomic, nullable, readonly) NSDictionary<QYKFNIMSession *, NSArray<QYKFNIMMsgIndexRecord *> *> * records;

/**
 *  是否包含消息
 */
@property (nonatomic, readonly) BOOL withMesssage;

/**
 *  分会话索引记录
 *
 *  @param session    指定会话
 *  @discussion
 */
- (NSArray<QYKFNIMMessage *> *)messages:(nonnull QYKFNIMSession *)session;

/**
 *  查询结果中的消息数量
 *
 *  @param session    指定会话，不传表示所有
 *  @discussion
 */
- (NSUInteger)messageCount:(nullable QYKFNIMSession *)session;

/**
 *  查询消息
 *
 *  @param session    指定会话，不传表示所有
 *  @param completion 完成回调
 *  @discussion 消息结果记录在查询结果中
 */
- (void)queryMessage:(nullable QYKFNIMSession *)session
          completion:(nullable QYKFNIMMsgIndexQueryMsgBlock)completion;

@end

/**
 *  消息索引生成委托
 */
@protocol QYKFNIMMsgIndexProduceDelegate <NSObject>

@optional

- (nullable NSString *)produceText:(QYKFNIMMessage *)message;

- (nullable NSArray<QYKFNIMIndexText *> *)produceTexts:(QYKFNIMMessage *)message;

@end

/**
 *  同步消息索引 Block
 *
 *  @param error 错误信息,如果成功,error 为 nil
 */
typedef void(^QYKFNIMSyncMsgIndexBlock)(NSError * __nullable error);

/**
 *  查询消息索引 Block
 *
 *  @param error 错误信息,如果成功,error 为 nil
 */
typedef void(^QYKFNIMQueryMsgIndexBlock)(NSError * __nullable error, QYKFNIMMsgIndexQueryResult * __nullable result);

/**
 *  重置消息索引 Block
 *
 *  @param error 错误信息,如果成功,error 为 nil
 */
typedef void(^QYKFNIMResetMsgIndexBlock)(NSError * __nullable error);

/**
 *  索引委托
 */
@protocol QYKFNIMIndexManagerDelegate <NSObject>

@optional

@end

/**
 *  索引协议
 */
@protocol QYKFNIMIndexManager <NSObject>

/**
 *  同步消息索引
 *
 *  @param old    同步方向，YES往老方向，NO往新方向
 *  @param session    指定会话，不传表示所有
 *  @param completion 完成回调
 *  @discussion 老方向和新方向不代表消息产生时间，而是指存入本地的时间
 */
- (void)syncMsgIndex:(BOOL)old
             session:(nullable QYKFNIMSession *)session
          completion:(nullable QYKFNIMSyncMsgIndexBlock)completion;

/**
 *  查询消息索引
 *
 *  @param text    查询文本
 *  @param session    指定会话，不传表示所有
 *  @param option    查询选项
 *  @param withMesssage 是否查询消息
 *  @param completion 完成回调
 *  @discussion 老方向和新方向不代表消息产生时间，而是指存入本地的时间
 */
- (void)queryMsgIndex:(nonnull NSString *)text
              session:(nullable QYKFNIMSession *)session
               option:(nullable QYKFNIMMsgIndexQueryOption *)option
          withMessage:(BOOL)withMessage
           completion:(nullable QYKFNIMQueryMsgIndexBlock)completion;

/**
 *  重置消息索引
 *
 *  @param completion 完成回调
 */
- (void)resetMsgIndex:(nullable QYKFNIMResetMsgIndexBlock)completion;

/**
 *  添加索引委托
 *
 *  @param delegate 检索委托
 */
- (void)addDelegate:(id<QYKFNIMIndexManagerDelegate>)delegate;

/**
 *  移除索引委托
 *
 *  @param delegate 检索委托
 */
- (void)removeDelegate:(id<QYKFNIMIndexManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
