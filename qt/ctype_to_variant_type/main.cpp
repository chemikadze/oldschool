#include <QVariant>
#include <iostream>
#include <QString>


template <class T>
	QVariant::Type ctypeToVariantType()
{
//	static QVariant val;
	static QVariant val = T();
	return val.type();
}

void printType(QVariant::Type t)
{
	const char* s = QVariant::typeToName(t);
	std::cout << int(t) << " " << (s?s:"") << std::endl;
}

int main()
{
	QVariant v(int());
	printType(ctypeToVariantType<int>());
	printType(ctypeToVariantType<double>());
	printType(ctypeToVariantType<QVariantList>());
	printType(ctypeToVariantType<QString>());

//	std::cout << QVariant::nameToType("int") << std::endl;
}
