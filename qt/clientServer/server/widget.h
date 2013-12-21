#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtNetwork>

class Widget : public QWidget
{
    Q_OBJECT

    QTcpServer *servSock;
    QLabel *lbl;
    QTextEdit *edit;
    qint32 len;
private slots:
    void slotNewConnection();
    void slotReadSocket();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
