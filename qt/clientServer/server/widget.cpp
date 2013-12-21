#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    len=0;
    QVBoxLayout *la=new QVBoxLayout;
    lbl=new QLabel(tr("<h3>Server</h3>"));
    edit=new QTextEdit;
    la->addWidget(lbl);
    la->addWidget(edit);
    this->setLayout(la);
    servSock=new QTcpServer(this);
    if (!servSock->listen(QHostAddress::Any, 1234))
    {
	QString errMsg=tr("Server unable to open connection with error string \"%1\"").arg(servSock->errorString());
	QMessageBox::critical(this, tr("Error opening port!"), errMsg);
	edit->append(QTime::currentTime().toString("hh:mm:ss ")+errMsg);
    }
    else
    {
	connect(servSock, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));
    }
}

Widget::~Widget()
{
}

void Widget::slotNewConnection()
{
    QTcpSocket *newSock=servSock->nextPendingConnection();
    connect(newSock, SIGNAL(readyRead()), this, SLOT(slotReadSocket()));
    //connect(newSock, SIGNAL(disconnected()), this, SLOT(deleteLater()));
    edit->append(QTime::currentTime().toString("hh:mm:ss")+tr(" Client connected."));
}

void Widget::slotReadSocket()
{
    QTcpSocket *sock = (QTcpSocket*)sender();
    if (!sock) return;

    QDataStream io(sock);
    QByteArray arr;
    QDataStream buf(&arr, QIODevice::WriteOnly);
    QString str;

    for (;;)
    {
	if (sock->bytesAvailable() < sizeof(qint32))
	    break;
	io >> len;

	if (sock->bytesAvailable() < len)
	    break;
	io >> str;

	edit->append(QTime::currentTime().toString("hh:mm:ss ")+tr("Client sent: ")+str);

	buf << (qint32)0 << QTime::currentTime() << str;
	buf.device()->seek(0);
	buf << arr.size()-sizeof(qint32);
	sock->write(arr);
	arr.clear();
    }
}
