#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QDoubleValidator>

namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
	QDoubleValidator *doubleValidator;
private slots:
	void calculate();
};

#endif // WIDGET_H
