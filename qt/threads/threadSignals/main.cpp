#include <QApplication>
#include "progressbar.h"
#include "tickthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tickThread thread;
    progressBar bar;

    QObject::connect(&thread, SIGNAL(tick()), &bar, SLOT(step()));
    bar.show();
    thread.start();


    return a.exec();
}
