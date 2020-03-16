//================================================================================
//
// (c) Copyright China Digital Video (Beijing) Limited, 2017. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
//--------------------------------------------------------------------------------
//   Birth Date:    Feb 16. 2017
//   Author:        NewAuto video team
//================================================================================
#pragma once

#import "NvsFx.h"
#import "NvsTimelineCompoundCaption.h"
#import <CoreGraphics/CGGeometry.h>

/*! \if ENGLISH
 *  \brief Timeline captions
 *
 *  Timeline captions are the custom text that is superimposed on the video. When editing a video, users can add and remove the timeline captions and adjust the caption position. After adding subtitles, user can also set the style, including font size, color, shadow, stroke, etc.
 *  \warning In the NvsTimelineCaption class, all public APIs are used in the UI thread! ! !
 *  \else
 *  \brief 时间线字幕
 *
 *  时间线字幕是视频上叠加的自定义文字。编辑视频时，可以添加和移除时间线字幕，并对字幕位置进行调整处理。添加完字幕，还可以进行样式设置，包括字体大小，颜色，阴影，描边等。
 *  \warning NvsTimelineCaption类中，所有public API都在UI线程使用！！！
 *  \endif
*/
NVS_EXPORT @interface NvsTimelineCaption : NvsFx

@property (readonly) BOOL isPanoramic;                //!< \if ENGLISH Whether it is a panorama caption \else 是否为全景图字幕 \endif \since 1.6.0
@property (nonatomic) BOOL clipAffinityEnabled;       //!< \if ENGLISH Whether to enable the affinity with clip \else 是否开启与clip的亲和关系 \endif \since 1.7.1
@property (readonly) int64_t inPoint;                 //!< \if ENGLISH The in point of the caption on the timeline(in microseconds) \else 字幕在时间线上显示的入点（单位微秒） \endif
@property (readonly) int64_t outPoint;                //!< \if ENGLISH The out point of the caption on the timeline (in microseconds) \else 字幕在时间线显示上的出点（单位微秒） \endif
@property (readonly) NvsRoleInTheme roleInTheme;      //!< \if ENGLISH The role of captions in the theme (general, title, and trailer.) \else 字幕在主题中的角色(通用、片头、片尾) \endif
@property (readonly) NvsCategory category;            //!< \if ENGLISH Clip type \else 片段类型 \endif
@property (readonly) NSString* captionStylePackageId; //!< \if ENGLISH The package ID of the caption style\else 字幕样式包裹ID \endif

/*! \if ENGLISH
 *  \brief Changes the out point of the caption on the timeline.
 *  \param newInPoint The new out point of the caption on the timeline (in microseconds)
 *  \return Returns the in point of the caption which displayed on the timeline (in microseconds).
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变字幕在时间线上显示的入点
 *  \param newInPoint 字幕在时间线上的新的入点（单位微秒）
 *  \return 返回字幕在时间线上的显示的入点值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeOutPoint:
 *  \sa movePosition:
*/
- (int64_t)changeInPoint:(int64_t)newInPoint;

/*! \if ENGLISH
 *  \brief Changes the out point of the caption on the timeline.
 *  \param newOutPoint The new out point of the caption on the timeline (in microseconds)
 *  \return Returns the out point of the caption which displayed on the timeline (in microseconds).
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变字幕在时间线上显示的出点
 *  \param newOutPoint 字幕在时间线上的新的出点（单位微秒）
 *  \return 返回字幕在时间线上显示的出点值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeInPoint:
 *  \sa movePosition:
*/
- (int64_t)changeOutPoint:(int64_t)newOutPoint;

/*! \if ENGLISH
 *  \brief Changes the display position of the caption on the timeline (the in and out points move the value of "offset" at the same time).
 *  \param offset The offset value (in microseconds)
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 改变字幕在时间线上的显示位置(入点和出点同时偏移offset值)
 *  \param offset 偏移值（单位微秒）
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
 *  \sa changeInPoint:
 *  \sa changeOutPoint:
*/
- (void)movePosition:(int64_t)offset;

/*! \if ENGLISH
 *  \brief Apply the caption style.
 *  \param captionStylePackageId The resource package ID of the caption style
 *  \return Returns bool value. True means it use caption style successfully, and false means it fails.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 运用字幕样式
 *  \param captionStylePackageId 字幕样式资源包ID
 *  \return 返回bool值。true表示成功运用字幕样式，false则运用失败
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
*/
-(bool) applyCaptionStyle:(NSString*) captionStylePackageId;

