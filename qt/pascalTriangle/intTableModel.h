#ifndef _intListModel_h_
#define _intListModel_h_

#include <QtCore>

class intTableModel : public QAbstractTableModel
{
	Q_OBJECT
	private:
		QVector< QVector <qlonglong> > table;
	
	public:
		intTableModel(QVector < QVector <qlonglong> > tbl, QObject * obj=0) : QAbstractTableModel(obj), table(tbl) {}
		
		QVariant 	data(const QModelIndex& index, int role/*=Qt::DisplayRole*/)const;
		QVariant	headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole)const;
		Qt::ItemFlags	flags(const QModelIndex& index)const;
		bool	setData(const QModelIndex& index, const QVariant& dat, int role/*=Qt::EditRole*/);
		int	rowCount(const QModelIndex& parent)const;
		int	columnCount(const QModelIndex& parent)const;
};

#endif
