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

/*! \file NvsVideoTrack.h 
*/
#pragma once

#import "NvsTrack.h"

@class NvsVideoClip;
@class NvsVideoTransition;

/*! \if ENGLISH
 *  \brief Video track is the collection of video clips.
 *
 *  A video track is an entity that holds video clips. Users can add, insert, and delete multiple video clips on the track. As the clip increases,the video track continues to expand. Video transitions can be used between clips.
 *  The video clip source added to the video track can be video or image. If the clip source is an image, it is recommended to give priority to the path (localIdentifier) in the album.
 *  The loaded image resolution cannot be higher than 1920 * 1080, otherwise it will not be rendered on the Live Window.
 *  If the loaded image causes a black screen,etc., users need to consider reducing the resolution and reloading.
 *  When adding a package transition, users must install it firstly. After the installation, users can get the package Id and then use. For the built-in effects, obtains the names and then uses it.
 *
 *  Note: The index of the video clip starts from 0.
 *  \warning In the NvsVideoTrack class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 视频轨道，视频片段的集合
 *
 *  视频轨道是容纳视频片段的实体，可以添加、插入、删移多个视频片段。视频轨道随着片段的增加不断延展，而片段与片段之间可进行视频转场设置。
 *  视频轨道添加的视频片段源可以是视频或图片。如果片段源选择的是图片，建议优先给出相册里的路径（localIdentifier）。加载的图片分辨率不能高于1920 * 1080，否则在Live Window 上渲染不出来。
 *  如果加载的图片出现黑屏等现象，此时需考虑缩小分辨率再加载。添加包裹转场时，都得先安装，安装成功后获取packageId才能使用，而内建转场(builtin)只需获取转场名称即可使用。
 *
 *  注：视频片段的索引都是从0开始。
 *  \warning NvsVideoTrack类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsVideoTrack : NvsTrack

/*! \if ENGLISH
 *  \brief Appends clip at the end of the video track.
 *  \param filePath The path of clip. For the method of the clip path, please refer to the "filePath" which is the parameter of [addClip:inPoint:](@ref addClip:inPoint:).
 *  \return Returns the appended NvsVideoClip object.
 *
 *  The example is as follows:
 *
 *  ![] (@ref TrackClip.PNG)
 *  There are three clips C1, C2, and C3 on the video track in the above figure. If a new clip C4 is added to the end of the video track, the code is:
 *
 *          NvsVideoTrack *videoTrack;          //The object of videoTrack's creation is omitted here
 *          [videoTrack appendClip:filepath];   //filepath:the path of the clip C4.
 *
 *  After addition, the result is as follows:
 *  ![] (@ref TrackAppendClip.PNG)
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 在视频轨道尾部追加片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip:inPoint:] (@ref addClip:inPoint:)的参数filePath。
 *  \return 返回追加的视频片段对象
 *
 *  示例如下:
 *
 *  ![] (@ref TrackClip.PNG)
 *  上图中视频轨道上有三个片段C1、C2、C3, 如果在视频轨道尾部追加一个新的片段C4,实现代码：
 *
 *          NvsVideoTrack *videoTrack;//videoTrack这里省略创建
 *          [videoTrack appendClip:filepath];//filepath为C4片段的视频文件路径
 *
 *  追加后的结果:
 *  ![] (@ref TrackAppendClip.PNG)
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa insertClip:clipIndex:
 *  \sa getClipWithIndex:
 *  \sa appendClip:trimIn:trimOut:
*/
- (NvsVideoClip *)appendClip:(NSString *)filePath;

/*! \if ENGLISH
 *  \brief Appends a video clip of the specified duration to the end of the video track.
 *  \param filePath The path of clip. For the method of the clip path, please refer to the "filePath" which is the parameter of [addClip:inPoint:](@ref addClip:inPoint:).
 *  \param trimIn The in point of triming on the video clip (in microseconds)
 *  \param trimOut The out point of triming on the video clip (in microseconds)
 *  \return Returns the appended NvsVideoClip object.
 *
 *  For more information of triming in and out points, please refer to [The Topic of Triming In and Out Points] (\ref TrimInOut.md).
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 在轨道尾部追加指定长度的片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip:inPoint:] (@ref addClip:inPoint:)的参数filePath。
 *  \param trimIn 片段裁剪入点（单位微秒）
 *  \param trimOut 片段裁剪出点（单位微秒）
 *  \return 返回追加的视频片段对象
 *
 *  对于片段裁剪入点与出点的理解，具体请参见[裁剪入点与出点(trimIn and trimOut)] (\ref TrimInOut.md)专题。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:
 *  \sa insertClip:clipIndex:
 *  \sa getClipWithIndex:
*/
- (NvsVideoClip *)appendClip:(NSString *)filePath trimIn:(int64_t)trimIn trimOut:(int64_t)trimOut;

