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

#import "NvsObject.h"


/*! \if ENGLISH
 *  \brief Clip type
 *  \else
 *  \brief 片段类型
 *  \endif
*/
typedef enum NvsClipType {
    NvsClipType_Video = 0,     //!< \if ENGLISH Video clip. \else 视频片段 \endif
    NvsClipType_Audio,         //!< \if ENGLISH Audio clip. \else 音频片段 \endif
} NvsClipType;


/*! \if ENGLISH
 *  \brief Clips are specific description of audio and video files.
 *
 *  A clip is an entity that accommodates audio and video content and a description of video and audio files which divided into an audio clip and a video clip.
 *  It defines the common attributes and behaviors of different types of clips,that is,the derived audio clips and video clips can be modified as needed for each triming in and out point, left and right channel, playback speed, etc. In the SDK framework, corresponding audio clips and video clips can be added to the track.
 *  \warning In the NvsClip class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 片段，音视频文件的具体描述
 *
 *  片段是容纳音视频内容的实体，是对视频、音频文件的描述，分为音频片段(Audio Clip)和视频片段(Video Clip)。它定义了不同类型片段所拥有的共同属性和行为，
 *  即派生的音频片段和和视频片段可根据需要修改各自的裁剪出入点，左右声道，播放速度等。在SDK框架中，在轨道(Track)上可添加相应的音频片段和视频片段。
 *  \warning NvsClip类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsClip : NvsObject

@property (readonly) int64_t trimIn;             //!< \if ENGLISH Clip triming in point (in microseconds). \else 片段裁剪入点(单位微秒)\endif

@property (readonly) int64_t trimOut;            //!< \if ENGLISH Clip triming out point (in microseconds). \else 片段裁剪出点(单位微秒) \endif

@property (readonly) int64_t inPoint;            //!< \if ENGLISH The in point of the clip on the timeline (in microseconds). \else 片段在时间线上的入点(单位微秒) \endif

@property (readonly) int64_t outPoint;           //!< \if ENGLISH The out point of the clip on the timeline (in microseconds). \else 片段在时间线上的出点(单位微秒) \endif

@property (readonly) NvsClipType type;           //!< \if ENGLISH Clip type (video, audio). \else 片段类型（视频、音频） \endif

@property (readonly) unsigned int index;         //!< \if ENGLISH The index of the clip on the track. \else 片段在轨道上的索引 \endif

@property (readonly) NSString *filePath;         //!< \if ENGLISH File path of clip. \else 片段文件路径 \endif

@property (readonly) unsigned int fxCount;       //!< \if ENGLISH The count of special effects on the clip. \else 片段上的特效数量 \endif

/*! \if ENGLISH
 *  \brief Change the trimming in point of the clip.
 *  \param newTrimInPoint New trimming in point (in microseconds)
 *  \param affectSibling Whether it affects other clips on the same track
 *  \return Returns the actual reachable trimming in point (in microseconds). Note: The range of the actual achievable trimming in point is [0,trimOut - 1].
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 修改片段裁剪入点
 *  \param newTrimInPoint 新裁剪入点(单位微秒)
 *  \param affectSibling 是否影响同轨道上其他片段
 *  \return 返回实际可到达的裁剪入点(单位微秒)。注意：实际可达到的裁剪入点范围在[0,trimOut - 1]
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeTrimOutPoint:affectSibling:
*/
- (int64_t)changeTrimInPoint:(int64_t)newTrimInPoint affectSibling:(BOOL)affectSibling;

/*! \if ENGLISH
 *  \brief Change the trimming out point of the clip.
 *  \param newTrimOutPoint New trimming out point (in microseconds)
 *  \param affectSibling Whether it affects other clips on the same track
 *  \return Returns the actual reachable trimming out point (in microseconds). Note: The range of the actual achievable trimming out point is [trimIn + 1,clipDuration).
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 修改片段裁剪出点
 *  \param newTrimOutPoint 新裁剪出点(单位微秒)
 *  \param affectSibling 是否影响同轨道上其他片段
 *  \return 返回实际可到达的裁剪出点(单位微秒)。注意：实际可达到的裁剪出点范围在[trimIn + 1,clipDuration),clipDuration为片段时长。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeTrimInPoint:affectSibling:
*/
- (int64_t)changeTrimOutPoint:(int64_t)newTrimOutPoint affectSibling:(BOOL)affectSibling;

