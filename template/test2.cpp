#include "header.h"
#include "test.h"
#include <iostream>

template <>
void C::print<int>(int val)
{
	std::cout << "implement 2: " << val << std::endl;
}

void implement2(int n)
{
	C::print<int>(n);
}
