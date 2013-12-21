#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *la=new QGridLayout;
    lbl1=new QLabel("thread1");
    lbl2=new QLabel("thread2");
    thread1=new Thread(&signals1, &running);
    thread2=new Thread(&signals2, &running);
    startButton=new QPushButton(tr("Запустить"));
    bar=new QProgressBar();
    bar->setRange(0, 100);
    bar->setValue(50);
    slider1=new prioritySlider();
    slider2=new prioritySlider();
    timer=new QTimer();
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    /*
    =========
      (   )
	|
      */
    la->addWidget(bar, 0, 0, 1, 4);
    la->addWidget(startButton, 1, 1, 1, 2);
    la->addWidget(lbl1, 2, 0, 1, 2);
    la->addWidget(lbl2, 2, 2, 1, 2);
    la->addWidget(slider1, 3, 0, 1, 2);
    la->addWidget(slider2, 3, 2, 1, 2);
    setLayout(la);
    running=false;
    connect(startButton, SIGNAL(clicked()), this, SLOT(startStop()), Qt::DirectConnection);
}

void mainWindow::startStop()
{
    if (!thread1->isRunning())
    {
	signals1=signals2=1;
	sum=2;
	bar->setValue(50);
	running=true;
	qDebug() << slider1->value();
	qDebug() << slider2->value();
	thread1->start(slider1->value());
	thread2->start(slider2->value());
	timer->start();
	startButton->setText(tr("Остановить"));
    }
    else
    {
	timer->stop();
	qDebug() << "stop";
	thread1->stop();
	thread2->stop();
	startButton->setText(tr("Запустить"));
    }
}

void mainWindow::refresh()
{
    sum=signals1+signals2;
    bar->setValue(round(signals1*100/sum));
    lbl1->setText(QString().setNum(signals1));
    lbl2->setText(QString().setNum(signals2));
}

mainWindow::~mainWindow()
{

}
