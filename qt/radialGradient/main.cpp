#include <QtCore>
#include <QtGui>
#include <QtCore>
#include "gradient.h"

int main(int argc, char **argv)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QApplication app(argc, argv);

	QPaintWidget wgt;
	QSlider xSlider, ySlider;
	QGridLayout la;

	xSlider.setOrientation(Qt::Horizontal);
	ySlider.setOrientation(Qt::Vertical);
	ySlider.setInvertedAppearance(true);	

	xSlider.setMinimum(0);
	ySlider.setMinimum(0);
	xSlider.setMaximum(100);
	ySlider.setMaximum(100);

	QObject::connect(&xSlider, SIGNAL(valueChanged(int)), &wgt, SLOT(moveX(int)));
	QObject::connect(&ySlider, SIGNAL(valueChanged(int)), &wgt, SLOT(moveY(int)));
	QObject::connect(&wgt, SIGNAL(movedX(int)), &xSlider, SLOT(setValue(int)));
	QObject::connect(&wgt, SIGNAL(movedY(int)), &ySlider, SLOT(setValue(int)));


	xSlider.setValue(50);
	ySlider.setValue(50);

	la.addWidget(&xSlider, 1, 0, 1, 1);
	la.addWidget(&ySlider, 0, 1, 1, 1);
	wgt.setLayout(&la);
	
	wgt.show();

	return app.exec();
}
