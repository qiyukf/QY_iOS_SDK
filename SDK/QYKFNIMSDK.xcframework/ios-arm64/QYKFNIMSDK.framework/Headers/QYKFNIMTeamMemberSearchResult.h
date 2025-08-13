//
//  QYKFNIMTeamMemberSearchResult.h
//  NIMLib
//
//  Created by 崔生余 on 2024/1/12.
//  Copyright © 2024 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
@class QYKFNIMTeamMember;

NS_ASSUME_NONNULL_BEGIN

@interface QYKFNIMTeamMemberSearchResult : NSObject

/// 查询返回的列表
@property(nullable,nonatomic,copy,readonly) NSArray<QYKFNIMTeamMember *> *teamMemberList;

/// 下一次的偏移量
@property(nonatomic,assign,readonly) NSInteger offset;

/// 查询j结束
@property(nonatomic,assign,readonly) BOOL finished;

@end

NS_ASSUME_NONNULL_END
