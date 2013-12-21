#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/STACK:30000000")

#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cassert>
#include <utility>

using namespace std;

#define EPS 1E-8
const int INF = (int)1E+9;

#define C_IN_FILE "input.txt"
#define C_OUT_FILE "output.txt"

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

void outdata() {
}

void solve() {
}

void readdata() {
	scanf("%d%d%d", &n, &k, &m);
	printf("n = %d, m = %d, k = %d", n, m, k);
	int l, r, sum = 0;
	forn(i, m) {
		scanf("%d%d", &l, &r);
		sum += r - l + 1;
	}
	printf(", sum = %d\n", sum);
}

int main() {
	readdata();
	solve();
	outdata();
	return 0;
}

