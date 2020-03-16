//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Feb 17. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsFx.h"
#import <CoreGraphics/CGGeometry.h>

/*! \if ENGLISH
 *  \brief Timeline animation sticker, which is animated sticker.
 *
 *  Timeline animation sticker is a kind of beauty effect used in video editing. Overlaying the stickers on the video will produce special effects.
 *  When editing a video, users can add and remove animated stickers through the Timeline. If the added sticker position is not what users want, users can also change the position as they like.
 *  \warning In the NvsTimelineAnimatedSticker class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 时间线动画贴纸，带有动画效果的贴纸
 *
 *  时间线动画贴纸是视频编辑时使用的一种美化特效，叠加在视频上会产生一些特殊效果。编辑视频时，可通过时间线(Time Line)来添加和移除动画贴纸。如果添加的贴纸位置不合理，还可进行调整移动。
 *  \warning NvsTimelineAnimatedSticker类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsTimelineAnimatedSticker : NvsFx

@property (readonly) BOOL hasAudio;             //!< \if ENGLISH Whether it contains audio. \else 是否含有音频 \endif \since 2.0.3
@property (readonly) BOOL isPanoramic;          //!< \if ENGLISH Whether It's a panorama animated sticker. \else 是否为全景图动画贴纸贴纸 \endif \since 1.6.0
@property (nonatomic) BOOL clipAffinityEnabled; //!< \if ENGLISH Whether to open the affinity with clip. \else 是否开启与clip的亲和关系 \endif \since 1.7.1
@property (readonly) int64_t inPoint;           //!< \if ENGLISH The in point of the animated sticker on the timeline (in microseconds). \else 动画贴纸在时间线上显示的入点（单位微秒） \endif
@property (readonly) int64_t outPoint;          //!< \if ENGLISH The out point of the animated sticker on the timeline (in microseconds). \else 动画贴纸在时间线上显示的出点（单位微秒） \endif
@property (readonly) int64_t defaultDuration;   //!< \if ENGLISH Animation sticker default length (in microseconds). \else 动画贴纸默认长度（单位微秒） \endif \since 2.1.0

/*! \if ENGLISH
 *  \brief Gets the animated sticker package ID.
 *  \return Returns the animated sticker package ID.
 *  \else
 *  \brief 获取动画贴纸包ID
 *  \return 返回获取动画贴纸包ID
 *  \endif
 *  \since 1.7.0
*/
- (NSString *)getAnimatedStickerPackageId;

/*! \if ENGLISH
 *  \brief Changes the in point of the animated sticker on the timeline.
 *  \param newInPoint The new in point of the animated sticker on the timeline (in microseconds).
 *  \return Returns the in point value (in microseconds) of the animated sticker displayed on the timeline.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变动画贴纸在时间线上显示的入点
 *  \param newInPoint 动画贴纸在时间线上的新的入点（单位微秒）
 *  \return 返回动画贴纸在时间线上的显示的入点值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeOutPoint:
 *  \sa movePosition:
*/
- (int64_t)changeInPoint:(int64_t)newInPoint;

/*! \if ENGLISH
 *  \brief Changes the out point of the animated sticker on the timeline.
 *  \param newOutPoint The new out point of the animated sticker on the timeline (in microseconds).
 *  \return Returns the point value (in microseconds) of the animated sticker on the timeline.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief
 *  \brief 改变动画贴纸在时间线上显示的出点
 *  \param newOutPoint 动画贴纸在时间线上的新的出点（单位微秒）
 *  \return 返回动画贴纸在时间线上的显示的出点值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeInPoint:
 *  \sa movePosition:
*/
- (int64_t)changeOutPoint:(int64_t)newOutPoint;

