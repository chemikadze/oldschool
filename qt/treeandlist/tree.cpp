#include "tree.h"

TAL::TAL(QWidget *parent) : QMainWindow(parent)
{
	QLayout *laListWidget, *laGrBox;
	QTreeWidgetItem *twi, *twi2;
	QStringList slNames, slFiles;
	int i;	

	slFiles << "girl.png" << "goth.png"	<< "moine.png";
	slNames << QObject::tr("Деффачка") << QObject::tr("Готег") << QObject::tr("Монашег");

	splitter=new QSplitter();
	splitter->setWindowTitle(QObject::tr("Разделитель с деревом и списком"));
	
	laGrBox=new QVBoxLayout();
	laListWidget=new QVBoxLayout();
	listWidget=new QWidget();
	grBox=new QGroupBox(QObject::tr("Стиль списка"));
	rbIcon=new QRadioButton(QObject::tr("Иконки"));
	rbIcon->setChecked(true);
	rbList=new QRadioButton(QObject::tr("Список"));
	laGrBox->addWidget(rbIcon);
	laGrBox->addWidget(rbList);
	grBox->setLayout(laGrBox);
	laListWidget=new QVBoxLayout();
	list=new QListWidget();
	list->setViewMode(QListWidget::IconMode);
	list->setIconSize(QSize(24, 24));
	iconSize=new QSlider();
	iconSize->setRange(16, 128);
	iconSize->setValue(24);
	iconSize->setOrientation(Qt::Horizontal);
	laListWidget->addWidget(list);
	laListWidget->addWidget(grBox);
	laListWidget->addWidget(iconSize);
	listWidget->setLayout(laListWidget);

	tree=new QTreeWidget();
	twi=new QTreeWidgetItem(tree);
	twi->setText(0, QObject::tr("Пингвины"));
	for (i=0; i<slNames.size(); i++)
	{
		twi2=new QTreeWidgetItem(twi);
		twi2->setText(0, slNames[i]);
		twi2->setIcon(0, QPixmap(slFiles[i]));
	}
	splitter->addWidget(tree);
	splitter->addWidget(listWidget);

	setCentralWidget(splitter);

	QObject::connect(tree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(addListItem(QTreeWidgetItem*)));
	QObject::connect(rbIcon, SIGNAL(clicked()), this, SLOT(changeListMode()));
	QObject::connect(rbList, SIGNAL(clicked()), this, SLOT(changeListMode()));
	QObject::connect(iconSize, SIGNAL(valueChanged(int)), this, SLOT(resizeItems(int)));
}

void TAL::changeListMode()
{
	if (rbIcon->isChecked())
	{
		list->setViewMode(QListWidget::IconMode);
		list->setIconSize(QSize(iconSize->value(), iconSize->value()));
	}
	else
	{
		list->setViewMode(QListWidget::ListMode);
		list->setIconSize(QSize(16, 16));
	}
}

void	TAL::resizeItems(int size)
{
	list->setIconSize(QSize(size, size));
}

void TAL::addListItem(QTreeWidgetItem *item)
{
	QListWidgetItem *listItem;

	listItem=new QListWidgetItem(list);
	if (item->childCount())
		return;
	listItem->setText(item->text(0));
	listItem->setIcon(item->icon(0));
}
