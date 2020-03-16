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
/*! \file NvsVideoClip.h
 */
#pragma once

#import "NvsCommonDef.h"
#import "NvsClip.h"
#import "NvsCustomVideoFx.h"

/*! \if ENGLISH
 *  \brief The type of the video clip
 *  \else
 *  \brief 视频片段类型
 *  \endif
*/
typedef enum NvsVideoClipType {
    NvsVideoClipType_AV = 0,   //!< \if ENGLISH Audio and video \else 音视频 \endif
    NvsVideoClipType_Image,    //!< \if ENGLISH Image \else 图片 \endif
} NvsVideoClipType;

/*! \if ENGLISH
 *  \brief The motion mode of the clip.
 *  \else
 *  \brief 图片片段运作模式
 *  \endif
 *  \since 1.1.0
*/
typedef enum {
    NvsStreamingEngineImageClipMotionMode_LetterBoxZoomIn = 0,  //!< \if ENGLISH Zoom in \else 放大 \endif
    NvsStreamingEngineImageClipMotionMode_LetterBoxZoomOut,     //!< \if ENGLISH Zoom out\else 缩小 \endif
    NvsStreamingEngineImageClipMotionMode_ROI                   //!< \if ENGLISH The image clip's ROI(Region Of Interesting) \else 图片片段ROI(Region Of Interesting) \endif      //!< 图片片段ROI(Region Of Interesting)
} NvsStreamingEngineImageClipMotionMode;

/*! \if ENGLISH
 *  \brief Background mode
 *  \else
 *  \brief 背景模式
 *  \endif
*/
typedef enum NvsSourceBackgroundMode {
    NvsSourceBackgroundModeColorSolid = 0,  //!< \if ENGLISH Solid color \else 纯色 \endif
    NvsSourceBackgroundModeBlur,            //!< \if ENGLISH Blur \else 模糊 \endif
} NvsSourceBackgroundMode;

typedef enum NvsClipWrapMode {
    NvsClipWrapMode_Repeat_LastFrame = 0,
    NvsClipWrapMode_Repeat_FirstFrame = 1,
    NvsClipWrapMode_Repeat = 2
} NvsClipWrapMode;

typedef enum NvsExtraVideoRotation {
    NvsExtraVideoRotation_0 = 0,
    NvsExtraVideoRotation_90 = 1,
    NvsExtraVideoRotation_180 = 2,
    NvsExtraVideoRotation_270 = 3
} NvsExtraVideoRotation;

@class NvsVideoFx;

/*! \if ENGLISH
 *  \brief The video clip is description of the video file.
 *
 *  The video clip source can be a video or an image. Each video clip can be modified for its in and out point value, the speed of playing, and the pan and scan.
 *  When editing a video, users can add or insert multiple video effects by the type of effect (built-in, package and beauty).
 *  When adding a resource package effect, users have to install it firstly. When installation is successful, users can get the package Id to use, and the built-in effect can be used only by obtaining the effect name.
 *  \warning In the NvsVideoClip class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 视频片段，对视频文件的描述
 *
 *  视频片段源可以是视频或者图片。每个视频片段可以修改其裁剪入点、裁剪出点以及播放速度，也可以设置摇摄和扫描。编辑视频时，可以按特效类型的不同（内建特效，包裹式特效，美颜特效）添加或者插入多个视频特效。
 *  添加资源包特效时，都得先安装，安装成功后获取packageId才能使用，而内建特效(builtin)只需获取特效名称即可使用。
 *  \warning NvsVideoClip类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsVideoClip : NvsClip


@property (readonly) NvsVideoClipType videoType;                              //!< \if ENGLISH Type of the video clip. \else 视频片段类型 \endif


@property (readonly) NvsRoleInTheme roleInTheme;                              //!< \if ENGLISH The clip's role in themes (General, title and trailer). \else 视频片段在主题中角色(通用、片头、片尾) \endif

@property (nonatomic) NvsStreamingEngineImageClipMotionMode imageMotionMode;  //!< \if ENGLISH The motion mode of the image clip. \else 图片片段运作模式 \endif \since 1.1.0

@property (nonatomic) BOOL imageMotionAnimationEnabled;                       //!< \if ENGLISH Whether it supports animation of images. \else 是否支持图片动画 \endif \since 1.1.0

@property (readonly) NvsRect startROI;                                        //!< \if ENGLISH Image clip's starting ROI (Region Of Interesting)\else 图片片段起始ROI \endif \since 1.1.0

@property (readonly) NvsRect endROI;                                          //!< \if ENGLISH Image clip's ending ROI (Region Of Interesting) \else 图片片段结束ROI \endif \since 1.1.0

/*! \if ENGLISH
 *  \brief Sets whether the clip is reversed.
 *
 *  Note: If users use the reversed clip to playback,please ensure that the current video file is a I frame video, otherwise the efficiency of the reversed playback is extremely low and completely intolerable! Users can use the Recording flag of
 *  Uses STREAMING_ENGINE_RECORDING_FLAG_VIDEO_INTRA_FRAME_ONLY for the Meishe SDK to generate a I frame video file.
 *  If the files which import from other places cannot be guaranteed to be a I frame video and users want to use the reversed function, users can use the Meishe transcoding SDK to directly transcode the original video into a reversed file and then use the reversed file.
 *  Note: Make sure the video files locate in the sandbox of the app that users need to reverse.
 *  \param playInReverse Whether the clip is reversed.
 *  \else
 *  \brief 设置片段是否倒放
 *
 *  注意：使用片段倒放请确保当前视频文件为全I帧视频，否则倒放播放效率极低完全无法忍受！可以利用美摄SDK录制标志
 *  STREAMING_ENGINE_RECORDING_FLAG_VIDEO_INTRA_FRAME_ONLY来产生出全I帧视频文件。如果从别的地方
 *  导入的文件无法保证为全I帧视频又想用倒放功能则可以使用美摄的转码SDK直接将原始视频转码为一个倒放的文件再使用。
 *  注意：请确保需要倒放的视频文件位于APP的沙盒中
 *  \param playInReverse 片段是否倒放
 *  \endif
 *  \since 1.5.1
 *  \sa getPlayInReverse
*/
- (void)setPlayInReverse:(BOOL)playInReverse;

