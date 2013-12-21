#include <QtCore>

class TFile
{
public:
	qint64 size;
	QString name;
	QString fullName;
	QSet <TFile*> *duplicates;
	QDateTime created;
	TFile() {}
};

QSet < TFile* > files;
QDir* dir;

void dfsDir()
{
	TFile *file;
	foreach (const QFileInfo& fil, dir->entryInfoList(QDir::Files | QDir::Readable, QDir::Name))
	{
		file=new TFile;
		file->name=fil.fileName();
		file->fullName=fil.absoluteFilePath();
		file->size=fil.size();
		file->created=fil.created();
		file->duplicates=NULL;
		files.insert(file);
	}
	QString pth=dir->absolutePath();
	foreach (const QString &s, dir->entryList(QDir::Dirs | QDir::Readable | QDir::NoDotAndDotDot, QDir::Name))
	{
		dir->cd(s);
		dfsDir();
		dir->cd(pth);
	}
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	printf("Starting. Press enter...");
	getchar();

	if (argc == 1)
		dir=new QDir(QDir::currentPath());
	else
		dir=new QDir(argv[1]);

	//printf("Finished. Press enter...");
	//getchar();


QString pwd = dir->currentPath();
	for (int i=1; i <= 30; i++){
	dir->cd(QString::number(i));
	dfsDir();

	foreach (TFile *f, files)
		delete f;
	files.clear();
	dir->cd(pwd);
	}

	printf("Freed. Press enter...");
	getchar();

	return 0;
}
