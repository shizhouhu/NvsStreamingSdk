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

/*!
 *  \brief
 *  流媒体上下文创建标志
 */
typedef enum {
    NvsEffectSdkContextFlag_NoFlag = 0
} NvsEffectSdkContextFlag;

/*!
 *  \brief 人体检测特征标志
 */
typedef enum {
    NvsEffectSdkHumanDetectionFeature_FaceLandmark = 1,
    NvsEffectSdkHumanDetectionFeature_FaceAction = 2
} NvsEffectSdkHumanDetectionFeatureFlag;

/*!
 *  \brief 人体检测数据包类型
 */
typedef enum {
    NvsEffectSdkHumanDetectionDataType_FakeFace = 0
} NvsEffectSdkHumanDetectionDataTypeFlag;

NVS_EXPORT @interface NvsEffectSdkContext : NSObject

@property (readonly) NvsAssetPackageManager *assetPackageManager;

/*!
 *  \brief 验证SDK授权文件。注意：授权文件接口必须在NvsStreamingContext初始化之前调用。
 *  \param sdkLicenseFilePath SDK授权文件路径
 *  \return 返回BOOL值。YES表示授权验证成功，NO则验证失败。若验证失败，则后续的视频预览和生成视频会出现水印。
 */
+ (BOOL)verifySdkLicenseFile:(NSString *)sdkLicenseFilePath;

/*!
 *  \brief 获取流媒体上下文的唯一实例
 *  \return 返回流媒体上下文的对象实例
 *  \sa destroyInstance
 */
+ (NvsEffectSdkContext *)sharedInstance:(NvsEffectSdkContextFlag)flags;

/*!
 *  \brief 销毁流媒体上下文实例。注意: 销毁之后无法再次创建及获取
 *  \sa sharedInstance:
 */
+ (void)destroyInstance;


/*!
    \brief 检测当前SDK是否含有AR模块
    \return 返回值0表示不含有AR模块，大于0表示含有AR模块
    \since 2.5.0
*/
+ (int)hasARModule;

/*!
    \brief 初始化人体检测机制
    \param modelFilePath 人脸模型文件路径
    \param licenseFilePath 授权文件路径
    \param features 人体检测特征标志字段。请参见[人体检测特征标志](@ref NvsEffectSdkHumanDetectionFeatureFlag)
    \return 返回值表示是否成功
    \since 2.5.0
*/
+ (BOOL)initHumanDetection:(NSString *)modelFilePath
           licenseFilePath:(NSString *)licenseFilePath
                  features:(int)features;

/*!
    \brief 初始化人体检测相关数据包
    \param dataType 人体检测数据包类型。请参见[人体检测数据包类型](@ref NvsEffectSdkHumanDetectionDataTypeFlag)
    \param dataFilePath 数据文件路径
    \return 返回值表示是否成功
    \since 2.6.0
*/
+ (BOOL)setupHumanDetectionData:(int)dataType
           dataFilePath:(NSString *)dataFilePath;

/*!
    \brief 关闭人体检测机制
    \since 2.5.0
*/
+ (void)closeHumanDetection;

/*!
 *  \brief 获取全部内嵌视频特效名称
 *  \return 返回包含所有内嵌的视频特效名称的数组对象
 */
- (NSArray *)getAllBuiltinVideoFxNames;

/*!
 *  \brief 创建特效对象
 *  \param effectId 特效id。对于内嵌视频特效，就是特效的名字，如果是资源包特效，就是资源包id
 *  \param aspectRatio 横纵比
 *  \return 返回创建的特效对象
 */
- (NvsVideoEffect *)createVideoEffect:(NSString *)effectId aspectRatio:(NvsEffectRational)aspectRatio;

/*!
 *  \brief 创建特效渲染对象
 *  \return 返回创建的特效渲染对象
 */
- (NvsEffectRenderCore *)createEffectRenderCore;

/*! \cond */
/*!
 *  \brief 验证某项功能是否可用。
 *  \param sdkFunctionName sdk功能的名字
 *  \return 返回BOOL值。YES表示授权验证成功，NO则验证失败。
 */
+ (BOOL)functionalityAuthorised:(NSString *)sdkFunctionName;
/*! \endcond */

@end
