#include "notebook.h"

Notebook::Notebook()/*:Computer()*/
{
	s_className=NotebookDefaultClassName;
	description=Tr("Default notebook configuration");
	notebookName=Tr("NoName");
	notebookOrigin=Tr("China");
	notebookCost=0;
	monitorDiagonal=15;
	monitorSize=QSize(1220, 450);
	weight=2.5;
	color=Qt::black;
	batterySize=4400;
	batteryTime=3; // hrs
}