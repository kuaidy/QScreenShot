#ifndef WORDPRESSAPI_H
#define WORDPRESSAPI_H
#include <QString>
#include <QSettings>
#include <QJsonObject>
#include <QFile>
#include "HttpHelper.h"

class WordpressApi
{
public:
    WordpressApi();
    QString GetToken();
    bool UploadFile(QByteArray data,QString fileName);
    QString m_userName;
    QString m_password;
    QString m_tokenUrl;
    QString m_mediaUrl;
    QString m_token;
};

#endif // WORDPRESSAPI_H
