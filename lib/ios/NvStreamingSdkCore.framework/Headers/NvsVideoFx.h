//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Dec 29. 2016
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsFx.h"


/*! \if ENGLISH
 *  \brief The type of the video effect
 *  \else
 *  \brief 视频特效类型
 *  \endif
*/
typedef enum {
    NvsVideoFxType_Builtin = 0,
    NvsVideoFxType_Package,
    NvsVideoFxType_Custom
} NvsVideoFxType;

/*! \if ENGLISH
 *  \brief Video effect
 *
 *  The video effect is a special effect that display on the video clip, which can change the overall or partial color, brightness, transparency, etc. of the video image, so that the video can show a special effect.
 *  On the Video Clip, users can add, remove, and get multiple video effects.
 *  \warning In the NvsVideoFx class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 视频特效
 *
 *  视频特效是显示在视频片段上的特效，能够改变视频图像整体或者局部的颜色、亮度、透明度等，使视频显示出特殊的效果。在视频片段(Video Clip)上，可以添加、移除、获取多个视频特效。
 *  \warning NvsVideoFx类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsVideoFx : NvsFx

@property (readonly) NvsVideoFxType videoFxType;    //!< \if ENGLISH The type of the video effect. \else 视频特效类型 \endif
@property (readonly) NSString *bultinVideoFxName;   //!< \if ENGLISH The name of the built-in video effect. If it's not a built-in video effect, return nil.\else 内嵌视频特效名字。如果不是内嵌视频特效，返回nil \endif
@property (readonly) NSString *videoFxPackageId;    //!< \if ENGLISH The ID of the video effect resource package. If it's not a resource package video effect, return nil. \else 视频特效资源包ID。如果不是资源包视频特效，返回nil \endif
@property (readonly) unsigned int index;            //!< \if ENGLISH The index of the Video effect. \else 视频特效索引 \endif

@end

