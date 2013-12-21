#include "intListModel.h"

QVariant intListModel::data(const QModelIndex& index, int role/*=Qt::DisplayRole*/)const
{
	return index.isValid() && (role==Qt::DisplayRole || role==Qt::EditRole) ? list[index.row()] : QVariant();
}

QVariant intListModel::headerData(int section, Qt::Orientation orientation, int role/*Qt::DisplayRole*/)const
{
	if (role==Qt::DisplayRole || role==Qt::EditRole)
		return ((orientation == Qt::Vertical) ? ( QVariant(section) ) : ( QVariant("Number") ));
	else
		return QVariant();
}

Qt::ItemFlags intListModel::flags(const QModelIndex& index)const
{
	Qt::ItemFlags flag=QAbstractListModel::flags(index);
	
	if (index.isValid())
	{
		qDebug() << "YES";
	}
	return (index.isValid() ? (flag | Qt::ItemIsEditable) : flag);
} 

bool intListModel::setData(const QModelIndex& index, const QVariant& data, int role/*=Qt::EditRole*/)
{
	int p;
	bool ok=false;
	if (role==Qt::EditRole && index.isValid())
	{
		p=data.toInt(&ok);
		if (ok)
		{
			list[index.row()]=p;	
			emit dataChanged(index, index);
		}
	}
	return ok;
}

int intListModel::rowCount(const QModelIndex& parent)const
{
	return list.count();
}

