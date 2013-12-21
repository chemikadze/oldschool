#include <QtCore>
#include <QtGui>

#include "intListModel.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	QTableView *table;
	QListView *list;
//	QStringListModel *model=new QStringListModel(QStringList()<<"qrty"<<"wy");

	intListModel *model;	
	model=new intListModel(QList<int>() << 0 << 1 << 2 << 3);
	
	table=new QTableView();
	table->setModel(model);
	
	list=new QListView();
	list->setModel(model);

	list->show();
	table->show();

	return app.exec();
}
