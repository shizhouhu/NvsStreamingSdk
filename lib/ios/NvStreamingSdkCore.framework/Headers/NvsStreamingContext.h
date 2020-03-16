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

#import <Foundation/Foundation.h>
#import "NvsTimeline.h"
#import "NvsAssetPackageManager.h"
#import "NvsAVFileInfo.h"
#import "NvsVideoFrameRetriever.h"
#import "NvsVideoFrameReceiver.h"
#import "NvsCustomVideoFx.h"
#import "NvsCommonDef.h"


/*! \if ENGLISH
 *  \brief Streaming context creation flag
 *  \else
 *  \brief 流媒体上下文创建标志
 *  \endif
*/
typedef enum {
    NvsStreamingContextFlag_Support4KEdit = 1,        //!< \if ENGLISH Supports up to 4K video editing. \else 支持4K视频编辑 \endif
    NvsStreamingContextFlag_Support8KEdit = 4,        //!< \if ENGLISH Supports up to 8K (images only). \else 支持8K编辑(仅图片) \endif
    NvsStreamingContextFlag_AsyncEngineState = 16     //!< \if ENGLISH Asynchronous engine \else 引擎状态切换使用异步方式以便减少主线程的卡顿 \endif
} NvsStreamingContextFlag;

/*! \if ENGLISH
 *  \brief Clear cache flags
 *  \else
 *  \brief 清理缓存标志
 *  \endif
*/
typedef enum {
    NvsClearCacheFlag_StreamingEngine = 1,          //!< \if ENGLISH Cache of streaming engine \else 流媒体引擎的缓存 \endif
    NvsClearCacheFlag_IconEngine = 2,               //!< \if ENGLISH Cache of icon engine \else 缩略图的缓存 \endif
    NvsClearCacheFlag_WaveformEngine = 4,           //!< \if ENGLISH Cache of waveform engine \else 音频波形的缓存 \endif
    NvsClearCacheFlag_AVFileInfo = 8,               //!< \if ENGLISH Cache of avfile infors \else 视音频文件信息的缓存 \endif
    NvsClearCacheFlag_CaptionFontInfo = 16          //!< \if ENGLISH Cache of font infos \else 字幕字体信息的缓存 \endif
} NvsClearCacheFlag;


/*! \if ENGLISH
 *  \brief Resolution level for compiling video (define video resolution at time of createTimeline. Automatically defining rendering video width in according to output video height).
 *  \else
 *  \brief 生成视频文件的分辨率高度级别(创建时间线(createTimeline)时指定视频的宽高和横纵比，根据输出的视频分辨率高度算出生成视频文件的宽度)
 *  \endif
*/
typedef enum {
    NvsCompileVideoResolutionGrade360 = 0,                //!< \if ENGLISH Output height: 360 pixel \else 输出高度360像素 \endif
    NvsCompileVideoResolutionGrade480,                    //!< \if ENGLISH Output height: 480 pixel\else 输出高度480像素 \endif
    NvsCompileVideoResolutionGrade720,                    //!< \if ENGLISH Output height: 720 pixel\else 输出高度720像素 \endif
    NvsCompileVideoResolutionGrade1080,                   //!< \if ENGLISH Output height: 1080 pixel\else 输出高度1080像素 \endif
    NvsCompileVideoResolutionGrade2160,                   //!< \if ENGLISH Output height: 2160 pixel\else 输出高度2160像素 \endif
    NvsCompileVideoResolutionGradeCustom = 256            //!< \if ENGLISH Custom height\else 自定义生成视频高度 \endif
} NvsCompileVideoResolutionGrade;

/*! \if ENGLISH
 *  \brief The bitrate level of compiling the video file.
 *  \else
 *  \brief 生成视频文件的码率级别
 *  \endif
*/
typedef enum {
    NvsCompileBitrateGradeLow = 0,          //!< \if ENGLISH Low bitrate \else 低码率 \endif
    NvsCompileBitrateGradeMedium,           //!< \if ENGLISH Medium bitrate \else 中等码率 \endif
    NvsCompileBitrateGradeHigh              //!< \if ENGLISH High bitrate \else 高码率 \endif
} NvsCompileVideoBitrateGrade;

/*! \if ENGLISH
 *  \brief Flag of compiling video
 *  \else
 *  \brief 生成视频文件标志
 *  \endif
*/
typedef enum {
    NvsStreamingEngineCompileFlag_None = 0,          //!< \if ENGLISH None. \else 没有任何特殊标识 \endif
    NvsStreamingEngineCompileFlag_DisableHardwareEncoder = 1, //!< \if ENGLISH Disables the hardware encoder \else 禁用硬件编码器 \endif
    NvsStreamingEngineCompileFlag_OnlyVideo = 4,     //!< \if ENGLISH Compile the video file only. \else 仅生产只有视频流的文件 \endif
    NvsStreamingEngineCompileFlag_OnlyAudio = 8,      //!< \if ENGLISH Compile the audio file only. \else 仅生产只有音频流的文件 \endif
    NvsStreamingEngineCompileFlag_BuddyHostVideoFrame = 32      //!< \if ENGLISH Buddy video frame in host. \else 伴侣视频帧 \endif
} NvsStreamingEngineCompileFlag;


/*! \if ENGLISH
 *  \brief Mode of preview video.
 *  \else
 *  \brief 视频预览模式
 *  \endif
*/
typedef enum {
    NvsVideoPreviewSizeModeFullSize = 0,     //!< \if ENGLISH Preview in full size. \else 全屏预览 \endif
    NvsVideoPreviewSizeModeLiveWindowSize    //!< \if ENGLISH Preview in controll of "liveWindow" \else liveWindow预览 \endif
} NvsVideoPreviewSizeMode;

/*! \if ENGLISH
 *  \brief Resolution level for capturing video
 *  \else
 *  \brief 视频采集分辨率级别
 *  \endif
*/
typedef enum {
    NvsVideoCaptureResolutionGradeLow = 0,              //!< \if ENGLISH Low resolution \else 低分辨率 \endif
    NvsVideoCaptureResolutionGradeMedium,               //!< \if ENGLISH Medium resolution \else 中等分辨率 \endif
    NvsVideoCaptureResolutionGradeHigh,                 //!< \if ENGLISH High resolution \else 高分辨率 \endif
    NvsVideoCaptureResolutionGradeSupperHigh,           //!< \if ENGLISH Super high resolution \else 超高分辨率 \endif
} NvsVideoCaptureResolutionGrade;

/*! \if ENGLISH
 *  \brief Streaming engine status
 *  \else
 *  \brief 流媒体引擎状态
 *  \endif
*/
typedef enum {
    NvsStreamingEngineState_Stopped = 0,      //!< \if ENGLISH Engine stopped \else 引擎停止 \endif
    NvsStreamingEngineState_CapturePreview,   //!< \if ENGLISH Capturing preview \else 采集预览 \endif
    NvsStreamingEngineState_CaptureRecording, //!< \if ENGLISH Recording \else 采集录制 \endif
    NvsStreamingEngineState_Playback,         //!< \if ENGLISH Playback \else 播放 \endif
    NvsStreamingEngineState_Seeking,          //!< \if ENGLISH Seeking \else 定位 \endif
    NvsStreamingEngineState_Compile           //!< \if ENGLISH Compiling \else 生成 \endif
} NvsStreamingEngineState;

/*! \if ENGLISH
 *  \brief Flag of capturing
 *  \else
 *  \brief 采集标志
 *  \endif
*/
typedef enum
{
    NvsStreamingEngineCaptureFlag_GrabCapturedVideoFrame = 1,       //!< \if ENGLISH Gets the capture frame content(this operation may reduce performance, use it only when needed).\else 获取采集视频的帧内容（打开这个标志会降低性能，只有在必要的时候开启这个标志）\endif
    NvsStreamingEngineCaptureFlag_StrictPreviewVideoSize = 8,       //!< \if ENGLISH Preview video size within system-defined size. \else 限定预览视频尺寸只能是系统自带的预览视频尺寸 \endif
    NvsStreamingEngineCaptureFlag_DontCaptureAudio = 16,            //!< \if ENGLISH No audio capturing. \else 不采集音频 \endif
    NvsStreamingEngineCaptureFlag_CaptureBuddyHostVideoFrame = 32,  //!< \if ENGLISH Captures buddy video frames. \else 采集伴侣视频帧 \endif
    NvsStreamingEngineCaptureFlag_IgnoreScreenOrientation = 64,     //!< \if ENGLISH Does not apply screen coordinate for defining rotation angle of captured video. \else 不使用屏幕方向来确定采集画面的旋转角度 \endif \since 1.15.2
    NvsStreamingEngineCaptureFlag_AutoVideoStabilization = 128,     //!< \if ENGLISH Enables auto video stabilization. \else 启用视频防抖动 \endif \since 1.16.1
    NvsStreamingEngineCaptureFlag_FaceActionWithParticle = 256,     //!< \if ENGLISH Uses facial action to control particle effects. \else 使用脸部动作控制粒子特效 \endif \since 2.1.0
    NvsStreamingEngineCaptureFlag_DontAutomaticallyConfiguresApplicationAudioSession = 1024  //!< \if ENGLISH Does not apply automatically configures application audiosession . \else 不使用自动配置AudioSession \endif \since 2.12.0
} NvsStreamingEngineCaptureFlag;

/*! \if ENGLISH
 *  \brief Enters the image rotation angle of the buffer.
 *  \else
 *  \brief 输入buffer的图像旋转角度
 *  \endif
*/
typedef enum
{
    BufferImageRotation_0 = 0,
    BufferImageRotation_90 = 1,
    BufferImageRotation_180 = 2,
    BufferImageRotation_270 = 3,
} BufferImageRotation;

/*! \if ENGLISH
 *  \brief Stabilization flag
 *  \else
 *  \brief 防抖动标志
 *  \endif
*/
typedef enum
{
    VideoStabilizationFlag_Off = 0,          //!< \if ENGLISH  Video stabilization mode is off. \else  视频防抖动模式关闭 \endif
    VideoStabilizationFlag_Auto = 1,         //!< \if ENGLISH  Video stabilization automatic mode. \else  视频防抖自动模式 \endif
    VideoStabilizationFlag_Standard = 2,     //!< \if ENGLISH  Video standard stabilization. \else  视频防抖自动模式 \endif
    VideoStabilizationFlag_Super = 3,        //!< \if ENGLISH  Video stabilization movie mode. \else  视频防抖电影模式 \endif
} VideoStabilizationFlag;

/*! \if ENGLISH
 *  \brief Flag of Recording
 *  \else
 *  \brief 录制标志
 *  \endif
*/
typedef enum
{
    NvsStreamingEngineRecordingFlag_VideoIntraFrameOnly = 2,  //!< \if ENGLISH Records a video file containing I-Frame only. \else 录制仅包含I-Frame的视频文件 \endif
    NvsStreamingEngineRecordingFlag_OnlyRecordVideo = 16,     //!< \if ENGLISH Records only video stream. \else 仅录制视频流 \endif
    NvsStreamingEngineRecordingFlag_IgnoreVideoRotation = 32  //!< \if ENGLISH Ignores video device rotation while recording. Remark：it has only effects when using the method of "startRecordingWithFx:". \else 录制时不根据设备的手持方向对视频做旋转。注意：必须用startRecordingWithFx进行录制才有效果 \endif
} NvsStreamingEngineRecordingFlag;

/*! \if ENGLISH
 *  \brief Flag of seeking engine
 *  \else
 *  \brief 引擎定位标识
 *  \endif
*/
typedef enum {
    NvsStreamingEngineSeekFlag_ShowCaptionPoster = 2,          //!< \if ENGLISH Shows entire caption. \else 整体展示字幕效果 \endif
    NvsStreamingEngineSeekFlag_ShowAnimatedStickerPoster = 4,  //!< \if ENGLISH Shows entire animated sticker. \else 整体展示动画贴纸效果 \endif
    NvsStreamingEngineSeekFlag_BuddyHostVideoFrame = 16        //!< \if ENGLISH Buddy video frame in host. \else 伴侣视频帧 \endif
} NvsStreamingEngineSeekFlag;

/*! \if ENGLISH
 *  \brief Flag of playing engine
 *  \else
 *  \brief 引擎播放标志
 *  \endif
*/
typedef enum {
    NvsStreamingEnginePlaybackFlag_LowPipelineSize = 8,               //!< \if ENGLISH Reduces the internal pipeline size of the engine during playback. \else 降低引擎在播放时内部的流水线尺寸 \endif
    NvsStreamingEnginePlaybackFlag_DisableFixedPrerollTime = 16,      //!< \if ENGLISH Reduces the engine's playback delay of the first frame during playback. \else 降低引擎在播放时首帧的播出延迟 \endif
    NvsStreamingEnginePlaybackFlag_BuddyHostVideoFrame = 32           //!< \if ENGLISH Buddy video frame in host. \else 伴侣视频帧 \endif
} NvsStreamingEnginePlaybackFlag;

/*! \if ENGLISH
 *  \brief Flag of stoppoing engine stopp
 *  \else
 *  \brief 停止引擎标志
 *  \endif
*/
typedef enum {
    NvsStreamingEngineStopFlag_Async = 2    //!< \if ENGLISH Stops the engine asynchronously, and avoids blocking the main thread. \else 异步停止引擎，避免阻塞主线程 \endif
} NvsStreamingEngineStopFlag;

