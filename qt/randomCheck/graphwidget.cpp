#include "graphwidget.h"

GraphWidget::GraphWidget()
{
	sum=0.0L;
	m_range=0;
	counts.resize(0);
}

void GraphWidget::paintEvent ( QPaintEvent * event )
{
	QPainter *p=new QPainter(this);
	int i;
	p->setPen(QColor::fromRgb(200, 0, 0));
	p->setBrush(QBrush(QColor::fromRgb(255, 0, 0)));
	for (i=0; i<counts.size(); i++)
	{
		p->drawRect(double(width())/(counts.size()*2+1)*(i*2+1), (height()-5)-(height()-10)*double(counts[i])/sum, double(width())/(counts.size()*2+1), (height()-10)*double(counts[i])/sum);
	}
	p->end();
	delete p;
}

void GraphWidget::setRange(int newRange)
{
	m_range=newRange;
	counts.resize(m_range);
	clear();
	repaint();
}

int GraphWidget::range()
{
	return m_range;
}

void GraphWidget::clear()
{
	counts.fill(0);
	sum=0.0L;
	repaint();
}

void GraphWidget::addItem(int val)
{
	sum++;
	counts[val]++;
	repaint();
}
