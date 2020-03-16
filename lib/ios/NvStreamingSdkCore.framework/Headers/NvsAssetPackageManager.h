//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Jan 23. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsCommonDef.h"

#import <Foundation/Foundation.h>

/*! \if ENGLISH
*   \brief Asset package type
*   \else
*   \brief 资源包类型
*   \endif
*/
typedef enum
{
    NvsAssetPackageType_VideoFx = 0,        //!< \if ENGLISH Video Fx Type \else 视频特效 \endif
    NvsAssetPackageType_VideoTransition,    //!< \if ENGLISH Video Transition Type \else 视频转场 \endif
    NvsAssetPackageType_CaptionStyle,       //!< \if ENGLISH Caption Style Type\else 字幕样式 \endif
    NvsAssetPackageType_AnimatedSticker,    //!< \if ENGLISH Animated Sticker Type \else 动画贴纸 \endif
    NvsAssetPackageType_Theme,              //!< \if ENGLISH Theme Type \else 主题 \endif
    NvsAssetPackageType_CaptureScene,       //!< \if ENGLISH Capture Scene Type \else 拍摄场景 \endif
    NvsAssetPackageType_ARScene,             //!< \if ENGLISH AR Scene Type\else AR场景 \endif
    NvsAssetPackageType_CompoundCaption    //!< \if ENGLISH Compound caption type\else 复合字幕类型 \endif
} NvsAssetPackageType;

/*! \if ENGLISH
*   \brief Asset package status
*   \else
*   \brief 资源包状态
*   \endif
*/
typedef enum
{
    NvsAssetPackageStatus_NotInstalled = 0,  //!< \if ENGLISH Not installed \else 未安装 \endif
    NvsAssetPackageStatus_Installing,        //!< \if ENGLISH Installing \else 正在安装 \endif
    NvsAssetPackageStatus_Ready,             //!< \if ENGLISH Ready \else 准备 \endif
    NvsAssetPackageStatus_Upgrading          //!< \if ENGLISH Upgrading \else 正在升级 \endif
} NvsAssetPackageStatus;

/*! \if ENGLISH
*   \brief Resource Package Manager error type.
*
*   "NvsAssetPackageManagerError_NoError" or "NvsAssetPackageManagerError_AlreadyInstalled" indicates that the installation is successful, others it fails.
*   \else
*   \brief 资源包管理器错误类别。
*
*   NvsAssetPackageManagerError值为NvsAssetPackageManagerError_NoError或者NvsAssetPackageManagerError_AlreadyInstalled表示安装成功，其他则安装失败。
*   \endif
*/
typedef enum
{
    NvsAssetPackageManagerError_NoError = 0,          //!< \if ENGLISH Installed successfully\else 安装成功 \endif
    NvsAssetPackageManagerError_Name,                 //!< \if ENGLISH Wrong name\else 名称错误 \endif
    NvsAssetPackageManagerError_AlreadyInstalled,     //!< \if ENGLISH Already installed\else 已经安装 \endif
    NvsAssetPackageManagerError_WorkingInProgress,    //!< \if ENGLISH Installation or upgrade in progress \else 安装或升级正在进行中 \endif
    NvsAssetPackageManagerError_NotInstalled,         //!< \if ENGLISH Not installed \else 尚未安装 \endif
    NvsAssetPackageManagerError_ImproperStatus,       //!< \if ENGLISH Incorrect status \else 不正确状态 \endif
    NvsAssetPackageManagerError_Decompression,        //!< \if ENGLISH Decompression error \else 解压错误 \endif
    NvsAssetPackageManagerError_InvalidPackage,       //!< \if ENGLISH Invalid assets package \else 无效包 \endif
    NvsAssetPackageManagerError_AssetType,            //!< \if ENGLISH Resource type error \else 资源类型错误 \endif
    NvsAssetPackageManagerError_Permission,           //!< \if ENGLISH Permission error \else 许可错误 \endif
    NvsAssetPackageManagerError_MetaContent,          //!< \if ENGLISH Meta content error \else 元内容错误 \endif
    NvsAssetPackageManagerError_SdkVersion,           //!< \if ENGLISH Wrong SDK version \else Sdk版本错误 \endif
    NvsAssetPackageManagerError_UpgradeVersion,       //!< \if ENGLISH Upgrade version error \else 升级版本错误 \endif
    NvsAssetPackageManagerError_IO,                   //!< \if ENGLISH Input and output error \else 输入输出错误 \endif
    NvsAssetPackageManagerError_Resource              //!< \if ENGLISH Resource error \else 资源错误 \endif
} NvsAssetPackageManagerError;

