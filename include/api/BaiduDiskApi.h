#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QEventLoop>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QTabWidget>
#include <QCoreApplication>
#include <QWebEngineFindTextResult>
#include <QWebEnginePage>
#include <QFile>
#include <QJsonDocument>
#include <QCryptographicHash>
#include <QJsonArray>
#include <QUrlQuery>

#include "HttpHelper.h"

class BaiduDiskApi:public QObject{
public:
    const QString TokenApi="https://openapi.baidu.com/oauth/2.0/token";
    const QString NoServerTokenApi="https://openapi.baidu.com/oauth/2.0/authorize?response_type=token&client_id=AVPyRVuMPRRehbMxROzsFmEXotMEmQ9x&redirect_uri=oob&display=popup";
    const QString PreCreateApi="https://pan.baidu.com/rest/2.0/xpan/file?method=precreate";
    const QString UploadApi="https://d.pcs.baidu.com/rest/2.0/pcs/superfile2";
    const QString CreateApi="https://pan.baidu.com/rest/2.0/xpan/file?method=create";
    QString GetToken();
    QString GetTokenByNoserver();
    QString GetTokenByFile();
    QString PreCreateFile(QString filePath,QString token);
    QString UploadFile(QString filePath,QString uploadPath,QString token,QString uploadid);
    QString CreateFile();
};
