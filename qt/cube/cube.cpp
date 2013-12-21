// Программа cube
// Соколов Николай, ФПК 1-2
// Файл cube.cpp
//

#include "cube.h"

Cube::Cube(QGLWidget *parent)
    : QGLWidget(parent),d(0), x_angle(0), y_angle(0)
{
    QTreeWidget f;
    setSizePolicy(f.sizePolicy());
}

Cube::~Cube()
{

}

point pnt3(double x, double y, double z)
{
    point p;
    p.x=x;
    p.y=y;
    p.z=z;
    return p;
}



void Cube::initializeGL()
{
	qglClearColor(Qt::black);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	m_cube=generateCube(1);
}

void Cube::resizeGL(int w, int h)
{
	glViewport(0, 0, (GLint)w, (GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double d=1.1;
//	double M=max(w,h), m=min(w,h);
	//glFrustum(-d, d, -d, d, 1, 10.0);
	if (h>=w)
	  glOrtho(-d, d, d*double(h)/double(w), -d*double(h)/double(w), -10, 10);
	else
	  glOrtho(-d*double(w)/double(h), d*double(w)/double(h), d, -d, -10, 10);
}

void Cube::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0.0, 0.0, -3.0);

	//glRotatef(91, 0, 1, 0);
	glRotated(y_angle, 1.0, 0.0, 0.0);glRotatef(x_angle, 0.0, 1.0, 0.0);


	#define rgbVertex(X, Y, Z) {glColor3d(X,Y,Z);glVertex3d(X,Y,Z);}
	glCallList(m_cube);

	double vx,vy,vz,zx,zy,zz,D,x,y,z;

	vx=sin(x_angle*M_PI/180)*cos(y_angle*M_PI/180);
	vy=-sin(y_angle*M_PI/180);
	vz=-cos(x_angle*M_PI/180)*cos(y_angle*M_PI/180);

	zx=zy=zz=0.5;
	zx+=0.01*vx*d;
	zy+=0.01*vy*d;
	zz+=0.01*vz*d;
	D=-zx*vx-zy*vy-zz*vz;
	QVector <point> p;
	char w[4][2]={{0,0},
		      {1,0},
		      {1,1},
		      {0,1}};
	int i;
	for (i=0; i<4; i++)
	{
		if (abs(vx)>0.000001)
		{
			x=(-D-vy*w[i][0]-vz*w[i][1])/vx;
			if (x>=0 && x<=1)
				p.push_back(pnt3(x,w[i][0],w[i][1]));
		}
		if (abs(vy)>0.000001)
		{
			y=(-D-vx*w[i][0]-vz*w[i][1])/vy;
			if (y>=0 && y<=1)
				p.push_back(pnt3(w[i][0],y,w[i][1]));
		}
		if (abs(vz)>0.000001)
		{
			z=(-D-vx*w[i][0]-vy*w[i][1])/vz;
			if (z>=0 && z<=1)
				p.push_back(pnt3(w[i][0],w[i][1],z));
		}
	}

    #define sqr(_X) ((_X)*(_X))
    #define len(_V) (sqrt(sqr(_V.x-zx)+sqr(_V.y-zy)+sqr(_V.z-zz)))
	if (p.size()<3)
	    return;
	int j;

	QVector <double> v;
	double pv;
	v.resize(p.size());
	v[0]=0;
	for (i=1; i<p.size(); i++)
	{
		v[i]=acos(pv=((p[i].x-zx)*(p[0].x-zx)+
			   (p[i].y-zy)*(p[0].y-zy)+
			   (p[i].z-zz)*(p[0].z-zz))/(len(p[0])*len(p[i])));
		if (pv==-1) v[i]=M_PI; else
		if (vx*((p[0].y-zy)*(p[i].z-zz)-(p[0].z-zz)*(p[i].y-zy))+
		    vy*((p[0].x-zx)*(p[i].z-zz)-(p[0].z-zz)*(p[i].x-zx))+
		    vz*((p[0].x-zx)*(p[i].y-zy)-(p[0].y-zy)*(p[i].x-zx)) >= 0)
			v[i]=M_PI*2-v[i];
	}
	qDebug() << v;
	for (i=0; i<p.size()-1; i++)
	    for (j=0; j<p.size()-i-1; j++)
	    {
		if (v[j]>v[j+1])
		{
		    swap(v[j], v[j+1]);
		    swap(p[j], p[j+1]);
		}
	    }
	qDebug() << v;
	//glBegin(GL_LINE_STRIP);
	glBegin(GL_POLYGON);
		 for (i=0; i<p.count(); i++)
		     rgbVertex(p[i].x, p[i].y, p[i].z);
	glEnd();

}

GLint Cube::generateCube(double size)
{
	GLint id=glGenLists(1);
	glNewList(id, GL_COMPILE);
		glTranslated(-size/2, -size/2, -size/2);
		glBegin(GL_LINE_LOOP);
			rgbVertex(size, size, size);
			rgbVertex(size, 0, size);
			rgbVertex(0, 0, size);
			rgbVertex(0, size, size);
		glEnd();
		glBegin(GL_LINE_LOOP);
			rgbVertex(size, size, 0);
			rgbVertex(size, 0, 0);
			rgbVertex(0, 0, 0);
			rgbVertex(0, size, 0);
		glEnd();
		glBegin(GL_LINES);
			rgbVertex(size, size, 0);
			rgbVertex(size, size, size)
		glEnd();
		glBegin(GL_LINES);
			rgbVertex(size, 0, 0);
			rgbVertex(size, 0, size)
		glEnd();
		glBegin(GL_LINES);
			rgbVertex(0, size, 0);
			rgbVertex(0, size, size)
		glEnd();
		glBegin(GL_LINES);
			rgbVertex(0, 0, 0);
			rgbVertex(0, 0, size)
		glEnd();
		glBegin(GL_LINES);// оси
		    rgbVertex(0, 0, 0);
		    rgbVertex(2, 0, 0);
		    rgbVertex(0, 0, 0);
		    rgbVertex(0, 2, 0);
		    rgbVertex(0, 0, 0);
		    rgbVertex(0, 0, 2);
		glEnd();
	glEndList();

	return id;
}

void Cube::mousePressEvent (QMouseEvent * event)
{
	m_point=event->pos();
}

 void Cube::mouseMoveEvent(QMouseEvent * event)
 {
	x_angle+=double(event->pos().x()-m_point.x())/double(width())*180;
	y_angle+=double(event->pos().y()-m_point.y())/double(height())*180;
	m_point=event->pos();
	updateGL();
	emit XaChanged(int(x_angle));
	emit YaChanged(int(y_angle));
 }

 void Cube::setD(int n_d)
 {
	d=n_d;
	updateGL();
 }

void Cube::setXa(int a)
{
	x_angle=a;
	updateGL();
}

void Cube::setYa(int a)
{
	y_angle=a;
	updateGL();
}