/*! \if ENGLISH
 *  \brief Flag of human detection
 *  \else
 *  \brief 人体检测特征标志
 *  \endif
*/
typedef enum {
    NvsHumanDetectionFeature_FaceLandmark = 1,
    NvsHumanDetectionFeature_FaceAction = 2,
    NvsHumanDetectionFeature_AvatarExpression = 4,
    NvsHumanDetectionFeature_VideoMode = 8,
    NvsHumanDetectionFeature_ImageMode = 16,
    NvsHumanDetectionFeature_MultiThread = 32,
    NvsHumanDetectionFeature_SingleThread = 64,
    NvsHumanDetectionFeature_Extra = 128
} NvsHumanDetectionFeatureFlag;

/*! \if ENGLISH
 *  \brief Type of human detection data package
 *  \else
 *  \brief 人体检测数据包类型
 *  \endif
*/
typedef enum {
    NvsHumanDetectionDataType_FakeFace = 0
} NvsHumanDetectionDataTypeFlag;

/*! \anchor RECORD_CONFIGURATIONS */
/*!
 *  \if ENGLISH
 *   @name Configuration of recording video
 *  \else
 *   @name 录制视频配置
 *  \endif
*/
//!@{
#define NVS_RECORD_BITRATE        @"bitrate"			//!< \if ENGLISH Video bitrate \else 录制视频码率 \endif
#define NVS_RECORD_GOP_SIZE       @"gopsize"            //!< \if ENGLISH Video GOP size \else 录制视频GOP SIZE \endif
//!@}

/*! \anchor COMPILE_CONFIGURATIONS */
/*!
 *  \if ENGLISH
 *   @name Configuration of Compilation Timeline
 *  \else
 *   @name 生成时间线的配置
 *  \endif
*/
//!@{
#define NVS_COMPILE_BITRATE                     @"bitrate"                         //!< \if ENGLISH Bitrate for compiling video \else 生成视频码率 \endif
#define NVS_COMPILE_GOP_SIZE                    @"gopsize"                         //!< \if ENGLISH GOP SIZE for compiling video \else 生成视频GOP SIZE \endif
#define NVS_COMPILE_AUDIO_BITRATE               @"audio bitrate"                   //!< \if ENGLISH Bitrate for compiling audio\else 生成音频码率 \endif
#define NVS_COMPILE_LOSSLESS_AUDIO              @"lossless audio"                  //!< \if ENGLISH Whether to generate lossless audio. \else 是否生成无损音频 \endif
#define NVS_COMPILE_OPTIMIZE_FOR_NETWORK_USE    @"optimize-for-network-use"        //!< \if ENGLISH Whether to optimize for network use. \else 是否前置索引表 \endif
#define NVS_COMPILE_VIDEO_ENCODEC_NAME          @"video encoder name"              //!< \if ENGLISH Specifies the video compression format, currently it supports hevc（h.265). \else 指定视频压缩格式，目前支持hevc（h.265） \endif
#define NVS_COMPILE_AUDIO_ENCODEC_NAME          @"audio encoder name"              //!< \if ENGLISH Specifies the audio compression format, currently it supports amr-wb. \else 指定视频压缩格式，目前支持amr-wb \endif
#define NVS_COMPILE_VIDEO_FPS                   @"fps"                             //!< \if ENGLISH frames per second when compiling \else 生成的帧速率 \endif
//!@}


/*! \if ENGLISH
 *  \brief Special identifier when acquiring audio and video information.
 *  \else
 *  \brief 获取音视频信息时的特殊标识
 *  \endif
*/
typedef enum {
    NvsAVFileinfoExtra_None = 0,          //!< \if ENGLISH Default. \else 默认值 \endif
    NvsAVFileinfoExtra_AVPixelFormat      //!< \if ENGLISH Gets AVPixelFormat. \else 获取AVPixelFormat \endif
} NvsAVFileinfoExtraFlag;

@class NvsCaptureDeviceCapability;
@class NvsCaptureVideoFx;
@class NvsFxDescription;
@class NvsCaptureDeviceCapability;
@class NvsCaptureVideoFx;
@class NvsFxDescription;

@protocol NvsStreamingContextDelegate <NSObject>
@optional


/*! \if ENGLISH
 *  \brief The captured device is ready.
 *  \param captureDeviceIndex Device index
 *  \else
 *  \brief 采集设备准备完成
 *  \param captureDeviceIndex 设备索引
 *  \endif
*/
- (void)didCaptureDeviceCapsReady:(unsigned int)captureDeviceIndex;

/*! \if ENGLISH
 *  \brief Captured device resolution is ready.
 *  \param captureDeviceIndex Device index
 *  \else
 *  \brief 采集设备预览解析度准备完成
 *  \param captureDeviceIndex 设备索引
 *  \endif
*/
- (void)didCaptureDevicePreviewResolutionReady:(unsigned int)captureDeviceIndex;

/*! \if ENGLISH
 *  \brief Startes the captured device preview.
 *  \param captureDeviceIndex Device index
 *  \else
 *  \brief 采集设备预览开始
 *  \param captureDeviceIndex 设备索引
 *  \endif
*/
- (void)didCaptureDevicePreviewStarted:(unsigned int)captureDeviceIndex;

/*! \if ENGLISH
 *  \brief Capture device error.
 *  \param captureDeviceIndex Device index
 *  \param errorCode Error code
 *  \else
 *  \brief 采集设备错误
 *  \param captureDeviceIndex 设备索引
 *  \param errorCode 错误码
 *  \endif
*/
- (void)didCaptureDeviceError:(unsigned int)captureDeviceIndex errorCode:(int32_t)errorCode;

/*! \if ENGLISH
 *  \brief Stopps  the captured device
 *  \param captureDeviceIndex Device index
 *  \else
 *  \brief 采集设备停止
 *  \param captureDeviceIndex 设备索引
 *  \endif
*/
- (void)didCaptureDeviceStopped:(unsigned int)captureDeviceIndex;

/*! \if ENGLISH
 *  \brief The captured device's autofocus is completed.
 *  \param captureDeviceIndex Device index
 *  \param succeeded Whether the autofocus is completed.
 *  \else
 *  \brief 采集设备自动对焦完成
 *  \param captureDeviceIndex 设备索引
 *  \param succeeded 对焦是否完成
 *  \endif
*/
- (void)didCaptureDeviceAutoFocusComplete:(unsigned int)captureDeviceIndex succeeded:(BOOL)succeeded;

/*! \if ENGLISH
 *  \brief Recording started.
 *  \param captureDeviceIndex Device index
 *  \else
 *  \brief 采集录制开始
 *  \param captureDeviceIndex 设备索引
 *  \endif
 *  \sa didCaptureRecordingFinished:
 *  \sa didCaptureRecordingError:
 *  \since 1.16.0
*/
- (void)didCaptureRecordingStarted:(unsigned int)captureDeviceIndex;

/*! \if ENGLISH
 *  \brief Notification of recording's duration.
 *  \param captureDeviceIndex Device index
 *  \param duration The duration that has been recorded (in microseconds).
 *  \else
 *  \brief 录制时长通知
 *  \param captureDeviceIndex 设备索引
 *  \param duration 已经录制的时长，单位是微秒
 *  \endif
 *  \since 1.17.0
*/
- (void)didCaptureRecordingDurationUpdated:(int)captureDeviceIndex duration:(int64_t)duration;

/*! \if ENGLISH
 *  \brief Recording is completed.
 *  \param captureDeviceIndex Device index
 *  \else
 *  \brief 采集录制完成
 *  \param captureDeviceIndex 设备索引
 *  \endif
 *  \sa didCaptureRecordingStarted:
 *  \sa didCaptureRecordingError:
*/
- (void)didCaptureRecordingFinished:(unsigned int)captureDeviceIndex;

/*! \if ENGLISH
 *  \brief Recording fails.
 *  \param captureDeviceIndex Device index
 *  \else
 *  \brief 采集录制失败
 *  \param captureDeviceIndex 设备索引
 *  \endif
 *  \sa didCaptureRecordingStarted:
 *  \sa didCaptureRecordingFinished:
*/
- (void)didCaptureRecordingError:(unsigned int)captureDeviceIndex;

/*! \if ENGLISH
 *  \brief Playback preload completed.
 *  \param timeline Timeline
 *  \else
 *  \brief 播放预先加载完成
 *  \param timeline 时间线
 *  \endif
*/
- (void)didPlaybackPreloadingCompletion:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Current position of timeline playback.
 *  \param timeline Timeline
 *  \param position Current position
 *  \else
 *  \brief 时间线播放的当前位置
 *  \param timeline 时间线
 *  \param position 当前位置
 *  \endif
 *  \since 1.6.0
*/
- (void)didPlaybackTimelinePosition:(NvsTimeline *)timeline position:(int64_t)position;

/*! \if ENGLISH
 *  \brief Timeline playback delay.
 *  \param timeline Timeline
 *  \param time Delay time
 *  \param flag Whether it's video (true is video, false is audio).
 *  \else
 *  \brief 时间线播放视频延迟
 *  \param timeline 时间线
 *  \param time 延迟时间
 *  \param flag 是否是视频（true是视频，false是音频）
 *  \endif
 *  \since 2.5.0
*/
- (void)didPlaybackDelayed:(NvsTimeline *)timeline delayTime:(int64_t)time isVideo:(bool)flag;

/*! \if ENGLISH
 *  \brief Playback stopped.
 *  \param timeline Timeline
 *  \else
 *  \brief 播放停止
 *  \param timeline 时间线
 *  \endif
*/
- (void)didPlaybackStopped:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Playbacks to the end.
 *  \param timeline Timeline
 *  \else
 *  \brief 播放到结尾
 *  \param timeline 时间线
 *  \endif
*/
- (void)didPlaybackEOF:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Progress of compiling video file.
 *  \param timeline Timeline
 *  \param progress Progress
 *  \else
 *  \brief 生成视频文件进度
 *  \param timeline 时间线
 *  \param progress 进度值
 *  \endif
*/
- (void)didCompileProgress:(NvsTimeline *)timeline progress:(int)progress;

/*! \if ENGLISH
 *  \brief Progress of compiling video file.
 *  \param timeline Timeline
 *  \param progress float Progress
 *  \else
 *  \brief 生成视频文件进度
 *  \param timeline 时间线
 *  \param progress 浮点进度值
 *  \endif
*/
- (void)didCompileFloatProgress:(NvsTimeline *)timeline progress:(float)progress;

/*! \if ENGLISH
 *  \brief Compiling video file is completed.
 *  \param timeline Timeline
 *  \else
 *  \brief 生成视频文件完成
 *  \param timeline 时间线
 *  \endif
 *  \sa didCompileFailed:
*/
- (void)didCompileFinished:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Compiling video file is completed.
 *  \param timeline Timeline
 *  \param isCanceled The midway cancellation results in the completion of the compile. Note: any operations on the engine that causes compilation to stop are refer to as cancelation.
 *  \else
 *  \brief 生成视频文件完成
 *  \param timeline 时间线
 *  \param isCanceled 中途取消导致生成完成。注：任何对引擎操作引起的停止生成均视为中途取消
 *  \endif
 *  \since 1.6.0
 *  \sa didCompileFinished:
*/
- (void)didCompileCompleted:(NvsTimeline *)timeline isCanceled:(BOOL)isCanceled;

/*! \if ENGLISH
 *  \brief Fails to compile video file.
 *  \param timeline Timeline
 *  \else
 *  \brief 生成视频文件失败
 *  \param timeline 时间线
 *  \endif
*/
- (void)didCompileFailed:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Engine state changed.
 *  \param state Engine state
 *  \else
 *  \brief 引擎状态改变
 *  \param state 引擎状态
 *  \endif
*/
- (void)didStreamingEngineStateChanged:(NvsStreamingEngineState)state;

/*! \if ENGLISH
 *  \brief First video frame is presented.
 *  \param timeline Timeline
 *  \else
 *  \brief 第一视频帧呈现
 *  \param timeline 时间线
 *  \endif
*/
- (void)didFirstVideoFramePresented:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Timeline out of bounds (Note: Do not use this callback interface if it is not necessary).
 *  \param timeline Timeline
 *  \else
 *  \brief 时间线越界（注：非必要情况请勿使用此回调接口）
 *  \param timeline 时间线
 *  \endif
 *  \since 1.2.0
*/
- (void)didTimestampOutOfRange:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Current position of seeking the timeline
 *  \param timeline Timeline
 *  \param position Current position
 *  \else
 *  \brief 时间线搜索的当前位置
 *  \param timeline 时间线
 *  \param position 当前位置
 *  \endif
 *  \since 2.5.0
*/
- (void)didSeekingTimelinePosition:(NvsTimeline *)timeline position:(int64_t)position;

/*! \if ENGLISH
 *  \brief Gets the captured video frame.
 *
 *  Please pay attention: this function is called in a separate thread, not in the UI thread. Please consider thread-safe issues!!
 *  \param sampleBufferInfo The obtained image data
 *  \else
 *  \brief 获取采集预览图像
 *
 *  请特别注意:这个函数被调用是在一个单独的线程,而不是在UI线程.使用请考虑线程安全的问题!!!
 *  \param sampleBufferInfo 获取到的图像数据
 *  \endif
 *  \since 1.4.0
*/
- (void)captureVideoFrameGrabbedArrived:(NvsVideoFrameInfo*)sampleBufferInfo;

