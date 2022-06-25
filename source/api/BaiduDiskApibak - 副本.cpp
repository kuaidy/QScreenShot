#include "BaiduDiskApi.h"

QString BaiduDiskApi::GetToken(){
    QNetworkRequest request;
    QNetworkAccessManager* manager=new QNetworkAccessManager();
    //指定url
    request.setUrl(QUrl(BaiduDiskApi::TokenApi));
    //设置header
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    //发送的数据
    QJsonObject obj;
    obj.insert("grant_type","client_credentials");
    obj.insert("client_id","AVPyRVuMPRRehbMxROzsFmEXotMEmQ9x");
    obj.insert("client_secret","kp2ouuZgqWNtNjxuLPEd9YdpOuDoM36f");
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
};
QString BaiduDiskApi::GetTokenByNoserver(){
    QString tokenStr=GetTokenByFile();
    if(tokenStr.isEmpty()){
        QWebEngineView *webView;
        webView = new QWebEngineView();
        webView->load(QUrl(BaiduDiskApi::NoServerTokenApi));
        webView->show();
        QEventLoop eventLoop;
        connect(webView, &QWebEngineView::urlChanged, this, [this,webView,&tokenStr,&eventLoop](const QUrl &url){
            QFile file("baidutoken.txt");
            file.open(QIODevice::ReadWrite|QIODevice::Text);
            file.write(url.toString().toUtf8());
            file.close();
            tokenStr=GetTokenByFile();
            if(!tokenStr.isEmpty()){
                eventLoop.exit();
                webView->close();
            }
        });
        eventLoop.exec();
    }
    return tokenStr;
}
QString BaiduDiskApi::GetTokenByFile(){
    QString tokenStr;
    QFile file("baidutoken.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray byteArr = file.readAll();
    QString str=QString(byteArr);
    if(str.contains("access_token",Qt::CaseSensitive)){
        QStringList listStr = str.split('&');
        QStringList tokenListStr=listStr[1].split('=');
        tokenStr=tokenListStr[1];
    }
    return tokenStr;
}
//预上传
QString BaiduDiskApi::PreCreateFile(QString filePath,QString token){
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return "";
    QString url=BaiduDiskApi::PreCreateApi+"&access_token="+token;
    QJsonObject obj;
    QString fileName=filePath.section("\\",-1,-1);
    int totalSize=file.size();
    int bytesToWrite=totalSize;
    int isDir=0;
    int autoInit=1;
    int loadSize=1024*4;
    QCryptographicHash ch(QCryptographicHash::Md5);
    QByteArray buf;
    while(true){
        if(bytesToWrite>0){
            buf=file.read(qMin(bytesToWrite,loadSize));
            ch.addData(buf);
            bytesToWrite-=buf.length();
            buf.resize(0);
        }else{
            break;
        }
    }
    file.close();
    QUrlQuery params;
    params.addQueryItem("path","/apps/截图管理/"+fileName);
    params.addQueryItem("size",QString::number(totalSize));
    params.addQueryItem("isdir",QString::number(isDir));
    params.addQueryItem("autoinit",QString::number(autoInit));
    params.addQueryItem("rtype","1");
    QJsonArray array;
    array.push_back("98d02a0f54781a93e354b1fc85caf488");
    params.addQueryItem("block_list",QJsonDocument(array).toJson());
    QString res=HttpHelper::Post(url,params);
    return res;
}
//分片上传
QString BaiduDiskApi::UploadFile(QString filePath,QString uploadPath,QString token,QString uploadid){
    QUrlQuery params;
    params.addQueryItem("method","upload");
    params.addQueryItem("access_token",token);
    params.addQueryItem("type","tmpfile");
    params.addQueryItem("path",uploadPath);
    params.addQueryItem("uploadid",uploadid);
    params.addQueryItem("partseq",0);
    return "";
}
