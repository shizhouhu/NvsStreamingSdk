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

/*! \file NvsTrack.h
 */
#pragma once

#import "NvsObject.h"

/*! \if ENGLISH
 *  \brief Track type
 *  \else
 *  \brief 轨道类型
 *  \endif
*/
typedef enum NvsTrackType {
    NvsTrackType_Video = 0,   //!< \if ENGLISH Video \else 视频 \endif
    NvsTrackType_Audio,       //!< \if ENGLISH Audio \else 音频 \endif
} NvsTrackType;

/*! \if ENGLISH
 *  \brief Track is container for video and audio clips.
 *
 *  A track can be thought of as a collection of clips, divided into audio track and video track. Once you have created a timeline instance, you can add or remove multiple tracks.
 *  On each track, you can add multiple video and audio clips to edit, and set the volume for the clips, as well as remove and move positions.
 *  \warning For NvsTrack class, all public API must be implemented within UI thread！！！
 *  \else
 *  \brief 轨道，容纳片段的实体
 *
 *  轨道可视作片段的集合,分为音频轨道(Audio Track)和视频轨道(Video Track)。创建时间线实例后，可添加或移除多条轨道。在每一条轨道上，可以添加多个要编辑的视音频片段，并对片段进行音量设置，也可以进行移除和位置移动。
 *  \warning NvsTrack类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsTrack : NvsObject

@property (readonly) NvsTrackType type;  //!< \if ENGLISH Track type. \else 轨道类型 \endif

@property (readonly) unsigned int index;  //!< \if ENGLISH Index of track. \else 轨道索引 \endif

@property (readonly) int64_t duration;   //!< \if ENGLISH Duration of track (in microseconds). \else 轨道长度(单位微秒) \endif

@property (readonly) unsigned int clipCount;  //!< \if ENGLISH Count of clips on the track \else 轨道上的片段数量 \endif

/*! \if ENGLISH
 *  \brief Change the in point of the clip on the timeline.
 *  \param clipIndex Index of clip
 *  \param newInPoint The new in point on the timeline (in microseconds)
 *  \return Returns the in point (in microseconds) which can be actual reachable on the timeline. Note: The range of in points on the timeline is within the open interval of the timeline out point of the previous clip and the timeline out point of this clip.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 修改片段在时间线上的入点
 *  \param clipIndex 片段索引
 *  \param newInPoint 时间线上新的入点（单位微秒）
 *  \return 返回实际可到达的时间线上的入点（单位微秒）。注意：实际可达到的时间线上的入点范围在前一个片段的时间线出点与此片段的时间线出点的开区间内
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \since 1.6.0
 *  \sa changeOutPoint:newOutPoint:
*/
- (int64_t)changeInPoint:(unsigned int)clipIndex newInPoint:(int64_t)newInPoint;

/*! \if ENGLISH
 *  \brief Change the out point of the clip on the timeline.
 *  \param clipIndex Index of clip
 *  \param newOutPoint The new out point on the timeline (in microseconds)
 *  \return Returns the out point (in microseconds) which can be actual reachable on the timeline. Note: The range of out points on the timeline is within the open interval of the timeline in point of this clip and the timeline in point of the next clip.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 修改片段在时间线上的出点
 *  \param clipIndex 片段索引
 *  \param newOutPoint 新时间线上的出点（单位微秒）
 *  \return 返回实际可到达的时间线上的出点（单位微秒）。注意：实际可达到的时间线上的出点范围在此片段的时间线入点与后一个片段的时间线入点的开区间内。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \since 1.6.0
 *  \sa changeInPoint:newInPoint:
*/
- (int64_t)changeOutPoint:(unsigned int)clipIndex newOutPoint:(int64_t)newOutPoint;

/*! \if ENGLISH
 *  \brief Split the specified clip.
 *  \param clipIndex Index of clip
 *  \param splitPoint Split point (in microseconds)）
 *  \return Determine whether the split is successful, YES is successful for splitting,NO is unsuccessful.
 *
 *  Splitting a clip, that is, an operation of dividing a clip of a specified index value into two clips, the index value of the clip on the corresponding track is also changed accordingly.
 *
 *  An example is as follows:
 *
 *  ![] (@ref TrackClip.PNG)
 *  In the above figure, there are three video clips C1, C2, and C3 on the track, and the clip C2 is splited, and the spilted clips are named C2 and C4, respectively.
 *  It's determined whether the segmentation is successful by obtaining the current count of clips on the track. If the segmentation is successful, the C2 and C4 index values correspond to 1 and 2.
 *
 *  The results are as follows:
 *  ![] (@ref afterSplitClip.PNG)
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 分割指定的片段
 *  \param clipIndex 片段索引
 *  \param splitPoint 分割点（单位微秒）
 *  \return 判断是否分割成功，YES为分割成功； NO则不成功
 *
 *  分割片段，即对指定索引值的片段进行分割而变为两个片段的操作，对应的轨道上片段的索引值也会进行相应变化。
 *
 *  示例如下:
 *
 *  ![] (@ref TrackClip.PNG)
 *  上图中轨道上有三个视频片段C1、C2、C3，对片段C2进行分割，分割后的片段分别命名为C2和C4。通过获取轨道上当前片段数来判定是否分割成功，分割成功则C2和C4索引值对应为1和2。
 *
 *  结果如下图：
 *  ![] (@ref afterSplitClip.PNG)
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa removeClip
*/
- (BOOL)splitClip:(unsigned int)clipIndex splitPoint:(int64_t)splitPoint;

