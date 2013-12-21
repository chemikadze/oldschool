#ifndef _intListModel_h_
#define _intListModel_h_

#include <QtCore>

class intListModel : public QAbstractListModel
{
	Q_OBJECT
	private:
		QList <int> list;
	
	public:
		intListModel(QList <int> lst, QObject * obj=0) : QAbstractListModel(obj), list(lst) {}
		
		QVariant 	data(const QModelIndex& index, int role/*=Qt::DisplayRole*/)const;
		QVariant	headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole)const;
		Qt::ItemFlags	flags(const QModelIndex& index)const;
		bool	setData(const QModelIndex& index, const QVariant& dat, int role/*=Qt::EditRole*/);
		int	rowCount(const QModelIndex& parent)const;
};

#endif
