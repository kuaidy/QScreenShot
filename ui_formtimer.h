/********************************************************************************
** Form generated from reading UI file 'formtimer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTIMER_H
#define UI_FORMTIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormTimer
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *FormTimer)
    {
        if (FormTimer->objectName().isEmpty())
            FormTimer->setObjectName(QString::fromUtf8("FormTimer"));
        FormTimer->resize(400, 300);
        gridLayout = new QGridLayout(FormTimer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(FormTimer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background:red"));

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        retranslateUi(FormTimer);

        QMetaObject::connectSlotsByName(FormTimer);
    } // setupUi

    void retranslateUi(QWidget *FormTimer)
    {
        FormTimer->setWindowTitle(QCoreApplication::translate("FormTimer", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormTimer", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTimer: public Ui_FormTimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTIMER_H
