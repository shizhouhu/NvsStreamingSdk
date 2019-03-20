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

/*! \if ENGLISH \else \brief 比例值 \endif*/
typedef struct {
    int num;    //!< \if ENGLISH Numerator \else 分子 \endif
    int den;    //!< \if ENGLISH Denominator \else 分母 \endif
} NvsEffectRational;

/*! \if ENGLISH \else \brief 视频解析度 \endif */
typedef struct {
    unsigned int imageWidth;  //!< \if ENGLISH \else 图像宽度 \endif
    unsigned int imageHeight; //!< \if ENGLISH \else 图像高度 \endif
    NvsEffectRational imagePAR;     //!< \if ENGLISH \else 像素比（仅支持1:1）\endif
} NvsEffectVideoResolution;

/*!
    \brief 自定义颜色类

    SDK中，NvsEffectColor类属性r,g,b,a取值范围是[0,1]，而非[0,255]。
 */
typedef struct {
    float r, g, b, a;
} NvsEffectColor;

/*! \if ENGLISH \else \brief 二维坐标结构 \endif */
typedef struct {
    float x, y;
} NvsEffectPosition2D;
/*! \if ENGLISH \else \brief 三维坐标结构 \endif */
typedef struct {
    float x, y, z;
} NvsEffectPosition3D;

typedef enum NvsEffectVideoFramePixelFormat
{
    NvsEffectPixelFormat_Nv12,  //!< \if ENGLISH \else  YUV  4:2:0   12bpp ( 2通道, 一个通道是连续的亮度通道, 另一通道为VU分量交错 ) \endif
    NvsEffectPixelFormat_YUV420, //!< \if ENGLISH \else  YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另两个为U分量和V分量通道, 所有通道都是连续的 ) \endif
    NvsEffectPixelFormat_BGRA
} NvsEffectVideoFramePixelFormat;

#define NVS_VIDEO_FRAME_MAX_PLANES     4

typedef struct{
    //!< \if ENGLISH \else 获取到图像的宽度(以像素为单位) \endif
    int frameWidth;
    //!< \if ENGLISH \else 获取到图像的高度(以像素为单位) \endif
    int frameHeight;
    //!< \if ENGLISH \else 平面图像每行在Frame中占的字节数 \endif
    int planeRowPitch[NVS_VIDEO_FRAME_MAX_PLANES];
    void* planePtr[NVS_VIDEO_FRAME_MAX_PLANES];
    //!< \if ENGLISH \else 获取到图像的格式 \endif
    NvsEffectVideoFramePixelFormat pixelFormat;
    //!< \if ENGLISH \else 获取到图像的时间戳（单位微秒） \endif
    int64_t frameTimestamp;
    bool isRec601; //!< \if ENGLISH \else 是否是BT.601 \endif
    bool isFullRangeYUV;

    int displayRotation; //!< \if ENGLISH \else 显示当前图像需要旋转的角度 \endif
    bool flipHorizontally; //!< \if ENGLISH \else 显示当前图像需要不需要水平翻转 \endif
} NvsEffectVideoFrameInfo;
