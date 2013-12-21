#include <iostream>

class A
{
	static const int N = 3;
public:
	void print()
	{
		std::cout << N;
	}

	A()
	{
	}
};

int main()
{
	A a;
	a.print();
}
