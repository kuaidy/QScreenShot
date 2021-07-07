#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

typedef struct _DLONG{
    LONG wParam;
    LONG lParam;
}stLONG;

editwindow *ewind=NULL;
int i=0;
//回调函数
BOOL CALLBACK MainWindow::EnumWindowsProc(HWND hwnd,LPARAM lParam){
    qDebug()<<hwnd;
    if(hwnd){
//        QPixmap pixmap = QPixmap::grabWindow((WId)hwnd);
//        ewind->editview(&pixmap);
//        ewind->show();
//        i++;
//        if(i>=100){
//            return false;
//        }
    }else{
        return false;
    }
}

//捕获活动窗口
void MainWindow::on_pb_widgetscreenshot_clicked()
{
    hide();
    QThread::msleep(800);
    //获取所有窗口
    //EnumWindows(EnumWindowsProc,NULL);
    HWND tmp=GetForegroundWindow();
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

char m_Name[MAXBYTE];
char m_Title[MAXBYTE];
WORD m_nNum;
QList<QRect> ListRect;
//回调函数
BOOL CALLBACK EnumAllWindows(HWND Hwnd, LPARAM IParm)//系统返还给你的窗口句柄,API调用进来的参数
{
    //每次Hwnd返回回来，都需要获取他的类名和标题
    GetClassNameA(Hwnd,m_Name,MAXBYTE);//获得指定窗口所属的类的类名
    GetWindowTextA(Hwnd,m_Title,MAXBYTE);//查找标题
    m_nNum++;
    QString strName = QString::fromLocal8Bit(m_Name);
    QString strTitle = QString::fromLocal8Bit(m_Title);
    QWindow *m_window;
    m_window = QWindow::fromWinId((WId)Hwnd);
    if(IsWindow(Hwnd)&&IsWindowEnabled(Hwnd)&&IsWindowVisible(Hwnd)){
        qDebug()<<"ID:"<<m_nNum<<"hwnd:"<<Hwnd<<"classname:"<<strName<<"title:"<<strTitle;
        qDebug()<<m_window->width();
        qDebug()<<m_window->height();
        qDebug()<<m_window->x();
        qDebug()<<m_window->y();

        QRect rect;
        rect.setX(m_window->x());
        rect.setY(m_window->y());
        rect.setWidth(m_window->width());
        rect.setHeight(m_window->height());
        ListRect.append(rect);
    }

//    return false;//枚举一次就不枚举了
    return true;//枚举到完毕
}

//获取窗口对象
void MainWindow::on_pb_windowsshot_clicked()
{
//    hide();
//    QThread::msleep(800);
//    HWND tmp=GetActiveWindow();
//    qDebug()<<tmp;
//    QPixmap pixmap = QPixmap::grabWindow((WId)tmp);
//    editwin.editview(&pixmap);
//    editwin.show();
//    show();

//    EnumWindows(EnumAllWindows,(LPARAM)"");
    EnumChildWindows(GetDesktopWindow(), EnumAllWindows, (LPARAM)"");

    if(ListRect.count()>0){

    }

//    hide();
//    QThread::msleep(800);
//    screenview *sv=new screenview(this,0);
//    connect(sv, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));
//    sv->show();


}

//捕获固定窗口的大小
void MainWindow::on_pb_fixedsize_clicked()
{
    hide();
    QThread::msleep(800);
    screenview *sv=new screenview(nullptr,1);
    connect(sv, SIGNAL(senddata(QPixmap)),this,SLOT(receiveData(QPixmap)));
    sv->show();
}
