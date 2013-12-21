#include <QtGui/QApplication>
#include "cmakeqtgui.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    cmakeqtgui foo;
    foo.show();
    return app.exec();
}
