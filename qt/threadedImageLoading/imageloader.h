#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QtGui/QImage>
#include <QtCore/QThread>
#include <QtCore/QSemaphore>

class ThumbLoader : public QThread
{
	Q_OBJECT

	QSize m_size;
	bool m_loaded;
	QString m_filename;
	static QSemaphore m_semaphore;

signals:
	void imageLoaded(const QImage&);

public:
	QImage loadImage(const QString& filename, const QSize &size, bool *ok = 0);
	void run();
	inline bool loaded() { return m_loaded; }
	inline void setFilename(const QString&  file) { m_filename = file; }
	inline QString filename() { return m_filename; }
	inline QSize size() { return m_size; }
	inline void setSize(QSize size) { m_size = size; }
	ThumbLoader();
	~ThumbLoader();
};

#endif // IMAGELOADER_H
