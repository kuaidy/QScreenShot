#pragma once

#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QPainter>

class AntLine  : public QWidget
{
	Q_OBJECT

public:
	AntLine(QWidget* parent);
	~AntLine();

	//线条长度
	int lineLen;
	//线条宽度
	int lineWidth;
	//每次移动的步长
	int lineStep;
	//线条流动的速度
	int lineSpeed;
	//线条颜色
	QColor lineColor = QColor(0,0,0);

	int dashes;
	int spaces;
	//
	QVector<double> dashPattern;
	//更新定时器
	QTimer* timer;

protected:
	void paintEvent(QPaintEvent* event);

private slots:
	void updateValue();

public:
	int getLineLen()const;
	int getLineWidth()const;
	int getLineStep()const;
	int getLineSpeed()const;

	QColor getLineColor()const;
	QSize sizeHint()const;
	QSize minimumSizeHint()const;

public Q_SLOTS:
	//设置线条长度
	void setLineLen(int lineLen);
	//设置线条宽度
	void setLineWidth(int lineWidth);
	//设置线条步长
	void setLineStep(int lineStep);
	//设置线条速度
	void setLineSpeed(int lineSpeed);
	//设置线条颜色
	void setLineColor(const QColor& lineColor);
};
