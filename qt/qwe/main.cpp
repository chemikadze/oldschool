#include <QtCore>

int main()
{
	int i;
	QVector < QVector <int> > a;
	QVector < QVector <int> > b;

	a.resize(2);
	for (i=0; i<a.size(); i++)
		a[i].resize(3);
	b=a;
	a[0][0]=1;
	qDebug() << a;
	qDebug() << b;
}
