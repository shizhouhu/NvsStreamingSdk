//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Sep 6. 2018
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import "NvsAssetPackageManager.h"
#import "NvsVideoEffect.h"
#import "NvsEffectRenderCore.h"
#import "NvsEffectCommonDef.h"

/*! \if ENGLISH
*   \brief Effect SDK context creation flag.
*   \else
*   \brief Effect SDK上下文创建标志
*   \endif
*/
typedef enum {
    NvsEffectSdkContextFlag_NoFlag = 0
} NvsEffectSdkContextFlag;

/*! \if ENGLISH
*   \brief Human detection feature
*   \else
*   \brief 人体检测特征标志
*   \endif
*/
typedef enum {
    NvsEffectSdkHumanDetectionFeature_FaceLandmark = 1,
    NvsEffectSdkHumanDetectionFeature_FaceAction = 2,
    NvsEffectSdkHumanDetectionFeature_AvatarExpression = 4,
    NvsEffectSdkHumanDetectionFeature_VideoMode = 8,
    NvsEffectSdkHumanDetectionFeature_ImageMode = 16,
    NvsEffectSdkHumanDetectionFeature_MultiThread = 32,
    NvsEffectSdkHumanDetectionFeature_SingleThread = 64,
    NvsEffectSdkHumanDetectionFeature_Extra = 128
} NvsEffectSdkHumanDetectionFeatureFlag;

/*! \if ENGLISH
*   \brief Human detection data packet type
*   \else
*   \brief 人体检测数据包类型
*   \endif
*/
typedef enum {
    NvsEffectSdkHumanDetectionDataType_FakeFace = 0
} NvsEffectSdkHumanDetectionDataTypeFlag;

/*! \if ENGLISH
*   \brief Effect SDK context class
*   \else
*   \brief Effect SDK上下文类
*   \endif
*/
NVS_EXPORT @interface NvsEffectSdkContext : NSObject

@property (readonly) NvsAssetPackageManager *assetPackageManager; //!< \if ENGLISH Asset package manager\else 素材包管理器 \endif

/*! \if ENGLISH
 *  \brief Verifies the SDK license. Note: This interface must be called before the NvsStreamingContext is initialized.
 *  \param sdkLicenseFilePath SDK license file path
 *  \return Returns BOOL value. YES indicates that the license verification is successful, and NO indicates that the verification fails. If the verification fails, a subsequent watermark will appear in video preview and generated videos.
 *  \else
 *  \brief 验证SDK授权文件。注意：授权文件接口必须在NvsStreamingContext初始化之前调用。
 *  \param sdkLicenseFilePath SDK授权文件路径
 *  \return 返回BOOL值。YES表示授权验证成功，NO则验证失败。若验证失败，则后续的视频预览和生成视频会出现水印。
 *  \endif
*/
+ (BOOL)verifySdkLicenseFile:(NSString *)sdkLicenseFilePath;

/*! \if ENGLISH
 *  \brief Gets the unique instance of the effect sdk context.
 *  \return Returns the instance of the effect sdk context.
 *  \else
 *  \brief 获取effect sdk上下文的唯一实例
 *  \return 返回effect sdk上下文的对象实例
 *  \endif
 *  \sa destroyInstance
*/
+ (NvsEffectSdkContext *)sharedInstance:(NvsEffectSdkContextFlag)flags;

/*! \if ENGLISH
*   \brief Destroys the effect sdk context instance.
*   \else
*   \brief 销毁effect sdk上下文实例。
*   \endif
*   \sa sharedInstance:
*/
+ (void)destroyInstance;

/*! \if ENGLISH
*   \brief Checks if the current SDK contains an AR module.
*   \return Returns value of 0 means that no AR module exists, and a value greater than 0 means that the AR module exists.
*   \else
*   \brief 检测当前SDK是否含有AR模块
*   \return 返回值0表示不含有AR模块，大于0表示含有AR模块
*   \endif
*   \since 2.5.0
*/
+ (int)hasARModule;

