#include "widget.h"
#include "ui_widget.h"
#include <QtGui/QTableWidgetItem>
#include <cmath>
#include <QLinkedList>
#include <set>
#include <algorithm>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
	ui->inputTable->setRowCount(1);
	ui->outputTable->setRowCount(1);

	connect(ui->queryCount, SIGNAL(valueChanged(int)),
							SLOT(queryCountChanged(int)));
	connect(ui->cylinderCount, SIGNAL(valueChanged(int)),
							SLOT(cylinderCountChanged(int)));
	connect(ui->runButton, SIGNAL(clicked()),
						   SLOT(run()));
	connect(ui->generateButton, SIGNAL(clicked()),
								SLOT(generate()));
	connect(ui->runButton, SIGNAL(clicked()),
						   SLOT(run()));
	connect(ui->shuffleButton, SIGNAL(clicked()),
							   SLOT(shuffle()));
	connect(ui->algoBox, SIGNAL(currentIndexChanged(int)),
						 SLOT(algoChanged(int)));
	ui->queryCount->setValue(10);
	ui->cylinderCount->setValue(100);
	ui->startPosition->setValue(15);

	ui->algoBox->insertItem(0, tr("FCFS (First Come First Served)"));
	ui->algoBox->insertItem(1, tr("SSTF (Short Seek Time First)"));
	ui->algoBox->insertItem(2, tr("Scan"));
	ui->algoBox->insertItem(3, tr("C-Scan"));
	ui->algoBox->insertItem(4, tr("Look"));
	ui->algoBox->insertItem(5, tr("C-Look"));
	ui->algoBox->setCurrentIndex(5);
}

void Widget::queryCountChanged(int val)
{
	int oldSize = ui->inputTable->columnCount();

	ui->inputTable->setColumnCount(val);
	for (int i = oldSize; i < val; i++)
	{
		QTableWidgetItem *item = new QTableWidgetItem();
		item->setData(Qt::DisplayRole, 0);
		ui->inputTable->setItem(0, i, item);
	}
}

