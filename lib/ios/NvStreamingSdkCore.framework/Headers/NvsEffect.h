//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Sep 7. 2019
//   Author:        NewAuto video team
//================================================================================

#pragma once

#import <Foundation/Foundation.h>
#import "NvsEffectCommonDef.h"

@class NvsArbitraryData;
@class NvsEffectDescription;
@class NvsParticleSystemContext;
@class NvsPaintingEffectContext;


/*!
 *  \brief 特效
 * 
 *   特效类是视频特效(Video Fx)，音频特效(Audio Fx)，音频转场(Audio Transition)，视频转场(Video Transition)等不同类型特效的基类。在SDK框架中，特效是很关键的一部分，
 *  派生自NvsFx类的每种不同类型的特效，或通过片段实例，或时间线实例，或轨道实例来添加，移除和获取。同时，特效类中提供了不同的API接口来设置和获取特效参数类型。
 *  \warning NvsFx类中，所有public API都在UI线程使用！！！
 */
NVS_EXPORT @interface NvsEffect : NSObject

@property (readonly) NvsEffectDescription *description; //!< \if ENGLISH \else 特效描述 \endif

/*!
   \brief setIntVal  设置特效参数整数值

   \param fxParam  参见 [NVS_PARAM_TYPE_INT] (@ref PARAM_TYPE) 特效参数整数类型
   \param val  整数
   \sa getIntVal:
 */
- (void)setIntVal:(NSString *)fxParam val:(int)val;

/*!
   \brief getIntVal  获得特效参数整数值

   \param fxParam  参见 [NVS_PARAM_TYPE_INT] (@ref PARAM_TYPE) 特效参数整数类型

   \return 返回整数值
   \sa setIntVal:val:
*/
- (int)getIntVal:(NSString *)fxParam;

/*!
   \brief setFloatVal  设置特效参数浮点值

   \param fxParam  参见 [NVS_PARAM_TYPE_FLOAT] (@ref PARAM_TYPE) 特效参数浮点数类型
   \param val  浮点值
   \sa getFloatVal:
*/
- (void)setFloatVal:(NSString *)fxParam val:(double)val;

/*!
   \brief getFloatVal  获得特效参数浮点值

   \param fxParam  参见 [NVS_PARAM_TYPE_FLOAT] (@ref PARAM_TYPE) 特效参数浮点数类型

   \return 返回double值
   \sa setFloatVal:val:
*/
- (double)getFloatVal:(NSString *)fxParam;

/*!
   \brief setBooleanVal  设置特效参数布尔值

   \param fxParam  参见 [NVS_PARAM_TYPE_BOOL] (@ref PARAM_TYPE) 特效参数布尔值类型
   \param val  布尔值
   \sa getBooleanVal:
*/
- (void)setBooleanVal:(NSString *)fxParam val:(BOOL)val;

/*!
   \brief getBooleanVal  获得特效参数布尔值

   \param fxParam  参见 [NVS_PARAM_TYPE_BOOL] (@ref PARAM_TYPE) 特效参数布尔值类型

   \return 返回布尔值。YES 成功获取特效参数布尔值；NO 获取参数布尔值失败
   \sa setStringVal:val:
*/
- (BOOL)getBooleanVal:(NSString *)fxParam;

/*!
   \brief setStringVal  设置特效参数字符串值

   \param fxParam  参见 [NVS_PARAM_TYPE_STRING] (@ref PARAM_TYPE) 特效参数字符串类型
   \param val  字符串
   \sa getStringVal:
*/
- (void)setStringVal:(NSString *)fxParam val:(NSString *)val;

/*!
   \brief getStringVal  获得特效参数字符串值

   \param fxParam  参见 [NVS_PARAM_TYPE_STRING] (@ref PARAM_TYPE) 特效参数字符串类型

   \return 返回字符串指针
   \sa setStringVal:val:
*/
- (NSString *)getStringVal:(NSString *)fxParam;