/*! \if ENGLISH
*   \brief Initializes the human body detection mechanism.
*   \param modelFilePath The file path of the face model
*   \param licenseFilePath The file path of license
*   \param features Human detection feature flag field. Please refer to [Human detection feature](@ref NvsEffectSdkHumanDetectionFeatureFlag)
*   \return The return value indicates whether it is successful
*   \else
*   \brief 初始化人体检测机制
*   \param modelFilePath 人脸模型文件路径
*   \param licenseFilePath 授权文件路径
*   \param features 人体检测特征标志字段。请参见[人体检测特征标志](@ref NvsEffectSdkHumanDetectionFeatureFlag)
*   \return 返回值表示是否成功
*   \endif
*   \since 2.5.0
*/
+ (BOOL)initHumanDetection:(NSString *)modelFilePath
           licenseFilePath:(NSString *)licenseFilePath
                  features:(int)features;

/*! \if ENGLISH
*   \brief Setup human detection data package.
*   \param dataType Human detection data package type.Please refer to[Human detection data packet type](@ref NvsEffectSdkHumanDetectionDataTypeFlag).
*   \param dataFilePath The file path of data
*   \return The return value indicates whether it is successful.
*   \else
*   \brief 安装人体检测相关数据包
*   \param dataType 人体检测数据包类型。请参见[人体检测数据包类型](@ref NvsEffectSdkHumanDetectionDataTypeFlag)
*   \param dataFilePath 数据文件路径
*   \return 返回值表示是否成功
*   \endif
*   \since 2.6.0
*/
+ (BOOL)setupHumanDetectionData:(int)dataType
           dataFilePath:(NSString *)dataFilePath;

/*! \if ENGLISH
*   \brief Turns off the human detection mechanism.
*   \else
*   \brief 关闭人体检测机制
*   \endif
*   \since 2.5.0
*/
+ (void)closeHumanDetection;

/*! \if ENGLISH
 *  \brief Gets a list of all build-in video effects' names.
 *  \return Returns an array object containing all the build-in video effects' names.
 *  \else
 *  \brief 获取全部内嵌视频特效名称列表
 *  \return 返回包含所有内嵌的视频特效名称的数组对象
 *  \endif
*/
- (NSArray *)getAllBuiltinVideoFxNames;

/*! \if ENGLISH
 *  \brief Creates a special effect object.
 *  \param effectId Special effects ID. For build-in video effects, it is the name of the effect. If it is a resource package effect, it is the resource package ID.
 *  \param aspectRatio Aspect ratio
 *  \return Returns the created special effect object.
 *  \else
 *  \brief 创建特效对象
 *  \param effectId 特效id。对于内嵌视频特效，就是特效的名字，如果是资源包特效，就是资源包id
 *  \param aspectRatio 横纵比
 *  \return 返回创建的特效对象
 *  \endif
*/
- (NvsVideoEffect *)createVideoEffect:(NSString *)effectId aspectRatio:(NvsEffectRational)aspectRatio;

/*! \if ENGLISH
 *  \brief Creates a special effect rendering object.
 *  \return Returns the created effect rendering object.
 *  \else
 *  \brief 创建特效渲染对象
 *  \return 返回创建的特效渲染对象
 *  \endif
*/
- (NvsEffectRenderCore *)createEffectRenderCore;

/*! \cond */

/*! \if ENGLISH
 *  \brief Verifies whether a feature is available.
 *  \param sdkFunctionName The name of the sdk function
 *  \return Returns BOOL value. YES indicates that the authorization verification is successful, and NO indicates that the verification fails.
 *  \else
 *  \brief 验证某项功能是否可用。
 *  \param sdkFunctionName sdk功能的名字
 *  \return 返回BOOL值。YES表示授权验证成功，NO则验证失败。
 *  \endif
*/
+ (BOOL)functionalityAuthorised:(NSString *)sdkFunctionName;
/*! \endcond */

@end
