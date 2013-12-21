#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QVector>

class GraphWidget : public QWidget
{
	Q_OBJECT

	double sum;
	QVector <int> counts;
	int m_range;
private:
	virtual void paintEvent ( QPaintEvent * event );

public slots:
	void setRange(int newRange);
	void clear();

public:
	void addItem(int val);
	int range();

    GraphWidget();
};

#endif // GRAPHWIDGET_H
