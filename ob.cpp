/*
 * =====================================================================================
 *
 *       Filename:  ob.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19.02.2010 00:38:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

class Base
{
	public:
		virtual void print()
		{
			std::cout << "Base" << std::endl;
		}
};

class Child: public Base
{
	public:
		virtual void print()
		{
			std::cout << "Child" << std::endl;
		}
};

class Child1: public Child
{
	public:
		virtual void print()
		{
			std::cout << "Child1" << std::endl;
		}
};

int main()
{
	Child * o=new Child1;
	o->print();
	return 0;
}
