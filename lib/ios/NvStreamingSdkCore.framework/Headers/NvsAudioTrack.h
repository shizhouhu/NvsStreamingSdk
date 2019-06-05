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

#import "NvsTrack.h"

@class NvsAudioClip;
@class NvsAudioTransition;

/*! \if ENGLISH
 *  \brief Audio track, collection of audio clips.
 *
 *  An audio track is an entity that holds audio clips. Multiple audio clips can be added to or removed from an audio track. An audio transition setting is required for the transition at the joint of two clips.
 *
 *  Note: For the meaning of interfaces and parameters of the audio track, please refer to the corresponding interface of the video track [NvsVideoTrack] (@ref NvsVideoTrack).
 *  \warning In the NvsAudioTrack class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 音频轨道，音频片段的集合
 *
 *  音频轨道是容纳音频片段的实体。每条音频轨道可以添加或者移除多个音频片段。一个音频片段播放到另一个音频片段时，需要进行音频转场设置，以便过渡衔接。
 *
 *  注：对于音频轨道的一系列接口及所其属参数含义,请参照视频轨道[NvsVideoTrack] (@ref NvsVideoTrack)的对应接口来对照理解。
 *  \warning NvsAudioTrack类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsAudioTrack : NvsTrack

/*! \if ENGLISH
 *  \brief Appends a clip at the end of the track
 *  \param filePath The path of file. For file path mode, please refer to the parameters of filePath for [addClip()] (@ref addClip:inPoint:).
 *  \return Returns the appended NvsAudioClip object.
 *  \warning This interface will cause the streaming engine state to jump to the engine stopping state. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief 在轨道尾部追加片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip()] (@ref addClip:inPoint:)的参数filePath。
 *  \return 返回追加的音频片段对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:trimIn:trimOut:
 *  \sa getClipWithIndex:
 *  \sa insertClip:clipIndex:
*/
- (NvsAudioClip *)appendClip:(NSString *)filePath;

/*! \if ENGLISH
 *  \brief Appends a clip at the end of the track.
 *  \param filePath The path of file. For file path mode, please refer to the parameters of filePath for [addClip()] (@ref addClip:inPoint:).
 *  \param trimIn Clip trim in point (in microseconds)
 *  \param trimOut Clip trim out point  (in microseconds)
 *  \return Returns the appended NvsAudioClip object.
 *  \warning This interface will cause the streaming engine state to jump to the engine stopping state. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief 在轨道尾部追加片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip()] (@ref addClip:inPoint:)的参数filePath。
 *  \param trimIn 片段裁剪入点(单位微秒)
 *  \param trimOut 片段裁剪出点(单位微秒)
 *  \return 返回追加的音频片段对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:
 *  \sa insertClip:trimIn:trimOut:clipIndex:
 *  \sa getClipWithIndex:
*/
- (NvsAudioClip *)appendClip:(NSString *)filePath trimIn:(int64_t)trimIn trimOut:(int64_t)trimOut;

/*! \if ENGLISH
 *  \brief Inserts a clip at the specified clip index on the track.
 *  \param filePath The path of file. For file path mode, please refer to the parameters of filePath for [addClip()] (@ref addClip:inPoint:).
 *  \param clipIndex The index of the special clip
 *  \return Returns the inserted NvsAudioClip object.
 *  \warning This interface will cause the streaming engine state to jump to the engine stopping state. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief
 *  \brief 在轨道上指定片段索引处插入片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip()] (@ref addClip:inPoint:)的参数filePath。
 *  \param clipIndex 指定片段索引
 *  \return 返回插入的音频片段对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:
 *  \sa getClipWithIndex:
 *  \sa insertClip:trimIn:trimOut:clipIndex:
*/
- (NvsAudioClip *)insertClip:(NSString *)filePath clipIndex:(unsigned int)clipIndex;

/*! \if ENGLISH
 *  \brief Inserts a clip at the specified clip index on the track.
 *  \param filePath The path of file. For file path mode, please refer to the parameters of filePath for [addClip()] (@ref addClip:inPoint:).
 *  \param trimIn Clip trim in point(in microseconds)
 *  \param trimOut Clip trim out point(in microseconds)
 *  \param clipIndex The index of the special clip
 *  \return Returns the inserted NvsAudioClip object.
 *  \warning This interface will cause the streaming engine state to jump to the engine stopping state. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief
 *  \brief 在轨道上指定片段索引处插入片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip()] (@ref addClip:inPoint:)的参数filePath。
 *  \param trimIn 片段裁剪入点(单位微秒)
 *  \param trimOut 片段裁剪出点(单位微秒)
 *  \param clipIndex 指定片段索引
 *  \return 返回插入的音频片段对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:trimIn:trimOut:
 *  \sa getClipWithIndex:
 *  \sa insertClip:clipIndex:
*/
- (NvsAudioClip *)insertClip:(NSString *)filePath trimIn:(int64_t)trimIn trimOut:(int64_t)trimOut clipIndex:(unsigned int)clipIndex;

