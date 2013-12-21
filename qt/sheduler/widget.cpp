#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
	ui->setupUi(this);

	ui->inputTable->setColumnCount(3);
	QStringList headers;
	headers << tr("CPU Burst") << tr("Время появления") << tr("Приоритет");
	ui->inputTable->setHorizontalHeaderLabels(headers);
	ui->inputTable->setColumnHidden(2, true);

	methods << tr("FCFS (First Come First Served)")
			<< tr("RR (Round Robin)")
			<< tr("SJF (Shortest Job First)");

	ui->shedulers->addItems(methods.toList());

	connect(ui->taskCount, SIGNAL(valueChanged(int)), this, SLOT(changeTaskCount(int)));
	connect(ui->usePriority, SIGNAL(toggled(bool)), this, SLOT(showPriority(bool)));
	connect(ui->useApperance, SIGNAL(toggled(bool)), this, SLOT(showApperance(bool)));
	connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(generateInput()));
	connect(ui->clearButton, SIGNAL(clicked()), ui->inputTable, SLOT(clearContents()));
	connect(ui->shuffleButton, SIGNAL(clicked()), this, SLOT(shuffleInput()));
	connect(ui->runButton, SIGNAL(clicked()), this, SLOT(run()));
	connect(ui->shedulers, SIGNAL(currentIndexChanged(int)), this, SLOT(shedulerChanged(int)));
	ui->taskCount->setValue(3);
	ui->useApperance->setChecked(true);
	ui->usePriority->setChecked(false);
	shedulerChanged(0);

	ui->resultLabel->setVisible(false);

	srand(time(NULL));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::run()
{
	Tasks tasks(taskCount);
	int i, j;
	QTableWidgetItem *item;
	for (i=0; i<taskCount; i++)
	{
		tasks[i].id	= i;
		item=ui->inputTable->item(i, 0);
		if (NULL==item ? true : ! item->data(Qt::DisplayRole).toInt())
		{
			if (NULL==item)
			{
				item=new QTableWidgetItem();
				item->setData(Qt::DisplayRole, 1);
				ui->inputTable->setItem(i, 0, item);
			}
			else
				item->setData(Qt::DisplayRole, 1);
		}
		tasks[i].CPUburst  = item->data(Qt::DisplayRole).toInt();
		tasks[i].apperance = NULL!=(item=ui->inputTable->item(i, 1)) && ui->useApperance->isChecked() ?
							 item->data(Qt::DisplayRole).toInt() : 0;
		if (ui->usePriority->isChecked())
			tasks[i].priority  = NULL!=(item=ui->inputTable->item(i, 2)) && ui->usePriority->isChecked() ?
								item->data(Qt::DisplayRole).toInt() : 0;
		else
			tasks[i].priority = tasks[i].CPUburst;
	}

	avgFullExecutionTime = 0;
	avgWaitingTime = 0;

	IntMatrix result;
	switch (ui->shedulers->currentIndex())
	{
		case 0:	// FCFS
			result = fcfsSheduler(tasks);
			break;
		case 1:	// RR
			result = rrSheduler(tasks);
			break;
		case 2:	// SJF
			result = sjfSheduler(tasks);
			break;
	}

	ui->outputTable->setColumnCount(result[0].size());
	for (i=0; i<result.size(); i++)
	{
		for (j=0; j<result[i].size(); j++)
		{
			item = NULL==(item=ui->outputTable->takeItem(i, j)) ? new QTableWidgetItem() : item;
			switch (result[i][j])
			{
				case NO:
					item->setText(tr(""));
					item->setBackgroundColor(Qt::white);
					break;
				case READY:
					item->setText(tr("R"));
					item->setBackgroundColor(QColor(153, 153, 255));
					break;
				case EXEC:
					item->setText(tr("E"));
					item->setBackgroundColor(Qt::green);
					break;
			}
			ui->outputTable->setItem(i, j, item);
		}
	}
	QStringList labels;
	for (i=0; i<ui->outputTable->colorCount(); i++)
		labels << QString::number(i);
	ui->outputTable->setHorizontalHeaderLabels(labels);
	ui->outputTable->resizeColumnsToContents();

	ui->resultLabel->setVisible(true);
	ui->resultLabel->setText(
			tr("Среднее полное время выполнения: %1\nСреднее время ожидания: %2")
			.arg(QString::number(double(avgFullExecutionTime)/taskCount),
				 QString::number(double(avgWaitingTime)/taskCount)));
}

