#include "imuser.h"

ImUser::ImUser()
{
	len=0;
	sock=NULL;
}

ImUser::~ImUser()
{
	delete sock;
}

void ImUser::disconnectUser()
{
	io.unsetDevice();
	if (sock->isOpen())
		sock->close();
	emit disconnectedUser();
}

void ImUser::readData()
{
	if (io.device()!=NULL && io.device()->openMode()==QIODevice::ReadWrite)
	for (;;)
	{
		if  (len==0)
			if (sock->bytesAvailable() < sizeof(qint32))
				break;
			else
				io >> len;
		else
			if (sock->bytesAvailable() < len-sizeof(qint32))
				break;
			else
			{
				len=0;
				emit incomingData();
			}
	}
}

void ImUser::setSocket(QTcpSocket *newSock)
{
    if (sock!=NULL)
    {
	QObject::disconnect(sock, SIGNAL(readyRead()), this, SLOT(readData()));
	QObject::disconnect(sock, SIGNAL(disconnected()), this, SIGNAL(disconnectUser()));
	sock->close();
	delete sock;
    }

    sock=newSock;
    io.setDevice(sock);
    QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(readData()));
    QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(disconnectUser()));
}

QTcpSocket* ImUser::socket()
{
	return sock;
}