/*! \if ENGLISH
 *  \brief apply the caption style.
 *  \param captionStylePackageId The resource package ID of the caption style
 *  \param isUseDefaultAssetParam Whether to use the default material parameters.
 *  \return Returns bool value. True means it use caption style successfully, and false means it fails.
 *  \warning This interface will cause the streaming engine state to jump to the state of stopping engine. For details, please refer to [The Topic of Changing Engine](\ref EngineChange.md).
 *  \else
 *  \brief 运用字幕样式
 *  \param captionStylePackageId 字幕样式资源包ID
 *  \param isUseDefaultAssetParam 是否使用默认素材参数
 *  \return 返回bool值。true表示成功运用字幕样式，false则运用失败
 *  \warning 此接口会引发流媒体引擎状态跳转到引擎停止状态，具体情况请参见[引擎变化专题] (\ref EngineChange.md)。
 *  \endif
*/
-(bool) applyCaptionStyleWithAssetDefaultParam:(NSString*) captionStylePackageId isUseDefaultAssetParam:(NvsAssetDefaultParam)isUseDefaultAssetParam;

/*! \if ENGLISH
 *  \brief Set the caption text.
 *  \param text The caption text
 *  \else
 *  \brief 设置字幕文本
 *  \param text 字幕文本
 *  \endif
 *  \sa getText
*/
- (void)setText:(NSString *)text;

/*! \if ENGLISH
 *  \brief Gets the caption text.
 *  \return Returns the obtained caption text.
 *  \else
 *  \brief 获取字幕文本
 *  \return 返回获取的字幕文本
 *  \endif
 *  \sa setText:
*/
- (NSString *)getText;

/*! \if ENGLISH
 *  \brief Sets the caption alignment method.
 *  \param textAlign the caption alignment method
 *  \else
 *  \brief 设置字幕对齐方式
 *  \param textAlign 字幕对齐方式
 *  \endif
 *  \sa getTextAlignment
*/
- (void)setTextAlignment:(NvsTextAlignment)textAlign;

/*! \if ENGLISH
 *  \brief Gets the caption alignment method.
 *  \return Returns the caption alignment method.
 *  \else
 *  \brief 获取字幕对齐方式
 *  \return 返回字幕对齐方式
 *  \endif
 *  \sa setTextAlignment:
*/
- (NvsTextAlignment)getTextAlignment;

/*! \if ENGLISH
 *  \brief Sets whether the caption font is bold.
 *  \param bold Indicates whether the caption font is bold.YES means it is bold, NO means it is not.
 *  \else
 *  \brief 设置字幕字体是否加粗
 *  \param bold 表示字幕字体是否加粗，YES表示加粗，NO则不加粗。
 *  \endif
 *  \sa getBold
*/
- (void)setBold:(BOOL)bold;

/*! \if ENGLISH
 *  \brief Gets the state whether the caption font is bold.
 *  \return Returns the state whether the caption font is bold. YES means it is bold, NO means it is not.
 *  \else
 *  \brief 获取字幕字体加粗状态
 *  \return 返回字幕字体加粗状态，YES表示字体已加粗，NO则字体未加粗。
 *  \endif
 *  \sa setBold:
*/
- (BOOL)getBold;

/*! \if ENGLISH
 *  \brief Sets caption weight.
 *  \param weight the value in opentype weight integer.
 *  \else
 *  \brief 设置字幕权重
 *  \param weight opentype中的权重值
 *  \endif
 *  \sa getWeight
 */
- (void)setWeight:(int)weight;

/*! \if ENGLISH
 *  \brief Gets the caption weight.
 *  \return Returns the caption weight.
 *  \else
 *  \brief 获取字幕权重值
 *  \return 字幕权重值
 *  \endif
 *  \sa setWeight
 */
- (int)getWeight;

/*! \if ENGLISH
 *  \brief Sets whether the caption font is italic.
 *  \param italic Whether it is italic. YES means the caption font is italic, and NO means it is not.
 *  \else
 *  \brief 设置字幕字体是否是斜体
 *  \param italic 是否是斜体。YES表示设置字幕字体为斜体，NO则不设为斜体
 *  \endif
 *  \sa getItalic
*/
- (void)setItalic:(BOOL)italic;

