#include <stdio.h>
#include <QtGui>
#include <QtCore>


int main(int argc, char * argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("cp1251"));
	QApplication app(argc, argv);
	
	if (argc==1)
	{
		qDebug("Нет входного файла!");
		return 0;
	}

	FILE * input=fopen(argv[1], "r");
	QString qstr;
	char * cstr;

	if (input==NULL)
	{
		qDebug("Не могу открыть входной файл!");
		return 0;
	}

	cstr=new char[256];
	QTextEdit * te;
	
	while (fgets(cstr, 256, input)!=NULL)
		qstr+=QObject::tr(cstr);
		//qstr+=cstr;
	te=new QTextEdit();
	te->setWindowTitle(QObject::tr(argv[1]));
	te->setReadOnly(true);
	te->setHtml(qstr);
	
	te->show();

	return app.exec();
}
