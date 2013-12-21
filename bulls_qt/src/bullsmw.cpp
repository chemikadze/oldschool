#include <QObject>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextCodec>
#include "bullsmw.h"

MainWindow::MainWindow()
{
  setupUi(this);
  bull=new Bulls(len, base);
  newgame();
  connect(lineEdit, SIGNAL(returnPressed()),
          this,     SLOT(setbc()));
  connect(pushButton, SIGNAL(clicked()),
          this,       SLOT(newgame()));
}

void MainWindow::setbc()
{
  int c, b;
  QString s;
  if (sscanf(lineEdit->text().toAscii(), "%d%d", &c, &b)!=2 || lineEdit->text().length()!=3)
  {
    QMessageBox::information(this, tr("Ошибка!"), tr("Ввод в формате \"%d %d\""));
    return;
  }
  textEdit->append(QString("> ")+lineEdit->text());
  if (bull->setbc(c, b))
  {
    s=tr("компьютер выиграл с %1-ого раза!").arg(bull->getsteps());
    lineEdit->setReadOnly(true);
  }
  else
    s=bull->getnext();
  if (bull->getnext()==NULL)
  {
    QMessageBox::information(this, tr("Ошибка!"), tr("Ошибка ввода"));
    return;
  }
  textEdit->append(s);
  lineEdit->clear();
}

void MainWindow::newgame()
{
  bull->clear();
  textEdit->clear();
  textEdit->append(bull->getnext());
  lineEdit->setReadOnly(false);
}