/*! \if ENGLISH
 *  \brief Gets the state whether the caption font is italic.
 *  \return Returns boolean value. YES means the caption font is italic. NO means it is not.
 *  \else
 *  \brief 获取字幕斜体状态
 *  \return 返回BOOL值，YES表示是斜体字体，NO则不是斜体
 *  \endif
 *  \sa setItalic:
*/
- (BOOL)getItalic;

/*! \if ENGLISH
 *  \brief Sets caption word spacing.
 *  \param letterSpacing Word spacing is expressed in percentage value. 100 is the original default word spacing value.
 *  \else
 *  \brief 设置字幕字间距
 *  \param letterSpacing 字间距，百分比值，100为原始默认字间距
 *  \endif
 *  \sa setLetterSpacing:
 *  \since 2.13.0
 */
- (float)getLetterSpacing;

/*! \if ENGLISH
 *  \brief Gets caption word spacing.
 *  \return Returns the float value, the percentage value. 100 is the original default word spacing.
 *  \else
 *  \brief 获取字幕字间距
 *  \return 返回float值，百分比值，100为原始默认字间距
 *  \endif
 *  \sa getLetterSpacing
 *  \since 2.13.0
 */
- (void)setLetterSpacing:(float)letterSpacing;

/*! \if ENGLISH
 *  \brief Sets the color of the caption text.
 *  \param textColor the color of the caption text
 *  \else
 *  \brief 设置字幕文本颜色
 *  \param textColor 字幕文本颜色值
 *  \endif
 *  \sa getTextColor
*/
- (void)setTextColor:(const NvsColor *)textColor;

/*! \if ENGLISH
 *  \brief Gets the current color value of the caption font.
 *  \return Returns the NvsColor object representing the obtained color value.
 *  \else
 *  \brief 获取字幕字体的当前颜色值
 *  \return 返回NvsColor对象，表示获得的颜色值
 *  \endif
 *  \sa setTextColor:
*/
- (NvsColor)getTextColor;

/*! \if ENGLISH
 *  \brief Sets whether the caption draws the outline.
 *  \param drawOutline whether the caption draws the outline。YES means it draws the outline. NO means it does not.
 *  \else
 *  \brief 设置字幕是否描边
 *  \param drawOutline 是否对字幕描边。YES表示对字幕进行描边，NO则不描边
 *  \endif
 *  \sa getDrawOutline
*/
- (void)setDrawOutline:(BOOL)drawOutline;

/*! \if ENGLISH
 *  \brief Gets the status whether the caption draws the outline.
 *  \return  Returns boolean value. YES means it has drawed the outline. NO means it has not.
 *  \else
 *  \brief 获取字幕描边状态
 *  \return 返回BOOL值，YES表示已描边，NO则未描边
 *  \endif
 *  \sa setDrawOutline:
*/
- (BOOL)getDrawOutline;

/*! \if ENGLISH
 *  \brief Sets the color of the outline for the caption.
 *  \param outlineColor the color of the outline
 *  \else
 *  \brief 设置字幕描边的颜色
 *  \param outlineColor 描边颜色值
 *  \endif
 *  \sa getOutlineColor
*/
- (void)setOutlineColor:(const NvsColor *)outlineColor;

/*! \if ENGLISH
 *  \brief Gets the color of the outline for the caption.
 *  \return  Returns the NvsColor object representing the color of the outline for the caption.
 *  \else
 *  \brief 获取当前字幕描边的颜色值
 *  \return 返回NvsColor对象，表示获得的字幕描边的颜色
 *  \endif
 *  \sa setOutlineColor:
*/
- (NvsColor)getOutlineColor;

/*! \if ENGLISH
 *  \brief Sets the width of the outline for the caption.
 *  \param outlineWidth the width of the outline
 *  \else
 *  \brief 设置字幕描边的宽度
 *  \param outlineWidth 描边宽度
 *  \endif
 *  \sa getOutlineWidth
*/
- (void)setOutlineWidth:(float)outlineWidth;

