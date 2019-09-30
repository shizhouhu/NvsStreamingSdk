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

#import "NvsCommonDef.h"
#import "NvsObject.h"
#import "NvsLiveWindow.h"
#import "NvsCustomVideoFx.h"
#import "NvsTimelineCompoundCaption.h"

@class NvsVideoTrack;
@class NvsAudioTrack;
@class NvsTimelineCaption;
@class NvsTimelineAnimatedSticker;
@class NvsTimelineVideoFx;

/*! \if ENGLISH
 *  \brief Watermark position
 *  \else
 *  \brief 水印位置标识
 *  \endif
*/
typedef enum {
    NvsTimelineWatermarkPosition_TopRight = 0,        //!< \if ENGLISH Watermark on top-right. \else 水印显示在右上角 \endif
    NvsTimelineWatermarkPosition_TopLeft = 1,         //!< \if ENGLISH Watermark on top-left. \else 水印显示在左上角 \endif
    NvsTimelineWatermarkPosition_BottomLeft = 2,      //!< \if ENGLISH Watermark on bottom-left. \else 水印显示在左下角 \endif
    NvsTimelineWatermarkPosition_BottomRight = 3      //!< \if ENGLISH Watermark on bottom-right. \else 水印显示在右下角 \endif
} NvsTimelineWatermarkPosition;

NVS_EXPORT @interface NvsPlaybackRateControlRegion : NSObject

    @property (nonatomic, assign) int64_t startTime;
    @property (nonatomic, assign) int64_t endTime;
    @property (nonatomic, assign) float playbackRate;
    @property (nonatomic, assign) float audioGain;

@end

/*! \if ENGLISH
 *  \brief Timeline is which the entity of editing the scene.
 *
 *  The timeline consists of tracks and can be thought of as a collection of audio and video tracks. The timeline can add or remove multiple video and audio tracks, and the multiple tracks are superimposed and combined.
 *  When editing video,users can add captions. themes, animated stickers to make final beautifull videos.Otherwise,User needs to install asset package (theme package, animated stick package, Caption style and timeline effect package) before loading and using them.
 *  Each package comes with its unique package ID.For built-in timeline effects, they can be applied only with obtaining their effect name.
 *  \warning: for NvsTimeline class，all public APIs should be implemented in a UI thread!!!
 *  \else
 *  \brief 时间线，编辑场景的时间轴实体
 *
 *  时间线由轨道组成，可视作一系列音视频轨道的集合。在时间线上可添加或者移除多条视频轨道和音轨轨道，多条轨道之间是相互叠加合成的关系。
 *  当编辑视频时，根据需要还会添加上时间线字幕，主题以及相应的动画贴纸，以制作出美观的视频。另外，添加素材资源包(主题包，动画贴纸包，字幕样式包，时间线特效包等)，
 *  都得先安装，安装成功后获取packageId才能使用，而内建时间线特效(builtin)只需获取特效名称即可使用。
 *  \warning NvsTimeline类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsTimeline : NvsObject

@property (readonly) NvsVideoResolution videoRes;           //!< \if ENGLISH Video resolution (width:height ratio of video image). \else 视频解析度(图像宽高及横纵比) \endif

@property (readonly) NvsAudioResolution audioRes;           //!< \if ENGLISH Audio resolution (sampling rate, format and channel count) \else 音频解析度(采样率、采样格式及通道数) \endif

@property (readonly) NvsRational videoFps;                  //!< \if ENGLISH Video frame rate. \else 视频帧率 \endif

@property (readonly) int64_t duration;                      //!< \if ENGLISH Timeline duration(in micro-second). \else 时间线的时长（单位微秒） \endif

@property (nonatomic) int64_t audioFadeOutDuration;         //!< \if ENGLISH Audio fade out duration(in micro-second). \else 音频淡出时长（单位微秒） \endif


/*! \if ENGLISH
 *  \brief Appends video track.
 *  \return returns the appended NvsVideoTrack object.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 追加视频轨道
 *  \return 返回追加的视频轨道对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa removeVideoTrack:
 *  \sa videoTrackCount
 *  \sa getVideoTrackByIndex:
*/
- (NvsVideoTrack *)appendVideoTrack;

/*! \if ENGLISH
 *  \brief Appends audio track.
 *  \return returns the appended NvsAudioTrack object.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 追加音频轨道
 *  \return 返回追加的音频轨道对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa removeAudioTrack:
 *  \sa audioTrackCount
 *  \sa getAudioTrackByIndex:
*/
- (NvsAudioTrack *)appendAudioTrack;

/*! \if ENGLISH
 *  \brief Remove video track.
 *  \param trackIndex Index of video track
 *  \return Returns a BOOL value.YES means it removes successfully, NO means it fails.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 移除视频轨道
 *  \param trackIndex 视频轨道索引
 *  \return  判断是否移除成功。返回YES移除成功，NO则失败
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendVideoTrack
 *  \sa videoTrackCount
 *  \sa getVideoTrackByIndex:
*/
- (BOOL)removeVideoTrack:(unsigned int)trackIndex;

