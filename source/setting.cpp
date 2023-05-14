#include "../include/setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
    this->settingRead();
}

Setting::~Setting()
{
    delete ui;
}

QSize CustomTabStyle::sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const
{
    QSize s=QProxyStyle::sizeFromContents(type,option,size,widget);
    if(type==QStyle::CT_TabBarTab){
        s.transposed();
        s.rwidth()=100;
        s.rheight()=50;
    }
    return s;
}
void CustomTabStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    if(element==CE_TabBarTabLabel){
        if(const QStyleOptionTab *tab=qstyleoption_cast<const QStyleOptionTab *>(option)){
            QRect allRect=tab->rect;
            if(tab->state&QStyle::State_Selected){
                painter->save();
                painter->setPen(0x1296db);
                painter->setBrush(QBrush(0x1296db));
                painter->drawRect(allRect.adjusted(5,5,-5,-5));
                painter->restore();
            }
            QTextOption option;
            option.setAlignment(Qt::AlignCenter);
            if(tab->state&QStyle::State_Selected){
                painter->setPen(0xf8fcff);
            }else{
                painter->setPen(0x000001);
            }
            painter->drawText(allRect,tab->text,option);
            return ;
        }
    }
    if(element==CE_TabBarTab){
        QProxyStyle::drawControl(element,option,painter,widget);
    }
}

void Setting::on_pushButton_clicked()
{
    QString userName=ui->userName->text();
    QString password=ui->password->text();
    QString tokenUrl=ui->tokenUrl->text();
    QString mediaUrl=ui->mediaUrl->text();
    QString imageCompressLevel=ui->imageCompressLevel->text();
    QSettings settings("setting.ini",QSettings::IniFormat);
    //基本设置
    settings.beginGroup("basic");
    settings.setValue("imageCompressLevel",imageCompressLevel);
    settings.endGroup();

    //图片上传设置
    settings.beginGroup("upload");
    settings.setValue("userName",userName);
    settings.setValue("password",password);
    settings.setValue("tokenUrl",tokenUrl);
    settings.setValue("mediaUrl",mediaUrl);
    settings.endGroup();
    QMessageBox::information(this,"提示","保存成功",QMessageBox::Ok);
}

void Setting::settingRead(){
    QSettings settingsread("setting.ini",QSettings::IniFormat);
    QString userName = settingsread.value("upload/userName").toString();
    QString password = settingsread.value("upload/password").toString();
    QString tokenUrl = settingsread.value("upload/tokenUrl").toString();
    QString mediaUrl = settingsread.value("upload/mediaUrl").toString();
    int imageCompressLevel=settingsread.value("basic/imageCompressLevel").toInt();
    ui->userName->setText(userName);
    ui->password->setText(password);
    ui->tokenUrl->setText(tokenUrl);
    ui->mediaUrl->setText(mediaUrl);
    ui->imageCompressLevel->setValue(imageCompressLevel);
}
