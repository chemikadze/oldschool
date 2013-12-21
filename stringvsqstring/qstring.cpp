#include <QtCore>

int main()
{
	QString qs;
	int i;
	for (i=0; i<1000000; i++)
		qs=QString("%1 %2 %3 %4").arg("one").arg("two").arg("three").arg("four");
	//	qs=QString("%1").arg("one");
	qDebug() << qs;
	return 0;
}
