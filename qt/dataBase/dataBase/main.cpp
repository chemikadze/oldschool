#include <QtCore>
#include <QtSql>

#define tr(_X) QObject::tr(_X)

QSqlDatabase* openConnection()
{
	QSqlDatabase *db=new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
	db->setDatabaseName("addressbook");

	db->setHostName("host");
	db->setUserName("uzer");
	db->setPassword("pasw0rd");

	if (!db->open())
	{
		qDebug() << tr("Can not open database \"%1\"").arg(db->databaseName());
		return NULL;
	}
	return db;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	QSqlDatabase *db;

	qDebug() << tr("Opening connection...");
	if ((db=openConnection()) == NULL)
	{
		return -1;
	}

	QSqlQuery *query=new QSqlQuery();
	QString str;

	str="CREATE TABLE addressbook ( "
		"number INTEGER PRIMARY KEY NOT NULL, "
		"name VARCHAR(20), "
		"email VARCHAR(20), "
		"phone VARCHAR(20) "
		");";

	qDebug() << tr("Creating table...");
	if (!query->exec(str))
	{
		qDebug() << tr("Can not create database: %1").arg(query->lastError().text());
	}

	qDebug() << tr("Inserting data...");

	str=tr("INSERT INTO addressbook (number, name, email, phone) "
		   "VALUES (%1, \'%2\', \'%3\', \'%4\');");

	if (!query->exec(str.arg("1", "ChemiKadze", "chemkadze@yandex.ru", "+7 915 796 0 286")))
		qDebug() << tr("Can not insert %1 with error: %2").arg("ChemiKadze", query->lastError().text());

	if (!query->exec(str.arg("4", "Tector", "Enin.Alex@gmail.com", "none")))
		qDebug() << tr("Can not insert %1 with error: %2").arg("Tector", query->lastError().text());

	if (!query->exec(str.arg("3", "ChemiKadze", "chemikadze@gmail.com", "none")))
		qDebug() << tr("Can not insert %1 with error: %2").arg("Chemikadze", query->lastError().text());

	qDebug() << tr("Reading emails...");

	if (!query->exec("SELECT * FROM addressbook;"))
		qDebug() << tr("Can not select with error: %1").arg(query->lastError().text());

	QSqlRecord rec=query->record();

	while (query->next())
	{
		qDebug() << query->value(rec.indexOf("number")).toInt() << "\t"
				 << query->value(rec.indexOf("name")).toString() << "\t"
				 << query->value(rec.indexOf("email")).toString() << "\t"
				 << query->value(rec.indexOf("phone")).toString();
	}

	delete query;
	delete db;
	QSqlDatabase::removeDatabase("addressbook");
	qDebug() << tr("Finished.");

	return 0;
}