/*! \if ENGLISH
*   \brief Asset package aspect ratio
*   \else
*   \brief 资源包支持的横纵比
*   \endif
*/
typedef enum {
    NvsAssetPackageAspectRatio_16v9 = 1,
    NvsAssetPackageAspectRatio_1v1 = 2,
    NvsAssetPackageAspectRatio_9v16 = 4,
    NvsAssetPackageAspectRatio_4v3 = 8,
    NvsAssetPackageAspectRatio_3v4 = 16,
    NvsAssetPackageAspectRatio_18v9 = 32,
    NvsAssetPackageAspectRatio_9v18 = 64
} NvsAssetPackageAspectRatio;


typedef struct {
    bool enabled;
    float amplitude;
    float whitening;
    float reddening;
    bool sharpenEnabled;
    bool defaultBeautyEnabled;
    float defaultBeautyIntensity;
} NvsARSceneBeautyPreset;

typedef struct {
    bool enabled;
    float eyeSizeWarp;
    float eyeCornerStretch;
    float faceWidthWarp;
    float faceLengthWarp;
    float foreheadWarp;
    float hairlineWarp;
    float malarWarp;
    float jawWarp;
    float chinWarp;
    float eyebrowWarp;
    float eyeDistanceWarp;
    float noseLengthWarp;
    float noseWidthWarp;
    float mouthSizeWarp;
    float mouthWidthWarp;
    float mouthCornerLift;
    float faceSizeWarp;
} NvsARSceneShapeBeautificationPreset;


@protocol NvsAssetPackageManagerDelegate <NSObject>
@optional

/*! \if ENGLISH
 *  \brief Notifies the accomplishment of asset package installation
 *  \param assetPackageId Asset package ID
 *  \param assetPackageFilePath Asset package file path
 *  \param assetPackageType Asset package type
 *  \param error Returns error value of installation. "NvsAssetPackageManagerError_NoError" indicates that the installation succeeds, otherwise it fails.
 *  \else
 *  \brief 通知资源包的安装过程结束
 *  \param assetPackageId 安装资源包ID
 *  \param assetPackageFilePath 安装资源包的文件路径
 *  \param assetPackageType 安装资源包的类型
 *  \param error 返回安装过程的错误值。值为NvsAssetPackageManagerError_NoError表示安装成功，否则表示安装失败
 *  \endif
 *  \sa didFinishAssetPackageUpgrading:filePath:type:error:
 */
- (void)didFinishAssetPackageInstallation:(NSString *)assetPackageId filePath:(NSString *)assetPackageFilePath type:(NvsAssetPackageType)assetPackageType error:(NvsAssetPackageManagerError)error;

/*! \if ENGLISH
 *  \brief Notifies the completion of asset package upgrade.
 *  \param assetPackageId Asset package ID.
 *  \param assetPackageFilePath Asset package file path
 *  \param assetPackageType Asset package type
 *  \param error Returns error value of upgrading. "NvsAssetPackageManagerError_NoError" indicates that the installation succeeds, otherwise it fails.
 *  \else
 *  \brief 通知资源包的升级过程结束
 *  \param assetPackageId 升级资源包ID
 *  \param assetPackageFilePath 升级资源包的文件路径
 *  \param assetPackageType 升级资源包的类型
 *  \param error 返回升级过程的错误值。值为NvsAssetPackageManagerError_NoError表示安装成功，否则表示安装失败。
 *  \endif
 *  \sa didFinishAssetPackageInstallation:filePath:type:error:
*/
- (void)didFinishAssetPackageUpgrading:(NSString *)assetPackageId filePath:(NSString *)assetPackageFilePath type:(NvsAssetPackageType)assetPackageType error:(NvsAssetPackageManagerError)error;

