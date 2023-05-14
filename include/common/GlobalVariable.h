#ifndef USERTOKENINFO_H
#define USERTOKENINFO_H
enum OptionTypeEnum{
    PaintRect,
    PaintArrow,
    PaintFreedom,
    PaintLine,
    Vague,
    ActionCrop,
    None
};
extern OptionTypeEnum OptionFlag;
//缩放比列
extern float Scale;

#endif
