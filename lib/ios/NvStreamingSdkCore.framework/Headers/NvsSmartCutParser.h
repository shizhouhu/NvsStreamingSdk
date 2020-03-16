//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2019. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Aug 21. 2019
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import "NvsCommonDef.h"

@class NvsInferenceScheme;

/*!
 *  \if ENGLISH
 *   @name Smart context creation flags
 *  \else
 *   @name 智能剪辑标志
 *  \endif
 */
typedef enum {
    NvsSmartCutParserFlag_None = 0        //!< \if ENGLISH Supports up to 4K video editing. \else 支持4K视频编辑 \endif
} NvsSmartCutParserFlag;

/*!
 *  \if ENGLISH
 *   @name Framework type flags
 *  \else
 *   @name 架构类型标志
 *  \endif
 */
typedef enum {
    NvsFrameworkTypeFlag_Unknown = -1,
    NvsFrameworkTypeFlag_General = 0,
    NvsFrameworkTypeFlag_MobileGeneral = 1,
    NvsFrameworkTypeFlag_Huawei = 2,
    NvsFrameworkTypeFlag_Qualcomm = 3,
    NvsFrameworkTypeFlag_Mediatek = 4,
    NvsFrameworkTypeFlag_Nnapi = 5,
} NvsFrameworkTypeFlag;

/*!
 *  \if ENGLISH
 *   @name Device type flags
 *  \else
 *   @name 设备类型标志
 *  \endif
 */
typedef enum {
    NvsDeviceTypeFlag_Unknown = -1,
    NvsDeviceTypeFlag_Cpu = 0,
    NvsDeviceTypeFlag_Gpu = 1,
    NvsDeviceTypeFlag_Npu = 2
} NvsDeviceTypeFlag;

@protocol NvsSmartCutParserDelegate <NSObject>
@optional

/*! \if ENGLISH
 *  \brief Start detecting.
 *  \param mediaPath media path.
 *  \param taskId task ID.
 *  \else
 *  \brief 开始检测
 *  \param mediaPath 资源路径
 *  \param taskId 任务序号
 *  \endif
 */
- (void)didDetectStarted:(NSString*)mediaPath taskId:(int64_t)taskId;

/*! \if ENGLISH
 *  \brief Finish detecting.
 *  \param mediaPath media path.
 *  \param scdPath scd path.
 *  \else
 *  \brief 完成检测
 *  \param mediaPath 资源路径
 *  \param scdPath 检测结果路径
 *  \endif
 */
- (void)didDetectFinished:(NSString*)mediaPath scdPath:(NSString*)scdPath;

/*! \if ENGLISH
*  \brief detect exception information.
*  \param errorType Type of detect error.
*  \else
*  \brief 检测异常信息
*  \param errorType 错误类型
*  \endif
*/
- (void)didDetectError:(int)errorType;

/*! \if ENGLISH
*  \brief Progress of detect.
*  \param mediaPath media path.
*  \param progress Progess value.
*  \else
*  \brief 检测进度
*  \param mediaPath 资源路径
*  \param progress 进度值
*  \endif
*/
- (void)didDetectProgress:(NSString*)mediaPath progress:(float)progress;

@end

/*! \if ENGLISH
*   \brief Smart cut parser class
*   \warning In the NvsSmartCutParser class, all public APIs can be used not only in the UI thread, but also across threads! ! !
*   \else
*   \brief 智能剪辑类
*   \warning NvsSmartCutParser类中，所有public API不仅可以在UI线程使用，也可以跨线程使用！！！
*   \endif
*/

NVS_EXPORT @interface NvsSmartCutParser : NSObject

@property (atomic, weak) id<NvsSmartCutParserDelegate> delegate;

/*! \if ENGLISH
*  \brief query support schemes.
*  \return Returns sheme list.
*  \else
*  \brief 获取支持的推理方案
*  \return 返回支持的方案列表
*  \endif
*  \sa getInstance
*  \sa close
*/
+ (NSArray *)querySupportedSchemes;

/*! \if ENGLISH
 *  \brief Initializes smart cut instance.
 *  \param scheme.
 *  \param sceneModelPath scene model.
 *  \param placeModelPath place model.
 *  \return Returns a smart cut instance object.
 *  \return Returns an object instance of the smart cut parser.
 *  \else
 *  \brief 对智能剪辑类的单例实例进行初始化
 *  \param scheme 方案.
 *  \param sceneModelPath 景别模型文件.
 *  \param placeModelPath 场景模型文件.
 *  \return 返回智能剪辑类的对象实例
 *  \endif
 *  \sa close
*/
+ (NvsSmartCutParser *)init:(NvsInferenceScheme *)scheme sceneModelPath:(NSString *)sceneModelPath placeModelPath:(NSString *) placeModelPath;


