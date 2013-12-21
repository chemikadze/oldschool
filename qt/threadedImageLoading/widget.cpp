#include "widget.h"
#include <QtCore/QDir>
#include <QtCore/QDebug>

Widget::Widget(QWidget *parent)
	: QListWidget(parent)
{
	setViewMode(QListWidget::IconMode);
	setWordWrap(true);
	setWrapping(true);
	setIconSize(QSize(100, 100));
	setMovement(QListWidget::Static);
	filters << "*.png"
			<< "*.jpg"
			<< "*.jpeg"
			<< "*.bmp"
			<< "*.gif";
}

Widget::~Widget()
{

}

void Widget::imageLoaded(const QImage &image)
{
	ThumbLoader *loader = qobject_cast<ThumbLoader*>(sender());
	if (loader)
	{
		QFileInfo info(loader->filename());
		QListWidgetItem *item = m_hash.value(info.fileName(), 0);
		if (item)
		{
			item->setData(Qt::DecorationRole, image);
		}
		qDebug() << loader->filename();
	}
}

void Widget::setThumbSize(const QSize& size)
{
	setGridSize(size + QSize(20, 20));
	setIconSize(size);
	QHash <QString, QListWidgetItem*>::iterator it;
	for (it = m_hash.begin(); it != m_hash.end(); ++it)
	{
		ThumbLoader *loader = new ThumbLoader;
		loader->connect(loader, SIGNAL(imageLoaded(const QImage&)),
						this, SLOT(imageLoaded(const QImage&)));
		loader->setFilename( m_path + '/' + it.key());
		loader->setSize(size);
		loader->start();
	}
}

void Widget::setDir(const QString& path)
{
	while (count())
	{
		delete takeItem(0);
	}

	qDebug() << path;

	m_hash.clear();

	QDir pwd(path);
	m_path = path;
	QStringList filenames;
	filenames = pwd.entryList(filters, QDir::Files, QDir::Name);

	foreach (QString filename, filenames)
	{
		QListWidgetItem *item = new QListWidgetItem(filename, this);
		m_hash.insert(filename, item);
	}
	qDebug() << "ok";
	setThumbSize(iconSize());
}

void Widget::openItem(QListWidgetItem*)
{
}
