#ifndef CALCULATIONTABLE_H
#define CALCULATIONTABLE_H

#include <QTableView>

class CalculationTable : public QTableView
{
	Q_OBJECT
protected:
	QAbstractTable
public:

    CalculationTable();
public slots:
	void loadFromFile();
};

#endif // CALCULATIONTABLE_H