/*! \if ENGLISH
 *  \brief Adds a clip
 *  \param filePath The path of file.
 *
 *  In IOS, there are four ways to import the path of audio and video clips:
 *
 *  a. Imports through the ALAssetsLibrary instance, the file path format is as follows："assets-library://asset/asset.mov?id=E0723C86-AA47-409C-B4E2-526D7C2AA9B5&ext=mov";
 *
 *  b. Imports through the MPMediaQuery instance of the IPod Library, the file path format is as follows："ipod-library://item/item.mp3?id=1217463725835578132";
 *
 *  c. Imports through the sand box, the file path format is as follows:"/var/mobile/Containers/Data/Documents/tmp/video20170406101714.mp4";
 *
 *  d. After IOS 8.0, the Photos framework replaces the ALAssetsLibrary library and is imported via the PHAset instance. The file path is as follows:："file:///var/mobile/Media/DCIM/100APPLE/IMG_0646.MP4".
 *  \param inPoint The in point of the clip on the timeline (in microseconds)
 *  \return Returns the added NvsAudioClip object.
 *  \warning This interface will cause the streaming engine state to jump to the engine stopping state. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief 添加片段
 *  \param filePath 片段路径
 *
 *  IOS中，对于导入的音视频片段的路径，有四种方式：
 *
 *  a. 通过ALAssetsLibrary实例导入，片段路径格式如下："assets-library://asset/asset.mov?id=E0723C86-AA47-409C-B4E2-526D7C2AA9B5&ext=mov"；
 *
 *  b. 通过IPod Library库的MPMediaQuery实例导入，片段路径格式如下："ipod-library://item/item.mp3?id=1217463725835578132"；
 *
 *  c. 通过沙河路径路径导入，片段路径格式如下："/var/mobile/Containers/Data/Documents/tmp/video20170406101714.mp4"；
 *
 *  d. IOS 8.0版以后，Photos框架替代ALAssetsLibrary库，通过PHAsset实例导入，片段路径如下："file:///var/mobile/Media/DCIM/100APPLE/IMG_0646.MP4"。
 *  \param inPoint 片段在时间线上的入点(单位微秒)
 *  \return 返回添加的音频片段对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:
 *  \sa insertClip:clipIndex:
 *  \sa addClip:inPoint:trimIn:trimOut:
*/
- (NvsAudioClip *)addClip:(NSString *)filePath inPoint:(int64_t)inPoint;

/*! \if ENGLISH
 *  \brief Add a clip in the specified duration.
 *  \param filePath The path of file. For file path mode, please refer to the parameters of filePath for [addClip()] (@ref addClip:inPoint:).
 *  \param inPoint The in point of the clip on the timeline (in microseconds)
 *  \param trimIn Clip trim in point (in microseconds)
 *  \param trimOut Clip trim out point (in microseconds)
 *  \return Returns the added NvsAudioClip object.
 *  \warning This interface will cause the streaming engine state to jump to the engine stopping state. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief 添加指定长度的片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip()] (@ref addClip:inPoint:)的参数filePath。
 *  \param inPoint 片段在时间线上的入点(单位微秒)
 *  \param trimIn 片段裁剪入点(单位微秒)
 *  \param trimOut 片段裁剪出点(单位微秒)
 *  \return 返回添加的音频片段对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:trimIn:trimOut:
 *  \sa insertClip:trimIn:trimOut:clipIndex:
 *  \sa addClip:inPoint:
*/
- (NvsAudioClip *)addClip:(NSString *)filePath inPoint:(int64_t)inPoint trimIn:(int64_t)trimIn trimOut:(int64_t)trimOut;

/*! \if ENGLISH
 *  \brief Gets a clip by index.
 *  \param clipIndex Clip index
 *  \return Returns the obtained NvsAudioClip object.
 *  \else
 *  \brief 通过索引获取片段
 *  \param clipIndex 片段索引
 *  \return 返回获取的音频片段对象
 *  \endif
 *  \sa getClipWithTimelinePosition:
 *  \sa appendClip:
 *  \sa insertClip:clipIndex:
*/
- (NvsAudioClip *)getClipWithIndex:(unsigned int)clipIndex;

/*! \if ENGLISH
 *  \brief Gets a clip by the specified position of the timeline.
 *  \param timelinePos The position on the timeline (in microseconds)
 *  \return Returns the obtained NvsAudioClip object.
 *  \else
 *  \brief 通过时间获取片段对象
 *  \param timelinePos 时间线上的位置(微秒)
 *  \return 返回获取的音频片段对象
 *  \endif
 *  \sa getClipWithIndex:
*/
- (NvsAudioClip *)getClipWithTimelinePosition:(int64_t)timelinePos;

/*! \if ENGLISH
 *  \brief Sets a built-in transition.
 *  \param srcClipIndex The index of the source clip
 *  \param transitionName Audio transition name. Note: If users set a null string, original transition should be deleted.
 *  \return Returns the NvsAudioTransition object.
 *  \warning The interface will cause the streaming engine status to jump to the engine stop status. For details, please refer to[The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief 设置内嵌式转场
 *  \param srcClipIndex 源片段索引
 *  \param transitionName 音频转场名称。注意：如果设为空字符串，则删除原有转场
 *  \return 返回音频转场对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa getTransitionWithSourceClipIndex:
*/
- (NvsAudioTransition *)setBuiltinTransition:(unsigned int)srcClipIndex withName:(NSString *)transitionName;

/*! \if ENGLISH
 *  \brief Gets the transition through the index of the source clip.
 *  \param srcClipIndex The index of the source clip
 *  \return Returns the acquired  NvsAudioTransition object.
 *  \else
 *  \brief 通过源片段索引获取转场
 *  \param srcClipIndex 源片段索引
 *  \return 返回获取的音频转场对象
 *  \endif
 *  \sa setBuiltinTransition:withName:
*/
- (NvsAudioTransition *)getTransitionWithSourceClipIndex:(unsigned int)srcClipIndex;

@end
