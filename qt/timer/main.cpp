#include <QtGui>
#include <QtCore>
#include "timer.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	QWidget wgt;
	QMyClock clock;
	
	QGridLayout la;
	QPushButton start(QObject::tr("Старт")), stop(QObject::tr("Стоп/Ноль"));	
	QLCDNumber lcd;

	QObject::connect(&start, SIGNAL(clicked()), &clock, SLOT(startTimer()));
	QObject::connect(&stop, SIGNAL(clicked()), &clock, SLOT(stopTimer()));
	QObject::connect(&clock, SIGNAL(timeChanged(int)), &lcd, SLOT(display(int)));

	la.addWidget(&clock, 0, 0, 2, 2);
	la.addWidget(&lcd, 2, 0, 1, 2);
	la.addWidget(&start, 3, 0);
	la.addWidget(&stop, 3, 1);
	
	wgt.setLayout(&la);
	wgt.setWindowTitle(QObject::tr("Таймер"));
	wgt.show();

	app.exec();
}

