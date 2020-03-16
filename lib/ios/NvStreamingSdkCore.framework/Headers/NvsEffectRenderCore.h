//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Sep 10. 2019
//   Author:        NewAuto video team
//================================================================================

#pragma once

#import <Foundation/Foundation.h>
#import "NvsEffectCommonDef.h"
#import <CoreVideo/CVPixelBuffer.h>

@class NvsEffect;

typedef enum {
    NvsEffectCoreError_NoError = 0,
    NvsEffectCoreError_Unknown = -1,
    NvsEffectCoreError_InvalidTexture = -2,
    NvsEffectCoreError_InvalidPixelFormat = -3,
    NvsEffectCoreError_NotInitialized = -4,
} NvsEffectCoreError;

typedef enum {
    NvsInitializeFlag_NoFlag = 0,
    NvsInitializeFlag_InSingleGLThread = 1,
    NvsInitializeFlag_CreateGLContextIfNeed = 2,
    NvsInitializeFlag_SUPPORT_4K = 4,
    NvsInitializeFlag_SUPPORT_8K = 8
} NvsInitializeFlags;

typedef enum {
    NvsRenderFlag_NoFlag = 0,
    NvsRenderFlag_IsUpsideDownTexture = 1,
    NvsRenderFlags_InputTextureIsFlipHorizontally = 2
} NvsRenderFlag;

/*! \if ENGLISH
*   \brief Class for special effects rendering.
*
*   This class is the entry of effect rendering module of the entire SDK.
*   \warning In the NvsEffectRenderCore class, all public APIs must be used in OpenGL threads! ! !
*   \else
*   \brief 特效渲染类
*
*   特效渲染类整个SDK的特效渲染入口。
*   \warning NvsEffectRenderCore类中，所有public API都必须在OpenGL线程使用！！！
*   \endif
*/
NVS_EXPORT @interface NvsEffectRenderCore : NSObject

/*! \if ENGLISH
*   \brief Initializes
*   \return YES means success, while NO means failure.
*   \else
*   \brief 初始化
*   \return 成功返回YES，失败返回NO
*   \endif
*   \since 2.3.0
*/
- (BOOL)initialize;

/*! \if ENGLISH
*   \brief Initializes
*   \param falgs Refer to the NvsInitializeFlags code definition
*   \return YES means success, while NO means failure.
*   \else
*   \brief 初始化
*   如果标志为NvsInitializeFlag_CreateGLContextIfNeed，如果当前的线程没有GLContext，SDK内部会创建GLContext，这个renderCore中的所有API，需要在这个线程中调用
*   \param falgs 参考NvsInitializeFlags
*   \return 成功返回YES，失败返回NO
*   \endif
*   \since 2.3.0
*/
- (BOOL)initializeWithFlags:(int)falgs;

/*! \if ENGLISH
*   \brief Clears all resources in NvsEffectRenderCore.
*   \else
*   \brief 清除NvsEffectRenderCore中的所有资源
*   \endif
*   \since 2.14.0
*/
- (void)cleanUp;

/*! \if ENGLISH
 *  \brief Rendering effects
 *  \param effect The effect object to be rendered
 *  \param inputTexId ID of input texture
 *  \param inputVideoResolution Resolution of input texture
 *  \param outputTexId ID of output texture
 *  \param timestamp Timestamp of current rendering
 *  \param flags Temporarily set to 0
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 渲染特效
 *  \param effect 要渲染的特效对象
 *  \param inputTexId 输入纹理
 *  \param inputVideoResolution 输入纹理的视频解析度
 *  \param outputTexId 输出纹理
 *  \param timestamp 当前渲染的时间戳
 *  \param flags 暂时为0
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.3.0
*/
- (NvsEffectCoreError)renderEffect:(NvsEffect *)effect inputTexId:(int)inputTexId inputVideoResolution:(NvsEffectVideoResolution *)inputVideoResolution
                        outputTexId:(int)outputTexId timestamp:(int64_t)timestamp flags:(NvsRenderFlag)flags;

