#ifndef TICKTHREAD_H
#define TICKTHREAD_H

#include <QThread>

class tickThread : public QThread
{
    Q_OBJECT
public:
    tickThread();
    void run();
signals:
    void tick();
};

#endif // TICKTHREAD_H
