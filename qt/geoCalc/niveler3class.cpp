#include "niveler3class.h"

QVector <QVariant> Niveler3Class::m_columnNames;

Niveler3Class::Niveler3Class(QObject *parent/* = NULL*/) : MethodModel(parent)
{
	m_m.append(QVector<double>(m_colCount, 0));
	measures = 0;
	addMeasure();
	retranslateColumns();
}

void Niveler3Class::retranslateColumns()
{
	m_columnNames.clear();
	m_columnNames << QVariant(tr("По дальном. нитям\nзадняя рейка"))
				  << QVariant(tr("По дальном. нитям\nпередняя рейка"))
				  << QVariant(tr("Контрольные\n превышения"))
				  << QVariant(tr("По средн. нити\nЗадняя"))
				  << QVariant(tr("По средн. нити\nПередняя"))
				  << QVariant(tr("По средн. нити\nПревышение"))
				  << QVariant(tr("Превышение"));
}

Qt::ItemFlags Niveler3Class::flags(const QModelIndex & index)const
{
	Qt::ItemFlags flag=QAbstractTableModel::flags(index);
	int col = index.column();

	return index.isValid() && ((index.row()+1)%4) && ((index.row()+2)%4) && (col == 0 || col == 1 || col == 3 || col == 4)  ?
			flag|Qt::ItemIsEditable :
			flag;
}

QVariant Niveler3Class::data(const QModelIndex & index, int role/* = Qt::DisplayRole*/ )const
{
	if (index.isValid() && (role == Qt::EditRole || role == Qt::DisplayRole) && ((index.row()+1)%4))
	{
		int realRow = index.row() - index.row()/4;
		int realCol = index.column();
		if (realCol == 2)
		{
			QString str;
			if (((index.row()+2)%4))
				return str.sprintf("%+.0lf", m_m[realRow][realCol]);
			else
				return str.sprintf("%+.0lf/%+.0lf", m_m[realRow][realCol], m_m[realRow][realCol+1]);
			//return tr("%1/%2").m_m[realRow][realCol];
		}
		else
			realCol += realCol>2;
		if (m_m.size() > realRow && m_m.first().size() > realCol)
		{
			return m_m[realRow][realCol];
		}
	}
	return QVariant();
}

QVariant Niveler3Class::headerData(int section, Qt::Orientation orientation, int role/* = Qt::DisplayRole */) const
{
	if ( role != Qt::EditRole && role != Qt::DisplayRole )
		return QVariant();
	if (orientation==Qt::Vertical)
	{
		if ( section == m_m.size() + m_m.size()/3 - 1 )
			return QVariant(tr("Кон.\nвыч."));
		else if ( !(section%4) )
			return QVariant( section/4+1 );
		else if ( !((section-1) % 4) )
			return  QVariant( tr( !(section/4%2) ? "1-2" : "2-1") );
		else
			return QVariant();
	}
	else if (orientation == Qt::Horizontal && section >= 0 && section < m_colCount)
	{
		return m_columnNames[section];
	}
	return QVariant();
}

int Niveler3Class::rowCount(const QModelIndex & parent/* = QModelIndex()*/ ) const
{
	return m_m.size() + m_m.size()/3;
}

int Niveler3Class::columnCount(const QModelIndex & parent/* = QModelIndex() */) const
{
	return m_colCount - 1; // because is one doubled column
}

bool Niveler3Class::setData(const QModelIndex & index, const QVariant & value, int role/* = Qt::EditRole */)
{
	if ( role != Qt::EditRole || !index.isValid())
		return false;
	int realRow = index.row() - index.row()/4;
	int realCol = index.column();
	int col = index.column();
	realCol += realCol > 2;
	bool ok = false;
	if (realRow < m_m.size() && realCol < m_m.first().size() &&
		((index.row()+1)%4) && ((index.row()+2)%4) && (col == 0 || col == 1 || col == 3 || col == 4))
	{
		m_m[realRow][realCol] = value.toDouble(&ok);
		if (ok)
			emit dataChanged(index, index);
	}
	return ok;
}

void Niveler3Class::addMeasure()
{
	beginInsertRows(QModelIndex(), rowCount()-1, rowCount()+2);
	qDebug() << "insert: " << rowCount()-1 << rowCount()+2;
	measures++;
	m_m.insert(m_m.size()-1, 3, QVector<double>(m_colCount, 0));
	endInsertRows();
}

void Niveler3Class::deleteMeasure()
{
	int rowCnt = rowCount();
	if (rowCnt <= 5)
		return;
	beginRemoveRows(QModelIndex(), rowCount()-4, rowCount()-1);
	measures--;
	m_m.remove(m_m.size()-4, 3);
	endRemoveRows();
}

void Niveler3Class::calculate()
{
	int i, row, j;
	for (i=0; i < measures; i++)
	{
		row = i*3;
		for (j=0; j<2; ++j) // 9 10
			m_m[row+2][j] = m_m[row+1][j] - m_m[row][j];
		for (j=0; j<2; ++j) // 11 12
			m_m[row+j][2] = m_m[row+j][0] - m_m[row+j][1];
		// 13
		m_m[row+2][2] = m_m[row+2][0] - m_m[row+2][1];
		m_m[row+2][3] = m_m[row+2][2] + (i ? m_m[row-3][3] : 0);
		for (j=0; j<2; ++j) // 14 15
			m_m[row+j][6] = m_m[row+j][4] - m_m[row+j][5];
		for (j=0; j<2; ++j) // 16 17
			m_m[row+2][4+j] = m_m[row+1][4+j] - m_m[row][4+j];
		m_m[row+2][4+2] = m_m[row][4+2] - m_m[row+1][4+2]; // 18
		m_m[row+1][7] = (m_m[row][6] + m_m[row+1][6] + m_m[row+2][6])/2;
	}
	emit layoutChanged();
}
