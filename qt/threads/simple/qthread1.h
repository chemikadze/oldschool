#ifndef QTHREAD1_H
#define QTHREAD1_H

#include <QThread>
#include <QDebug>

class QThread1 : public QThread
{
public:
    int val;
    void run();
    QThread1();
};

#endif // QTHREAD1_H
