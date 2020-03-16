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

/*! \file NvsCommonDef.h
 * */
#pragma once

#include <stdint.h>

#define NVS_EXPORT  __attribute__((visibility("default")))

/*! \if ENGLISH
*   \brief Audio sampling format
*   \else
*   \brief 音频采样格式
*   \endif
*/
typedef enum {
    NvsAudSmpFmt_None = -1,//!< \if ENGLISH None \else 无 \endif
    NvsAudSmpFmt_U8,       //!< \if ENGLISH unsigned 8 bit \else unsigned 8 bit \endif
    NvsAudSmpFmt_S16,      //!< \if ENGLISH signed 16 bit \else signed 16 bit \endif
    NvsAudSmpFmt_S32,      //!< \if ENGLISH signed 32 bit \else signed 32 bit \endif
    NvsAudSmpFmt_FLT,      //!< \if ENGLISH single precision float \else 单精度浮点数 \endif
    NvsAudSmpFmt_DBL,      //!< \if ENGLISH double precision float \else 双精度浮点数 \endif

    NvsAudSmpFmt_U8P,      //!< \if ENGLISH unsigned 8 bit,planer \else unsigned 8 bit 平面格式 \endif
    NvsAudSmpFmt_S16P,     //!< \if ENGLISH signed 16 bit,planer \else signed 16 bit 平面格式 \endif
    NvsAudSmpFmt_S32P,     //!< \if ENGLISH signed 32 bit,planer \else signed 32 bit 平面格式 \endif
    NvsAudSmpFmt_FLTP,     //!< \if ENGLISH single precision float,planar \else 单精度浮点数 平面格式\endif
    NvsAudSmpFmt_DBLP,     //!< \if ENGLISH double precision float,olanar \else 双精度浮点数 平面格式\endif

    NvsAudSmpFmt_Count
} NvsAudioSampleFormat;

/*! \if ENGLISH
*   \brief File type
*   \else
*   \brief 文件类型
*   \endif
*/
typedef enum {
    NvsAVFileType_Unknown = -1,      //!< \if ENGLISH Unknown \else 未知 \endif
    NvsAVFileType_AudioVideo = 0,    //!< \if ENGLISH Video \else 视频 \endif
    NvsAVFileType_Audio,             //!< \if ENGLISH Audio \else 音频 \endif
    NvsAVFileType_Image              //!< \if ENGLISH Image \else 图片 \endif
} NvsAVFileType;

/*! \if ENGLISH
*   \brief Video rotation
*   \else
*   \brief 视频旋转角度
*   \endif
*/
typedef enum
{
    NvsVideoRotation_0 = 0,
    NvsVideoRotation_90,
    NvsVideoRotation_180,
    NvsVideoRotation_270
} NvsVideoRotation;

/*! \if ENGLISH
*   \brief Video codec type
*   \else
*   \brief 视频编码类型
*   \endif
*/
typedef enum
{
    NvsVideoCodecType_Unknown = 0,
    NvsVideoCodecType_H264,
    NvsVideoCodecType_H265
} NvsVideoCodecType;

/*! \if ENGLISH
*   \brief The role of the clip in the theme
*   \else
*   \brief 片段在主题中的角色
*   \endif
*/
typedef enum NvsRoleInTheme
{
    NvsRoleInThemeGeneral,   //!< \if ENGLISH General \else 通用 \endif
    NvsRoleInThemeTitle,     //!< \if ENGLISH Title \else 片头 \endif
    NvsRoleInThemeTrailer    //!< \if ENGLISH Trailer \else 片尾 \endif
} NvsRoleInTheme;

/*! \if ENGLISH
*   \brief Text alignment style
*   \else
*   \brief 字幕对齐方式
*   \endif
*/
typedef enum NvsTextAlignment
{
    NvsTextAlignmentLeft = 0,
    NvsTextAlignmentCenter,
    NvsTextAlignmentRight
} NvsTextAlignment;

/*! \if ENGLISH
*   \brief Uses the default caption package
*   \else
*   \brief 使用默认的字幕包属性
*   \endif
*/
typedef enum NvsAssetDefaultParam
{
    USE_ASSET_DEFAULT_PARAM = 0,
    NOT_USE_ASSET_DEFAULT_PARAM
} NvsAssetDefaultParam;

/*! \if ENGLISH
*   \brief The type of clip in theme
*   \else
*   \brief 片段在主题中的类型
*   \endif
*/
typedef enum NvsCategory
{
    NvsDefaultCategory,   //!< \if ENGLISH Default type \else 默认类型 \endif
    NvsUserCategory,      //!< \if ENGLISH User-defined type \else 用户自定义类型 \endif
    NvsThemeCategory      //!< \if ENGLISH Theme category \else 主题类型 \endif
} NvsCategory;