@end

/*! \if ENGLISH
 *  \brief Streaming context.
 *
 *  The streaming context class is considered as the entry of the entire SDK framework. During development, the NvsStreamingContext class uses the static sharedInstance() interface to create an unique streaming context instance.
 *  Through this instantce object, we can turn on the recording device to record videos, adding effects to recorded videos, set various parameters for recording, which include autofocus, automatic exposure adjustment, swtiching on/off of the light supplement and so on.
 *  Meanwhile, this instance can also create timelines, connecting timelines to the real-time preview window which view the recorded videos in real-time. When the whole video has been produced completely, please destroy the instances of streaming context.
 *  When recording with special effects,users have to first install the package and obtain packageID after installation,before adding resources packages (recording effects package, scene resources package and so on),. For built-in special effects, users only need to obtain the name of the effect when using it.
 *  <br>In SDK interfaces, users need to use the full pathway when importing resources or authorizations.
 *  \warning For NvsStreamingContext class, all public APIs must be used in the UI thread except getAVFileInfo(), detectVideoFileKeyframeInterval(),createVideoFrameRetriever(), which can be used across threads.
 *  \else
 *  \brief 流媒体上下文
 *
 *  流媒体上下文类可视作整个SDK框架的入口。开发过程中，NvsStreamingContext类提供了静态sharedInstance()接口创建流上下文的唯一实例。
 *  通过这个实例对象，我们可以开启采集设备录制视频，添加采集视频特效，设置拍摄时的各项参数，包括自动聚焦，自动曝光调节，开关换补光灯等。
 *  同时，还能够创建时间线，并将时间线与实时预览窗口(Live Window)连接起来，实时预览播放已经拍摄完成的视频。整个视频制作完成后，要销毁流媒体上下文的对象实例。
 *  带特效拍摄时，添加素材资源包(采集特效包，场景资源包等)，都得先安装，安装成功后获取packageId才能使用，而内建采集特效(builtin)只需获取特效名称即可使用。
 *  <br>sdk接口中凡是需要传入资源、授权等文件路径时一定是全路径。
 *  \warning NvsStreamingContext类中，所有public API除了getAVFileInfo，detectVideoFileKeyframeInterval，createVideoFrameRetriever可以跨线程使用，其他都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsStreamingContext : NSObject

@property (nonatomic, weak) id<NvsStreamingContextDelegate> delegate;
@property (readonly) NvsAssetPackageManager *assetPackageManager;       //!< \if ENGLISH Package manager \else 包管理器 \endif
@property (nonatomic) float compileVideoBitrateMultiplier;              //!< \if ENGLISH Bitrate multiplier of compiling video. \else 生成视频码率倍乘系数 \endif \since 1.5.0
@property (nonatomic) float recordVideoBitrateMultiplier;               //!< \if ENGLISH Bitrate multiplier of recording video. \else 录制视频码率倍乘系数 \endif \since 1.5.0
@property (nonatomic) BOOL defaultCaptionFade;                          //!< \if ENGLISH Whether the default caption effect is fade in and out. \else 默认字幕是否为淡入淡出 \endif \since 1.8.0

/*! \if ENGLISH
 *  \brief Sets the timeline configurations, which stay valid once set. For key values in NSMutableDictionary, please refer to [Configuration of Compilation Timeline](@ref COMPILE_CONFIGURATIONS)
 *         For instance: NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_COMPILE_GOP_SIZE]; //If set to 1 then a I-frame-only video is compiled.
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_COMPILE_BITRATE]; // 10M bps
 *              [config setValue:[NSNumber numberWithInteger:256000] forKey:NVS_COMPILE_AUDIO_BITRATE]; // Sets the audio bitrate to 256Kbps
 *              [config setValue:[NSNumber numberWithBool:YES] forKey:NVS_COMPILE_LOSSLESS_AUDIO]; //Sets to generate lossless audio
 *              [config setValue:[NSNumber numberWithBool:YES] forKey:NVS_COMPILE_OPTIMIZE_FOR_NETWORK_USE]; //Sets index table to prepose
 *              _streamingContext.compileConfigurations = config;
 *         Cancels configurations and returns to default settings:[_streamingContext.compileConfigurations setValue:nil forKey:NVS_COMPILE_GOP_SIZE];
 *  \else
 *  \brief 生成时间线配置，设置一次即一直生效。NSMutableDictionary中关键字的值请参见 [生成时间线的配置] (@ref COMPILE_CONFIGURATIONS)
 *         例如：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_COMPILE_GOP_SIZE]; // 设置为1即是生成全I帧视频
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_COMPILE_BITRATE]; // 10M bps
 *              [config setValue:[NSNumber numberWithInteger:256000] forKey:NVS_COMPILE_AUDIO_BITRATE]; // 设置音频码率为256Kbps
 *              [config setValue:[NSNumber numberWithBool:YES] forKey:NVS_COMPILE_LOSSLESS_AUDIO]; // 设置生成无损音频
 *              [config setValue:[NSNumber numberWithBool:YES] forKey:NVS_COMPILE_OPTIMIZE_FOR_NETWORK_USE]; // 设置索引表前置
 *              NvsRational videoFps = {12, 1};
 *              [config setValue:[NSData dataWithBytes:&videoFps length:sizeof(NvsRational)] forKey:NVS_COMPILE_VIDEO_FPS]; // 设置帧速率FPS
 *              _streamingContext.compileConfigurations = config;
 *         取消设置并恢复默认方式例如：[_streamingContext.compileConfigurations setValue:nil forKey:NVS_COMPILE_GOP_SIZE];
 *  \endif
 *  \since 1.8.0
*/
@property (nonatomic) NSMutableDictionary *compileConfigurations;

/*! \if ENGLISH
 *  \brief Gets the version information of Meishe SDK
 *  \param majorVersion Major version number
 *  \param minorVersion Minor version number
 *  \param revisionNumber Revision number
 *  \else
 *  \brief 获取美摄SDK的版本信息
 *  \param majorVersion 主版本号
 *  \param minorVersion 次版本号
 *  \param revisionNumber 修订版本号
 *  \endif
 *  \since 1.4.1
*/
+ (void)getSdkVersion:(int *)majorVersion minorVersion:(int *)minorVersion revisionNumber:(int *)revisionNumber;

/*! \if ENGLISH
 *  \brief Sets whether to write debugging information of the SDK to the file.
 *  \param saveDebugMessagesToFile Whether to write debugging information of the SDK to the file.
 *  \else
 *  \brief 设置是否将SDK的调试信息写入到文件中
 *  \param saveDebugMessagesToFile 是否将SDK的调试信息写入到文件中
 *  \endif
 *  \since 1.17.0
*/
+ (void)setSaveDebugMessagesToFile:(BOOL)saveDebugMessagesToFile;

/*! \if ENGLISH
 *  \brief Verifies the SDK license file. Note: The license file interface must be called before the NvsStreamingContext is initialized.
 *  \param sdkLicenseFilePath Path of SDK license file
 *  \return Returns the BOOL value. YES indicates that the authorization verification is successful, and NO indicates that it fails. If the verification fails, a subsequent watermark will appear in the video preview and the compiled video.
 *  \else
 *  \brief 验证SDK授权文件。注意：授权文件接口必须在NvsStreamingContext初始化之前调用。
 *  \param sdkLicenseFilePath SDK授权文件路径
 *  \return 返回BOOL值。YES表示授权验证成功，NO则验证失败。若验证失败，则后续的视频预览和生成视频会出现水印。
 *  \endif
*/
+ (BOOL)verifySdkLicenseFile:(NSString *)sdkLicenseFilePath;

/*! \if ENGLISH
 *  \brief Gets a unique instance of the streaming context.
 *  \return Returns an object instance of the streaming context.
 *  \else
 *  \brief 获取流媒体上下文的唯一实例
 *  \return 返回流媒体上下文的对象实例
 *  \endif
 *  \sa destroyInstance
*/
+ (NvsStreamingContext *)sharedInstance;

/*! \if ENGLISH
 *  \brief Gets a unique instance of the streaming context. For details, please refer to [4k Video Editing](@ref support4kVideoEdit.md).
 *  \param flags Flag field. If there is no special requirement, please fill in 0.
 *  \return Returns the NvsStreamingContext object.
 *  \else
 *  \brief 获取流媒体上下文的唯一实例。详细了解参见[4k视频编辑专题] (@ref support4kVideoEdit.md)
 *  \param flags 标志字段，如无特殊需求请填写0。
 *  \return 返回流媒体上下文的对象实例
 *  \endif
 *  \since 1.5.0
 *  \sa destroyInstance
 *
*/
+ (NvsStreamingContext *)sharedInstanceWithFlags:(NvsStreamingContextFlag)flags;

/*! \if ENGLISH
 *  \brief Destroys the streaming context instance.
 *  \else
 *  \brief 销毁流媒体上下文实例。
 *  \endif
 *  \sa sharedInstance
*/
+ (void)destroyInstance;

/*! \if ENGLISH
 *  \brief Checks if the current SDK contains an AR module.
 *  \return The return value of 0 means no AR module, and greater than 0 means that the AR module is included.
 *  \else
 *  \brief 检测当前SDK是否含有AR模块
 *  \return 返回值0表示不含有AR模块，大于0表示含有AR模块
 *  \endif
 *  \since 2.5.0
*/
+ (int)hasARModule;

/*! \if ENGLISH
 *  \brief Initializes the human body detection mechanism.
 *  \param modelFilePath Path of the model file
 *  \param licenseFilePath Path of the license file
 *  \param features human detection flag field. Please refer to [Flag of human detection](@ref NvsHumanDetectionFeatureFlag).
 *  \else
 *  \brief 初始化人体检测机制
 *  \param modelFilePath 人脸模型文件路径
 *  \param licenseFilePath 授权文件路径
 *  \param features 人体检测特征标志字段。请参见[人体检测特征标志](@ref NvsHumanDetectionFeatureFlag)
 *  \endif
 *  \since 2.5.0
*/
+ (BOOL)initHumanDetection:(NSString *)modelFilePath
           licenseFilePath:(NSString *)licenseFilePath
                  features:(int)features;

/*! \if ENGLISH
 *  \brief Human detection initialization extension.
 *  \param modelFilePath Path of the model file
 *  \param licenseFilePath Path of the license file
 *  \param features human detection flag field. Please refer to [Flag of human detection](@ref NvsHumanDetectionFeatureFlag).
 *  \else
 *  \brief 初始化人体检测机制
 *  \param modelFilePath 人脸模型文件路径
 *  \param licenseFilePath 授权文件路径
 *  \param features 人体检测特征标志字段。请参见[人体检测特征标志](@ref NvsHumanDetectionFeatureFlag)
 *  \endif
 *  \since 2.5.0
*/
+ (BOOL)initHumanDetectionExt:(NSString *)modelFilePath
              licenseFilePath:(NSString *)licenseFilePath
                     features:(int)features;

/*! \if ENGLISH
 *  \brief Initializes human detection data packets
 *  \param dataType Type of human detection packet. Please refer to [Type of human detection packete](@ref NvsHumanDetectionDataTypeFlag)
 *  \param dataFilePath Path of the data file
 *  \return The return value indicates whether it is successful.
 *  \else
 *  \brief 初始化人体检测数据包
 *  \param dataType 人体检测数据包类型。请参见[人体检测数据包类型](@ref NvsHumanDetectionDataTypeFlag)
 *  \param dataFilePath 数据文件路径
 *  \return 返回值表示是否成功
 *  \endif
 *  \since 2.6.0
*/
+ (BOOL)setupHumanDetectionData:(int)dataType
           dataFilePath:(NSString *)dataFilePath;

/*! \if ENGLISH
 *  \brief Close the human detection mechanism.
 *  \else
 *  \brief 关闭人体检测机制
 *  \endif
 *  \since 2.5.0
*/
+ (void)closeHumanDetection;

/*! \if ENGLISH
 *  \brief Gets the EAGLSharegroup object used by the engine from the streaming context.
 *  \else
 *  \brief 从流媒体上下文中获取引擎所用的EAGLSharegroup对象
 *  \endif
 *  \since 1.5.0
*/
- (EAGLSharegroup *)getEAGLSharegroup;

/*! \if ENGLISH
 *  \brief Get the current rendering speed of the engine from the streaming context that it's only valid after startCapturePreview and playbackTimeline.
 *  \else
 *  \brief 从流媒体上下文中获取引擎当前的渲染速度，只在startCapturePreview和playbackTimeline之后有效。
 *  \endif
 *  \since 2.8.0
*/
- (float)detectEngineRenderFramePerSecond;

/*! \if ENGLISH
 *  \brief Gets audio and video informations of a file.
 *  \param avFilePath File path
 *  \return Returns the NvsAVFileInfo Object
 *  \else
 *  \brief 获取文件的音视频信息
 *  \param avFilePath 文件路径
 *  \return 返回音视频文件信息的对象
 *  \endif
*/
- (NvsAVFileInfo *)getAVFileInfo:(NSString *)avFilePath;

/*! \if ENGLISH
 *  \brief Gets audio and video information of a file.
 *  \param avFilePath File path
 *  \param extraFlag Special flag for Audio and video information. Please refer to [Special identifier when acquiring audio and video information.](@ref NvsAVFileinfoExtraFlag).
 *  \return 返回音视频文件信息的对象
 *  \else
 *  \brief 获取文件的音视频信息
 *  \param avFilePath 文件路径
 *  \param extraFlag 音视频信息特殊标识。请参见[音视频信息flag](@ref NvsAVFileinfoExtraFlag)
 *  \return 返回音视频文件信息的对象
 *  \endif
*/
- (NvsAVFileInfo *)getAVFileInfoExtra:(NSString *)avFilePath extraFlag:(int) extraFlag;

