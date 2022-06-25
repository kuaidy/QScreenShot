#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDockWidget>
#include <QGridLayout>
#include <QImage>
#include <QScrollArea>
#include <QPainter>
#include <QMouseEvent>
#include <QList>
#include <cmath>
#include <QFileDialog>
#include <QDateTime>
#include <QPixmap>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QCursor>
#include <QMessageBox>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QNetworkProxyFactory>
#include <QBuffer>

#include "shotcommon.h"
#include "setting.h"
#include "api/BaiduDiskApi.h"
#include "api/wordpressapi.h"
#include "plabel.h"
#include "common/GlobalVariable.h"

namespace Ui {
class editwindow;
}
class editwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr);
    ~editwindow();
    void CreateTab(QPixmap qPixmap,QString fileName);
private:
    Ui::editwindow *ui;
    QDockWidget *DockImage;
    //状态栏大小
    QLabel *sizeStatus;
    //状态栏缩放比例
    QLabel *scaleStatus;
public:
    void editview(QPixmap *qpix);
private slots:
    void on_paintrec_triggered();
    void on_paintarrow_triggered();
    void on_paintrec_triggered(bool checked);
    void on_paintarrow_triggered(bool checked);
    void on_filesaveother_triggered();
    void on_vague_triggered(bool checked);
    void on_actionpaintfreedom_triggered(bool checked);
    void on_enlarge_triggered();
    void on_narrow_triggered();
    void on_fileopen_triggered();
    void on_setting_triggered();
    void removeSubTab(int index);
    void on_actionupload_triggered();
    void on_actionCrop_triggered(bool checked);

};

#endif // EDITWINDOW_H



