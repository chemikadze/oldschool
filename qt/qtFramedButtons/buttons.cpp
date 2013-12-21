#include "buttons.h"

Buttons::Buttons(QWidget *parent/*=0*/):QPushButton(parent)
{
	b_success=true;
}

Buttons::Buttons(int size, int count/*=1*/, QColor first/*=Qt::black*/, QColor last/*=Qt::red*/)
{
	b_success=createButtons(size, count, first, last);
}

bool Buttons::createButtons(int size, int count/*=1*/, QColor first/*=Qt::black*/, QColor last/*=Qt::red*/)
{
	if ( count==0 || size<0 || size/count<=1 )
	{
		QMessageBox::warning(this, tr("Неверные данные"), tr("Расстояние между кнопками должно быть больше 1 пиксела!"));
		return false;
	}

	this->resize(size, size);

	/*QLinearGradient *gradient=new QLinearGradient(0, 0, count, 1);
	QImage *img=new QImage(QSize(count, 1), QImage::Format_RGB32);
	QPainter* painter=new QPainter;
	gradient->setColorAt(0, first);
//	gradient->setColorAt(0.5, Qt::blue);
	gradient->setColorAt(1, last);
	painter->begin(img);
	painter->setBrush(QBrush(*gradient));
	painter->drawRect(0, 0, img->height(), img->width());
	painter->end();
	delete painter;
	delete gradient;*/

	int sizeStep=size/count/2;

	QPalette *palet=new QPalette;
	int i;
	*palet=this->palette();
	palet->setColor(this->backgroundRole(), first);
	this->setPalette(*palet);
	buttonStack.push(this);
	for (i=1; i<count; i++)
	{
		QPushButton *btn=new QPushButton(buttonStack.last());
		if (i!=(count-1))
		    palet->setColor(btn->backgroundRole(), QColor(round((first.red()+double(i)/double(count-i-1)*last.red())/(1+double(i)/double(count-i-1))),
								  round((first.green()+double(i)/double(count-i-1)*last.green())/(1+double(i)/double(count-i-1))),
								  round((first.blue()+double(i)/double(count-i-1)*last.blue())/(1+double(i)/double(count-i-1)))));
		else
		{
		    palet->setColor(btn->backgroundRole(), last);
		}
		btn->setPalette(*palet);
		btn->move(sizeStep, sizeStep);
		btn->resize(buttonStack.last()->width()-sizeStep*2, buttonStack.last()->height()-sizeStep*2);
		buttonStack.push(btn);
	}
	return true;
}

void Buttons::closeEvent(QCloseEvent *event)
{
	Q_UNUSED(event)
	emit closed();
}

bool Buttons::success()
{
	return b_success;
}

Buttons::~Buttons()
{
	//close();
	while (buttonStack.size()!=1)
		delete buttonStack.pop();
}
