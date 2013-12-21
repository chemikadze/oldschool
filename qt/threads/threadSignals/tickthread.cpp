#include "tickthread.h"

tickThread::tickThread()
{
}

void tickThread::run()
{
    for (int i=0; i < 11*10; i++)
    {
	usleep(100000);
	emit tick();
    }
}
