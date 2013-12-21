#include <QtGui/QApplication>
#include "widget.h"

#include <QtGui/QFileDialog>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    Widget w;
	w.resize(640, 480);
    w.show();
	w.setDir(
	QFileDialog::getExistingDirectory());
	return a.exec();
}
