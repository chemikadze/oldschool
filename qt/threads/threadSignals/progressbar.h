#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QProgressBar>
#include <QDebug>

class progressBar : public QProgressBar
{
    Q_OBJECT
public:
    progressBar();
public slots:
    void step();
};

#endif // PROGRESSBAR_H
