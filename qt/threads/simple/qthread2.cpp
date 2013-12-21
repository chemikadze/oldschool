#include "qthread2.h"

QThread2::QThread2()
{
	val=0;
}

void QThread2::run()
{
    while (true)
	val++;
}
