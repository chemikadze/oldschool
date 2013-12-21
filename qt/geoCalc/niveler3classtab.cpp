#include "niveler3classtab.h"
#include "ui_niveler3classtab.h"

Niveler3ClassTab::Niveler3ClassTab(QWidget *parent) :
	AbstractCalculationTab(parent),
    ui(new Ui::Niveler3ClassTab)
{
    ui->setupUi(this);
	model = new Niveler3Class(ui->tableView);
	ui->tableView->setModel(model);

	connect(ui->addBtn, SIGNAL(clicked()), SLOT(addMeasure()));
	connect(ui->deleteBtn, SIGNAL(clicked()), SLOT(deleteMeasure()));
	connect(ui->calculateBtn, SIGNAL(clicked()), SLOT(calculate()));
}

Niveler3ClassTab::~Niveler3ClassTab()
{
    delete ui;
}

void Niveler3ClassTab::addMeasure()
{
	model->addMeasure();
}

void Niveler3ClassTab::deleteMeasure()
{
	model->deleteMeasure();
}

void Niveler3ClassTab::calculate()
{
	model->calculate();
}

void Niveler3ClassTab::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
