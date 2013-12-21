#include "settingsbox.h"

SettingsBox::SettingsBox()
{
	QGridLayout *la=new QGridLayout();
	hostLabel=new QLabel(tr("Host adress"));
	hostEdit=new QLineEdit("localhost");
	portLabel=new QLabel(tr("Port"));
	portEdit=new QSpinBox();
	portEdit->setRange(1, 32000);
	ok=new QPushButton(tr("Ok"));
	connect(ok, SIGNAL(clicked()), this, SLOT(accept()));
	cancel=new QPushButton(tr("Cancel"));
	connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
	la->addWidget(hostLabel, 0, 0);
	la->addWidget(hostEdit,  0, 1);
	la->addWidget(portLabel, 1, 0);
	la->addWidget(portEdit,  1, 1);
	la->addWidget(ok, 2, 0);
	la->addWidget(cancel, 2, 1);
	setLayout(la);
	portEdit->setValue(1234);
	setModal(true);
}

QString SettingsBox::getHost()
{
	return hostEdit->text();
}

qint16 SettingsBox::getPort()
{
	return portEdit->value();
}

void SettingsBox::setHost(const QString& h)
{
	hostEdit->setText(h);
}

void SettingsBox::setPort(qint16 p)
{
	portEdit->setValue(p);
}
