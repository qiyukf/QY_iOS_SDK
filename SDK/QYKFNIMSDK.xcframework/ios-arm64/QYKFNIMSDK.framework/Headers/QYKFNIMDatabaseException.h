//
//  QYKFNIMDatabaseException.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class QYKFNIMDatabaseException;

NS_ASSUME_NONNULL_BEGIN

/**
 *  数据库异常类型
 */
typedef NS_ENUM(NSInteger, QYKFNIMDatabaseExceptionType)
{
    /**
     *  损坏的DB
     *  @deprecated 请使用 QYKFNIMDatabaseExceptionTypeCorrupt
     */
    QYKFNIMDatabaseExceptionTypeBadDb = 1,

    /**
     *  未分类的通用错误
     */
    QYKFNIMDatabaseExceptionTypeGeneric = 0,

    /**
     *  数据库损坏
     */
    QYKFNIMDatabaseExceptionTypeCorrupt = 1,
    
    /**
     *  磁盘空间已满
     */
    QYKFNIMDatabaseExceptionTypeFull = 2,
};

/**
 *  数据库异常处理协议
 */
@protocol QYKFNIMDatabaseHandleExceptionProtocol <NSObject>

@optional

/**
 *  数据库异常处理方法
 */
- (void)handleException:(QYKFNIMDatabaseException *)exception;

@end

/**
 *  数据库异常信息
 */
@interface QYKFNIMDatabaseException : NSObject

/**
 * 异常
 */
@property (nonatomic,assign,readonly) QYKFNIMDatabaseExceptionType exception;

/**
 *  数据库异常信息
 */
@property (nullable,nonatomic,copy,readonly) NSString *message;

/**
 *  数据库文件沙盒路径
 */
@property (nullable,nonatomic,copy,readonly) NSString *databasePath;

/**
 *  注册数据库异常处理对象
 *  @param handler 用户自定义处理对象
 */
+ (void)registerExceptionHandler:(id<QYKFNIMDatabaseHandleExceptionProtocol>)handler;

@end

NS_ASSUME_NONNULL_END
