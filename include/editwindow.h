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
#include <QNetworkProxyFactory>
#include <QBuffer>
#include <QQmlApplicationEngine>
#include <QUrl>
#include <QQuickWidget>
#include <QQmlComponent>
#include <QSizePolicy>
#include <QClipboard>

#include "shotcommon.h"
#include "setting.h"
#include "api/baidudiskapi.h"
#include "api/wordpressapi.h"
#include "imagelabel.h"
#include "common/globalvariable.h"
#include "tabwidget.h"
#include "displaywidget.h"
#include "common/globalsetting.h"

namespace Ui {
class EditWindow;
}

class EditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();
    void CreateTab(QPixmap qPixmap,QString fileName);
    void CreateNewTab(QPixmap pixmap,QString fileName);
private:
    Ui::EditWindow *ui;
    QDockWidget *DockImage;
    //状态栏大小
    QLabel *sizeStatus;
    //状态栏缩放比例
    QLabel *scaleStatus;
public:
    void editview(QPixmap *qpix);
private slots:
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

    void on_about_triggered();
    void on_copy_triggered();
};

#endif // EDITWINDOW_H