/*! \if ENGLISH
 *  \brief Initializes smart cut instance.
 *  \param scheme.
 *  \param sceneModelPath scene model.
 *  \param placeModelPath place model.
 *  \param flags Flags, 0 if no special requirement.
 *  \return Returns a smart cut instance object.
 *  \return Returns an object instance of the smart cut parser.
 *  \else
 *  \brief 对智能剪辑类的单例实例进行初始化
 *  \param scheme 方案.
 *  \param sceneModelPath 景别模型文件.
 *  \param placeModelPath 场景模型文件.
 *  \param flags 标志字段，如果无特殊需求请填写0。
 *  \return 返回智能剪辑类的对象实例
 *  \endif
 *  \sa close
*/
+ (NvsSmartCutParser *)init:(NvsInferenceScheme *)scheme sceneModelPath:(NSString *)sceneModelPath placeModelPath:(NSString *) placeModelPath flags:(int)flags;

/*! \if ENGLISH
 *  \brief Destroys the smart cut object instance. note: it can be created again after destruction.
 *  \else
 *  \brief 销毁智能剪辑类实例。注意: 销毁之后可以再次创建及获取
 *  \endif
 *  \sa init
 *  \sa getInstance
 */
+ (void)close;

/*! \if ENGLISH
 *  \brief Gets the instance of smart cut object (only can use this after initialization)
 *  \return Returns the smart cut object instance.
 *  \else
 *  \brief 获取智能剪辑类的单例实例(必须进行初始化后才能使用)
 *  \return 返回智能剪辑类的单例实例对象
 *  \endif
 *  \sa init
 *  \sa close
 */
+ (NvsSmartCutParser *)getInstance;

/*! \if ENGLISH
 *  \brief set max detect thread count
 *  \param threadCount thread count
 *  \return Returns a boolean value. true means successful and false means failure
 *  \else
 *  \brief 设置最大检测线程数目
 *  \param threadCount 线程数目
 *  \return 返回布尔值。值为true则成功，false则失败。
 *  \endif
 */
- (Boolean)setMaxThreadCount:(int)threadCount;

/*! \if ENGLISH
 *  \brief detect media files
 *  \param dataArray data array
 *  \return Returns a boolean value. true means successful and false means failure
 *  \else
 *  \brief 检测资源
 *  \param dataArray 资源列表
 *  \return 返回布尔值。值为true则成功，false则失败。
 *  \endif
 */
- (Boolean)detectMediaFiles:(NSArray *)dataArray;

/*! \if ENGLISH
 *  \brief cancel media detect task.
 *  \param taskId task ID.
 *  \else
 *  \brief 取消检测任务
 *  \param taskId 任务序号
 *  \endif
 */
- (void)cancelTask:(int64_t)taskId;

/*! \if ENGLISH
 *  \brief cancel all detect tasks.
 *  \else
 *  \brief 取消所有检测任务
 *  \endif
 */
- (void)cancelAllTasks;

/*! \if ENGLISH
 *  \brief suspend all detect tasks.
 *  \else
 *  \brief 挂起检测任务
 *  \endif
 */
- (void)suspend;

/*! \if ENGLISH
 *  \brief resume all detect tasks.
 *  \else
 *  \brief 恢复所有检测任务
 *  \endif
 */
- (void)resume;

@end

/*! \if ENGLISH
 *  \brief inference scheme
 *
 *  Defines the inference scheme properties, including auto focus, auto exposure, zoom, etc.
 *  \else
 *  \brief 推理方案
 *
 *  定义采集设备的相关属性，包含自动聚焦，自动曝光，缩放等
 *  \endif
*/
NVS_EXPORT @interface NvsInferenceScheme : NSObject

@property (nonatomic) NvsFrameworkTypeFlag frameworkType;            //!< \if ENGLISH framework type \else 架构类型 \endif
@property (nonatomic) NvsDeviceTypeFlag deviceType;               //!< \if ENGLISH device type \else 设备类型 \endif

@end

/*! \if ENGLISH
*   \brief detect data class.
*   \else
*   \brief 智能检测数据类
*   \endif
*/

NVS_EXPORT @interface NvsDetectData : NSObject

@property (nonatomic) NSString* mediaPath;    //!< \if ENGLISH media path \else 资源路径 \endif
@property (nonatomic) int frameSpace;      //!< \if ENGLISH frame space \else 帧间隔 \endif
@property (nonatomic) NvsSize detectSize;      //!< \if ENGLISH detect size \else 检测区域 \endif

@end
