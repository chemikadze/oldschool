#include <iostream>

class Class2 {
public:
	int a;
	Class2() : a(0) {}
};

class Class {
public:
	int a;
	int b;
	Class2 c;
};


void corrupt()
{
	Class c;
	c.a = 1;
	c.b = 2;
	c.c.a = 3;
}

void print()
{
	Class c;
	std::cout << c.a << ' ' << c.b << ' ' << c.c.a << std::endl;
}

int main()
{
	corrupt();
	print();
	return 0;
}
