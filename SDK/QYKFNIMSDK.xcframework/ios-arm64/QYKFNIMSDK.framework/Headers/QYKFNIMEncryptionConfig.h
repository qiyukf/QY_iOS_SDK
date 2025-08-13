//
//  QYKFNIMEncryptionConfig.h
//  QYKFNIMSDK
//
//  Created by Netease on 2019/10/14.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QYKFNIMAsymEncryptionOption.h"

NS_ASSUME_NONNULL_BEGIN

/**
 非对称加密类型

 - QYKFNIMAsymEncryptionTypeRSA: RSA加密
 - QYKFNIMAsymEncryptionTypeSM2: SM加密
 */
typedef NS_ENUM (NSInteger, QYKFNIMAsymEncryptionType){
    QYKFNIMAsymEncryptionTypeRSA = 1, //RSA
    QYKFNIMAsymEncryptionTypeSM2 = 1 << 1, //SM2
};

/**
 对称加密类型

 - QYKFNIMSymEncryptionTypeRC4: RC4加密
 - QYKFNIMSymEncryptionTypeAES: AES加密
 - QYKFNIMSymEncryptionTypeSM4: SM4加密
 - QYKFNIMSymEncryptionTypeAES256GCM: AES/GCM/NoPadding
 - QYKFNIMSymEncryptionTypeAES256CBC: AES/CBC/PKCS5Padding
 */
typedef NS_ENUM (NSInteger, QYKFNIMSymEncryptionType){
    QYKFNIMSymEncryptionTypeRC4 = 1,  //RC4
    QYKFNIMSymEncryptionTypeAES = 1 << 1,  //AES
    QYKFNIMSymEncryptionTypeSM4 = 1 << 2,  //SM4
    QYKFNIMSymEncryptionTypeAES256GCM = 1 << 3, // AES 256 GCM
    QYKFNIMSymEncryptionTypeAES256CBC = 1 << 6, // AES 256 CBC
};

@interface QYKFNIMEncryptionConfig : NSObject

/// 非对称加密类型（默认：RSA）
@property (nonatomic, assign) QYKFNIMAsymEncryptionType asymEncryptionType;

/// 对称加密类型（默认：RC4）
@property (nonatomic, assign) QYKFNIMSymEncryptionType symEncryptionType;

/// 更新非对称加密RSA的配置
/// @param option RSA配置
- (void)updateRSAOption:(QYKFNIMRSAOption *)option;

/// 更新非对称加密SM2的配置
/// @param option SM2配置
- (void)updateSM2Option:(QYKFNIMSM2Option *)option;

@end




NS_ASSUME_NONNULL_END
