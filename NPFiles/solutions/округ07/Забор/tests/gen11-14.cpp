#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/STACK:30000000")

#include <string>
#include <ctime>
#include <windows.h>
#include <vector>
//#include <cmath>
//#include <queue>
//#include <set>
//#include <map>
//#include <algorithm>
#include <iostream>
//#include <cstdio>
//#include <sstream>
#include <cassert>
//#include <utility>

using namespace std;

#define EPS 1E-8
const int INF = (int)1E+9;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define PII pair<int, int>
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

int n, m, k, l, ans;
int ns[4] = {11000, 9978, 999992988, 967543219};
int ms[4] = {9, 12, 23, 50};
int ks[4] = {33, 61, 100, 4};
int ls[4] = {9321, 8760, 922134568, 9982319};
FILE * f;

int random(int value)
{
	return ((((unsigned int)rand()) << 15) + ((unsigned int)rand())) % value;
}

void outdata() {
}

void solve() {
	fprintf(f, "%d %d\n%d\n", n, k, m);
	int r = 0;
	int sum = l;
	int sn = n;
	forn(i, m) {
		int gap = random((n - sum) / ((m - i) + 1) + 1) + 1;
		n -= gap;
		r += gap;
		fflush(f);
		assert(1 <= r && r <= sn);
		fprintf(f, "%d ", r);
		int len = random(sum / (m - i) + 1) + 1;
		sum -= len - 1;
		n -= len - 1;
		r += len - 1;
		fprintf(f, "%d\n", r);
		fflush(f);
		assert(1 <= r && r <= sn);
	}
}

int main() 
{
	srand(73783832);
	char buf[100];
	forn(i, 4) {
		cerr << "! " << i + 11 << endl;
		sprintf(buf, "%.2d", i + 11);
		f = fopen(buf, "wt");
		n = ns[i];
		m = ms[i];
		k = ks[i];
		l = ls[i];
		solve();
		outdata();
		fclose(f);
	}
	return 0;
}

