#include <QtGui/QApplication>
#include "qtcmake.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    qtcmake foo;
    foo.show();
    return app.exec();
}
