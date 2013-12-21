#include <QtCore>
#include <QtGui>

#define for_all(_X_) for(i=0;i<_X_.size();i++)

class SimpleDelegate : public QItemDelegate
{
	public:
	SimpleDelegate(QObject *obj = 0) : QItemDelegate(obj)
	{
	}

	void paint(QPainter* painter, const QStyleOptionViewItem &style, const QModelIndex& index)const
	{
		if (style.state & QStyle::State_MouseOver)
		{
			QRect rect(style.rect);
			QLinearGradient gradient(0, 0, rect.width(), rect.height());
			gradient.setColorAt(0, Qt::white);
			gradient.setColorAt(0.5, Qt::green);
			gradient.setColorAt(1, Qt::blue);
			painter->setBrush(gradient);
			painter->drawRect(rect);
		}
		QItemDelegate::paint(painter, style, index);
	} 
	
};

int main(int argc, char* argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	QApplication app(argc, argv);
	
	QWidget wgt;
	QHBoxLayout * la=new QHBoxLayout();
	QTreeView *tree=new QTreeView();
	QListView *list=new QListView();
	QTableView *table=new QTableView();

	QStringListModel *model=new QStringListModel();
	model->setStringList(QStringList() << "One" << "Two" << "Three");

	QItemSelectionModel * selection=new QItemSelectionModel(model);
	
	tree->setModel(model);
	list->setModel(model);
	table->setModel(model);

	tree->setSelectionModel(selection);
	list->setSelectionModel(selection);
	table->setSelectionModel(selection);

	list->setItemDelegate(new SimpleDelegate(list));
	list->viewport()->setAttribute(Qt::WA_Hover);
	tree->setItemDelegate(new SimpleDelegate(tree));
	table->setItemDelegate(new SimpleDelegate(table));
	tree->viewport()->setAttribute(Qt::WA_Hover);
	table->viewport()->setAttribute(Qt::WA_Hover);
	
	la->addWidget(tree);
	la->addWidget(list);
	la->addWidget(table);

	wgt.setLayout(la);
	wgt.show();

	return app.exec();	
}
