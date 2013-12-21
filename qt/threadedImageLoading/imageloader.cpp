#include "imageloader.h"
#include <QtCore/QDebug>

QSemaphore ThumbLoader::m_semaphore(1);

ThumbLoader::ThumbLoader()
{
} 

ThumbLoader::~ThumbLoader()
{
}

void ThumbLoader::run()
{
	setPriority(QThread::IdlePriority);

	m_semaphore.acquire();
	qDebug() << "opening...";

	QImage img;
	img = loadImage(m_filename, m_size);
	emit imageLoaded(img);

	m_semaphore.release();
	qDebug() << "closing...";

	deleteLater();
}

QImage ThumbLoader::loadImage(const QString& filename, const QSize &size, bool *ok /* = 0*/)
{
	QImage ret;
	m_loaded = ret.load(filename);
	m_filename = filename;
	if (m_loaded)
		ret = ret.scaled(size, Qt::KeepAspectRatio);
	if (ok)
		*ok = m_loaded;

	return ret;
}