/*! \if ENGLISH
 *  \brief Gets the width of the outline for the caption.
 *  \return Returns the width of the outline for the caption.
 *  \else
 *  \brief 获取当前字幕描边的宽度
 *  \return 返回获得的字幕描边的宽度值
 *  \endif
 *  \sa setOutlineWidth:
*/
- (float)getOutlineWidth;

/*! \if ENGLISH
 *  \brief Sets the caption shadows.
 *  \param drawShadow Whether to set the caption shadow. YES means to set the caption shadow. NO means not.
 *  \else
 *  \brief 设置字幕阴影
 *  \param drawShadow 是否设置字幕阴影。YES表示设置字幕阴影，NO则不设置
 *  \endif
 *  \sa getDrawShadow
*/
- (void)setDrawShadow:(BOOL)drawShadow;

/*! \if ENGLISH
 *  \brief Gets the state of the current caption shadow.
 *  \return Returns BOOL value. YES means the caption has shadow. NO means it is not.
 *  \else
 *  \brief 获取当前字幕阴影状态
 *  \return 返回BOOL值，YES表示有字幕阴影，NO则没有字幕阴影
 *  \endif
 *  \sa setDrawShadow:
*/
- (BOOL)getDrawShadow;

/*! \if ENGLISH
 *  \brief Sets the color of the caption shadow.
 *  \param shadowColor The color of the caption shadow
 *  \else
 *  \brief 设置字幕阴影的颜色
 *  \param shadowColor 字幕阴影颜色值
 *  \endif
 *  \sa getShadowColor
*/
- (void)setShadowColor:(const NvsColor *)shadowColor;

/*! \if ENGLISH
 *  \brief Gets the color of the caption shadow.
 *  \return Returns the NvsColor object representing the caption shadow color which obtained.
 *  \else
 *  \brief 获取当前字幕阴影的颜色
 *  \return 返回NvsColor对象，表示获得的字幕阴影颜色值
 *  \endif
 *  \sa setShadowColor:
*/
- (NvsColor)getShadowColor;

/*! \if ENGLISH
 *  \brief Sets the offset of the caption shadow.
 *  \param shadowOffset The offset of the caption shadow.
 *  \else
 *  \brief 设置字幕阴影的偏移量
 *  \param shadowOffset 字幕阴影的偏移量
 *  \endif
 *  \sa getShadowOffset
*/
- (void)setShadowOffset:(CGPoint)shadowOffset;

/*! \if ENGLISH
 *  \brief Gets the offset of the caption shadow.
 *  \return Returns CGPoint object representing the caption shadow offset which obtained.
 *  \else
 *  \brief 获取当前字幕阴影的偏移量
 *  \return 返回CGPoint对象，表示获得的字幕阴影偏移量
 *  \endif
 *  \sa setShadowOffset:
*/
- (CGPoint)getShadowOffset;

/*! \if ENGLISH
 *  \brief Sets the feathering degree of the caption shadow.
 *  \param feather feathering degree
 *  \else
 *  \brief 设置字幕阴影的羽化程度
 *  \param feather 羽化程度
 *  \endif
 *  \sa getShadowFeather
*/
- (void)setShadowFeather:(float)feather;

/*! \if ENGLISH
 *  \brief Gets the feathering degree of the caption shadow
 *  \return Returns feathering degree
 *  \else
 *  \brief 获取当前字幕阴影的羽化程度
 *  \return 返回羽化程度
 *  \endif
 *  \sa setShadowFeather
*/
- (float)getShadowFeather;

/*! \if ENGLISH
 *  \brief Sets the font size of the caption.
 *  \param fontSize the font size of the caption
 *  \else
 *  \brief 设置字幕字体大小
 *  \param fontSize 字幕字体大小值
 *  \endif
 *  \sa getFontSize
*/
- (void)setFontSize:(float)fontSize;

/*! \if ENGLISH
 *  \brief Gets the font size of the caption.
 *  \return Returns the font size of the caption.
 *  \else
 *  \brief 获取当前字幕的字体大小
 *  \return 返回获得的字幕字体大小值
 *  \endif
 *  \sa setFontSize:
*/
- (float)getFontSize;

/*! \if ENGLISH
 *  \brief Sets the caption font.
 *  \param filePath The file path of the caption font. If it's a null string,it's set as the default font.
 *  \else
 *  \brief 设置字幕字体
 *  \param filePath 字幕字体文件路径，若设为空字符串，则设为默认字体
 *  \endif
 *  \since 1.3.0
 *  \sa getFontFilePath
*/
- (void)setFontWithFilePath:(NSString *)filePath;

