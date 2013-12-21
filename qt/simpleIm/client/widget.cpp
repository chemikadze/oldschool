#include "widget.h"

Widget::Widget(QWidget *parent)
	: QMainWindow(parent)
{
	len=0;
	QVBoxLayout *la=new QVBoxLayout;
	QVBoxLayout *laL=new QVBoxLayout,
				*laR=new QVBoxLayout;

	sock=new QTcpSocket(this);
	io.setDevice(sock);
	connect(sock, SIGNAL(readyRead()), this, SLOT(processData()));
	connect(sock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(sockError(QAbstractSocket::SocketError)));
	connect(sock, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(stateChanged(QAbstractSocket::SocketState)));
	lbl=new QLabel(tr("<h3>Simple IM client</h3>"));
	split=new QSplitter;
	connButton=new QPushButton(tr("Connect"));
	connButton->setCheckable(true);
	connect(connButton, SIGNAL(clicked(bool)), this, SLOT(setConnectionState(bool)));
	nameEdit=new QLineEdit(tr("Username"));
	setWindowTitle(nameEdit->text()+tr(" - client"));
	connect(nameEdit, SIGNAL(returnPressed()), this, SLOT(changeName()));
	msgEdit=new QLineEdit();
	connect(msgEdit, SIGNAL(returnPressed()), this, SLOT(sendMessage()));
	history=new QTextEdit();
	history->setAcceptRichText(true);
	history->setReadOnly(true);
	contactList=new QListWidget();
	laR->addWidget(connButton);
	laR->addWidget(contactList);
	laR->setMargin(0);
	right=new QWidget;
	right->setLayout(laR);
	laL->addWidget(nameEdit);
	laL->addWidget(history);
	laL->setMargin(0);
	left=new QWidget;
	left->setLayout(laL);
	la->addWidget(lbl);
	split->addWidget(left);
	split->addWidget(right);
	split->setStretchFactor(0, 3);
	split->setStretchFactor(1, 1);
	la->addWidget(split, 5);
	la->addWidget(msgEdit);
	host=tr("localhost");
	port=1234;
	mainWidget=new QWidget;
	mainWidget->setLayout(la);
	setCentralWidget(mainWidget);
	fileMenu=menuBar()->addMenu(tr("Program"));
	connAct=fileMenu->addAction(tr("Connect"));
	connAct->setCheckable(true);
	connect(connAct, SIGNAL(triggered(bool)), this, SLOT(setConnectionState(bool)));
	connect(connAct, SIGNAL(triggered(bool)), connButton, SLOT(setChecked(bool)));
	connect(connButton, SIGNAL(clicked(bool)), connAct, SLOT(setChecked(bool)));
	settingsAct=fileMenu->addAction(tr("Settings"), this, SLOT(settings()));
	fileMenu->addSeparator();
	exitAct=fileMenu->addAction(tr("Exit"), this, SLOT(close()));
	helpMenu=menuBar()->addMenu(tr("About"));
	aboutAct=helpMenu->addAction(tr("About Simple IM client"), this, SLOT(about()));
}

Widget::~Widget()
{

}

void Widget::setConnectionState(bool b)
{
    if (b)
		sock->connectToHost(host, port);
    else
		sock->close();
}

void Widget::sockError(QAbstractSocket::SocketError err)
{
    history->append(tr("<b>Error: %1.</b>").arg(sock->errorString()));
}

void Widget::stateChanged(QAbstractSocket::SocketState stat)
{
    QByteArray *data=new QByteArray;
    QDataStream ds(data, QIODevice::WriteOnly);
    switch (stat)
    {
	case (QAbstractSocket::UnconnectedState):
	    history->append(tr("<b>%1</b>").arg(tr("Disconnected.")));
	    connButton->setChecked(false);
		connAct->setChecked(false);
	    break;
	case (QAbstractSocket::ConnectedState):
	    history->append(tr("<b>%1</b>").arg(tr("Connected.")));

	    ds << qint32(0) << qint32(ImCommands::ImName) << nameEdit->text();
	    ds.device()->seek(0);
	    ds << qint32(data->size());
	    sock->write(*data);
	    data->clear();

	    ds.device()->seek(0);
	    ds << qint32(0) << qint32(ImCommands::ImList);
	    ds.device()->seek(0);
	    ds << qint32(data->size());
	    sock->write(*data);
	    delete data;
	    break;
	 default:;
    }
}

