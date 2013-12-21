#include "thread.h"
#include "priority.h"

Thread::Thread(double* p_data)
{
    data=p_data;
    b_running=new bool;
    *b_running=true;
}

Thread::Thread(double* p_data, bool *b_addr)
{
    b_running=b_addr;
    data=p_data;
}

void Thread::run()
{
    qDebug() << prioritySlider::getNameByPriority(priority());
    QImage *img;
    QPainter paint;
    for (; *b_running; )
    {
	// some resource-critical useless work
	img=new QImage(QSize(1400, 900), QImage::Format_ARGB32);
	paint.begin(img);
	paint.setBrush(Qt::Dense4Pattern);
	paint.drawEllipse(img->rect());
	paint.drawImage(img->rect(), QImage(*img));
	paint.end();
	delete img;
	// inc iteraions
	(*data)++;
    }
    qDebug() << " i finished";
}

void Thread::stop()
{
    qDebug() << "yes, master";
    *b_running=false;
}
