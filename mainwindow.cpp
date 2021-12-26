#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}
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

typedef struct _DLONG{
    LONG wParam;
    LONG lParam;
}stLONG;

editwindow *ewind=NULL;
int i=0;
//回调函数
//BOOL CALLBACK MainWindow::EnumWindowsProc(HWND hwnd,LPARAM lParam){
//    qDebug()<<hwnd;
//    if(hwnd){
////        QPixmap pixmap = QPixmap::grabWindow((WId)hwnd);
////        ewind->editview(&pixmap);
////        ewind->show();
////        i++;
////        if(i>=100){
////            return false;
////        }
//    }else{
//        return false;
//    }
//}

//捕获活动窗口
void MainWindow::on_pb_widgetscreenshot_clicked()
{
    hide();
    //QThread::msleep(800);
    //获取所有窗口
    //EnumWindows(EnumWindowsProc,NULL);
    //HWND tmp=GetForegroundWindow();
//    QPixmap pixmap = QPixmap::grabWindow((WId)tmp);
//    editwin.editview(&pixmap);
//    editwin.show();
//    show();
}

//捕获顶层窗口的截图
void MainWindow::on_pb_activewinshot_clicked()
{
//    hide();
//    QThread::msleep(800);
//    //获取所有窗口
//    //EnumWindows(EnumWindowsProc,NULL);
//    HWND tmp=GetForegroundWindow();
//    QPixmap pixmap = QPixmap::grabWindow((WId)tmp);
//    editwin.editview(&pixmap);
//    editwin.show();
//    show();
}

QList<QRect> ListWindows;
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

//获取窗口对象
void MainWindow::on_pb_windowsshot_clicked()
{
    //windows操作系统执行
    #ifdef Q_OS_WIN
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
