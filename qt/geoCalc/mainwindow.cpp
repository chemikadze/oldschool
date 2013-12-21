#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connectAll();
	newTabIndex = 1;
}

void MainWindow::connectAll()
{
	connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), SLOT(closeTab(int)));

	connect(ui->niveler3Class, SIGNAL(clicked()), SLOT(newNiveler3ClassTab()));
	connect(ui->actionNiveler3Class, SIGNAL(triggered()), SLOT(newNiveler3ClassTab()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newNiveler3ClassTab()
{
	ui->tabWidget->addTab(new Niveler3ClassTab(this), tr("NewTable%1").arg(newTabIndex++));
}

void MainWindow::closeTab(int index)
{
	if (!index)
		return;
	QWidget *t = ui->tabWidget->widget(index);
	ui->tabWidget->removeTab(index);
	delete t;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
