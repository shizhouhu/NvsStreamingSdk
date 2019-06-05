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

#import <Foundation/Foundation.h>
#import "NvsCommonDef.h"

/*! \if ENGLISH
*   \brief Asset package type
*   \else
*   \brief 资源包类型
*   \endif
*/
typedef enum
{
    NvsParticleType_Normal = 0,         //!< \if ENGLISH Particle effect without interaction. \else 一般指没有交互的粒子效果 \endif
    NvsParticleType_Touch,              //!< \if ENGLISH Particle effect controlled by touch screen. \else 触摸屏幕进行交互的粒子效果 \endif
    NvsParticleType_Gesture,            //!< \if ENGLISH Particle effect controlled by gesture. \else 手势进行交互的粒子效果 \endif
    NvsParticleType_Eye,                //!< \if ENGLISH Particle effect controlled by eye. \else 眼睛进行交互的效果 \endif
    NvsParticleType_Mouth,              //!< \if ENGLISH Particle effect controlled by mouth. \else 嘴巴进行交互的粒子效果 \endif
} NvsParticleType;


/*! \if ENGLISH
*   \brief Asset package status
*   \else
*   \brief 资源包状态
*   \endif
*/
typedef enum
{
    NvsEmitterPlace_Left = 0,       //!< \if ENGLISH The particle emitter is on the left of the current position. \else 粒子发生器在当前部位的左边 \endif
    NvsEmitterPlace_Right,          //!< \if ENGLISH The particle emitter is on the right of the current position. \else 粒子发生器在当前部位的右边 \endif
    NvsEmitterPlace_Top,            //!< \if ENGLISH The particle emitter is above the current position. \else 粒子发生器在当前部位的上边 \endif
    NvsEmitterPlace_Bottom,         //!< \if ENGLISH The particle emitter is below the current position. \else 粒子发生器在当前部位的下边 \endif
    NvsEmitterPlace_Center          //!< \if ENGLISH The particle emitter is in the middle of the current position. \else 粒子发生器在当前部位的中间 \endif
} NvsEmitterPlace;



/*! \if ENGLISH
 *  \brief Particle Fx package description parser
 *  \warning In the NvsAssetPackageParticleDescParser,all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 粒子特技包描述解析器
 *  \warning NvsAssetPackageParticleDescParser类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsAssetPackageParticleDescParser : NSObject


- (instancetype)initWithEffectDesc:(NSString *)desc;

/*! \if ENGLISH
  *  \brief Gets particle type
  *  \return Return the type of NvsParticleType.
  *  \else
  *  \brief 获取粒子类型
  *  \return 返回粒子类型
  *  \endif
*/
- (NvsParticleType) getParticleType;

/*! \if ENGLISH
 *  \brief Gets the count of particle fragments
 *  \return Returns the count of fragments.
 *  \else
 *  \brief 获取粒子分片数量
 *  \return 返回分片数量
 *  \endif
*/
-(int) getParticlePartitionCount;

/*! \if ENGLISH
 *  \brief Gets the position where a fragmented particle emitter should be placed.
 *  \param partitionIndex Partition index
 *  \return Returns the position.
 *  \else
 *  \brief 获取某一分片粒子发射器应该放置的位置
 *  \param partitionIndex 分片索引值
 *  \return 返回放置的位置
 *  \endif
*/
- (NvsEmitterPlace) getParticlePartitionPlace:(unsigned int)partitionIndex;

/*! \if ENGLISH
 *  \brief Gets a list of name for a fragmented particle emitter.
 *  \param partitionIndex Partition index
 *  \return Returns an NSArray array object representing a list of asset packages of a certain type. Each NSString element in the list is an emitter name.
 *  \else
 *  \brief 获取某一分片粒子发射器名字列表
 *  \param partitionIndex 分片索引值
 *  \return 返回NSArray数组对象，表示某个类型下资源包的的列表。列表里每个NSString元素都是一个发射器名字。
 *  \endif
*/
 - (NSArray *) getParticlePartitionEmitter:(unsigned int)partitionIndex;


/////////////////////////////////////////////////////////////////////////////////
//

/*! \if ENGLISH
 *  \brief Gets the position of the particle emitter in the left eye.
 *  \return Returns the position.
 *  \else
 *  \brief 获取放在左眼粒子发射器位置
 *  \return 返回放置的位置
 *  \endif
*/
- (NvsEmitterPlace) getLeftEyePlace;

/*! \if ENGLISH
 *  \brief Gets a list of name for the particle emitter in the left eye.
 *  \return Returns an NSArray array object representing a list of asset packages of a certain type. Each NSString element in the list is an emitter name.
 *  \else
 *  \brief 获取放在左眼粒子发射器名字列表
 *  \return 返回NSArray数组对象，表示某个类型下资源包的的列表。列表里每个NSString元素都是一个发射器名字。
 *  \endif
*/
- (NSArray *) getLeftEyeEmitter;

/*! \if ENGLISH
 *  \brief Gets the position of the particle emitter in the right eye.
 *  \return Returns the position.
 *  \else
 *  \brief 获取放在右眼粒子发射器位置
 *  \return 返回放置的位置
 *  \endif
*/
-(NvsEmitterPlace) getRightEyePlace;

/*! \if ENGLISH
 *  \brief Gets a list of name for the particle emitter in the right eye.
 *  \return Returns an NSArray array object representing a list of asset packages of a certain type. Each NSString element in the list is an emitter name.
 *  \else
 *  \brief 获取放在右眼粒子发射器名字列表
 *  \return 返回NSArray数组对象，表示某个类型下资源包的的列表。列表里每个NSString元素都是一个发射器名字。
 *  \endif
*/
-(NSArray *) getRightEyeEmitter;

@end

