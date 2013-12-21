#ifndef PRIORITY_H
#define PRIORITY_H

#include <QtGui>

class prioritySlider : public QWidget
{
    Q_OBJECT
    QSlider *slider;
    QLabel *label;
    QThread::Priority p_value;
private slots:
    void sliderChanged(int val);
public:
    QString static getNameByPriority(QThread::Priority prior);
public:
    QThread::Priority value();
    prioritySlider();
    prioritySlider(QThread::Priority prior);
};

#endif // PRIORITY_H
