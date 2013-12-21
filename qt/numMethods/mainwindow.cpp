#include "mainwindow.h"
#include "ui_mainwindow.h"

#define toQStr(_x_) QString::number(_x_)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	finDiffTab = new QTableWidget();
	lagrangeTab = new QTextEdit();
	newtonTab = new QTextEdit();
	graphWidget = new GraphWidget();

	lagrangeTab->setReadOnly(true);

	xyHeaders << tr("x") << tr("y");
	finDiffTab->setColumnCount(2);
	finDiffHeaders << tr("xi") << tr("yi");
	finDiffTab->setVerticalHeaderLabels(finDiffHeaders);
	finDiffTab->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("xi")));
	finDiffTab->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("yi")));


	ui->tabWidget->addTab(graphWidget, tr("График ф-ии"));
	ui->tabWidget->addTab(lagrangeTab, tr("Многочлен Лагранжа"));
	ui->tabWidget->addTab(finDiffTab, tr("Конечные суммы"));
	ui->tabWidget->addTab(newtonTab, tr("Формула Ньютона"));

	connect(ui->countBox, SIGNAL(valueChanged(int)), SLOT(setPointCount(int)));
	connect(ui->calcButton, SIGNAL(clicked()), SLOT(calculate()));
	connect(ui->clearButton, SIGNAL(clicked()), SLOT(clear()));
	connect(ui->actionAbout, SIGNAL(triggered()), SLOT(about()));
	connect(ui->actionClear, SIGNAL(triggered()), SLOT(clear()));
	connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(ui->actionQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

	ui->countBox->setValue(3);
	setPointCount(ui->countBox->value());
	ui->inputVals->setMaximumHeight(ui->inputVals->rowHeight(0)*4);
}

QVariant getItemDataOrCreate(QTableWidget *w, int row, int col)
{
	QTableWidgetItem *item = w->item(row, col);
	if (item != NULL)
		return item->data(Qt::DisplayRole);
	else
	{
		item = new QTableWidgetItem();
		item->setData(Qt::DisplayRole, 0.0);
		w->setItem(row, col, item);
		return QVariant();
	}
}

void setItemValue(QTableWidget* w, int row, int col, const QVariant &data)
{
	QTableWidgetItem *it;
	it = w->item(row, col);
	if (it == NULL)
	{
		it = new QTableWidgetItem();
		it->setData(Qt::DisplayRole, data);
		w->setItem(row, col, it);
		return;
	}
	it->setData(Qt::DisplayRole, data);
}

void MainWindow::setPointCount(int count)
{
	N = count;
	finDiffTab->setRowCount(count+1);
	finDiffTab->setColumnCount(count+2);
	ui->inputVals->setColumnCount(count+1);

	QString deltaPattern = tr("Δ%1 yi");
	for (int i=finDiffHeaders.size()-1; i<=count; i++)
	{
		if (i!=1)
			finDiffHeaders.append(deltaPattern.arg(i));
		else
			finDiffHeaders.append(tr("Δ yi"));
	}
	for (int i=indexHeaders.size(); i<=count; i++)
	{
		indexHeaders.append(toQStr(i));
	}
	finDiffTab->setHorizontalHeaderLabels(finDiffHeaders);
	finDiffTab->setVerticalHeaderLabels(indexHeaders);
	ui->inputVals->setHorizontalHeaderLabels(indexHeaders);
}

void MainWindow::clear()
{
	ui->inputVals->clear();
	finDiffTab->clear();
	lagrangeTab->clear();
	ui->inputVals->setHorizontalHeaderLabels(indexHeaders);
	ui->inputVals->setVerticalHeaderLabels(xyHeaders);
	finDiffTab->setVerticalHeaderLabels(indexHeaders);
	finDiffTab->setHorizontalHeaderLabels(finDiffHeaders);
}