/*! \if ENGLISH
 *  \brief Detects the I frame interval of video files.
 *  \param videoFilePath Video file path
 *  \return Returns the detected I frame interval, and returning 0 means the detection failed.
 *  \else
 *  \brief 探测视频文件的I帧间距
 *  \param videoFilePath 视频文件的路径
 *  \return 返回探测到的I帧间距，返回0表示探测失败
 *  \endif
 *  \since 1.6.0
*/
- (int)detectVideoFileKeyframeInterval:(NSString *)videoFilePath;

/*! \if ENGLISH
 *  \brief Sets the default theme logo image path.
 *  \param logoImageFilePath Path of logo image file
 *  \return Returns the BOOL value. YES means the setting is successful, NO means it fails.
 *  \else
 *  \brief 设置默认主题logo图片路径
 *  \param logoImageFilePath logo图片文件路径
 *  \return 返回BOOL值。YES 设置成功；NO 设置失败
 *  \endif
 *  \sa getDefaultThemeEndingLogoImageFilePath
*/
- (BOOL)setDefaultThemeEndingLogoImageFilePath:(NSString *)logoImageFilePath;

/*! \if ENGLISH
 *  \brief Gets the default theme logo image path.
 *  \return Returns the image path
 *  \else
 *  \brief 获取默认主题logo图片路径
 *  \return 返回表示图片路径
 *  \endif
 *  \sa setDefaultThemeEndingLogoImageFilePath:
*/
- (NSString *)getDefaultThemeEndingLogoImageFilePath;

/*! \if ENGLISH
 *  \brief Sets whether the logo effect at the end of the theme is displayed or not.
 *  \return Returns BOOL value. YES means setting is successful, NO means it fails.
 *  \else
 *  \brief 设置主题结尾logo特效是否显示
 *  \return 返回BOOL值。YES 设置成功；NO 设置失败
 *  \endif
 *  \sa setDefaultThemeEndingLogoImageFilePath:
*/
- (BOOL)setThemeEndingEnabled:(BOOL)enable;

/*! \if ENGLISH
 *  \brief  Gets the fontFamily of the font file.
 *  \param fontFilePath Font file path
 *  \return Returns the fontFamily of the font.
 *  \else
 *  \brief 获取字体文件的fontFamily
 *  \param fontFilePath 字体文件路径
 *  \return 返回字体的fontFamily
 *  \endif
*/
- (NSString*)registerFontByFilePath:(NSString *)fontFilePath;

/*! \if ENGLISH
 *  \brief Creates timeline.
 *  \param videoEditRes Video file's resolution (specify the width,height and ratio). For video editting resolution, when importing corresponding params, the imported image's width has to be a multiple of 4, the height has to be a multiple of 2.
 *   Note: if one creates NvsStreamingContext's instance that supports 4K video editting, then video editting's resolution cannot be higher then 3840*2160(imageWidth*imageHeight), otherwise the imageWidth*imageHeight cannot exceed 1920* 1080 pixels.
 *  \param videoFps Video frame rate
 *  \param audioEditRes Audio editing resolution (specify the sampling rate, sampling format, and count of channels). For audio editing resolution, the incoming sample rate values support two types: 44100 and 48000.
 *  \return Returns the created NvsTimeline object.
 *  \else
 *  \brief 创建时间线
 *  \param videoEditRes 视频编辑解析度(指定视频宽高及像素比)。对于视频编辑解析度，在传入对应参数值时，目前要求传入的图像宽度值是4的倍数，高度值是2的倍数。注：如果创建NvsStreamingContext单例对象，支持4k视频编辑，则视频编辑解析度里的imageWidth * imageHeight不能高于3840*2160像素，否则视频编辑解析度里的imageWidth * imageHeight不能高于1920 * 1080像素。
 *  \param videoFps 视频帧率
 *  \param audioEditRes 音频编辑解析度(指定采样率、采样格式及声道数)。对于音频编辑解析度，传入的采样率值支持两种：44100与48000。
 *  \return 返回创建的时间线对象
 *  \endif
 *  \sa removeTimeline:
*/
- (NvsTimeline *)createTimeline:(NvsVideoResolution *)videoEditRes videoFps:(NvsRational *)videoFps audioEditRes:(NvsAudioResolution *)audioEditRes;

/*! \if ENGLISH
 *  \brief Removes timeline.
 *  \param timeline The timeline  which will be removed
 *  \return Returns the BOOL value. YES means removal succeeds, NO means removal fails.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 移除时间线
 *  \param timeline 要移除的时间线
 *  \return 返回BOOL值。YES 移除成功；NO 移除失败
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa createTimeline:videoFps:audioEditRes:
*/
- (BOOL)removeTimeline:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Gets the engine state.
 *  \return Returns the engine state.
 *  \else
 *  \brief 获取引擎状态
 *  \return 返回引擎状态
 *  \endif
*/
- (NvsStreamingEngineState)getStreamingEngineState;

/*! \if ENGLISH
 *  \brief Gets the current position of the timeline (in microseconds).
 *  \param timeline Timeline
 *  \return Returns the current position value of the timeline.
 *  \else
 *  \brief 取得时间线当前时间位置，单位为微秒
 *  \param timeline 时间线
 *  \return 返回时间线的当前位置值
 *  \endif
*/
- (int64_t)getTimelineCurrentPosition:(NvsTimeline *)timeline;

/*! \if ENGLISH
 *  \brief Compiles the video files by the timeline.
 *  \param timeline Timeline
 *  \param startTime Start time (in microseconds). The start time value ranges from [0, timeline.duration - 1], and other values are invalid.
 *  \param endTime End time (in microseconds). The value of endTime is in (startTime, timeline.duration], and the other values are invalid.
 *  \param outputFilePath The output video file path. Note: Currently only .mov format is supported.
 *  \param videoResolutionGrade Resolution level of video output.
 *  \param videoBitrateGrade The bitrate of the video output. The video output bitrate level is divided into low bitrate, medium bitrate, and high bitrate. The specific bitrate of video compiled is correlated with compiled file's resolution.
 *  Taking a 1280*720 pixels video for example, the approximate bitrates are as follows:
 *  <br>Bitrates for NvsCompileBitrateGradeLow, NvsCompileBitrateGradeMedium, NvsCompileBitrateGradeHigh are 2.2Mbps, 3.3Mbps and 6Mbps separately.s
 *  \param flags Special flag for video output (temporarily set to 0 only).Please refer to NvsStreamingEngineCompileFlag] (@ref NvsStreamingEngineCompileFlag).
 *  \return Returns the BOOL value. Note: Compiling timeline to video files is an asynchronous operation. If the return value is YES, compiling video startups successfully, otherwise it fails to startup.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 时间线生成视频文件
 *  \param timeline 时间线
 *  \param startTime 开始时间(单位微秒)。startTime取值范围在[0,timeline.duration - 1],传入其他值无效。
 *  \param endTime 结束时间(单位微秒)。endTime取值范围在(startTime,timeline.duration],同样传入其他值无效。
 *  \param outputFilePath 生成视频输出的文件路径。注意: 目前只支持输出.mov格式的文件
 *  \param videoResolutionGrade 生成视频输出的分辨率级别
 *  \param videoBitrateGrade 生成视频输出的码率。视频输出码率级别分为低码率，中等码率，高等码率。视频生成具体码率值跟生成视频的分辨率有关，这里以1280 * 720p为例，计算出不同码率级别对应的近似值，
 *                           NvsCompileBitrateGradeLow级别值为2.2Mbps，NvsCompileBitrateGradeMedium级别值为3.3Mbps，NvsCompileBitrateGradeHigh级别值为6Mbps。
 *  \param flags 生成视频输出的特殊标志。请参见 [NvsStreamingEngineCompileFlag] (@ref NvsStreamingEngineCompileFlag)
 *  \return 返回BOOL值。注意：时间线生成视频文件是异步操作。返回值为YES则启动时间线生成文件成功，NO则时间线生成文件启动失败。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa seekTimeline:timestamp:videoSizeMode:flags:
 *  \sa playbackTimeline:startTime:endTime:videoSizeMode:preload:flags:
*/
- (BOOL)compileTimeline:(NvsTimeline *)timeline startTime:(int64_t)startTime endTime:(int64_t)endTime outputFilePath:(NSString *)outputFilePath videoResolutionGrade:(NvsCompileVideoResolutionGrade)videoResolutionGrade videoBitrateGrade:(NvsCompileVideoBitrateGrade)videoBitrateGrade flags:(int)flags;

/*! \if ENGLISH
 *  \brief Pause compiling timeline
 *  \return Returns a BOOL value indicating whether the pause was successful
 *  \else
 *  \brief 暂定生成时间线
 *  \return 返回布尔值表示暂停是否成功
 *  \endif
 *  \since 2.9.0
 *  \sa resumeCompiling
 */
- (BOOL)pauseCompiling;

/*! \if ENGLISH
 *  \brief Resume compiling timeline
 *  \return Returns a boolean value indicating whether the resume was successful
 *  \else
 *  \brief 恢复生成时间线
 *  \return 返回布尔值表示恢复是否成功
 *  \endif
 *  \since 2.9.0
 *  \sa pauseCompiling
 */
- (BOOL)resumeCompiling;

/*! \if ENGLISH
 *  \brief Check if compiling timeline is paused
 *  \return Returns a boolean value indicating whether compiling timeline is paused
 *  \else
 *  \brief 检查生成时间线是否暂停了
 *  \return 返回布尔值表示生成时间线是否暂停了
 *  \endif
 *  \since 2.9.0
 *  \sa pauseCompiling
 */
- (BOOL)isCompilingPaused;

/*! \if ENGLISH
 *  \brief Sets the customized height for video.
 *   <br> When compiling videos, set the bitrate grade for compiled video to COMPILE_VIDEO_RESOLUTION_GRADE_CUSTOM.
            Plesae note, to make sure the file is compiled successfully, Meishe SDK would calibrate the height accordingly, thus the final output file may not necessarily be the height set here.
 *  \param videoHeight Custom height of the compiled video
 *  \else
 *  \brief 设置自定义的生成视频高度。
 *         <br>在生成时视频时，设置生成视频的分辨率高度级别为NvsCompileVideoResolutionGradeCustom
 *         就可以使用自定义的生成视频高度。但是请注意，为了保证视频生成成功，美摄SDK会对高度进行适当的对齐，
 *         因此最终生成的视频高度不一定就是这里设置的高度！
 *  \param videoHeight 自定义的生成视频高度
 *  \endif
 *  \since 1.6.1
*/
- (void)setCustomCompileVideoHeight:(unsigned int)videoHeight;

/*! \if ENGLISH
 *  \brief Gets the custom video height
 *  \return Returns the custom video height
 *  \else
 *  \brief 获取当前自定义的生成视频高度。
 *  \return 返回当前自定义的生成视频高度
 *  \endif
 *  \since 1.6.1
*/
- (unsigned int)getCustomCompileVideoHeight;

/*! \if ENGLISH
 *  \brief Connects timeline with live window.
 *  \param timeline Timeline
 *  \param liveWindow Live window
 *  \return Returns BOOL value. YES means a successful connection, and NO means the opposite.
 *  \else
 *  \brief 连接时间线和实时预览窗口
 *  \param timeline 时间线
 *  \param liveWindow 实时预览窗口
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 *  \endif
*/
- (BOOL)connectTimeline:(NvsTimeline *)timeline withLiveWindow:(NvsLiveWindow *)liveWindow;

/*! \if ENGLISH
 *  \brief Connects timeline with video frame receiver.
 *  \param timeline Timeline
 *  \param receiver Video frame receiver
 *  \return  Returns BOOL value. YES means a successful connection, and NO means the opposite.
 *  \else
 *  \brief 连接时间线和视频帧接收器
 *  \param timeline 时间线
 *  \param receiver 视频帧接收器
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 *  \endif
*/
- (BOOL)connectTimeline:(NvsTimeline *)timeline withVideoFrameReceiver:(NvsVideoFrameReceiver *)receiver;

/*! \if ENGLISH
 *  \brief Seeks to a certain timestamp of images
 *  \param timeline Timeline
 *  \param timestamp Timestamp (in microseconds). The range of timestamp value is [0, timeline.duration - 1]. And any other input value is invalid, seekTimeline will return No, resulting in seek failure.
 *  \param videoSizeMode Mode of previewing image
 *  \param flags Special seek flag for engine. Please refer to [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return Returns BOOL value. Note: Seeking to a timestamp is an asynchronous operation. A return value of YES means that seeking video startups successfully, otherwise it fails to startup.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 定位某一时间戳的图像
 *  \param timeline 时间线
 *  \param timestamp 时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，seekTimeline会返回No,导致无法开启定位。
 *  \param videoSizeMode 图像预览模式
 *  \param flags 引擎定位的特殊标志。请参见 [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return 返回BOOL值。注意：定位某时间戳图像是异步操作。返回值为YES则成功开启定位，NO则无法开启定位。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
 *  \sa playbackTimeline:startTime:endTime:proxyScale:preload:flags:
 *  \sa seekTimeline:timestamp:proxyScale:flags:
*/
- (BOOL)seekTimeline:(NvsTimeline *)timeline timestamp:(int64_t)timestamp videoSizeMode:(NvsVideoPreviewSizeMode)videoSizeMode flags:(int)flags;

