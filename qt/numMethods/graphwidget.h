#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QPainter>
#include <QtCore/QVector>
#include <QtCore/QPointF>
#include <QtCore/QSet>
#include <QtGui/QMouseEvent>
#include <QtCore/QTime>
#include <QtCore/QDebug>
#include <cmath>

class Path {
		QVector < QPointF > v_data;
		QColor s_color;
	public:
		inline QColor color() { return s_color; }
		inline void setColor(QColor clr) { s_color = clr; }
		inline QVector < QPointF > data() { return v_data; }
		inline QPointF& operator[] (int i) { return v_data[i]; }
		inline void addPoint(const QPointF& pnt) { v_data.append(pnt); }
		inline int size() { return v_data.size(); }
		void resize(int size) { v_data.resize(size); }
		Path(const QVector<double> &x, const QVector<double> &y);
		Path();
};

class GraphWidget : public QWidget
{
	QSet <Path*> paths;
	QPointF trans;
	double s_scale;
	QPoint prevPos;
protected:
	virtual void paintEvent(QPaintEvent*);
	virtual void mouseMoveEvent ( QMouseEvent *);
	virtual void mousePressEvent ( QMouseEvent *);
	virtual void mouseDoubleClickEvent ( QMouseEvent *);
	virtual void keyPressEvent(QKeyEvent *);
	virtual void wheelEvent(QWheelEvent*);
public:
	static const int defaultScale = 40;
	static const int maxScale = 100;
	static const int minScale = 3;

	inline int xToCanvX(double a_x) { return a_x*s_scale + trans.x() + width()/2; }
	inline int yToCanvY(double a_y) { return -a_y*s_scale + trans.y() + height()/2; }
	inline double canvXToDec(int a_x) { return (a_x - trans.x() - width()/2)/s_scale; }
	inline double canvYToDec(int a_y) { return (-a_y + trans.y() + height()/2)/s_scale; }
	inline double minX() { return canvXToDec(0); }
	inline double maxX() { return canvXToDec(width()); }
	inline void setScale(double s) { if (s>minScale && s<maxScale) s_scale = s; }
	inline double scale() { return s_scale; }
	bool addPath(Path* p);
	Path* takePath(Path* p);
	void clearPaths(bool del = false);
	inline int pathCount() { return paths.size(); }
	GraphWidget(QWidget *parent=NULL);
};

#endif // GRAPHWIDGET_H
