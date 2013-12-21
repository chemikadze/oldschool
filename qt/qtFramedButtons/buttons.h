#ifndef BUTTONS_H
#define BUTTONS_H

#include <QtGui>
#include <QtCore>

class Buttons : public QPushButton
{
	Q_OBJECT
protected:
	bool b_success;
	QStack <QPushButton*> buttonStack;
	virtual void closeEvent(QCloseEvent *event);
signals:
	void closed();
public:
	bool success();
	bool createButtons(int size, int count=1, QColor first=Qt::black, QColor last=Qt::red);
	Buttons(QWidget *parent=0);
	Buttons(int size, int count=1, QColor first=Qt::black, QColor last=Qt::red);
	~Buttons();
};

#endif // BUTTONS_H
