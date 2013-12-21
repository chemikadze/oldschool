#ifndef IMUSER_H
#define IMUSER_H

#include <QString>
#include <QDataStream>
#include <QTcpSocket>

class ImUser: public QObject
{
	Q_OBJECT

	QByteArray inData;
	qint32 len;
	QTcpSocket *sock;

signals:
	void disconnectedUser();
	void incomingData();

public slots:
	void disconnectUser();
	void readData();

public:
	QString userName;
	QDataStream io;

	QTcpSocket* socket();
	void setSocket(QTcpSocket* newSock);

    ImUser();
	~ImUser();
};

#endif // IMUSER_H
