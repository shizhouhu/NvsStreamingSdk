//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Dec 27. 2016
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <GLKit/GLKit.h>
#import "NvsCommonDef.h"

/*! \if ENGLISH
 *  \brief Live Window fill mode
 *  \else
 *  \brief Live Window 填充模式
 *  \endif
*/
typedef enum {
    /*! \if ENGLISH
     *  \brief The image is evenly filled and cropped if necessary (default mode).
     *
     *  ![] (PreserveAspectCrop.png)
     *  \else
     *  \brief 图像按比例均匀填充，必要时进行裁剪(默认模式)
     *
     *  ![] (PreserveAspectCrop.png)
     *  \endif
    */
    NvsLiveWindowFillModePreserveAspectCrop = 0,

    /*! \if ENGLISH
     *  \brief The image is evenly scaled to fit the window, without cropping.
     *
     *  ![] (PreserveAspectFit.png)
     *  \else
     *  \brief 图像均匀地缩放来适合窗口，没有裁剪。
     *
     *  ![] (PreserveAspectFit.png)
     *  \endif
    */
    NvsLiveWindowFillModePreserveAspectFit,

    /*! \if ENGLISH
     *  \brief The image is scaled to fit the window.
     *
     *  ![] (Stretch.png)
     *  \else
     *  \brief 图像被缩放来适合窗口
     *
     *  ![] (Stretch.png)
     *  \endif
    */
    NvsLiveWindowFillModeStretch
} NvsLiveWindowFillMode;


/*! \if ENGLISH
 *  \brief Real-time shooting preview window.
 *
 *  When shooting a video, connect the live window with the capture preview and preview the scene in real time. After the shooting is completed, the live window is connected to the created timeline.
 *  And the video which has shooted can edit as needed, and then compile and output a video .mov format file.
 *  \warning For NvsLiveWindow class，all public API must be implemented within UI thread！！！
 *  \else
 *  \brief 实时拍摄预览窗口
 *
 *  在拍摄视频时，将实时预览窗口与采集预览连接，对拍摄场景进行实时预览。完成拍摄后，将实时预览窗口与创建的时间线(Time Line)连接，对已完成拍摄的视频根据需要进行编辑，然后生成视频输出.mov格式的文件。
 *  \warning NvsLiveWindow类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsLiveWindow : GLKView

@property (nonatomic) NvsLiveWindowFillMode fillMode;  //!< \if ENGLISH \else LiveWindow的填充模式 \endif

- (instancetype)init;
- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithCoder:(NSCoder *)aDecoder;
- (instancetype)initWithFrame:(CGRect)frame context:(EAGLContext *)context;

/*! \if ENGLISH
 *  \brief Timeline coordinates are converted to view coordinates.
 *  \param ptCanonical Timeline coordinates
 *  \return Returns the converted view coordinate point CGPoint object
 *  \else
 *  \brief 时间线坐标转换成视图坐标
 *  \param ptCanonical 时间线坐标点
 *  \return 返回转换后的视图坐标点CGPoint对象
 *  \endif
 *  \sa mapViewToCanonical:
*/
- (CGPoint)mapCanonicalToView:(CGPoint)ptCanonical;

/*! \if ENGLISH
 *  \brief View coordinates are converted to timeline coordinates
 *  \param ptView View coordinates
 *  \return Returns the converted timeline coordinate point CGPoint object
 *  \else
 *  \brief 视图坐标转换成时间线坐标
 *  \param ptView 视图坐标点
 *  \return 返回转换后的时间线坐标点CGPoint对象
 *  \endif
 *  \sa mapCanonicalToView:
*/
- (CGPoint)mapViewToCanonical:(CGPoint)ptView;

/*! \if ENGLISH
 *  \brief Normalized coordinates are converted to view coordinates
 *  \param ptNormalized Normalized coordinates
 *  \return Returns the converted view coordinate point CGPoint object
 *  \else
 *  \brief 归一化坐标转换成视图坐标
 *  \param ptNormalized 归一化坐标点
 *  \return 返回转换后的视图坐标点CGPoint对象
 *  \endif
 *  \sa mapViewToNormalized:
*/
- (CGPoint)mapNormalizedToView:(CGPoint)ptNormalized;

/*! \if ENGLISH
 *  \brief View coordinates are converted to normalized coordinates
 *  \param ptView View coordinates
 *  \return Returns the converted normalized coordinate point CGPoint object
 *  \else
 *  \brief 视图坐标转换成归一化坐标
 *  \param ptView 视图坐标点
 *  \return 返回转换后的归一化坐标点CGPoint对象
 *  \endif
 *  \sa mapNormalizedToView:
*/
- (CGPoint)mapViewToNormalized:(CGPoint)ptView;

/*! \if ENGLISH
 *  \brief Clear LiveWindow video frames
 *  \else
 *  \brief 清除LiveWindow的视频帧
 *  \endif
*/
- (void)clearVideoFrame;

/*! \if ENGLISH
 *  \brief Screen Shot
 *  \else
 *  \brief 截屏
 *  \endif
*/
- (UIImage*)takeScreenShot;

/*! \if ENGLISH
 *  \brief Set the background color of LiveWindow.
 *  \param red red(0~1)
 *  \param green green(0~1)
 *  \param blue blue(0~1)
 *  \else
 *  \brief 设置LiveWindow的背景色
 *  \param red red值(0~1)
 *  \param green green值(0~1)
 *  \param blue blue值(0~1)
 *  \endif
*/
- (void)setBackgroundColorWithRed:(float)red green:(float)green blue:(float)blue;

@end