void MainWindow::calculate()
{
	QWidget * w = ui->tabWidget->currentWidget();
	readData();
	if (w == finDiffTab)
	{
		finiteDifferences();
	}
	else if (w == lagrangeTab)
	{
		lagrange(m_x);
	}
	else if (w == newtonTab)
	{
		if (abs(v_x[0]-m_x) < abs(v_x[1]-v_x[0]))
			newtonMethod1(m_x);
		else if (abs(v_x[N]-m_x) < abs(v_x[N]-v_x[N-1]))
			newtonMethod2(m_x);
		else
			newtonTab->setText(tr("Невозможно применить ни одну формулу Ньютона - точка находится слишом далеко от x<sub>0</sub> и x<sub>n</sub>"));
	}
	else if (w == graphWidget)
	{
		Path *p = new Path();
		double x, y, maxX = graphWidget->maxX();
		double step = 1 / graphWidget->scale() * 2;
		for (x = graphWidget->minX(); x <= maxX; x+=step)
		{
			y = lagrange(x, false);
			p->addPoint(QPointF(x, y));
		}
		qDebug() << "Path length: " << p->size();
		graphWidget->clearPaths(true);
		graphWidget->addPath(p);
		graphWidget->repaint();
	}
}

double MainWindow::inflPolinom(double x, int num)
{
	double res = 1;
	for (int i=0; i <= N; i++)
		if (i != num)
			res *= (x - v_x[i]) / (v_x[num] - v_x[i]);
	return res;
}

double MainWindow::lagrange(double x, bool out/* = true*/)
{
	double res = 0;
	double inflPolinomVal;
	if (out)
	{
		lagrangeTab->clear();
		lagrangeTab->append( tr("Интерполирование методом Лагранжа:\nx = %1\nn = %2\nМногочлены влияния:").arg(toQStr(x), toQStr(N)) );
	}
	QString str(tr("L<sub>%2</sub>(%1) = %3").arg(x));

	for (int i=0; i <= N; i++)
	{
		inflPolinomVal = inflPolinom(x, i);
		if (out)
			lagrangeTab->append( str.arg(i).arg(inflPolinomVal) );
		res += inflPolinomVal * v_y[i];
	}

	if (out)
		lagrangeTab->append( tr("f(%1) = %2").arg(x).arg(res) );
	return res;
}

void MainWindow::calcFinDiff()
{
	int i, j;

	finDiff.resize(N+1);
	finDiff[0].resize(N+1);
	for (i=0; i<=N; i++)
		finDiff[0][i] = v_y[i];
	for (i=1; i<=N; i++)
	{
		finDiff[i].resize(N+1-i);
		for (j=0; j<=N-i; j++)
		{
			finDiff[i][j] = finDiff[i-1][j+1] - finDiff[i-1][j];
		}
	}
}

void MainWindow::finiteDifferences()
{
	int i, j;

	calcFinDiff();
	for (i=0; i<=N; i++)
	{
		setItemValue(finDiffTab, i, 0, v_x[i]);
		setItemValue(finDiffTab, i, 1, v_y[i]);
	}
	for (i=1; i<=N; i++)
	{
		for (j=0; j<=N-i; j++)
		{
			setItemValue(finDiffTab, j, i+1, finDiff[i][j]);
		}
	}
}


