/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITWINDOW_H
#define UI_EDITWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editwindow
{
public:
    QAction *filenew;
    QAction *fileopen;
    QAction *filesaveother;
    QAction *enlarge;
    QAction *narrow;
    QAction *paintrec;
    QAction *paintarrow;
    QAction *actionpaintfreedom;
    QAction *actionupload;
    QAction *setting;
    QAction *actionCrop;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_set;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBarfile;
    QToolBar *toolBarSize;
    QToolBar *toolBarPaint;
    QToolBar *toolBarOption;
    QToolBar *toolBarClound;
    QToolBar *toolBarSet;

    void setupUi(QMainWindow *editwindow)
    {
        if (editwindow->objectName().isEmpty())
            editwindow->setObjectName(QString::fromUtf8("editwindow"));
        editwindow->resize(588, 401);
        filenew = new QAction(editwindow);
        filenew->setObjectName(QString::fromUtf8("filenew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        filenew->setIcon(icon);
        fileopen = new QAction(editwindow);
        fileopen->setObjectName(QString::fromUtf8("fileopen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        fileopen->setIcon(icon1);
        filesaveother = new QAction(editwindow);
        filesaveother->setObjectName(QString::fromUtf8("filesaveother"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/saveother.png"), QSize(), QIcon::Normal, QIcon::Off);
        filesaveother->setIcon(icon2);
        enlarge = new QAction(editwindow);
        enlarge->setObjectName(QString::fromUtf8("enlarge"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/enlarge.png"), QSize(), QIcon::Normal, QIcon::Off);
        enlarge->setIcon(icon3);
        narrow = new QAction(editwindow);
        narrow->setObjectName(QString::fromUtf8("narrow"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/narrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        narrow->setIcon(icon4);
        paintrec = new QAction(editwindow);
        paintrec->setObjectName(QString::fromUtf8("paintrec"));
        paintrec->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/paintrectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintrec->setIcon(icon5);
        paintarrow = new QAction(editwindow);
        paintarrow->setObjectName(QString::fromUtf8("paintarrow"));
        paintarrow->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/paintarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintarrow->setIcon(icon6);
        actionpaintfreedom = new QAction(editwindow);
        actionpaintfreedom->setObjectName(QString::fromUtf8("actionpaintfreedom"));
        actionpaintfreedom->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/drawfreedom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpaintfreedom->setIcon(icon7);
        actionupload = new QAction(editwindow);
        actionupload->setObjectName(QString::fromUtf8("actionupload"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionupload->setIcon(icon8);
        setting = new QAction(editwindow);
        setting->setObjectName(QString::fromUtf8("setting"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting->setIcon(icon9);
        actionCrop = new QAction(editwindow);
        actionCrop->setObjectName(QString::fromUtf8("actionCrop"));
        actionCrop->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCrop->setIcon(icon10);
        centralwidget = new QWidget(editwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        editwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(editwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 588, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_set = new QMenu(menubar);
        menu_set->setObjectName(QString::fromUtf8("menu_set"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        editwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(editwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        editwindow->setStatusBar(statusbar);
        toolBarfile = new QToolBar(editwindow);
        toolBarfile->setObjectName(QString::fromUtf8("toolBarfile"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarfile);
        toolBarSize = new QToolBar(editwindow);
        toolBarSize->setObjectName(QString::fromUtf8("toolBarSize"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarSize);
        toolBarPaint = new QToolBar(editwindow);
        toolBarPaint->setObjectName(QString::fromUtf8("toolBarPaint"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarPaint);
        toolBarOption = new QToolBar(editwindow);
        toolBarOption->setObjectName(QString::fromUtf8("toolBarOption"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarOption);
        toolBarClound = new QToolBar(editwindow);
        toolBarClound->setObjectName(QString::fromUtf8("toolBarClound"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarClound);
        toolBarSet = new QToolBar(editwindow);
        toolBarSet->setObjectName(QString::fromUtf8("toolBarSet"));
        editwindow->addToolBar(Qt::TopToolBarArea, toolBarSet);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_set->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(filenew);
        menu->addAction(fileopen);
        menu->addAction(filesaveother);
        toolBarfile->addAction(fileopen);
        toolBarfile->addAction(filesaveother);
        toolBarSize->addAction(enlarge);
        toolBarSize->addAction(narrow);
        toolBarPaint->addAction(actionpaintfreedom);
        toolBarPaint->addAction(paintarrow);
        toolBarPaint->addAction(paintrec);
        toolBarOption->addAction(actionCrop);
        toolBarClound->addAction(actionupload);
        toolBarSet->addAction(setting);

        retranslateUi(editwindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(editwindow);
    } // setupUi

    void retranslateUi(QMainWindow *editwindow)
    {
        editwindow->setWindowTitle(QCoreApplication::translate("editwindow", "\347\274\226\350\276\221\345\231\250", nullptr));
        filenew->setText(QCoreApplication::translate("editwindow", "\346\226\260\345\273\272", nullptr));
        fileopen->setText(QCoreApplication::translate("editwindow", "\346\211\223\345\274\200", nullptr));
        filesaveother->setText(QCoreApplication::translate("editwindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        enlarge->setText(QCoreApplication::translate("editwindow", "\346\224\276\345\244\247", nullptr));
        narrow->setText(QCoreApplication::translate("editwindow", "\347\274\251\345\260\217", nullptr));
        paintrec->setText(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\237\251\345\275\242", nullptr));
#if QT_CONFIG(tooltip)
        paintrec->setToolTip(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\237\251\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        paintarrow->setText(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\256\255\345\244\264", nullptr));
#if QT_CONFIG(tooltip)
        paintarrow->setToolTip(QCoreApplication::translate("editwindow", "\347\273\230\345\210\266\347\256\255\345\244\264", nullptr));
#endif // QT_CONFIG(tooltip)
        actionpaintfreedom->setText(QCoreApplication::translate("editwindow", "\350\207\252\347\224\261\347\273\230\345\210\266", nullptr));
        actionupload->setText(QCoreApplication::translate("editwindow", "upload", nullptr));
#if QT_CONFIG(tooltip)
        actionupload->setToolTip(QCoreApplication::translate("editwindow", "\345\260\206\345\275\223\345\211\215\345\233\276\347\211\207\344\270\212\344\274\240", nullptr));
#endif // QT_CONFIG(tooltip)
        setting->setText(QCoreApplication::translate("editwindow", "setting", nullptr));
#if QT_CONFIG(tooltip)
        setting->setToolTip(QCoreApplication::translate("editwindow", "\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCrop->setText(QCoreApplication::translate("editwindow", "Crop", nullptr));
#if QT_CONFIG(tooltip)
        actionCrop->setToolTip(QCoreApplication::translate("editwindow", "\350\243\201\345\211\252", nullptr));
#endif // QT_CONFIG(tooltip)
        menu->setTitle(QCoreApplication::translate("editwindow", "\346\226\207\344\273\266", nullptr));
        menu_set->setTitle(QCoreApplication::translate("editwindow", "\350\256\276\347\275\256", nullptr));
        menu_3->setTitle(QCoreApplication::translate("editwindow", "\345\270\256\345\212\251", nullptr));
        toolBarfile->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
        toolBarSize->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar_2", nullptr));
        toolBarPaint->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
        toolBarOption->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
        toolBarClound->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar_2", nullptr));
        toolBarSet->setWindowTitle(QCoreApplication::translate("editwindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editwindow: public Ui_editwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
