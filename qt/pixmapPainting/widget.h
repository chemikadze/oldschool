#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>

class Widget : public QWidget
{
    Q_OBJECT
    QLineEdit *nameEdit;
    QPushButton *saveButton;
public slots:
    void save();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
