#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout la;
    nameEdit=new QLineEdit();
    saveButton=new QPushButton(tr("Сохранить"));
    nameEdit->setText(tr("Имя сохраняемого файла"));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    la.addWidget(nameEdit);
    la.addWidget(saveButton);
    this->setLayout(&la);
}

Widget::~Widget()
{

}

void Widget::save()
{
    QPainter p;
    QImage pix(QSize(300,200),QImage::Format_ARGB32);
    p.begin(&pix);
    p.drawEllipse(pix.rect());
    p.end();
    nameEdit->setText(QFileDialog::getSaveFileName());
    pix.save(nameEdit->text(), "PNG", 100);
}
