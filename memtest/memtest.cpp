#include <iostream>
#include <vector>
using namespace std;

const int N=100; // size in megabytes

int main()
{
	vector <char> v;
	v.resize(1024 * 1024 * N);
	cout << N << " MBytes used" << endl;
	cin >> v[0];
}