/*! \if ENGLISH
 *  \brief Remove audio track.
 *  \param trackIndex Index of audio track
 *  \return Returns a BOOL value.YES means it removes successfully, NO means it fails
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 移除音频轨道
 *  \param trackIndex 音频轨道索引
 *  \return  判断是否移除成功。返回YES移除成功，NO则失败
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendAudioTrack
 *  \sa audioTrackCount
 *  \sa getAudioTrackByIndex:
*/
- (BOOL)removeAudioTrack:(unsigned int)trackIndex;

/*! \if ENGLISH
 *  \brief Get count of video track.
 *  \return returns count of video track.
 *  \else
 *  \brief 获取视频轨道数量
 *  \return 返回视频轨道的数量
 *  \endif
 *  \sa appendVideoTrack
 *  \sa removeVideoTrack:
*/
- (unsigned int)videoTrackCount;

/*! \if ENGLISH
 *  \brief Get count of audio track.
 *  \return returns count of audio track.
 *  \else
 *  \brief 获取音频轨道数量
 *  \return 返回音频轨道的数量
 *  \endif
 *  \sa appendAudioTrack
 *  \sa removeAudioTrack:
*/
- (unsigned int)audioTrackCount;

/*! \if ENGLISH
 *  \brief Gets video track with track index.
 *  \param trackIndex Index of video track
 *  \return returns the NvsVideoTrack object.
 *  \else
 *  \brief 通过索引获取视频轨道
 *  \param trackIndex 视频轨道索引
 *  \return 返回获取的视频轨道对象
 *  \endif
 *  \sa appendVideoTrack
 *  \sa videoTrackCount
 *  \sa removeVideoTrack:
*/
- (NvsVideoTrack *)getVideoTrackByIndex:(unsigned int)trackIndex;

/*! \if ENGLISH
 *	\brief Gets audio track with track index.
 *	\param trackIndex Index of audio track
 *  \return returns the NvsAudioTrack object.
 *  \else
 *	\brief 通过索引获取音频轨道
 *	\param trackIndex 音频轨道索引
 *  \return 返回获取的音频轨道对象
 *  \endif
 *  \sa appendAudioTrack
 *  \sa audioTrackCount
 *  \sa removeAudioTrack:
*/
- (NvsAudioTrack *)getAudioTrackByIndex:(unsigned int)trackIndex;

/*! \if ENGLISH
 *  \brief Change the timeline video resolution.
 *         <br>Remark:If timeline is linked to a surfaceTexture, the surfaceTexture must be detached first, and then timeline video resolution can be changed.
 *          After timeline resolution is changed, the SurfaceTexture can be re-attached to timeline.
 *  \param videoWidth New video width
 *  \param videoHeight New video height
 *  \return Reurns YES means it changes successfully, NO means it fails.
 *  \else
 *  \brief 改变时间线的视频尺寸
 *         <br>注意:如果当前时间线已经被连接到了一个SurfaceTexture上，那么请在改变时间线的视频尺寸之前
 *         先断开当前时间线与SurfaceTexture的连接，改变视频尺寸后再重现连接那个SurfaceTexture!
 *  \param videoWidth 新的视频宽度
 *  \param videoHeight 新的视频高度
 *  \return 返回值表示改变是否成功
 *  \endif
 *  \since 2.5.0
*/
- (BOOL)changeVideoSize:(int)videoWidth videoHeight:(int)videoHeight;

/*! \if ENGLISH
 *  \brief Set the border of the caption to the actual envelope size of the text.
 *  \param isActualBoundingRect Whether to display the actual envelope size
 *  \else
 *  \brief 设置字幕的边框为文字的实际包络大小
 *  \param isActualBoundingRect 是否显示实际包络大小
 *  \endif
 *  \since 2.5.0
*/
- (void)setCaptionBoundingRectInActualMode:(BOOL)isActualBoundingRect;

/*! \if ENGLISH
 *  \brief Get the first caption on the timeline.
 *  \return Returns the NvsTimelineCaption object.
 *  \else
 *  \brief 获取时间线上的第一个字幕
 *  \return 返回获取的时间线字幕对象
 *  \endif
 *  \sa getLastCaption
 *  \sa addCaption:inPoint:duration:captionStylePackageId:
*/
- (NvsTimelineCaption *)getFirstCaption;

/*! \if ENGLISH
 *  \brief Get the last caption on the timeline.
 *  \return Returns the NvsTimelineCaption object.
 *  \else
 *  \brief 获取时间线上的最后一个字幕
 *  \return 返回获取的时间线字幕对象
 *  \endif
 *  \sa getFirstCaption
 *  \sa addCaption:inPoint:duration:captionStylePackageId:
*/
- (NvsTimelineCaption *)getLastCaption;

/*! \if ENGLISH
 *  \brief Get the previous caption of the current caption on the timeline
 *  \param caption The current caption on the timeline
 *  \return Returns the NvsTimelineCaption object.
 *  \else
 *  \brief 获取时间线上的当前字幕的前一个字幕
 *  \param caption 时间线上当前字幕对象
 *  \return 返回获取的时间线字幕对象
 *  \endif
 *  \sa getNextCaption:
*/
- (NvsTimelineCaption *)getPrevCaption:(NvsTimelineCaption *)caption;

