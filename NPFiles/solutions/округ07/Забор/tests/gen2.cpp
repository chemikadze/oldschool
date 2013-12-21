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
	n = random(1000) + 100;
	printf("%d ", n);
	printf("%d\n", random(100) + 1);
	vector<int> q;
	forn(i, n) if (random(2) && q.size() < 100) q.pb(i + 1);
	vector<int> ls, rs;
	int l = q[0], r = q[0];
	forv (i, q) {
		if (q[i] > r + 1) {
//			printf("%d %d\n", l, r);
			ls.pb(l);
			rs.pb(r);
			l = r = q[i];
		} else {
			r = q[i];
		}
	}
   	ls.pb(l);
   	rs.pb(r);
	printf("%d\n", min((int)ls.size(), 50));
	forn(i, min((int)ls.size(), 50)) printf("%d %d\n", ls[i], rs[i]);
}

int main() 
{
	srand(GetTickCount());
	readdata();
	solve();
	outdata();
	return 0;
}

