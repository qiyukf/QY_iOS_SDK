//
//  QYNIMConfig.h
//  QYVendor
//
//  Created by zhongzhida on 2022/7/26.
//  Copyright © 2022 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QYNIMConfig : NSObject
+ (instancetype)shareInstance;

- (BOOL)isForeign;

- (NSString *)nimLbsAddress;

- (NSString *)nimLinkAddress;
@end

NS_ASSUME_NONNULL_END
