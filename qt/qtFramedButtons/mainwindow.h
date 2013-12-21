#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtCore>
#include "buttons.h"
#include "colorchooser.h"

class mainWindow : public QWidget
{
	Q_OBJECT
	int key;
	QHash <int,Buttons*> buttons;

	QSpinBox *sizeBox;
	QSpinBox *countBox;
	QListWidget *listWindows;
	QPushButton *addButton;
	QPushButton *delButton;
	colorChooser *firstColor;
	colorChooser *lastColor;
private:
	virtual void closeEvent(QCloseEvent *event);
public slots:
	void newButtons();
	void delButtons();
public:
	mainWindow(QWidget *parent = 0);
	~mainWindow();
};

#endif // MAINWINDOW_H
