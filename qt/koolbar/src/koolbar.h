#ifndef KOOLBAR_H
#define KOOLBAR_H

#include <QtGui/QToolBar>
#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtCore/QSettings>

class KoolBar : public QToolBar
{
	Q_OBJECT

	static QList <KoolBar*> m_instances;
	QMenu* m_menu;
	void createPopupMenu();
protected:
	virtual void contextMenuEvent(QContextMenuEvent *);
public:
	void init(const QString& name);
	static QList <KoolBar*> instances() { return m_instances; }
	KoolBar(QWidget* parent = 0);
	KoolBar(const QString& title, QWidget* parent = 0);
	~KoolBar();
};

#endif // KOOLBAR_H
