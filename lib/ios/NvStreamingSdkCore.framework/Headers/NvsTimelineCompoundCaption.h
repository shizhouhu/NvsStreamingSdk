#pragma once

#import "NvsFx.h"
#import <CoreGraphics/CGGeometry.h>

/*! \if ENGLISH
 *  \brief Timeline compound caption.
 *
 *  Timeline compound captions are compound caption that is superimposed on the video, each compound caption
 *  may composed of several sub-captions. When editing a video, users can add or remove timeline compound captions and adjust the captions position.
 *  User can also set its properties such as font family, text color, etc.
 *  \warning In the NvsTimelineCompoundCaption class, all public APIs should be used in the UI thread!!!
 *  \else
 *  \brief 时间线复合字幕
 *
 *  时间线复合字幕是视频上叠加的组合型文字，每个复合字幕包含若干个子字幕。编辑视频时，可以添加和移除时间线复合字幕，并对字幕位置进行调整处理，还可以对字体，颜色属性进行修改。
 *  \warning NvsTimelineCompoundCaption类中，所有public API都必须在UI线程使用!!!
 *  \endif
 *  \since 2.9.0
 */

/*! \anchor BOUNDING_TYPE */
/*!
 *  \if ENGLISH
 *   @name Bounding type
 *  \else
 *   @name 边框类型
 *  \endif
 */

typedef enum
{
    NvsBoundingType_Text = 0,               //!< \if ENGLISH The actual text bounding \else 文字的实际边框 \endif
    NvsBoundingType_Text_Frame = 1,         //!< \if ENGLISH Text frame bounding \else 文字框的边框 \endif
    NvsBoundingType_Frame = 2,              //!< \if ENGLISH The whole bounding including decoration \else 包括装饰在内的整体边框 \endif
} NvsBoundingType;

NVS_EXPORT @interface NvsTimelineCompoundCaption : NvsFx

/*! \if ENGLISH
 *  \brief Gets number of sub-cpations in this compound caption
 *  \return Returns number of sub-cpations
 *  \else
 *  \brief 获取该复合字幕中子字幕的数量
 *  \return 子字幕数量
 *  \endif
 */
@property (readonly) NSInteger captionCount;

/*! \if ENGLISH
 *  \brief Sets whether to turn on affinity between the caption and video clip.
 *  \param enable Whether to turn on affinity between the caption and video clip
 *  \else
 *  \brief 是否开启字幕与视频片段之间的亲和度
 *  \endif
 */
@property (nonatomic) BOOL clipAffinityEnabled;


@property (readonly) int64_t inPoint;                 //!< \if ENGLISH The in point of the caption on the timeline(in microseconds) \else 字幕在时间线上显示的入点（单位微秒） \endif
@property (readonly) int64_t outPoint;                //!< \if ENGLISH The out point of the caption on the timeline (in microseconds) \else 字幕在时间线显示上的出点（单位微秒） \endif

/*! \if ENGLISH
 *  \brief Changes the in-point of the caption on the timeline.
 *  \param newInPoint The new in-point of the caption on the timeline (in microseconds).
 *  \return Returns the in-point of the caption on the timeline (in microseconds).
 *  \else
 *  \brief 改变字幕在时间线上显示的入点
 *  \param newInPoint 字幕在时间线上的新的入点（单位微秒）
 *  \return 返回字幕在时间线上的显示的入点（单位微秒）
 *  \endif
 *  \sa changeOutPoint
 *  \sa getInPoint
 *  \sa movePosition
 */
- (int64_t)changeInPoint:(int64_t)newInPoint;

/*! \if ENGLISH
*  \brief Changes the out-point of the caption on the timeline.
*  \param newOutPoint The new out-point of the caption on the timeline (in microseconds).
*  \return Returns the out-point of the caption on the timeline (in microseconds).
*  \else
*  \brief 改变字幕在时间线上显示的出点
*  \param newOutPoint 字幕在时间线上的新的出点（单位微秒）
*  \return 返回字幕在时间线上显示的出点（单位微秒）
*  \endif
*  \sa changeInPoint
*  \sa getOutPoint
*  \sa movePosition
*/
- (int64_t)changeOutPoint:(int64_t)newOutPoint;

/*! \if ENGLISH
 *  \brief Changes the display position of the caption on the timeline (the in and out points are offset from the offset value at the same time).
 *  \param offset Offset value for in and out points changes (in microseconds).
 *  \else
 *  \brief 改变字幕在时间线上的显示位置(入点和出点同时偏移offset值)
 *  \param offset 入点和出点改变的偏移值（单位微秒）
 *  \endif
 *  \sa changeInPoint
 *  \sa changeOutPoint
 */
- (void)movePosition:(int64_t)offset;

/*! \if ENGLISH
 *  \brief Sets caption text.
 *  \param captionIndex caption index to set text
 *  \param text Caption text
 *  \else
 *  \brief 设置字幕文本
 *  \param captionIndex 想要设置文字的字幕索引号
 *  \param text 字幕文本
 *  \endif
 *  \sa getText
 */