@end

/*! \if ENGLISH
 *  \brief Asset package manager for managing assets in video.
 *
 *   In the development of the SDK, the asset package manager unifies the various special asset packages including subtitles, themes, animation stickers, etc. for installation, upgrading, and uninstallation. When it is installing, upgrading, and uninstalling, there will be a corresponding error type for errors to be quickly located and resolved.
 *  \warning NvsAssetPackageManager类中，所有public API都在UI线程使用！！！
 *  \else
 *  \brief 资源包管理器，管理视频场景中的资源包
 *
 *   在SDK开发过中，资源包管理器统一对需要的各种特技资源包包括字幕，主题，动画贴纸等进行相应的安装，升级，卸载等操作。在安装，升级，卸载时，出现差错都会有相应的错误提示类型，以便快速定位和解决错误。
 *  \warning NvsAssetPackageManager类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsAssetPackageManager : NSObject

@property (nonatomic, weak) id<NvsAssetPackageManagerDelegate> delegate;

/*! \if ENGLISH
 *  \brief Gets asset package ID from asset package path.
 *  \param assetPackageFilePath Asset package file path
 *  \return Returns a string representing the assets package ID.
 *  \else
 *  \brief 从资源包的文件路径获得资源包ID
 *  \param assetPackageFilePath 资源包的文件路径
 *  \return 返回表示资源包ID的字符串
 *  \endif
*/
- (NSString *)getAssetPackageIdFromAssetPackageFilePath:(NSString *)assetPackageFilePath;

/*! \if ENGLISH
 *  \brief Gets the package version number from package file path.
 *  \param assetPackageFilePath Asset package file path
 *  \return Returns the version of package. If the asset package does not have a version number, return 1.
 *  \else
 *  \brief 从资源包的文件路径获得资源包版本号
 *  \param assetPackageFilePath 资源包的文件路径
 *  \return 返回表示资源包版本号。如果该资源包不包含版本号则返回1.
 *  \endif
*/
- (int)getAssetPackageVersionFromAssetPackageFilePath:(NSString *)assetPackageFilePath;

/*! \if ENGLISH
 *  \brief Installs asset package
 *  \param assetPackageFilePath Asset package file path
 *  \param licenseFilePath License file path
 *  \param type Asset package type
 *  \param synchronous Whether to install synchronously: A value of YES will cause the installation process to block the current thread until the installation succeeds or fails. NO means results in the installation process being asynchronously notified by the delegate (but also notified by the current thread).
 *  \param assetPackageId output value. Output asset package ID
 *  \return Returns error value of installation. "NvsAssetPackageManagerError_NoError" or "NvsAssetPackageManagerError_AlreadyInstalled" indicates that the installation succeeds (It can only be returned in synchronous installation), otherwise it fails.
 *  \else
 *  \brief 安装资源包
 *  \param assetPackageFilePath 待安装资源包的文件路径
 *  \param licenseFilePath 待安装资源包的授权文件路径
 *  \param type 待安装资源包的类型
 *  \param synchronous 是否同步安装。值为YES则安装过程会阻塞当前线程直到安装成功或者失败，NO则安装过程的结果通过delegate异步通知（但也在当前线程通知）。
 *  \param assetPackageId 返回值，返回该资源包ID。
 *  \return 返回错误类型值。NvsAssetPackageManagerError_NoError: 表示安装成功（只有同步安装才可能返回这个)，任何其它返回值都表示安装错误。
 *  \endif
 *  \sa upgradeAssetPackage:license:type:sync:assetPackageId:
 *  \sa uninstallAssetPackage:type:
*/
// 安装asset package
// @assetPackageFilePath: 待安装asset package的文件路径
// @licenseFilePath: 待安装asset package的授权文件
// @type: 待安装asset package的类型
// @synchronous: 是否同步安装
//               YES: 安装过程会阻塞当前线程直到安装成功或者失败
//               NO: 安装过程的结果通过delegate异步通知（但也在当前线程通知）
// @assetPackageId: 返回该asset package的标识符
//
// 返回值为一个错误号
// NvsAssetPackageManagerError_NoError: 表示安装成功（只有同步安装才可能返回这个值）
// NvsAssetPackageManagerError_AlreadyInstalled: 表示当前asset package已经安装
// NvsAssetPackageManagerError_WorkingInProgress: 表示安装正在进行中（只有异步安装才可能返回这个值）
// 任何其它返回值都表示安装错误
//
- (NvsAssetPackageManagerError)installAssetPackage:(NSString *)assetPackageFilePath license:(NSString *)licenseFilePath type:(NvsAssetPackageType)type sync:(BOOL)synchronous assetPackageId:(NSMutableString *)assetPackageId;

