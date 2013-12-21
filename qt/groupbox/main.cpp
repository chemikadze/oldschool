#include <QtCore>
#include "box.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Box * mw;
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	mw=new Box();
	mw->setWindowTitle(QObject::tr("Акошка с цвитами"));
	mw->show();

	return app.exec();
}
