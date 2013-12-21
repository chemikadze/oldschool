#include <QtGui>
#include <QtCore>

int main(int argc, char ** argv)
{
	QApplication app(argc, argv);
	QWidget *wgt=new QWidget();
	QVBoxLayout la;
	la.addWidget(new QLabel("label"));
	la.addWidget(new QLabel("label"));
	la.addWidget(new QLabel("label"));
	//la.addWidget(new QPushButton("button"));
	//la.addWidget(new QTableWidget());
	la.setStretch(1, 0);
	la.setStretch(2, 1);
	la.setStretch(3, 2);
	wgt->setLayout(&la);
	delete wgt;
	wgt=new QWidget();
	wgt->setLayout(&la);
	return app.exec();
}
