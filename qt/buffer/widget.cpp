#include "widget.h"

Widget::Widget(QWidget *parent)
    : QLabel(parent)
{
    buf.setBuffer(&arr);
    buf.open(QIODevice::ReadWrite);
    buf.write("qwerty");
    //buf.seek(0);
    buf.write("asdfgh");
    buf.close();
    this->setText(QString(arr));
}

Widget::~Widget()
{

}
