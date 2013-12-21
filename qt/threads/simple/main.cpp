#include <QtCore>
#include "qthread1.h"
#include "qthread2.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QThread1 tr1;
    QThread2 tr2;

    tr1.start();
    tr2.start();
    for (int i=0; i<1000; i++)
	qDebug() << tr1.val << tr2.val;

    return app.exec();
}
