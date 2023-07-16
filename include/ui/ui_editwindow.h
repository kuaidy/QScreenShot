/********************************************************************************
** Form generated from reading UI file 'editwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
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

class Ui_EditWindow
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
    QAction *about;
    QAction *copy;
    QAction *shear;
    QAction *parse;
    QAction *selectcolor;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_help;
    QMenu *menu_set;
    QStatusBar *statusbar;
    QToolBar *toolBarfile;
    QToolBar *toolBarSize;
    QToolBar *toolBarPaint;
    QToolBar *toolBarOption;
    QToolBar *toolBarClound;
    QToolBar *toolBarSet;

    void setupUi(QMainWindow *EditWindow)
    {
        if (EditWindow->objectName().isEmpty())
            EditWindow->setObjectName("EditWindow");
        EditWindow->resize(931, 460);
        filenew = new QAction(EditWindow);
        filenew->setObjectName("filenew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        filenew->setIcon(icon);
        fileopen = new QAction(EditWindow);
        fileopen->setObjectName("fileopen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        fileopen->setIcon(icon1);
        filesaveother = new QAction(EditWindow);
        filesaveother->setObjectName("filesaveother");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/saveother.png"), QSize(), QIcon::Normal, QIcon::Off);
        filesaveother->setIcon(icon2);
        enlarge = new QAction(EditWindow);
        enlarge->setObjectName("enlarge");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/enlarge.png"), QSize(), QIcon::Normal, QIcon::Off);
        enlarge->setIcon(icon3);
        narrow = new QAction(EditWindow);
        narrow->setObjectName("narrow");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/narrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        narrow->setIcon(icon4);
        paintrec = new QAction(EditWindow);
        paintrec->setObjectName("paintrec");
        paintrec->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/paintrectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintrec->setIcon(icon5);
        paintarrow = new QAction(EditWindow);
        paintarrow->setObjectName("paintarrow");
        paintarrow->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/paintarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintarrow->setIcon(icon6);
        actionpaintfreedom = new QAction(EditWindow);
        actionpaintfreedom->setObjectName("actionpaintfreedom");
        actionpaintfreedom->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/drawfreedom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpaintfreedom->setIcon(icon7);
        actionupload = new QAction(EditWindow);
        actionupload->setObjectName("actionupload");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionupload->setIcon(icon8);
        setting = new QAction(EditWindow);
        setting->setObjectName("setting");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting->setIcon(icon9);
        actionCrop = new QAction(EditWindow);
        actionCrop->setObjectName("actionCrop");
        actionCrop->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCrop->setIcon(icon10);
        about = new QAction(EditWindow);
        about->setObjectName("about");
        copy = new QAction(EditWindow);
        copy->setObjectName("copy");
        QIcon icon11;
        QString iconThemeName = QString::fromUtf8("applications-office");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        copy->setIcon(icon11);
        shear = new QAction(EditWindow);
        shear->setObjectName("shear");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/shear.png"), QSize(), QIcon::Normal, QIcon::Off);
        shear->setIcon(icon12);
        parse = new QAction(EditWindow);
        parse->setObjectName("parse");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/parse.png"), QSize(), QIcon::Normal, QIcon::Off);
        parse->setIcon(icon13);
        selectcolor = new QAction(EditWindow);
        selectcolor->setObjectName("selectcolor");
        QIcon icon14(QIcon::fromTheme(QString::fromUtf8("accessories-calculator")));
        selectcolor->setIcon(icon14);
        centralwidget = new QWidget(EditWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        EditWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 931, 25));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName("menu_file");
        menu_help = new QMenu(menubar);
        menu_help->setObjectName("menu_help");
        menu_set = new QMenu(menubar);
        menu_set->setObjectName("menu_set");
        EditWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EditWindow);
        statusbar->setObjectName("statusbar");
        EditWindow->setStatusBar(statusbar);
        toolBarfile = new QToolBar(EditWindow);
        toolBarfile->setObjectName("toolBarfile");
        EditWindow->addToolBar(Qt::TopToolBarArea, toolBarfile);
        toolBarSize = new QToolBar(EditWindow);
        toolBarSize->setObjectName("toolBarSize");
        EditWindow->addToolBar(Qt::TopToolBarArea, toolBarSize);
        toolBarPaint = new QToolBar(EditWindow);
        toolBarPaint->setObjectName("toolBarPaint");
        toolBarPaint->setStyleSheet(QString::fromUtf8(""));
        EditWindow->addToolBar(Qt::TopToolBarArea, toolBarPaint);
        toolBarOption = new QToolBar(EditWindow);
        toolBarOption->setObjectName("toolBarOption");
        EditWindow->addToolBar(Qt::TopToolBarArea, toolBarOption);
        toolBarClound = new QToolBar(EditWindow);
        toolBarClound->setObjectName("toolBarClound");
        EditWindow->addToolBar(Qt::TopToolBarArea, toolBarClound);
        toolBarSet = new QToolBar(EditWindow);
        toolBarSet->setObjectName("toolBarSet");
        EditWindow->addToolBar(Qt::TopToolBarArea, toolBarSet);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_set->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(filenew);
        menu_file->addAction(fileopen);
        menu_file->addAction(filesaveother);
        menu_help->addAction(about);
        toolBarfile->addAction(fileopen);
        toolBarfile->addAction(filesaveother);
        toolBarSize->addAction(enlarge);
        toolBarSize->addAction(narrow);
        toolBarPaint->addAction(actionpaintfreedom);
        toolBarPaint->addAction(paintarrow);
        toolBarPaint->addAction(paintrec);
        toolBarPaint->addAction(selectcolor);
        toolBarOption->addAction(actionCrop);
        toolBarOption->addAction(shear);
        toolBarOption->addAction(copy);
        toolBarOption->addAction(parse);
        toolBarClound->addAction(actionupload);
        toolBarSet->addAction(setting);

        retranslateUi(EditWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(EditWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditWindow)
    {
        EditWindow->setWindowTitle(QCoreApplication::translate("EditWindow", "\347\274\226\350\276\221\345\231\250-QScreenShot", nullptr));
        filenew->setText(QCoreApplication::translate("EditWindow", "\346\226\260\345\273\272", nullptr));
        fileopen->setText(QCoreApplication::translate("EditWindow", "\346\211\223\345\274\200", nullptr));
        filesaveother->setText(QCoreApplication::translate("EditWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        enlarge->setText(QCoreApplication::translate("EditWindow", "\346\224\276\345\244\247", nullptr));
        narrow->setText(QCoreApplication::translate("EditWindow", "\347\274\251\345\260\217", nullptr));
        paintrec->setText(QCoreApplication::translate("EditWindow", "\347\273\230\345\210\266\347\237\251\345\275\242", nullptr));
#if QT_CONFIG(tooltip)
        paintrec->setToolTip(QCoreApplication::translate("EditWindow", "\347\273\230\345\210\266\347\237\251\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        paintarrow->setText(QCoreApplication::translate("EditWindow", "\347\273\230\345\210\266\347\256\255\345\244\264", nullptr));
#if QT_CONFIG(tooltip)
        paintarrow->setToolTip(QCoreApplication::translate("EditWindow", "\347\273\230\345\210\266\347\256\255\345\244\264", nullptr));
#endif // QT_CONFIG(tooltip)
        actionpaintfreedom->setText(QCoreApplication::translate("EditWindow", "\350\207\252\347\224\261\347\273\230\345\210\266", nullptr));
        actionupload->setText(QCoreApplication::translate("EditWindow", "upload", nullptr));
#if QT_CONFIG(tooltip)
        actionupload->setToolTip(QCoreApplication::translate("EditWindow", "\345\260\206\345\275\223\345\211\215\345\233\276\347\211\207\344\270\212\344\274\240", nullptr));
#endif // QT_CONFIG(tooltip)
        setting->setText(QCoreApplication::translate("EditWindow", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        setting->setToolTip(QCoreApplication::translate("EditWindow", "\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCrop->setText(QCoreApplication::translate("EditWindow", "Crop", nullptr));
#if QT_CONFIG(tooltip)
        actionCrop->setToolTip(QCoreApplication::translate("EditWindow", "\350\243\201\345\211\252", nullptr));
#endif // QT_CONFIG(tooltip)
        about->setText(QCoreApplication::translate("EditWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        about->setToolTip(QCoreApplication::translate("EditWindow", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        copy->setText(QCoreApplication::translate("EditWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        copy->setToolTip(QCoreApplication::translate("EditWindow", "\345\244\215\345\210\266\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        shear->setText(QCoreApplication::translate("EditWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        shear->setToolTip(QCoreApplication::translate("EditWindow", "\345\211\252\345\210\207\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        parse->setText(QCoreApplication::translate("EditWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        parse->setToolTip(QCoreApplication::translate("EditWindow", "\347\262\230\350\264\264\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        selectcolor->setText(QString());
#if QT_CONFIG(tooltip)
        selectcolor->setToolTip(QCoreApplication::translate("EditWindow", "\351\200\211\346\213\251\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        menu_file->setTitle(QCoreApplication::translate("EditWindow", "\346\226\207\344\273\266", nullptr));
        menu_help->setTitle(QCoreApplication::translate("EditWindow", "\345\270\256\345\212\251", nullptr));
        menu_set->setTitle(QCoreApplication::translate("EditWindow", "\350\256\276\347\275\256", nullptr));
        toolBarfile->setWindowTitle(QCoreApplication::translate("EditWindow", "toolBar", nullptr));
        toolBarSize->setWindowTitle(QCoreApplication::translate("EditWindow", "toolBar_2", nullptr));
        toolBarPaint->setWindowTitle(QCoreApplication::translate("EditWindow", "toolBar", nullptr));
        toolBarOption->setWindowTitle(QCoreApplication::translate("EditWindow", "toolBar", nullptr));
        toolBarClound->setWindowTitle(QCoreApplication::translate("EditWindow", "toolBar_2", nullptr));
        toolBarSet->setWindowTitle(QCoreApplication::translate("EditWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditWindow: public Ui_EditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITWINDOW_H
