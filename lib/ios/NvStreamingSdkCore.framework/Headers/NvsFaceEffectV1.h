//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Aug 2. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import "NvsCommonDef.h"

NVS_EXPORT @interface NvsFaceEffectV1 : NSObject

/*! \if ENGLISH
 *  \brief Initialize face effects.
 *  \param bundlePath Bundle data path
 *  \param package Authorization package
 *  \param size Authorization package size
 *  \else
 *  \brief 初始化人脸特效
 *  \param bundlePath bundle数据路径
 *  \param package 授权包
 *  \param size 授权包大小
 *  \endif
*/
+(void) InitFaceEffectV1:(NSString*) bundlePath authPackage:(void *)package authSize:(int)size;

/*! \if ENGLISH
 *  \brief Turn on multi-person detection mode, which can detect up to 8 faces at the same time. By default, 1 face is detected.
 *  \param maxFaceCount Maximum count of faces
 *  \else
 *  \brief 开启多人检测模式，最多可同时检测 8 张人脸，默认检测 1 张人脸
 *  \param maxFaceCount 最大人脸数
 *  \endif
*/
+(void) SetMaxFaces:(int) maxFaceCount;

+(void) done;

@end
