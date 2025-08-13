//
//  QYKFNIMTeamSearchOption.h
//  QYKFNIMSDK
//
//  Created by Genning-Work on 2019/12/6.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, QYKFNIMTeamSearchContentOption){
    /*
     * 匹配TeamName
     */
    QYKFNIMTeamSearchContentOptiontName = 1 << 0,
    /*
     * 匹配TeamID
     */
    QYKFNIMTeamSearchContentOptiontId = 1 << 1,
    /*
     * 匹配全部，默认
     */
    QYKFNIMTeamSearchContentOptionTeamAll = QYKFNIMTeamSearchContentOptiontName | QYKFNIMTeamSearchContentOptiontId
};

@interface QYKFNIMTeamSearchOption : NSObject

/**
*  搜索文本的匹配区域。（默认：QYKFNIMUserSearchContentOptiontTeamName）
*/
@property (nonatomic, assign) QYKFNIMTeamSearchContentOption searchContentOption;

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
