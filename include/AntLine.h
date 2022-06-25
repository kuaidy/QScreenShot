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

	//��������
	int lineLen;
	//�������
	int lineWidth;
	//ÿ���ƶ��Ĳ���
	int lineStep;
	//�����������ٶ�
	int lineSpeed;
	//������ɫ
	QColor lineColor = QColor(0,0,0);

	int dashes;
	int spaces;
	//
	QVector<double> dashPattern;
	//���¶�ʱ��
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
	//������������
	void setLineLen(int lineLen);
	//�����������
	void setLineWidth(int lineWidth);
	//������������
	void setLineStep(int lineStep);
	//���������ٶ�
	void setLineSpeed(int lineSpeed);
	//����������ɫ
	void setLineColor(const QColor& lineColor);
};
