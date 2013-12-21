#ifndef NIVELER3CLASSTAB_H
#define NIVELER3CLASSTAB_H

#include <QWidget>
#include "abstractcalculationtab.h"
#include "niveler3class.h"

namespace Ui {
    class Niveler3ClassTab;
}

class Niveler3ClassTab : public AbstractCalculationTab {
    Q_OBJECT
	Niveler3Class *model;
public:
    Niveler3ClassTab(QWidget *parent = 0);
    ~Niveler3ClassTab();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Niveler3ClassTab *ui;

public slots:
	void addMeasure();
	void deleteMeasure();
	void calculate();
};

#endif // NIVELER3CLASSTAB_H
