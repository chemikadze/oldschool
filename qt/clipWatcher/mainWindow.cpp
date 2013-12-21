#include "mainWindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *la=new QGridLayout();
    clipTextEdit=new QTextEdit();
    clipTextEdit->setReadOnly(true);
    x11SelectionEdit=new QTextEdit();
    x11SelectionEdit->setReadOnly(true);
    cb=QApplication::clipboard();
    clipTextLabel=new QLabel("Global clipboard");
    x11SelectionLabel=new QLabel("X11 selection buffer");
    showHtml=new QPushButton("Show HTML");
    showHtml->setCheckable(true);
    la->addWidget(clipTextLabel, 0, 0);
    la->addWidget(showHtml, 0, 1);
    la->addWidget(clipTextEdit, 1, 0, 1, 2);
    if (cb->supportsSelection())
    {
	la->addWidget(x11SelectionLabel, 2, 0, 1, 2);
	la->addWidget(x11SelectionEdit, 3, 0, 1, 2);
    }
    this->setLayout(la);
    connect(cb, SIGNAL(dataChanged()), this, SLOT(readClipboardData()));
    connect(cb, SIGNAL(selectionChanged()), this, SLOT(readClipboardData()));
    connect(showHtml, SIGNAL(clicked()), this, SLOT(readClipboardData()));
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    readClipboardData();
}

Widget::~Widget()
{

}

void Widget::readClipboardData()
{
    const QMimeData *mdata=cb->mimeData();
    if (mdata->hasHtml() && showHtml->isChecked())
		clipTextEdit->setPlainText(mdata->html());
    else
		clipTextEdit->setPlainText(mdata->text());
	//delete mdata;
	mdata=cb->mimeData(QClipboard::Selection);
	if (mdata->hasHtml() && showHtml->isChecked())
		x11SelectionEdit->setPlainText(mdata->html());
	else
		x11SelectionEdit->setPlainText(mdata->text());
}
