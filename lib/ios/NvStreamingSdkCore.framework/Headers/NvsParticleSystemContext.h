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
 *  \brief Particle effect context
 *
 *  The particle effect context class can be Regarded as the entry point for adjusting particle effects. Users can adjust the position, size, emission rate, etc. of the particle emitter.
 *  \warning In the NvsParticleSystemContext class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 粒子特效上下文
 *
 *  粒子特效上下文类可视作调整粒子效果的入口。可以调整粒子发射器的位置，大小，发射速率等
 *  \warning NvsParticleSystemContext类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsParticleSystemContext : NSObject

- (void)setInternalContext:(void *)internalContext;

/*! \if ENGLISH
 *  \brief Sets a particle emitter to be valid or invalid.
 *  \param emitterName The name of the particle emitter
 *  \param enable Be valid or invalid
 *  \else
 *  \brief 设置某一个粒子发生器有效或者无效
 *  \param emitterName 粒子发生器名字
 *  \param enable 有效或者无效
 *  \endif
*/
- (void)setEmitterEnabled:(NSString *)emitterName emitterEnable:(bool)enable;

/*! \if ENGLISH
 *  \brief Sets the position of the particle emitter
 *  \param emitterName The name of the particle emitter
 *  \param x The position of X
 *  \param y The position of Y
 *  \else
 *  \brief 设置某一个粒子发生器位置
 *  \param emitterName 粒子发生器名字
 *  \param x x位置值
 *  \param y y位置值
 *  \endif
*/
- (void)setEmitterPosition:(NSString *)emitterName emitterPositionX:(float)x emitterPositionY:(float)y;

/*! \if ENGLISH
 *  \brief Sets the position of a particle emitter at a certain time.
 *  \param emitterName The name of the particle emitter
 *  \param time A certain time
 *  \param x The position of X
 *  \param y The position of Y
 *  \else
 *  \brief 设置某一个粒子发生器某一时间点的位置
 *  \param emitterName 粒子发生器名字
 *  \param time 某一时间点
 *  \param x x位置值
 *  \param y y位置值
 *  \endif
*/
- (void)appendPositionToEmitterPositionCurve:(NSString *)emitterName curveTime:(float)time emitterPositionX:(float)x emitterPositionY:(float)y;

/*! \if ENGLISH
 *  \brief Sets the speed gain of the particle emitter.
 *  \param emitterName The name of the particle emitter
 *  \param gain Speed gain
 *  \else
 *  \brief 设置某一个粒子发生器速度增益
 *  \param emitterName 粒子发生器名字
 *  \param gain 速度增益
 *  \endif
*/
- (void)setEmitterRateGain:(NSString *)emitterName emitterGain:(float)gain;

/*! \if ENGLISH
 *  \brief Sets the size gain of the particle emitter.
 *  \param emitterName The name of the particle emitter
 *  \param gain Size gain
 *  \else
 *  \brief 设置某一个粒子发生器大小增益
 *  \param emitterName 粒子发生器名字
 *  \param gain 大小增益
 *  \endif
*/
- (void)SetEmitterParticleSizeGain:(NSString *)emitterName emitterGain:(float)gain;

@end

