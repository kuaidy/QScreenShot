#include "wordpressapi.h"

WordpressApi::WordpressApi()
{

}
QString WordpressApi::GetToken(){
    QSettings settingsread("setting.ini",QSettings::IniFormat);
    QString userName = settingsread.value("upload/userName").toString();
    QString password = settingsread.value("upload/password").toString();
    QString tokenUrl = settingsread.value("upload/tokenUrl").toString();
    QString mediaUrl = settingsread.value("upload/mediaUrl").toString();
    QJsonObject jsonData;
    jsonData.insert("username",userName);
    jsonData.insert("password",password);
    jsonData.insert("email","");
    QString userTokenInfo=HttpHelper::Post(tokenUrl,jsonData);
    return userTokenInfo;
}
