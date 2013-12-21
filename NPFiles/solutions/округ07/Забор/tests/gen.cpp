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
//#include <cassert>
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

int n, m, ans;

int random(int value)
{
	return ((((unsigned int)rand()) << 15) + ((unsigned int)rand())) % value;
}

void outdata() {
}

void solve() {
}

void readdata() {
	printf("15 ");
	int msk = random(1 << 15);
	while (msk == 0) msk = random(1 << 15);
	printf("%d\n", random(15) + 1);
	int r = 0;
	forn(i, 15) if (msk & (1 << i)) ++r;
	printf("%d\n", r);
	forn(i, 15) if (msk & (1 << i)) printf("%d %d\n", i + 1, i + 1);

}

int main() 
{
	srand(GetTickCount());
	readdata();
	solve();
	outdata();
	return 0;
}