/*! \if ENGLISH
 *  \brief Inserts a video clip at the specified clip index on the video track.
 *  \param filePath The path of clip. For the method of the clip path, please refer to the "filePath" which is the parameter of [addClip:inPoint:](@ref addClip:inPoint:).
 *  \param clipIndex Index of the specified clip
 *  \return Returns the inserted NvsVideoClip object.
 *
 *  Calling the function of insertClip:clipIndex: inserts a clip before the clip of the specified "clipIndex". An example is as follows:
 *
 *  ![] (@ref TrackClip.PNG)
 *  There are three video clips C1, C2, and C3 on the track in the above figure, and the clip to be inserted is recorded as C4. If the clip is inserted before C1, the value of "clipIndex" is 0 and same rule can be used in other cases. The corresponding code is implemented as follows:
 *
 *         NvsVideoTrack *videoTrack;                       //The object of videoTrack's creation is omitted here
 *         [videoTrack insertClip:filepath clipIndex:0];    //filepath: the path of clip C4, and the value of "clipIndex" is [0, clipCount-1]
 *
 *  After insertion, the result is as follows:
 *  ![] (@ref TrackInsertClip.PNG)
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 在视频轨道上指定片段索引处插入片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip:inPoint:] (@ref addClip:inPoint:)的参数filePath。
 *  \param clipIndex 指定片段索引
 *  \return 返回插入的视频片段对象
 *
 *  调用insertClip:clipIndex:执行的是前插入即在clipIndex所表示的片段之前进行插入。示例如下:
 *
 *  ![] (@ref TrackClip.PNG)
 *  上图中轨道上有三个视频片段C1、C2、C3，待插入的片段记为C4。如果在C1之前插入,则clipIndex值为0,其它以此类推。相应代码实现如下：
 *
 *         NvsVideoTrack *videoTrack;                   //videoTrack这里省略创建
 *         [videoTrack insertClip:filepath clipIndex:0];//filepath为片段C4的路径,clipIndex取值为[0,clipCount-1]
 *
 *  插入后结果:
 *  ![] (@ref TrackInsertClip.PNG)
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:
 *  \sa getClipWithIndex:
 *  \sa insertClip:trimIn:trimOut:clipIndex:
*/
- (NvsVideoClip *)insertClip:(NSString *)filePath clipIndex:(unsigned int)clipIndex;

/*! \if ENGLISH
 *	\brief Inserts a video clip of the specified duration at the specified clip index on the video track.
 *  \param filePath The path of clip. For the method of the clip path, please refer to the "filePath" which is the parameter of [addClip:inPoint:](@ref addClip:inPoint:).
 *  \param trimIn The in point of triming on the video clip (in microseconds)
 *  \param trimOut The out point of triming on the video clip (in microseconds)
 *	\param clipIndex Index of the specified clip
 *  \return Returns the inserted NvsVideoClip object.
 *
 *  The example is as followes:
 *
 *  ![] (@ref beforeInsertClip.PNG)
 *  There are three video clips C1, C2, C3 on the track in the above figure, and the clip C4 is to be inserted. The point indicated by the arrow on the C4 clip is the triming in and out point of the clip, and the C4 is inserted into the track after triming.
 *  Note: The trim in and out values must be within the duration of this clip, and the in point of triming value must be less than the out point of triming value. The implementation code is as follows:
 *
 *         NvsVideoTrack *videoTrack;   //The object of videoTrack's creation is omitted here
 *         //filepath: the path of clip C4. "trimIn" and "trimOut" are the values at the position indicated by the arrow on the C4 clip of the above figure, and the value of "clipIndex" is [0, clipCount-1].
 *         [videoTrack insertClip:filepath trimIn:trimIn trimOut:trimOut clipIndex:0];
 *
 *  After insertion, the result is as follows:
 *  ![] (@ref TrackInsertClip.PNG)
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *	\brief 在轨道上指定片段索引处插入指定长度的片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip:inPoint:] (@ref addClip:inPoint:)的参数filePath。
 *  \param trimIn 片段裁剪入点（单位微秒）
 *  \param trimOut 片段裁剪出点（单位微秒）
 *	\param clipIndex 指定片段索引
 *  \return 返回插入的视频片段对象
 *
 *  示例如下:
 *
 *  ![] (@ref beforeInsertClip.PNG)
 *  上图中轨道上有三个视频片段C1、C2、C3，以及待插入的片段C4。C4片段上箭头所指处即为片段裁剪的的入点和出点，裁剪后将对应片段插入到轨道上。注意：裁剪入点和出点值必须在此片段的时长范围里，且裁剪入点值必须小于裁剪出点值。实现代码如下：
 *
 *         NvsVideoTrack *videoTrack; //videoTrack这里省略创建
 *         [videoTrack insertClip:filepath trimIn:trimIn trimOut:trimOut clipIndex:0];//filepath为片段C4的路径,trimIn和trimOut为上图C4片段上箭头所指位置处的值，clipIndex取值为[0,clipCount-1]
 *
 *  插入后结果:
 *  ![] (@ref TrackInsertClip.PNG)
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:trimIn:trimOut:
 *  \sa insertClip:clipIndex:
 *  \sa getClipWithIndex:
*/
- (NvsVideoClip *)insertClip:(NSString *)filePath trimIn:(int64_t)trimIn trimOut:(int64_t)trimOut clipIndex:(unsigned int)clipIndex;