bool lessThanTasksTime(const Task &first, const Task &second)
{
	return first.apperance < second.apperance;
}

IntMatrix Widget::fcfsSheduler(Tasks tasks)
{
	int tasksToDo=taskCount;
	int i;
	IntMatrix timeline(taskCount);
	QVector <int> states(taskCount, NO);
	QQueue <Task> appear;	// appearing queue
	for (i=0; i<tasks.size(); i++)
		appear.append(tasks[i]);
	qStableSort(appear.begin(), appear.end(), lessThanTasksTime);

	// stupid code, but full emulation needed
	int time;
	int interruptTime;
	int active;
	QQueue <Task> queue;
	for (time=0; tasksToDo; time++)
	{
		active = -1;
		if (queue.size())
		{
			active = queue.first().id;
			states[ active ] = EXEC;
			interruptTime = time+queue.first().CPUburst;
		}
		else
			interruptTime = appear.size() ? appear.first().apperance-1 : 0; // if no elements in queue
		bool noInterruption = time >= interruptTime;
		for (; time < interruptTime || noInterruption; time++, noInterruption=false)
		{
			while (appear.size() && time == appear.first().apperance)
			{
				queue.enqueue(appear.dequeue());
				states[ queue.last().id ] = READY;
			}
			if (active<0 && queue.size())
				break;
			for (i=0; i<taskCount; i++)
			{
				timeline[i].push_back(states[i]);
				if (states[i] != NO)
					this->avgFullExecutionTime++;
				if (states[i] == READY)
					this->avgWaitingTime++;
			}
		}
		time--;
		if (queue.size() && active>=0)
		{
			states[queue.dequeue().id] = NO;
			tasksToDo--;
		}
	}
	return timeline;
}

IntMatrix Widget::rrSheduler(Tasks tasks)
{
	int tasksToDo=taskCount;
	int i;
	IntMatrix timeline(taskCount);
	QVector <int> states(taskCount, NO);
	QQueue <Task> appear;	// appearing queue
	for (i=0; i<tasks.size(); i++)
		appear.append(tasks[i]);
	qStableSort(appear.begin(), appear.end(), lessThanTasksTime);

	// stupid code, but full emulation needed
	int time;
	int interruptTime;
	QQueue <Task> queue;
	int quantumSize = ui->quantumSize->value();
	int active;
	for (time=0; tasksToDo; time++)
	{
		active = -1;
		if (queue.size())
		{
			active = queue.first().id;
			states[ active ] = EXEC;
			interruptTime = time + min(queue.first().CPUburst, quantumSize);
			if (time <= interruptTime)
				queue.first().CPUburst-=interruptTime-time;
		}
		else
			interruptTime = appear.size() ? appear.first().apperance-1 : 0;  // if no elements in queue
		bool noInterruption = time >= interruptTime;
		for (; time < interruptTime || noInterruption; time++, noInterruption=false)
		{
			while (appear.size() && time == appear.first().apperance)
			{
				queue.enqueue(appear.dequeue());
				states[ queue.last().id ] = READY;
			}
			if (active<0 && queue.size())
				break;
			for (i=0; i<taskCount; i++)
			{
				timeline[i].push_back(states[i]);
				if (states[i] != NO)
					this->avgFullExecutionTime++;
				if (states[i] == READY)
					this->avgWaitingTime++;
			}
		}
		time--;
		if (queue.size() && active >= 0)
		{
			if (queue.first().CPUburst > 0)
			{
				states[active] = READY;
				queue.enqueue(queue.dequeue());
			}
			else
			{
				states[active] = NO;
				tasksToDo--;
				queue.dequeue();
			}
		}
	}
	return timeline;
}


