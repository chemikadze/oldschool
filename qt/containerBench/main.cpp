#include <QtCore>

int main(int argc, char** argv)
{
	int N, i;

	if (argc == 1)
	{
		qWarning("Enter count as parameter.");
		return 0;
	}
	sscanf(argv[1], "%d", &N);
	if (N<0)
	{
		qWarning("Count must be positive value!");
		return 0;
	}

//	QSet <int> set;
	QMap <int,int> map;
//	QVector <int> map(1000000);
//	QHash <int, int> map;
	srand(time(NULL));
	qDebug("Starting...");
	QTime t;t.start();

	i=N;
	while ( i-- )
	{
//		set.insert(rand()%1000000);
		map[ rand()%1000000 ] = rand();
	}

	qDebug("Processed %d int`s, time: %d mseconds.", N, t.elapsed());

	return 0;
}
