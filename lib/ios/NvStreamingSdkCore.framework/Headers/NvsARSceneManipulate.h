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
#import "NvsCommonDef.h"

/*! \if ENGLISH
*   \brief File type
*   \else
*   \brief 文件类型
*   \endif
*/
typedef enum {
    NvsARSceneDetectionMode_Video = 0x1,      //!< \if ENGLISH detection mode video \else 视频检测 \endif
    NvsARSceneDetectionMode_Image = 0x2,    //!< \if ENGLISH detection mode image \else 图像检测 \endif
    NvsARSceneDetectionMode_SingleThread = 0x4,    //!< \if ENGLISH detection single thread \else 单线程检测 \endif
    NvsARSceneDetectionMode_MultiThread = 0x28,    //!< \if ENGLISH detection multi thread \else 多线程检测 \endif
} NvsARSceneDetectionMode;

@protocol NvsARSceneManipulateDelegate <NSObject>
@optional

/*! \if ENGLISH
 *  \brief Get the callback of the original enclosing rectangle for the face.
 *  <br>Please pay special attention: this function is called in the background thread, not in the UI thread. Please consider thread safety issues!!
 *  \param faceIds Array of face tag
 *  \param boundingRects Array of face range
 *  \param count Count of face arrays. When the count is 0, the pointers of "faceIds" and "boundingRects" are nil.
 *  \else
 *  \brief 获取人脸的原始包围矩形框回调
 *  <br>请特别注意:这个函数被调用是在后台的线程,而不是在UI线程.使用请考虑线程安全的问题!!
 *  \param faceIds 人脸标记数组
 *  \param boundingRects 人脸范围数组
 *  \param count 人脸数组数量，当数量为0时，faceIds和boundingRects的指针为空
 *  \endif
 *  \since 2.7.0
*/
- (void)notifyFaceBoundingRectWithId:(int*)faceIds boundingRect:(NvsRect*)boundingRects faceCount:(int)count;

@end

/*! \if ENGLISH
 *  \brief AR scene processing interface
 *
 *  \warning In the NvsARSceneManipulate class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief AR场景处理接口
 *
 *  \warning NvsARSceneManipulate类中，所有public API都在UI线程使用！！！
 *  \endif
*/
@interface NvsARSceneManipulate : NSObject

@property (nonatomic, weak) id<NvsARSceneManipulateDelegate> delegate;

- (void)setDetectionMode:(NvsARSceneDetectionMode)mode;

- (void)resetTracking;

- (void)setInternalObject:(void *)internalObject;

@end
