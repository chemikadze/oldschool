#include "imserver.h"

ImServer::ImServer()
{
	server=new QTcpServer();
	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(addUser()));
	n_port=1234;
}

ImServer::ImServer(int newPort)
{
	server=new QTcpServer();
	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(addUser()));
	n_port=newPort;
	server->listen(QHostAddress::Any, n_port);
}

ImServer::~ImServer()
{
	delete server;
	foreach(ImUser* user, users)
	{
		delete user;
	}
}

void ImServer::deleteUser()
{
	ImUser* user=qobject_cast<ImUser*>(sender());
	if (user==NULL)
		return;;
	QString s;
	QByteArray *data=new QByteArray;
	QDataStream io(data, QIODevice::WriteOnly);

	if (!user->userName.isEmpty())
	{
	    s=user->userName;
	    users.take(s)->deleteLater();

	    io << qint32(0) << qint32(ImCommands::ImExit) << s;
	    io.device()->seek(0);
	    io << qint32(data->size());

	    foreach(ImUser *iuser, users)
	    {
			if (iuser!=user)
				iuser->socket()->write(*data);
	    }
	    emit usersChanged();
	}
	else
	{
	    loginUsers.remove(user);
	    user->deleteLater();
	}
}

void ImServer::addUser()
{
	ImUser* user=new ImUser();
	user->setSocket(server->nextPendingConnection());
	QObject::connect(user, SIGNAL(incomingData()), this, SLOT(processData()));
	QObject::connect(user, SIGNAL(disconnectedUser()), this, SLOT(deleteUser()));
	loginUsers.insert(user);
}

void ImServer::processData()
{
	ImUser* user=qobject_cast<ImUser*>(sender());
	if (!user)
	    return;
	QByteArray* data=new QByteArray;
	QDataStream ds(data, QIODevice::WriteOnly);
	QString s;
	qint32 command;
	user->io >> command;
	switch (command)
	{
	    case (ImCommands::ImName):
		user->io >> s;
		if (users.contains(s))
		{/*
		    ds << qint32(0) << qint32(ImCommands::ImServMesg) << tr("Username \'%1\' is in use now.").arg(s);
		    ds.device()->seek(0);
		    ds << qint32(data->size());
		    user->socket()->write(*data);
		    data->clear();
		    ds.device()->seek(0);*/
		    if (user->userName.isEmpty())
		    {
				user->disconnectUser();
		    }
		    else
		    {
				ds << qint32(0) << qint32(ImCommands::ImName) << s << user->userName;
				ds.device()->seek(0);
				ds << qint32(data->size());
				user->socket()->write(*data);
		    }
		    delete data;
		    emit usersChanged();
		    return;
		    break;
		}
		else
		{
		    if (!user->userName.isEmpty())
				users.remove(user->userName);
		    else
				loginUsers.remove(user);
		    users.insert(s, user);

		    ds << qint32(0) << qint32(ImCommands::ImName) << user->userName << s;
		    ds.device()->seek(0);
		    ds << qint32(data->size());
		    user->userName=s;
		    emit usersChanged();
		}
		break;

	    case (ImCommands::ImExit):
		ds << qint32(0) << qint32(ImCommands::ImExit) << user->userName;
		ds.device()->seek(0);
		ds << qint32(data->size());
		user->disconnect();
		break;

	    case (ImCommands::ImMesg):
		user->io >> s;
		ds << qint32(0) << qint32(ImCommands::ImMesg) << user->userName << s;
		ds.device()->seek(0);
		ds << qint32(data->size());
		break;

	    case (ImCommands::ImList):
		ds << qint32(0) << qint32(ImCommands::ImList) << usersList();
		ds.device()->seek(0);
		ds << qint32(data->size());
		user->socket()->write(*data);
		delete data;
		return;
		break;
	}
	foreach(ImUser* iuser, users)
	{
	    if ( command==ImCommands::ImName | command==ImCommands::ImMesg | iuser!=user)
	    {
			iuser->socket()->write(*data);
	    }
	}
	delete data;
	user->readData();
}

qint16 ImServer::port()
{
	return n_port;
}

void ImServer::setPort(qint16 p)
{
	n_port=p;
}

void ImServer::open()
{
	if (!server->isListening())
		server->listen(QHostAddress::Any, n_port);
}

void ImServer::close()
{
	server->close();
}

QStringList ImServer::usersList()
{
	return users.keys();
}

void ImServer::sendServerMessage(const QString &str)
{
    QByteArray *data=new QByteArray;
    QDataStream ds(data, QIODevice::WriteOnly);
    ds << qint32(0) << qint32(ImCommands::ImServMesg) << str;
    ds.device()->seek(0);
    ds << qint32(data->size());
    foreach (ImUser* user, users)
		user->socket()->write(*data);
    delete data;
}
