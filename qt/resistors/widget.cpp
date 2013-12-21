#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
	doubleValidator = new QDoubleValidator(this);
	ui->inputEdit1->setValidator(doubleValidator);
	ui->inputEdit2->setValidator(doubleValidator);
	connect(ui->pushButton, SIGNAL(clicked()), SLOT(calculate()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate()
{
	double first, second, answer;
	bool ok = true;
	first = ui->inputEdit1->text().toDouble(&ok);
	if (ok)
		second = ui->inputEdit2->text().toDouble(&ok);
	if (!ok)
	{
		ui->outputEdit->setText(tr("Введите данные"));
		return;
	}
	if (ui->parallel->isChecked())
		answer = (first*second)/(first+second);
	else
		answer = first+second;
	ui->outputEdit->setText(QString::number(answer));
}
