#ifndef METHODMODEL_H
#define METHODMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include <QVector>

class MethodModel : public QAbstractTableModel
{
protected:
	QVector < QVector <double> > m_m;
public:
	virtual void calculate();

	MethodModel(QObject *parent = NULL);
};

#endif // METHODMODEL_H
