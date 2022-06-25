/********************************************************************************
** Form generated from reading UI file 'screenview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENVIEW_H
#define UI_SCREENVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenview
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *screenview)
    {
        if (screenview->objectName().isEmpty())
            screenview->setObjectName(QString::fromUtf8("screenview"));
        screenview->resize(400, 300);
        gridLayout = new QGridLayout(screenview);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        retranslateUi(screenview);

        QMetaObject::connectSlotsByName(screenview);
    } // setupUi

    void retranslateUi(QWidget *screenview)
    {
        screenview->setWindowTitle(QCoreApplication::translate("screenview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screenview: public Ui_screenview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENVIEW_H
