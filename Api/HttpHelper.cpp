#include "HttpHelper.h"

HttpHelper::HttpHelper()
{

}

QString HttpHelper::Get(QString url){
    QNetworkRequest request;
    QNetworkAccessManager* manager=new QNetworkAccessManager();
    //指定url
    request.setUrl(QUrl(url));
    //设置header
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    QNetworkReply* reply = manager->get(request);
    QEventLoop eventLoop;
    connect(manager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();
    //返回结果
    QByteArray responseData;
    responseData = reply->readAll();
    QString strResponse = QString::fromUtf8(responseData);
    return strResponse;
}

QString HttpHelper::Post(QString url,QJsonObject obj)
{
    QNetworkRequest request;
    QNetworkAccessManager* manager=new QNetworkAccessManager();
    //指定url
    request.setUrl(QUrl(url));
    //设置header
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    //发送的数据
    QByteArray postData;
    postData.append(QJsonDocument(obj).toJson());
    QNetworkReply* reply = manager->post(request,postData);
    QEventLoop eventLoop;
    connect(manager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();
    //返回结果
    QByteArray responseData;
    responseData = reply->readAll();
    QString strResponse = QString::fromUtf8(responseData);
    return strResponse;
}
QString HttpHelper::Post(QString url,QUrlQuery params)
{
    QNetworkRequest request;
    QNetworkAccessManager* manager=new QNetworkAccessManager();
    //指定url
    request.setUrl(QUrl(url));
    //设置header
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    //发送的数据
    QNetworkReply* reply = manager->post(request,params.query().toUtf8());
    QEventLoop eventLoop;
    connect(manager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();
    //返回结果
    QByteArray responseData;
    responseData = reply->readAll();
    QString strResponse = QString::fromUtf8(responseData);
    return strResponse;
}
QString HttpHelper::Post(QString url,QJsonObject jsonData,QString token){
    QNetworkRequest request;
    QNetworkAccessManager* manager=new QNetworkAccessManager();
    //指定url
    request.setUrl(QUrl(url));
    //设置header
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setRawHeader("Authorization",("Bearer "+token).toUtf8());
    //发送的数据
    QByteArray postData;
    postData.append(QJsonDocument(jsonData).toJson());
    QNetworkReply* reply = manager->post(request,postData);
    QEventLoop eventLoop;
    connect(manager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();
    //返回结果
    QByteArray responseData;
    responseData = reply->readAll();
    QString strResponse = QString::fromUtf8(responseData);
    return strResponse;
}
bool HttpHelper::Post(QString url,QByteArray data,QString token,QString fileName){
    try{
        QUrl reqUrl(url);
        QNetworkRequest request(reqUrl);
        request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("multipart/form-data"));
        request.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("attachment; filename="+fileName));
        request.setRawHeader("Authorization",("Bearer "+token).toUtf8());
        QNetworkAccessManager *manager=new QNetworkAccessManager();
        QNetworkReply *reply=manager->post(request,data);
        QEventLoop eventLoop;
        connect(manager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
        eventLoop.exec();
        QByteArray responseData = reply->readAll();
        QJsonObject strResponse=QJsonDocument::fromJson(responseData).object();
        if(strResponse.value("id").toInt()>0){
            return true;
        }else{
            return false;
        }
    }catch(_exception){
        return false;
    }
}
