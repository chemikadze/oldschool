#ifndef APLAYER_H
#define APLAYER_H

#include <QtGui>
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>

class APlayer : public QMainWindow
{
	Q_OBJECT

	QTreeWidgetItem *old;
	QTreeView *w_fileSystemTree;
	QTreeWidget *w_folderContents;
	QSplitter *w_splitter;


	QPushButton *w_playPause;
	QPushButton *w_stop;
	QSlider *w_progress;
	QPushButton *w_sound;
	QSlider *w_volume;

	QVBoxLayout *la_mainWindow;
	QHBoxLayout *la_playerButtons;

	QFileSystemModel *m_fsModel;
	QFileSystemModel *m_fsListModel;

	Phonon::MediaObject *m_media;

private slots:
	void treeItemClicked(const QModelIndex& index);
	void treeChanged();
	void setPlaybackMax(qint64);
	void setPlaybackState(qint64);
	void fileDoubleClicked(QTreeWidgetItem*,int);

public slots:
	void play();
	void playPause();
	void stop();
	void setDir(QString path);

public:
    APlayer();
};

#endif // APLAYER_H
