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

#define C_IN_FILE "chain.in"
#define C_OUT_FILE "chain.out"

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define PII pair<int, int>
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

int n, m, ans, al, ar;

char buf[251000];
char* s[251000];
int l[251000];

map<int, bool> MEM[251000];

void outdata() {
	printf("%d %d\n", al, ar);
}

int random(int v) {
	return ((rand() << 15) ^ rand()) % v;
}

bool isOk(int a, int b) {
	if (l[b] <= l[a]) return false;
	if (MEM[a].count(b) > 0) return MEM[a][b];
	int len = l[a];
	char tmp = s[b][len];
	s[b][len] = '\0';
	bool res = true;
	if (strcmp(s[a], s[b]) != 0) res = false;
	s[b][len] = tmp;
	return MEM[a][b] = res;
}

void solve() {
	int p, cr;
	scanf("%d", &m);
	scanf("%d", &p);
	--p;
	int l = 1, r = 1;
	ans = 1;
	al = ar = 1;
	forn(i, m - 1) {
		scanf("%d", &cr);
		--cr;
		if (isOk(p, cr)) ++r; else l = r = r + 1;
		if (ans < r - l + 1) {
			ans = r - l + 1;
			al = l;
			ar = r;
		}
		p = cr;
	}
}

void readdata() {
	scanf("%d", &n);
	assert(1 <= n && n <= 250000);
	int sum = 0;
	forn(i, n) {
		scanf("%s", buf);
		int len = strlen(buf);
		assert(1 <= len && len <= 250000);
		sum += len;
		s[i] = strdup(buf);
		l[i] = len;
	}
	assert(1 <= sum && sum <= 250000);
}

int main() {
    freopen(C_IN_FILE, "rt", stdin);
    freopen(C_OUT_FILE, "wt", stdout);
	readdata();
	solve();
	outdata();
	return 0;
}

