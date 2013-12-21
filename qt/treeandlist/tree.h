#ifndef _TREE_H_
#define _TREE_H_

#include <QtGui>
#include <QtCore>

class TAL : public QMainWindow
{
	Q_OBJECT
	public slots:
		void addListItem(QTreeWidgetItem* item);
		void changeListMode();
		void resizeItems(int size);
	public:
		QSplitter	*splitter;
		QTreeWidget	*tree;
		QSlider		*iconSize;
		QListWidget	*list;
		QWidget		*listWidget;
		QGroupBox	*grBox;
		QRadioButton	*rbIcon;
		QRadioButton	*rbList;
			
		TAL(QWidget *parent=0);
};

#endif