double MainWindow::newtonMethod1(double x, bool out/* = true*/)
{
	int i, j;
	double t = (x - v_x[0]) / (v_x[1]-v_x[0]);
	double r=0, b;

	//calcFinDiff();
	finiteDifferences();
	if (out)
	{
		newtonTab->clear();
		newtonTab->append(tr("Интерполирование по 1 интерполяционной формуле Ньютона\n"
							 "x = %1\nt = (%1 - %2) / %3 = %4").arg(toQStr(x),
															   toQStr(v_x[0]),
															   toQStr(v_x[1]-v_x[0]),
															   toQStr(t)));
		newtonTab->append(tr("y<sub>0</sub> = %1").arg(v_y[0]));
	}
	if (!out)
	{
		for (i=N; i>0; i--) // правильно, но б-дло не поймет
		{
			b = finDiff[i][0];
			r += b;
			r *= (t-i+1)/i;
		}
		r += finDiff[0][0];
	}
	else
	{
		r = b = v_y[0];
		QString cs1(tr("Δy<sub>0</sub>*t = %1"));
		QString cs2(tr("Δ<sup>%1</sup>y<sub>0</sub>/%1! * (t)...(t-%1-1) = %2"));
		for (i=1; i<=N; i++)
		{
			b = finDiff[i][0];
			for (j=0; j<i; j++)
				b *= (t-j)/(j+1);
			if (i>1)
				newtonTab->append(cs2.arg(toQStr(i), toQStr(b)));
			else
				newtonTab->append(cs1.arg(toQStr(b)));
			r += b;
		}
		newtonTab->append(tr("f(%1) = %2").arg(toQStr(x), toQStr(r)));
	}
	return r;
}

double MainWindow::newtonMethod2(double x, bool out /*= true*/)
{
	int i, j;
	double t = (x - v_x[N]) / (v_x[N]-v_x[N-1]);
	double r, b;

	//calcFinDiff();
	finiteDifferences();
	if (out)
	{
		newtonTab->clear();
		newtonTab->append(tr("Интерполирование по 2 интерполяционной формуле Ньютона\n"
							 "x = %1\nt = (%1 - %2) / %3 = %4").arg(toQStr(x),
															   toQStr(v_x[N]),
															   toQStr(v_x[N]-v_x[N-1]),
															   toQStr(t)));
		newtonTab->append(tr("y<sub>n</sub> = %1").arg(v_y[N]));
	}
	if (!out)
	{
		r = 0;
		for (i=N; i>0; i--) // правильно, но б-дло не поймет
		{
			b = finDiff[i][N-i];
			r += b;
			r *= (t+i-1)/i;
		}
		r += finDiff[0][N];
	}
	else
	{
		r = b = v_y[N];
		QString cs1(tr("Δy<sub>n-1</sub>*t = %1"));
		QString cs2(tr("Δ<sup>%1</sup>y<sub>%2</sub>/%1! * (t)...(t+%1-1) = %3"));
		for (i=1; i<=N; i++)
		{
			b = finDiff[i][N-i];
			for (j=0; j<i; j++)
				b *= (t+j)/(j+1);
			if (i>1)
				newtonTab->append(cs2.arg(toQStr(i), toQStr(N-i), toQStr(b)));
			else
				newtonTab->append(cs1.arg(toQStr(b)));
			r += b;
		}
		newtonTab->append(tr("f(%1) = %2").arg(toQStr(x), toQStr(r)));
	}
	return r;
}


void MainWindow::readData()
{
	int i;
	v_x.resize(ui->inputVals->columnCount());
	v_y.resize(ui->inputVals->columnCount());
	m_x = ui->doubleSpinBox->value();
	for (i=0; i <= N; i++)
	{
		v_x[i]=getItemDataOrCreate(ui->inputVals, 0, i).toDouble();
		v_y[i]=getItemDataOrCreate(ui->inputVals, 1, i).toDouble();
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about()
{
	QMessageBox::about(this,
					   tr("О программе..."),
					   tr("<b>Реализация алгоритмов численных методов, версия 0.1</b><br>"
						  "Функционал:"
						  "<ul>"
						  "<li>Построение графика интерполяционного многочлена</li>"
						  "<li>Метод Лагранжа</li>"
						  "<li>Конечные разности</li>"
						  "<li>1-ый и 2-й интерполционный многочлен Ньютона</li>"
						  "</ul>"
						  "По вопросам ошибок и добавления функционала обращаться на <a href=\"mailto:chemikadze@gmail.com\">chemikadze@gmail.com</a>"));
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
