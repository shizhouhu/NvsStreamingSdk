//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Sep 7. 2019
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsEffect.h"


/*!
 *  \brief
 *  视频特效类型
 */
typedef enum {
    NvsVideoEffectType_Builtin = 0,
    NvsVideoEffectType_Package,
    NvsVideoEffectType_Custom
} NvsVideoEffectType;

/*!
    \brief 视频特效

    视频特效是显示在视频片段上的特效，能够改变视频图像整体或者局部的颜色、亮度、透明度等，使视频显示出特殊的效果。在视频片段(Video Clip)上，可以添加、移除、获取多个视频特效。
    \warning NvsVideoEffect类中，所有public API都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsVideoEffect : NvsEffect

@property (readonly) NvsVideoEffectType type; //!< 视频特效类型
@property (readonly) NSString *builtinName; //!< 内嵌视频特效名字。如果不是内嵌视频特效返回nil
@property (readonly) NSString *packageId; //!< 视频特效资源包ID。如果不是资源包视频特效返回nil

@end

