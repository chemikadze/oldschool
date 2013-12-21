#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class Widget : public QWidget
{
    Q_OBJECT
    QClipboard *cb;
    QLabel *clipTextLabel;
    QTextEdit *clipTextEdit;
    QLabel *x11SelectionLabel;
    QTextEdit *x11SelectionEdit;
    QPushButton *showHtml;
private slots:
    void readClipboardData();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // MAINWINDOW_H
