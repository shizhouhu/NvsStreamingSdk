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
@class NvsARSceneManipulate;

/*! \if ENGLISH
*   \brief Special effects.
*
*   Special effects are the basic types of different types of effects such as Video effect. Special effects are a key part of the SDK framework.
*   It can be added by the createVideoEffect:aspectRatio: method of the NvsEffectSdkContext class.
*   \warning In the NvsEffect class, all public APIs are used in the UI thread! ! !
*   \else
*   \brief 特效
*
*   特效类是视频特效(Video effect)等不同类型特效的基类。在SDK框架中，特效是很关键的一部分，
*   可以通过NvsEffectSdkContext类的createVideoEffect:aspectRatio:方法来添加。
*   \warning NvsEffect类中，所有public API都在UI线程使用！！！
*   \endif
*/
NVS_EXPORT @interface NvsEffect : NSObject

@property (readonly) NvsEffectDescription *description; //!< \if ENGLISH \else 特效描述 \endif

/*! \if ENGLISH
*   \brief Sets effect parameter of integer type.
*   \param fxParam  Effect parameter integer type,please refer to[NVS_PARAM_TYPE_INT] (@ref EFFECT_PARAM_TYPE).
*   \param val Integer value
*   \else
*   \brief 设置特效参数整数值
*   \param fxParam 特效参数整数类型，请参见[NVS_PARAM_TYPE_INT] (@ref EFFECT_PARAM_TYPE)
*   \param val 整形值
*   \endif
*   \sa getIntVal:
*/
- (void)setIntVal:(NSString *)fxParam val:(int)val;