/*! \if ENGLISH
 *  \brief Gets whether the clip is reversed.
 *  \return Returns the BOOL value whether the clip is reversed.
 *  \else
 *  \brief 获取片段是否倒放
 *  \return 返回片段是否倒放
 *  \endif
 *  \since 1.5.1
 *  \sa setPlayInReverse
*/
- (BOOL)getPlayInReverse;

/*! \if ENGLISH
 *  \brief Sets the video's extra rotation angle.
 *  \param rotation Extra rotation angle
 *  \else
 *  \brief 设置视频额外旋转角度
 *  \param rotation 额外旋转角度
 *  \endif
 *  \sa getExtraVideoRotation
*/
- (void)setExtraVideoRotation:(NvsExtraVideoRotation)rotation;

/*! \if ENGLISH
 *  \brief Sets the video's extra rotation angle.
 *  \param rotation Extra rotation angle
 *  \else
 *  \brief 设置视频额外旋转角度
 *  \param rotation 额外旋转角度
 *  \param rotateROI 是否旋转ROI运动方向
 *  \endif
 *  \sa getExtraVideoRotation
*/
- (void)setExtraVideoRotation:(NvsExtraVideoRotation)rotation rotateROI:(bool)rotateROI;

/*! \if ENGLISH
 *  \brief Gets the video's extra rotation angle.
 *  \return Return the extra rotation angle which obtains.
 *  \else
 *  \brief 获取视频额外旋转角度
 *  \return 返回获取额外旋转角度
 *  \endif
 *  \sa setExtraVideoRotation:
*/
- (NvsExtraVideoRotation)getExtraVideoRotation;

/*! \if ENGLISH
 *  \brief Sets the pan and scan.
 *
 *  The pan and scan functions are used to adapt the position and size of the video's image on the display window. For details, please refer to the topic of [Pan and Scan] (\ref Pan_Scan.md).
 *  \param pan 摇摄
 *  \param scan 扫描
 *  \else
 *  \brief 设置摇摄和扫描
 *
 *  摇摄和扫描功能是用来适配图像在显示窗口上的位置与大小的。具体请参见[摇摄与扫描(Pan and Scan)] (\ref Pan_Scan.md)专题。
 *  \param pan 摇摄
 *  \param scan 扫描
 *  \endif
 *  \sa getPan:andScan:
*/
- (void)setPan:(float)pan andScan:(float)scan;

/*! \if ENGLISH
 *  \brief Gets the pan and scan.
 *  \param pan Output the panning value
 *  \param scan Output the scanning value
 *  \else
 *  \brief 获取摇摄和扫描
 *  \param pan 输出摇摄值
 *  \param scan 输出扫描值
 *  \endif
 *  \sa setPan:andScan:
*/
- (void)getPan:(float *)pan andScan:(float *)scan;

