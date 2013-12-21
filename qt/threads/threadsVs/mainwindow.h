#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "thread.h"
#include "priority.h"

class mainWindow : public QWidget
{
    Q_OBJECT
    bool running;
    Thread *thread1;
    Thread *thread2;
    QPushButton *startButton;
    prioritySlider *slider1;
    prioritySlider *slider2;
    QProgressBar *bar;
    QTimer *timer;
    QLabel *lbl1, *lbl2;
    double signals1, signals2, sum;
public slots:
    void startStop();
    void refresh();
public:
    mainWindow(QWidget *parent = 0);
    ~mainWindow();
};

#endif // MAINWINDOW_H