/*! \if ENGLISH
 *  \brief Seeks to a certain timestamp of images
 *  \param timeline Timeline
 *  \param timestamp Timestamp (in microseconds). The range of timestamp value is [0, timeline.duration - 1]. And any other input value is invalid, seekTimeline will return No, resulting in seek failure.
 *  \param proxyScale Proxy scale value
 *  \param flags Special seek flag for engine. Please refer to [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return Returns BOOL value. Note: Seeking to a timestamp is an asynchronous operation. A return value of YES means that seeking video startups successfully, otherwise it fails to startup.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 定位某一时间戳的图像
 *  \param timeline 时间线
 *  \param timestamp 时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，seekTimeline会返回No,导致无法开启定位。
 *  \param proxyScale 代理缩放比例
 *  \param flags 引擎定位的特殊标志。请参见 [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return 返回BOOL值。注意：定位某时间戳图像是异步操作。返回值为YES则成功开启定位，NO则无法开启定位。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa seekTimeline:timestamp:videoSizeMode:flags:
 *  \sa playbackTimeline:startTime:endTime:videoSizeMode:preload:flags:
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
*/
- (BOOL)seekTimeline:(NvsTimeline *)timeline timestamp:(int64_t)timestamp proxyScale:(const NvsRational *)proxyScale flags:(int)flags;

/*! \if ENGLISH
 *  \brief Gets the image in the timeline of a certain timestamp. For details, refer to [The Topic of Video Frame Image Extraction] (@ref videoFrameRetriever.md).
 *  \param timeline The timeline object which gets the image
 *  \param timestamp The timestamp (in microseconds) for the image. The range of timestamp is [0, timeline.duration - 1]. Other values are invalid, and grabImageFromTimeline will return nil.
 *  \param proxyScale Proxy scale.Setting nil indicates the default ratio of 1:1.
 *  \return Returns the UIImage object of the image, it will return nil if grabbing image is failed.
 *  \else
 *  \brief 获取时间线某一时间戳的图像。详细情况参见[视频帧图像提取专题] (@ref videoFrameRetriever.md)
 *  \param timeline 欲获取图像的时间线对象
 *  \param timestamp 欲获取图像的时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，grabImageFromTimeline会返回nil。
 *  \param proxyScale 代理缩放比例，填写nil表示使用默认比例1:1
 *  \return 返回该时间戳图像的UIImage对象，如果获取图像失败返回nil
 *  \endif
 *  \since 1.1.2
*/
- (UIImage *)grabImageFromTimeline:(NvsTimeline *)timeline
                         timestamp:(int64_t)timestamp
                        proxyScale:(const NvsRational *)proxyScale;

/*! \if ENGLISH
 *  \brief Gets the image in the timeline of a certain timestamp. For details, refer to [The Topic of Video Frame Image Extraction] (@ref videoFrameRetriever.md).
 *  \param timeline The timeline object which gets the image
 *  \param timestamp The timestamp (in microseconds) for the image. The range of timestamp is [0, timeline.duration - 1]. Other values are invalid, and grabImageFromTimeline will return nil.
 *  \param proxyScale Proxy scale.Setting nil indicates the default ratio of 1:1.
 *  \param flags Special flag for seeking engine. Please refer to [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag).
 *  \return Returns the UIImage object of the image, it will return nil if grabbing image is failed.
 *  \else
 *  \brief 获取时间线某一时间戳的图像。详细情况参见[视频帧图像提取专题] (@ref videoFrameRetriever.md)
 *  \param timeline 欲获取图像的时间线对象
 *  \param timestamp 欲获取图像的时间戳(单位是微秒)。timestamp取值范围在[0,timeline.duration - 1]。传入其他值无效，grabImageFromTimeline会返回nil。
 *  \param proxyScale 代理缩放比例，填写nil表示使用默认比例1:1
 *  \param flags 引擎定位的特殊标志。请参见 [NvsStreamingEngineSeekFlag] (@ref NvsStreamingEngineSeekFlag)
 *  \return 返回该时间戳图像的UIImage对象，如果获取图像失败返回nil
 *  \endif
 *  \since 1.16.0
*/
- (UIImage *)grabImageFromTimeline:(NvsTimeline *)timeline timestamp:(int64_t)timestamp proxyScale:(const NvsRational *)proxyScale flags:(int)flags;

/*! \if ENGLISH
 *  \brief Playback timeline
 *  \param timeline Timeline
 *  \param startTime Start time (in microseconds). The value range of startTime is [0, timeline.duration - 1]. Any other value is invalid, and the playbackTimeline will return NO, resulting in startuping unsuccessfully for the playback video.
 *  \param endTime End time (in microseconds). If the input endTime value is negative, it will play to the end of the video by default.
 *  \param videoSizeMode Mode of previewing image
 *  \param preload Whether it preloads or not
 *  \param flags Special flag for previewing. If there is no special need, please fill in 0. Please refer to [NvsStreamingEnginePlaybackFlag] (@ref NvsStreamingEnginePlaybackFlag).
 *  \return Returns BOOL value. Note: The timeline playback is an asynchronous operation. Returning YES will start the timeline playback, and NO will not.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 播放时间线
 *  \param timeline 时间线
 *  \param startTime 开始时间(单位是微秒)。startTime取值范围在[0,timeline.duration - 1]。传入其他值无效，playbackTimeline会返回No导致无法开启播放。
 *  \param endTime 结束时间(单位是微秒)。如果endTime值传入是负值，则默认播放到视频末尾。
 *  \param videoSizeMode 图像预览模式
 *  \param preload 是否预先加载
 *  \param flags 预览的特殊标志，如无特殊需求，请填写0。请参见 [NvsStreamingEnginePlaybackFlag] (@ref NvsStreamingEnginePlaybackFlag)
 *  \return 返回BOOL值。注意：播放时间线是异步操作。返回YES则可以开启播放时间线，NO则无法开启播放。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa playbackTimeline:startTime:endTime:proxyScale:preload:flags:
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
 *  \sa seekTimeline:timestamp:videoSizeMode:flags:
*/
- (BOOL)playbackTimeline:(NvsTimeline *)timeline startTime:(int64_t)startTime endTime:(int64_t)endTime videoSizeMode:(NvsVideoPreviewSizeMode)videoSizeMode preload:(BOOL)preload flags:(int)flags;

/*! \if ENGLISH
 *  \brief Playback timeline
 *  \param timeline Timeline
 *  \param startTime Start time (in microseconds). The value range of startTime is [0, timeline.duration - 1]. Any other value is invalid, and the playbackTimeline will return NO, resulting in startuping unsuccessfully for the playback video.
 *  \param endTime End time (in microseconds). If the input endTime value is negative, it will play to the end of the video by default.
 *  \param proxyScale Proxy scale
 *  \param preload Whether it preloads or not
 *  \param flags Special flag for previewing. If there is no special need, please fill in 0. Please refer to [NvsStreamingEnginePlaybackFlag] (@ref NvsStreamingEnginePlaybackFlag).
 *  \return Returns BOOL value. Note: The timeline playback is an asynchronous operation. Returning YES will start the timeline playback, and NO will not.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 播放时间线
 *  \param timeline 时间线
 *  \param startTime 开始时间(单位是微秒)。startTime取值范围在[0,timeline.duration - 1]。传入其他值无效，playbackTimeline会返回No导致无法开启播放。
 *  \param endTime 结束时间(单位是微秒)。如果endTime值传入是负值，则默认播放到视频末尾。
 *  \param proxyScale 代理缩放比例
 *  \param preload 是否预先加载
 *  \param flags 预览的特殊标志，如无特殊需求，请填写0。请参见 [NvsStreamingEnginePlaybackFlag] (@ref NvsStreamingEnginePlaybackFlag)
 *  \return 返回BOOL值。注意：播放时间线是异步操作。返回YES则可以开启播放时间线，NO则无法开启播放。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa playbackTimeline:startTime:endTime:videoSizeMode:preload:flags:
 *  \sa seekTimeline:timestamp:proxyScale:flags:
 *  \sa compileTimeline:startTime:endTime:outputFilePath:videoResolutionGrade:videoBitrateGrade:flags:
*/
- (BOOL)playbackTimeline:(NvsTimeline *)timeline startTime:(int64_t)startTime endTime:(int64_t)endTime proxyScale:(const NvsRational *)proxyScale preload:(BOOL)preload flags:(int)flags;

/*! \if ENGLISH
 *  \brief Stops the engine
 *  \else
 *  \brief 停止引擎
 *  \endif
*/
- (void)stop;

/*! \if ENGLISH
 *  \brief tops the engine
 *  \param flags Flag of stopping the engine. Please refer to [NvsStreamingEngineStopFlag] (@ref NvsStreamingEngineStopFlag).
 *  \else
 *  \brief 停止引擎
 *  \param flags 停止引擎标志。请参见 [NvsStreamingEngineStopFlag] (@ref NvsStreamingEngineStopFlag)
 *  \endif
 *  \since 2.3.0
*/
- (void)stop:(int)flags;

/*! \if ENGLISH
 *  \brief Clears the cached resources.
 *  \param asynchronous Whether it's Asynchronous or not.
 *  \else
 *  \brief 清除缓存资源
 *  \param asynchronous 是否异步
 *  \endif
*/
- (void)clearCachedResources:(BOOL)asynchronous;

/*! \if ENGLISH
 *  \brief Clears the cached resources.
 *  \param asynchronous Whether it's Asynchronous or not.
 *  \else
 *  \brief 清除缓存资源
 *  \param asynchronous 是否异步
 *  \param flags 清除缓存标志，如无特殊需求请填写0。请参见 [NvsClearCacheFlag] (@ref NvsClearCacheFlag)。
 *  \endif
*/
- (void)clearCachedResources:(BOOL)asynchronous flags:(int)flags;

/*! \if ENGLISH
 *  \brief Count of captureing devices
 *  \return Returns the count of captureing devices.
 *  \else
 *  \brief 采集设备的数量
 *  \return 返回采集设备数
 *  \endif
*/
- (unsigned int)captureDeviceCount;

/*! \if ENGLISH
 *  \brief Whether it's a rear capturing device.
 *  \param catpureDeviceIndex Index of capturing device
 *  \return Returns BOOL value. YES means it is a rear capture device, and NO means the opposite.
 *  \else
 *  \brief 是否为后置采集设备
 *  \param catpureDeviceIndex 采集设备索引
 *  \return 返回BOOL值。返回YES则是后置采集设备，NO则不是。
 *  \endif
*/
- (BOOL)isCaptureDeviceBackFacing:(unsigned int)catpureDeviceIndex;

/*! \if ENGLISH
 *  \brief Obtains the capability description object of the capture device.
 *  \param catpureDeviceIndex Index of capturing device
 *  \return Returns the NvsCaptureDeviceCapability object.
 *  \else
 *  \brief 获取采集设备的能力描述对象
 *  \param catpureDeviceIndex 采集设备索引
 *  \return 返回采集设备能力描述对象
 *  \endif
*/
- (NvsCaptureDeviceCapability *)getCaptureDeviceCapability:(unsigned int)catpureDeviceIndex;

/*! \if ENGLISH
 *  \brief Connects the captured preview with live window.
 *  \param liveWindow Live window for previewing
 *  \return Returns the BOOL value. YES indicates a successful connection, and NO means the opposite.
 *  \else
 *  \brief 连接采集预览和实时预览窗口
 *  \param liveWindow 实时预览窗口
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 *  \endif
 *  \sa connectTimeline:withLiveWindow:
*/
- (BOOL)connectCapturePreviewWithLiveWindow:(NvsLiveWindow *)liveWindow;

/*! \if ENGLISH
 *  \brief Connects the captured preview with video frame receiver.
 *  \param receiver Video frame receiver
 *  \return Returns the BOOL value. YES indicates a successful connection, and NO means the opposite.
 *  \else
 *  \brief 连接采集预览和视频帧接收器
 *  \param receiver 视频帧接收器
 *  \return 返回BOOL值。返回YES则连接成功，NO则连接失败。
 *  \endif
 *  \since 1.7.1
*/
- (BOOL)connectCapturePreviewWithVideoFrameReceiver:(NvsVideoFrameReceiver *)receiver;

/*! \if ENGLISH
 *  \brief Adds a custom watermark for capturing video.
 *  \param watermarkFilePath Path of the watermark file, which should be a .PNG or .JPG file.
 *  \param displayWidth The width of the watermark displayed in the preview. If it is 0, the original width of the image is used.
 *  \param displayHeight The height of the watermark displayed in the preview. If it is 0, the original height of the image is used.
 *  \param opacity Watermark opacity, the range of which is 0~1
 *  \param position Position of the watermark, please refer to [NvsTimelineWatermarkPosition] (@ref NvsTimelineWatermarkPosition).
 *  \param marginX Watermark horizontal margin
 *  \param marginY Watermark vertical margin
 *  \else
 *  \brief 为视频采集添加用户水印
 *  \param watermarkFilePath 水印文件的路径，须为PNG或JPG文件
 *  \param displayWidth 水印在视频预览画面中显示的宽度，为0则使用图片文件的宽度
 *  \param displayHeight 水印在视频预览画面中显示的高度，为0则使用图片文件的高度
 *  \param opacity 水印的不透明度, 取值范围 0~1
 *  \param position 水印的位置，请参见 [NvsTimelineWatermarkPosition] (@ref NvsTimelineWatermarkPosition)
 *  \param marginX 水印在X方向的边距
 *  \param marginY 水印在Y方向的边距
 *  \endif
 *  \since 2.0.1
*/
-(void)setUserWatermarkForCapture:(NSString *)watermarkFilePath
                     displayWidth:(int)displayWidth
                    displayHeight:(int)displayHeight
                          opacity:(float)opacity
                         position:(NvsTimelineWatermarkPosition)position
                          marginX:(int)marginX
                          marginY:(int)marginY;

