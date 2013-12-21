#include <QtGui>
#include <QtSql>

QSqlDatabase* openConnection()
{
	QSqlDatabase *db=new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
	db->setDatabaseName("addressbook");

	db->setHostName("host");
	db->setUserName("uzer");
	db->setPassword("pasw0rd");

	if (!db->open())
	{
		qDebug() << QObject::tr("Can not open database \"%1\"").arg(db->databaseName());
		return NULL;
	}
	return db;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSqlDatabase *db=openConnection();

	if (!db)
		return -1;

	QSqlTableModel model;
	QSqlTableModel selectedModel;
	QSqlQueryModel queryModel;

	model.setTable("addressbook");
	model.select();
	model.setEditStrategy(QSqlTableModel::OnFieldChange);

	selectedModel.setTable("addressbook");
	selectedModel.setFilter("name = 'ChemiKadze'");
	selectedModel.select();
	selectedModel.setEditStrategy(QSqlTableModel::OnFieldChange);

	queryModel.setQuery("SELECT name, email FROM addressbook WHERE name = 'ChemiKadze'  ; ");

	QTreeView *all, *sel, *que;
	all=new QTreeView;
	all->setModel(&model);
	sel=new QTreeView;
	sel->setModel(&selectedModel);
	que=new QTreeView;
	que->setModel(&queryModel);

	all->setWindowTitle("Database");
	sel->setWindowTitle("Selected by QSqlTableModel");
	que->setWindowTitle("Selected by QSqlQueryModel");

	all->show();
	sel->show();
	que->show();

	return a.exec();
}