/*! \if ENGLISH
 *  \brief Gets the file path of the caption font.
 *  \return Returns the file path of the caption font.
 *  \else
 *  \brief 获取字幕字体的文件路径
 *  \return 返回字幕字体的文件路径
 *  \endif
 *  \since 1.3.0
 *  \sa setFontWithFilePath:
*/
- (NSString *)getFontFilePath;

/*! \if ENGLISH
 *  \brief Gets the caption font.
 *  \else
 *  \brief 获取字幕字体
 *  \endif
 *  \since 2.13.3
 *  \sa setFontFamily
*/
- (NSString *)getFontFamily;

/*! \if ENGLISH
 *  \brief Sets the caption font.
 *  \param family The font family. if it's a null string, it's set as the default font.
 *  \else
 *  \brief 设置字幕字体
 *  \param family 字体名字，若设为空字符串，则设为默认字体
 *  \endif
 *  \since 2.4.2
 *  \sa getFontFamily
*/
- (void)setFontFamily:(NSString *)family;

/*! \if ENGLISH
 *  \brief Sets the translation amount of the caption.
 *  \param translation The horizontal and vertical absolute translation of the caption.
 *  \else
 *  \brief 设置字幕的平移量
 *  \param translation 字幕平移的水平和垂直的绝对平移值
 *  \endif
 *  \sa getCaptionTranslation
 *  \sa translateCaption:
*/
- (void)setCaptionTranslation:(CGPoint)translation;

/*! \if ENGLISH
 *  \brief Gets the translation amount of the caption.
 *  \return Returns the CGPoint object indicating the translation amount of the caption which obtained.
 *  \else
 *  \brief 获取字幕的平移量
 *  \return 返回CGPoint对象，表示获得的字幕平移量
 *  \endif
 *  \sa setCaptionTranslation:
*/
- (CGPoint)getCaptionTranslation;

/*! \if ENGLISH
 *  \brief translates the caption.
 *  \param translationOffset The horizontal and vertical offset values for the caption translation
 *  \else
 *  \brief 平移字幕
 *  \param translationOffset 字幕平移的水平和垂直的偏移值
 *  \endif
 *  \since 1.7.0
 *  \sa setCaptionTranslation:
 *  \sa getCaptionTranslation
*/
- (void)translateCaption:(CGPoint)translationOffset;

/*! \if ENGLISH
 *  \brief Sets the caption anchor.
 *  \param anchor Anchor
 *  \else
 *  \brief 设置字幕锚点
 *  \param anchor 锚点
 *  \endif
 *  \since 1.15.0
 *  \sa getAnchorPoint
*/
- (void)setAnchorPoint:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Gets the caption anchor.
 *  \return Returns the caption anchor.
 *  \else
 *  \brief 获取字幕锚点
 *  \return 返回字幕锚点
 *  \endif
 *  \since 1.15.0
 *  \sa setAnchorPoint:
*/
- (CGPoint)getAnchorPoint;

/*! \if ENGLISH
 *  \brief Sets the horizontal scaling factor for the caption.
 *  \param scale The horizontal scaling factor
 *  \else
 *  \brief 对字幕设置水平缩放系数
 *  \param scale 水平缩放系数
 *  \endif
 *  \since 1.14.1
 *  \sa getScaleX
 *  \sa setScaleY:
*/
- (void)setScaleX:(float)scale;

/*! \if ENGLISH
 *  \brief Gets the horizontal scaling factor for the caption.
 *  \return Returns the horizontal scaling factor for the caption.
 *  \else
 *  \brief 获取字幕水平缩放系数
 *  \return 返回字幕水平缩放系数
 *  \endif
 *  \since 1.14.1
 *  \sa setScaleX:
 *  \sa getScaleY
*/
- (float)getScaleX;

/*! \if ENGLISH
 *  \brief Sets the vertical scaling factor for the caption.
 *  \param scale the vertical scaling factor
 *  \else
 *  \brief 对字幕设置垂直缩放系数
 *  \param scale 垂直缩放系数
 *  \endif
 *  \since 1.14.1
 *  \sa getScaleY
 *  \sa setScaleX:
*/
- (void)setScaleY:(float)scale;

