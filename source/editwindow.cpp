#include "../include/editwindow.h"
#include "ui_editwindow.h"

#define STRETCH_RECT_HEIGHT 4
#define STRETCH_RECT_WIDTH 4

QPixmap *PlabelPixmap=nullptr;
QImage PlabelImage;


EditWindow::EditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
    ui->tabWidget->layout();
    //这样每页都会有关闭按钮
    ui->tabWidget->setTabsClosable(true);
    //状态栏显示
    sizeStatus=new QLabel("大小：");
    scaleStatus=new QLabel("缩放：");
    ui->statusbar->addWidget(sizeStatus);
    ui->statusbar->addWidget(scaleStatus);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::editview(QPixmap *qpix){
    showMaximized();
//    ui->tabWidget->clear();
    PlabelPixmap=qpix;
    PlabelImage = qpix->toImage();
    //插入页
    QString tabname="新建";
    QString tabnum=QString::number(ui->tabWidget->count(),10);
    tabname.append(tabnum);
    int tabindex=ui->tabWidget->count()-1<0?0:ui->tabWidget->count()-1;
//    CreateTab(*qpix,tabname);
    CreateNewTab(*qpix,tabname);
    //状态栏显示
//    sizeStatus=new QLabel("大小："+QString::number(qpix->width())+'x'+QString::number(qpix->height()));
//    scaleStatus=new QLabel("缩放："+QString::number(Scale)+"%");
//    ui->statusbar->addWidget(sizeStatus);
//    ui->statusbar->addWidget(scaleStatus);
    sizeStatus->setText("大小："+QString::number(qpix->width())+'x'+QString::number(qpix->height()));
    scaleStatus->setText("缩放："+QString::number(Scale*100)+"%");
}

//绘制矩形
void EditWindow::on_paintrec_triggered(bool checked)
{
    if(checked){
        OptionFlag=OptionTypeEnum::PaintRect;
    }else{
        OptionFlag=OptionTypeEnum::None;
    }
}

//绘制箭头
void EditWindow::on_paintarrow_triggered(bool checked)
{
   if(checked){
       OptionFlag=OptionTypeEnum::PaintArrow;
   }else{
       OptionFlag=OptionTypeEnum::None;
   }
}

//另存为
void EditWindow::on_filesaveother_triggered()
{
    int tabIndex=ui->tabWidget->currentIndex();
    QDateTime timenow=QDateTime::currentDateTime();
    QString filestr=timenow.toString("yyyy-MM-dd-hhmmss");
    QFileDialog *fileDialog=new QFileDialog();
    fileDialog->setWindowTitle(tr("另存为"));
    fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setFileMode(QFileDialog::AnyFile);
    QString fileName=fileDialog->getSaveFileName(this,tr("另存为"),filestr+".png");
    if(!fileName.isNull()){
        QWidget* qWidget= ui->tabWidget->currentWidget();
        //根据子控件的名称查找子控件
        QLabel* label = qWidget->findChild<QLabel*>();
        QPixmap pixmap=label->grab();
        pixmap.save(fileName,"PNG",_globalSetting._imageCompressLevel*10);
    }
}

