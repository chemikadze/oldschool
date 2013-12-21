#include "colorchooser.h"

colorChooser::colorChooser()
{
    QVBoxLayout *la=new QVBoxLayout;
    a_color=Qt::white;
    dialog=new QColorDialog(a_color, this);
    colorLabel=new QLabel(a_color.name());
    colorWidget=new QPushButton();
    filter=new clickFilter();
    colorLabel->installEventFilter(filter);
    colorWidget->installEventFilter(filter);
    connect(filter, SIGNAL(clicked()), this, SLOT(showDialog()));
    la->addWidget(colorLabel);
    la->addWidget(colorWidget);
    QPalette pal; // dirty... but these buttons are too small to move this to top
    pal=colorWidget->palette();
    pal.setColor(colorWidget->backgroundRole(), a_color);
    colorWidget->setAutoFillBackground(true);
    colorWidget->setPalette(pal);
    colorLabel->setCursor(Qt::PointingHandCursor);
    setLayout(la);
}

colorChooser::colorChooser(QColor newColor)
{
    QVBoxLayout *la=new QVBoxLayout;
    a_color=newColor;
    dialog=new QColorDialog(a_color, this);
    colorLabel=new QLabel(a_color.name());
    //colorWidget=new QWidget();
    colorWidget=new QPushButton();
    filter=new clickFilter();
    colorLabel->installEventFilter(filter);
    colorWidget->installEventFilter(filter);
    connect(filter, SIGNAL(clicked()), this, SLOT(showDialog()));
    la->addWidget(colorLabel);
    la->addWidget(colorWidget);
    QPalette pal; // dirty... but these buttons are too small to move this to top
    pal=colorWidget->palette();
    pal.setColor(colorWidget->backgroundRole(), a_color);
    colorWidget->setPalette(pal);
   // colorWidget->setAutoFillBackground(true);
    setLayout(la);
}

QColor colorChooser::showDialog()
{
    a_color=dialog->getColor(a_color, this);
    QPalette pal; // dirty... but these buttons are too small to move this to top
    pal=colorWidget->palette();
    pal.setColor(colorWidget->backgroundRole(), a_color);
    colorWidget->setPalette(pal);
    colorLabel->setText(a_color.name());
    return a_color;
}

QColor colorChooser::color()
{
    return a_color;
}

void colorChooser::setColor(QColor newColor)
{
    a_color=newColor;
    colorLabel->setText(a_color.name());
    QPalette pal; // dirty... but these buttons are too small to move this to top
    pal=colorWidget->palette();
    pal.setColor(colorWidget->backgroundRole(), a_color);
    colorWidget->setPalette(pal);
}

bool clickFilter::eventFilter(QObject *filter, QEvent *event)
{
    if (event->type()==QEvent::MouseButtonPress)
    {
	emit clicked();
    }
    return false;
}
