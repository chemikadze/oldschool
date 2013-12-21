#include "koolbar.h"

KoolBar::KoolBar(QWidget *parent) : QToolBar(parent)
{

}

KoolBar::KoolBar(const QString &title, QWidget *parent) : QToolBar(title, parent)
{

}

void KoolBar::init(const QString &name)
{
	setObjectName(name);
	QRect geom;
	QSettings *s = new QSettings();
	geom = s->value("KoolBar "+objectName(), QVariant(QRect())).toRect();
	if (geom != QRect())
		setGeometry(geom);
	delete s;
}

KoolBar::~KoolBar()
{
	QSettings *s = new QSettings();
	s->setValue("KoolBar "+objectName(), geometry());
	delete s;
}

void KoolBar::createPopupMenu()
{
	m_menu = new QMenu(this);
}

void KoolBar::contextMenuEvent(QContextMenuEvent *)
{

}
