#include <QtCore>
#include <QtGui>
#include <cmath>

class QPaintWidget: public QWidget
{
 protected:
	void paintEvent(QPaintEvent *event)
	{
		QPainter p(this);
		QLinearGradient grad;

		grad.setColorAt(0, Qt::black);
		grad.setColorAt(0.5, Qt::gray);
		grad.setColorAt(1, Qt::red);
		
		p.setBrush(grad);
		//p.drawRect(0, 0, height(), width());
		p.drawRect(rect());
		p.end();

	}
};

int main(int argc, char **argv)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QApplication app(argc, argv);

	QPaintWidget wgt;

	wgt.show();

	return app.exec();
}
