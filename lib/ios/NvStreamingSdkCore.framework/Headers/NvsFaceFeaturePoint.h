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

/// @brief 供106点使用
NVS_EXPORT @interface NvsFaceInfo : NSObject

@property (nonatomic, assign) int faceId;                       ///< faceID
@property (nonatomic, strong) NSMutableArray *pointsArray;      ///< 人脸106关键点的数组, (NvsEffectPosition2D *)
@property (nonatomic, strong) NSMutableArray *visibilityArray;  /// 对应点是否被遮挡, 未被遮挡1.0, 遮挡值是0.0, (float)

@end

NVS_EXPORT @interface NvsFaceFeaturePoint : NvsArbitraryData

@property (nonatomic, strong) NSMutableArray *faces;    ///< 检测到的人脸信息，(NvsFaceInfo *)
@property (nonatomic, assign) int faceCount;            ///< 检测到的人脸数目

- (instancetype)initWithCapacity:(int)capacity;

@end
