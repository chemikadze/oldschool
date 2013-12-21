#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include "graphwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

	QPushButton *start;
	QSpinBox *box;
	GraphWidget *graph;
	QTimer *timer;
public slots:
	void slotTimer();
	void slotStart();

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