/*! \if ENGLISH
 *  \brief Get the next caption of the current caption on the timeline
 *  \param caption The current caption on the timeline
 *  \return Returns the NvsTimelineCaption object.
 *  \else
 *  \brief 获取时间线上的当前字幕的前一个字幕
 *  \param caption 时间线上当前字幕对象
 *  \return 返回获取的时间线字幕对象
 *  \endif
 *  \sa getPrevCaption:
*/
- (NvsTimelineCaption *)getNextCaption:(NvsTimelineCaption *)caption;

/*! \if ENGLISH
 *	\brief Get a list of captions based on the position on the timeline.
 *  \param timelinePos The position on the timeline(in micro-second)
 *	\return Returns a list of arrays of captions at the current position。
 *  <br>The sorting rules for the obtained captions list are as follows:
 *  <br>1.When adding, the in points are different, and captions are arranged in the order of the in points;
 *  <br>2.When adding, the in points are the same, and captions are arranged in the order of adding captions.
 *  \else
 *	\brief 根据时间线上的位置获得字幕列表
 *  \param timelinePos 时间线上的位置（单位微秒）
 *	\return 返回当前位置字幕的数组列表
 *  <br>获取的字幕列表排序规则如下：
 *  <br>1.添加时字幕入点不同，按入点的先后顺序排列；
 *  <br>2.添加时字幕入点相同，按添加字幕的先后顺序排列。
 *  \endif
 *  \sa addCaption:inPoint:duration:captionStylePackageId:
*/
- (NSArray *)getCaptionsByTimelinePosition:(int64_t)timelinePos;

/*! \if ENGLISH
 *  \brief Add a caption on the timeline
 *  \param captionText Text of caption
 *  \param inPoint The in point of the caption on the timeline (in microseconds)
 *  \param duration Caption display duration (in microseconds)
 *  \param captionStylePackageId Caption style package Id
 *  \return Returns the NvsTimelineCaption object
 *  \else
 *  \brief 在时间线上添加字幕
 *  \param captionText 字幕的文字
 *  \param inPoint 字幕在时间线上的起点（单位微秒）
 *  \param duration 字幕显示时长（单位微秒）
 *  \param captionStylePackageId 字幕样式包Id
 *  \return 返回时间线字幕对象
 *  \endif
 *  \sa removeCaption:
*/
- (NvsTimelineCaption *)addCaption:(NSString *)captionText inPoint:(int64_t)inPoint duration:(int64_t)duration captionStylePackageId:(NSString *)captionStylePackageId;

/*! \if ENGLISH
 *  \brief Add a panorama caption on the timeline
 *  \param captionText Text of caption
 *  \param inPoint The in point of the caption on the timeline (in microseconds)
 *  \param duration Caption display duration (in microseconds)
 *  \param captionStylePackageId Caption style package Id
 *  \return Returns the NvsTimelineCaption object
 *  \else
 *  \brief 在时间线上添加全景图字幕
 *  \param captionText 字幕的文字
 *  \param inPoint 字幕在时间线上的入点（单位微秒）
 *  \param duration 字幕的显示时长（单位微秒）
 *  \param captionStylePackageId 字幕样式包Id
 *  \return 返回时间线字幕对象
 *  \endif
 *  \since 1.6.0
 *  \sa removeCaption:
*/
- (NvsTimelineCaption *)addPanoramicCaption:(NSString *)captionText inPoint:(int64_t)inPoint duration:(int64_t)duration captionStylePackageId:(NSString *)captionStylePackageId;

/*! \if ENGLISH
 *	\brief Remove the caption on the timeline.
 *	\param caption timeline caption object which removed
 *  \return Returns the next NvsTimelineCaption object.
 *  \else
 *	\brief 移除时间线上的字幕
 *	\param caption 要移除的时间线字幕对象
 *  \return 返回下一个时间线字幕对象
 *  \endif
 *  \sa addCaption:inPoint:duration:captionStylePackageId:
*/
- (NvsTimelineCaption *)removeCaption:(NvsTimelineCaption *)caption;

/*! \if ENGLISH
 *  \brief Get the first compound caption on the timeline.
 *  \return Returns the compound caption object.
 *  \else
 *  \brief 获取时间线上的第一个复合字幕
 *  \return 返回获取的时间线复合字幕对象
 *  \endif
 *  \since 2.9.0
 *  \sa getLastCompoundCaption
 *  \sa addCompoundCaption
 */
- (NvsTimelineCompoundCaption *)getFirstCompoundCaption;

/*! \if ENGLISH
 *  \brief Get the last compound caption on the timeline.
 *  \return Returns the compound caption object.
 *  \else
 *  \brief 获取时间线上的最后一个复合字幕
 *  \return 返回获取的时间线复合字幕对象
 *  \endif
 *  \since 2.9.0
 *  \sa getFirstCompoundCaption
 *  \sa addCompoundCaption
 */
- (NvsTimelineCompoundCaption *)getLastCompoundCaption;

/*! \if ENGLISH
 *  \brief Get the previous compound caption of the current compound caption on the timeline
 *  \param caption The current compound caption on the timeline
 *  \return Returns the compound caption object.
 *  \else
 *  \brief 获取时间线上的当前复合字幕的前一个复合字幕
 *  \param caption 时间线上当前复合字幕对象
 *  \return 返回获取的时间线复合字幕对象
 *  \endif
 *  \since 2.9.0
 *  \sa getNextCompoundCaption
 */
