#ifndef NIVELER3CLASS_H
#define NIVELER3CLASS_H

#include "methodmodel.h"

class Niveler3Class : public MethodModel
{
	static QVector <QVariant> m_columnNames;
	static const int m_colCount = 8;
	int measures;
	void retranslateColumns();
public:
	Niveler3Class(QObject *parent = NULL);
	Qt::ItemFlags flags ( const QModelIndex & index ) const;
	QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
	QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
	int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
	int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
	bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ;
	void addMeasure();
	void deleteMeasure();
	void calculate();
};

#endif // NIVELER3CLASS_H
