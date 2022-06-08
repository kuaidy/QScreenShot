#include "colorvalue.h"
#include "ui_colorvalue.h"

ColorValue::ColorValue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorValue)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setMouseTracking(true);
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

ColorValue::~ColorValue()
{
    delete ui;
}
void ColorValue::SetColorValue(int r,int g,int b){
    QString colorValue="R:"+QString::number(r)+"G:"+QString::number(g)+"B:"+QString::number(b);
    ui->colorRGB->setText(colorValue);
    QString hex="#"+QString::number(r, 16)+QString::number(g, 16)+QString::number(b, 16);
    ui->colorHex->setText(hex);
    ui->colorPre->setStyleSheet("background-color:"+hex);
}
void ColorValue::mouseMoveEvent(QMouseEvent *event){
    move(event->globalPos());
}
