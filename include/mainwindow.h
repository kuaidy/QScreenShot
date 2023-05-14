#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include <QPixmap>
#include <QWidget>
#include <QScreen>
#include <QDateTime>
#include <QTimer>
#include <QThread>
#include <QPainter>
#include <QPen>
#include <QMessageBox>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#ifdef Q_OS_WIN
#include <Windows.h>
#endif
#ifdef Q_OS_LINUX
//#include <X11/Xlib.h>
//#include <X11/Xatom.h>
//#include <X11/Xutil.h>
#endif
#include <QApplication>
#include "screenview.h"
#include "editwindow.h"
#include "common/globalsetting.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    EditWindow editwin;

private:
    #ifdef Q_OS_WIN
    static BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam);
    #endif
private slots:
    void shotscreen();
    void on_pb_fullscreenshot_clicked();
    void on_pb_regscreenshot_clicked();
    void on_pb_delayedshot_clicked();
    //接收传递过来的数据的槽
    void receiveData(QPixmap data);
    void on_pb_widgetscreenshot_clicked();
    void on_pb_activewinshot_clicked();
    void on_pb_windowsshot_clicked();
    void on_pb_fixedsize_clicked();
    void showWin();

    void on_pb_colorpicker_clicked();

signals:
    void senddata(QString str);

private:
    Ui::MainWindow *ui;
    QPixmap originalPixmap;


};
#endif // MAINWINDOW_H
