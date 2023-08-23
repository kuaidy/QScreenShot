#include "../include/AntLine.h"

AntLine::AntLine(QWidget* parent) : QWidget(parent)
{
    lineLen = 6;
    lineWidth = 2;
    lineStep = 1;
    lineSpeed = 100;
    lineColor = QColor(255,255,255);
    dashes = lineLen;
    spaces = lineLen;
    dashPattern.clear();
    for (int i = 0; i < 20; ++i) {
        dashPattern << lineLen;
    }
    
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    timer->start(lineSpeed);
}

AntLine::~AntLine()
{
    if (timer->isActive()) {
        timer->stop();
    }
}

void AntLine::paintEvent(QPaintEvent* event)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QPen pen;
    pen.setWidth(lineWidth);
    pen.setColor(lineColor);
    pen.setDashPattern(dashPattern);
    painter.setPen(pen);

    painter.drawRect(0, 0, width, height);
}

void AntLine::updateValue()
{
    if (dashes == lineLen && spaces == lineLen) {
        dashes = 0;
        spaces = 0;
    }

    if (dashes == 0 && spaces < lineLen) {
        spaces = spaces + lineStep;
    }
    else if (spaces == lineLen && dashes < lineLen) {
        dashes = dashes + lineStep;
    }

    dashPattern[0] = dashes;
    dashPattern[1] = spaces;

    update();
}

int AntLine::getLineLen() const
{
    return this->lineLen;
}

int AntLine::getLineWidth() const
{
    return this->lineWidth;
}

int AntLine::getLineStep() const
{
    return this->lineStep;
}

int AntLine::getLineSpeed() const
{
    return this->lineSpeed;
}

QColor AntLine::getLineColor() const
{
    return this->lineColor;
}


QSize AntLine::sizeHint() const
{
    return QSize(100, 100);
}

QSize AntLine::minimumSizeHint() const
{
    return QSize(20, 20);
}

void AntLine::setLineLen(int lineLen)
{
    if (this->lineLen != lineLen) {
        this->lineLen = lineLen;

        dashes = lineLen;
        spaces = lineLen;
        dashPattern.clear();
        for (int i = 0; i < 20; ++i) {
            dashPattern << lineLen;
        }

        update();
    }
}

void AntLine::setLineWidth(int lineWidth)
{
    if (this->lineWidth != lineWidth) {
        this->lineWidth = lineWidth;
        update();
    }
}

void AntLine::setLineStep(int lineStep)
{
    if (this->lineStep != lineStep) {
        this->lineStep = lineStep;
        update();
    }
}

void AntLine::setLineSpeed(int lineSpeed)
{
    if (this->lineSpeed != lineSpeed) {
        this->lineSpeed = lineSpeed;
        update();
    }
}

void AntLine::setLineColor(const QColor& lineColor)
{
    if (this->lineColor != lineColor) {
        this->lineColor = lineColor;
        update();
    }
}
