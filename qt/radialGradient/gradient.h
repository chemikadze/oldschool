#include <QtCore>
#include <QtGui>

class QPaintWidget: public QWidget
{
	Q_OBJECT
	QPoint  focusAspect;
	QPointF focus;
 protected:
	void resizeEvent(QResizeEvent *event)
	{
		focus=QPointF(double(width()*focusAspect.x())/100, double(height()*focusAspect.y())/100);
		update();
	}
	
	void mousePressEvent(QMouseEvent *event)
	{
		focus=event->posF();
		focusAspect=QPoint(int(focus.x()*100/width()), int(focus.y()*100/height()));
		update();
		emit movedX(focusAspect.x());
		emit movedY(focusAspect.y());
	}

	void mouseMoveEvent(QMouseEvent *event)
	{
		focus=event->posF();
		focusAspect=QPoint(int(focus.x()*100/width()), int(focus.y()*100/height()));
		update();
		emit movedX(focusAspect.x());
		emit movedY(focusAspect.y());
	}

	void paintEvent(QPaintEvent *event)
	{
		QPainter p(this);
		QRadialGradient gradient(this->rect().center(), this->width()/2, this->focus);
		QPalette palett=this->palette();	
		QPen pen;	

		palett.setColor(QPalette::Window, Qt::white);
		pen.setColor(Qt::green);
		this->setPalette(palett);	

		gradient.setColorAt(0, Qt::black);
		gradient.setColorAt(0.5, Qt::red);
		gradient.setColorAt(1, Qt::white);

		p.setRenderHint(QPainter::Antialiasing, this->width() > this->height());
		p.setBrush(gradient);
		p.setPen(pen);	
	
		p.setFont(QFont("Arial", 10));
		//p.drawEllipse(0, 0, this->width(), this->height());
		p.drawRect(rect());
		p.drawText(focus, QString("Qt win! Coords: %1 %2").arg(focus.x()).arg(focus.y()));

		p.end();
	}

 public slots:
	void moveX(int px)
	{
		focusAspect.setX(px);	
		focus.setX((double(px)/100)*this->width());update();	
	}
	void moveY(int py)
	{	
		focusAspect.setY(py);
		focus.setY((double(py)/100)*this->height());update();
	}	
	
 signals:
	void movedX(int px);
	void movedY(int py);

 public:
	QPaintWidget(QWidget *parent=0):focus(50, 50), focusAspect(50, 50) { setMouseTracking(true);setAutoFillBackground(true);update(); };
};
