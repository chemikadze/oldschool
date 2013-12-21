#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	tw=new TetrisWidget;
	tw->setFocus();
	setCentralWidget(tw);
	gameMenu=menuBar()->addMenu(tr("Game"));
	newAct=gameMenu->addAction(tr("New game"), tw, SLOT(start()));
	pauseAct=gameMenu->addAction(tr("Pause"), tw, SLOT(pause()));
	pauseAct->setCheckable(true);
	connect(tw, SIGNAL(paused(bool)), pauseAct, SLOT(setChecked(bool)));
	stopAct=gameMenu->addAction(tr("End game"), tw, SLOT(stop()));
	gameMenu->addSeparator();
	exitAct=gameMenu->addAction(tr("Exit"), this, SLOT(close()));

	helpMenu=menuBar()->addMenu(tr("Help"));
	aboutThis=helpMenu->addAction(tr("About QTetris..."), this, SLOT(aboutThisSlot()));
	helpMenu->addSeparator();
	aboutQt=helpMenu->addAction(tr("About Qt..."), this, SLOT(aboutQtSlot()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::aboutQtSlot()
{
	QMessageBox::aboutQt(this);
}

void MainWindow::aboutThisSlot()
{
	QMessageBox::about(this, tr("About QTetris."), tr("<h3>QTetris</h3><br>By ChemiKadze. Based on Qt."));
}
