#include "pinger_mv.h"
#include "main.h"
#include <QTextCodec>
#include <QObject>


void aMainWindow::PingSaid(double ms)
{
	this->plainTextEdit->appendPlainText("th");
	//TODO
}

void aMainWindow::run()
{
	thePinger->setHost(this->lineEdit->text().toAscii().data());
	thePinger->ping();
}

aMainWindow::aMainWindow(QWidget * parent)
{
	setupUi(this);
	connect(pushButton,
		SIGNAL(clicked()),
		this,
		SLOT(run())
		);
}

aMainWindow::~aMainWindow()
{
}