/*!
   \brief setColorVal  设置特效参数颜色值

   \param fxParam  参见 [NVS_PARAM_TYPE_COLOR] (@ref PARAM_TYPE) 特效参数颜色类型
   \param val 颜色值
   \sa getColorVal:
*/
- (void)setColorVal:(NSString *)fxParam val:(NvsEffectColor *)val;

/*!
   \brief getColorVal  获得特效参数颜色值

   \param fxParam  参见 [NVS_PARAM_TYPE_COLOR] (@ref PARAM_TYPE) 特效参数颜色类型

   \return 返回自定义颜色对象
   \sa setColorVal:val:
*/
- (NvsEffectColor)getColorVal:(NSString *)fxParam;

/*!
   \brief setPosition2DVal  设置特效参数二维坐标

   \param fxParam  参见 [NVS_PARAM_TYPE_POSITION2D] (@ref PARAM_TYPE) 特效参数二维坐标类型
   \param val  二维坐标
   \sa getPosition2DVal:
*/
- (void)setPosition2DVal:(NSString *)fxParam val:(NvsEffectPosition2D *)val;

/*!
   \brief getPosition2DVal  获得特效参数二维坐标

   \param fxParam  参见 [NVS_PARAM_TYPE_POSITION2D] (@ref PARAM_TYPE) 特效参数二维坐标类型

   \return 返回二维坐标
   \sa setPosition2DVal:val:
*/
- (NvsEffectPosition2D)getPosition2DVal:(NSString *)fxParam;

/*!
   \brief setPosition3DVal  设置特效参数三维坐标

   \param fxParam  参见 [NVS_PARAM_TYPE_POSITION3D] (@ref PARAM_TYPE) 特效参数三维坐标类型
   \param val  三维坐标
   \sa getPosition3DVal:
*/
- (void)setPosition3DVal:(NSString *)fxParam val:(NvsEffectPosition3D *)val;

/*!
   \brief getPosition3DVal  获得特效参数三维坐标

   \param fxParam  参见 [NVS_PARAM_TYPE_POSITION3D] (@ref PARAM_TYPE) 特效参数三维坐标类型

   \return 返回三维坐标
   \sa setPosition3DVal:val:
*/
- (NvsEffectPosition3D)getPosition3DVal:(NSString *)fxParam;

/*!
   \brief setPosition2DVal  设置特效参数菜单值

   \param fxParam  参见 [NVS_PARAM_TYPE_MENU] (@ref PARAM_TYPE) 特效参数菜单类型
   \param val  字符串
   \sa getMenuVal:
*/
- (void)setMenuVal:(NSString *)fxParam val:(NSString *)val;

/*!
   \brief setPosition2DVal  获得特效参数菜单值

   \param fxParam  参见 [NVS_PARAM_TYPE_MENU] (@ref PARAM_TYPE) 特效参数菜单类型

   \return 返回指向菜单的字符串指针
   \sa setMenuVal:val:
*/
- (NSString *)getMenuVal:(NSString *)fxParam;

/*!
   \brief 设置自定义数据参数值

   \param fxParam 特效的自定义数据参数的类型。
   \param val 字符串
   \sa getMenuVal
*/
- (void)setArbDataVal:(NSString *)fxParam val:(NvsArbitraryData *)val;


/*!
   \brief 设置滤镜的强度
   \param intensity 滤镜强度值，取值范围一般为[0,1]，为0则滤镜无效果，为1则为默认效果
   \since 2.0.2
*/
-(void)setFilterIntensity:(float)intensity;

/*!
   \brief 获得滤镜的强度
   \return 返回滤镜的强度值
   \since 2.0.2
*/
-(float)getFilterIntensity;

/*!
   \brief getParticleSystemContext  获得粒子特效上下文句柄

   \return 返回指向粒子特效上下文句柄指针
*/
- (NvsParticleSystemContext *)getParticleSystemContext;

/*!
   \brief getPaintingEffectContext  获得手绘特效上下文句柄

   \return 返回指向手绘特效上下文句柄指针
*/
- (NvsPaintingEffectContext *)getPaintingEffectContext;

@end
