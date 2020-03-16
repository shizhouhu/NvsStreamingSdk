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

/*! \file NvsEffectCommonDef.h
 * */
#pragma once

#include <stdint.h>

#define NVS_EXPORT  __attribute__((visibility("default")))

/*! \if ENGLISH
*   \brief Rational value
*   \else
*   \brief 比例值
*   \endif
*/
typedef struct {
    int num;    //!< \if ENGLISH Numerator \else 分子 \endif
    int den;    //!< \if ENGLISH Denominator \else 分母 \endif
} NvsEffectRational;

/*! \if ENGLISH
*   \brief Video resolution
*   \else
*   \brief 视频解析度
*   \endif
*/
typedef struct {
    unsigned int imageWidth;        //!< \if ENGLISH Image width \else 图像宽度 \endif
    unsigned int imageHeight;       //!< \if ENGLISH Image height \else 图像高度 \endif
    NvsEffectRational imagePAR;     //!< \if ENGLISH Pixel ratio (only 1:1) \else 像素比（仅支持1:1）\endif
} NvsEffectVideoResolution;

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
} NvsEffectColor;

/*! \if ENGLISH
*   \brief 2D coordinate structure
*   \else
*   \brief 二维坐标结构
*   \endif
*/
typedef struct {
    float x, y;
} NvsEffectPosition2D;

/*! \if ENGLISH
*   \brief 3D coordinate structure
*   \else
*   \brief 三维坐标结构
*   \endif
*/
typedef struct {
    float x, y, z;
} NvsEffectPosition3D;

/*! \if ENGLISH
*   \brief Video frame pixel format
*   \else
*   \brief 视频帧像素格式
*   \endif
*/
typedef enum NvsEffectVideoFramePixelFormat
{
    NvsEffectPixelFormat_Nv12,      //!< \if ENGLISH YUV  4:2:0   12bpp (Two channels, one channel is a continuous luminance channel, and the other channel is VU component interlaced) \else  YUV  4:2:0   12bpp ( 2通道, 一个通道是连续的亮度通道, 另一通道为VU分量交错 ) \endif
    NvsEffectPixelFormat_YUV420,    //!< \if ENGLISH YUV  4:2:0   12bpp (Three channels, one luminance channel, the other two are U component and V component channels, all channels are continuous) \else  YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另两个为U分量和V分量通道, 所有通道都是连续的 ) \endif
    NvsEffectPixelFormat_BGRA
} NvsEffectVideoFramePixelFormat;

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
    NvsEffectVideoFramePixelFormat pixelFormat;     //!< \if ENGLISH The captured image's format \else 获取到图像的格式 \endif
    int64_t frameTimestamp;                         //!< \if ENGLISH The captured image's timestamp (in microseconds) \else 获取到图像的时间戳（单位微秒） \endif
    bool isRec601;                                  //!< \if ENGLISH Whether it is BT.601 \else 是否是BT.601 \endif
    bool isFullRangeYUV;

    int displayRotation;                            //!< \if ENGLISH Shows the angle at which the current image needs to be rotated \else 显示当前图像需要旋转的角度 \endif
    bool flipHorizontally;                          //!< \if ENGLISH Shows whether current image requires horizontal flip or not\else 显示当前图像需要不需要水平翻转 \endif
} NvsEffectVideoFrameInfo;