/*! \if ENGLISH
 *  \brief Gets the vertical scaling factor for the caption.
 *  \return Returns the vertical scaling factor for the caption.
 *  \else
 *  \brief 获取字幕垂直缩放系数
 *  \return 返回字幕垂直缩放系数
 *  \endif
 *  \since 1.14.1
 *  \sa setScaleY:
 *  \sa getScaleX
*/
- (float)getScaleY;

/*! \if ENGLISH
 *  \brief Scales the caption.
 *  \param scaleFactor The scaling factor for the caption
 *  \param anchor The anchor for Scaling the caption
 *  \else
 *  \brief 缩放字幕
 *  \param scaleFactor 字幕缩放的因子
 *  \param anchor 字幕缩放的锚点
 *  \endif
 *  \since 1.8.1
*/
- (void)scaleCaption:(float)scaleFactor anchor:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Sets the rotation angle for the caption.
 *  \param angle The rotation angle
 *  \else
 *  \brief 对字幕设置旋转角度
 *  \param angle 旋转角度
 *  \endif
 *  \since 1.14.1
 *  \sa getRotationZ
*/
- (void)setRotationZ:(float)angle;

/*! \if ENGLISH
 *  \brief Gets the rotation angle for the caption.
 *  \return Returns the rotation angle for the caption.
 *  \else
 *  \brief 获取字幕旋转角度
 *  \return 返回字幕旋转角度
 *  \endif
 *  \since 1.14.1
 *  \sa setRotationZ:
*/
- (float)getRotationZ;

/*! \if ENGLISH
 *  \brief Rotates the caption.
 *  \param angle The rotation angle of the caption
 *  \param anchor The rotation anchor of the caption
 *  \else
 *  \brief 旋转字幕
 *  \param angle 字幕旋转的角度
 *  \param anchor 字幕旋转的锚点
 *  \endif
 *  \since 1.8.1
 *  \sa rotateCaption:
*/
- (void)rotateCaption:(float)angle anchor:(CGPoint)anchor;

/*! \if ENGLISH
 *  \brief Rotates the caption with the caption center point as the anchor point.
 *  \param angle The rotation angle of caption
 *  \else
 *  \brief 以字幕中心点为锚点旋转字幕
 *  \param angle 字幕旋转的角度
 *  \endif
 *  \since 1.8.1
 *  \sa rotateCaption:anchor:
*/
- (void)rotateCaption:(float)angle;

/*! \if ENGLISH
 *  \brief Gets the rectangle of the caption text.
 *  \return Returns the NvsRect object representing the obtained rectangle.
 *  \else
 *  \brief 获取字幕文本矩形框
 *  \return 返回NvsRect对象，表示获得的字幕文本矩形框
 *  \endif
*/
- (NvsRect)getTextBoundingRect;

/*! \if ENGLISH
 *  \brief Gets the vertex position of the original enclosing rectangle of the caption after transformation.
 *  \return Returns the NSArray object, the object type is NSValue, and the actual data type is CGPoint, which contains four vertex positions corresponding to the upper left, lower left, lower right, and upper right vertex of the original enclosing rectangle.
 *  \else
 *  \brief 获取字幕的原始包围矩形框变换后的顶点位置
 *  \return 返回NSArray对象，里面的对象类型为NSValue，而实际包含的数据类型为CGPoint，包含四个顶点位置，依次分别对应原始包围矩形框的左上，左下，右下，右上顶点
 *  \endif
 *  \since 1.8.1
*/
- (NSArray *)getBoundingRectangleVertices;

/*! \if ENGLISH
 *  \brief Gets the transformed vertices position of the original caption bounding
 *  \param boundingType Bounding type. Please refer to [Bounding Type] (@ref NvsBoundingType)
 *  \return Returns the NSArray object, the object type is NSValue, and the actual data type is CGPoint, which correspond to the top left, bottom left, bottom right, and top right vertices of the original bounding.
 *  \else
 *  \brief 获取字幕原始边框变换后的顶点位置
 *  \param boundingType 边框类型。请参见[边框类型] [Bounding Type] (@ref NvsBoundingType)
 *  \return 返回NSArray对象，里面的对象类型为NSValue，而实际包含的数据类型为CGPoint，包含四个顶点位置，依次分别对应原始边框的左上，左下，右下，右上顶点
 *  \endif
 *  \since 2.9.0
 */
