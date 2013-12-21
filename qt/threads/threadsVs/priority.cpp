#include "priority.h"

prioritySlider::prioritySlider()
{
    QVBoxLayout *la=new QVBoxLayout;
    slider=new QSlider(Qt::Horizontal);
    slider->setRange(0, 6);
    slider->setValue(3);
    label=new QLabel(getNameByPriority((QThread::Priority)slider->value()));
    la->addWidget(label);
    la->addWidget(slider);
    setLayout(la);
    p_value=QThread::NormalPriority;
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(sliderChanged(int)));
}

prioritySlider::prioritySlider(QThread::Priority prior)
{
    prioritySlider();
    p_value=prior;
    slider->setValue(prior);
}

void prioritySlider::sliderChanged(int val)
{
    p_value=(QThread::Priority)val;
    label->setText(getNameByPriority((QThread::Priority)val));
}

QString prioritySlider::getNameByPriority(QThread::Priority val)
{
    switch (val)
    {
	case QThread::IdlePriority: return tr("Idle priority");
	case QThread::LowestPriority: return tr("Lowest priority");
	case QThread::LowPriority: return tr("Low priority");
	case QThread::NormalPriority: return tr("Nomal priority");
	case QThread::HighPriority: return tr("High priority");
	case QThread::HighestPriority: return tr("Highest priority");
	case QThread::TimeCriticalPriority: return tr("Time critical");
	default: return tr("Unknown priority");
    }
}

QThread::Priority prioritySlider::value()
{
    return p_value;
}