void Widget::processData()
{
    QString s, s1;
    qint32 command;
    for (;;)
    {
	if (!len)
	{
	    if (sock->bytesAvailable() < sizeof(qint32))
		break;
	    else
		io >> len;
	}

	if (sock->bytesAvailable() < len-sizeof(qint32))
	    break;
	else
	{
	    QStringList list;
	    QList <QListWidgetItem*> items;
	    io >> command;
	    switch (command)
	    {
		case (ImCommands::ImExit):
		    io >> s;
		    history->append(tr("User <b>%1</b> is now offline.").arg(s));
		    items=contactList->findItems(s, Qt::MatchContains | Qt::MatchFixedString);
		    delete contactList->takeItem(contactList->row(items.first()));
		    break;
		case (ImCommands::ImServMesg):
		    io >> s;
		    history->append(tr("<b>Server message:</b> %1").arg(s));
		    break;
		case (ImCommands::ImName):
			io >> s >> s1;
		    if (s!=nameEdit->text())
		    {
				if (!s.isEmpty())
				{
					items=contactList->findItems(s, Qt::MatchContains | Qt::MatchFixedString);
					if (items.size())
					{
						items.first()->setText(s1);
						history->append(tr("Username <b>%1</b> now is <b>%2</b>").arg(s, s1));
					}
				}
				else
				{
					contactList->addItem(s1);
					history->append(tr("User <b>%1</b> is now online.").arg(s1));
				}
		    }
		    else
			{
				history->append(tr("Can not change name. Revert to <b>%1</b>").arg(s1));
				items=contactList->findItems(s, Qt::MatchContains | Qt::MatchFixedString);
				if (items.size())
				{
					items.first()->setText(s1);
				}
				nameEdit->setText(s1);
				setWindowTitle(nameEdit->text()+tr(" - client"));
		    }
		    break;

		case (ImCommands::ImMesg):
			io >> s >> s1;
		    history->append(tr("<b>%1:</b> %2").arg(s,s1));
		    break;

		case (ImCommands::ImList):
		    io >> list;
		    contactList->clear();
		    contactList->addItems(list);
		    break;
	    }
	    len=0;
	}
    }
}

void Widget::sendMessage()
{
    QByteArray *data=new QByteArray;
    QDataStream ds(data, QIODevice::WriteOnly);
    ds << qint32(0) << qint32(ImCommands::ImMesg) << msgEdit->text();
    ds.device()->seek(0);
    ds << qint32(data->size());
    sock->write(*data);
    delete data;
    msgEdit->clear();
}

void Widget::changeName()
{
	QByteArray *data=new QByteArray;
    QDataStream ds(data, QIODevice::WriteOnly);
    ds << qint32(0) << qint32(ImCommands::ImName) << nameEdit->text();
    ds.device()->seek(0);
    ds << qint32(data->size());
    sock->write(*data);
	setWindowTitle(nameEdit->text()+tr(" - client"));
    delete data;
}

void Widget::settings()
{
	SettingsBox *box=new SettingsBox;
	box->setPort(port);
	box->setHost(host);
	if (box->exec()==QDialog::Accepted)
	{
		host=box->getHost();
		port=box->getPort();
	}
	delete box;
}

void Widget::about()
{
	QMessageBox::about(this, tr("Simple IM client"), tr("<h3>Simple IM client</h3>IRC-like instant messenger by ChemiKadze (<a href=\"mailto:chemikadze@gmail.com\">chemikadze@gmail.com</a>).<br>Based on Qt 4.5."));
}