/*! \if ENGLISH
 *  \brief Rendering special effects
 *  \param effect The effect object to be rendered
 *  \param inputTexId ID of input texture
 *  \param inputBuddyBuffer Buddy buffer of the input texture (NV12 or BGRA or YUV420 format).
 *  \param physicalOrientation Physical orientation
 *  \param inputVideoResolution Resolution of input texture
 *  \param outputTexId ID of output texture
 *  \param timestamp Timestamp of current rendering
 *  \param flags Temporarily set to 0.
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 渲染特效
 *  \param effect 要渲染的特效对象
 *  \param inputTexId 输入纹理
 *  \param inputBuddyBuffer 输入纹理的伴随buffer(支持NV12或BGRA或YUV420格式)
 *  \param physicalOrientation 设备方向
 *  \param inputVideoResolution 输入纹理的视频解析度
 *  \param outputTexId 输出纹理
 *  \param timestamp 当前渲染的时间戳
 *  \param flags 暂时为0
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.5.0
*/
- (NvsEffectCoreError)renderEffect:(NvsEffect *)effect inputTexId:(int)inputTexId inputBuddyBuffer:(const NvsEffectVideoFrameInfo*)inputBuddyBuffer
                        physicalOrientation:(int)physicalOrientation
                        inputVideoResolution:(NvsEffectVideoResolution *)inputVideoResolution
                        outputTexId:(int)outputTexId timestamp:(int64_t)timestamp flags:(NvsRenderFlag)flags;

/*! \if ENGLISH
 *  \brief Rendering effects
 *  [Attention] Must be used in the same thread as initialize function. If the thread used does not have an OpenGL environment, the call to initializewithflags must have NvsInitializeFlag_CreateGLContextIfNeed
 *  \param effect The effect object to be rendered
 *  \param inputImage input image
 *  \param rotation rotation of input image
 *  \param isFlip need flip horizontally
 *  \param timestamp Timestamp of current rendering
 *  \param flags Temporarily set to 0
 *  \param format output image buffer format  Refer to NvsEffectVideoFramePixelFormat
 *  \param is601
 *  \param ouputImage The result of rendered
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 渲染特效
 *  【特别注意】必须和initialize在同一个线程中使用。如果使用的线程没有OpenGL环境，在调用initializeWithFlags必须带有NvsInitializeFlag_CreateGLContextIfNeed
 *  \param effect 要渲染的特效对象
 *  \param inputImage 输入图像
 *  \param rotation 输入图像旋转角度，只能是0， 90， 180， 270
 *  \param isFlip 是否需要横向翻转
 *  \param timestamp 当前渲染的时间戳
 *  \param flags 暂时为0
 *  \param format 输出图像格式请参数 NvsEffectVideoFramePixelFormat
 *  \param is601 如果输出图像是Nv12或者YUV420P格式才有意义
 *  \param ouputImage 输出图像数据
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.14.0
*/
- (NvsEffectCoreError)renderEffect:(NvsEffect *)effect
                        inputImage:(CVPixelBufferRef)inputImage
                   displayRotation:(int)rotation
                isFlipHorizontally:(BOOL)isFlip
                         timestamp:(int64_t)timestamp
                             flags:(NvsRenderFlag)flags
                 outputFrameFormat:(NvsEffectVideoFramePixelFormat)format
                outputFrameIsBT601:(BOOL)is601
                       outputImage:(CVPixelBufferRef*)ouputImage;

/*! \if ENGLISH
 *  \brief Rendering effects
 *  [Attention] Must be used in the same thread as initialize function. If the thread used does not have an OpenGL environment, the call to initializewithflags must have NvsInitializeFlag_CreateGLContextIfNeed
 *  \param effects The effects object to be rendered
 *  \param inputImage input image
 *  \param rotation rotation of input image
 *  \param isFlip need flip horizontally
 *  \param timestamp Timestamp of current rendering
 *  \param flags Temporarily set to 0
 *  \param format output image buffer format  Refer to NvsEffectVideoFramePixelFormat
 *  \param is601
 *  \param ouputImage The result of rendered
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 渲染特效
 *  【特别注意】必须和initialize在同一个线程中使用。如果使用的线程没有OpenGL环境，在调用initializeWithFlags必须带有NvsInitializeFlag_CreateGLContextIfNeed
 *  \param effects 要渲染的特效对象
 *  \param inputImage 输入图像
 *  \param rotation 输入图像旋转角度，只能是0， 90， 180， 270
 *  \param isFlip 是否需要横向翻转
 *  \param timestamp 当前渲染的时间戳
 *  \param flags 暂时为0
 *  \param format 输出图像格式请参数 NvsEffectVideoFramePixelFormat
 *  \param is601 如果输出图像是Nv12或者YUV420P格式才有意义
 *  \param ouputImage 输出图像数据
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.14.0
*/
- (NvsEffectCoreError)renderEffects:(NSArray<NvsEffect *>*)effects
                        inputImage:(CVPixelBufferRef)inputImage
                   displayRotation:(int)rotation
                isFlipHorizontally:(BOOL)isFlip
                         timestamp:(int64_t)timestamp
                             flags:(NvsRenderFlag)flags
                 outputFrameFormat:(NvsEffectVideoFramePixelFormat)ouputFrameformat
                outputFrameIsBT601:(BOOL)is601
                       outputImage:(CVPixelBufferRef*)ouputImage;


