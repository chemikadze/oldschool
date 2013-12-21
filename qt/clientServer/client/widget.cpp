#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("client"));
    len=0;
    QVBoxLayout *la=new QVBoxLayout;
    lbl=new QLabel(tr("<h3>Client</h3>"));
    edit=new QTextEdit;
    lineEdit=new QLineEdit;
    la->addWidget(lbl);
    la->addWidget(edit);
    la->addWidget(lineEdit);
    this->setLayout(la);
    sock=new QTcpSocket(this);
    connect(sock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
    sock->connectToHost("localhost", 1234);
    connect(sock, SIGNAL(readyRead()), this, SLOT(slotReadSocket()));
    connect(lineEdit, SIGNAL(returnPressed()), this, SLOT(slotSendData()));
}

Widget::~Widget()
{
}

void Widget::slotReadSocket()
{
    QDataStream io(sock);
    QString str;
    QTime time;

    for (;;)
    {
	if (sock->bytesAvailable() < sizeof(qint32))
	    break;
	io >> len;

	if (sock->bytesAvailable() < len)
	    break;
	io >> time >> str;

	edit->append(time.toString("hh:mm:ss ")+tr("Server response: ")+str);
    }
}

void Widget::slotSendData()
{
    QByteArray arr;
    QDataStream io(&arr, QIODevice::WriteOnly);
    io << (qint32)0 << lineEdit->text();
    io.device()->seek(0);
    io << arr.size()-sizeof(qint32);
    sock->write(arr);
    QFile fil("file.dat");
    fil.open(QFile::WriteOnly);
    fil.write(arr);
    fil.close();
    edit->append(QTime::currentTime().toString("hh:mm:ss ")+lineEdit->text());
    lineEdit->clear();
}

void Widget::slotError(QAbstractSocket::SocketError err)
{
    QString errMsg=tr("Client can not connect to server with error string \"%1\"").arg(sock->errorString());
    QMessageBox::critical(this, tr("Error connecting to server!"), errMsg);
    edit->append(QTime::currentTime().toString("hh:mm:ss ")+errMsg);
}
