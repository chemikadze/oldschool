#include <QObject>
#include <QWidget>
#include "ui_pinger_mv.h"

#ifndef PINGER_MV_H
#define PINGER_MV_H

class aMainWindow: public QMainWindow, private Ui_MainWindow
{
	Q_OBJECT
public:
	void PingSaid(double ms);
	aMainWindow(QWidget * parent=0);
	~aMainWindow();
public slots:
	void run();
};

#endif