/*! \if ENGLISH
 *  \brief Upgrades asset package
 *  \param assetPackageFilePath File path of the asset package to be upgraded
 *  \param licenseFilePath License file path of the asset package to be upgraded
 *  \param type Type of the asset package to be upgraded
 *  \param synchronous Whether to upgrade synchronously. Value of YES will cause the upgrade process to block the current thread until the upgrade succeeds or fails. NO results in the upgrade process being asynchronously notified by the delegate (it can also be notified by the current thread).
 *  \param assetPackageId Output value, output the assets package ID
 *  \return Returns error value of upgrading. "NvsAssetPackageManagerError_NoError" indicates that the upgrade succeeds (It can only be returned in synchronous installation), otherwise it fails.
 *  \else
 *  \brief 升级资源包
 *  \param assetPackageFilePath 待升级资源包的文件路径
 *  \param licenseFilePath 待升级资源包的授权文件路径
 *  \param type 待升级资源包的类型
 *  \param synchronous 是否同步升级。值为YES则升级过程会阻塞当前线程直到升级成功或者失败，NO则升级过程的结果通过delegate异步通知（但也在当前线程通知）。
 *  \param assetPackageId 返回值，返回该资源包ID
 *  \return 返回错误类型。值为NvsAssetPackageManagerError_NoError表示升级成功（只有同步升级才可能返回这个)，任何其它返回值都表示升级错误。
 *  \endif
 *  \sa installAssetPackage:license:type:sync:assetPackageId:
 *  \sa uninstallAssetPackage:type:
*/
// 升级asset package
// @assetPackageFilePath: 待升级asset package的文件路径
// @licenseFilePath: 待升级asset package的授权文件
// @type: 待升级asset package的类型
// @synchronous: 是否同步升级
//               YES: 升级过程会阻塞当前线程直到升级成功或者失败
//               NO: 升级过程的结果通过delegate异步通知（但也在当前线程通知）
// @assetPackageId: 返回该asset package的标识符
//
// 返回值为一个错误号
// NvsAssetPackageManagerError_NoError: 表示升级成功（只有同步升级才可能返回这个值）
// NvsAssetPackageManagerError_NotInstalled: 表示当前asset package尚未安装
// NvsAssetPackageManagerError_WorkingInProgress: 表示升级正在进行中（只有异步升级才可能返回这个值）
// 任何其它返回值都表示升级错误
//
- (NvsAssetPackageManagerError)upgradeAssetPackage:(NSString *)assetPackageFilePath license:(NSString *)licenseFilePath type:(NvsAssetPackageType)type sync:(BOOL)synchronous assetPackageId:(NSMutableString *)assetPackageId;

