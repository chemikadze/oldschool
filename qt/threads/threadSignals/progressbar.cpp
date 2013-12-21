#include "progressbar.h"

progressBar::progressBar()
{
    setRange(0, 10);
    setValue(0);
}

void progressBar::step()
{
    qDebug() << "step";
    if (value() == maximum())
	setValue(0);
    else
	setValue(value()+1);
}
