#include "timer.h"
using std::min;

void QMyClock::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen pen(Qt::black, 10, Qt::DashLine);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.drawEllipse((this->width()-min(this->width(), this->height()))/2, (this->height()-min(this->width(), this->height()))/2, min(this->width(), this->height()), min(this->width(), this->height()));
    painter.drawLine(this->width()/2, this->height()/2, (this->width()-min(this->width(), this->height()))/2+min(this->width(), this->height())/2*(1+cos(2*M_PI/60*(timer-time0)-M_PI/2)), (this->height()-min(this->width(), this->height()))/2+min(this->height(), this->width())/2*(1+sin(2*M_PI/60*(timer-time0)-M_PI/2)));
    painter.end();
}


void QMyClock::startTimer()
{
    if (!qtimer.isActive())
    {
        //time0+=(time(NULL)-timer);
        qtimer.start(1000);
        //time(&timer);
    }
    else
        this->zero();
    this->update();
    emit timeChanged(timer-time0);
}

void QMyClock::stopTimer()
{
    if (qtimer.isActive())
        qtimer.stop();
    else
    {
        this->zero();
        emit timeChanged(timer-time0);
    }
    this->update();

}

void QMyClock::zero()
{
    //time(&timer);
    time0=timer=0;
    this->update();
    emit timeChanged(timer-time0);
}

void QMyClock::updateTimer()
{
    if (time(NULL)!=timer)
    {
        //time(&timer);
        timer++;
        emit timeChanged(timer-time0);
        this->update();
    }
}

QMyClock::QMyClock(QWidget *parent/*=0*/):QWidget(parent)
{
    QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    policy.setHeightForWidth(true);

    this->setWindowTitle(tr("Таймер"));
    this->setAutoFillBackground(true);
    this->setMinimumWidth(100);
    this->setMinimumHeight(100);
    this->resize(300, 300);
    //	this->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    this->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));

    qtimer.setInterval(1000);
    if (qtimer.isActive()) qtimer.stop();
    QObject::connect(&qtimer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    this->zero();
}
