#include "widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	QHBoxLayout *la=new QHBoxLayout;

	output=new QTextEdit;
	output->setAcceptRichText(true);
	output->setReadOnly(true);
	openDirBtn=new QPushButton(tr("Открыть"));
	pathEd=new QLineEdit;
	rescanBtn=new QPushButton(tr("Перезагрузить"));
	la->addWidget(pathEd, 1);
	la->addWidget(openDirBtn, 0);
	la->addWidget(rescanBtn, 0);

	QVBoxLayout *mainLa=new QVBoxLayout;
	mainLa->addLayout(la);
	mainLa->addWidget(output);

	connect(openDirBtn, SIGNAL(clicked()), SLOT(openDir()));
	connect(rescanBtn, SIGNAL(clicked()), SLOT(scan()));

	this->setLayout(mainLa);
}

void Widget::openDir()
{
	QFileDialog *dial=new QFileDialog();
	dial->setDirectory(dir);
	dial->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
	dial->setFileMode(QFileDialog::DirectoryOnly);
	if (dial->exec())
	{
		dir.setPath(dial->selectedFiles().first());
		pathEd->setText(dial->selectedFiles().first());
		scan();
	}
}

void Widget::scan()
{
	for (int i=0; i<data.size(); i++)
		data[i].clear();
	data.clear();
	data.resize(1);
	current.clear();
	depth=0;
	dfsDir();
	QString htmlTable;
	output->clear();
	htmlTable.append("<table><tr>");
	for (int i=0; i<data[0].size(); i++)
	{
		htmlTable.append(tr("<th>") + data[0][i] + tr("</th>"));
	}
	htmlTable.append("</tr>");
	for (int i=1; i < data.size(); i++)
	{
		htmlTable.append("<tr>");
		for (int j=0; j < data[i].size(); j++)
			htmlTable.append(tr("<td>") + data[i][j] + tr("</td>"));
		htmlTable.append("</tr>");
	}
	output->setHtml(htmlTable);
}

void Widget::dfsDir()
{
	QStringList nodes=dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
	if (data[0].size() == depth)
	{
		QFile desc(dir.filePath("description.txt"));
		desc.open(QIODevice::ReadOnly);
		data[0].append(tr(desc.readLine(1024)));
		desc.close();
	}
	current.append(dir.dirName());
	foreach (QString s, nodes)
	{
		depth++;
		dir.cd(s);
		dfsDir();
		dir.cdUp();
		depth--;
	}
	if (nodes.size() == 0)
	{
		data.append(current);
	}
	current.pop_back();
}

Widget::~Widget()
{
}
