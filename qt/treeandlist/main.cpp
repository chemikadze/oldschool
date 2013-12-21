#include <QtCore>
#include "tree.h"

int main(int argc, char **argv)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	QApplication app(argc, argv);
	TAL * tal;

	tal=new TAL();
	tal->show();

	return app.exec();
}
