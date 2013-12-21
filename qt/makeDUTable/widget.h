#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore>
#include <QtGui>

class Widget : public QWidget
{
    Q_OBJECT

	QDir dir;
	int depth;
	QVector <QVector <QString> > data;
	QVector <QString> current;

	QTextEdit *output;
	QPushButton *openDirBtn;
	QPushButton *rescanBtn;
	QLineEdit *pathEd;

	void dfsDir();
public slots:
	void openDir();
	void scan();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
