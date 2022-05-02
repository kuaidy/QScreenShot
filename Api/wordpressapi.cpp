#include "wordpressapi.h"

WordpressApi::WordpressApi()
{
    QSettings settingsread("setting.ini",QSettings::IniFormat);
    m_userName = settingsread.value("upload/userName").toString();
    m_password = settingsread.value("upload/password").toString();
    m_tokenUrl = settingsread.value("upload/tokenUrl").toString();
    m_mediaUrl = settingsread.value("upload/mediaUrl").toString();
}
QString WordpressApi::GetToken(){
    QJsonObject jsonData;
    jsonData.insert("username",m_userName);
    jsonData.insert("password",m_password);
    jsonData.insert("email","");
    QString userTokenInfo=HttpHelper::Post(m_tokenUrl,jsonData);
    QJsonDocument doc = QJsonDocument::fromJson(userTokenInfo.toUtf8());
    QJsonObject  jsonUserTokenInfo= doc.object();
    m_token=jsonUserTokenInfo["token"].toString();
    return m_token;
}
bool WordpressApi::UploadFile(QByteArray data,QString fileName){
    return HttpHelper::Post(m_mediaUrl,data,m_token,fileName);
}