/*! \if ENGLISH
 *  \brief Removes custom watermark which added for capturing video.
 *  \else
 *  \brief 移除为视频采集添加的用户水印。
 *  \endif
 *  \since 2.0.1
*/
-(void)removeUserWatermarkForCapture;

/*! \if ENGLISH
 *  \brief Starts the capture preview.
 *  \param captureDeviceIndex Index of the capture device
 *  \param videoResGrade Video capture resolution level. The video resolution is defined by the short side (width or height) of the captured video. Value of the other side (width or height) is calculated according to the video aspect ratio (nil means the aspect ratio will be determined by the system capture device).
 *  It includes three levels, namely low, medium and high, the front camera corresponds to 480P, 540P, 720P, and the rear camera corresponds to 540P, 720P, 1080P.
 *  If the user wants to customize the recording resolution, such as 540*960 pixels, then it will need to record a video with equal aspect ratio, create a timeline with aspect ratio of 540*960 and compile it to file.
 *  When compiling, there is no grade corresponding to a height of 960p, thus the user needs to call setCustomCompileVideoHeight() to customize the height before compilation. Then call compileTimeline(),
 *  and the compiled level should be set to NvsCompileVideoResolutionGradeCustom. The example code is as follows:
 *
 *          NvsVideoResolution videoEditRes;
 *          videoEditRes.imageWidth = 540;
 *          videoEditRes.imageHeight = 960;
 *          videoEditRes.imagePAR = (NvsRational){1, 1};
 *          NvsRational videoFps = {25, 1};
 *          NvsAudioResolution audioEditRes;
 *          audioEditRes.sampleRate = 48000;
 *          audioEditRes.channelCount = 2;
 *          audioEditRes.sampleFormat = NvsAudSmpFmt_S16;
 *          self.timeline = [_context createTimeline:&videoEditRes videoFps:&videoFps audioEditRes:&audioEditRes];
 *          [_context setCustomCompileVideoHeight:960];
 *          [self.context compileTimeline:self.timeline startTime:0 endTime:self.timeline.duration outputFilePath:videoPath
 *          videoResolutionGrade:NvsCompileVideoResolutionGradeCustom videoBitrateGrade:NvsCompileBitrateGradeMedium flags:0];
 *  \param flags Flag field, if there is no special requirement, please fill in 0. Please refer to [NvsStreamingEngineCaptureFlag] (@ref NvsStreamingEngineCaptureFlag). The application scene for each flag  is as follows:
 *  <br>NvsStreamingEngineCaptureFlag_GrabCapturedVideoFrame which is used in grabing video frame；
 *  <br>NvsStreamingEngineCaptureFlag_StrictPreviewVideoSize is used for face detection combination with NvsStreamingEngineCaptureFlag_CaptureBuddyHostVideoFrame;
 *  <br>NvsStreamingEngineCaptureFlag_DontCaptureAudio Used for live video without audio stream. Usually not used.
 *  \param aspectRatio Aspect ratio for previewing, setting nil means that it will be determined by the system capture device.
 *  \return Returns BOOL value. YES indicates that the preview is started successfully, and NO means the opposite.
 *  \else
 *  \brief 启动采集设备预览
 *  \param captureDeviceIndex 采集设备索引
 *  \param videoResGrade 视频采集分辨率级别。视频分辨率等级是指录制时所拍摄视频短边（即可能是宽度或者是高度）的分辨率值，根据视频横纵比aspectRatio(值为nil则由系统采集设备来决定横纵比)计算得到另一边（即可能是宽度或者是高度）的值。
 *  其包括三种级别，分别是LOW，MEDIUM，HIGH，前置摄像头依次对应480p，540p，720p，后置摄像头依次对应540p，720p，1080p。如果有用户想自定义录制视频的等级，
 *  例如540 * 960,则需要拍摄等横纵比的视频，通过创建宽高依次是540和960的时间线，编辑然后生成。生成时，生成分辨率高度等级里面没有960p的等级，因此需要在生成前调用
 *  setCustomCompileVideoHeight()接口来自定义高度，然后调用生成接口compileTimeline()，生成高度级别设置为NvsCompileVideoResolutionGradeCustom即可。实例代码如下：
 *
 *          NvsVideoResolution videoEditRes;
 *          videoEditRes.imageWidth = 540;
 *          videoEditRes.imageHeight = 960;
 *          videoEditRes.imagePAR = (NvsRational){1, 1};
 *          NvsRational videoFps = {25, 1};
 *          NvsAudioResolution audioEditRes;
 *          audioEditRes.sampleRate = 48000;
 *          audioEditRes.channelCount = 2;
 *          audioEditRes.sampleFormat = NvsAudSmpFmt_S16;
 *          self.timeline = [_context createTimeline:&videoEditRes videoFps:&videoFps audioEditRes:&audioEditRes];
 *          [_context setCustomCompileVideoHeight:960];
 *          [self.context compileTimeline:self.timeline startTime:0 endTime:self.timeline.duration outputFilePath:videoPath
 *          videoResolutionGrade:NvsCompileVideoResolutionGradeCustom videoBitrateGrade:NvsCompileBitrateGradeMedium flags:0];
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineCaptureFlag] (@ref NvsStreamingEngineCaptureFlag)。每个Flag应用场景如下：
 *  <br>NvsStreamingEngineCaptureFlag_GrabCapturedVideoFrame用于视频抠像；
 *  <br>NvsStreamingEngineCaptureFlag_StrictPreviewVideoSize与NvsStreamingEngineCaptureFlag_CaptureBuddyHostVideoFrame结合用于人脸检测；
 *  <br>NvsStreamingEngineCaptureFlag_DontCaptureAudio用于视频直播，不采集音频流，一般不常用。
 *  \param aspectRatio 预览视频横纵比，传入nil则由系统采集设备来决定横纵比
 *  \return 返回BOOL值。返回YES则启动预览成功，NO则启动预览失败。
 *  \endif
*/
- (BOOL)startCapturePreview:(unsigned int)captureDeviceIndex
              videoResGrade:(NvsVideoCaptureResolutionGrade)videoResGrade
                      flags:(int)flags
                aspectRatio:(const NvsRational *)aspectRatio;

/*! \if ENGLISH
 *  \brief Starts the capture preview with inputting buffer mode.
 *  \param width Input buffer width.
 *  \param height Input buffer height.
 *  \param fps Input buffer framerate.
 *  \param rotation Input buffer rotation angle. Please refer to [Image rotation angle of input buffer](@ref BufferImageRotation)
 *  \param flipHorizontally whether to flip the buffer horizontally.
 *  \return Returns BOOL value. YES indicates that the preview is started successfully, and NO means the opposite.
 *  \else
 *  \brief 启动输入buffer模式的采集设备预览
 *  \param width 输入buffer的宽
 *  \param height 输入buffer的高
 *  \param fps 输入buffer的帧率
 *  \param rotation 输入buffer的图像旋转角度。请参见 [输入buffer的图像旋转角度] (@ref BufferImageRotation)
 *  \param flipHorizontally 是否需要水平翻转
 *  \return 返回BOOL值。返回YES则启动预览成功，NO则启动预览失败。
 *  \endif
 *  \sa sendBufferToCapturePreview
*/
- (BOOL)startBufferCapturePreview:(unsigned int)width
                                                height:(unsigned int)height
  fps:(const NvsRational *)fps
  rotation:(int)rotation
  flipHorizontally:(BOOL)flipHorizontally;

/*! \if ENGLISH
 *  \brief Transfers the input buffer to capture preivew.
 *  \param data Data and information of the input buffer. Only NV12 format is supported.
 *  \return Returns BOOL value.
 *  \else
 *  \brief 输入buffer给采集设备预览
 *  \param data 输入buffer的数据和相应信息。仅支持NV12格式的数据
 *  \return 返回BOOL值。
 *  \endif
 *  \sa startBufferCapturePreview
*/
- (BOOL)sendBufferToCapturePreview:(const NvsVideoFrameInfo *)data;

/*! \cond */
- (BOOL)startCapturePreviewForLiveStreaming:(unsigned int)captureDeviceIndex
                              videoResGrade:(NvsVideoCaptureResolutionGrade)videoResGrade
                                      flags:(int)flags
                                aspectRatio:(const NvsRational *)aspectRatio
                      liveStreamingEndPoint:(NSString *)liveStreamingEndPoint;
/*! \endcond */

/*! \if ENGLISH
 *  \brief Gets the capture preview resolution.
 *  \param catpureDeviceIndex Index of capturing device
 *  \return Gets the capture preview resolution.
 *  \else
 *  \brief 获取采集预览视频分辨率
 *  \param catpureDeviceIndex 采集设备索引
 *  \return 获取采集预览视频分辨率
 *  \endif
 *  \since 1.7.1
*/
- (NvsSize)getCapturePreviewVideoSize:(unsigned int)catpureDeviceIndex;

/*! \if ENGLISH
 *  \brief Samples the capture device's video frame
 *  \param sampleRect Rectangular area to sample, of which coordinates are in livewindow's coordinate system
 *  \return Returns the NvsColor object. This color value is the average color value of all pixels in sampled rectangular area.
 *  \else
 *  \brief 对采集设备的视频帧内容进行采样
 *  \param sampleRect 采样的矩形区域，坐标为实时预览窗口的自身坐标系
 *  \return 返回值为采样的颜色值，该颜色值是采样的矩形区域内所有像素颜色的平均值
 *  \endif
 *  \since 1.2.0
*/
- (NvsColor)sampleColorFromCapturedVideoFrame:(CGRect)sampleRect;

/*! \if ENGLISH
 *  \brief Starts autofocus.
 *  \param focusPointOfInterest The target area for autofocus, of which coordinates are in live-window's coordinate system
 *  \else
 *  \brief 启动自动聚焦
 *  \param focusPointOfInterest 自动聚焦的目标点，坐标为实时预览窗口的自身坐标系
 *  \endif
 *  \sa cancelAutoFocus
*/
- (void)startAutoFocus:(CGPoint)focusPointOfInterest;

/*! \if ENGLISH
 *  \brief Cancels the ongoing autofocus
 *  \else
 *  \brief 取消正在进行中的自动聚焦
 *  \endif
 *  \sa startAutoFocus:
*/
- (void)cancelAutoFocus;

/*! \if ENGLISH
 *  \brief Starts continuous focus.
 *  \else
 *  \brief 启动连续聚焦
 *  \endif
*/
- (void)startContinuousFocus;

/*! \if ENGLISH
 *  \brief Starts automatic exposure adjustment.
 *  \param pointOfInterest Exposure adjustment point
 *  \else
 *  \brief 启动自动曝光调节
 *  \param pointOfInterest 曝光调节点
 *  \endif
*/
- (void)startAutoExposure:(CGPoint)pointOfInterest;

/*! \if ENGLISH
 *  \brief Sets the zoom factor.
 *  \param zoomFactor Zoom ratio
 *  \else
 *  \brief 设置缩放因子
 *  \param zoomFactor 缩放比例
 *  \endif
 *  \sa getZoomFactor
*/
- (void)setZoomFactor:(float)zoomFactor;

/*! \if ENGLISH
 *  \brief Gets the zoom factor.
 *  \return Returns zoom factor value.
 *  \else
 *  \brief 获取缩放因子
 *  \return 返回缩放因子值
 *  \endif
 *  \sa setZoomFactor:
*/
- (float)getZoomFactor;

/*! \if ENGLISH
 *  \brief Sets which the flash light is on/off.
 *  \param on whether the flash light is on or not
 *  \else
 *  \brief 开/关换补光灯
 *  \param on 闪光灯是否开或关
 *  \endif
 *  \sa isFlashOn
*/
- (void)toggleFlash:(BOOL)on;

/*! \if ENGLISH
 *  \brief get state of the flash light.
 *  \return Returns a BOOL value, true means flash light is on and false means off.
 *  \else
 *  \brief 开/关换补光灯状态
 *  \return 返回BOOL值。返回YES则换补光灯是打开状态，NO则是关闭状态。
 *  \endif
 *  \sa toggleFlash:
*/
- (BOOL)isFlashOn;

/*! \if ENGLISH
 *  \brief Gets the current video’s stabilization flag.
 *  \return Returns the current flag.
 *  \else
 *  \brief 获取当前的视频防抖动标志
 *  \return 返回当前标志.
 *  \endif
 *  \sa setVideoStabilization:
*/
- (VideoStabilizationFlag)getVideoStabilization;

/*! \if ENGLISH
 *  \brief Sets video stabilization.
 *  \param flags Video stabilization value
 *  \else
 *  \brief 设置视频防抖动
 *  \param flags 视频防抖动值
 *  \endif
 *  \sa getVideoStabilization
*/
- (void)setVideoStabilization:(VideoStabilizationFlag)flags;

