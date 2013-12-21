#ifndef IMSERVER_H
#define IMSERVER_H

#include <QHash>
#include <QtNetwork>
#include "imuser.h"
#include "imcommands.h"

class ImServer:public QObject
{
	Q_OBJECT

	QTcpServer *server;
	QHash <QString, ImUser*> users;
	QSet <ImUser*> loginUsers;
	qint16 n_port;

signals:
	void usersChanged();

public slots:
	void deleteUser();
	void addUser();
	void processData();

	qint16 port();
	void setPort(qint16 p);

	void close();
	void open();

	void sendServerMessage(const QString &str);

public:
	QStringList usersList();
    ImServer();
	ImServer(int newPort);
	~ImServer();
};

#endif // IMSERVER_H