/*! \if ENGLISH
 *  \brief  Adds the clip.
 *  \param filePath The path of clip
 *
 *  For the clip's path in IOS, there are four ways:
 *
 *  a. When imported through the ALAssetsLibrary instance, the clip's path format is as follows: "assets-library://asset/asset.mov?id=E0723C86-AA47-409C-B4E2-526D7C2AA9B5&ext=mov";
 *
 *  b. When imported through the MPMediaQuery instance of the IPod Library, the clip's path format is as follows: "ipod-library://item/item.mp3?id=1217463725835578132";
 *
 *  c. When imported through the sand box path, the clip's path format is as follows: "/var/mobile/Containers/Data/Documents/tmp/video20170406101714.mp4";
 *
 *  d. After IOS 8.0, the Photos framework replaces the ALAssetsLibrary library, and when imported via the PHAset instance. The clip's path is as follows: "file:///var/mobile/Media/DCIM/100APPLE/IMG_0646.MP4".
 *  \param inPoint The in point Which the clip is on the timeline (in microseconds)
 *  \return Returns the added NvsVideoClip object.
 *
 *  For more information of the in and out points of a clip on the timeline, please refer to [The Topic of Triming In and Out Points] (\ref TrimInOut.md).
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 添加片段
 *  \param filePath 片段路径
 *
 *  IOS中，对于导入的音视频片段的路径，有四种方式：
 *
 *  a. 通过ALAssetsLibrary实例导入，片段路径格式如下："assets-library://asset/asset.mov?id=E0723C86-AA47-409C-B4E2-526D7C2AA9B5&ext=mov"；
 *
 *  b. 通过IPod Library库的MPMediaQuery实例导入，片段路径格式如下："ipod-library://item/item.mp3?id=1217463725835578132"；
 *
 *  c. 通过沙河路径路径导入，片段路径格式如下："/var/mobile/Containers/Data/Documents/tmp/video20170406101714.mp4"；
 *
 *  d. IOS 8.0版以后，Photos框架替代ALAssetsLibrary库，通过PHAsset实例导入，片段路径如下："file:///var/mobile/Media/DCIM/100APPLE/IMG_0646.MP4"。
 *  \param inPoint 片段在时间线上的入点（单位微秒）
 *  \return 返回添加的视频片段对象
 *
 *  对于片段在时间线上的入点与出点的理解，具体请参见[裁剪入点与出点(trimIn and trimOut)] (\ref TrimInOut.md)专题。
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:
 *  \sa insertClip:clipIndex:
 *  \sa addClip:inPoint:trimIn:trimOut:
*/
- (NvsVideoClip *)addClip:(NSString *)filePath inPoint:(int64_t)inPoint;