- (void)setText:(NSInteger)captionIndex
           text:(NSString *)text;

/*! \if ENGLISH
 *  \brief Get caption text.
 *  \param captionIndex caption index to get text
 *  \return Returns caption text.
 *  \else
 *  \brief 获取字幕文本
 *  \param captionIndex 想要获取文字的字幕索引号
 *  \return 返回字幕文本
 *  \endif
 *  \sa setText
 */
- (NSString *)getText:(NSInteger)captionIndex;

/*! \if ENGLISH
 *  \brief Sets caption font family.
 *  \param captionIndex caption index to set font family
 *  \param family Caption font family name. It will be set to default font if family is an empty string
 *  \else
 *  \brief 设置字幕字体
 *  \param captionIndex 想要设置字体的字幕索引号
 *  \param family 字体名称，若设为空字符串，则设为默认字体
 *  \endif
 *  \sa getFontFamily
 */
- (void)setFontFamily:(NSInteger)captionIndex
               family:(NSString *)family;

/*! \if ENGLISH
 *  \brief Get the name of caption font.
 *  \param captionIndex caption index to get font family
 *  \return Returns the name of caption font.
 *  \else
 *  \brief 获取字幕字体的名字
 *  \param captionIndex 想要获取字体的字幕索引号
 *  \return 返回字幕字体的名字
 *  \endif
 *  \sa setFontFamily
 */
- (NSString *)getFontFamily:(NSInteger)captionIndex;

/*! \if ENGLISH
 *  \brief Sets caption text color.
 *  \param captionIndex caption index to set text color
 *  \param textColor Caption text color value.
 *  \else
 *  \brief 设置字幕文本颜色
 *  \param captionIndex 想要设置文本颜色的字幕索引号
 *  \param textColor 文本颜色值
 *  \endif
 *  \sa getTextColor
 */
- (void)setTextColor:(NSInteger)captionIndex
           textColor:(const NvsColor *)textColor;

/*! \if ENGLISH
 *  \brief Gets the color value of the caption.
 *  \param captionIndex caption index to get text color
 *  \return Return NvsColor object which is the text color
 *  \else
 *  \brief 获取字幕的颜色值
 *  \param captionIndex 想要获取文本颜色的字幕索引号
 *  \return 返回NvsColor对象，表示文本的颜色值
 *  \endif
 *  \sa setTextColor
 */
- (NvsColor)getTextColor:(NSInteger)captionIndex;

/*! \if ENGLISH
 *  \brief Sets the amount of caption translation.
 *  \param translation The horizontal and vertical translation of the caption.
 *  \else
 *  \brief 设置字幕平移量
 *  \param translation 字幕平移的水平和垂直的平移值
 *  \endif
 *  \sa getCaptionTranslation
 */
- (void)setCaptionTranslation:(CGPoint)translation;

/*! \if ENGLISH
 *  \brief Gets the amount of caption translation.
 *  \return Returns CGPoint object indicating the amount of caption translation obtained.
 *  \else
 *  \brief 获取字幕的平移量
 *  \return 返回CGPoint对象，表示获得的字幕平移量
 *  \endif
 *  \sa setCaptionTranslation
 */
- (CGPoint)getCaptionTranslation;

/*! \if ENGLISH
 *  \brief Translate caption
 *  \param translationOffset Horizontal and vertical offset values for caption.
 *  \else
 *  \brief 平移字幕
 *  \param translationOffset 字幕平移的水平和垂直的偏移值
 *  \endif
 *  \sa setCaptionTranslation
 *  \sa getCaptionTranslation
 */
- (void)translateCaption:(CGPoint)translationOffset;

/*! \if ENGLISH
 *  \brief Sets caption anchor.
 *  \param anchor Anchor.
 *  \else
 *  \brief 设置字幕锚点
 *  \param anchor 锚点
 *  \endif
 *  \sa getAnchorPoint
 */
- (void)setAnchorPoint:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Gets caption anchor.
 *  \return Returns caption anchor.
 *  \else
 *  \brief 获取字幕锚点
 *  \return 返回字幕锚点
 *  \endif
 *  \sa setAnchorPoint
 */
- (CGPoint)getAnchorPoint;

/*! \if ENGLISH
 *  \brief Sets horizontal scaling factor for caption.
 *  \param scale Horizontal scaling factor.
 *  \else
 *  \brief 对字幕设置水平缩放系数
 *  \param scale 水平缩放系数
 *  \endif
 *  \sa getScaleX
 *  \sa setScaleY
 */
- (void)setScaleX:(float)scale;

/*! \if ENGLISH
 *  \brief Gets caption horizontal scaling factor.
 *  \return Returns caption horizontal scaling factor.
 *  \else
 *  \brief 获取字幕水平缩放系数
 *  \return 返回字幕水平缩放系数
 *  \endif
 *  \sa setScaleX
 *  \sa getScaleY
 */
- (float)getScaleX;

