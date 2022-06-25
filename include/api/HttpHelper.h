#ifndef HTTPHELP_H
#define HTTPHELP_H

#include <QString>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>
#include <QFile>
#include <QHttpMultiPart>
#include <QHttpPart>

class HttpHelper:public QObject
{
public:
    HttpHelper();
    static QString Get(QString url);
    static QString Get(QString url,QString token);
    static QString Post(QString url,QJsonObject jsonData);
    static QString Post(QString url,QJsonObject jsonData,QString token);
    static QString Post(QString url,QUrlQuery params);
    static bool Post(QString url,QByteArray data,QString token,QString fileName);
};

#endif // HTTPHELP_H
