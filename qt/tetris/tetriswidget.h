#ifndef TETRISWIDGET_H
#define TETRISWIDGET_H

#include <QtGui/QWidget>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>
#include <QtGui/QPainter>
#include "element.h"

class TetrisWidget : public QWidget
{
	Q_OBJECT

#define TET_WIDTH  10
#define TET_HEIGHT 20
	enum State {Stopped, Started, Paused, GameOver} m_state;
	QVector <char*> m_field;
	Element *elem;
	Element *nextElem;
	quint32 m_score;
	QTimer  *timer;
	qint8	m_row;
	qint8	m_col;
	qint8	m_level;
	bool	m_paused;
	bool	m_stopped;

protected:
	void elemDropped();
	bool canBe(qint8 nrow, qint8 ncol);
	virtual void paintEvent(QPaintEvent*);
	virtual void keyPressEvent(QKeyEvent* event);
	virtual void keyReleaseEvent (QKeyEvent * event);

signals:
	void paused(bool);
	void stopped();
	void scoreChanged(qint32);
	void levelChanged(qint8);

protected slots:
	bool dropDown();

public slots:
	void start();
	void pause();
	void pause(bool b);
	void setLevel(qint8 level);
	void stop();
	void clear();

public:
	qint8 level();
	qint32 score();
	virtual QSize sizeHint();
    TetrisWidget();
};

#endif // TETRISWIDGET_H