- (NvsTimelineCompoundCaption *)getPrevCompoundCaption:(NvsTimelineCompoundCaption *)caption;

/*! \if ENGLISH
 *  \brief Get the next compound caption of the current compound caption on the timeline
 *  \param caption The current compound caption on the timeline
 *  \return Returns the compound caption object.
 *  \else
 *  \brief 获取时间线上的当前复合字幕的前一个复合字幕
 *  \param caption 时间线上当前复合字幕对象
 *  \return 返回获取的时间线复合字幕对象
 *  \endif
 *  \since 2.9.0
 *  \sa getPrevCompoundCaption
 */
- (NvsTimelineCompoundCaption *)getNextCompoundCaption:(NvsTimelineCompoundCaption *)caption;

/*! \if ENGLISH
 *  \brief Get a list of compound captions based on the position on the timeline.
 *  \param timelinePos The position on the timeline(in micro-second)
 *  \return Returns a list of compound captions at the current position。
 *  <br>The sorting rules for the obtained captions list are as follows:
 *  <br>1. If the in points are different, captions are sorted in the order of the in points;
 *  <br>2. If the in points are the same, and captions are sorted in the order of compound caption added.
 *  \else
 *  \brief 根据时间线上的位置获得复合字幕列表
 *  \param timelinePos 时间线上的复合位置（单位微秒）
 *  \return 返回当前位置复合字幕的列表
 *  <br>获取的字幕列表排序规则如下：
 *  <br>1.如果字幕入点不同，按入点时间排列
 *  <br>2.如果字幕入点相同，按添加字幕的先后顺序排列。
 *  \endif
 *  \since 2.9.0
 *  \sa addCompoundCaption
 */
- (NSArray<NvsTimelineCompoundCaption*> *)getCompoundCaptionsByTimelinePosition:(long)timelinePos;

/*! \if ENGLISH
 *  \brief Add a caption on the timeline
 *  \param captionText Text of caption
 *  \param inPoint The in point of the caption on the timeline (in microseconds)
 *  \param duration Caption display duration (in microseconds)
 *  \param captionStylePackageId Caption style package Id
 *  \return Returns the NvsTimelineCaption object
 *  \else
 *  \brief 在时间线上添加字幕
 *  \param captionText 字幕的文字
 *  \param inPoint 字幕在时间线上的起点（单位微秒）
 *  \param duration 字幕显示时长（单位微秒）
 *  \param captionStylePackageId 字幕样式包Id
 *  \return 返回时间线字幕对象
 *  \endif
 *  \since 2.9.0
 *  \sa removeCaption
 */
- (NvsTimelineCompoundCaption *)addCompoundCaption:(long)inPoint
                                          duration:(long)duration
                          compoundCaptionPackageId:(NSString *)compoundCaptionPackageId;

/*! \if ENGLISH
 *  \brief Remove compound caption from the timeline.
 *  \param caption timeline compound caption object which to be removed
 *  \return Returns the next compound caption object.
 *  \else
 *  \brief 移除时间线上的复合字幕
 *  \param caption 要移除的时间线复合字幕对象
 *  \return 返回下一个时间线复合字幕对象
 *  \endif
 *  \since 2.9.0
 *  \sa addCompoundCaption
 */
- (NvsTimelineCompoundCaption *)removeCompoundCaption:(NvsTimelineCompoundCaption *)caption;

/*! \if ENGLISH
 *	\brief Get the first animated sticker on the timeline.
 *	\return Return the acquired NvsTimelineAnimatedSticker object.
 *  \else
 *	\brief 获取时间线上第一个动画贴纸
 *	\return 返回获取的时间线动画贴纸对象
 *  \endif
 *  \sa getLastAnimatedSticker
 *  \sa addAnimatedSticker:duration:animatedStickerPackageId:
*/
- (NvsTimelineAnimatedSticker *)getFirstAnimatedSticker;

/*! \if ENGLISH
 *	\brief Get the last animated sticker on the timeline.
 *	\return Return the acquired NvsTimelineAnimatedSticker object.
 *  \else
 *	\brief 获取时间线上最后一个动画贴纸
 *	\return 返回获取的时间线动画贴纸对象
 *  \endif
 *  \sa getFirstAnimatedSticker
*/
- (NvsTimelineAnimatedSticker *)getLastAnimatedSticker;

/*! \if ENGLISH
 *	\brief Get the previous animated sticker of the current animated sticker of the timeline.
 *	\param animatedSticker the current NvsTimelineAnimatedSticker obejct
 *	\return Return the acquired NvsTimelineAnimatedSticker object.
 *  \else
 *	\brief 获取时间线当前动画贴纸的前一个动画贴纸
 *	\param animatedSticker 时间线动画贴纸对象
 *	\return 返回获取的时间线动画贴纸对象
 *  \endif
 *  \sa getNextAnimatedSticker:
*/
- (NvsTimelineAnimatedSticker *)getPrevAnimatedSticker:(NvsTimelineAnimatedSticker *)animatedSticker;

