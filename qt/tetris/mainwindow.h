#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtGui/QMainWindow>
#include"tetriswidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

	TetrisWidget *tw;
	QMenu *gameMenu;
	QAction *newAct;
	QAction *pauseAct;
	QAction *stopAct;
	QAction *exitAct;

	QMenu *helpMenu;
	QAction *aboutQt;
	QAction *aboutThis;

public slots:
	void aboutThisSlot();
	void aboutQtSlot();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
