#ifndef SETTINGSBOX_H
#define SETTINGSBOX_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class SettingsBox : public QDialog
{
	QLabel *hostLabel;
	QLineEdit *hostEdit;
	QLabel *portLabel;
	QSpinBox *portEdit;
	QPushButton *ok, *cancel;
public:
	void setHost(const QString&);
	void setPort(qint16 p);
	QString getHost();
	qint16 getPort();
    SettingsBox();
};

#endif // SETTINGSBOX_H