/*! \if ENGLISH
 *  \brief Changes the position of the animated sticker on the timeline (the in and out points move the value of "offset" at the same time).
 *  \param offset Offset value which the in and out points changes (in microseconds)
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine] (\ref EngineChange.md).
 *  \else
 *  \brief 改变动画贴纸在时间线上的显示位置(入点和出点同时偏移offset值)
 *  \param offset 入点和出点改变的偏移值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeInPoint:
 *  \sa changeOutPoint:
*/
- (void)movePosition:(int64_t)offset;

/*! \if ENGLISH
 *  \brief Sets zoom.
 *  \param scale Scaling value
 *  \else
 *  \brief 设置缩放
 *  \param scale 缩放值
 *  \endif
 *  \sa getScale
*/
- (void)setScale:(float)scale;

/*! \if ENGLISH
 *  \brief Gets the scaling value.
 *  \return Returns the obtained scaling value.
 *  \else
 *  \brief 获取缩放值
 *  \return 返回获取的缩放值
 *  \endif
 *  \sa setScale:
*/
- (float)getScale;

/*! \if ENGLISH
 *  \brief Sets horizontal flip.
 *  \param flip Whether to flip horizontally. True means it flips horizontally, false doesn't flip.
 *  \else
 *  \brief 设置水平翻转
 *  \param flip 是否水平翻转。true表示水平翻转，false则不翻转
 *  \endif
 *  \sa getHorizontalFlip
*/
- (void)setHorizontalFlip:(bool)flip;

/*! \if ENGLISH
 *  \brief Gets the horizontal flip state.
 *  \return Returns a boolean value indicating a horizontal flip state. True means it flips, false doesn't flip.
 *  \else
 *  \brief 获取水平翻转状态
 *  \return 返回BOOL值，表示水平翻转状态。YES表示已翻转，NO则未翻转
 *  \endif
 *  \sa setHorizontalFlip:
*/
- (BOOL)getHorizontalFlip;

/*! \if ENGLISH
 *  \brief Sets the vertical flip.
 *  \param flip Whether to flip vertically. True means it flip vertically, false doesn't flip.
 *  \else
 *  \brief 设置竖直翻转
 *  \param flip 是否竖直翻转。true表示竖直翻转，false则不翻转
 *  \endif
 *  \sa getVerticalFlip
*/
- (void)setVerticalFlip:(bool)flip;

/*! \if ENGLISH
 *  \brief Gets the vertical flip state.
 *  \return Returns a boolean value indicating a vertical flip state. True means it flips, false doesn't flips.
 *  \else
 *  \brief 获取竖直翻转状态
 *  \return 返回BOOL值，表示竖直翻转状态。YES表示已翻转，NO则未翻转
 *  \endif
 *  \sa setVerticalFlip:
*/
- (BOOL)getVerticalFlip;

/*! \if ENGLISH
 *  \brief Sets the rotation angle.
 *  \param angle The rotation angle.
 *  \else
 *  \brief 设置旋转角度
 *  \param angle 旋转角度
 *  \endif
 *  \sa getRotationZ
*/
- (void)setRotationZ:(float)angle;

/*! \if ENGLISH
 *  \brief Gets the rotation angle.
 *  \return Returns the obtained rotation angle
 *  \else
 *  \brief 获取旋转角度
 *  \return 返回获取的旋转角度
 *  \endif
 *  \sa setRotationZ:
*/
- (float)getRotationZ;

/*! \if ENGLISH
 *  \brief Sets the translation position.
 *  \param translation The translation position
 *  \else
 *  \brief 设置平移
 *  \param translation 平移位置
 *  \endif
 *  \sa getTransltion
 *  \sa translateAnimatedSticker:
*/
- (void)setTranslation:(CGPoint)translation;

/*! \if ENGLISH
 *  \brief Gets the translation position.
 *  \return Returns the CGPoint object representing the translation position.
 *  \else
 *  \brief 获取平移位置
 *  \return 返回CGPoint对象，表示获取的平移位置
 *  \endif
 *  \sa setTranslation:
*/
- (CGPoint)getTransltion;

