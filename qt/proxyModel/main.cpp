#include <QtCore>
#include <QtGui>

int main(int argc, char** argv)
{
	QApplication application(argc, argv);

	QWidget * wgt;
	QHBoxLayout *la;
	//QStringListModel * slModel;
	QStandardItemModel * slModel;	
	QSortFilterProxyModel * proxyModel;
	QStringList sl;

	QListView *list1, *list2;

	sl << "moine" << "girl" << "goth";
	//slModel=new QStringListModel();
	slModel=new QStandardItemModel(sl.size(), 1);
qDebug() << sl;	
	//slModel->setStringList(sl);


	for (int i=0; i<sl.size(); i++)
	{
		QModelIndex index=slModel->index(i,0);
		slModel->setData(index, QIcon(sl[i]+".png"), Qt::DecorationRole);
		slModel->setData(index, sl[i], Qt::DisplayRole);
	}
	proxyModel=new QSortFilterProxyModel();
	proxyModel->setSourceModel(slModel);
	proxyModel->setFilterWildcard("g*");
	proxyModel->setSortRole(Qt::DisplayRole);
	proxyModel->setFilterRole(Qt::DisplayRole);
	
	QObject::connect(slModel, SIGNAL(itemChanged(QStandardItem*)), proxyModel, SLOT(invalidate()));

	list1=new QListView();
	list1->setModel(slModel);
	list2=new QListView();
	list2->setModel(proxyModel);
	la=new QHBoxLayout();
	la->addWidget(list1);
	la->addWidget(list2);
	wgt=new QWidget();
	wgt->setLayout(la);
	wgt->show();

	return application.exec();
}
