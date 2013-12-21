#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <algorithm>
using std::min;

namespace Ui {
    class Widget;
}

typedef struct
{
	int id;
	int CPUburst;
	int apperance;
	int priority;
} Task;

typedef QVector <Task>  Tasks;
typedef QVector < QVector <char> > IntMatrix;

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

	IntMatrix fcfsSheduler(Tasks);
	IntMatrix rrSheduler(Tasks);
	IntMatrix sjfSheduler(Tasks);

protected:
	int taskCount;
	QVector <QString> methods;
	int avgFullExecutionTime;
	int avgWaitingTime;


	void changeEvent(QEvent *);
	bool event(QEvent *);
private:
	Ui::Widget *ui;

private slots:
	void changeTaskCount(int);
	void showPriority(bool);
	void showApperance(bool show);
	void generateInput();
	void shuffleInput();
	void run();
	void shedulerChanged(int index);
};

#define NO 0x0
#define READY 0x1
#define EXEC  0x2
#define WAIT  0x3

#endif // WIDGET_H