/*! \if ENGLISH
 *  \brief Translates animation sticker.
 *  \param translationOffset The horizontal and vertical offset values which animated sticker translates.
 *  \else
 *  \brief 平移动画贴纸
 *  \param translationOffset 动画贴纸平移的水平和垂直的偏移值
 *  \endif
 *  \since 1.8.1
 *  \sa setTranslation:
 *  \sa getTranslation
*/
- (void)translateAnimatedSticker:(CGPoint)translationOffset;

/*! \if ENGLISH
 *  \brief Scales the animation sticke
 *  \param scaleFactor The scaled factor
 *  \param anchor The scaled anchor
 *  \else
 *  \brief 缩放动画贴纸
 *  \param scaleFactor 纸缩放因子
 *  \param anchor 缩放锚点
 *  \endif
 *  \since 1.8.1
*/
- (void)scaleAnimatedSticker:(float)scaleFactor anchor:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Rotates the animated sticker.
 *  \param angle The rotation angle
 *  \param anchor The rotation anchor
 *  \else
 *  \brief 旋转动画贴纸
 *  \param angle 旋转角度
 *  \param anchor 旋转锚点
 *  \endif
 *  \since 1.8.1
 *  \sa rotateAnimatedSticker:
*/
- (void)rotateAnimatedSticker:(float)angle anchor:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Rotates the animated sticker with an animated sticker center point as an anchor.
 *  \param angle The rotation angle
 *  \else
 *  \brief 以动画贴纸中心点为锚点旋转动画贴纸
 *  \param angle 旋转角度
 *  \endif
 *  \since 1.8.1
 *  \sa rotateAnimatedSticker:anchor:
*/
- (void)rotateAnimatedSticker:(float)angle;

/*! \if ENGLISH
 *  \brief Gets the original enclosing rectangle.
 *  \return Returns the obtained NvsRect object representing the original enclosing rectangle.
 *  \else
 *  \brief 获取原始包围矩形框
 *  \return 返回NvsRect对象，表示获取的原始包围矩形框
 *  \endif
*/
- (NvsRect)getOriginalBoundingRect;

/*! \if ENGLISH
 *  \brief Gets the vertex position of the original enclosing rectangle of the animated sticker after transformation.
 *  \return Returns the NSArray object, the object type is NSValue, and the actual data type is CGPoint, which contains four vertex positions correspond to the upper left, lower left, lower right, and upper right vertex of the original enclosing rectangle.
 *  \else
 *  \brief 获取动画贴纸原始包围矩形框变换后的顶点位置
 *  \return 返回NSArray对象，里面的对象类型为NSValue，而实际包含的数据类型为CGPoint，包含四个顶点位置，依次分别对应原始包围矩形框的左上，左下，右下，右上顶点
 *  \endif
 *  \since 1.4.0
*/
- (NSArray *)getBoundingRectangleVertices;

