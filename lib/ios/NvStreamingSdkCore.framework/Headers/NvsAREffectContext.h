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
 *  \brief Built-in face twist zone context.
 *
 *  The built-in face twist zone context contains some APIs about twist zone for face features.
 *  \else
 *  \brief 内置人脸扭区上下文
 *
 *  内置人脸扭区上下文包含一些对人脸特征的扭区接口
 *  \endif
*/
NVS_EXPORT @interface NvsAREffectContext : NSObject

- (void)setInternalContext:(void *)internalContext;

/*! \if ENGLISH
 *  \brief Set the level of eyes which can enlarge.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置大眼程度
 *  \param ratio 缩放程度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setEyeEnlargeRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of face which can shrink.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置瘦脸程度
 *  \param ratio 程度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setShrinkFaceRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of forehead which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置额头高度
 *  \param ratio 高度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setForeheadWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the hairline which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置发际线高度
 *  \param ratio 高度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setHairlineWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the Malar which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置颧骨宽度
 *  \param ratio 宽度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setMalarWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the Jaw which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置下颌大小
 *  \param ratio 大小:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setJawWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the Chin which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置下巴大小
 *  \param ratio 大小:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setChinWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the eyebrow which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置眉毛长度
 *  \param ratio 长度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setEyebrowWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the eye distance which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置眼间距
 *  \param ratio 间距:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setEyeDistanceWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the nose length which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置鼻梁长度
 *  \param ratio 长度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setNoseLengthWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the nose width which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置鼻子宽度
 *  \param ratio 宽度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setNoseWidthWarpRatio:(float)ratio;

/*! \if ENGLISH
 *  \brief Set the level of the mouth width which can warp.
 *  \param ratio Scaling level. The range is [-1,1], and the default is 0.
 *  \else
 *  \brief 设置嘴部宽度
 *  \param ratio 宽度:最大值1,最小值:-1,默认值0
 *  \endif
*/
- (void)setMouthWidthWarpRatio:(float)ratio;

@end

