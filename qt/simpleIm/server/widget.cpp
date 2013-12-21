#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
	port=1234;
	QGridLayout *la=new QGridLayout;
	capt=new QLabel(tr("<h3>IRC-like Server</h3>"));
	listOnline=new QListWidget();
	openButton=new QPushButton(tr("Connect"));
	openButton->setCheckable(true);
	openButton->setChecked(true);
	msgEdit=new QLineEdit;
	portBox=new QSpinBox;
	portBox->setRange(0, 32000);
	portBox->setValue(port);
	la->addWidget(capt, 0, 0, 1, 2);
	la->addWidget(listOnline, 1, 0, 1, 2);
	la->addWidget(openButton, 2, 0);
	la->addWidget(portBox, 2, 1);
	la->addWidget(msgEdit, 3, 0, 1, 2);
	setLayout(la);
	server=new ImServer(1234);
	connect(openButton, SIGNAL(clicked(bool)), this, SLOT(setServerState(bool)));
	connect(server, SIGNAL(usersChanged()), this, SLOT(setListItems()));
	connect(msgEdit, SIGNAL(returnPressed()), this, SLOT(sendServerMessage()));
}

Widget::~Widget()
{

}

void Widget::setServerState(bool b)
{
	portBox->setReadOnly(true);
	port=portBox->value();
	if (b)
	{
		server->open();

	}
	else
	{
		server->close();
	}
}


void Widget::setListItems()
{
	listOnline->clear();
	listOnline->addItems(server->usersList());
}

void Widget::sendServerMessage()
{
    server->sendServerMessage(msgEdit->text());
}
