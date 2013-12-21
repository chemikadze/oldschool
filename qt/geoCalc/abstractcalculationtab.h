#ifndef ABSTRACTCALCULATIONTAB_H
#define ABSTRACTCALCULATIONTAB_H

#include <QWidget>

class AbstractCalculationTab : public QWidget
{
Q_OBJECT
public:
    explicit AbstractCalculationTab(QWidget *parent = 0);

signals:

public slots:
	virtual void calculate();
};

#endif // ABSTRACTCALCULATIONTAB_H
