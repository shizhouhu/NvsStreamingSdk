//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2019. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Apr 20. 2019
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import <UIKit/UIImage.h>
#import "NvsCommonDef.h"


/*! \cond */
@protocol NvsIconGeneratorDelegate<NSObject>

- (void)didIconReady:(UIImage *)icon timestamp:(int64_t)timestamp taskId:(int64_t)timestamp;

@end


NVS_EXPORT @interface NvsIconGenerator : NSObject

@property (nonatomic, weak) id<NvsIconGeneratorDelegate> delegate;

- (instancetype)init;

- (UIImage *)getIconFromCache:(NSString *)mediaFilePath timestamp:(int64_t)timestamp flags:(int)flags;

- (int64_t)getIcon:(NSString *)mediaFilePath timestamp:(int64_t)timestamp flags:(int)flags;

- (void)cancelTask:(int64_t)taskId;

@end
/*! \endcond */