//模糊
void EditWindow::on_vague_triggered(bool checked)
{
    if(checked){
       OptionFlag=OptionTypeEnum::Vague;
    }else{
       OptionFlag=OptionTypeEnum::None;
    }
}
//自由绘制
void EditWindow::on_actionpaintfreedom_triggered(bool checked)
{
    if(checked){
        OptionFlag=OptionTypeEnum::PaintFreedom;
    }else{
        OptionFlag=OptionTypeEnum::None;
    }
}
//放大
void EditWindow::on_enlarge_triggered()
{
    const int num=2;
    QWidget* qWidget= ui->tabWidget->currentWidget();
    //根据子控件的名称查找子控件
    QLabel* label = qWidget->findChild<QLabel*>();
    //获取原图片
    int pixWidth=PlabelImage.width();
    int pixHeigth=PlabelImage.height();
    Scale=Scale*num;
    QPixmap pixMap=QPixmap::fromImage(PlabelImage.scaled(pixWidth*Scale,pixHeigth*Scale,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    label->setPixmap(pixMap);
    label->resize(pixMap.width(),pixMap.height());
    sizeStatus->setText("大小："+QString::number(pixMap.width())+"x"+QString::number(pixMap.height()));
    scaleStatus->setText("缩放："+QString::number(Scale*100)+"%");
}

//缩小
void EditWindow::on_narrow_triggered()
{
    const int num=2;
    QWidget* qWidget= ui->tabWidget->currentWidget();
    //根据子控件的名称查找子控件
    QLabel* label = qWidget->findChild<QLabel*>();
    //获取原图片
    int pixWidth=PlabelImage.width();
    int pixHeigth=PlabelImage.height();
    Scale=Scale/num;
    QPixmap pixMap=QPixmap::fromImage(PlabelImage.scaled(pixWidth*Scale,pixHeigth*Scale,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    label->setPixmap(pixMap);
    label->resize(pixMap.width(),pixMap.height());
    sizeStatus->setText("大小："+QString::number(pixMap.width())+"x"+QString::number(pixMap.height()));
    scaleStatus->setText("缩放："+QString::number(Scale*100)+"%");
}

//打开文件
void EditWindow::on_fileopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"),"./", tr("Image files(*.bmp *.jpg *.png);All files (*.*)"));
    if(!fileName.isEmpty())
    {
        QFileInfo fileInfo=QFileInfo(fileName);
        QImage img;
        if(img.load(fileName)){
            CreateTab(QPixmap::fromImage(img),fileInfo.fileName());
        }
    }
}
//创建tab页
void EditWindow::CreateTab(QPixmap pixMap,QString fileName){
    //保存原始图片
    //创建一个窗口，放到tab里头
    //    QWidget *widget = new QWidget();
    DisplayWidget *widget=new DisplayWidget();
    //    widget->setStyleSheet("background-color:green;");
    QGridLayout *qgridlayout=new QGridLayout(widget);
    //去除默认边距
    qgridlayout->setSpacing(0);
    qgridlayout->setContentsMargins(0,0,0,0);
    //创建滚动条
    QScrollArea *scrollarea=new QScrollArea(widget);
    scrollarea->setStyleSheet("background-color:white;");
    scrollarea->setAttribute(Qt::WA_TranslucentBackground, true);
    //    scrollarea->setWidgetResizable(true);
    //创建一个label用来显示图片
    widget->imageLabel=new ImageLabel();
    widget->imageLabel->setMargin(0);
    //    connect(imagelabel,SIGNAL(mouseDoubleClickEvent(QMouseEvent*)),this,SLOT(removeSubTab(int)));
    widget->imageLabel->setObjectName(fileName);
    //    widget->imageLabel->setStyleSheet("background:white;");
    //    widget->imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    // 图像与imgLabel同大小
    widget->imageLabel->resize(pixMap.size());
    //    widget->imageLabel->setFixedSize(pixMap.size());
    //内容居中
    widget->imageLabel->setAlignment(Qt::AlignCenter);
    // 禁用QLabel的边框
    //    widget->imageLabel->setFrameStyle(QFrame::NoFrame);
    //    widget->imageLabel->setContentsMargins(0,0,0,0);
    //内容保持原来的大小
    widget->imageLabel->setScaledContents(false);
    //设置图像
    widget->imageLabel->setPixmap(pixMap);

    scrollarea->setAlignment(Qt::AlignCenter);
    scrollarea->setWidget(widget->imageLabel);
    scrollarea->setMouseTracking(true);
    qgridlayout->addWidget(scrollarea);
    //插入页
    ui->tabWidget->addTab(widget,fileName);
    ui->tabWidget->setCurrentWidget(widget);
}

//创建新的tab页
void EditWindow::CreateNewTab(QPixmap pixMap,QString fileName){
//    //保存原始图片
//    //创建一个窗口，放到tab里头
//    //    QWidget *widget = new QWidget();
//    displayWidget *widget=new displayWidget();
//    //    widget->setStyleSheet("background-color:green;");
//    QGridLayout *qgridlayout=new QGridLayout(widget);
//    //去除默认边距
//    qgridlayout->setSpacing(0);
//    qgridlayout->setContentsMargins(0,0,0,0);
//    //创建滚动条
//    QScrollArea *scrollarea=new QScrollArea(widget);
//    scrollarea->setStyleSheet("background-color:white;");
//    scrollarea->setAttribute(Qt::WA_TranslucentBackground, true);
//    //    scrollarea->setWidgetResizable(true);
//    //创建一个label用来显示图片
//    widget->imageLabel=new Plabel();
    ImageLabel *imageLabel=new ImageLabel();
    imageLabel->setStyleSheet("background-color:#f0f0f0;");
    imageLabel->setMargin(0);
    //connect(imagelabel,SIGNAL(mouseDoubleClickEvent(QMouseEvent*)),this,SLOT(removeSubTab(int)));
    imageLabel->setObjectName(fileName);
    //imageLabel->setStyleSheet("background:white;");
    //imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    // 图像与imgLabel同大小
//    imageLabel->resize(pixMap.size());
    //imageLabel->setFixedSize(pixMap.size());
    //内容居中
    imageLabel->setAlignment(Qt::AlignCenter);
    //禁用QLabel的边框
    //imageLabel->setFrameStyle(QFrame::NoFrame);
    //imageLabel->setContentsMargins(0,0,0,0);
    //内容保持原来的大小
    imageLabel->setScaledContents(false);
    //设置图像
    imageLabel->setPixmap(pixMap);
    //插入页
    ui->tabWidget->addTab(imageLabel,fileName);
    ui->tabWidget->setCurrentWidget(imageLabel);
}


void EditWindow::removeSubTab(int index)
{
    ui->tabWidget->removeTab(index);
}

void EditWindow::on_setting_triggered()
{
    Setting *setting=new Setting();
    setting->show();
}

//上传图片
void EditWindow::on_actionupload_triggered()
{
    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "提示", "确定要上传图片吗?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;
    QPixmap pixMap=QPixmap::fromImage(PlabelImage);
    QByteArray bytearray;
    QBuffer buffer(&bytearray);
    buffer.open(QIODevice::WriteOnly);
    bool bOk = pixMap.save(&buffer,"PNG",20);
    QDateTime timenow=QDateTime::currentDateTime();
    QString fileName=timenow.toString("yyyy-MM-dd-hhmmss")+".png";
    WordpressApi *wordpressApi=new WordpressApi();
    wordpressApi->GetToken();
    bool res=wordpressApi->UploadFile(bytearray,fileName);
    QMessageBox::information(this,"提示","上传成功！",QMessageBox::Ok);
}

//裁剪
void EditWindow::on_actionCrop_triggered(bool checked)
{
    if(checked){
        OptionFlag=OptionTypeEnum::ActionCrop;
    }else{
        OptionFlag=OptionTypeEnum::None;
    }
}

//关于
void EditWindow::on_about_triggered()
{
    //出现段错误，锚点布局导致？？？
    QQuickWidget view;
    view.setResizeMode(QQuickWidget::SizeRootObjectToView);
    view.setFixedSize(400,300);
    view.setSource(QUrl::fromLocalFile("C:/Myproject/QScreenShot/ui/about.qml"));
    view.show();

    // 创建 QQmlEngine 对象
//    QQmlEngine engine;

//    // 创建 QQmlComponent 对象，并关联 QQmlEngine
//    QQmlComponent component(&engine, QUrl::fromLocalFile("../ui/about.qml"));

//    // 设置 QML 数据
//    QObject *object = component.create();

//    if (object)
//    {
//        // 将 QML 组件添加到父对象中
//        QWidget *window = new QWidget();
//        QHBoxLayout *layout = new QHBoxLayout(window);
//        QQuickItem *item = qobject_cast<QQuickItem *>(object);
//        layout->addWidget(item);
//        window->setCentralWidget(container);
//        window->show();
//    }
}

//复制图片到剪切板
void EditWindow::on_copy_triggered()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    // 将图片复制到剪切板
//    clipboard->setPixmap(*PlabelPixmap);
    clipboard->setImage(PlabelImage);
}

