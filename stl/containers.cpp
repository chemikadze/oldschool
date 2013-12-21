#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <numeric>
#include <functional>
#include <set>
#include <list>
#include <deque>
#include <strings.h>
using namespace std;

template <typename T, typename it_T>
void output(it_T beg, it_T end)
{
	std::copy(beg, end, std::ostream_iterator<T>(cout));
}

int main()
{
	vector <int> v;
	
	for (int i=0; i<5; ++i)
	{
		v.push_back(i);
	}
	
	cout << "before: ";
	output<int>(v.begin(), v.end());
	cout << endl;

	vector<int>::iterator nend =  remove(v.begin(), v.end()-1, 0); 
	

	cout << "after: ";
	output<int>(v.begin(), nend);
	cout << endl;
}
