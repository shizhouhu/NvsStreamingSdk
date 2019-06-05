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
 *  \brief AR effects.
 *  \else
 *  \brief AR特效
 *  \endif
*/
NVS_EXPORT @interface NvsAREffect : NSObject

/*! \if ENGLISH
 *  \brief Initialize face effects.
 *  \else
 *  \brief 初始化人脸特效
 *  \endif
*/
+(void) InitAREffect:(NSString*) faceModelPath landmark:(NSString *)landmarkModelPath;


+(void) AREffectFinish;

@end
