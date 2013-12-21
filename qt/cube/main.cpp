// Программа cube
// Соколов Николай, ФПК 1-2
// Файл main.cpp
//

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.resize(400, 400);
    w.show();
    return a.exec();
}