/*! \if ENGLISH
*   \brief Get effect parameter of integer type.
*   \param fxParam  Effect parameter integer type,please refer to[NVS_PARAM_TYPE_INT] (@ref EFFECT_PARAM_TYPE).
*   \return Returns integer value
*   \else
*   \brief 获得特效参数整数值
*   \param fxParam 特效参数整数类型，请参见[NVS_PARAM_TYPE_INT] (@ref EFFECT_PARAM_TYPE)
*   \return 返回整数值
*   \endif
*   \sa setIntVal:val:
*/
- (int)getIntVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets effect parameter of float type.
*   \param fxParam  Effect parameter float type,please refer to[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \param val Float value
*   \else
*   \brief 设置特效参数浮点值
*   \param fxParam 特效参数浮点类型，请参见[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \param val 浮点值
*   \endif
*   \sa getFloatVal:
*/
- (void)setFloatVal:(NSString *)fxParam val:(double)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of float type.
*   \param fxParam Effect parameter float type,please refer to[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \return Returns double value
*   \else
*   \brief 获得特效参数浮点值
*   \param fxParam 特效参数浮点数类型，请参见[NVS_PARAM_TYPE_FLOAT] (@ref EFFECT_PARAM_TYPE)
*   \return 返回double值
*   \endif
*   \sa setFloatVal:val:
*/
- (double)getFloatVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets effect parameter of BOOL type.
*   \param fxParam Effect parameter BOOL type,please refer to[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \param val BOOL value
*   \else
*   \brief 设置特效参数布尔值
*   \param fxParam 特效参数布尔值类型，请参见[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \param val 布尔值
*   \endif
*   \sa getBooleanVal:
*/
- (void)setBooleanVal:(NSString *)fxParam val:(BOOL)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of BOOL type.
*   \param fxParam Effect parameter BOOL type,please refer to[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \return Returns BOOL value,YES means it successfully get the boolean value; NO means it fails.
*   \else
*   \brief 获得特效参数布尔值
*   \param fxParam 特效参数布尔值类型，请参见[NVS_PARAM_TYPE_BOOL] (@ref EFFECT_PARAM_TYPE)
*   \return 返回布尔值。YES 成功获取特效参数布尔值；NO 获取参数布尔值失败。
*   \endif
*   \sa setBooleanVal:val:
*/
- (BOOL)getBooleanVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets effect parameter of string type.
*   \param fxParam Effect parameter string type,please refer to[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \param val String value
*   \else
*   \brief 设置特效参数字符串值
*   \param fxParam 特效参数字符串类型，请参见[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \param val 字符串值
*   \endif
*   \sa getStringVal:
*/
- (void)setStringVal:(NSString *)fxParam val:(NSString *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of string value.
*   \param fxParam Effect parameter string type,please refer to[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \return Returns string value.
*   \else
*   \brief 获得特效参数字符串值
*   \param fxParam 特效参数字符串类型，请参见[NVS_PARAM_TYPE_STRING] (@ref EFFECT_PARAM_TYPE)
*   \return 返回字符串指针
*   \endif
*   \sa setStringVal:val:
*/
- (NSString *)getStringVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets effect parameter of color type.
*   \param fxParam Effect parameter color type,please refer to[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \param val Color value
*   \else
*   \brief 设置特效参数颜色值
*   \param fxParam 特效参数颜色类型，请参见[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \param val 颜色值
*   \endif
*   \sa getColorVal:
*/
- (void)setColorVal:(NSString *)fxParam val:(NvsEffectColor *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of color value.
*   \param fxParam Effect parameter color type,please refer to[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \return Returns Color value.
*   \else
*   \brief 获得特效参数颜色值
*   \param fxParam 特效参数颜色类型，请参见[NVS_PARAM_TYPE_COLOR] (@ref EFFECT_PARAM_TYPE)
*   \return 返回自定义颜色对象
*   \endif
*   \sa setColorVal:val:
*/
- (NvsEffectColor)getColorVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets effect parameter of 2D coordinates type.
*   \param fxParam Effect parameter 2D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \param val 2D coordinates value
*   \else
*   \brief 设置特效参数二维坐标
*   \param fxParam 特效参数二维坐标类型，请参见[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \param val 二维坐标
*   \endif
*   \sa getPosition2DVal:
*/
- (void)setPosition2DVal:(NSString *)fxParam val:(NvsEffectPosition2D *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of 2D coordinates value.
*   \param fxParam Effect parameter 2D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \return Returns 2D coordinates value.
*   \else
*   \brief 获得特效参数二维坐标
*   \param fxParam 特效参数二维坐标类型，请参见[NVS_PARAM_TYPE_POSITION2D] (@ref EFFECT_PARAM_TYPE)
*   \return 返回二维坐标
*   \endif
*   \sa setPosition2DVal:val:
*/
- (NvsEffectPosition2D)getPosition2DVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets effect parameter of 3D coordinates type.
*   \param fxParam Effect parameter 3D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \param val 3D coordinates value
*   \else
*   \brief 设置特效参数三维坐标
*   \param fxParam 特效参数三维坐标类型，请参见[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \param val 三维坐标
*   \endif
*   \sa getPosition3DVal:
*/
- (void)setPosition3DVal:(NSString *)fxParam val:(NvsEffectPosition3D *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of 3D coordinates value.
*   \param fxParam Effect parameter 3D coordinates type,please refer to[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \return Returns 3D coordinates value.
*   \else
*   \brief 获得特效参数三维坐标
*   \param fxParam 特效参数三维坐标类型，请参见[NVS_PARAM_TYPE_POSITION3D] (@ref EFFECT_PARAM_TYPE)
*   \return 返回三维坐标
*   \endif
*   \sa setPosition2DVal:val:
*/
- (NvsEffectPosition3D)getPosition3DVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets effect parameter of menu type.
*   \param fxParam Effect parameter menu type,please refer to[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \param val Menu value
*   \else
*   \brief 设置特效参数菜单值
*   \param fxParam 特效参数菜单类型，请参见[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \param val 字符串
*   \endif
*   \sa getMenuVal:
*/
- (void)setMenuVal:(NSString *)fxParam val:(NSString *)val;

/*! \if ENGLISH
*   \brief Gets effect parameter of menu value.
*   \param fxParam Effect parameter menu type,please refer to[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \return Returns menu value.
*   \else
*   \brief 获得特效参数菜单值
*   \param fxParam 特效参数菜单类型，请参见[NVS_PARAM_TYPE_MENU] (@ref EFFECT_PARAM_TYPE)
*   \return 返回菜单值
*   \endif
*   \sa setMenuVal:val:
*/
- (NSString *)getMenuVal:(NSString *)fxParam;

/*! \if ENGLISH
*   \brief Sets the effect parameter of custom type.
*   \param fxParam The type of custom data parameter for the effect
*   \param val NvsArbitraryData data value
*   \else
*   \brief 设置自定义数据参数值
*   \param fxParam 特效自定义数据参数的类型
*   \param val NvsArbitraryData数据值
*   \endif
*/
- (void)setArbDataVal:(NSString *)fxParam val:(NvsArbitraryData *)val;

/*! \if ENGLISH
*   \brief Set the filter intensity.
*   \param intensity The filter intensity value. The value range is generally [0,1]. 0 means the filter has no effect, the default value is 1.
*   \else
*   \brief 设置滤镜的强度
*   \param intensity 滤镜强度值，取值范围一般为[0,1]，为0则滤镜无效果，为1则为默认效果
*   \endif
*   \sa getFilterIntensity
*   \since 2.0.2
*/
-(void)setFilterIntensity:(float)intensity;

/*! \if ENGLISH
*   \brief Gets the filter intensity.
*   \return Returns the filter intensity.
*   \else
*   \brief 获得滤镜的强度
*   \return 返回滤镜的强度值
*   \endif
*   \sa setFilterIntensity:
*   \since 2.0.2
*/
-(float)getFilterIntensity;

/*! \if ENGLISH
 *  \brief Sets whether the filter is regional.
 *  \param regional whether the filter is regional. true means regional, while false means the opposite.
 *  \else
 *  \brief 设置滤镜是否为局部滤镜
 *  \param regional 是否为局部滤镜，true为局部滤镜，false不是
 *  \endif
 *  \sa getRegional
 *  \since 2.10.1
 */
-(void)setRegional:(BOOL)isRegional;

/*! \if ENGLISH
 *  \brief Gets whether the filter is regional.
 *  \return Returns whether the filter is regional.
 *  \else
 *  \brief 获得滤镜是否为局部滤镜
 *  \return 返回滤镜是否为局部滤镜
 *  \endif
 *  \sa setRegional
 *  \since 2.10.1
 */
-(BOOL)getRegional;

/*! \if ENGLISH
 *  \brief Sets the region of this regional filter.
 *  \param region the effective region of this filter. It is composed with a series of points, which are in NDC coordinate system.
 *  \else
 *  \brief 设置局部滤镜的控制范围
 *  \param region 局部滤镜的控制范围, 由一系列连续的点构成，点的坐标在NDC坐标系中
 *  \endif
 *  \since 2.10.1
 */
-(void)setRegion:(NSArray *)region;

/*! \if ENGLISH
 *  \brief Sets the feather width of this regional filter.
 *  \param featherWidth feather width of regional filter
 *  \else
 *  \brief 设置局部滤镜的羽化宽度
 *  \param featherWidth 局部滤镜的羽化宽度
 *  \endif
 *  \sa getRegionalFeatherWidth
 *  \since 2.10.1
 */
-(void)setRegionalFeatherWidth:(float)featherWidth;

/*! \if ENGLISH
 *  \brief Gets the feather width of this regional filter.
 *  \return Returns the feather width of this regional filter.
 *  \else
 *  \brief 获得局部滤镜的羽化宽度
 *  \return 返回局部滤镜的羽化宽度
 *  \endif
 *  \sa setRegionalFeatherWidth
 *  \since 2.10.1
 */
-(float)getRegionalFeatherWidth;

/*! \if ENGLISH
*   \brief Gets the particle effect context.
*   \return Returns a pointer to a particle effect context.
*   \else
*   \brief 获得粒子特效上下文
*   \return 返回指向粒子特效上下文的指针
*   \endif
*/
- (NvsParticleSystemContext *)getParticleSystemContext;

/*! \if ENGLISH
*   \brief Gets the particle effect context.
*   \return Returns a pointer to a hand-drawn effect context.
*   \else
*   \brief 获得手绘特效上下文
*   \return 返回指向手绘特效上下文指针
*   \endif
*/
- (NvsPaintingEffectContext *)getPaintingEffectContext;

/*! \if ENGLISH
 *  \brief Get the AR scene operation pointer.
 *  \return Return the AR scene operation pointer.
 *  \else
 *  \brief 获得AR场景操作指针
 *  \return 返回指向AR场景操作指针
 *  \endif
*/
- (NvsARSceneManipulate *)getARSceneManipulate;
@end
