#ifndef COMPUTERWIDGET_H
#define COMPUTERWIDGET_H

#include <QtGui>
#include <QtCore>
#include "computer.h"
#include "notebook.h"

class ComputerWidget: public QTreeWidget
{
	Q_OBJECT
	QString p_compClassName;
	Computer* p_comp;
	QVector <QTreeWidgetItem*> caption;
	
	void createCaptions();
	void inputData();
	void outputData();
virtual void resizeEvent(QResizeEvent* event);	
public slots:
	void setComp(Computer* newComp=NULL);
public:
	Computer* comp() const;
	ComputerWidget(QWidget* parent=0);	
};

#endif