- (NSArray *)getCaptionBoundingVertices:(NvsBoundingType)boundingType;

/*! \if ENGLISH
 *  \brief Sets the polar angle of the center point for the caption. It's only valid for the panorama caption.
 *  \param centerPolarAngle The polar angle of the center point (in degrees).
 *  \else
 *  \brief 对字幕设置中心点的极角。只对全景图字幕有效
 *  \param centerPolarAngle 中心点的极角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (void)setCenterPolarAngle:(float)centerPolarAngle;

/*! \if ENGLISH
 *  \brief Gets the polar angle of the center point for the caption. It's only valid for the panorama caption.
 *  \return Returns the polar angle of the center point (in degrees).
 *  \else
 *  \brief 获取字幕中心点的极角。只对全景图字幕有效
 *  \return 返回字幕中心点的极角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (float)getCenterPolarAngle;

/*! \if ENGLISH
 *  \brief Gets the polar angle of the center point for the caption text. It's only valid for the panorama caption.
 *  \return Returns the polar angle of the center point (in degrees) for the caption text.
 *  \else
 *  \brief 获取字幕文本中心点的极角。只对全景图字幕有效
 *  \return 返回字幕文本中心点的极角，单位为角度
 *  \endif
 *  \since 2.5.1
*/
- (float)getTextCenterPolarAngle;

/*! \if ENGLISH
 *  \brief Sets the azimuth angle of the center point for the caption. It's only valid for the panorama caption.
 *  \param centerAzimuthAngle the azimuth angle of the center point (in degrees)
 *  \else
 *  \brief 对字幕设置中心点的方位角。只对全景图字幕有效
 *  \param centerAzimuthAngle 中心点的方位角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (void)setCenterAzimuthAngle:(float)centerAzimuthAngle;

/*! \if ENGLISH
 *  \brief Gets the azimuth angle of the center point for the caption. It's only valid for the panorama caption.
 *  \return Returns the azimuth angle of the center point (in degrees).
 *  \else
 *  \brief 获取字幕中心点的方位角。只对全景图字幕有效
 *  \return 返回字幕中心点的方位角，单位为角度
 *  \endif
 *  \since 1.6.0
*/

- (float)getCenterAzimuthAngle;

/*! \if ENGLISH
 *  \brief Gets the azimuth angle of the center point for the caption text. It's only valid for the panorama caption.
 *  \return Returns the polar angle of the center point (in degrees).
 *  \else
 *  \brief 获取字幕文本中心点的方位角。只对全景图字幕有效
 *  \return 返回字幕文本中心点的方位角，单位为角度
 *  \endif
 *  \since 2.5.1
*/
- (float)getTextCenterAzimuthAngle;

/*! \if ENGLISH
 *  \brief Sets the ranging angle of the polar angle for the caption. It's only valid for the panorama caption.
 *  \param polarAngleRange the ranging angle of the polar angle (in degrees)
 *  \else
 *  \brief 对字幕设置极角的张角。只对全景图字幕有效
 *  \param polarAngleRange 极角的张角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (void)setPolarAngleRange:(float)polarAngleRange;

/*! \if ENGLISH
 *  \brief Gets the ranging angle of the polar angle for the caption. It's only valid for the panorama caption.
 *  \return Returns the ranging angle of the polar angle (in degrees).
 *  \else
 *  \brief 获取字幕极角的张角。只对全景图字幕有效
 *  \return 返回字幕极角的张角，单位为角度
 *  \endif
 *  \since 1.6.0
*/
- (float)getPolarAngleRange;

/*! \if ENGLISH
 *  \brief Gets the ranging angle of the polar angle for the caption text. It's only valid for the panorama caption.
 *  \return Returns the ranging angle of the polar angle for the caption text (in degrees).
 *  \else
 *  \brief 获取字幕文本极角的张角。只对全景图字幕有效
 *  \return 返回字幕文本极角的张角，单位为角度
 *  \endif
 *  \since 2.5.1
*/
- (float)getTextPolarAngleRange;

