#include <QApplication>
#include <QTextCodec>

#include "main.h"

aPinger * thePinger;
aMainWindow * theMainWindow;


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextCodec * codec=QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);
	thePinger=new aPinger();
	
	theMainWindow=new aMainWindow();
	theMainWindow->setWindowTitle(QMainWindow::tr("Пингер v 0.0.1"));
	theMainWindow->show();

	return app.exec();
}

