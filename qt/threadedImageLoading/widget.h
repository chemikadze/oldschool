#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore/QList>
#include <QtGui/QListWidget>
#include <QtCore/QHash>
#include <QtCore/QStringList>

#include "imageloader.h"

class Widget : public QListWidget
{
    Q_OBJECT

	QStringList filters;
	QString m_path;
	int m_count;
	QVector <QImage> m_images;
	QHash <QString, QListWidgetItem*> m_hash;

public slots:
	void imageLoaded(const QImage& image);
	void setDir(const QString& path);
	void setThumbSize(const QSize& size);
	void openItem(QListWidgetItem*);

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
