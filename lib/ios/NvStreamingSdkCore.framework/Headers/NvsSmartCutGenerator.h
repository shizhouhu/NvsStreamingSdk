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

/*! \if ENGLISH
 *   \brief SmartCutGenerator data class.
 *   \else
 *   \brief 智能剪辑结果数据类
 *   \endif
 */
NVS_EXPORT @interface NvsSmartCutClipData : NSObject

@property (nonatomic, assign)   int                 templateSlotIndex;
@property (nonatomic, copy)     NSString*           videoFilePath;
@property (nonatomic, assign)   long                trimIn;
@property (nonatomic, assign)   long                trimOut;
@property (nonatomic, assign)   BOOL                nospeed;
@property (nonatomic, assign)   BOOL                isImage;
@property (nonatomic, assign)   BOOL                imageMotion;

@end

NVS_EXPORT @interface NvsSmartCutCaptionInfo : NSObject

@property (nonatomic, assign)   int                 templateSlotIndex;
@property (nonatomic, copy)     NSString*           text;
@property (nonatomic, copy)     NSString*           style;
@property (nonatomic, assign)   long                duration;

@end

NVS_EXPORT @interface NvsSmartCutTransitionInfo : NSObject

@property (nonatomic, assign)   int                 templateSlotIndex;
@property (nonatomic, copy)     NSString*           name;
@property (nonatomic, assign)   long                duration;

@end

NVS_EXPORT @interface NvsSmartCutFilterInfo : NSObject

@property (nonatomic, assign)   int                 templateSlotIndex;
@property (nonatomic, copy)     NSString*           name;
@property (nonatomic, assign)   long                duration;

@end

NVS_EXPORT @interface NvsSmartCutSpeedInfo : NSObject

@property (nonatomic, assign)   long                duration;
@property (nonatomic, assign)   float               speed0;
@property (nonatomic, assign)   float               speed1;

@end

NVS_EXPORT @interface NvsSmartCutSpeedList : NSObject

@property (nonatomic, assign)   int                 templateSlotIndex;
@property (nonatomic, strong)   NSMutableArray<NvsSmartCutSpeedInfo*>* speeds;

@end

NVS_EXPORT @interface NvsSmartCutSCDData : NSObject

@property (nonatomic, assign)   uint64_t               frameIndex;
@property (nonatomic, assign)   int8_t                 sceneType;
@property (nonatomic, assign)   int8_t                 environment;
@property (nonatomic, assign)   int8_t                 location;
@property (nonatomic, assign)   int8_t                 placeTypeL1;
@property (nonatomic, assign)   int8_t                 placeTypeL2;

@end

NVS_EXPORT @interface NvsSmartCutSCDInfo : NSObject

@property (nonatomic, copy)     NSString*           videoFilePath;
@property (nonatomic, copy)     NSArray<NvsSmartCutSCDData*>* scdDataArray;

@end


NVS_EXPORT @interface NvsSmartCutResultData : NSObject

@property (nonatomic, strong) NSString *templatePath;
@property (nonatomic, strong) NSString *videoDate;
@property (nonatomic, strong) NSMutableArray <NvsSmartCutClipData *>*smartCutClips;
@property (nonatomic, strong) NSString *titleFilePath;
@property (nonatomic, strong) NSString *endingFilePath;
@property (nonatomic, strong) NSMutableArray <NvsSmartCutCaptionInfo *>*smartCutCaptions;
@property (nonatomic, strong) NSMutableArray <NvsSmartCutTransitionInfo *>*smartCutTransitions;
@property (nonatomic, strong) NSMutableArray <NvsSmartCutFilterInfo *>*smartCutClipFilters;
@property (nonatomic, strong) NSMutableArray <NvsSmartCutSpeedList *>*smartCutSpeeds;
@property (nonatomic, strong) NvsSmartCutFilterInfo *endingFilter;
@property (nonatomic, strong) NSString *musicFilePath;
@property (nonatomic, strong) NSMutableArray <NSString *>*timelineFilters;
@property (nonatomic, strong) NSString *smartFilter;
@property (nonatomic, strong) NvsSmartCutCaptionInfo *titleCaption;
@property (nonatomic, strong) NvsSmartCutCaptionInfo *endingCaption;

@end


