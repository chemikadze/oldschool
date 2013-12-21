#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QDebug>
#include <QImage>
#include <QPainter>

class Thread : public QThread
{
    Q_OBJECT
    bool *b_running;
    double *data;
public:
    void run();
    void stop();
    Thread(double* p_data, bool *b_addr);
    Thread(double *p_data);

};

#endif // THREAD_H