// YOU DOING IT WRONG! mabe =)
IntMatrix Widget::sjfSheduler(Tasks tasks)
{
	int tasksToDo=taskCount;
	int i;
	IntMatrix timeline(taskCount);
	QVector <int> states(taskCount, NO);
	QQueue <Task> appear;	// appearing queue
	for (i=0; i<tasks.size(); i++)
		appear.append(tasks[i]);
	qStableSort(appear.begin(), appear.end(), lessThanTasksTime);

	// stupid code, but full emulation needed
	int time;
	int interruptTime;
	int active;
	QQueue <Task> queue;
	QQueue<Task>::Iterator it;
	for (time=0; tasksToDo; time++)
	{
		active = -1;
		if (queue.size())
		{
			active = queue.first().id;
			states[active] = EXEC;
			interruptTime = time + queue.first().CPUburst;
		}
		else
			interruptTime = appear.size() ? appear.first().apperance-1 : 0; // if no elements in queue
		bool noInterruption = time >= interruptTime;
		bool displace = false;
		for (; (time < interruptTime || noInterruption) && !displace; time++, noInterruption=false)
		{
			while (appear.size() && time == appear.first().apperance)
			{
				Task af = appear.dequeue();

				if (ui->usePriority->isChecked())
					for (it = queue.begin() + (active>=0 && !ui->displacement->isChecked());
						it != queue.end()  && queue.size() && ((*it).priority<af.priority || ((*it).priority==af.priority && (*it).CPUburst<af.CPUburst));
						++it,qDebug() << af.id << " p:" << af.priority << " a" << af.apperance);
				else
					for (it = queue.begin() + (active>=0 && !ui->displacement->isChecked());
						it != queue.end()  && queue.size() && ((*it).CPUburst<=af.CPUburst);
						++it,qDebug() << af.id << " p:" << af.priority << " a" << af.apperance);
				if (it == queue.begin() && active>=0)
				{
					if (ui->displacement->isChecked() || ((*it).apperance==af.apperance))
					{
						states[active]=READY;
						active = -1;
					}
					else
						++it;
				}
				queue.insert(it, af);
				states[ af.id ] = READY;

			}
			if (active>=0)
				queue.first().CPUburst--;
			else
				if (queue.size())
					break;
			for (i=0; i<taskCount && !displace; i++)
			{
				timeline[i].push_back(states[i]);
				if (states[i] != NO)
					this->avgFullExecutionTime++;
				if (states[i] == READY)
					this->avgWaitingTime++;
			}
		}
		time--;
		if (active >= 0)
		{
			if (queue.first().CPUburst > 0)
			{
				states[active] = READY;
			}
			else
			{
				states[active] = NO;
				tasksToDo--;
				queue.dequeue();
			}
		}
	}
	return timeline;
}

void Widget::showPriority(bool show)
{
	ui->inputTable->setColumnHidden(2, !show);
}

void Widget::showApperance(bool show)
{
	ui->inputTable->setColumnHidden(1, !show);
}

void Widget::changeTaskCount(int count)
{	
	ui->inputTable->setRowCount(count);
	ui->outputTable->setRowCount(count);
	ui->outputTable->clear();
	taskCount = count;
}

void Widget::shedulerChanged(int index)
{
	ui->displacement->setEnabled(index == 2);
	ui->usePriority->setEnabled(index == 2);
	ui->inputTable->setColumnHidden(2, index!=2 || !ui->usePriority->isChecked());
	ui->quantumSize->setEnabled( index == 1 );
}

void Widget::generateInput()
{
	for (int i=0; i<taskCount; i++)
		for (int j=0; j<3; j++)
		{
			int val = (val=rand()%15) || j ? val : 1;
			QTableWidgetItem *item = ui->inputTable->item(i, j);
			if (item != NULL)
				item->setData(Qt::DisplayRole, val);
			else
			{
				item = new QTableWidgetItem;
				item->setData(Qt::DisplayRole, val);
				ui->inputTable->setItem(i, j, item);
			}
		}
}

void Widget::shuffleInput()
{
	QVector <bool> w(taskCount, true);
	for (int i=0; i<taskCount-1; i++)
	{
		if (w[i])
		{
			int second = rand()%(taskCount-i-1)+i+1;
			qDebug() << second;
			for (int j=0; j<3; j++)
			{
				QTableWidgetItem *item1 = ui->inputTable->takeItem(i, j);
				QTableWidgetItem *item2 = ui->inputTable->takeItem(second, j);
				ui->inputTable->setItem(i, j, item2);
				ui->inputTable->setItem(second, j, item1);
			}
			//w[i] = false;
			//w[second] = false;
		}
	}
	ui->inputTable->setInputMethodHints(Qt::ImhDigitsOnly);
}

//  events

bool Widget::event(QEvent *e)
{
	if (e->type()==QEvent::Resize || e->type()==QEvent::Show)
	{
		int clientWidth = ui->inputTable->viewport()->width();
		int colCount = ui->inputTable->columnCount();
		for (int i=0; i<colCount; i++)
			ui->inputTable->setColumnWidth(i, clientWidth / colCount);
	}
	return QWidget::event(e);
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
