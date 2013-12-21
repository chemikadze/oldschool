#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>

class Widget : public QLabel
{
    Q_OBJECT
    QByteArray arr;
    QBuffer buf;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
