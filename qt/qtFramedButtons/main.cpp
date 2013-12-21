#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QApplication a(argc, argv);
	mainWindow w;
	w.show();
	return a.exec();
}