void Widget::cylinderCountChanged(int val)
{
	for (int i=0; i < ui->inputTable->columnCount(); ++i)
	{
		QTableWidgetItem *item = ui->inputTable->item(0, i);
		item->setData(Qt::DisplayRole, item->data(Qt::DisplayRole).toInt() % ui->cylinderCount->value() );
	}
	ui->startPosition->setMaximum(val);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::run()
{
	readQueries();
	m_moveCount = 0;
	QVector <int> res;
	switch (ui->algoBox->currentIndex())
	{
	case 0: // FCFS
		res = algoFCFS();
		break;
	case 1: // SSTF
		res = algoSSTF();
		break;
	case 2: // Scan
		res = algoScan();
		break;
	case 3: // C-Scan
		res = algoScan(true);
		break;
	case 4: // Look
		res = algoLook();
		break;
	case 5: // C-Look
		res = algoLook(true);
		break;
	}
	ui->infoLabel->setText( tr("Длина пробега головки жесткого диска: %1").arg(m_moveCount) );
	writeOutput(res);
	ui->hddSheme->setVector(res);
	ui->hddSheme->setCylinderCount(ui->cylinderCount->value());
	ui->hddSheme->play();
}

QVector <int> Widget::algoFCFS()
{
	QVector <int> res;
	res.reserve(m_queries.size()+1);

	int pos = ui->startPosition->value();
	res.push_back(pos);

	for (int i=0; i < m_queries.size(); ++i)
	{
		moveHead(pos, m_queries[i]);
		res.push_back(pos);
	}

	return res;
}

QVector <int> Widget::algoSSTF()
{
	QVector <int> res;
	res.reserve(m_queries.size()+1);

	int pos = ui->startPosition->value();
	res.push_back(pos);

	std::multiset <int> unused;
	foreach (int elem, m_queries)
		unused.insert(elem);

	while (unused.size())
	{
		int next, minDist = INT_MAX;
		std::multiset <int>::iterator nextIt = unused.end();
		for (std::multiset<int>::iterator i = unused.begin(); i!=unused.end(); ++i)
		{
			if (abs(*i-pos) < minDist)
			{
				next = *i;
				minDist = abs(*i-pos);
				nextIt = i;
			}
		}
		unused.erase(nextIt);
		moveHead(pos, next);
		res.push_back(pos);
	}

	return res;
}

QVector <int> Widget::algoScan(bool cycle /* = false */)
{
	QVector <int> res;
	res.reserve(m_queries.size()+1);
	enum Direction { LeftToRight, RightToLeft } direction;
	direction = ui->directionBar->value() ? LeftToRight : RightToLeft;

	int pos = ui->startPosition->value();
	res.push_back(pos);

	m_queries.append(pos);
	qSort(m_queries);
	QLinkedList <int> unread;
	foreach (int val, m_queries)
		unread.append(val);
	QLinkedList <int>::iterator it;
	if (direction == LeftToRight)
		for (it = unread.begin(); *it!=pos; ++it);
	else
		for (it = unread.end()-1; *it!=pos; --it);

	while (unread.count()-1)
	{
		if (direction == LeftToRight)
		{
			if (it+1 != unread.end())
			{
				moveHead(pos, *(++it));
				res.push_back(pos);
				unread.erase(it-1);
			}
			else
			{
				if (cycle)
				{
					moveHead(pos, ui->cylinderCount->value());
					res.push_back(pos);
					moveHead(pos, 0);
					res.push_back(pos);

					unread.erase(it);
					it = unread.begin();
					moveHead(pos, *it);
					res.push_back(pos);
				}
				else
				{
					moveHead(pos, ui->cylinderCount->value());
					res.push_back(pos);

					direction = RightToLeft;
				}
			}
		}
		else
		{
			if (it != unread.begin())
			{
				moveHead(pos, *(--it));
				res.push_back(pos);
				unread.erase(it+1);
			}
			else
			{
				if (cycle)
				{
					moveHead(pos, 0);
					res.push_back(pos);
					moveHead(pos, ui->cylinderCount->value());
					res.push_back(pos);

					unread.erase(it);
					it = unread.end()-1;
					moveHead(pos, *(it));
					res.push_back(pos);
				}
				else
				{
					moveHead(pos, 0);
					res.push_back(pos);

					direction = LeftToRight;
				}
			}
		}
	}

	return res;
}

// LOOK и C-LOOK
QVector <int> Widget::algoLook(bool cycle /* = false */ )
{
	// выделяем память для результата
	QVector <int> res;
	res.reserve(m_queries.size()+1);
	// направление движения
	enum Direction { LeftToRight, RightToLeft } direction;
	direction = ui->directionBar->value() ? LeftToRight : RightToLeft;

	// текущая позиция
	int pos = ui->startPosition->value();
	res.push_back(pos);

	// подготавливаем очередь для обработки
	m_queries.append(pos);
	qSort(m_queries);
	// копируем в связный список для удаления за O(1)
	QLinkedList <int> unread;
	foreach (int val, m_queries)
		unread.append(val);
	// итератор текущей позиции
	QLinkedList <int>::iterator it;
	// находим первоначальную позицию в списке
	if (direction == LeftToRight)
		for (it = unread.begin(); *it!=pos; ++it);
	else
		for (it = unread.end()-1; *it!=pos; --it);

	// пока есть куда переходить
	while (unread.count()-1)
	{
		if (direction == LeftToRight)	// если движемся направо
		{
			if (it+1 != unread.end())	// если не крайний
			{
				moveHead(pos, *(++it)); // перемещаемся
				res.push_back(pos);
				unread.erase(it-1);		// и удаляем обработанный
			}
			else
			{							// если крайний
				if (cycle)				// если C-LOOK
				{
					unread.erase(it);	// удаляем текущую позицию
					it = unread.begin();// переходим в начало
					moveHead(pos, *it);
					res.push_back(pos);
				}
				else					// если LOOK
				{						// меняем направление
					direction = RightToLeft;
				}
			}
		}
		else
		{
			if (it != unread.begin())	// если не крайний
			{
				moveHead(pos, *(--it));	// перемещаемся
				res.push_back(pos);
				unread.erase(it+1);		// и удаляем прошлый
			}
			else
			{
				if (cycle)				// если C-LOOK
				{
					unread.erase(it);	// удаляем обработанный
					it = unread.end()-1;
					moveHead(pos, *(it));// перемещаемся
					res.push_back(pos);
				}
				else					// если LOOK
				{						// меняем направление
					direction = LeftToRight;
				}
			}
		}
	}

	return res;							// возвращаем результат
}

void Widget::readQueries()
{
	m_queries.resize( ui->queryCount->value() );
	for (int i=0; i < m_queries.count(); ++i)
	{
		QTableWidgetItem *item = ui->inputTable->item(0, i);
		if (item)
			m_queries[i] = item->data(Qt::DisplayRole).toInt();
		else
			m_queries[i] = 0;
	}
}

void Widget::writeOutput(QVector <int> tab)
{
	ui->outputTable->setColumnCount(tab.count());
	for (int i=0; i < tab.count(); ++i)
	{
		QTableWidgetItem *item = ui->outputTable->item(0, i);
		if (item)
			item->setData(Qt::DisplayRole, tab[i]);
		else
		{
			item = new QTableWidgetItem();
			item->setFlags( (item->flags() | Qt::ItemIsEditable) ^ Qt::ItemIsEditable );
			item->setData( Qt::DisplayRole, tab[i] );
			ui->outputTable->setItem(0, i, item);
		}
	}
}

void Widget::generate()
{
	for (int i=0; i < ui->inputTable->columnCount(); ++i)
	{
		QTableWidgetItem *item = ui->inputTable->item(0, i);
		item->setData(0, rand() % ui->cylinderCount->value() );
	}
}

void Widget::shuffle()
{
	// Fisher-Yates algorithm
	for (int i=ui->inputTable->columnCount()-1; i > 0; --i)
	{
		int k = rand() % (i+1);
		if (k == i)
			continue;
		QTableWidgetItem *itemI = ui->inputTable->takeItem(0, i);
		QTableWidgetItem *itemK = ui->inputTable->takeItem(0, k);

		ui->inputTable->setItem(0, k, itemI);
		ui->inputTable->setItem(0, i, itemK);
	}
}

void Widget::moveHead(int& pos, int newPos)
{
	m_moveCount += abs(pos - newPos);
	pos = newPos;
}

void Widget::algoChanged(int val)
{
	ui->directionBar->setEnabled(val >= 2 && val <= 5);
}