/*! \if ENGLISH
 *  \brief Sets the background mode.
 *  \param sourceBackgroundMode the background mode
 *  \else
 *  \brief 设置背景模式
 *  \param sourceBackgroundMode 背景模式
 *  \endif
 *  \sa getSourceBackgroundMode:
*/
- (void)setSourceBackgroundMode:(NvsSourceBackgroundMode) sourceBackgroundMode;

/*! \if ENGLISH
 *  \brief Gets the background mode.
 *  \return Background mode
 *  \else
 *  \brief 获取背景模式
 *  \return 背景模式
 *  \endif
 *  \sa setSourceBackgroundMode:sourceBackgroundMode:
*/
- (NvsSourceBackgroundMode)getSourceBackgroundMode;

/*! \if ENGLISH
 *  \brief Sets the background color.
 *  \param color the background color
 *  \else
 *  \brief 设置片段背景颜色
 *  \param color 背景颜色
 *  \endif
 *  \sa getSourceBackgroundColor:
 *  \since 2.11.1
 */
- (void)setSourceBackgroundColor:(NvsColor *)color;

/*! \if ENGLISH
 *  \brief Gets the background color.
 *  \return Background color
 *  \else
 *  \brief 获取背景颜色
 *  \return 背景颜色
 *  \endif
 *  \sa setSourceBackgroundColor:
 *  \since 2.11.1
 */
- (NvsColor)getSourceBackgroundColor;

/*! \if ENGLISH
 *  \brief Sets whether the video disables the approximate scale cropping of the screen.
 *  \param disable whether disable or not.
 *  \else
 *  \brief 设置是否禁止画面的近似比例裁剪
 *  \param disable 是否禁止
 *  \endif
 *  \sa isAmbiguousCropDisabled:
*/
- (void)disableAmbiguousCrop:(BOOL) disable;

/*! \if ENGLISH
 *  \brief Gets whether the video disables the approximate scale cropping of the screen.
 *  \return Whether the video disables the approximate scale cropping of the screen.
 *  \else
 *  \brief 获取是否禁止画面的近似比例裁剪
 *  \return 是否禁止画面的近似比例裁剪
 *  \endif
 *  \sa disableAmbiguousCrop:disable:
*/
- (BOOL)isAmbiguousCropDisabled;

/*! \if ENGLISH
 *  \brief Sets the motion ROI(Region Of Interesting) for the Image clip.
 *
 *  For details, please refer to [The Topics of the Image Clip's ROI](\ref ImageROI.md)
 *  \param startROI Image clip's starting ROI
 *  \param endROI Image clip's terminating ROI
 *  \else
 *  \brief 设置图片片段动态移动ROI
 *
 *  具体情况请参见[图片片段ROI专题] (\ref ImageROI.md)
 *  \param startROI 图片片段起始ROI
 *  \param endROI 图片片段终止ROI
 *  \endif
 *  \since 1.1.0
 *  \sa setPan:andScan:
*/
- (void)setImageMotionROI:(NvsRect *)startROI endROI:(NvsRect *)endROI;

/*! \if ENGLISH
 *  \brief Sets the clip's loop mode.
 *  \param wrapMode Loop mode
 *  \else
 *  \brief 设置片段循环模式
 *  \param wrapMode 循环模式
 *  \endif
 *  \since 2.2.3
 *  \sa getClipWrapMode
*/
- (void)setClipWrapMode:(NvsClipWrapMode)wrapMode;

/*! \if ENGLISH
 *  \brief Gets the clip's loop mode.
 *  \return Returns the loop mode.
 *  \else
 *  \brief 获取视频循环模式
 *  \return 返回循环模式
 *  \endif
 *  \since 2.2.3
 *  \sa setClipWrapMode
*/
- (NvsClipWrapMode)getClipWrapMode;

/*! \if ENGLISH
 *  \brief Changes the playback speed of the clip.
 *  \param startSpeed start playback speed.
 *  \param endSpeed end playback speed.
 *  \param keepAudioPitch Keep the tone unchanged.
 *  \warning This interface will cause the streaming engine state to jump to the engine stop state, see [Engine Change Feature] (\ref EngineChange.md) for details.
 *  \sa getStartSpeed
 *  \since 2.11.0
 *  \else
 *  \brief 改变片段的播放速度
 *  \param startSpeed 开始播放速度
 *  \param endSpeed 结束播放速度
 *  \param keepAudioPitch 保持音调不变
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \sa getEndSpeed,
 *  \since 2.11.0
 *	\endif
 */
