#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QTextEdit>
#include <QtGui/QTableWidget>
#include <QtCore/QStringList>
#include <QtCore/QVector>
#include <QtGui/QMessageBox>
#include <QDebug>
#include "graphwidget.h"

inline double abs(double x) {return x>=0 ? x : -x;}

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
	~MainWindow();

	double inflPolinom(double x, int num);
	double lagrange(double x, bool out = true);
	void finiteDifferences();
	void calcFinDiff();
	double newtonMethod1(double x, bool out = true);
	double newtonMethod2(double x, bool out = true);

	void readData();

public slots:
	void setPointCount(int count);
	void calculate();
	void clear();
	void about();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
	QTableWidget *finDiffTab;
	QTextEdit *lagrangeTab;
	QTextEdit *newtonTab;
	GraphWidget *graphWidget;

	QStringList finDiffHeaders;
	QStringList indexHeaders;
	QStringList xyHeaders;

	double m_x;
	QVector <double> v_x;
	QVector <double> v_y;
	int N;
	QVector < QVector<double> > finDiff;

	void retranslate();
};

#endif // MAINWINDOW_H
