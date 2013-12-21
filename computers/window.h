#ifndef WINDOW_H
#define WINDOW_H

#include <QtCore>
#include <QtGui>
#include "computer.h"
#include "computerwidget.h"

class Window : public QMainWindow
{
	Q_OBJECT
private:
	QWidget *mw;
	QGridLayout la;
	QListWidget *list;
	ComputerWidget *computerWidget;

	QPushButton *addComp;
	QPushButton *delComp;

	QMenu	*addMenu;
	QAction *addNoteAct;
	QAction *addCompAct;

	int key;
	QMap <int, Computer*> computers;
private slots:
	void addComputer();
	void addNotebook();
	void delComputer();
	void selComputer(QListWidgetItem* item);

public:	
	void addComputerData(Computer* data);
	Window(QWidget *parent=0);
};

#endif