/*! \if ENGLISH
 *  \brief Get the next animated sticker of the current animated sticker of the timeline.
 *  \param animatedSticker the current NvsTimelineAnimatedSticker obejct
 *  \return Return the acquired NvsTimelineAnimatedSticker object.
 *  \else
 *  \brief 获取时间线当前动画贴纸的后一个动画贴纸
 *  \param animatedSticker 时间线动画贴纸对象
 *  \return 返回获取的时间线动画贴纸对象
 *  \endif
 *  \sa getPrevAnimatedSticker:
*/
- (NvsTimelineAnimatedSticker *)getNextAnimatedSticker:(NvsTimelineAnimatedSticker *)animatedSticker;

/*! \if ENGLISH
 *  \brief Get an animated sticker list based on the position on the timeline.
 *  \param timelinePos Position on the timeline (in microseconds)
 *  \return Returns an array holding the current position animated sticker object
 *  <br>The sorting rules for the obtained animated sticker list are as follows:
 *  <br>1.When adding, the in points are different,animated stickers are arranged in the order of the in points;
 *  <br>2.When adding, the in points are the same, they are arranged in the order in which the animation stickers are added.
 *  \else
 *  \brief 根据时间线上的位置获得动画贴纸列表
 *  \param timelinePos 时间线上的位置（单位微秒）
 *  \return 返回保存当前位置动画贴纸对象的数组
 *  <br>获取的动画贴纸列表排序规则如下：
 *  <br>1.添加时入点不同，按入点的先后顺序排列；
 *  <br>2.添加时入点相同，按添加动画贴纸的先后顺序排列。
 *  \endif
 *  \sa addAnimatedSticker:duration:animatedStickerPackageId:
*/
- (NSArray *)getAnimatedStickersByTimelinePosition:(int64_t)timelinePos;

/*! \if ENGLISH
 *  \brief Add a animated sticker on the timeline.
 *  \param inPoint The in point of the animated sticker on the timeline (in microseconds)
 *  \param duration The duration of the animation sticker which displayed (in microseconds)
 *  \param animatedStickerPackageId Animated sticker package Id
 *  \return Return the NvsTimelineAnimatedSticker object.
 *  \else
 *  \brief 在时间线上添加动画贴纸
 *  \param inPoint 动画贴纸在时间线上的入点（单位微秒）
 *  \param duration 动画贴纸的显示时长（单位微秒）
 *  \param animatedStickerPackageId 动画贴纸包Id
 *  \return 返回时间线动画贴纸对象
 *  \endif
 *  \sa removeAnimatedSticker:
*/
- (NvsTimelineAnimatedSticker *)addAnimatedSticker:(int64_t)inPoint duration:(int64_t)duration animatedStickerPackageId:(NSString *)animatedStickerPackageId;

/*! \if ENGLISH
 *  \brief Add a panorama animation sticker on the timeline.
 *  \param inPoint The in point of the animated sticker on the timeline (in microseconds)
 *  \param duration The duration of the animation sticker which displayed (in microseconds)
 *  \param animatedStickerPackageId Animated sticker package Id
 *  \return Return the NvsTimelineAnimatedSticker object.
 *  \else
 *  \brief 在时间线上添加全景图动画贴纸
 *  \param inPoint 动画贴纸在时间线上的起点（单位微秒）
 *  \param duration 动画贴纸的显示时长（单位微秒）
 *  \param animatedStickerPackageId 动画贴纸资源包ID
 *  \return 返回时间线动画贴纸对象
 *  \endif
 *  \since 1.6.0
 *  \sa removeAnimatedSticker
*/
- (NvsTimelineAnimatedSticker *)addPanoramicAnimatedSticker:(int64_t)inPoint duration:(int64_t)duration animatedStickerPackageId:(NSString *)animatedStickerPackageId;

/*! \if ENGLISH
 *  \brief Add a custom animated sticker on the timeline.
 *  \param inPoint The in point of custom animated sticker on the timeline (in microseconds)
 *  \param duration The duration of custom animation sticker which displayed (in microseconds)
 *  \param animatedStickerPackageId Animated sticker package Id
 *  \param customImagePath Path of custom animated sticker image
 *  \return Return the NvsTimelineAnimatedSticker object.
 *  \else
 *  \brief 在时间线上添加自定义动画贴纸
 *  \param inPoint 自定义动画贴纸在时间线上的入点（单位微秒）
 *  \param duration 自定义动画贴纸的显示时长（单位微秒）
 *  \param animatedStickerPackageId 自定义动画贴纸包Id
 *  \param customImagePath 自定义动画贴纸图像路径
 *  \return 返回时间线自定义动画贴纸对象
 *  \endif
 *  \sa removeAnimatedSticker:
*/
- (NvsTimelineAnimatedSticker *)addCustomAnimatedSticker:(int64_t)inPoint duration:(int64_t)duration animatedStickerPackageId:(NSString *)animatedStickerPackageId customImagePath:(NSString *)customImagePath;

