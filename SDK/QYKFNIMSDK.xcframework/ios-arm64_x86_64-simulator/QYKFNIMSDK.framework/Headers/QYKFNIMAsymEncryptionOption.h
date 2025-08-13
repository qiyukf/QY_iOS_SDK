//
//  QYKFNIMAsymEncryptionOption.h
//  QYKFNIMSDK
//
//  Created by Netease on 2019/10/14.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// SM2加密配置类
@interface QYKFNIMSM2Option : NSObject

/// 密钥版本
@property (nonatomic, assign) NSInteger version;

/// SM2 X值
@property (nonatomic, copy) NSString *SM2X;

/// SM2 Y值
@property (nonatomic, copy) NSString *SM2Y;

@end

typedef NS_ENUM(NSUInteger, QYKFNIMRSAPaddingMode) {
    QYKFNIMRSAPaddingModePKCS1,
    QYKFNIMRSAPaddingModeOAEPWithSHA_1AndMGF1,
    QYKFNIMRSAPaddingModeOAEPWithSHA_256AndMGF1
};

/// RSA加密配置类
@interface QYKFNIMRSAOption : NSObject

/// 密钥版本
@property (nonatomic, assign) NSInteger version;

/// RSA module
@property (nonatomic, copy) NSString *module;


/// RSA exp
@property (nonatomic, assign) NSUInteger exp;

/// RSA padding
@property (nonatomic, assign) QYKFNIMRSAPaddingMode paddingMode;

@end

NS_ASSUME_NONNULL_END
