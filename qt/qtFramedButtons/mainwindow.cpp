#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
{
/*	layout like that
	   -----
	  |  |  | spins
	  | + - | buttons
	  |     | list
	  -------		*/
	key=0;
	QGridLayout* la=new QGridLayout();
	sizeBox=new QSpinBox();
	sizeBox->setRange(10, 900);
	sizeBox->setValue(200);
	countBox=new QSpinBox();
	countBox->setRange(1, 100);
	countBox->setValue(10);
	listWindows=new QListWidget();
	addButton=new QPushButton(QIcon(QPixmap(":/list-add.png")), tr("Показать"));
	delButton=new QPushButton(QIcon(QPixmap(":/list-remove.png")), tr("Закрыть"));
	firstColor=new colorChooser(Qt::black);
	lastColor=new colorChooser(Qt::white);
	la->addWidget(sizeBox, 0, 0);
	la->addWidget(countBox, 0, 1);
	la->addWidget(listWindows, 3, 0, 1, 2);
	la->addWidget(addButton, 2, 0);
	la->addWidget(delButton, 2, 1);
	la->addWidget(firstColor, 4, 0);
	la->addWidget(lastColor, 4, 1);
	this->setLayout(la);
	connect(addButton, SIGNAL(clicked()), this, SLOT(newButtons()));
	connect(delButton, SIGNAL(clicked()), this, SLOT(delButtons()));
}

mainWindow::~mainWindow()
{
	QHash <int,Buttons*>::iterator it;
	for (it=buttons.begin(); it!=buttons.end(); ++it)
		delete *it;
	buttons.clear();
}

void mainWindow::closeEvent(QCloseEvent *event)
{
	QApplication::quit();
}

void mainWindow::newButtons()
{
	Buttons *butt=new Buttons;

	if (butt->createButtons(sizeBox->value(), countBox->value(), firstColor->color(), lastColor->color()))
	{
		buttons.insert(++key, butt);
		butt->setWindowTitle(tr("# %1").arg(key));
		butt->show();
		QListWidgetItem *item=new QListWidgetItem();
		item->setData(Qt::DisplayRole, QVariant(tr("# %3: %1 штук %2 x %2").arg(countBox->value()).arg(sizeBox->value()).arg(key)));

		item->setData(Qt::UserRole, key);
		listWindows->addItem(item);
		connect(butt, SIGNAL(closed()), this, SLOT(delButtons()));
	}
	else
	{
		delete butt;
	}
}

void mainWindow::delButtons() /* TODO: holy shit, this must to work */
{
	if (sender() != delButton)
	{
		int i, p=buttons.key((Buttons*)sender());
		for (i=0; i<listWindows->count() && listWindows->item(i)->data(Qt::UserRole).toInt()!=p; i++);
		delete listWindows->takeItem(i);
		delete buttons.take(p);
	}
	else
	{
		QList<QListWidgetItem*> items=listWindows->selectedItems();
		QList<QListWidgetItem*>::iterator it;
		for (it=items.begin(); it!=items.end(); ++it)
		{
			delete buttons.take((*it)->data(Qt::UserRole).toInt());
			delete listWindows->takeItem(listWindows->row(*it));
		}
	}

}
