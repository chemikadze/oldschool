// Программа cube
// Соколов Николай, ФПК 1-2
// Файл mainwindow.cpp
//

#include "mainwindow.h"

mainWindow::mainWindow()
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QGridLayout *la=new QGridLayout;
    cube=new Cube;
    slider=new QSlider(Qt::Horizontal);
    slider->setRange(-100, 100);
    slider->setValue(0);
    sliderLabel=new QLabel(tr("Сдвиг секущей"));
    xDialLabel=new QLabel(tr("Угол по горизонтали"));
    yDialLabel=new QLabel(tr("Угол по вертикали"));
    xDial=new QDial();
    xDial->setWrapping(true);
    xDial->setValue(0);
    xDial->setRange(0, 359);
    yDial=new QDial();
    yDial->setWrapping(true);
    yDial->setValue(0);
    yDial->setRange(0, 359);
    slider->setSizePolicy(xDial->sizePolicy());
/*
	labl
	X
  Cube	labl
	Y
	labl
	slider

  */
    la->addWidget(cube,		0, 0, 6, 1);
    la->addWidget(xDialLabel,	0, 1);
    la->addWidget(xDial,	1, 1);
    la->addWidget(yDialLabel,	2, 1);
    la->addWidget(yDial,	3, 1);
    la->addWidget(sliderLabel,	4, 1);
    la->addWidget(slider,	5, 1);
    setLayout(la);
    connect(slider, SIGNAL(valueChanged(int)), cube, SLOT(setD(int)));
    connect(xDial, SIGNAL(valueChanged(int)), cube, SLOT(setXa(int)));
    connect(yDial, SIGNAL(valueChanged(int)), cube, SLOT(setYa(int)));
    connect(cube, SIGNAL(XaChanged(int)), xDial, SLOT(setValue(int)));
    connect(cube, SIGNAL(YaChanged(int)), yDial, SLOT(setValue(int)));
}