/*! \if ENGLISH
 *  \brief Add a a custom panorama animated sticker on the timeline.
 *  \param inPoint The in point of custom animated sticker on the timeline (in microseconds)
 *  \param duration The duration of custom animation sticker which displayed (in microseconds)
 *  \param animatedStickerPackageId Animated sticker package Id
 *  \param customImagePath Path of custom animated sticker image
 *  \return Return the NvsTimelineAnimatedSticker object.
 *  \else
 *  \brief 在时间线上添加自定义全景图动画贴纸
 *  \param inPoint 动画贴纸在时间线上的起点（单位微秒）
 *  \param duration 动画贴纸的显示时长（单位微秒）
 *  \param animatedStickerPackageId 动画贴纸资源包ID
 *  \param customImagePath 自定义动画贴纸图像路径
 *  \return 返回时间线动画贴纸对象
 *  \endif
 *  \since 1.6.0
 *  \sa removeAnimatedSticker
*/
- (NvsTimelineAnimatedSticker *)addCustomPanoramicAnimatedSticker:(int64_t)inPoint duration:(int64_t)duration animatedStickerPackageId:(NSString *)animatedStickerPackageId customImagePath:(NSString *)customImagePath;

/*! \if ENGLISH
 *  \brief Remove an animated sticker on the timeline.
 *  \param animatedSticker The NvsTimelineAnimatedSticker object which will be removed
 *  \return Return the next NvsTimelineAnimatedSticker object.
 *  \else
 *  \brief 移除时间线上的动画贴纸
 *  \param animatedSticker 要移除的动画贴纸对象
 *  \return 返回下一个时间线动画贴纸对象
 *  \endif
 *  \sa addAnimatedSticker:duration:animatedStickerPackageId:
*/
- (NvsTimelineAnimatedSticker *)removeAnimatedSticker:(NvsTimelineAnimatedSticker *)animatedSticker;

/*! \if ENGLISH
 *  \brief Get the first timeline video effect on the timeline.
 *  \return Returns the acquired NvsTimelineVideoFx object.
 *  \else
 *  \brief 获取时间线上第一个时间线视频特效
 *  \return 返回获取的时间线视频特效对象
 *  \endif
*/
- (NvsTimelineVideoFx *)getFirstTimelineVideoFx;

/*! \if ENGLISH
 *  \brief Get the last timeline video effect on the timeline.
 *  \return Returns the acquired NvsTimelineVideoFx object.
 *  \else
 *  \brief 获取时间线上最后一个时间线视频特效
 *  \return 返回获取的时间线视频特效对象
 *  \endif
*/
- (NvsTimelineVideoFx *)getLastTimelineVideoFx;

/*! \if ENGLISH
 *  \brief Get the previous timeline video effect of a timeline video effect on the timeline.
 *  \param videoFx The NvsTimelineVideoFx object
 *  \return Returns the acquired NvsTimelineVideoFx object.
 *  \else
 *  \brief 获取时间线上某个时间线视频特效的前一个时间线视频特效
 *  \param videoFx 时间线视频特效对象
 *  \return 返回获取的时间线视频特效对象
 *  \endif
*/
- (NvsTimelineVideoFx *)getPrevTimelineVideoFx:(NvsTimelineVideoFx *)videoFx;

/*! \if ENGLISH
 *  \brief Get the next timeline video effect of a timeline video effect on the timeline.
 *  \param videoFx The NvsTimelineVideoFx object
 *  \return Returns the acquired NvsTimelineVideoFx object.
 *  \else
 *  \brief 获取时间线上某个时间线视频特效的下一个时间线视频特效
 *  \param videoFx 时间线视频特效对象
 *  \return 返回获取的时间线视频特效对象
 *  \endif
*/
- (NvsTimelineVideoFx *)getNextTimelineVideoFx:(NvsTimelineVideoFx *)videoFx;

/*! \if ENGLISH
 *  \brief Get a list of timeline video effects based on position on the timeline.
 *  \param timelinePos The position on the timeline (in microseconds)
 *  \return Returns an array of timeline video effects in current position.
 *  <br>The ordering rules for the acquired timeline video effects are as follows:
 *  <br>1.When adding, the in points are different, arranged in the order of the in points;
 *  <br>2.When adding, the entry points are the same, arranged in the order of adding timeline video effects.
 *  \else
 *  \brief 根据时间线上的位置获得时间线视频特效列表
 *  \param timelinePos 时间线上的位置（单位微秒）
 *  \return 返回当前位置时间线视频特效对象的数组
 *  <br>获取的时间线视频特效排序规则如下：
 *  <br>1.添加时入点不同，按入点的先后顺序排列；
 *  <br>2.添加时入点相同，按添加时间线视频特效的先后顺序排列。
 *  \endif
*/
- (NSArray *)getTimelineVideoFxByTimelinePosition:(int64_t)timelinePos;

/*! \if ENGLISH
 *  \brief Add a built-in timeline video effect on the timeline
 *  \param inPoint The in point of the timeline video effect on the timeline (in microseconds)
 *  \param duration Duration of the timeline video effect which displayed (in microseconds)
 *  \param videoFxName The video effect name
 *  \return Return the NvsTimelineVideoFx object
 *  \else
 *  \brief 在时间线上添加内嵌的时间线视频特效
 *  \param inPoint 时间线视频特效在时间线上的入点（单位微秒）
 *  \param duration 时间线视频特效显示的时长（单位微秒）
 *  \param videoFxName 内嵌的时间线视频特效名字
 *  \return 返回时间线视频特对象
 *  \endif
*/
- (NvsTimelineVideoFx *)addBuiltinTimelineVideoFx:(int64_t)inPoint duration:(int64_t)duration videoFxName:(NSString *)videoFxName;

