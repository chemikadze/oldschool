

#include <QApplication>
#include <QTextCodec>
#include "bullsmw.h"

int main(int argc, char *argv[])
{
      QTextCodec *codec = QTextCodec::codecForName("UTF-8");
      QTextCodec::setCodecForTr(codec);
      QTextCodec::setCodecForCStrings(codec);
      QTextCodec::setCodecForLocale(codec);
      QApplication app(argc, argv);
      MainWindow * mw=new MainWindow();
      mw->show();
      return app.exec();
}

