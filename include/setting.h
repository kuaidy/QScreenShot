#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QProxyStyle>
#include <QStyleOptionTab>
#include <QPainter>
#include <QSettings>
#include <QMessageBox>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Setting *ui;
public:
    void settingRead();
};

//自定义tabbar的样式
class CustomTabStyle:public QProxyStyle{
public:
    CustomTabStyle(){}
    QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

};
#endif // SETTING_H