/*! \if ENGLISH
 *  \brief Add a timeline video effect in the form of a resource package on the timeline.
 *  \param inPoint The in point of the timeline video effect on the timeline (in microseconds)
 *  \param duration  Duration of the timeline video effect which displayed (in microseconds)
 *  \param videoFxPackageId The Id of resource package
 *  \return Return the NvsTimelineVideoFx object
 *  \else
 *  \brief 在时间线上添加资源包形式的时间线视频特效
 *  \param inPoint 时间线视频特效在时间线上的入点（单位微秒）
 *  \param duration 时间线视频特效显示的时长（单位微秒）
 *  \param videoFxPackageId 时间线视频特效资源包Id
 *  \return 返回时间线视频特对象
 *  \endif
*/
- (NvsTimelineVideoFx *)addPackagedTimelineVideoFx:(int64_t)inPoint duration:(int64_t)duration videoFxPackageId:(NSString *)videoFxPackageId;

/*! \if ENGLISH
 *  \brief Add a custom timeline video effect on the timeline
 *  \param inPoint The in point of the timeline video effect on the timeline (in microseconds)
 *  \param duration  Duration of the timeline video effect which displayed (in microseconds)
 *  \param customVideoFxRender User-implemented custom video effects renderer interface
 *  \return Return the NvsTimelineVideoFx object
 *  \else
 *  \brief 在时间线上添加自定义时间线视频特效
 *  \param inPoint 时间线视频特效在时间线上的入点（单位微秒）
 *  \param duration 时间线视频特效的时长（单位微秒）
 *  \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
 *  \return 返回时间线视频对象
 *  \endif
 *  \since 1.7.0
*/
- (NvsTimelineVideoFx *)addCustomTimelineVideoFx:(int64_t)inPoint
                                        duration:(int64_t)duration
                             customVideoFxRender:(id<NvsCustomVideoFxRenderer>)customVideoFxRender;

/*! \if ENGLISH
 *  \brief Remove a timeline video effect from the timeline.
 *  \param videoFx The NvsTimelineVideoFx object which will be removed
 *  \return Returns the next NvsTimelineVideoFx object of current timeline video effect which has removed.
 *  \else
 *  \brief 移除时间线上的时间线视频特效
 *  \param videoFx 要移除的时间线视频特效对象
 *  \return 返回被删除的时间线视频特效的下一个时间线视频特效对象
 *  \endif
*/
- (NvsTimelineVideoFx *)removeTimelineVideoFx:(NvsTimelineVideoFx *)videoFx;

/*! \if ENGLISH
 *  \brief Get the id of the current theme
 *  \return Current theme id, if no theme,returns nil.
 *  \else
 *  \brief 获得当前主题的id
 *  \return 当前主题id，若无主题返回nil。
 *  \endif
 *  \sa applyTheme:
 *  \sa removeCurrentTheme
*/
- (NSString *)getCurrentThemeId;

/*! \if ENGLISH
 *	\brief Apply a theme to the current timeline (the theme is relative to the entire timeline).
 *
 *  For themes, there may be a title or a trailer, or both of them, or none.
 *  When applying a theme with a title or a trailer or both of them are treated as a clip, resulting in an increase in the count of clips. When using this interface, be careful to determine the count of clips.
 *  \param themeId Id of theme package
 *  \return Determine if the theme is applied successfully. If YES is returned, the theme is used successfully, and NO means the oppsite.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *	\brief 对当前时间线应用主题(主题是相对于整个时间线而言)
 *
 *  对于主题，可能包含有片头或片尾，或片头片尾都有，也有可能都没有。应用含有片头或片尾的主题时，片头和片尾都被视作一个clip，从而导致clip数量的增加。使用此接口时请注意判断片段的数量。
 *  \param themeId 主题包裹的id
 *  \return 判断是否应用主题成功。返回YES则主题运用成功，NO则运用失败。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa getCurrentThemeId
 *  \sa removeCurrentTheme
*/
- (BOOL)applyTheme:(NSString *)themeId;

/*! \if ENGLISH
 *  \brief Remove current theme.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 移除当前主题
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa applyTheme:
 *  \sa getCurrentThemeId
*/
- (void)removeCurrentTheme;

/*! \if ENGLISH
 *  \brief Set the caption text for theme title.
 *  \param text The caption text
 *  \else
 *  \brief 设置主题片头字幕文本
 *  \param text 字幕文本
 *  \endif
 *  \sa setThemeTrailerCaptionText:
 *  \sa applyTheme:
*/
- (void)setThemeTitleCaptionText:(NSString *)text;

