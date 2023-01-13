/********************************************************************************
** Form generated from reading UI file 'fixedsizeform.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIXEDSIZEFORM_H
#define UI_FIXEDSIZEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fixedsizeform
{
public:
    QGridLayout *gridLayout;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QFrame *horizontalFrame1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QComboBox *comboBox;

    void setupUi(QWidget *fixedsizeform)
    {
        if (fixedsizeform->objectName().isEmpty())
            fixedsizeform->setObjectName(QString::fromUtf8("fixedsizeform"));
        fixedsizeform->resize(318, 159);
        fixedsizeform->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(fixedsizeform);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalFrame = new QFrame(fixedsizeform);
        horizontalFrame->setObjectName(QString::fromUtf8("horizontalFrame"));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        pushButton = new QPushButton(horizontalFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalFrame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalFrame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout->addWidget(horizontalFrame, 4, 0, 1, 1, Qt::AlignVCenter);

        groupBox = new QGroupBox(fixedsizeform);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(4);
        gridLayout_2->setContentsMargins(-1, 10, 10, -1);
        horizontalFrame1 = new QFrame(groupBox);
        horizontalFrame1->setObjectName(QString::fromUtf8("horizontalFrame1"));
        horizontalLayout_2 = new QHBoxLayout(horizontalFrame1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(horizontalFrame1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        spinBox_2 = new QSpinBox(horizontalFrame1);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_2->addWidget(spinBox_2, 0, Qt::AlignRight);

        label_2 = new QLabel(horizontalFrame1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(horizontalFrame1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        spinBox->setLayoutDirection(Qt::LeftToRight);
        spinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        spinBox->setStepType(QAbstractSpinBox::DefaultStepType);

        horizontalLayout_2->addWidget(spinBox, 0, Qt::AlignHCenter);

        comboBox = new QComboBox(horizontalFrame1);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        gridLayout_2->addWidget(horizontalFrame1, 3, 0, 1, 1, Qt::AlignHCenter);


        gridLayout->addWidget(groupBox, 1, 0, 3, 1);


        retranslateUi(fixedsizeform);

        QMetaObject::connectSlotsByName(fixedsizeform);
    } // setupUi

    void retranslateUi(QWidget *fixedsizeform)
    {
        fixedsizeform->setWindowTitle(QCoreApplication::translate("fixedsizeform", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("fixedsizeform", "\351\207\215\347\275\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("fixedsizeform", "\347\241\256\350\256\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("fixedsizeform", "\345\217\226\346\266\210", nullptr));
        groupBox->setTitle(QCoreApplication::translate("fixedsizeform", "\345\233\272\345\256\232\345\214\272\345\237\237", nullptr));
        label->setText(QCoreApplication::translate("fixedsizeform", "\351\225\277", nullptr));
        label_2->setText(QCoreApplication::translate("fixedsizeform", "\345\256\275", nullptr));
        comboBox->setCurrentText(QString());
        comboBox->setPlaceholderText(QCoreApplication::translate("fixedsizeform", "\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fixedsizeform: public Ui_fixedsizeform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIXEDSIZEFORM_H
