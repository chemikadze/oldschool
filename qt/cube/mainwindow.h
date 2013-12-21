// Программа cube
// Соколов Николай, ФПК 1-2
// Файл mainwindow.h
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "cube.h"

class mainWindow : public QWidget
{
    Q_OBJECT
    Cube *cube;
    QLabel *sliderLabel;
    QSlider *slider;
    QLabel *xDialLabel;
    QDial *xDial;
    QLabel *yDialLabel;
    QDial *yDial;
public:
    mainWindow();
};

#endif // MAINWINDOW_H