- (void)changeVariableSpeed:(double)startSpeed endSpeed:(double)endSpped keepAudioPitch:(BOOL)keepAudioPitch;

/*! \if ENGLISH
 *  \brief Get the playback speed of the clip.
 *
 *  \brief The default value is 1, which means that it plays at normal speed; the value less than 1 means slower playback; the value greater than 1 means faster playback.
 *  \return Returns the playback start speed of the current clip.
 *  \sa changeVariableSpeed:endSpeed:keepAudioPitch:
 *  \since 2.11.0
 *  \else
 *  \brief 默认值为1，表示按正常速度播放;小于1的值表示慢放;大于1的值表示快放
 *  \return 返回当前片段的起始播放速度
 *  \sa changeVariableSpeed:endSpeed:keepAudioPitch:
 *  \since 2.11.0
 *	\endif
*/
-(double)getStartSpeed;

/*! \if ENGLISH
*  \brief Get the playback speed of the clip.
*
*  \brief The default value is 1, which means that it plays at normal speed; the value less than 1 means slower playback; the value greater than 1 means faster playback.
*  \return Returns the playback end speed of the current clip.
*  \sa changeVariableSpeed:endSpeed:keepAudioPitch:
*  \since 2.11.0
*  \else
*  \brief 默认值为1，表示按正常速度播放;小于1的值表示慢放;大于1的值表示快放
*  \return 返回当前片段的结束播放速度
*  \sa changeVariableSpeed:endSpeed:keepAudioPitch:
*  \since 2.11.0
*	\endif
*/
- (double)getEndSpeed;

/*! \if ENGLISH
 *  \brief Appends the built-in effect on the clip.
 *  \param fxName The effect name,if users get the video effect name, please refer to [getAllBuiltinVideoFxNames()] (@ref NvsStreamingContext::getAllBuiltinVideoFxNames) or [The List of Built-in Effect Name] (\ref FxNameList.md)
 *  \return Returns the appended NvsVideoFx object.
 *  \else
 *  \brief 在片段上追加内嵌式特效
 *  \param fxName 特效名称。获取视频特效名称，请参见[getAllBuiltinVideoFxNames()] (@ref NvsStreamingContext::getAllBuiltinVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)
 *  \return 返回追加的视频特效对象
 *  \endif
 *  \sa insertBuiltinFx:fxIndex:
 *  \sa appendBeautyFx
 *  \sa appendPackagedFx:
*/
- (NvsVideoFx *)appendBuiltinFx:(NSString *)fxName;

/*! \if ENGLISH
 *  \brief Inserts a built-in effect at the specified effect index on the clip.
 *  \param fxName The effect name,if users get the video effect name, please refer to [getAllBuiltinVideoFxNames()] (@ref NvsStreamingContext::getAllBuiltinVideoFxNames) or [The List of Built-in Effect Name] (\ref FxNameList.md)
 *  \param fxIndex The specified effect index
 *  \return Returns the inserted NvsVideoFx object.
 *  \else
 *  \brief 在片段上指定特效索引处插入内嵌式特效
 *  \param fxName 特效名称。获取视频特效名称，请参见[getAllBuiltinVideoFxNames()] (@ref NvsStreamingContext::getAllBuiltinVideoFxNames)或[内建特效名称列表] (\ref FxNameList.md)
 *  \param fxIndex 指定特效索引
 *  \return 返回插入的视频特效对象
 *  \endif
 *  \sa appendBuiltinFx:
 *  \sa insertPackagedFx:fxIndex:
 *  \sa insertBeautyFx:
*/
- (NvsVideoFx *)insertBuiltinFx:(NSString *)fxName fxIndex:(unsigned int)fxIndex;

/*! \if ENGLISH
 *  \brief Appends the resource package effect on the clip.
 *  \param fxPackageId The resource package ID of effect
 *  \return Returns the appended NvsVideoFx object.
 *  \else
 *  \brief 在片段上追加资源包特效
 *  \param fxPackageId 特效资源包ID
 *  \return 返回追加的视频特效对象
 *  \endif
 *  \sa appendBeautyFx
 *  \sa appendBuiltinFx:
 *  \sa insertPackagedFx:fxIndex:
*/
- (NvsVideoFx *)appendPackagedFx:(NSString *)fxPackageId;