/*! \if ENGLISH
*   \brief Video frame pixel format
*   \else
*   \brief 视频帧像素格式
*   \endif
*/
typedef enum NvsVideoFramePixelFormat
{
    NvsPixelFormat_Nv12,  //!< \if ENGLISH YUV  4:2:0   12bpp (Two channels, one channel is a continuous luminance channel, and the other channel is VU component interlaced) \else  YUV  4:2:0   12bpp ( 2通道, 一个通道是连续的亮度通道, 另一通道为VU分量交错 ) \endif
    NvsPixelFormat_YUV420 //!< \if ENGLISH YUV  4:2:0   12bpp (Three channels, one luminance channel, the other two are U component and V component channels, all channels are continuous) \else  YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另两个为U分量和V分量通道, 所有通道都是连续的 ) \endif
} NvsVideoFramePixelFormat;

/*! \if ENGLISH
*   \brief Rational value
*   \else
*   \brief 比例值
*   \endif
*/
typedef struct {
    int num;    //!< \if ENGLISH Numerator \else 分子 \endif
    int den;    //!< \if ENGLISH Denominator \else 分母 \endif
} NvsRational;

/*! \if ENGLISH
*   \brief Size
*   \else
*   \brief 尺寸
*   \endif
*/
typedef struct {
    int width;    //!< \if ENGLISH Width \else 宽度 \endif
    int height;   //!< \if ENGLISH Height \else 高度 \endif
} NvsSize;

/*! \if ENGLISH
*   \brief Rectangle
*   \else
*   \brief 矩形
*   \endif
*/
typedef struct {
    float left;   //!< \if ENGLISH Left \else left \endif
    float right;  //!< \if ENGLISH Right \else right \endif
    float bottom; //!< \if ENGLISH Bottom \else bottom \endif
    float top;    //!< \if ENGLISH Top \else top \endif
} NvsRect;

/*! \if ENGLISH
*   \brief Audio resolution
*   \else
*   \brief 音频解析度
*   \endif
*/
typedef struct {
    unsigned int sampleRate;            //!< \if ENGLISH Sampling rate \else 采样率 \endif
    NvsAudioSampleFormat sampleFormat;  //!< \if ENGLISH Sampling format \else 采样格式 \endif
    unsigned int channelCount;          //!< \if ENGLISH Channel count \else 声道数 \endif
} NvsAudioResolution;

/*! \if ENGLISH
*   \brief Video resolution
*   \else
*   \brief 视频解析度
*   \endif
*/
typedef struct {
    unsigned int imageWidth;  //!< \if ENGLISH Image width \else 图像宽度 \endif
    unsigned int imageHeight; //!< \if ENGLISH Image height \else 图像高度 \endif
    NvsRational imagePAR;     //!< \if ENGLISH Pixel ratio (only 1:1) \else 像素比（仅支持1:1）\endif
} NvsVideoResolution;

/*! \if ENGLISH
*   \brief Self-defined color.
*
*   In the SDK, attributes r, g, b, a in NvsColor class range [0, 1] instead of [0, 255].
*   \else
*   \brief 自定义颜色类
*
*   SDK中，NvsColor类属性r,g,b,a取值范围是[0,1]，而非[0,255]。
*   \endif
*/
typedef struct {
    float r, g, b, a;
} NvsColor;

/*! \if ENGLISH
*   \brief 2D coordinate structure
*   \else
*   \brief 二维坐标结构
*   \endif
*/
typedef struct {
    float x, y;
} NvsPosition2D;

/*! \if ENGLISH
*   \brief 3D coordinate structure
*   \else
*   \brief 三维坐标结构
*   \endif
*/
typedef struct {
    float x, y, z;
} NvsPosition3D;


#define NVS_VIDEO_FRAME_MAX_PLANES     4

/*! \if ENGLISH
*   \brief Video frame information
*   \else
*   \brief 视频帧信息
*   \endif
*/
typedef struct{
    int frameWidth;                                 //!< \if ENGLISH The captured image's width (in pixel) \else 获取到图像的宽度(以像素为单位) \endif
    int frameHeight;                                //!< \if ENGLISH The captured image's height (in pixel) \else 获取到图像的高度(以像素为单位) \endif
    int planeRowPitch[NVS_VIDEO_FRAME_MAX_PLANES];  //!< \if ENGLISH The number of bytes per line in the frame of the flat image \else 平面图像每行在Frame中占的字节数 \endif
    void* planePtr[NVS_VIDEO_FRAME_MAX_PLANES];
    NvsVideoFramePixelFormat pixelFormat;           //!< \if ENGLISH The captured image's format \else 获取到图像的格式 \endif
    int64_t frameTimestamp;                         //!< \if ENGLISH The captured image's timestamp (in microseconds) \else 获取到图像的时间戳（单位微秒） \endif
    bool isRec601;                                  //!< \if ENGLISH Whether it is BT.601 \else 是否是BT.601 \endif
    bool isFullRangeYUV;

    int displayRotation;                            //!< \if ENGLISH Shows the angle at which the current image needs to be rotated \else 显示当前图像需要旋转的角度 \endif
    bool flipHorizontally;                          //!< \if ENGLISH Shows whether current image requires horizontal flip or not\else 显示当前图像需要不需要水平翻转 \endif
} NvsVideoFrameInfo;
