//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Aug 2. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <Foundation/Foundation.h>
#import "NvsCommonDef.h"


/*! \if ENGLISH
 *  \brief Human behavior detection configuration options
 *  \else
 *  \brief 人体行为检测配置选项
 *  \endif
*/
typedef enum {
    DetectionFlag_SupportFaceDetect = 1,                //!< \if ENGLISH Detection faces. \else 检测人脸 \endif
    DetectionFlag_SupportHandDetect = 2,                //!< \if ENGLISH Detection gesture. \else 检测手势 \endif
    DetectionFlag_SupportSegmentDetect = 4,             //!< \if ENGLISH Detection background segmentation. \else 检测背景分割 \endif
    DetectionFlag_SupportFaceExtraDetect = 8,           //!< \if ENGLISH Detectes face extra \else 检测人脸扩展点 \endif
    DetectionFlag_SupportEyeballCenterDetect = 16,       //!< \if ENGLISH Detectes eyeball center \else 检测眼球中心 \endif
    DetectionFlag_SupportEyeballContourDetect = 32,      //!< \if ENGLISH Detectes eyeball contour \else 检测眼球四周 \endif
} DetectionFlag;

/*! \if ENGLISH
 *  \brief Type of submodel data.
 *  \else
 *  \brief 子模型数据类型
 *  \endif
*/
typedef enum {
    Sub_Model_TYPE_Extra_Face_Points = 1,   //!< \if ENGLISH Face extension point model data. \else 人脸扩展点模型数据 \endif
    Sub_Model_TYPE_Face_Attribute ,         //!< \if ENGLISH Face attribute model data. \else 人脸属性模型数据 \endif
    Sub_Model_TYPE_Hand ,                   //!< \if ENGLISH Hand model data. \else 手模型数据 \endif
    Sub_Model_TYPE_Body_Fourteen ,          //!< \if ENGLISH Body 14 point model data. \else 身体14点模型数据 \endif
    Sub_Model_TYPE_Avatar_Core ,            //!< \if ENGLISH AVATAR model data \else AVATAR模型数据 \endif
    Sub_Model_TYPE_EyeBall_Contour ,        //!< \if ENGLISH Eye corner model data. \else 眼角点模型数据 \endif
    Sub_Model_TYPE_EyeBall_Center ,         //!< \if ENGLISH Eye center point model data. \else 眼球中心点模型数据 \endif
    Sub_Model_TYPE_Cat_Face ,               //!< \if ENGLISH Cat face model data. \else 猫脸模型数据 \endif
    SubModelType_AVATAR_HELP ,              //!< \if ENGLISH AVATAR help model data \else AVATAR模型辅助信息数据 \endif
    Sub_Model_Type_Segment_Detected,        //!< \if ENGLISH segment model data \else 背景分割模型数据 \endif
} SubModelType;

NVS_EXPORT @interface NvsFaceEffect2Init : NSObject


/*! \if ENGLISH
 *  \brief Check authorization file
 *  \param licFile Authorization file
 *  \else
 *  \brief 检查授权文件
 *  \param licFile 授权文件
 *  \endif
*/
+(bool) authentification:(NSString*) licFile;

+(bool) setupModeData:(NSString*) modeFile;

+(bool) setupModeData:(NSString*) modeFile withMode:(int) flags;

+(bool) setupSubModelData:(NSString*) modeFile withModel:(int) modelType;

+(bool) removeSubModelData:(int) modelType;

+(void) setMaxFaces:(int) maxFaceCount;

+(void) setMaxCatFaces:(int) maxFaceCount;

+(void) finish;

@end
