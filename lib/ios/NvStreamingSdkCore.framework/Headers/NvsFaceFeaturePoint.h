//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2016. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Sep 7. 2019
//   Author:        NewAuto video team
//================================================================================

#pragma once

#import <Foundation/Foundation.h>
#import "NvsEffectCommonDef.h"
#import "NvsArbitraryData.h"

/*! \if ENGLISH
*  \brief For 106 points
*  \else
*  \brief 供106点使用
*  \endif
*/
NVS_EXPORT @interface NvsFaceInfo : NSObject

@property (nonatomic, assign) int faceId;                       //!< \if ENGLISH Face ID. \else 人脸ID \endif
@property (nonatomic, strong) NSMutableArray *pointsArray;      //!< \if ENGLISH An array of 106 key points of the face. \else 人脸106关键点的数组 \endif
@property (nonatomic, strong) NSMutableArray *visibilityArray;  //!< \if ENGLISH Whether the corresponding point is occluded. If it is not occluded, it shows 1.0. 0.0 means occlusion. \else 对应点是否被遮挡, 未被遮挡1.0, 遮挡值是0.0 \endif

@end

NVS_EXPORT @interface NvsFaceFeaturePoint : NvsArbitraryData

@property (nonatomic, strong) NSMutableArray *faces;    //!< \if ENGLISH The information of face which detected. \else 检测到的人脸信息 \endif
@property (nonatomic, assign) int faceCount;             //!< \if ENGLISH The count of faces which detected \else 检测到的人脸数目 \endif

- (instancetype)initWithCapacity:(int)capacity;

@end