/*! \if ENGLISH
 *  \brief smart cut generator callback interface
 *  \else
 *  \brief 智能剪辑回调接口
 *  \endif
 */
@protocol SmartCutGeneratorDelegate <NSObject>
@optional

/*! \if ENGLISH
 *  \brief Finish smart editing.
 *  \param smartCutResult Result of smart editing
 *  \else
 *  \brief 完成剪辑
 *  \param smartCutResult 剪辑完成后的数据结果
 *  \endif
 */
- (void)didSmartCutFinished:(NvsSmartCutResultData*) smartCutResult;

/*! \if ENGLISH
 *  \brief editing exception information.
 *  \param errorType Type of editing error.
 *  \else
 *  \brief 剪辑异常信息
 *  \param errorType 错误类型
 *  \endif
 */
- (void)didSmartCutError:(int) errorType;

/*! \if ENGLISH
 *  \brief editing progress.
 *  \param progress editing progress.
 *  \else
 *  \brief 剪辑进度
 *  \param progress 剪辑进度
 *  \endif
 */
- (void)didSmartCutProgress:(float) progress;

@end


/*! \if ENGLISH
 *   \brief Smart cut generator class
 *   \else
 *   \brief 智能剪辑类
 *   \endif
 */
NVS_EXPORT @interface NvsSmartCutGenerator : NSObject

@property (weak, atomic) id<SmartCutGeneratorDelegate> delegate;

/*! \if ENGLISH
 *  \brief Initializes smart cut instance.
 *  \param flags Flags, zero temporarily
 *  \return Returns a smart cut instance object.
 *  \else
 *  \brief 对智能剪辑类的单例实例进行初始化
 *  \param flags 标志字段，目前暂时为0
 *  \return 返回智能剪辑类的单例实例对象
 *  \endif
 *  \since 2.13.0
 *  \sa close
 */
+ (instancetype)sharedInstance:(int)flag;


/*! \if ENGLISH
 *  \brief Destroys the smart cut object instance. note: it can be created again after destruction.
 *  \else
 *  \brief 销毁智能剪辑类实例。注意: 销毁之后可以再次创建及获取
 *  \endif
 *  \sa sharedInstance
 */
+ (void)close;


/*! \if ENGLISH
 *  \brief start smart editing
 *  \param scdFileList scd file path list
 *  \param videoFileList video or photo file path list
 *  \param templatePathList template file path list
 *  \param captionPath caption file path
 *  \param captionLicPath caption lic file path
 *  \param filterPath filter file path
 *  \param filterLicPath filter lic file path
 *  \param location location info，will be displayed in the video as a caption
 *  \return Returns a boolean value. true means successful and false means failure
 *  \else
 *  \brief 开始智能剪辑
 *  \param scdFileList scd文件路径列表
 *  \param videoFileList 视频/图片文件路径列表
 *  \param templatePathList 模板路径列表
 *  \param captionPath 字幕文件路径
 *  \param captionLicPath 字幕授权文件路径
 *  \param filterPath 滤镜文件路径
 *  \param filterLicPath 滤镜授权文件路径
 *  \param location 地理位置，将作为地理字幕显示在视频中
 *  \return 返回布尔值。值为true则成功，false则失败。
 *  \endif
 */
- (BOOL)startSmartCut:(NSMutableArray<NSString*>*)scdFileList
        videoFileList:(NSMutableArray<NSString*>*)videoFileList
     templatePathList:(NSMutableArray<NSString*>*)templatePathList
          captionPath:(NSString*)captionPath captionLicPath:(NSString*)captionLicPath
           filterPath:(NSString*)filterPath filterLicPath:(NSString*)filterLicPath
             location:(NSString*)location;

-(BOOL)startSmartCut:(NSArray<NvsSmartCutSCDInfo*>*)scdInfoList
    templatePathList:(NSArray<NSString*>*)templatePathList
         captionPath:(NSString*)captionPath
      captionLicPath:(NSString*)captionLicPath
          filterPath:(NSString*)filterPath
       filterLicPath:(NSString*)filterLicPath
            location:(NSString*)location;

/*! \if ENGLISH
 *  \brief Change template
 *  \param templatePath template path
 *  \else
 *  \brief 切换模板
 *  \param templatePath 模板路径
 *  \endif
 */
- (BOOL)changeTemplate:(NSString*)templatePath;

@end

