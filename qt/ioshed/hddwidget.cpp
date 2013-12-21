#include "hddwidget.h"
#include <QtGui/QPainter>
#include <QtCore/QTime>
#include <cmath>

HddWidget::HddWidget(QWidget* parent /*=NULL*/) : QWidget(parent)
{
	m_currentI = 0;
	m_cylSwitchTime = 7;
	timer.setInterval(500);
	connect(&timer, SIGNAL(timeout()), SLOT(timerTimeout()));
	m_repaintTimerId = startTimer(1000/24);

	setCylinderCount(1);
}

void HddWidget::timerEvent(QTimerEvent*)
{
	repaint();
}

void HddWidget::setVector(QVector <int> v)
{
	m_vector = v;
	m_currentI = 0;
	if (v.size())
		m_currentCyl = v.first();
	else
		m_currentCyl = 0;
}

void HddWidget::play()
{
	repaint();
	if (!m_repaintTimerId)
		m_repaintTimerId = startTimer(1000/24);
	timer.start(m_cylSwitchTime);
}

void HddWidget::pause()
{
	timer.stop();
	killTimer(m_repaintTimerId);
	m_repaintTimerId = 0;
}

void HddWidget::stop()
{
	timer.stop();
	killTimer(m_repaintTimerId);
	m_repaintTimerId = 0;
	m_currentI = 0;
}

void HddWidget::timerTimeout()
{
	static int reading = false;
	if (!m_vector.isEmpty())
	{
		if (m_currentI == m_vector.size())
		{
			m_currentI = 0;
			m_currentCyl = m_vector.first();
			timer.setInterval(m_cylSwitchTime);
		}
		else if (m_currentCyl == m_vector[m_currentI])
		{
			if (reading)
			{
				++m_currentI;
				if (m_currentI == m_vector.size())
					timer.setInterval(1000);
				else
					timer.setInterval(m_cylSwitchTime);
			}
			else
			{
				timer.setInterval(150);
			}
			reading = !reading;
		}
		else
		{
			if (m_currentCyl > m_vector[m_currentI])
				--m_currentCyl;
			else
				++m_currentCyl;
			timer.setInterval(m_cylSwitchTime);
		}
	}
}

void HddWidget::translateCoords(QPainter &p)
{
	int dx = 0, dy = 0;
	double w_to_h = double(width()) / double(height());
	if (w_to_h > 2.0/3.0)
	{
		dx = double(height()) * (w_to_h - 2.0/3.0) /
			 (double(height()) / 310.0);
	}
	else if (w_to_h < 2.0/3.0)
	{
		dy = double(width()) * (1/w_to_h - 3.0/2.0) /
			 (double(width()) / 210.0);
	}

	p.scale(width()/(210.0+dx), height()/(310.0+dy));
	p.translate(5+dx/2, 5+dy/2);

}

void HddWidget::paintEvent(QPaintEvent*)
{
	static int angle = 0;
	angle += 360/35*9;
	QPainter p(this);
	translateCoords(p);

	QPointF center(100, 100);
	p.drawRoundedRect(0, 0, 200, 300, 10, 10);
	p.drawRoundedRect(5, 5, 190, 290, 10, 10);
	p.setBrush(Qt::lightGray);
	p.drawEllipse(center, 85, 85);
	p.setBrush(this->palette().background());
	p.drawEllipse(center, 15, 15);
	p.setBrush(Qt::NoBrush);
	double pAngle = angle * M_PI_2 / 180.0;
	const int boltCount = 2;
	for (int i=0; i<boltCount; i++)
	{
		p.drawEllipse(QPointF(center.x()+7*cos(pAngle),
							  center.y()+7*sin(pAngle)),
							  3, 3);
		pAngle += 2.0 * M_PI / boltCount;
	}

	double r;

	p.setPen(Qt::blue);
	for (int i=m_currentI ? m_currentI : 1; i < m_vector.size(); ++i)
	{
		r = 15 + 1 + m_vector[i]*(85-15)/double(m_cylCount+1);
		p.drawEllipse(center, r, r);
	}

	qreal x;
	p.setPen(Qt::black);
	if (m_currentI < m_vector.size())
		x = 100 + 15 + 1 + m_currentCyl*(85-15)/double(m_cylCount+1);
	else
		x = 100 + 90;
	p.drawEllipse(QPointF(160, 260), 15, 15);
	p.drawLine(160, 260, x, 100);
	p.setBrush(Qt::black);
	p.drawRect(x - 2, 97, 4, 6);
	p.end();
}

void HddWidget::setCylinderCount(int count)
{
	if (count > 0)
	{
		m_cylCount = count;
	}
}

void HddWidget::mousePressEvent(QMouseEvent *)
{
	if (playing())
		pause();
	else
		play();
}
