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

/*!
 *  \brief 手绘特效上下文
 * 
 *  手绘特效上下文类可视作调整手绘效果的入口。可以调整手绘线条的路径，宽度，纹理等
 *  \warning NvsPaintingEffectContext类中，所有public API都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsPaintingEffectContext : NSObject

- (void)setInternalContext:(void *)internalContext;

/*!
 *  \brief 设置线条宽度
 *  \param width 线条宽度
 */
- (void)setStrokeWidth:(float)width;

/*!
 *  \brief 设置线条首尾样式
 *  \param capStyle 线条首尾样式
 */
- (void)setStrokeCapStyle:(NvsStrokeCapStyle)capStyle;

/*!
 *  \brief 设置线条弯曲部分衔接样式
 *  \param jointStyle 线条衔接样式
 */
- (void)setStrokeJointStyle:(NvsStrokeJointStyle)jointStyle;

/*!
 *  \brief 设置线条填充模式：颜色，纹理
 *  \param fillMode 填充模式
 */
- (void)setStrokeFillMode:(NvsStrokeFillMode)fillMode;

/*!
 *  \brief 设置线条填充颜色
 *  \param gradient 线条填充颜色
 */
- (void)setStrokeGradient:(NvsColor)gradient;

/*!
 *  \brief 设置线条纹理文件路径
 *  \param filePath 线条纹理文件路径
 */
- (void)setStrokeTextureFilePath:(NSString *)filePath;

/*!
 *  \brief 设置线条纹理附件方式
 *  \param warpType 线条纹理附加方式
 */
- (void)setStrokeTextureWarpType:(NvsStrokeTextureWarpType)warpType;

/*!
 *  \brief 设置线条纹理重复次数
 *  \param horRepeatTimes 横向纹理重复次数
 *  \param verRepeatTimes 纵向纹理重复次数
 */
- (void)setStrokeTextureRepeatTimes:(unsigned int)horRepeatTimes VerRepeatTimes:(unsigned int)verRepeatTimes;

/*!
 *  \brief 设置线条是否启用动态效果
 *  \param isAnimated 有无动态效果
 */
- (void)setStrokeAnimated:(bool)isAnimated;

/*!
 *  \brief 设置线条动态效果速率
 *  \param speed 动态效果速率
 */
- (void)setStrokeAnimationSpeed:(float)speed;

/*!
 *  \brief 设置线条动态效果使用的模拟信号类别：sin, cos, inverted sin, inverted cos
 *  \param analogType 模拟信号类别
 */
- (void)setStrokeAnalogType:(NvsStrokeAnalogType)analogType;

/*!
 *  \brief 设置模拟信号振幅
 *  \param amplitude 模拟信号振幅
 */
- (void)setStrokeAnalogAmplitude:(float)amplitude;

/*!
 *  \brief 设置模拟信号周期
 *  \param period 模拟信号周期
 */
- (void)setStrokeAnalogPeriod:(float)period;

/*!
 *  \brief 删除所有线条
 */
- (void)removeAllStroke;

/*!
 *  \brief 删除上一条线
 */
- (void)removeLastStroke;

/*!
 *  \brief 增添一条线
 *  \param path 连续点的集合
 */
- (void)addStroke:(NSArray *)path;

/*!
 *  \brief 延长最后一条线
 *  \param path 连续点的集合
 */
- (void)appendStroke:(NSArray *)path;

@end

