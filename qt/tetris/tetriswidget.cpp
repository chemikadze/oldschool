#include "tetriswidget.h"

TetrisWidget::TetrisWidget()
{
	this->setFocusPolicy(Qt::StrongFocus);
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	int i, j;
	m_field.resize(TET_HEIGHT+3*2);
	for (i=0; i<m_field.size(); i++)
	{
		m_field[i]=new char[TET_WIDTH+3*2];
		for (j=0; j<TET_WIDTH+3*2; j++)
			if (i>=TET_HEIGHT+3 || j>=TET_WIDTH+3 || j<3)
				m_field[i][j]=0xFF;
			else
				m_field[i][j]=0x0;
	}
	timer=new QTimer;
	srand(time(NULL));
	m_score=0;
	elem=new Element(Element::No, 0);
	nextElem=new Element(Element::No, 0);
	connect(timer, SIGNAL(timeout()), this, SLOT(dropDown()));
	m_row=-1;
	m_col=TET_WIDTH/2-2;
	m_level=1;
	m_state=Stopped;
}

bool TetrisWidget::dropDown()
{
	if (canBe(m_row+1, m_col))
	{
		m_row++;
		repaint();
		return true;
	}
	else
	{
		elemDropped();
		repaint();
		return false;
	}
}

bool TetrisWidget::canBe(qint8 nrow, qint8 ncol)
{
	for (int i=0; i<4 && (nrow-i+3)>=0; i++)
	{
		for (int j=0; j<4; j++)
			if (m_field[nrow-i+3][ncol+3+j]!=0 && elem->cell(i, j)!=0)
				return false;
	}
	return true;
}

void TetrisWidget::pause()
{
	if (m_state == Stopped || m_state == GameOver)
	{
		emit paused(!timer->isActive());
		return;
	}
	if (timer->isActive())
	{
		timer->stop();
		m_state=Paused;
	}
	else
	{
		timer->start();
		m_state=Started;
	}
	emit paused(!timer->isActive());
}

void TetrisWidget::pause(bool b)
{
	if (m_state == Stopped || m_state == GameOver)
	{
		emit paused(!timer->isActive());
		return;
	}
	if (!b)
	{
		timer->start();
		m_state=Started;
	}
	else
	{
		timer->stop();
		m_state=Paused;
	}
	emit paused(b);
}

void TetrisWidget::start()
{
	timer->start(1000/m_level);
	m_state=Started;
	m_score=0;
	m_row=0;
	m_col=TET_WIDTH/2-2;
	m_level=1;
	clear();
	delete elem;
	delete nextElem;
	int i=rand()%(Elements::count-1)+1;
	elem=new Element(Element::Type(i), rand()%(Elements::rotations[i]+1));
	i=rand()%(Elements::count-1)+1;
	nextElem=new Element(Element::Type(i), rand()%(Elements::rotations[i]+1));
	repaint();
}


qint8 TetrisWidget::level()
{
	return m_level;
}

// shit
void TetrisWidget::elemDropped()
{
	if (m_row<0)
	{
		timer->stop();
		m_state=GameOver;
		repaint();
		return;
	}
	qint8 i, j;
	for (i=0; i<4 && (m_row-i)>=0; i++)
		for (j=0; j<4; j++)
			if (elem->cell(i, j))
				m_field[m_row-i+3][m_col+j+3]=elem->cell(i, j);
	for (i=0; i<4 && (m_row-i)>=0; i++)
	{
		for (j=3; j<TET_WIDTH+3; j++)
		{
			if (!m_field[m_row-i+3][j])
				break;
		}
		if (j==TET_WIDTH+3)
		{
			m_field.prepend(m_field[m_row-i+3]);
			for (j=3; j<TET_WIDTH+3; j++)
				m_field[0][j]=0x0;
			m_field.remove(m_row-i+4);
			m_score+=m_level;
			emit scoreChanged(m_score);
			if (!(m_score%20))
				emit levelChanged(++m_level);
			i--;
		}
	}
	delete elem;
	elem=nextElem;
	i=rand()%(Elements::count-1)+1;
	nextElem=new Element(Element::Type(i), rand()%(Elements::rotations[i]+1));
	m_row=0;
	m_col=TET_WIDTH/2-2;
	timer->setInterval(1000/m_level);
	repaint();
}