/*! \if ENGLISH
 *  \brief Sets the polar angle of the center point on the animated sticker.It's only valid for the panorama animation sticker.
 *  \param centerPolarAngle The polar angle of the center point (in degrees).
 *  \else
 *  \brief 对动画贴纸设置中心点的极角。只对全景图动画贴纸有效
 *  \param centerPolarAngle 中心点的极角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (void)setCenterPolarAngle:(float)centerPolarAngle;

/*! \if ENGLISH
 *  \brief Gets the polar angle of the center point of the animated sticker. It's only valid for the panorama animation sticker.
 *  \return Returns the polar angle of the center point of the animation sticker (in degrees).
 *  \else
 *  \brief 获取动画贴纸中心点的极角。只对全景图动画贴纸有效
 *  \return 返回动画贴纸中心点的极角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (float)getCenterPolarAngle;

/*! \if ENGLISH
 *  \brief Sets the azimuth angle of the center point on the animated sticker. It's only valid for the panorama animation sticker.
 *  \param centerAzimuthAngle The azimuth angle of the center point (in degrees).
 *  \else
 *  \brief 对动画贴纸设置中心点的方位角。只对全景图动画贴纸有效
 *  \param centerAzimuthAngle 中心点的方位角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (void)setCenterAzimuthAngle:(float)centerAzimuthAngle;

/*! \if ENGLISH
 *  \brief Gets the azimuth angle of the center point of the animated sticker. It's only valid for the panorama animation sticker.
 *  \return Returns the azimuth angle of the center point of the animation sticker (in degrees).
 *  \else
 *  \brief 获取动画贴纸中心点的方位角。只对全景图动画贴纸有效
 *  \return 返回动画贴纸中心点的方位角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (float)getCenterAzimuthAngle;

/*! \if ENGLISH
 *  \brief Sets the ranging angle of the polar angle on the animated sticker.It's only valid for the panorama animation sticker.
 *  \param polarAngleRange The ranging angle of the polar angle (in degrees)
 *  \else
 *  \brief 对动画贴纸设置极角的张角。只对全景图动画贴纸有效
 *  \param polarAngleRange 极角的张角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (void)setPolarAngleRange:(float)polarAngleRange;

/*! \if ENGLISH
 *  \brief Gets the ranging angle of the polar angle on the animated sticker. It's only valid for the panorama animation sticker.
 *  \return Returns the ranging angle of the polar angle (in degrees).
 *  \else
 *  \brief 获取动画贴纸极角的张角。只对全景图动画贴纸有效
 *  \return 返回动画贴纸极角的张角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (float)getPolarAngleRange;

/*! \if ENGLISH
 *  \brief Gets the ranging angle which is perpendicular with the polar angle. It's only valid for the panorama animation sticker.
 *  \return Returns the ranging angle which is perpendicular with the polar angle (in degrees).
 *  \else
 *  \brief 获取动画贴纸与极角垂直的张角。只对全景图动画贴纸有效
 *  \return 返回动画贴纸与极角垂直的张角，单位为角度
 *  \endif
 *  \since 1.7.0
*/
- (float)getOrthoAngleRange;

/*! \if ENGLISH
 *  \brief Sets the sticker Z value.
 *  \param value The Z Value of sticker
 *  \else
 *  \brief 设置贴纸Z值
 *  \param value 贴纸Z值
 *  \endif
 *  \sa getZValue
*/
- (void)setZValue:(float)value;

/*! \if ENGLISH
 *  \brief Gets the Z value of the sticker.
 *  \return Returns the Z value.
 *  \else
 *  \brief 获取贴纸Z值
 *  \return 返回贴纸Z值
 *  \endif
 *  \sa setZValue:
*/
- (float)getZValue;

/*! \if ENGLISH
 *  \brief Sets the volume of the sticker.
 *  \param leftVolumeGain The volume gain of left channel
 *  \param rightVolumeGain The volume gain of right channel
 *  \else
 *  \brief 设置贴纸音量
 *  \param leftVolumeGain 左声道音量增益
 *  \param rightVolumeGain 右声道音量增益
 *  \endif
 *  \sa getVolumeGain:rightVolumeGain:
 *  \since 2.0.3
*/
- (void)setVolumeGain:(float)leftVolumeGain rightVolumeGain:(float)rightVolumeGain;

/*! \if ENGLISH
 *  \brief Gets the volume of the sticker.
 *  \param leftVolumeGain Outputs the volume value of the left channel
 *  \param rightVolumeGain Outputs the volume value of the right channel
 *  \else
 *  \brief 获取贴纸音量
 *  \param leftVolumeGain 输出左声道音量值
 *  \param rightVolumeGain 输出右声道音量值
 *  \endif
 *  \sa setVolumeGain:rightVolumeGain:
 *  \since 2.0.3
*/
- (void)getVolumeGain:(float *)leftVolumeGain rightVolumeGain:(float *)rightVolumeGain;

@end

