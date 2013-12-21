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

int n, m, k, ans;
int ns[6] = {32, 54, 70, 87, 100, 100};
int ms[6] = {7, 1, 30, 17, 15, 50};
int ks[6] = {7, 4, 9, 8, 1, 21};
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
	int sum = n;
	forn(i, m) {
		fflush(f);
		int gap = random(sum / (2 * (m - i) + 1) + 1) + 1;
		sum -= gap;
		r += gap;
		assert(1 <= r && r <= n);
		fprintf(f, "%d ", r);
		int len = random(sum / (2 * (m - i) + 1) + 1) + 1;
		sum -= len - 1;
		r += len - 1;
		if (i == m - 1 && random(2)) r = n;
		fprintf(f, "%d\n", r);
		assert(1 <= r && r <= n);
	}
}

int main() 
{
	srand(73783832);
	char buf[100];
	forn(i, 6) {
		cerr << "! " << i + 5 << endl;
		sprintf(buf, "%.2d", i + 5);
		f = fopen(buf, "wt");
		n = ns[i];
		m = ms[i];
		k = ks[i];
		solve();
		outdata();
		fclose(f);
	}
	return 0;
}

