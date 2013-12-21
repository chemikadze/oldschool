#include <QtCore>
#include <QtGui>

class MyValidator : public QValidator
{
	public:
		MyValidator(QObject* parent=NULL):QValidator(parent) {}
		virtual State validate(QString& str,int& pos)const
		{
			QRegExp rgx(QObject::tr("[0-9А-Я]"));
			return str.contains(rgx) ? Invalid : Acceptable;
		}
};

int main(int argc, char* argv[])
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

	QApplication app(argc, argv);
	
	QWidget * wdgt=new QWidget();
	QVBoxLayout * la=new QVBoxLayout();
	QLineEdit * ed;
	MyValidator * val=new MyValidator();

	ed=new QLineEdit();
	ed->setValidator(val);

	wdgt=ed;
	//wdgt->setLayout(la);
	wdgt->show();

	return app.exec();	
}