/*! \if ENGLISH
 *  \brief Get the playback speed of the clip.
 *
 *  The default value is 1, which means it plays at normal speed; the value less than 1 means it slowly plays; the value greater than 1 means it fast plays.
 *  \return Returns the playback speed of the current clip.
 *  \else
 *  \brief 获取片段的播放速度。
 *
 *  默认值为1，表示按正常速度播放;小于1的值表示慢放;大于1的值表示快放。
 *  \return 返回当前片段的播放速度
 *  \endif
 *  \sa changeSpeed:
*/
- (double)getSpeed;

/*! \if ENGLISH
 *  \brief Change the playback speed of the clip.
 *  \param newSpeed New playback speed
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变片段的播放速度
 *  \param newSpeed 新的播放速度
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa getSpeed
*/
- (void)changeSpeed:(double)newSpeed;

/*! \if ENGLISH
 *  \brief Change the playback speed of the clip.
 *  \param newSpeed The new playback speed
 *  \param keepAudioPitch Whether to keep the tone unchanged
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变片段的播放速度
 *  \param newSpeed 新的播放速度
 *  \param keepAudioPitch 保持音调不变
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa getSpeed
 *  \since 1.15.1
*/
- (void)changeSpeed:(double)newSpeed keepAudioPitch:(BOOL)keepAudioPitch;

/*! \if ENGLISH
 *  \brief Set the channels (left and right).
 *  \param leftVolumeGain The left channel value to be set, the range value is [0, 4).
 *  \param rightVolumeGain The right channel value to be set, the range value is [0, 4).
 *  \else
 *  \brief 设置声道（左声道和右声道）
 *  \param leftVolumeGain 要设置的左声道值，取值范围[0,4)。
 *  \param rightVolumeGain 要设置的右声道值，取值范围[0,4)。
 *  \endif
 *  \sa getVolumeGain:rightVolumeGain:
*/
- (void)setVolumeGain:(float)leftVolumeGain rightVolumeGain:(float)rightVolumeGain;

/*! \if ENGLISH
 *  \brief Get the channel values (left and right)
 *  \param leftVolumeGain The left channel value to be set, the range value is [0, 4).
 *  \param rightVolumeGain The right channel value to be set, the range value is [0, 4).
 *  \else
 *  \brief 获取置声道值（左声道和右声道）
 *  \param leftVolumeGain Output the left channel value.
 *  \param rightVolumeGain Output the right channel value.
 *  \endif
 *  \sa getVolumeGain:rightVolumeGain:
*/
- (void)getVolumeGain:(float *)leftVolumeGain rightVolumeGain:(float *)rightVolumeGain;

/*! \if ENGLISH
 *  \brief Sets whether to loop audio if the clip' trim out go beyond its audio stream's duration
 *  \param loop whether to loop audio
 *  \else
 *  \brief 设置当前片段的剪辑出点超过其音频流长度时是否循环播放音频
 *  \param loop 是否循环播放音频
 *	\endif
 *  \sa getLoopAudio
 *  \since 2.9.0
 */
- (void)setLoopAudio:(BOOL)loop;

/*! \if ENGLISH
 *  \brief Gets whether to loop audio if the clip' trim out go beyond its audio stream's duration
 *  \return Returns boolean value to indicate whether to loop audio
 *  \else
 *  \brief 检查当前片段的剪辑出点超过其音频流长度时是否循环播放音频
 *  \return 返回Boolean值表示是否循环播放音频
 *	\endif
 *  \sa setLoopAudio
 *  \since 2.9.0
 */
- (BOOL)getLoopAudio;

@end

