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


/*! \if ENGLISH
 *  \brief The type of the video effect
 *  \else
 *  \brief 视频特效类型
 *  \endif
*/
typedef enum {
    NvsVideoEffectType_Builtin = 0,
    NvsVideoEffectType_Package,
    NvsVideoEffectType_Custom
} NvsVideoEffectType;


/*! \if ENGLISH
 *  \brief Video effect
 *
 *  The video effect can change the overall or partial color, brightness, transparency, etc. of the video image, so that the video can show a special effect.
 *  \warning In the NvsVideoEffect class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 视频特效
 *
 *  视频特效能够改变视频图像整体或者局部的颜色、亮度、透明度等，使视频显示出特殊的效果。
 *  \warning NvsVideoEffect类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsVideoEffect : NvsEffect

@property (readonly) NvsVideoEffectType type;   //!< \if ENGLISH The type of the video effect. \else 视频特效类型 \endif
@property (readonly) NSString *builtinName;     //!< \if ENGLISH The name of the built-in video effect. If it's not a built-in video effect, return nil. \else 内嵌视频特效名字。如果不是内嵌视频特效返回nil \endif
@property (readonly) NSString *packageId;       //!< \if ENGLISH The ID of the resource package video effect. If it's not a resource package video effect, return nil. \else 视频特效资源包ID。如果不是资源包视频特效返回nil \endif

@end

