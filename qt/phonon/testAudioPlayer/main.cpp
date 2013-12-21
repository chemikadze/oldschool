#include <QtGui/QApplication>
#include "aplayer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	APlayer player;

	player.show();

    return a.exec();
}
