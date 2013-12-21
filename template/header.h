#include <iostream>

class C
{
public:
	template <class T>
		static void print(T val)
		{
			std::cout << "DEFAULT TEMPLATE: " <<  val << std::endl;
		}
};
