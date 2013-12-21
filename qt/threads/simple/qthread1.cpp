#include "qthread1.h"

QThread1::QThread1()
{
    val=0;
}

void QThread1::run()
{
    while (true)
	val++;
}
