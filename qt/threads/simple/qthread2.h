#ifndef QTHREAD2_H
#define QTHREAD2_H

#include <QThread>
#include <QDebug>

class QThread2 : public QThread
{
public:
    int val;
    void run();
    QThread2();
};

#endif // QTHREAD2_H