/*! \if ENGLISH
 *  \brief Inserts the resource package effect at the specified effect index on the clip.
 *  \param fxPackageId The resource package ID of effect.
 *  \param fxIndex The specified effect index
 *  \return Returns the inserted NvsVideoFx object.
 *  \else
 *  \brief 在片段上指定特效索引处插入包裹特效
 *  \param fxPackageId 包裹特效Id
 *  \param fxIndex 插入特效索引
 *  \return 返回插入的视频特效对象
 *  \endif
 *  \sa insertBeautyFx:
 *  \sa appendPackagedFx:
 *  \sa insertBuiltinFx:fxIndex:
*/
- (NvsVideoFx *)insertPackagedFx:(NSString *)fxPackageId fxIndex:(unsigned int)fxIndex;

/*! \if ENGLISH
 *  \brief Appends the custom video effect on the clip.
 *  \param customVideoFxRender The renderer interface of the custom video effect which users implement
 *  \return Returns the appended NvsVideoFx object.
 *  \else
 *  \brief 在片段上追加自定义视频特效
 *  \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
 *  \return 返回追加的视频特效对象
 *  \endif
 *  \since 1.7.0
*/
- (NvsVideoFx *)appendCustomFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender;

/*! \if ENGLISH
 *  \brief Inserts the custom video effect at the specified effect index on the clip.
 *  \param customVideoFxRender The renderer interface of the custom video effect which users implement
 *  \param fxIndex The specified effect index
 *  \return Returns the inserted NvsVideoFx object.
 *  \else
 *  \brief 在片段上指定特效索引处插入自定义视频特效
 *  \param customVideoFxRender 用户实现的自定义视频特效渲染器接口
 *  \param fxIndex 插入特效索引
 *  \return 返回插入的视频特效对象
 *  \endif
 *  \since 1.7.0
*/
- (NvsVideoFx *)insertCustomFx:(id<NvsCustomVideoFxRenderer>)customVideoFxRender fxIndex:(unsigned int)fxIndex;

/*! \if ENGLISH
 *  \brief Appends the beauty effect on the clip.
 *  \return Returns the appended NvsVideoFx object.
 *  \else
 *  \brief 在片段上追加美颜特效
 *  \return 返回追加的视频特效对象
 *  \endif
 *  \sa insertBeautyFx:
 *  \sa appendPackagedFx:
 *  \sa appendBuiltinFx:
*/
- (NvsVideoFx *)appendBeautyFx;

/*! \if ENGLISH
 *  \brief Inserts the beauty effect at the specified effect index on the clip.
 *  \param fxIndex The specified effect index
 *  \return Returns the inserted NvsVideoFx object.
 *  \else
 *  \brief 在片段上指定特效索引处插入美颜特效
 *  \param fxIndex 指定特效索引
 *  \return 返回插入的视频特效对象
 *  \endif
 *  \sa appendBeautyFx
 *  \sa insertPackagedFx:fxIndex:
 *  \sa insertBuiltinFx:fxIndex:
*/
- (NvsVideoFx *)insertBeautyFx:(unsigned int)fxIndex;

/*! \if ENGLISH
 *  \brief Removes the special effect.
 *  \param fxIndex The effect index
 *  \return Determines whether the removal is successful. YES means that it's successful; NO means it fails.
 *  \else
 *  \brief 移除特效
 *  \param fxIndex 特效索引
 *  \return 判断是否移除成功。返回YES则移除成功，NO则失败。
 *  \endif
 *  \sa removeAllFx
*/
- (BOOL)removeFx:(unsigned int)fxIndex;

/*! \if ENGLISH
 *  \brief Remove all the effects.
 *  \return Determines whether the removal is successful. YES means that it's successful; NO means it fails.
 *  \else
 *  \brief 移除所有特效
 *  \return 判断是否移除成功。返回YES则移除成功，NO则失败。
 *  \endif
 *  \sa removeFx:
*/
- (BOOL)removeAllFx;

/*! \if ENGLISH
 *  \brief Gets the special effect by index.
 *  \param fxIndex The index of the special effect
 *  \return Returns the obtained NvsVideoFx object.
 *  \else
 *  \brief 通过索引获取特效
 *  \param fxIndex 特效索引
 *  \return 返回获取的视频特效对象
 *  \endif
*/
- (NvsVideoFx *)getFxWithIndex:(unsigned int)fxIndex;

@end
