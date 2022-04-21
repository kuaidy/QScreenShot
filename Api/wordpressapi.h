#ifndef WORDPRESSAPI_H
#define WORDPRESSAPI_H
#include <QString>
#include <QSettings>
#include <QJsonObject>

#include "HttpHelper.h"

class WordpressApi
{
public:
    WordpressApi();
    QString GetToken();
};

#endif // WORDPRESSAPI_H