/*! \if ENGLISH
 *  \brief Sets vertical scaling factor for captions.
 *  \param scale Vertical scaling factor.
 *  \else
 *  \brief 对字幕设置垂直缩放系数
 *  \param scale 垂直缩放系数
 *  \endif
 *  \sa getScaleY
 *  \sa setScaleX
 */
- (void)setScaleY:(float)scale;

/*! \if ENGLISH
 *  \brief Gets caption vertical scaling factor.
 *  \return Returns caption vertical scaling factor.
 *  \else
 *  \brief 获取字幕垂直缩放系数
 *  \return 返回字幕垂直缩放系数
 *  \endif
 *  \sa setScaleY
 *  \sa getScaleX
 */
- (float)getScaleY;

/*! \if ENGLISH
 *  \brief Zooms caption.
 *  \param scaleFactor Caption scaling factor.
 *  \param anchor Caption zoom anchor.
 *  \else
 *  \brief 缩放字幕
 *  \param scaleFactor 字幕缩放的因子
 *  \param anchor 字幕缩放的锚点
 *  \endif
 */
- (void)scaleCaption:(float)scaleFactor
              anchor:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Sets the rotation angle for the caption.
 *  \param angle Rotation angle.
 *  \else
 *  \brief 对字幕设置旋转角度
 *  \param angle 旋转角度
 *  \endif
 *  \sa getRotationZ
 */
- (void)setRotationZ:(float)angle;

/*! \if ENGLISH
 *  \brief Gets caption rotation angle.
 *  \return Returns caption rotation angle.
 *  \else
 *  \brief 获取字幕旋转角度
 *  \return 返回字幕旋转角度
 *  \endif
 *  \sa setRotationZ
 */
- (float)getRotationZ;

/*! \if ENGLISH
 *  \brief Rotates captions.
 *  \param angle Angle of caption rotation.
 *  \param anchor Anchor of caption rotation.
 *  \else
 *  \brief 旋转字幕
 *  \param angle 字幕旋转的角度
 *  \param anchor 字幕旋转的锚点
 *  \endif
 */
- (void)rotateCaption:(float)angle
               anchor:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Rotates caption around center of the bounding
 *  \param angle Angle of rotation, in degree
 *  \param boundingType Bounding type to calculate center point. Please refer to [Bounding Type] (@ref NvsBoundingType)
 *  \else
 *  \brief 绕字幕边框中心旋转
 *  \param angle 字幕旋转的角度
 *  \param boundingType 用于计算中心点的边框类型。请参见[边框类型] (@ref NvsBoundingType)
 *  \endif
 */
- (void)rotateCaptionAroundCenter:(float)angle
                     boundingType:(NvsBoundingType)boundingType;

/*! \if ENGLISH
 *  \brief Gets the transformed vertices position of the original caption bounding
 *  \param captionIndex Caption index to get vertices positions
 *  \param boundingType Bounding type. Please refer to [Bounding Type] (@ref NvsBoundingType)
 *  \return Returns the NSArray object, the object type is NSValue, and the actual data type is CGPoint, which correspond to the top left, bottom left, bottom right, and top right vertices of the original bounding.
 *  \else
 *  \brief 获取字幕原始边框变换后的顶点位置
 *  \param captionIndex 要获取顶点位置的字幕索引号
 *  \param boundingType 边框类型。请参见[边框类型] (@ref NvsBoundingType)
 *  \return 返回NSArray对象，里面的对象类型为NSValue，而实际包含的数据类型为CGPoint，包含四个顶点位置，依次分别对应原始边框的左上，左下，右下，右上顶点
 *  \endif
 */
- (NSArray *)getCaptionBoundingVertices:(NSInteger)captionIndex
                           boundingType:(NvsBoundingType)boundingType;

/*! \if ENGLISH
 *  \brief Gets the transformed vertices position of the original compound caption bounding
 *  \param boundingType Bounding type. Please refer to [Bounding Type] (@ref NvsBoundingType)
 *  \return Returns the NSArray object, the object type is NSValue, and the actual data type is CGPoint, which correspond to the top left, bottom left, bottom right, and top right vertices of the original bounding.
 *  \else
 *  \brief 获取复合字幕原始边框变换后的顶点位置
 *  \param boundingType 边框类型。请参见[边框类型] (@ref NvsBoundingType)
 *  \return 返回NSArray对象，里面的对象类型为NSValue，而实际包含的数据类型为CGPoint，包含四个顶点位置，依次分别对应原始边框的左上，左下，右下，右上顶点
 *  \endif
 */
- (NSArray *)getCompoundBoundingVertices:(NvsBoundingType)boundingType;

/*! \if ENGLISH
 *  \brief Sets caption Z value.
 *  \param value Z value
 *  \else
 *  \brief 设置字幕Z值
 *  \param value z值
 *  \endif
 */
- (void)setZValue:(float)value;

/*! \if ENGLISH
 *  \brief Gets caption Z value.
 *  \return Returns caption Z value.
 *  \else
 *  \brief 获取字幕Z值
 *  \return 返回字幕Z值
 *  \endif
 */
- (float)getZValue;

@end
