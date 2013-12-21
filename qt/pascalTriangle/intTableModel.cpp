#include "intTableModel.h"

QVariant intTableModel::data(const QModelIndex& index, int role/*=Qt::DisplayRole*/)const
{
	return index.isValid() && (role==Qt::DisplayRole || role==Qt::EditRole) ? table[index.row()][index.column()] : QVariant();
}

QVariant intTableModel::headerData(int section, Qt::Orientation orientation, int role/*Qt::DisplayRole*/)const
{
	if (role==Qt::DisplayRole || role==Qt::EditRole)
		return QVariant(section);
	else
		return QVariant();
}

Qt::ItemFlags intTableModel::flags(const QModelIndex& index)const
{
	Qt::ItemFlags flag=QAbstractTableModel::flags(index);
	
	return (index.isValid() ? (flag | Qt::ItemIsEditable) : flag);
} 

bool intTableModel::setData(const QModelIndex& index, const QVariant& data, int role/*=Qt::EditRole*/)
{
	int p;
	bool ok=false;
	if (role==Qt::EditRole && index.isValid())
	{
		p=data.toInt(&ok);
		if (ok)
		{
			table[index.row()][index.column()]=p;
			emit dataChanged(index, index);
		}
	}
	return ok;
}

int intTableModel::rowCount(const QModelIndex& parent)const
{
	return table.count();
}

int intTableModel::columnCount(const QModelIndex& parent)const
{
	return table.count();
}
