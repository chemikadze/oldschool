#include <QtGui>
#include <QtCore>
#include "intTableModel.h"

typedef QVector <QVector <qlonglong> > Matrix;

void calculate(Matrix & matrix, int height)
{
	int i, j;
	matrix.resize(height+1);
	for (i=0; i<=height; i++)
	{
		matrix[i].resize(i+2);
		matrix[i][0] = 1;
		matrix[i].last() = 0;
	}

	for (i=1; i<=height; i++)
		for (j=1; j<=i; j++)
			matrix[i][j] = matrix[i-1][j] + matrix[i-1][j-1];
}

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QTableWidget *tab = new QTableWidget();

	const int height = 100;
	Matrix c;

	QTime t; t.start();
	calculate(c, height);
	qDebug() << t.elapsed();
/* 
	intTableModel model(c);
	QTableView *w = new QTableView();
	w->setModel(&model);
	w->show();
	qDebug() << t.elapsed();

	return app.exec();
*/	
	tab->setColumnCount(height+1);
	tab->setRowCount(height+1);
	tab->hide();
	for (int i=0; i<=height; i++)
	{
		QTableWidgetItem *it = new QTableWidgetItem();
		it->setData(Qt::DisplayRole, i);
		tab->setVerticalHeaderItem(i, it);
		tab->setHorizontalHeaderItem(i, it);
		for (int j=0; j<=i; j++)
		{
			it = new QTableWidgetItem();
			it->setData(Qt::DisplayRole, QVariant(c[i][j]));
			tab->setItem(i, j, it);
		}
//		qDebug() << i << ' ' << t.elapsed();
	}

	tab->show();
	qDebug() << t.elapsed();

	return app.exec();
}
