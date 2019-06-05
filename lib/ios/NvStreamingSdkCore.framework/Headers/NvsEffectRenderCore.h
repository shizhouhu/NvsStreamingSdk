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

@class NvsEffect;

typedef enum {
    NvsEffectCoreError_NoError = 0,
    NvsEffectCoreError_Unknown = -1,
    NvsEffectCoreError_InvalidTexture = -2,
    NvsEffectCoreError_InvalidPixelFormat = -3
} NvsEffectCoreError;

typedef enum {
    NvsRenderFlag_NoFlag = 0,
    NvsRenderFlag_IsUpsideDownTexture = 1
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
*   \brief Clears all resources in NvsEffectRenderCore.
*   \else
*   \brief 清除NvsEffectRenderCore中的所有资源
*   \endif
*   \since 2.3.0
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

@end
