#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
	QGridLayout *la=new QGridLayout;
	start=new QPushButton("Start");
	box=new QSpinBox;
	box->setValue(6);
	graph=new GraphWidget;
	timer=new QTimer(this);
	la->addWidget(graph, 0, 0, 1, 2);
	la->addWidget(box, 1, 0);
	la->addWidget(start, 1, 1);
	setLayout(la);
	graph->setRange(box->value());
	connect(box, SIGNAL(valueChanged(int)), graph, SLOT(setRange(int)));
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimer()));
	connect(start, SIGNAL(clicked()), this, SLOT(slotStart()));
	srand(time(NULL));
}

Widget::~Widget()
{

}

void Widget::slotTimer()
{
	graph->addItem(double(rand())/double(RAND_MAX)*graph->range());
}

void Widget::slotStart()
{
	if (timer->isActive())
		timer->stop();
	else
	{
		graph->clear();
		timer->start(100);
	}
}