/*! \if ENGLISH
 *  \brief Set the caption text for theme trailer.
 *  \param text 字幕文本
 *  \else
 *  \brief 设置主题片尾字幕文本
 *  \param text 字幕文本
 *  \endif
 *  \sa setThemeTitleCaptionText:
 *  \sa applyTheme:
*/
- (void)setThemeTrailerCaptionText:(NSString *)text;

/*! \if ENGLISH
 *  \brief Set the volume value for theme music.
 *  \param leftVolumeGain Left channel
 *  \param rightVolumeGain Right channel
 *  \else
 *  \brief 设置主题音乐音量
 *  \param leftVolumeGain 左声道
 *  \param rightVolumeGain 右声道
 *  \endif
 *  \sa getThemeMusicVolumeGain:rightVolumeGain:
*/
- (void)setThemeMusicVolumeGain:(float)leftVolumeGain rightVolumeGain:(float)rightVolumeGain;

/*! \if ENGLISH
 *  \brief Get the volume value for theme music.
 *  \param leftVolumeGain Output the value of left channel
 *  \param rightVolumeGain Output the value of right channel
 *  \else
 *  \brief 获取主题音乐音量
 *  \param leftVolumeGain 输出左声道值
 *  \param rightVolumeGain 输出左声道值
 *  \endif
 *  \sa getThemeMusicVolumeGain:rightVolumeGain:
*/
- (void)getThemeMusicVolumeGain:(float *)leftVolumeGain rightVolumeGain:(float *)rightVolumeGain;

/*! \if ENGLISH
 *  \brief Add watermark.
 *  \param watermarkFilePath The path of the watermark file must be a .PNG or .JPG file.
 *  \param displayWidth The width of the watermark displayed in the timeline. If 0, the width of the image file is used.
 *  \param displayHeight The height of the watermark displayed in the timeline. If 0, the height of the image file is used.
 *  \param opacity Watermark opacity, the range is [0,1]
 *  \param position The position of the watermark, please refer to [NvsTimelineWatermarkPosition] (@ref NvsTimelineWatermarkPosition)
 *  \param marginX The margin of the watermark in the horizontal direction
 *  \param marginY The margin of the watermark in the vertical direction
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 添加水印
 *  \param watermarkFilePath 水印文件的路径，须为PNG或JPG文件
 *  \param displayWidth 水印在timeline中显示的宽度，为0则使用图片文件的宽度
 *  \param displayHeight 水印在timeline中显示的高度，为0则使用图片文件的高度
 *  \param opacity 水印的不透明度, 取值范围 0~1
 *  \param position 水印的位置，请参见 [NvsTimelineWatermarkPosition] (@ref NvsTimelineWatermarkPosition)
 *  \param marginX 水印在X方向的边距
 *  \param marginY 水印在Y方向的边距
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa deleteWatermark:
 *  \sa setWatermarkOpacity:
*/
- (bool)addWatermark:(NSString*)watermarkFilePath displayWidth:(int)displayWidth displayHeight:(int)displayHeight opacity:(float)opacity position:(int)position marginX:(int)marginX marginY:(int)marginY;

/*! \if ENGLISH
 *  \brief Delete watermark which has added.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 删除已添加的水印
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa addWatermark:displayWidth:displayHeight:opacity:position:marginX:marginY:
 *  \sa setWatermarkOpacity:
*/
- (void)deleteWatermark;

/*! \if ENGLISH
 *  \brief Set watermark opacity
 *  \param opacity The opacity, the range is [0,1]
 *  \else
 *  \brief 设置水印不透明度
 *  \param opacity 水印的不透明度, 取值范围 0~1
 *  \endif
 *  \sa addWatermark:
 *  \sa deleteWatermark:
*/
- (bool)setWatermarkOpacity:(float)opacity;

/*! \if ENGLISH
 *  \brief Set the logo effect at the end of the timeline.
 *  \param logoFilePath The path of the logo file must be a .PNG or .JPG file.
 *  \param displayWidth The width of the logo displayed in the timeline. If 0, the width of the image file is used.
 *  \param displayHeight The height of the logo displayed in the timeline. If 0, the height of the image file is used.
 *  \param centerX logo中心点在X方向的位置
 *  \param centerY logo中心点在Y方向的位置
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 设置timeline结尾的Logo特效
 *  \param logoFilePath logo文件的路径，须为PNG或JPG文件
 *  \param displayWidth logo在timeline中显示的宽度，为0则使用图片文件的宽度
 *  \param displayHeight logo在timeline中显示的高度，为0则使用图片文件的高度
 *  \param centerX logo中心点在X方向的位置
 *  \param centerY logo中心点在Y方向的位置
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa removeTimelineEndingLogo:
*/
- (bool)setTimelineEndingLogo:(NSString*)logoFilePath displayWidth:(unsigned int)displayWidth displayHeight:(unsigned int)displayHeight centerX:(int)centerX centerY:(int)centerY;

/*! \if ENGLISH
 *  \brief  Remove the logo effect at the end of the timeline.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 移除已添加的timeline结尾的logo特效
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa setTimelineEndingLogo:displayWidth:displayHeight:centerX:centerY:
*/
- (void)removeTimelineEndingLogo;

- (void)setPlaybackRateControl:(NSArray *) arrayPlaybackRateControlRegion;

- (NSArray *)getPlaybackRateControl;

@end