/*! \if ENGLISH
 *  \brief Uninstalls asset package
 *  \param assetPackageId ID of the asset package to be uninstalled
 *  \param type Type of the asset package to be uninstalled
 *  \return Returns error value of uninstallation. "NvsAssetPackageManagerError_NoError" indicates that the uninstallation is successful, otherwise it fails.
 *  \else
 *  \brief 卸载资源包
 *  \param assetPackageId 待卸载资源包ID
 *  \param type 待卸载资源包的类型
 *  \return 返回错误类型。返回NvsAssetPackageManagerError_NoError表示卸载成功，其它则卸载失败
 *  \endif
 *  \sa installAssetPackage:license:type:sync:assetPackageId:
 *  \sa upgradeAssetPackage:license:type:sync:assetPackageId:
*/
- (NvsAssetPackageManagerError)uninstallAssetPackage:(NSString *)assetPackageId type:(NvsAssetPackageType)type;

/*! \if ENGLISH
 *  \brief Get the state of asset package.
 *  \param assetPackageId ID of the asset package to be checked
 *  \param type Asset package type
 *  \return Returns the current state value of asset package.
 *  \else
 *  \brief 获取资源包的当前状态。
 *  \param assetPackageId 待查询状态资源包ID
 *  \param type 待查询状态资源包的类型
 *  \return 返回资源包的当前状态值.
 *  \endif
*/
- (NvsAssetPackageStatus)getAssetPackageStatus:(NSString *)assetPackageId type:(NvsAssetPackageType)type;

/*! \if ENGLISH
 *  \brief Gets the version number of the installed asset package.
 *  \param assetPackageId ID of the asset package to be checked
 *  \param type Type of the asset package to be checked
 *  \return Returns the version number of the asset package. Returns 1 if asset package is not installed.
 *  \else
 *  \brief 获取已安装资源包的版本号
 *  \param assetPackageId 待查询状态资源包ID
 *  \param type 待查询状态资源包的类型
 *  \return 返回资源包的版本号。如果该资源包未安装，则返回1。
 *  \endif
*/
- (int)getAssetPackageVersion:(NSString *)assetPackageId type:(NvsAssetPackageType)type;

/*! \if ENGLISH
 *  \brief Gets the supported aspect ratio of the asset package.
 *  \param assetPackageId ID of the asset package to be checked.
 *  \param type Type of the asset package to be checked.
 *  \return Returns the supported aspect ratio of the asset package, which is the result of a bitwise OR operation of several aspect ratios (NvsAssetPackageAspectRatio_XXX).
 *  \else
 *  \brief 获取资源包的所支持的横纵比
 *  \param assetPackageId 待查询状态资源包ID
 *  \param type 待查询状态资源包的类型
 *  \return 返回资源包的所支持的横纵比，这个值是若干横纵比(NvsAssetPackageAspectRatio_XXX)的按位或的结果。
 *  \endif
*/
- (int)getAssetPackageSupportedAspectRatio:(NSString *)assetPackageId type:(NvsAssetPackageType)type;

/*! \if ENGLISH
 *  \brief Gets a list of asset packages of certain type.
 *  \param type Asset package type
 *  \return Return an NSArray array object. It represents a list of asset packages of a certain type. Each NSString element in the list is an asset package ID.
 *  \else
 *  \brief 获取某个类型的资源包列表
 *  \param type 资源包类型
 *  \return 返回NSArray数组对象，表示某个类型下资源包的的列表。列表里每个NSString元素都是一个资源包ID。
 *  \endif
*/
// 获取某个类型的asset package的列表
// @type: asset package的类型
// 返回值为一个NSString类型的NSArray，每一个NSString都是一个资源包的标识符
- (NSArray *)getAssetPackageListOfType:(NvsAssetPackageType)type;

/*! \if ENGLISH
 *  \brief Defines if it is a customized sticker
 *  \param uuidString Sticker uuid
 *  \return Returns BOOL value,which indicates whether it is customized sticker.
 *  \else
 *  \brief 判断是否为自定义贴纸
 *  \param uuidString 贴纸uuid
 *  \return 返回BOOL值，表示是否为自定义贴纸
 *  \endif
 *  \since 1.11.0
*/
- (BOOL)isCustomAnimatedSticker:(NSString *)uuidString;

