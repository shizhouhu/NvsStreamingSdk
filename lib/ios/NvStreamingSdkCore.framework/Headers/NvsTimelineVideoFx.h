//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jun 17. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsFx.h"
#include <CoreGraphics/CGGeometry.h>

/*! \if ENGLISH
 *  \brief The type of timeline video effect.
 *  \else
 *  \brief 时间线视频特效类型
 *  \endif
*/
typedef enum {
    NvsTimelineVideoFxType_Builtin = 0,
    NvsTimelineVideoFxType_Package,
    NvsTimelineVideoFxType_Custom
} NvsTimelineVideoFxType;


/*! \if ENGLISH
 *  \brief Timeline video effect
 *  \warning In the NvsTimelineVideoFx class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 时间线视频特效
 *  \warning NvsTimelineVideoFx类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsTimelineVideoFx : NvsFx

@property (readonly) NvsTimelineVideoFxType timelineVideoFxType;  //!< \if ENGLISH The type of timeline video effect. \else 时间线视频特效类型 \endif
@property (readonly) NSString *bultinTimelineVideoFxName;         //!< \if ENGLISH The name of the built-in video effect on the timeline. If it's not a built-in video effect on the timeline, it returns nil. \else 内嵌时间线视频特效名字。如果不是内嵌时间线视频特效返回nil \endif
@property (readonly) NSString *timelineVideoFxPackageId;          //!< \if ENGLISH The resource package ID of the video effect on the timeline. If it's not a resource package video effect on the timeline, it returns nil. \else 时间线视频特效资源包ID。如果不是资源包时间线视频特效返回nil \endif
@property (readonly) int64_t inPoint;                             //!< \if ENGLISH The in point of the timeline video effect on the timeline (in microseconds). \else 时间线视频特效在时间线上的入点（单位微秒） \endif
@property (readonly) int64_t outPoint;                            //!< \if ENGLISH The out point of the timeline video effect on the timeline (in microseconds). \else 时间线视频特效在时间线上的出点（单位微秒） \endif

/*! \if ENGLISH
 *  \brief Changes the in point of the timeline video effect on the timeline.
 *  \param newInPoint The new in point of the timeline video effect on the timeline (in microseconds)
 *  \return Returns the final in point value of the timeline video effect on the timeline (in microseconds).
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变时间线视频特效在时间线上的入点
 *  \param newInPoint 时间线特效在时间线上的新的入点（单位微秒）
 *  \return 返回时间线视频特效在时间线上最终的入点值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeOutPoint:
 *  \sa movePosition:
*/
- (int64_t)changeInPoint:(int64_t)newInPoint;

/*! \if ENGLISH
 *  \brief Changes the out point of the timeline video effects on the timeline.
 *  \param newOutPoint The new out point of the timeline video effect on the timeline (in microseconds)
 *  \return Returns the final out point value of the timeline video effect on the timeline (in microseconds).
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变时间线视频特效在时间线上的出点
 *  \param newOutPoint 时间线视频特效在时间线上的新的出点（单位微秒）
 *  \return 返回时间线视频特效在时间线最终的出点值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeInPoint:
 *  \sa movePosition:
*/
- (int64_t)changeOutPoint:(int64_t)newOutPoint;

/*! \if ENGLISH
 *  \brief Changes the position of the timeline video effect on the timeline (the in and out points move the value of "offset" at the same time).
 *  \param offset The offset value (in microseconds)
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变时间线视频特效在时间线上的位置(入点和出点同时偏移offset值)
 *  \param offset 偏移值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeInPoint:
 *  \sa changeOutPoint:
*/
- (void)movePosition:(int64_t)offset;

/*! \if ENGLISH
 *  \brief Converts the timeline coordinates to the particle system coordinates.
 *  \param ptCononical Timeline coordinates
 *  \return Returns the CGPoint object of the particle system coordinate after transforming.
 *  \else
 *  \brief 将时间线坐标转换为粒子系统坐标
 *  \param ptCononical 时间线坐标
 *  \return 返回转换后的粒子系统坐标CGPoint
 *  \endif
 *  \since 1.16.0
*/
- (CGPoint)mapPointFromCanonicalToParticleSystem:(CGPoint)ptCononical;

@end

