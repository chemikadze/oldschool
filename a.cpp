#include <iostream>
#include <string>

int main()
{
	std::wstring s;
	do 
	{
		std::getline(std::wcin, s);
		std::wcout << "You entered: \"" << s << "\"" << std::endl;
	}
	while (!s.empty());

	return 0;
}
