#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtNetwork>
#include "imcommands.h"
#include "settingsbox.h"

class Widget : public QMainWindow
{
    Q_OBJECT

	int len;
	qint16 port;
	QString host;
	QWidget *mainWidget;
	QLabel *lbl;
	QLineEdit *nameEdit;
	QPushButton *connButton;
	QTextEdit *history;
	QLineEdit *msgEdit;
	QListWidget *contactList;
	QTcpSocket *sock;
	QSplitter *split;
	QWidget *left;
	QWidget *right;
	QDataStream io;
	QMenu *fileMenu;
	QAction *connAct;
	QAction *settingsAct;
	QAction *exitAct;
	QMenu *helpMenu;
	QAction *aboutAct;
public slots:
	void settings();
	void about();
	void sendMessage();
	void changeName();
	void processData();
	void setConnectionState(bool b);
	void sockError(QAbstractSocket::SocketError err);
	void stateChanged(QAbstractSocket::SocketState stat);
public:
	Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
