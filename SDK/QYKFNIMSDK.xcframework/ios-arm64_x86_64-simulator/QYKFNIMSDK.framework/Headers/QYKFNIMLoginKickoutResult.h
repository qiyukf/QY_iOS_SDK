//
//  QYKFNIMLoginKickoutResult.h
//  NIMLib
//
//  Created by 丁文超 on 2020/5/22.
//  Copyright © 2020 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMLoginManagerProtocol.h"


NS_ASSUME_NONNULL_BEGIN

@interface QYKFNIMLoginKickoutResult : NSObject

@property (nonatomic, assign) QYKFNIMKickReason reasonCode;

@property (nonatomic, assign) QYKFNIMLoginClientType clientType;

@property (nonatomic, copy) NSString *reasonDesc;

@property (nonatomic, assign) NSInteger customClientType;

@end

NS_ASSUME_NONNULL_END
