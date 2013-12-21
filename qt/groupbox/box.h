#ifndef _BOX_
#define _BOX_
#include <QtCore>
#include <QtGui>
//#define tr(_X_) QObject::tr((_X_))

class Box : public QGroupBox
{
	Q_OBJECT
	
	public:
		Box(QWidget * pwgt=0);
	private:
		QCheckBox *light;
		QRadioButton *rb1, *rb2, *rb3;
		QPushButton * exit;
	public slots:
		void	changeColor();
};

#endif
