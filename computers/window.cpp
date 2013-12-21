#include "window.h"

Window::Window(QWidget* parent/*=0*/):QMainWindow(parent)
{
	key=1;
	mw=new QWidget;
	list=new QListWidget();
	addComp=new QPushButton(tr("New"));
	delComp=new QPushButton(tr("Delete"));
	computerWidget=new ComputerWidget();
	addMenu=new QMenu();
	addCompAct=new QAction(tr("Компьютер"), addMenu);
	addNoteAct=new QAction(tr("Ноутбук"), addMenu);
	addMenu->addAction(addCompAct);
	addMenu->addAction(addNoteAct);
	addComp->setMenu(addMenu);
	la.addWidget(list, 2, 1, 1, 2);
	la.addWidget(addComp, 1, 1, 1, 1);
	la.addWidget(delComp, 1, 2, 1, 1);
	la.addWidget(computerWidget, 1, 3, 2, 1);
	mw->setLayout(&la);
	setCentralWidget(mw);
	
	connect(list, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)), 
		this, SLOT(selComputer(QListWidgetItem*)));
	connect(addCompAct, SIGNAL(triggered()), 
		this,       SLOT(addComputer()));
	connect(addNoteAct, SIGNAL(triggered()), 
		this,       SLOT(addNotebook()));
	connect(addComp, SIGNAL(clicked()), 
		this,    SLOT(addComputer()));
	connect(delComp, SIGNAL(clicked()), 
		this,    SLOT(delComputer()));
}

void Window::addComputerData(Computer* data)
{
	QListWidgetItem *item;
	Computer* comp;
	
	qDebug() << data->className();
	comp=computers[key]=data;
	item=new QListWidgetItem();
	item->setFlags(item->flags() | Qt::ItemIsEditable);
	item->setData(Qt::DisplayRole, comp->description);
	item->setData(Qt::UserRole, key++);
	list->addItem(item);
}

void Window::addComputer()
{
	addComputerData(new Computer());
}

void Window::addNotebook()
{
	addComputerData(new Notebook());
}

void Window::selComputer(QListWidgetItem* item)
{
	qDebug() << "selComputer()";
	//computerWidget->setComp(new Computer);
	if (item==NULL)
		computerWidget->setComp();
	else
		computerWidget->setComp(computers[item->data(Qt::UserRole).toInt()]);
}

void Window::delComputer()
{
	int i;
	int itemIndex;
	QListWidgetItem* item;
	QList <QListWidgetItem*> items=list->selectedItems();
	
	for (i=0; i<items.size(); i++)
	{
		item=items[i];
		itemIndex=item->data(Qt::UserRole).toInt()-1;
		delete computers[itemIndex];    // lol, indexes are shit, or, maybe, let use QSet
		computers.remove(itemIndex);
		delete list->takeItem(list->row(item));
	}
}