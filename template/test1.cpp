#include "header.h"
#include "test.h"
#include <iostream>

template <>
void C::print<int>(int val)
{
	std::cout << "implement 1: " << val << std::endl;
}

void implement1(int n)
{
	C::print<int>(n);
}
