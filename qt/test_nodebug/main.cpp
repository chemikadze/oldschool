#define QT_NO_DEBUG

#include <QList>
#include <iostream>
#include <QString>

int main()
{
	QList<QString> l;

	try {
		 std::cout << l.at(100500).toStdString();
	}
	catch (...) {
		std::cout << "FOC YEA IZ WORKIN" << std::endl;
	}

	return 0;
}
