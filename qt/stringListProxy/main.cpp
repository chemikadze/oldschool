#include <QtCore>
#include <QtGui>

int main(int argc, char** argv)
{
	QApplication application(argc, argv);

	QWidget * wgt;
	QHBoxLayout *la;
	QStringListModel * slModel;
	QSortFilterProxyModel * proxyModel;
	QStringList sl;

	QListView *list1, *list2;

	sl << "moine" << "girl" << "goth";
	slModel=new QStringListModel();
qDebug() << sl;	
	slModel->setStringList(sl);

	proxyModel=new QSortFilterProxyModel();
	proxyModel->setSourceModel(slModel);
	proxyModel->setFilterWildcard("g*");
	
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
