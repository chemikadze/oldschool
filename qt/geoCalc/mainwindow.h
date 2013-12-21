#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>
#include <QStandardItemModel>
#include "methodmodel.h"

#include "niveler3classtab.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
	int newTabIndex;
	Ui::MainWindow *ui;

	void connectAll();

public slots:
	void newNiveler3ClassTab();
	void closeTab(int index);
};

#endif // MAINWINDOW_H
