
#ifndef GLOBALSETTING_H
#define GLOBALSETTING_H

class GlobalSetting
{
public:
    GlobalSetting();

public:
    //图片压缩等级
    int _imageCompressLevel;
};
extern GlobalSetting _globalSetting;
#endif // GLOBALSETTING_H