/*! \if ENGLISH
 *  \brief Rendering effects
 *  Rendering Multiple input textures effect, the input textures must be same size
 *  \param effect The effect object to be rendered
 *  \param inputTextures input texture array
 *  \param inputVideoResolution Resolution of input texture
 *  \param outputTexId ID of output texture
 *  \param timestamp Timestamp of current rendering
 *  \param flags Temporarily set to 0
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 渲染特效
 *  渲染需要多个输入的Texture的特效，多个输入texture的大小都必须一致
 *  \param effect 要渲染的特效对象
 *  \param inputTextures 输入图像组
 *  \param inputVideoResolution 输入纹理的视频解析度
 *  \param outputTexId 输出纹理
 *  \param timestamp 当前渲染的时间戳
 *  \param flags 暂时为0
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.14.0
*/
- (NvsEffectCoreError)renderEffect:(NvsEffect *)effect
                   inputTexIds:(NSArray*)inputTextures
          inputVideoResolution:(NvsEffectVideoResolution *)inputVideoResolution
                   outputTexId:(int)outputTexId
                     timestamp:(int64_t)timestamp
                         flags:(NvsRenderFlag)flags;
/*! \if ENGLISH
*   \brief Clears OpenGL resources cached in special effects.
*   \param effect The effect object to be cleared.
*   \else
*   \brief 清除特效中携带的OPenGL资源
*   \param effect 要清除的特效对象
*   \endif
*   \since 2.3.0
*/
- (void)clearEffectResources:(NvsEffect *)effect;

/*! \if ENGLISH
*   \brief Clears cached resources.
*   \else
*   \brief 清除缓存资源
*   \endif
*   \since 2.3.0
*/
- (void)clearCacheResources;

/*! \if ENGLISH
 *  \brief Uploading buffer to GPU texture
 *  \param frameBuffer buffer of the uploding frame (NV12 format).
 *  \param horizontalFlip hrozontal flip
 *  \param outputTexId ID of output texture
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 上传buffer到GPU纹理
 *  \param frameBuffer 需要上传buffer(支持NV12)
 *  \param horizontalFlip 是否横向反转
 *  \param outputTexId 输出纹理
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.12.0
*/
-(NvsEffectCoreError)uploadPixelBufferToTexture:(CVPixelBufferRef)frameBuffer displayRotation:(int)rotation horizontalFlip:(BOOL)flip outputTexId:(int)outputTexId;

/*! \if ENGLISH
 *  \brief Uploading buffer to GPU texture
 *  \param frameBuffer buffer of the uploding frame (NV12 format).
 *  \param horizontalFlip hrozontal flip
 *  \param outputTexId ID of output texture
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 上传buffer到GPU纹理
 *  \param frameBuffer 需要上传buffer(支持NV12)
 *  \param horizontalFlip 是否横向反转
 *  \param outputTexId 输出纹理
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.12.0
*/
-(NvsEffectCoreError)uploadPixelBufferToTexture:(CVPixelBufferRef)frameBuffer horizontalFlip:(BOOL)flip outputTexId:(int)outputTexId;

/*! \if ENGLISH
 *  \brief Downloading buffer from GPU texture
 *  \param inputTexId ID of input texture
 *  \param inputVideoResolution Resolution of input texture
 *  \param outputFrameFormat returned buffer foramt(BGRA or YUV420 format)
 *  \param isBT601 The color is converted according to BT.601 standard. If the returned buffer format is YUV, this parameter is meaningful.
 *  \param frameBuffer returned buffer of the downloading frame (BGRA or YUV420 format).
 *  \return "NvsEffectCoreError_NoError" means success, while any other value means failure. Refer to the error code definition.
 *  \else
 *  \brief 从GPU纹理下传到buffer
 *  \param inputTexId 输入纹理
 *  \param inputVideoResolution 输入纹理的视频解析度
 *  \param outputFrameFormat 返回下传的buffer格式(BGRA or YUV420 format)
 *  \param isBT601 是否按照BT.601的标准转化,如果返回下传的buffer格式为YUV,这个参数有意义
 *  \param frameBuffer 返回下传的buffer(BGRA or YUV420 format)
 *  \return 返回NvsEffectCoreError_NoError为成功,其他值都是错误,参考错误码定义
 *  \endif
 *  \since 2.12.0
*/
-(NvsEffectCoreError)downloadPixelBufferFromTexture:(int)inputTexId
                          inputVideoResolution:(NvsEffectVideoResolution *)inputVideoResolution
                             outputFrameFormat:(NvsEffectVideoFramePixelFormat)format
                                       isBT601:(BOOL)is601
                                   outputFrame:(CVPixelBufferRef*)frameBuffer;

@end
