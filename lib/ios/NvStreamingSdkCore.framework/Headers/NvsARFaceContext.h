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

/*! \if ENGLISH
*   \brief Detects configuration options
*   \else
*   \brief 检测配置选项
*   \endif
*/
typedef enum
{
    NvsObjectTrackingType_Face = 0,        //!< \if ENGLISH Detects faces \else 检测人脸 \endif
    NvsObjectTrackingType_Animal        //!< \if ENGLISH Detects animal \else 检测动物 \endif
} NvsObjectTrackingType;


@protocol NvsARFaceContextDelegate <NSObject>
@optional

/*! \if ENGLISH
 *  \brief Notifies that the face props starts loading.
 *  \param itemPath Face props path
 *  \else
 *  \brief 通知人脸道具开始加载
 *  \param itemPath 人脸道具路径
 *  \endif
 */
- (void)notifyFaceItemLoadingBegin:(NSString *)itemPath ;

/*! \if ENGLISH
 *  \brief Notifies the completion of loading face props
 *  \else
 *  \brief 通知人脸道具加载完成
 *  \endif
 */
- (void)notifyFaceItemLoadingFinish ;

#if defined(NV_ENABLE_AI) && defined(NV_AI_ST)
    /*! \if ENGLISH
     *  \brief Notifies the error of loading face props
     *  \else
     *  \brief 通知人脸道具加载出错
     *  \endif
     */
    - (void)notifyFaceItemLoadingFailed:(NSString *)itemPath error:(int) error ;
#endif

@end

/*!
 *  \if ENGLISH
 *  \brief ARFace context
 *  \warning In the NvsARFaceContext class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief ARFace上下文
 *  \warning NvsARFaceContext类中，所有public API都在UI线程使用！！！
 *  \endif
 */
@interface NvsARFaceContext : NSObject

@property (nonatomic, weak) id<NvsARFaceContextDelegate> delegate;

- (void)setInternalContext:(void *)internalContext;
- (bool)isFaceTracking;
- (bool)isObjectTracking:(NvsObjectTrackingType)trackingType;
- (void)setReloadCurSticker;

@end
