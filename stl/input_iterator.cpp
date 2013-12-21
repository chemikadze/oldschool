#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	std::vector <int> v;
	v.insert(v.begin(), std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
	std::cout << "V size is " << v.size() << std::endl;
	std::sort(v.begin(), v.end());
	std::unique_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	std::cout << std::endl;
}