/*! \if ENGLISH
 *  \brief Adds a clip of the specified duration.
 *  \param filePath The path of clip. For the method of the clip path, please refer to the "filePath" which is the parameter of [addClip:inPoint:](@ref addClip:inPoint:).
 *  \param inPoint The in point which the clip is on the timeline (in microseconds)
 *  \param trimIn The in point of triming on the video clip (in microseconds)
 *  \param trimOut The out point of triming on the video clip (in microseconds)
 *  \return Returns the added NvsVideoClip object.
 *
 *  When users use addClip:inPoint: to add a clip, the clip which will be added split firstly the current clip at the specified in point on the timeline.
 *  Then, from the current specified in point, the clips which contain in the position corresponding to the duaration on the track are deleted according to the duration of the clip which will be added.
 *  Then Add a clip of the specified duration. If there is a gap in the corresponding position, it will be covered directly.
 *
 *  Example is as follows:
 *
 *  ![] (@ref beforeAddClip.PNG)
 *  As shown above, there are three video clips C1, C2, C3 on the track, and a clip C4 will be added. The Arrow pointing on the C4 clip are the triming in and out point of the clip. The arrow on the track is the in-point of the clip on the timeline.
 *  After triming, the clip of the specified duration is added on the track. The code is implemented as follows:
 *
 *         NvsVideoTrack *videoTrack;   //The object of videoTrack's creation is omitted here
 *         //filepath: the path of the clip C4, and "inPoint" is the value of the position indicated by the arrow on the track in the figure, "trimIn" and "trimOut" are the values at the position indicated by the arrow on the C4 clip of the above figure.
 *         [videoTrack addClip:filepath inPoint:inPoint trimIn:trimIn trimOut:trimOut];
 *
 *  When added, the results are as follows:
 *
 *  ![] (@ref afterAddClip.PNG)
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 添加指定长度的片段
 *  \param filePath 片段路径。对于片段路径方式，请参见[addClip:inPoint] (@ref addClip:inPoint:)的参数filePath。
 *  \param inPoint 片段在时间线上的入点（单位微秒）
 *  \param trimIn 片段裁剪入点（单位微秒）
 *  \param trimOut 片段裁剪出点（单位微秒）
 *  \return 返回添加的视频片段对象
 *
 *  使用addClip:inPoint:添加片段时，待添加的片段会在时间线上指定的入点分割当前片段，再从当前指定的入点起，在轨道上按待添加片段的长度删除对应长度的位置里面所包含的片段，然后添加指定时长的片段。如果在对应位置上有空隙，则直接覆盖。
 *
 *  示例如下:
 *
 *  ![] (@ref beforeAddClip.PNG)
 *  如上图，轨道上有三个视频片段C1、C2、C3，以及待添加的片段C4。C4片段上箭头所指处即为片段裁剪的的入点和出点，轨道上箭头所指即为片段在时间线上的入点，裁剪后指定长度的片段将添加到轨道上。代码实现如下：
 *
 *         NvsVideoTrack *videoTrack; //videoTrack这里省略创建
 *         [videoTrack addClip:filepath inPoint:inPoint trimIn:trimIn trimOut:trimOut];//filepath为片段C4的路径,inPoint为图中轨道上箭头所指位置的值，trimIn和trimOut为上图C4片段上箭头所指位置处的值
 *
 *  添加后结果如下：
 *
 *  ![] (@ref afterAddClip.PNG)
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa appendClip:trimIn:trimOut:
 *  \sa insertClip:trimIn:trimOut:clipIndex:
 *  \sa addClip:inPoint:
*/
- (NvsVideoClip *)addClip:(NSString *)filePath inPoint:(int64_t)inPoint trimIn:(int64_t)trimIn trimOut:(int64_t)trimOut;

/*! \if ENGLISH
 *  \brief Gets the video clip by index.
 *  \param clipIndex The index of clip. Range of "clipIndex" is [0,clipCount-1].
 *  \return Returns the obtained NvsVideoClip object.
 *  \else
 *  \brief 通过索引获取片段对象
 *  \param clipIndex 片段索引。clipIndex的取值范围：[0,clipCount-1]
 *  \return 返回获取的视频片段对象
 *  \endif
 *  \sa getClipWithTimelinePosition:
 *  \sa appendClip:
 *  \sa insertClip:clipIndex:
*/
- (NvsVideoClip *)getClipWithIndex:(unsigned int)clipIndex;

/*! \if ENGLISH
 *  \brief Gets the video clip by time.
 *  \param timelinePos The position on the timeline (in microseconds)
 *  \return Returns he obtained NvsVideoClip object.
 *  \else
 *  \brief 通过时间获取片段对象
 *  \param timelinePos 时间线上的位置（单位微秒）
 *  \return 返回获取的视频片段对象
 *  \endif
 *  \sa getClipWithIndex:
*/
- (NvsVideoClip *)getClipWithTimelinePosition:(int64_t)timelinePos;

