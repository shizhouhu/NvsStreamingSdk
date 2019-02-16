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
