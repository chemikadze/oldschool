#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStringList>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include "imserver.h"

class Widget : public QWidget
{
    Q_OBJECT

	qint32 port;
	QLabel *capt;
	QListWidget *listOnline;
	QPushButton *openButton;
	QLineEdit *msgEdit;
	QSpinBox *portBox;
	ImServer *server;
public slots:
	void setServerState(bool b);
	void setListItems();
	void sendServerMessage();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
