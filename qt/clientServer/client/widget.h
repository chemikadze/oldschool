#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtNetwork>

class Widget : public QWidget
{
    Q_OBJECT

    QTcpSocket *sock;
    QLabel *lbl;
    QTextEdit *edit;
    QLineEdit *lineEdit;
    qint32 len;
private slots:
    void slotReadSocket();
    void slotSendData();
    void slotError(QAbstractSocket::SocketError err);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
