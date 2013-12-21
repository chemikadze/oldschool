#include <QtCore>
#include <QtGui>

#define for_all(_X_) for(i=0;i<_X_.size();i++)

int main(int argc, char* argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	QApplication app(argc, argv);
	QTreeView tree;	
	QStandardItemModel model(5, 3);

	int nTopRow, nRow, nCol;
	QModelIndex index;
	for (nTopRow=0; nTopRow<5; nTopRow++)
	{
		index=model.index(nTopRow, 0);
		model.setData(index, "item"+QString::number(nTopRow+1));
		model.insertRows(0, 4, index);
		model.insertColumns(0, 3, index);
		for (nRow=0; nRow<4; nRow++)
			for (nCol=0; nCol<3; nCol++)
				model.setData(model.index(nRow, nCol, index), QString("%1,%2").arg(nRow).arg(nCol));
		
	}
	tree.setModel(&model);
	tree.show();

	return app.exec();	
}
