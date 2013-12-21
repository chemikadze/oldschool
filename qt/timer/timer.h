#include <QtGui>
#include <QtCore>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using std::min;

class QMyClock: public QWidget
{
	Q_OBJECT
 private:
	QTimer qtimer;
	time_t timer, time0;

 protected:
        void paintEvent(QPaintEvent* event);

 public slots:
        void startTimer();
        void stopTimer();
        void zero();

 private slots:
        void updateTimer();

 signals:
	void timeChanged(int timerValue);

 public:
        QMyClock(QWidget *parent=0);
};
