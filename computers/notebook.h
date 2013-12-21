#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <computer.h>
#include <QtCore>

const QString NotebookDefaultClassName("Notebook");

class Notebook: public Computer
{
public:
	QString notebookName;
	QString notebookOrigin;
	int notebookCost;
	int monitorDiagonal;
	QSize monitorSize;
	
	double weight;
	
	QString color;
	
	int batterySize;
	double batteryTime;
	
	QString className();	
	Notebook();
};

#endif