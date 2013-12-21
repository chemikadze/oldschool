#include <QApplication>
#include <QSharedPointer>
#include <iostream>
#include <QMetaType>

struct O {
	static int x;
	O() { std::cout << "O::O()" << ++x << std::endl; }
	~O() { std::cout << "O::~O()" << --x << std::endl; }
};
int O::x = 0;
//Q_DECLARE_METATYPE( QSharedPointer<O> )
int id = qRegisterMetaType< QSharedPointer<O> >("QSharedPointer<O>");

class A : public QObject {
	Q_OBJECT
public:
	void emitSignal()
	{ emit emitPtr(QSharedPointer<O>(new O())); std::cout << "Thrown" << std::endl; }
signals:
	void emitPtr(QSharedPointer<O>);
};

class H : public QObject {
	Q_OBJECT
public slots:
	void handlePtr(QSharedPointer<O>)
	{ std::cout << "Handled!" << std::endl; }
};

int main(int argc, char**argv)
{
	QApplication app(argc, argv);
	A a;
	H h1, h2;
	QObject::connect(&a, SIGNAL(emitPtr(QSharedPointer<O>)), &h1, SLOT(handlePtr(QSharedPointer<O>)), Qt::QueuedConnection);
	QObject::connect(&a, SIGNAL(emitPtr(QSharedPointer<O>)), &h2, SLOT(handlePtr(QSharedPointer<O>)), Qt::QueuedConnection);
	a.emitSignal();
	return app.exec();
}

#include "main.moc"
