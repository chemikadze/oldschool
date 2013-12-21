#include <QtCore/QCoreApplication>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int maximalSum(vector <int> data)
{
	int sum=0;
	int z;
	int i;

		sort(data.begin(), data.end());

	for (i=0; (i<data.size()-1) && (data[i] < 0) && (data[i+1]<=0); i+=2)
	{
		cout << i;
		sum += data[i] * data[i+1];
	}
	z=i;

	for (i=data.size()-1; ((i >= z) && (data[i]) && (data[i-1])); --i)
	{
		if (data[i-1]==1 || data[i]==1)
			sum+=data[i];
		else
		{
			sum += data[i] * data[i-1];
			i--;
		}

	}
	for (; i>=z; i--)
		sum+=data[i];
	return sum;
}

int main(int argc, char *argv[])
{
	vector <int> v;
	v.push_back(2);
	v.push_back(3);/*
	v.push_back(4);
	v.push_back(5);*/

	cout << maximalSum(v);

	return 0;
}
