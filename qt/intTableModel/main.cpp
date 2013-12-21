#include <QtCore>
#include <QtGui>

#include "intTableModel.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	QTableView *table;

	intTableModel *model;	
	QList < QList <double> > intTable;

	for (int i=0; i<13; i++)
	{
		intTable.push_back(QList<double>());
		for (int j=0; j<3; j++)
			intTable[i].push_back(j);
	}

	model=new intTableModel(intTable);

	table=new QTableView();
	table->setModel(model);
	
	table->show();

	return app.exec();
}