/*! \if ENGLISH
 *  \brief Defines if it is particle Fx
 *  \param uuidString Fx Asset uuid
 *  \return Returns BOOL value,which indicates whether it is particle Fx
 *  \else
 *  \brief 判断是否为粒子特效
 *  \param uuidString 特效资源uuid
 *  \return 返回BOOL值，表示是否为粒子特效。
 *  \endif
 *  \since 1.14.0
*/
- (BOOL)isParticleFx:(NSString *)uuidString;

/*!
 *	\if ENGLISH
 *  \brief Check whether a theme package contain music
 *  \param uuidString theme package uuid
 *  \return Returns BOOL value indicating whether it contain music
 *	\else
 *  \brief 检查主题包是否含有音乐
 *  \param uuidString 主题包uuid
 *  \return 返回BOOL值，表示否含有音乐
 *	\endif
 *  \since 2.6.0
 */
- (BOOL)isThemeContainMusic:(NSString *)uuidString;

/*! \if ENGLISH
 *  \brief Gets the Fx description of an asset of type VideoFx
 *  \param uuidString Fx asset uuid
 *  \return Returns a String object,the Fx description of the Fx asset
 *  \else
 *  \brief 获取某个类型为VideoFx的资源的特效描述信息
 *  \param uuidString 特效资源uuid
 *  \return 返回String对象，特效资源的特效描述信息
 *  \endif
 *  \since 1.14.0
*/
- (NSString *)GetVideoFxAssetPackageDescription:(NSString *)uuidString;

/*!
 *	\if ENGLISH
 *  \brief Get the prompt message of the ARScene asset package
 *  \param uuidString asset package uuid
 *  \return Returns a String object which represent the prompt message.
 *	\else
 *  \brief 获取ARScene资源包的提示信息
 *  \param uuidString 资源包uuid
 *  \return 返回提示信息的String对象
 *	\endif
 *  \since 2.9.0
 */
- (NSString *)getARSceneAssetPackagePrompt:(NSString *)uuidString;

/*!
 *	\if ENGLISH
 *  \brief Get Beauty effect preset in a ARScene asset package
 *  \param uuidString asset package uuid
 *  \param beautyPreset a pointer of NvsARSceneBeautyPreset, preset data will be returned in this structure
 *  \return Returns YES on success, NO on failure or if there is no preset,
 *          data in preset will be undefined if this method returns NO!
 *	\else
 *  \brief 获取ARScene资源包美颜的预设参数
 *  \param uuidString 资源包uuid
 *  \param beautyPreset 一个NvsARSceneBeautyPreset结构的指针，预设数据将会被返回在这个结构里。
 *  \return 成功时返回YES，失败或者没有预设返回NO。当返回NO时，preset里面的数据时未定义的！
 *	\endif
 *  \since 2.9.0
 */
- (BOOL)getARSceneAssetPackage:(NSString *)uuidString
                  beautyPreset:(NvsARSceneBeautyPreset *)beautyPreset;

/*!
 *	\if ENGLISH
 *  \brief Get shape beautification effect preset in a ARScene asset package
 *  \param uuidString asset package uuid
 *  \param shapeBeautificationPreset a pointer of NvsARSceneShapeBeautificationPreset, preset data will be returned in this structure
 *  \return Returns YES on success, NO on failure or if there is no preset,
 *          data in preset will be undefined if this method returns NO!
 *	\else
 *  \brief 获取ARScene资源包美型的预设参数
 *  \param uuidString 资源包uuid
 *  \param shapeBeautificationPreset 一个NvsARSceneShapeBeautificationPreset结构的指针，预设数据将会被返回在这个结构里。
 *  \return 成功时返回YES，失败或者没有预设返回NO。当返回NO时，preset里面的数据时未定义的！
 *	\endif
 *  \since 2.9.0
 */
- (BOOL)getARSceneAssetPackage:(NSString *)uuidString
     shapeBeautificationPreset:(NvsARSceneShapeBeautificationPreset *)shapeBeautificationPreset;

/*! \cond */
- (NSString *)decodeFile:(NSString *)fileFile
                 licPath:(NSString *)licPath
                  isJson:(BOOL)isJson;
/*! \endcond */
@end

