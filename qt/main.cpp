#include <QtGui>
#include <QtCore>

int main(int argc, char** argv)
{
	QApplication a(argc, argv);

	QWidget w;
	QPalette palette = w.palette();
	palette.setColor(QPalette::Background, Qt::white);
	w.setPalette(palette);
	w.setWindowFlags(w.windowFlags() & Qt::FramelessWindowHint);
	w.show();

	return a.exec();
}
