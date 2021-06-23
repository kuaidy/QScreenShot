#include "formtimer.h"
#include "ui_formtimer.h"

FormTimer::FormTimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTimer)
{
    ui->setupUi(this);
}

FormTimer::~FormTimer()
{
    delete ui;
}
