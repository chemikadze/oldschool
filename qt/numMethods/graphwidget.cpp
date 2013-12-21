#include "graphwidget.h"

Path::Path(const QVector<double> &x, const QVector<double> &y)
{
	Path();
	int N = std::min(x.size(), y.size());
	for (int i=0; i<=N; i++)
	{
		v_data.append(QPointF(x[i], y[i]));
	}
}

Path::Path() : s_color(Qt::red)
{
}

GraphWidget::GraphWidget(QWidget *parent/*=NULL*/) : QWidget(parent), trans(0, 0), s_scale(defaultScale)
{
	setFocusPolicy(Qt::StrongFocus);
}

bool GraphWidget::addPath(Path* p)
{
	if (!paths.contains(p))
	{
		paths.insert(p);
		return true;
	}
	else
		return false;
}

Path* GraphWidget::takePath(Path *p)
{
	paths.remove(p);
	return p;
}

void GraphWidget::clearPaths(bool del /* = no */)
{
	if (del)
		foreach (Path* p, paths)
			delete p;
	paths.clear();
}

void GraphWidget::paintEvent(QPaintEvent *event)
{
	QTime t; t.start();

	QPainter p(this);

	p.fillRect(this->rect(), Qt::white);
	p.drawLine( 0, height()/2 + trans.y(), width(),  height()/2 + trans.y() );
	p.drawLine( width()/2 + trans.x(), 0, width()/2 + trans.x(), height() );

	int i;
	int dash3;
	const int dashL=3;
	int dashF=height()/2 - dashL/2 + trans.y();
	int dashT=dashF+dashL;
	int maxp = ceil(canvXToDec(width()));
	for (i=floor(canvXToDec(0)); i <= maxp ; i++)
	{
		dash3 = xToCanvX(i);
		p.drawLine(dash3, dashF, dash3, dashT);
		p.drawText(dash3, dashF, QString::number(i));
	}

	dashF = width()/2 - dashL/2 + trans.x();
	dashT = dashF+dashL;
	maxp = ceil(canvYToDec(0));
	int toI = std::min(maxp, -1);
	for (i=floor(canvYToDec(height())); i <= toI; i++)
	{
		dash3 = yToCanvY(i);
		p.drawLine(dashF, dash3, dashT, dash3);
		p.drawText(dashT, dash3, QString::number(i));
	}
	for (i=std::min(maxp+1, 1); i <= maxp; i++) // longer, but i don't want "if" here
	{
		dash3 = yToCanvY(i);
		p.drawLine(dashF, dash3, dashF+dashL, dash3);
		p.drawText(dashF+dashL, dash3, QString::number(i));
	}

	QPointF fr, to;
	p.setRenderHint(QPainter::Antialiasing, true);
	foreach (Path *path, paths)
	{
		if (path->size()<=0)
			break;

		p.setPen(path->color());
		for (i=1; i<path->size(); i++)
		{
			p.drawLine( xToCanvX((*path)[i-1].x()), yToCanvY((*path)[i-1].y()),
						xToCanvX((*path)[i].x()), yToCanvY((*path)[i].y()) );
		}
	}
	p.end();
	qDebug() << "Render time: " << t.elapsed();
}

void GraphWidget::mousePressEvent(QMouseEvent *event)
{
	prevPos = event->pos();
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event)
{
	trans += event->pos() - prevPos;
	prevPos = event->pos();
	repaint();
}

void GraphWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	trans.setX(0);
	trans.setY(0);
	s_scale = defaultScale;
	repaint();
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
	double oldscale = s_scale;
	switch (event->key())
	{
		case Qt::Key_Plus:
			setScale(s_scale * 1.5);break;
		case Qt::Key_Minus:
			setScale(s_scale/1.5);break;
		case Qt::Key_0:
			s_scale = defaultScale;
			trans.setX(0);
			trans.setY(0);
			break;
		case Qt::Key_Up:
			trans.setY(trans.y()-10);break;
		case Qt::Key_Down:
			trans.setY(trans.y()+10);break;
		case Qt::Key_Left:
			trans.setX(trans.x()-10);break;
		case Qt::Key_Right:
			trans.setX(trans.x()+10);break;
	}
	if (oldscale != s_scale)
		repaint();
}

void GraphWidget::wheelEvent(QWheelEvent *e)
{
	setScale(s_scale*std::pow(1.5, e->delta() / 100));
	repaint();
}
