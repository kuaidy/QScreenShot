#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint);
    QScreen *screen =QGuiApplication::primaryScreen();
    int x= screen->geometry().width()-300;
    int y= 100;
    move(x,y);

    //读取配置文件
    try{
        QSettings settingsread("setting.ini",QSettings::IniFormat);
        _globalSetting._imageCompressLevel = settingsread.value("basic/imageCompressLevel").toInt();
    }
    catch(std::exception ex){

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
//获取全屏
void MainWindow::on_pb_fullscreenshot_clicked()
{
    hide();
    if(MainWindow::isHidden()){
        QThread::msleep(800);
        QScreen *screen =QGuiApplication::primaryScreen();
        if(const QWindow *window=windowHandle())
            screen=window->screen();
        if(!screen)
            return ;
        originalPixmap=screen->grabWindow(0);
        editwin.editview(&originalPixmap);
        editwin.show();
        show();
    }
}
//截屏操作
void MainWindow::shotscreen(){


}

//画矩形截图
void MainWindow::on_pb_regscreenshot_clicked()
{
//    screenview sv;
    hide();
    QThread::msleep(800);
    screenview *sv=new screenview(nullptr,0);
    connect(sv, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));
    connect(sv,SIGNAL(showWin()),this,SLOT(showWin()));
    sv->show();
}

//延时截图
void MainWindow::on_pb_delayedshot_clicked()
{

}

void MainWindow::receiveData(QPixmap data){
    editwin.editview(&data);
    editwin.show();
    show();
}
void MainWindow::showWin(){
    show();
}

#ifdef Q_OS_WIN
typedef struct _DLONG{
    LONG wParam;
    LONG lParam;
}stLONG;
EditWindow *ewind=NULL;
int i=0;
#endif
//捕获活动窗口
void MainWindow::on_pb_widgetscreenshot_clicked()
{

}

//捕获顶层窗口的截图
void MainWindow::on_pb_activewinshot_clicked()
{

}
QList<QRect> ListWindows;
#ifdef Q_OS_WIN
//回调函数
BOOL CALLBACK EnumAllWindows(HWND Hwnd, LPARAM IParm)//系统返还给你的窗口句柄,API调用进来的参数
{
    QWindow *m_window;
    m_window = QWindow::fromWinId((WId)Hwnd);
    if(IsWindowEnabled(Hwnd)&&IsWindowVisible(Hwnd)&&!IsIconic(Hwnd)){
        QRect rect;
        rect.setX(m_window->frameGeometry().x());
        rect.setY(m_window->frameGeometry().y());
        rect.setWidth(m_window->frameGeometry().width());
        rect.setHeight(m_window->frameGeometry().height());
        ListWindows.append(rect);
    }
    //枚举到完毕
    return true;
}
#endif
//获取窗口对象
void MainWindow::on_pb_windowsshot_clicked()
{
    #ifdef Q_OS_WIN
        //windows操作系统执行
        hide();
        ListWindows.clear();
        QThread::msleep(800);
        EnumWindows(EnumAllWindows,(LPARAM)"");
        //EnumChildWindows(GetDesktopWindow(), EnumAllWindows, (LPARAM)"");
        if(ListWindows.count()>0){
            screenview *sv=new screenview(nullptr,&ListWindows,2);
            connect(sv, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));
            sv->show();
        }
    #endif
    #ifdef Q_OS_LINUX
        //linux
        QPoint point=QCursor().pos();
        QWindowList listWindow= QGuiApplication::allWindows();
        for(int i=0;i<listWindow.length();i++){
            if(listWindow[i]->isVisible()&&listWindow[i]->isWindowType()){
                QRect rect;
                rect.setX(listWindow[i]->x());
                rect.setY(listWindow[i]->y());
                rect.setWidth(listWindow[i]->width());
                rect.setHeight(listWindow[i]->height());
                ListWindows.append(rect);
            }
        }
        if(ListWindows.count()>0){
            screenview *sv=new screenview(nullptr,&ListWindows,2);
            connect(sv, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));
            sv->show();
        }
    #endif
}


//捕获固定窗口的大小
void MainWindow::on_pb_fixedsize_clicked()
{
    hide();
    QThread::msleep(800);
    screenview *sv=new screenview(nullptr,nullptr,1);
    connect(sv, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));
    sv->show();
}
//拾取颜色
void MainWindow::on_pb_colorpicker_clicked()
{
    screenview *sv=new screenview(nullptr,nullptr,3);
    sv->show();
}