/*! \if ENGLISH
 *  \brief Set exposure compensation.
 *  \param exposureBias Exposure compensation value
 *  \else
 *  \brief 设置曝光补偿
 *  \param exposureBias 曝光补偿值
 *  \endif
 *  \sa getExposureBias
*/
- (void)setExposureBias:(float)exposureBias;

/*! \if ENGLISH
 *  \brief Gets exposure compensation.
 *  \return Returns exposure compensation value
 *  \else
 *  \brief 获取曝光补偿
 *  \return 返回曝光补偿值
 *  \endif
 *  \sa setExposureBias:
*/
- (float)getExposureBias;

/*! \if ENGLISH
 *  \brief Appends a built-in capture video effect.
 *  \param videoFxName Video effect name. To get the video effect name, please refer to [getAllBuiltinCaptureVideoFxNames()] (@ref getAllBuiltinCaptureVideoFxNames) or [The List of Built-in Effect Name] (\ref FxNameList.md).
 *  \return Returns the appended NvsCaptureVideoFx object.
 *  \else
 *  \brief 追加一个内建视频特效
 *  \param videoFxName 视频特效名。获取视频特效名称，请参见[getAllBuiltinCaptureVideoFxNames()] (@ref getAllBuiltinCaptureVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)。
 *  \return 返回追加的内建视频特效对象
 *  \endif
 *  \sa insertBuiltinCaptureVideoFx:withInsertPosition:
*/
- (NvsCaptureVideoFx *)appendBuiltinCaptureVideoFx:(NSString *)videoFxName;

/*! \if ENGLISH
 *  \brief Inserts a built-in video capture effect.
 *  \param videoFxName Video effect name. To get the video effect name, please refer to [getAllBuiltinCaptureVideoFxNames()] (@ref getAllBuiltinCaptureVideoFxNames) or [The List of Built-in Effect Name] (\ref FxNameList.md).
 *  \param insertPosition Insertion position.
 *  \return Returns the inserted NvsCaptureVideoFx object.
 *  \else
 *  \brief 插入一个内建视频特效
 *  \param videoFxName 视频特效名。获取视频特效名称，请参见[getAllBuiltinCaptureVideoFxNames()] (@ref getAllBuiltinCaptureVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)。
 *  \param insertPosition 插入位置
 *  \return 返回插入的内建视频特效对象
 *  \endif
 *  \sa appendBuiltinCaptureVideoFx:
*/
- (NvsCaptureVideoFx *)insertBuiltinCaptureVideoFx:(NSString *)videoFxName withInsertPosition:(unsigned int)insertPosition;

/*! \if ENGLISH
 *  \brief Appends a package capture effectx.
 *  \param videoFxPackageId Video effect package ID
 *  \return Returns the appended NvsCaptureVideoFx object.
 *  \else
 *  \brief 追加一个包裹视频特效
 *  \param videoFxPackageId 视频特效包裹ID
 *  \return 返回追加的包裹视频特效对象
 *  \endif
 *  \sa insertPackagedCaptureVideoFx:withInsertPosition:
*/
- (NvsCaptureVideoFx *)appendPackagedCaptureVideoFx:(NSString *)videoFxPackageId;

/*! \if ENGLISH
 *  \brief Inserts a package capture effect.
 *  \param videoFxPackageId Video effect package ID
 *  \param insertPosition Insertion position
 *  \return Returns the inserted NvsCaptureVideoFx object.
 *  \else
 *  \brief 插入一个包裹视频特效
 *  \param videoFxPackageId 视频特效包裹ID
 *  \param insertPosition 插入位置
 *  \return 返回插入的包裹视频特效对象
 *  \endif
 *  \sa appendPackagedCaptureVideoFx:
*/
- (NvsCaptureVideoFx *)insertPackagedCaptureVideoFx:(NSString *)videoFxPackageId withInsertPosition:(unsigned int)insertPosition;

/*! \if ENGLISH
 *  \brief Appends a custom capture video effect.
 *  \param customVideoFxRender Interface of user-implemented custom video effect renderer
 *  \return Returns the appended NvsCaptureVideoFx object.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 追加自定义采集视频特效
 *  \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
 *  \return 返回追加的采集视频特效对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \since 1.7.0
*/
- (NvsCaptureVideoFx *)appendCustomCaptureVideoFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender;

/*! \if ENGLISH
 *  \brief Inserts a custom capture video effect.
 *  \param customVideoFxRender Interface of user-implemented custom video effect renderer
 *  \param insertPosition Insertion position
 *  \return Returns the inserted NvsCaptureVideoFx object.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 插入自定义采集视频特效
 *  \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
 *  \param insertPosition 插入位置
 *  \return 返回插入的采集视频特效对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \since 1.7.0
*/
- (NvsCaptureVideoFx *)insertCustomCaptureVideoFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender withInsertPosition:(int)insertPosition;

/*! \if ENGLISH
 *  \brief Appends a beauty effect.
 *  \return Returns the Appended NvsCaptureVideoFx object.
 *  \else
 *  \brief 追加一个美颜视频特效
 *  \return 返回追加的美颜视频特效对象
 *  \endif
 *  \sa insertBeautyCaptureVideoFx:
*/
- (NvsCaptureVideoFx *)appendBeautyCaptureVideoFx;

/*! \if ENGLISH
 *  \brief Inserts a skin beauty video effect.
 *  \param insertPosition Insertion position
 *  \return Returns the inserted NvsCaptureVideoFx object.
 *  \else
 *  \brief 插入一个美颜视频特效
 *  \param insertPosition 插入位置
 *  \return 返回插入的美颜视频特效对象
 *  \endif
 *  \sa appendBeautyCaptureVideoFx:
*/
- (NvsCaptureVideoFx *)insertBeautyCaptureVideoFx:(unsigned int)insertPosition;

/*! \if ENGLISH
 *  \brief Removes a certain capture video effect indicated by its index
 *  \param captureVideoFxIndex Video effect index
 *  \return Returns a BOOL value. If it is YES, the removal is successful, and NO means failure.
 *  \else
 *  \brief 对移除特定索引值的采集视频特效
 *  \param captureVideoFxIndex 视频特效索引
 *  \return 返回BOOL值。返回YES则移除成功，NO则失败
 *  \endif
 *  \sa appendBuiltinCaptureVideoFx:
 *  \sa appendPackagedCaptureVideoFx:
 *  \sa appendBeautyCaptureVideoFx
*/
- (BOOL)removeCaptureVideoFx:(unsigned int)captureVideoFxIndex;

/*! \if ENGLISH
 *  \brief Removes all capture video effects.
 *  \else
 *  \brief 移除所有采集视频特效
 *  \endif
 *  \sa removeCaptureVideoFx:
 *  \sa getCaptureVideoFxCount
*/
- (void)removeAllCaptureVideoFx;

/*! \if ENGLISH
 *  \brief Gets the count of video effects.
 *  \return Returns the count of video effects.
 *  \else
 *  \brief 获得采集视频特效的数量
 *  \return 返回视频特效数量
 *  \endif
*/
- (unsigned int)getCaptureVideoFxCount;

/*! \if ENGLISH
 *  \brief Gets a certain capture video effect
 *  \param captureVideoFxIndex Video effect index
 *  \return Returns the NvsCaptureVideoFx object.
 *  \else
 *  \brief 获得采集视频特效
 *  \param captureVideoFxIndex 视频特效索引
 *  \return 返回视频特效对象
 *  \endif
 *  \sa removeCaptureVideoFx:
*/
- (NvsCaptureVideoFx *)getCaptureVideoFxByIndex:(unsigned int)captureVideoFxIndex;

/*! \if ENGLISH
 *  \brief Apply a capture scene resource package to the capture device.
 *  \param captureSceneId The ID of capture scene resource package
 *  \return Returns a BOOL value. A value of YES will result in a successful application and NO means it fails to apply.
 *  \else
 *  \brief 对采集设备应用拍摄场景资源包
 *  \param captureSceneId 拍摄场景资源包的ID
 *  \return 返回BOOL值。值为YES则应用成功，NO则失败。
 *  \endif
 *  \since 1.2.0
 *  \sa getCurrentCaptureSceneId
 *  \sa removeCurrentCaptureScene
*/
- (BOOL)applyCaptureScene:(NSString *)captureSceneId;

/*! \if ENGLISH
 *  \brief Gets the ID of the current capture scene resource package.
 *  \return Retruns the current ID of the capture scene resource package. nil indicates that there is no capture scene resource package for now.
 *  \else
 *  \brief 取得当前拍摄场景资源包的ID
 *  \return 当前拍摄场景资源包的ID字符串，返回nil表示当前没有拍摄场景资源包
 *  \endif
 *  \since 1.2.0
 *  \sa applyCaptureScene:
 *  \sa removeCurrentCaptureScene
*/
- (NSString *)getCurrentCaptureSceneId;

/*! \if ENGLISH
 *  \brief Removes the current capture scene.
 *  \else
 *  \brief 移除当前拍摄场景
 *  \endif
 *  \since 1.2.0
 *  \sa applyCaptureScene:
 *  \sa getCurrentCaptureSceneId
*/
- (void)removeCurrentCaptureScene;

/*! \if ENGLISH
 *  \brief Starts recording. Please refer to [Method of Recording Video](\ref videoRecorderMode.md).
 *  \param outputFilePath The path to the recording file. Note: .mov is recommended as the output format.
 *  \return Returns a BOOL value. Returning YES means it starts recording successfully, and NO means it fails to start.
 *  \else
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \endif
 *  \sa stopRecording
*/
- (BOOL)startRecording:(NSString *)outputFilePath;

/*! \if ENGLISH
 *  \brief Starts recording. Please refer to [Method of Recording Video](\ref videoRecorderMode.md).
 *  \param outputFilePath The path to the recording file. Note: .mov is recommended as the output format.
 *  \param flags Flag field, if there is no special requirement, please fill in 0. Please refer to [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \return Returns a BOOL value. Returning YES means it starts recording successfully, and NO means it fails to start.
 *  \else
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \endif
 *  \since 1.5.1
 *  \sa stopRecording
*/
- (BOOL)startRecording:(NSString *)outputFilePath withFlags:(int)flags;

/*! \if ENGLISH
 *  \brief Starts recording. Please refer to [Method of Recording Video](\ref videoRecorderMode.md).
 *  \param outputFilePath The path to the recording file. Note: .mov is recommended as the output format.
 *  \param flags Flag field, if there is no special requirement, please fill in 0. Please refer to [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \param withRecordConfigurations Recording configuration. For the key values in NSMutableDictionary, please refer to [Recording Video Configuration](@ref RECORD_CONFIGURATIONS):
 *          <br>For instance：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_RECORD_GOP_SIZE]; // setting 1 means it will generate an I-frame video.
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_RECORD_BITRATE]; // 10M bps
 *  \return Returns a BOOL value. Returning YES means it starts recording successfully, and NO means it fails to start.
 *  \else
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \param withRecordConfigurations 录制视频配置。NSMutableDictionary中关键字的值请参见 [录制视频配置] (@ref RECORD_CONFIGURATIONS)
 *         <br>例如：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_RECORD_GOP_SIZE]; // 设置为1即是生成全I帧视频
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_RECORD_BITRATE]; // 10M bps
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \endif
 *  \since 1.16.0
 *  \sa stopRecording
*/
- (BOOL)startRecording:(NSString *)outputFilePath withFlags:(int)flags withRecordConfigurations:(NSMutableDictionary *)withRecordConfigurations;

/*! \if ENGLISH
 *  \brief Starts to record, and the recorded content contains all the special effects which applied.
 *
 *  Note: If the effect processed is too complicated, it may cause the recorded video to drop frames.
 *  Therefore, users must be careful when using this method. Make sure that the effects can be processed in real time for the current phone. Please refer to [Method of Recording  Video] (\ref videoRecorderMode.md).
 *  \param outputFilePath The path to the recording file. Note: .mov is recommended as the output format.
 *  \return Returns a BOOL value. Returning YES means it starts recording successfully, and NO means it fails to start.
 *  \else
 *  \brief 启动采集设备的录制，录制的内容包含所有的特效处理效果。
 *
 *  注意：如果特效处理过于复杂可能会导致录制的视频丢帧，所以使用这个方法一定要慎重，要确保特效的处理对于当前
 *  手机是完全可以实时处理的。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。我们建议输出.mov格式的文件
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \endif
 *  \sa stopRecording
*/
- (BOOL)startRecordingWithFx:(NSString *)outputFilePath;

/*! \if ENGLISH
 *  \brief Starts to record, and the recorded content contains all the special effects which applied.
 *
 *  Note: If the effect processed is too complicated, it may cause the recorded video to drop frames.
 *  Therefore, users must be careful when using this method. Make sure that the effects can be processed in real time for the current phone. Please refer to [Method of Recording  Video] (\ref videoRecorderMode.md).
 *  \param outputFilePath The path to the recording file. Note: .mov is recommended as the output format.
 *  \param flags Flag field, if there is no special requirement, please fill in 0. Please refer to [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \return Returns a BOOL value. Returning YES means it starts recording successfully, and NO means it fails to start.
 *  \else
 *  \brief 启动采集设备的录制，录制的内容包含所有的特效处理效果。
 *
 *  注意：如果特效处理过于复杂可能会导致录制的视频丢帧，所以使用这个方法一定要慎重，要确保特效的处理对于当前
 *  手机是完全可以实时处理的。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \endif
 *  \since 1.5.1
 *  \sa stopRecording
*/
- (BOOL)startRecordingWithFx:(NSString *)outputFilePath withFlags:(int)flags;