/*! \if ENGLISH
 *  \brief Sets built-in transitions.
 *  \param srcClipIndex The index of the source video clip
 *  \param  transitionName The name of the transition. if users want to get the video transition name, please refer to [getAllBuiltinVideoTransitionNames()] (@ref NvsStreamingContext::getAllBuiltinVideoTransitionNames) or [The List of Built-in Effect Name] (@ref FxNameList.md).
 *  Note: If the transition name is a null string, the original transition will be deleted.
 *  \return Returns the NvsVideoTransition object. If the transition name is a null string(namely, delete the original transition), the function will return null.
 *
 *  Example is as follows:
 *
 *  ![] (@ref Clip.PNG)
 *
 *  The video transition is used to realize a smooth transition between clips and avoid jumping when previewing videos.
 *  The transition must be set between the connected clips. Between the clips with gaps, the transition cannot be set.
 *  For instance, there are four video clips C1, C2, C3, C4 in the image above, we could set a built-in transition between C1 and C2, while we can't do it between C3 and C4.
 *  Codes are as follow:
 *
 *        NvsVideoTrack *videoTrack;
 *        [videoTrack setBuiltinTransition:0 withName:transitionName];
 *
 *  After setting a built-in transition, the result is as follow:
 *  ![] (@ref TrackTransition.PNG)
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief  设置内嵌式转场
 *  \param  srcClipIndex 源片段索引
 *  \param  transitionName 转场名称。获取视频转场名称，请参见[getAllBuiltinVideoTransitionNames()] (@ref NvsStreamingContext::getAllBuiltinVideoTransitionNames)或[内建特效名称列表] (\ref FxNameList.md)。
 *  注意：转场名称若设为空字符串，则删除原有转场
 *  \return 返回设置的视频转场对象。若transitionName设为空字符串(即删除原有转场),返回nil
 *
 *  示例如下:
 *
 *  ![] (@ref Clip.PNG)
 *
 *  设置视频转场的作用是为了片段与片段间的平缓过渡，避免视频预览时出现跳跃。转场必须设置在相互连接的片段间，而在有空隙的片段之间，则不能设置视频转场。
 *  如上图中轨道上有四个视频片段C1、C、C3、C4,在C1和C2之间可以设置一个内嵌式转场，而C3和C4则不能设置视频转场。实现代码：
 *
 *        NvsVideoTrack *videoTrack;
 *        [videoTrack setBuiltinTransition:0 withName:transitionName];
 *
 *  设置转场后:
 *  ![] (@ref TrackTransition.PNG)
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa setPackagedTransition:withPackageId:
*/
- (NvsVideoTransition *)setBuiltinTransition:(unsigned int)srcClipIndex withName:(NSString *)transitionName;

/*! \if ENGLISH
 *  \brief Sets the package transition.
 *  \param srcClipIndex The index of the source video clip
 *  \param packageId The ID of the resource package. If the package Id is a null string, the transition will be deleted; if the package Id is set to "theme", the transition at the video clip will be set to the one in the current theme. Note: If there is no theme, the transition at the video clip will be deleted.
 *  \return Returns the NvsVideoTransition object.
 *  \warning This interface causes the streaming engine state to jump to the state of stopping engine. For more details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 设置包裹转场
 *  \param srcClipIndex 源片段索引
 *  \param packageId 资源包ID。若packageId为空，则删除该视频片段处的转场；若packageId设为"theme",则该视频片段处的转场设为当前主题的转场。注意：若无主题，则删除该视频片段处的转场。
 *  \return 返回设置的视频转场对象
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa setBuiltinTransition:withName:
*/
- (NvsVideoTransition *)setPackagedTransition:(unsigned int)srcClipIndex withPackageId:(NSString *)packageId;

/*! \if ENGLISH
 *  \brief Gets the transition by the source clip index.
 *  \param srcClipIndex The index of the source clip
 *  \return Returns the obtained NvsVideoTransition object.
 *  \else
 *  \brief 通过源片段索引获取转场
 *  \param srcClipIndex 源片段索引
 *  \return 返回获取的视频转场对象
 *  \endif
 *  \sa setBuiltinTransition:withName:
*/
- (NvsVideoTransition *)getTransitionWithSourceClipIndex:(unsigned int)srcClipIndex;

@end
