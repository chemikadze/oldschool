#include "aplayer.h"

APlayer::APlayer()
{
	old = 0;

	m_fsModel = new QFileSystemModel(this);
	m_fsModel->setRootPath("/");
	m_fsModel->setFilter(QDir::Dirs | QDir::Drives | QDir::NoDotAndDotDot);

	w_fileSystemTree = new QTreeView();
	w_fileSystemTree->setModel(m_fsModel);
	w_fileSystemTree->setSelectionMode(QAbstractItemView::SingleSelection);

	w_folderContents = new QTreeWidget();
	w_folderContents->setHeaderLabels(QStringList() << "Artist" << "Title" << "Album" << "Year");

	w_splitter = new QSplitter();
	w_splitter->setOrientation(Qt::Horizontal);
	w_splitter->addWidget(w_fileSystemTree);
	w_splitter->addWidget(w_folderContents);
	w_splitter->setStretchFactor(0, 40);
	w_splitter->setStretchFactor(1, 60);

	w_playPause = new QPushButton(QIcon::fromTheme("media-playback-start"), tr(""));
	w_stop = new QPushButton(QIcon::fromTheme("media-playback-stop"), tr(""));
	w_sound = new QPushButton(QIcon::fromTheme("player-volume"), tr(""));

	w_progress = new QSlider(Qt::Horizontal);

	m_media = Phonon::createPlayer(Phonon::MusicCategory);
	m_media->setTickInterval(1000);

	la_playerButtons = new QHBoxLayout();
	la_playerButtons->addWidget(w_playPause);
	la_playerButtons->addWidget(w_stop);
	la_playerButtons->addWidget(w_sound);
	la_playerButtons->addWidget(w_progress);

	la_mainWindow = new QVBoxLayout();
	la_mainWindow->addWidget(w_splitter);
	la_mainWindow->addLayout(la_playerButtons);

	QWidget *w = new QWidget();
	w->setLayout(la_mainWindow);
	setCentralWidget(w);


	connect(w_fileSystemTree, SIGNAL(clicked(QModelIndex)), this, SLOT(treeItemClicked(QModelIndex)));

	connect(w_playPause, SIGNAL(clicked()), this, SLOT(playPause()));
	connect(w_stop, SIGNAL(clicked()), this, SLOT(stop()));

	connect(w_fileSystemTree, SIGNAL(collapsed(QModelIndex)), this, SLOT(treeChanged()));
	connect(w_fileSystemTree, SIGNAL(expanded(QModelIndex)), this, SLOT(treeChanged()));

	connect(m_media, SIGNAL(tick(qint64)), this, SLOT(setPlaybackState(qint64)));
	connect(m_media, SIGNAL(totalTimeChanged(qint64)), this, SLOT(setPlaybackMax(qint64)));

	connect(w_folderContents, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(fileDoubleClicked(QTreeWidgetItem*,int)));
}

void APlayer::treeItemClicked(const QModelIndex &index)
{
	if (m_fsModel->isDir(index))
	{
		setDir(m_fsModel->filePath(index));
	}
}

void APlayer::setDir(QString path)
{
	old = 0;
	m_media->clear();
	w_folderContents->clear();
	while (QTreeWidgetItem *item = w_folderContents->takeTopLevelItem(0))
	{
		delete item;
	}
	path += "/";
	QDir dir(path);
	QStringList files = dir.entryList(QStringList() << "*.mp3" << "*.ogg" << "*.wav" << "*.wma",
									  QDir::Files | QDir::NoDotAndDotDot,
									  QDir::Name);
	QString f = path + "%2";
	Phonon::MediaObject media;
	foreach (QString file, files)
	{
		QString filepath = f.arg(file);
		media.setCurrentSource(filepath);
		QMap <QString,QString> metaData = media.metaData();
		QStringList metaList;
		metaList << metaData.value("ARTIST")
				 << metaData.value("TITLE")
				 << metaData.value("ALBUM")
				 << metaData.value("DATE");
		qDebug() << metaList;
		if (metaList[0].isEmpty())
			metaList[0] = file;
		QTreeWidgetItem *item = new QTreeWidgetItem(metaList);
		item->setData(0, Qt::UserRole, filepath);
		w_folderContents->addTopLevelItem(item);
	}
	w_folderContents->resizeColumnToContents(0);
	if (w_folderContents->columnWidth(0) > 400)
		w_folderContents->setColumnWidth(0, 400);
}

void APlayer::fileDoubleClicked(QTreeWidgetItem *item, int)
{
	if (! item)
		return;
	m_media->clear();
	m_media->setCurrentSource(Phonon::MediaSource(item->data(0, Qt::UserRole).toString()));
	QFont font = item->font(0);
	font.setBold(false);
	if (old)
		for (int i; i < old->columnCount(); ++i)
			old->setFont(i, font);
	font.setBold(true);
	for (int i; i<item->columnCount(); ++i)
		item->setFont(i, font);
	old = item;

	play();
}

void APlayer::treeChanged()
{
	w_fileSystemTree->resizeColumnToContents(0);
}

void APlayer::setPlaybackMax(qint64 time)
{
	w_progress->setMaximum(time / 1000);
}

void APlayer::setPlaybackState(qint64 time)
{
	w_progress->setValue(time / 1000);
}

void APlayer::play()
{
	if (m_media->currentSource().type() != Phonon::MediaSource::Empty)
	{
		m_media->play();
		w_playPause->setIcon(QIcon::fromTheme("media-playback-pause"));
	}
}

void APlayer::playPause()
{
	if (m_media->currentSource().type() == Phonon::MediaSource::Empty)
		return;
	if (m_media->state() == Phonon::PlayingState)
	{
		m_media->pause();
		w_playPause->setIcon(QIcon::fromTheme("media-playback-start"));
	}
	else
	{
		m_media->play();
		w_playPause->setIcon(QIcon::fromTheme("media-playback-pause"));
	}
}

void APlayer::stop()
{
	m_media->stop();
	w_playPause->setIcon(QIcon::fromTheme("media-playback-start"));
}