/*! \if ENGLISH
 *  \brief Starts recording. Please refer to [Method of Recording Video](\ref videoRecorderMode.md).
 *  \param outputFilePath The path to the recording file. Note: .mov is recommended as the output format.
 *  \param flags Flag field, if there is no special requirement, please fill in 0. Please refer to [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \param withRecordConfigurations Recording configuration. For the key values in NSMutableDictionary, please refer to [Recording Video Configuration](@ref RECORD_CONFIGURATIONS):
 *          <br>For instance：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_RECORD_GOP_SIZE]; // setting 1 means it will generate an I-frame video.
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_RECORD_BITRATE]; // 10M bps
 *  \return Returns a BOOL value. Returning YES means it starts recording successfully, and NO means it fails to start.
 *  \else
 *  \brief 启动录制采集设备信号。请参见[视频录制方式] (\ref videoRecorderMode.md)
 *  \param outputFilePath 录制文件的路径。注意: 我们建议输出.mov格式的文件
 *  \param flags 标志字段，如无特殊需求请填写0。请参见 [NvsStreamingEngineRecordingFlag] (@ref NvsStreamingEngineRecordingFlag)
 *  \param withRecordConfigurations 录制视频配置。NSMutableDictionary中关键字的值请参见 [录制视频配置] (@ref RECORD_CONFIGURATIONS)
 *         例如：NSMutableDictionary *config = [[NSMutableDictionary alloc] init];
 *              [config setValue:[NSNumber numberWithInteger:15] forKey:NVS_RECORD_GOP_SIZE]; // 设置为1即是生成全I帧视频
 *              [config setValue:[NSNumber numberWithInteger:10000000] forKey:NVS_RECORD_BITRATE]; // 10M bps
 *  \return 返回BOOL值。返回YES则启动录制成功，NO则启动失败。
 *  \endif
 *  \since 1.16.0
 *  \sa stopRecording
*/
- (BOOL)startRecordingWithFx:(NSString *)outputFilePath withFlags:(int)flags withRecordConfigurations:(NSMutableDictionary *)withRecordConfigurations;

/*! \if ENGLISH
 *  \brief Stops recording
 *  \else
 *  \brief 结束录制采集设备信号
 *  \endif
 *  \sa startRecording:
*/
- (void)stopRecording;

/*! \if ENGLISH
 *  \brief Pause to record. Resuming recording after a pause will output the recorded video to the same file. Note: Recording can only be paused without using the built-in recorder!
 *  \return Returns a boolean value. A value of YES pause to record successfully and NO means it fails to pause.
 *  \else
 *  \brief 暂停录制采集信号。暂停录制之后再继续录制会录制到同一个媒体文件中。注意：只有不使用系统内置recorder时才能暂停录制！
 *  \return 返回布尔值。值为YES则暂停录制成功，NO则失败。
 *  \endif
 *  \since 1.17.0
 *  \sa resumeRecording
*/
- (BOOL)pauseRecording;

/*! \if ENGLISH
 *  \brief Continues to record. Continuing recording will output the recorded video to the same media file, to which the recording before suspend outputs contents.
 *  \return Returns a boolean value. A value of YES means it continues recording successfully and NO means it fails to continue.
 *  \else
 *  \brief 继续录制采集信号。继续录制会录制到暂停之前的同一个媒体文件中。
 *  \return 返回布尔值。值为YES则继续录制成功，NO则失败。
 *  \endif
 *  \since 1.17.0
 *  \sa pauseRecording
*/
- (BOOL)resumeRecording;

/*! \if ENGLISH
 *  \brief Checks if the recording has been paused.
 *  \return Returns a boolean value. If the value is YES, the recording has been paused, and NO means it's not paused.
 *  \else
 *  \brief 检查录制是否已经暂停
 *  \return 返回布尔值。值为YES则录制已经暂停，NO为未暂停。
 *  \endif
 *  \since 1.17.0
 *  \sa pauseRecording
 *  \sa resumeRecording
*/
- (BOOL)isRecordingPaused;

/*! \if ENGLISH
 *  \brief Gets the list of all built-in video effect names.
 *  \return Returns an array object containing all the built-in video effects’ names.
 *  \else
 *  \brief 获取全部内嵌视频特效名称
 *  \return 返回包含所有内嵌的视频特效名称的数组对象
 *  \endif
 *  \sa getAllBuiltinAudioFxNames
*/
- (NSArray *)getAllBuiltinVideoFxNames;

/*! \if ENGLISH
 *  \brief Gets the list of all built-in audio effect names.
 *  \return Returns an array object containing all the built-in audio effects’ names.
 *  \else
 *  \brief 获取全部内嵌音频特效名称
 *  \return 返回包含所有内嵌的音频特效名称的数组对象
 *  \endif
 *  \sa getAllBuiltinVideoFxNames
*/
- (NSArray *)getAllBuiltinAudioFxNames;

/*! \if ENGLISH
 *  \brief Gets the list of all built-in video transitions’ names.
 *  \return Returns an array object containing all built-in video transitions’ names.
 *  \else
 *  \brief 获取全部内嵌视频转场名称
 *  \return 返回包含所有内嵌的视频转场名称的数组对象
 *  \endif
 *  \sa getAllBuiltinCaptureVideoFxNames
 *  \sa getBeautyVideoFxName
 *  \sa getDefaultVideoTransitionName
*/
- (NSArray *)getAllBuiltinVideoTransitionNames;

/*! \if ENGLISH
 *  \brief Gets the list of all built-in capture video effects’ names.
 *  \return Returns an array object containing all built-in capture video effects’ names.
 *  \else
 *  \brief 获取全部内嵌采集视频特效名称
 *  \return 返回包含所有内嵌的采集视频特效名称的数组对象
 *  \endif
 *  \sa getBeautyVideoFxName
 *  \sa getAllBuiltinVideoFxNames
*/
- (NSArray *)getAllBuiltinCaptureVideoFxNames;

/*! \if ENGLISH
 *  \brief Gets the name of beauty effect.
 *  \return Returns the name of beauty effect.
 *  \else
 *  \brief 获得美颜的视频特效名称
 *  \return 返回美颜视频特效名称
 *  \endif
 *  \sa getAllBuiltinVideoFxNames
 *  \sa getAllBuiltinCaptureVideoFxNames
*/
- (NSString *)getBeautyVideoFxName;

/*! \if ENGLISH
 *  \brief Gets the default video transition’s name.
 *  \return Returns a string representing the default transition’s name.
 *  \else
 *  \brief 获得默认视频转场名称
 *  \return 返回表示默认转场名称的字符串
 *  \endif
 *  \sa getAllBuiltinVideoTransitionNames
*/
- (NSString *)getDefaultVideoTransitionName;

/*! \if ENGLISH
 *  \brief Sets the default audio transition’s name.
 *  \param name audio transition’s name
 *  \else
 *  \brief 设置默认视频转场名称
 *  \param name 音频转场的名字
 *  \endif
 *  \sa getAllBuiltinVideoTransitionNames
*/
- (void)setDefaultAudioTransitionName:(NSString *)name;

/*! \if ENGLISH
 *  \brief Gets the description of a video effect.
 *  \param fxName Video effect’s name
 *  \return Returns the object of the video effect description.
 *  \else
 *  \brief 获取视频特效描述
 *  \param fxName 视频特效名称
 *  \return 返回视频特效描述的对象
 *  \endif
 *  \sa getAudioFxDescription:
*/
- (NvsFxDescription *)getVideoFxDescription:(NSString *)fxName;

/*! \if ENGLISH
 *  \brief Gets the description of an audio effect.
 *  \param fxName Audio effect’s name
 *  \return Returns the object of the audio effect description.
 *  \else
 *  \brief 获取音频特效描述
 *  \param fxName 音频特效名称
 *  \return 返回音频特效描述的对象
 *  \endif
 *  \sa getVideoFxDescription:
*/
- (NvsFxDescription *)getAudioFxDescription:(NSString *)fxName;

/*! \if ENGLISH
 *  \brief Creates an object of video frame retriever.
 *  \param videoFilePath Path of the original video
 *  \return Returns an NvsVideoFrameRetriever object representing the video frame retriever object.
 *  \else
 *  \brief 创建视频帧提取对象
 *  \param videoFilePath 原始视频文件路径
 *  \return 返回NvsVideoFrameRetriever对象，表示视频帧提取对象
 *  \endif
 *  \since 1.2.0
*/
- (NvsVideoFrameRetriever *)createVideoFrameRetriever:(NSString *)videoFilePath;

/*! \if ENGLISH
 *  \brief Creates an object of auxiliary streaming context.
 *  \param lags Flag field. If there is no special requirement, please fill in 0.
 *  \return Returns an NvsStreamingContext object .
 *  \else
 *  \brief 创建辅助流媒体上下文对象
 *  \param flags 流媒体上下文创建标志
 *  \return 返回NvsVideoFrameRetriever对象，表示辅助流媒体上下文对象
 *  \endif
 *  \since 2.12.0
*/
- (NvsStreamingContext *)createAuxiliaryStreamingContext:(int)flags;

/*! \if ENGLISH
 *  \brief  destory auxiliary streaming context.
 *  \param NvsStreamingContext. destoryed auxiliary streaming context
  *  \else
 *  \brief 销毁辅助流媒体上下文对象
 *  \param NvsStreamingContext 被销毁的流媒体上下文对象
 *  \endif
 *  \since 2.12.0
*/
- (void)destoryAuxiliaryStreamingContext:(NvsStreamingContext*)auxContext;

/*! \if ENGLISH
 *  \brief set volume to audio output device.
 *  \param volume new volume to device, value range[0, 1]
 *  \else
 *  \brief 设置音频输出设备音量
 *  \param volume 新的音量 取值范围[0,1]
 *  \endif
 *  \since 2.14.0
*/
- (void)setAudioOutputDeviceVolume:(float)volume;

/*! \cond */
/*! \if ENGLISH
 *  \brief Verifies whether a feature is available or not.
 *  \param sdkFunctionName The name of the SDK’s function
 *  \return Returns a BOOL value. YES indicates that the authorization verification is successful, and NO indicates that the verification fails.
 *  \else
 *  \brief 验证某项功能是否可用。
 *  \param sdkFunctionName sdk功能的名字
 *  \return 返回BOOL值。YES表示授权验证成功，NO则验证失败。
 *  \endif
*/
+ (BOOL)functionalityAuthorised:(NSString *)sdkFunctionName;
/*! \endcond */

/*! \cond */
/*! \if ENGLISH
 *  \brief set special camera device type to sdk.
 *  \param specialCameraType special device type
 *  \else
 *  \brief 设置特殊的Camera 的设备类型。
 *  \param specialCameraType 特殊设备类型
 *  \endif
*/
+ (void)setSpecialCameraDeviceType:(NSString*)specialCameraType;
/*! \endcond */

/*! \cond */
/*! \if ENGLISH
 *  \brief set camera device capture fps.
 *  \param fps the frame count of per second
 *  \else
 *  \brief 设置采集帧率。
 *  \param fps 每秒钟的帧数量
 *  \endif
*/
- (void)setCaptureFps:(int)fps;
/*! \endcond */

@end

/*! \if ENGLISH
 *  \brief Description of capture device capability
 *
 *  Defines the relevant properties of the capture device, including auto focus, auto exposure, zoom, etc.
 *  \else
 *  \brief 采集设备能力描述
 *
 *  定义采集设备的相关属性，包含自动聚焦，自动曝光，缩放等
 *  \endif
*/
NVS_EXPORT @interface NvsCaptureDeviceCapability : NSObject

@property (readonly) BOOL supportAutoFocus;                     //!< \if ENGLISH Whether to support auto focus. \else 是否支持自动聚焦 \endif
@property (readonly) BOOL supportContinuousFocus;               //!< \if ENGLISH Whether to support continuous focus. \else 是否支持连续聚焦 \endif
@property (readonly) BOOL supportAutoExposure;                  //!< \if ENGLISH Whether to support automatic exposure. \else 是否支持自动曝光 \endif
@property (readonly) BOOL supportZoom;                          //!< \if ENGLISH Whether to support zoom. \else 是否支持缩放 \endif
@property (readonly) float maxZoomFactor;                       //!< \if ENGLISH Maximum zoom factor. \else 最大缩放比例 \endif
@property (readonly) BOOL supportFlash;                         //!< \if ENGLISH Whether to support flash light. \else 是否支持换补灯光 \endif
@property (readonly) BOOL supportVideoStabilization;            //!< \if ENGLISH Whether to support video stabilization. \else 是否支持防抖动 \endif
@property (readonly) BOOL supportExposureBias;                  //!< \if ENGLISH Whether to support exposure compensation. \else 是否支持曝光补偿 \endif
@property (readonly) float minExposureBias;                     //!< \if ENGLISH Minimum exposure compensation coefficient.\else 最小曝光补偿系数 \endif
@property (readonly) float maxExposureBias;                     //!< \if ENGLISH Maximum exposure compensation coefficient.\else 最大曝光补偿系数 \endif

@end

