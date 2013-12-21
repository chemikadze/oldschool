// Программа cube
// Соколов Николай, ФПК 1-2
// Файл cube.h
//


#ifndef CUBE_H
#define CUBE_H

#include <QtGui>
#include <QtOpenGL>
#include <cmath>
#include <algorithm>

using std::swap;
using std::abs;
using std::min;
using std::max;

struct s_point
{
	double x, y, z;
};

typedef struct s_point point;

class Cube : public QGLWidget
{
    Q_OBJECT
protected:
	int d;
	GLint m_cube;
	QPoint m_point;
	GLdouble x_angle;
	GLdouble y_angle;
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent (QMouseEvent * event);
	GLint	generateCube(double size);
public slots:
	void setD(int n_d);
	void setXa(int a);
	void setYa(int a);
signals:
	void XaChanged(int a);
	void YaChanged(int a);
public:
    Cube(QGLWidget *parent = 0);
    ~Cube();
};

#endif // CUBE_H
