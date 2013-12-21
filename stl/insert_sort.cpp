#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	vector <int> v;
	srand(rand());

	for (int i=0; i<10; ++i)
	{
		int val = rand()%10;
		v.insert( upper_bound(v.begin(), v.end(), val), val);
	}

	for (int i=0; i<v.size();  ++i)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}