void TetrisWidget::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
		case (Qt::Key_Escape):
			pause();
			break;

		case (Qt::Key_Left):
			if (canBe(m_row, m_col-1))
				m_col--;
			break;

		case (Qt::Key_Right):
			if (canBe(m_row, m_col+1))
				m_col++;
			break;

		case (Qt::Key_Up):
			elem->rotate();
			if (!canBe(m_row, m_col))
				elem->rotate(false);
			break;

		case (Qt::Key_Down):
		case (Qt::Key_Space):
			timer->setInterval(50);
			break;
	}
	repaint();
}

void TetrisWidget::keyReleaseEvent (QKeyEvent * event)
{
	if (event->key() == Qt::Key_Down || event->key() == Qt::Key_Space)
		setLevel(m_level);
}

void TetrisWidget::paintEvent(QPaintEvent*)
{
	double dx=0, dy=0, siz;
	if (width()>height())
	{
		dx=double(width()/2-double(height()/2));
		siz=double(height())/TET_HEIGHT;
	}
	else
	{
		dy=double(height()-double(width()))/2;
		siz=double(width()/2)/TET_WIDTH;
	}
	int i, j;
	QPainter p(this);
	p.setPen(Qt::black);
	p.setBrush(QBrush(Qt::white));
	p.drawRect(dx, dy, width()/2-dx, height()-dy*2);
	p.drawRect(width()/2, dy, width()/2-dx, height()-dy*2);
	p.setFont(QFont("Times", 15, QFont::Bold));
	p.drawText(QRectF(width()/2+20, dy+20, width()/2-dx, 20), Qt::AlignLeft, tr("Level: %1").arg(m_level));
	p.drawText(QRectF(width()/2+20, dy+40, width()/2-dx, 20), Qt::AlignLeft, tr("Score: %1").arg(m_score));
	p.drawText(QRectF(width()/2+20, dy+60, width()/2-dx, 20), Qt::AlignLeft, tr("Next:"));
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			if (nextElem->cell(i, j))
			{
				p.setBrush(QColor::fromRgb(0x99*((nextElem->cell(i, j))/0x4%0x2), 0x99*((nextElem->cell(i, j))/0x2%0x2), 0x99*((nextElem->cell(i, j))%0x2)));
				p.drawRect(QRectF(width()/2+(width()/2-dx)/2+(j-1)*siz, dy+80+siz*(4-i), siz, siz));
			}
	p.setBrush(QBrush(Qt::gray));
	for (i=0; i<TET_HEIGHT; i++)
		for (j=0; j<TET_WIDTH; j++)
		{
			if (m_field[i+3][j+3])
			{
				p.setBrush(QColor::fromRgb(0x99*((m_field[i+3][j+3])/0x4%0x2), 0x99*((m_field[i+3][j+3])/0x2%0x2), 0x99*((m_field[i+3][j+3])%0x2)));
				p.drawRect(QRectF(dx+j*siz, dy+i*siz, siz, siz));
			}
		}
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			if (elem->cell(i, j) && (m_row-i)>=0)
			{
				p.setBrush(QColor::fromRgb(0x99*((elem->cell(i, j))/0x4%0x2), 0x99*((elem->cell(i, j))/0x2%0x2), 0x99*((elem->cell(i, j))%0x2)));
				p.drawRect(QRectF(dx+(m_col+j)*siz, dy+(m_row-i)*siz, siz, siz));
			}
	if (m_state==Paused)
	{
		p.setBrush(QColor(Qt::white));
		p.drawRect(10, (height()-20)/2, width()-20, 20);
		p.drawText(QRectF(10, (height()-20)/2, width()-20, 20), Qt::AlignCenter,  tr("Paused"), NULL);
	}

	if (m_state==GameOver)
	{
		p.setBrush(QColor(Qt::white));
		p.drawRect(10, (height()-20)/2, width()-20, 20);
		p.drawText(QRectF(10, (height()-20)/2, width()-20, 20), Qt::AlignCenter,  tr("Game Over"), NULL);
	}

	p.end();
}

void TetrisWidget::setLevel(qint8 level)
{
	m_level=level;
	timer->setInterval(1000/m_level);
	emit levelChanged(m_level);
}

qint32 TetrisWidget::score()
{
	return m_score;
}

void TetrisWidget::stop()
{
	timer->stop();
	m_state=GameOver;
	repaint();
}

void TetrisWidget::clear()
{
	for (int i=0; i<TET_HEIGHT+3; i++)
		for (int j=3; j<TET_WIDTH+3; j++)
			m_field[i][j]=0x0;
}

QSize TetrisWidget::sizeHint()
{
	return QSize(400, 400);
}
