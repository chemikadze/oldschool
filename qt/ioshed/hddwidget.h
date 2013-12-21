#ifndef HDDWIDGET_H
#define HDDWIDGET_H

#include <QtCore/QVector>
#include <QtGui/QWidget>
#include <QtCore/QTimer>
#include <QtGui/QPainterPath>
#include <QtGui/QImage>

class HddWidget : public QWidget
{
	Q_OBJECT

	int m_cylSwitchTime;
	int m_currentI;
	int m_currentCyl;
	int m_cylCount;
	int m_repaintTimerId;
	QVector <int> m_vector;
	QTimer timer;

private slots:
	void timerTimeout();

protected:
	virtual void paintEvent(QPaintEvent*);
	void translateCoords(QPainter& p);
	virtual void timerEvent(QTimerEvent * event);
	virtual void mousePressEvent(QMouseEvent *);

public:
	void setVector(QVector <int> v);
	void play();
	void pause();
	void stop();
	inline bool playing() { return m_repaintTimerId; }
	void setCylinderCount(int count);
	HddWidget(QWidget *parent = NULL);
};

#endif // HDDWIDGET_H
