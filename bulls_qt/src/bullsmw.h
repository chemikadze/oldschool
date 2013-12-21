#include <QWidget>
#include <QMainWindow>
#include "ui_bullsmw.h"
#include "bulls.h"

const int len=4;
const int base=9;

class MainWindow: public QMainWindow, private Ui_MainWindow
{
  Q_OBJECT
  public slots:
    void setbc();
    void newgame();
  public:
    Bulls * bull;
    MainWindow();
};