/*! \if ENGLISH
 *	\brief Remove the specified clip
 *  \param clipIndex Index of clip
 *  \param keepSpace Whether the clip's space on the track is preserved after the clip is removed. A value of true is reserved, and a value of false is not retained.
 *  \return Determine if the removal is successful. Returning YES will remove the success and NO will fail.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *	\brief 移除指定的片段
 *  \param clipIndex 片段索引
 *  \param keepSpace 片段移除后，是否保留该片段在轨道上的空间。值为true则保留，false则不保留。
 *  \return 判断是否移除成功。返回YES则移除成功，NO则失败。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa removeAllClips
*/
- (BOOL)removeClip:(unsigned int)clipIndex keepSpace:(BOOL)keepSpace;

/*! \if ENGLISH
 *  \brief Remove all clips within the specified interval, and adjust the timeline in or out point if the clip only partially overlaps the interval.
 *  \param startTimelinePos The starting timeline position of the interval (in microseconds)
 *  \param endTimelinePos The ending timeline position of the interval (in microseconds)
 *  \param keepSpace After the segment in the interval is removed, whether the space on the track occupied by the interval is reserved. A value of true is reserved, and a value of false is not retained.
 *  \return Determine if the removal is successful. Returning YES will remove the success and NO will fail.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 移除指定的区间内的所有片段，如果片段只有部分与该区间重合则调整其时间线入点或者出点
 *  \param startTimelinePos 区间的起始时间线位置（单位微秒）
 *  \param endTimelinePos 区间的结束时间线位置（单位微秒）
 *  \param keepSpace 区间内的片段移除后，是否保留该区间所占轨道上的空间。值为true则保留，false则不保留
 *  \return 是否移除成功。返回true则移除成功，false则移除不成功
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
*/
- (BOOL)removeRange:(int64_t)startTimelinePos endTimelinePos:(int64_t)endTimelinePos keepSpace:(BOOL)keepSpace;

/*! \if ENGLISH
 *  \brief Move the specified clip
 *  \param clipIndex Index of clip
 *  \param destClipIndex Target index for clip movement
 *  \return Determine if the removal is successful. Returning YES will remove the success and NO will fail.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 移动指定的片段
 *  \param clipIndex 片段索引
 *  \param destClipIndex 片段移动的目标索引
 *  \return 判断是否移动成功。返回YES为移动成功，NO则失败。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
*/
- (BOOL)moveClip:(unsigned int)clipIndex destClipIndex:(unsigned int)destClipIndex;

/*! \if ENGLISH
 *	\brief Remove all clips
 *  \return Determine if the removal is successful. Returning YES will remove the success and NO will fail.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *	\brief 移除所有片段
 *  \return 判断是否移除成功。返回YES为移除成功，NO则失败。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa removeClip:keepSpace:
*/
- (BOOL)removeAllClips;

/*! \if ENGLISH
 *	\brief Set the volume
 *  \param leftVolumeGain Set the left channel of the volume, in the range [0, 4).
 *  \param rightVolumeGain Set the right channel of the volume, in the range [0, 4).
 *  \else
 *	\brief 设置音量
 *  \param leftVolumeGain 设置音量的左声道，取值范围[0,4)。
 *  \param rightVolumeGain 设置音量的右声道，取值范围[0,4)。
 *  \endif
 *  \sa getVolumeGain:rightVolumeGain:
*/
- (void)setVolumeGain:(float)leftVolumeGain rightVolumeGain:(float)rightVolumeGain;

/*! \if ENGLISH
 *	\brief Get the volume
 *  \param leftVolumeGain Output the left channel of the volume, in the range [0, 4).
 *  \param rightVolumeGain Output the right channel of the volume, in the range [0, 4).
 *  \else
 *	\brief 获取音量
 *  \param leftVolumeGain 输出音量的左声道
 *  \param rightVolumeGain 输出音量的右声道
 *  \endif
 *  \sa setVolumeGain:rightVolumeGain:
*/
- (void)getVolumeGain:(float *)leftVolumeGain rightVolumeGain:(float *)rightVolumeGain;

@end
