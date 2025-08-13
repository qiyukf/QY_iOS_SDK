//
//  QYKFNIMUserSearchOption.h
//  QYKFNIMSDK
//
//  Created by Genning-Work on 2019/11/25.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, QYKFNIMUserSearchRangeOption){
    /*
     * 在好友中查询
     */
    QYKFNIMUserSearchRangeOptionFriends = 0,
    /*
     * 在所有人中查询
     */
    QYKFNIMUserSearchRangeOptionAll,
};

typedef NS_OPTIONS(NSInteger, QYKFNIMUserSearchContentOption){
    /*
     * 匹配UserId
     */
    QYKFNIMUserSearchContentOptionUserId = 1 << 0,
    /*
     * 匹配备注名（只有好友支持备注名匹配）
     */
    QYKFNIMUserSearchContentOptionAlias = 1 << 1,
    /*
     * 匹配昵称
     */
    QYKFNIMUserSearchContentOptionNickName = 1 << 2,
    /*
     * 匹配全部
     */
    QYKFNIMUserSearchContentOptionAll = QYKFNIMUserSearchContentOptionUserId | QYKFNIMUserSearchContentOptionAlias | QYKFNIMUserSearchContentOptionNickName,
};

@interface QYKFNIMUserSearchOption : NSObject

/**
*  搜索文本的搜索范围。（默认：QYKFNIMUserSearchRangeOptionFriends）
*/
@property (nonatomic, assign) QYKFNIMUserSearchRangeOption searchRange;

/**
*  搜索文本的匹配区域。（默认：QYKFNIMUserSearchContentOptionAll）
*/
@property (nonatomic, assign) QYKFNIMUserSearchContentOption searchContentOption;

/**
*  忽略大小写。（默认：YES）
*/
@property (nonatomic, assign) BOOL ignoreingCase;

/**
*  搜索文本。
*/
@property (nullable,nonatomic,copy) NSString *searchContent;

@end

NS_ASSUME_NONNULL_END
