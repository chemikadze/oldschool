#include "box.h"

Box::Box(QWidget * pwdgt) : QGroupBox("QGrBx", pwdgt)
{
	QVBoxLayout * la;
	light=new QCheckBox("Light");
	light->setChecked(true);
	rb1=new QRadioButton("Red");
	rb2=new QRadioButton("Green");
	rb3=new QRadioButton("Blue");
	rb3->setChecked(true);
	exit=new QPushButton("Exit");
	la=new QVBoxLayout();
	la->addWidget(rb1);
	la->addWidget(rb2);
	la->addWidget(rb3);
	la->addWidget(light);
	la->addWidget(exit);
	this->setCheckable(true);
	this->setChecked(false);

	connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(rb1, SIGNAL(clicked()), this, SLOT(changeColor()));
	connect(rb2, SIGNAL(clicked()), this, SLOT(changeColor()));
	connect(rb3, SIGNAL(clicked()), this, SLOT(changeColor()));
	connect(light, SIGNAL(clicked()), this, SLOT(changeColor()));
	connect(this, SIGNAL(clicked()), this, SLOT(changeColor()));
	
	this->setLayout(la);
	
	changeColor();
}

void Box::changeColor()
{
	int lightFactor=light->isChecked() ? 150 : 80;
	QPalette pal;
	if (!isChecked())
	{
		setPalette(exit->palette());
		setAutoFillBackground(true);
		return;
	}
	if (rb1->isChecked())
		pal.setColor(backgroundRole(), QColor(Qt::red).lighter(lightFactor));
	else	
	if (rb2->isChecked())
		pal.setColor(backgroundRole(), QColor(Qt::green).lighter(lightFactor));
	else	
	if (rb3->isChecked())
		pal.setColor(backgroundRole(), QColor(Qt::blue).lighter(lightFactor));
	setPalette(pal);
	setAutoFillBackground(true);
}
