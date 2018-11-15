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

/*!
 *  \brief
 *  人体行为检测配置选项
 */
typedef enum {
    DetectionFlag_SupportFaceDetect = 1,  //!< \if ENGLISH \else 检测人脸 \endif
    DetectionFlag_SupportHandDetect = 2,   //!< \if ENGLISH \else 检测手势 \endif
    DetectionFlag_SupportSegmentDetect = 4,   //!< \if ENGLISH \else 检测背景分割 \endif
} DetectionFlag;

NVS_EXPORT @interface NvsFaceEffect2Init : NSObject

/*!
   \brief 检查授权文件
*/
+(bool) authentification:(NSString*) licFile;

+(bool) setupModeData:(NSString*) modeFile;

+(bool) setupModeData:(NSString*) modeFile withMode:(int) flags;

+(void) setMaxFaces:(int) maxFaceCount;

+(void) finish;

@end
