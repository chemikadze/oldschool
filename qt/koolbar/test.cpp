#include <QtGui/QMainWindow>
#include <QtGui/QApplication>
#include "src/koolbar.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	app.setOrganizationName("chemikadze");
	app.setApplicationName("Koolbar test");

	QMainWindow w;
	KoolBar* b1 = new KoolBar("My koolbar", &w);
	b1->addAction("One");
	b1->addAction("Two");

	KoolBar* b2 = new KoolBar("My koolbar 2", &w);
	b2->addAction("Three");
	b2->addAction("Four");

	w.addToolBar(b1);
	w.addToolBar(b2);
	b1->init("one");
	b2->init("two");
	w.show();

	app.exec();
}
