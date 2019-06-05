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

typedef enum {
    NvsStrokeFillGradient = 0,
    NvsStrokeFillTexture
} NvsStrokeFillMode;

typedef enum {
    NvsStrokeAnalogSin = 0,
    NvsStrokeAnalogInvertSin,
    NvsStrokeAnalogPositiveSin,
    NvsStrokeAnalogCos,
    NvsStrokeAnalogInvertCos,
    NvsStrokeAnalogPositiveCos
} NvsStrokeAnalogType;

typedef enum {
    NvsStrokeCapFlat = 0,
    NvsStrokeCapSquare,
    NvsStrokeCapRound,
    NvsStrokeCapItalic
} NvsStrokeCapStyle;

typedef enum {
    NvsStrokeJointBevel = 0,
    NvsStrokeJointMiter,
    NvsStrokeJointRound
} NvsStrokeJointStyle;

typedef enum {
    NvsStrokeTextureWarpClamp = 0,
    NvsStrokeTextureWarpRepeat,
    NvsStrokeTextureWarpMirroredRepeat
} NvsStrokeTextureWarpType;

/*! \if ENGLISH
 *  \brief Painting special effects context
 *
 *  The painting effect context class can be used as an entry to adjust the painting effect. Users can adjust the path, width, texture, etc. of the painting strokes.
 *  \warning NvsPaintingEffectContext类中，所有public API都在UI线程使用！！！
 *  \else
 *  \brief 手绘特效上下文
 *
 *  手绘特效上下文类可视作调整手绘效果的入口。可以调整手绘线条的路径，宽度，纹理等
 *  \warning NvsPaintingEffectContext类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsPaintingEffectContext : NSObject

- (void)setInternalContext:(void *)internalContext;

/*! \if ENGLISH
*   \brief Sets stroke width.
*   \param width Stroke width
*   \else
*   \brief 设置线条宽度
*   \param width 线条宽度
*   \endif
*/
- (void)setStrokeWidth:(float)width;

/*! \if ENGLISH
 *   \brief Sets the stroke head and tail style.
 *   \param capStyle Stroke head and tail style
 *   \else
 *   \brief 设置线条首尾样式
 *   \param capStyle 线条首尾样式
 *   \endif
*/
- (void)setStrokeCapStyle:(NvsStrokeCapStyle)capStyle;

/*! \if ENGLISH
 *   \brief Sets the stroke joint style.
 *   \param jointStyle The stroke joint style
 *   \else
 *   \brief 设置线条弯曲部分衔接样式
 *   \param jointStyle 线条衔接样式
 *   \endif
*/
- (void)setStrokeJointStyle:(NvsStrokeJointStyle)jointStyle;

/*! \if ENGLISH
 *  \brief Sets stroke fill mode: color,texture.
 *  \param fillMode Fill mode
 *  \else
 *  \brief 设置线条填充模式：颜色，纹理
 *  \param fillMode 填充模式
 *  \endif
*/
- (void)setStrokeFillMode:(NvsStrokeFillMode)fillMode;

/*! \if ENGLISH
 *  \brief Sets the stroke gradient color.
 *  \param gradient Stroke gradient color
 *  \else
 *  \brief 设置线条填充颜色
 *  \param gradient 线条填充颜色
 *  \endif
*/
- (void)setStrokeGradient:(NvsColor)gradient;

/*! \if ENGLISH
 *  \brief Sets stroke texture file path.
 *  \param filePath Stroke texture file path
 *  \else
 *  \brief 设置线条纹理文件路径
 *  \param filePath 线条纹理文件路径
 *  \endif
*/
- (void)setStrokeTextureFilePath:(NSString *)filePath;

/*! \if ENGLISH
 *  \brief Sets the stroke texture warp type.
 *  \param warpType Stroke texture warp type
 *  \else
 *  \brief 设置线条纹理附件方式
 *  \param warpType 线条纹理附加方式
 *  \endif
*/
- (void)setStrokeTextureWarpType:(NvsStrokeTextureWarpType)warpType;

/*! \if ENGLISH
 *  \brief Sets stroke repeating times.
 *  \param horRepeatTimes Horizontal repeating times.
 *  \param verRepeatTimes  Vertical repeating times.
 *  \else
 *  \brief 设置线条纹理重复次数
 *  \param horRepeatTimes 横向纹理重复次数
 *  \param verRepeatTimes 纵向纹理重复次数
 *  \endif
*/
- (void)setStrokeTextureRepeatTimes:(unsigned int)horRepeatTimes VerRepeatTimes:(unsigned int)verRepeatTimes;

/*! \if ENGLISH
 *  \brief Sets whether the stroke enables dynamic effects.
 *  \param isAnimated Whether there is dynamic effect.
 *  \else
 *  \brief 设置线条是否启用动态效果
 *  \param isAnimated 有无动态效果
 *  \endif
*/
- (void)setStrokeAnimated:(bool)isAnimated;

/*! \if ENGLISH
 *  \brief Sets the stroke dynamics rate.
 *  \param speed Dynamic effect rate
 *  \else
 *  \brief 设置线条动态效果速率
 *  \param speed 动态效果速率
 *  \endif
*/
- (void)setStrokeAnimationSpeed:(float)speed;

/*! \if ENGLISH
 *  \brief Sets the analog signal category used by line dynamics: sin, cos, inverted sin, inverted cos
 *  \param analogType Analog signal category
 *  \else
 *  \brief 设置线条动态效果使用的模拟信号类别：sin, cos, inverted sin, inverted cos
 *  \param analogType 模拟信号类别
 *  \endif
*/
- (void)setStrokeAnalogType:(NvsStrokeAnalogType)analogType;

/*! \if ENGLISH
 *  \brief Sets the analog signal amplitude.
 *  \param amplitude Analog signal amplitude
 *  \else
 *  \brief 设置模拟信号振幅
 *  \param amplitude 模拟信号振幅
 *  \endif
*/
- (void)setStrokeAnalogAmplitude:(float)amplitude;

/*! \if ENGLISH
 *  \brief Sets the analog signal period.
 *  \param period Analog signal period
 *  \else
 *  \brief 设置模拟信号周期
 *  \param period 模拟信号周期
 *  \endif
*/
- (void)setStrokeAnalogPeriod:(float)period;

/*! \if ENGLISH
 *  \brief Removes all strokes.
 *  \else
 *  \brief 移除所有线条
 *  \endif
*/
- (void)removeAllStroke;

/*! \if ENGLISH
 *  \brief Removes the previous stroke
 *  \else
 *  \brief 移除上一条线
 *  \endif
*/
- (void)removeLastStroke;

/*! \if ENGLISH
 *  \brief Adds a stroke.
 *  \param path Collection of consecutive points
 *  \else
 *  \brief 增添一条线
 *  \param path 连续点的集合
 *  \endif
*/
- (void)addStroke:(NSArray *)path;

/*! \if ENGLISH
 *  \brief Extends the last stroke.
 *  \param path Collection of consecutive points
 *  \else
 *  \brief 延长最后一条线
 *  \param path 连续点的集合
 *  \endif
*/
- (void)appendStroke:(NSArray *)path;

@end