/*! \if ENGLISH
 *  \brief Gets the ranging angle which is perpendicular with the polar angle for the caption. It's only valid for the panorama caption.
 *  \return Returns the ranging angle which is perpendicular with the polar angle (in degrees).
 *  \else
 *  \brief 获取字幕与极角垂直的张角。只对全景图字幕有效
 *  \return 返回字幕与极角垂直的张角，单位为角度
 *  \endif
 *  \since 1.7.0
*/
- (float)getOrthoAngleRange;

/*! \if ENGLISH
 *  \brief Gets the ranging angle of  which is perpendicular with the polar angle for the caption text. It's only valid for the panorama caption.
 *  \return Returns the ranging angle of  which is perpendicular with the polar angle (in degrees).
 *  \else
 *  \brief 获取字幕文本与极角垂直的张角。只对全景图字幕有效
 *  \return 返回字幕文本与极角垂直的张角，单位为角度
 *  \endif
 *  \since 2.5.1
*/
- (float)getTextOrthoAngleRange;

/*! \if ENGLISH
 *  \brief Sets the horizontal scaling factor for the caption. It's only valid for the panorama caption.
 *  \param scaleX The horizontal scaling factor
 *  \else
 *  \brief 对字幕设置水平缩放系数。只对全景图字幕有效
 *  \param scaleX 水平缩放系数
 *  \endif
 *  \since 1.6.0
*/
- (void)setPanoramicScaleX:(float)scaleX;

/*! \if ENGLISH
 *  \brief Gets the horizontal scaling factor for the caption. It's only valid for the panorama caption.
 *  \return Returns the horizontal scaling factor.
 *  \else
 *  \brief 获取字幕水平缩放系数。只对全景图字幕有效
 *  \return 返回字幕水平缩放系数
 *  \endif
 *  \since 1.6.0
*/
- (float)getPanoramicScaleX;

/*! \if ENGLISH
 *  \brief Sets the vertical scaling factor for the caption. It's only valid for the panorama caption.
 *  \param scaleY The vertical scaling factor
 *  \else
 *  \brief 对字幕设置垂直缩放系数。只对全景图字幕有效
 *  \param scaleY 垂直缩放系数
 *  \endif
 *  \since 1.6.0
*/
- (void)setPanoramicScaleY:(float)scaleY;

/*! \if ENGLISH
 *  \brief Gets the vertical scaling factor for the caption. It's only valid for the panorama caption.
 *  \return Returns the vertical scaling factor.
 *  \else
 *  \brief 获取字幕垂直缩放系数。只对全景图字幕有效
 *  \return 返回字幕垂直缩放系数
 *  \endif
 *  \since 1.6.0
*/
- (float)getPanoramicScaleY;

/*! \if ENGLISH
 *  \brief Sets the rotation angle for the caption. It's only valid for the panorama caption.
 *  \param rotationAngle The rotation angle
 *  \else
 *  \brief 对字幕设置旋转角度。只对全景图字幕有效
 *  \param rotationAngle 旋转角度
 *  \endif
 *  \since 1.7.1
*/
- (void)setPanoramicRotation:(float)rotationAngle;

/*! \if ENGLISH
 *  \brief Gets the rotation angle for the caption. It's only valid for the panorama caption.
 *  \return Returns the rotation angle of the caption.
 *  \else
 *  \brief 获取字幕旋转角度。只对全景图字幕有效
 *  \return 返回字幕旋转角度
 *  \endif
 *  \since 01.7.1
*/
- (float)getPanoramicRotation;

/*! \if ENGLISH
 *  \brief Sets the Z value of the caption.
 *  \param value The Z value
 *  \else
 *  \brief 设置字幕Z值
 *  \param value 字幕Z值
 *  \endif
 *  \sa getZValue
*/
- (void)setZValue:(float)value;

/*! \if ENGLISH
 *  \brief Gets the Z value of the caption.
 *  \return Returns the Z value of the caption.
 *  \else
 *  \brief 获取字幕Z值。
 *  \return 返回字幕Z值。
 *  \endif
 *  \sa setZValue:
*/
- (float)getZValue;

/*! \if ENGLISH
 *  \brief Sets whether to record user actions.
 *  \param recordingUserOperation
 *  \else
 *  \brief 设置字幕是否记录用户的操作
 *  \param recordingUserOperation 字幕是否记录用户操作
 *  \endif
 *  \since 02.11.0
*/
- (void)setRecordingUserOperation:(BOOL)recordingUserOperation;

@end

