//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2019. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Apr 20. 2019
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <UIKit/UIImage.h>
#import "NvsCommonDef.h"


/*! \cond */

/*! \if ENGLISH
 *  \brief Type of convertor error
 *  \else
 *  \brief 转码错误
 *  \endif
*/
typedef enum {
    keNvsMediaConvertorErrorType_NoError = 0,                        //!< \if ENGLISH no error \else 没有错误 \endif
    keNvsMediaConvertorErrorType_Cancled,                            //!< \if ENGLISH task is canceled \else 当前任务已经取消 \endif
    keNvsMediaConvertorErrorType_HardwareVideoEncoderSetupError, //!< \if ENGLISH video encoder setup error \else 视频编码器设置错误 \endif
    keNvsMediaConvertorErrorType_HardwareVideoEncodingError,         //!< \if ENGLISH video encoder error \else 视频编码器编码过程中出现错误 \endif
    keNvsMediaConvertorErrorType_HardwareVideoDecoderSetupError,     //!< \if ENGLISH video decoder setup error \else 视频解码器设置过程中出现错误 \endif
    keNvsMediaConvertorErrorType_HardwareVideoDecodingError,         //!< \if ENGLISH video decode error \else 视频解码器解码过程中出现错误 \endif
    keNvsMediaConvertorErrorType_ProcessVideoError,
    keNvsMediaConvertorErrorType_ProcessAudioError,
    keNvsMediaConvertorErrorType_ReadFileEof,
    keNvsMediaConvertorErrorType_UnkownError = 65535                //!< \if ENGLISH task has unknown error \else 出现没有定义的错误 \endif
} NvsMediaConvertorErrorType;

/*! \anchor CONVERTOR_CONFIGURATIONS */
/*!
 *  \if ENGLISH
 *   @name Configuration of media convertor
 *  \else
 *   @name 转码配置
 *  \endif
*/
//!@{
#define NVS_MEDIA_CONVERTOR_CUSTOM_HEIGHT                   @"custom-video-height"			//!< \if ENGLISH Set custom video height \else 设置自定义视频输出高度 \endif
#define NVS_MEDIA_CONVERTOR_CUSTOM_AUDIO_SAMPLE_RATE        @"custom-audio-sample-rate"     //!< \if ENGLISH Set custom audio sample rate \else 设置自定义音频采样率 \endif
#define NVS_MEDIA_CONVERTOR_NO_VIDEO                        @"convertor-no-video"           //!< \if ENGLISH only convert audio stream  \else 只进行音频转码 \endif
#define NVS_MEDIA_CONVERTOR_NO_AUDIO                        @"convertor-no-audio"           //!< \if ENGLISH only convert video stream \else 只进行视频转码 \endif
#define NVS_MEDIA_CONVERTOR_CUSTOM_AUDIO_CHANNEL            @"custom-audio-channel"         //!< \if ENGLISH Set custom audio channels \else 设置自定义音频通道数\endif
//!@}
//!

@protocol NvsMediaFileConvertorDelegate<NSObject>

- (void)didConvertorProgress:(int64_t)taskId progress:(float)progress;

- (void)didConvertorFinish:(int64_t)taskId sourceFile:(NSString*)src outputFile:(NSString*)dst errorCode:(NvsMediaConvertorErrorType)error;

- (void)didAudioMuteRage:(int64_t)taskId muteStart:(int64_t)start muteEnd:(int64_t)end;

@end


NVS_EXPORT @interface NvsMediaFileConvertor : NSObject

@property (nonatomic, weak) id<NvsMediaFileConvertorDelegate> delegate;

- (instancetype)init;

- (int64_t)convertMeidaFile:(NSString *)srcFilePath
                   outputFile:(NSString *)outputFilePath
             isReverseConvert:(bool)isReverse
                 fromPosition:(int64_t)from
                   toPosition:(int64_t)to
                      options:(NSMutableDictionary *)options;

- (void)cancelTask:(int64_t)taskId;

@end
/*! \endcond */

