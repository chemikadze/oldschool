#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QtCore/QVector>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QSpinBox>

namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
	QVector <int> m_queries;
	int m_moveCount;

	void readQueries();
	void writeOutput(QVector <int> tab);

	QVector <int> algoFCFS();
	QVector <int> algoSSTF();
	QVector <int> algoScan(bool cycle = false);
	QVector <int> algoLook(bool cycle = false);

	void moveHead(int& pos, int newPos);

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
	void queryCountChanged(int val);
	void cylinderCountChanged(int val);
	void run();
	void shuffle();
	void generate();
	void algoChanged(int val);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
