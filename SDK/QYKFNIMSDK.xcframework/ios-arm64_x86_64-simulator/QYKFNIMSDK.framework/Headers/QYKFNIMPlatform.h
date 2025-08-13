//
//  QYKFNIMPlatform.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017年 Netease. All rights reserved.
//

#ifndef QYKFNIMPlatform_h
#define QYKFNIMPlatform_h

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#define QYKFNIM_IOS 1
#endif

#if TARGET_OS_MAC && !TARGET_OS_IPHONE
#define QYKFNIM_MAC 1
#endif


#if QYKFNIM_IOS
#import <UIKit/UIKit.h>
#elif QYKFNIM_MAC
#import <Cocoa/Cocoa.h>
@compatibility_alias UIImage NSImage;
@compatibility_alias UIView NSView;

#endif


#endif /* NIMPlatform_h */
