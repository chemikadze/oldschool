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
vector<long long> hs[251000];
string s[251000];

void outdata() {
	printf("%d %d\n", al, ar);
}

int random(int v) {
	return ((rand() << 15) ^ rand()) % v;
}

bool isOk(int a, int b) {
	if (s[b].length() <= s[a].length()) return false;
	int len = (int)s[a].length();
	if (hs[a][len - 1] != hs[b][len - 1]) return false;
	forn(i, 5) {
		int cx = random(len);
		if (s[a][cx] != s[b][cx]) return false;
	}
	return true;
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
		s[i] = buf;
		long long cc = 221321;
		hs[i].resize(len);
		forn(j, len) {
			cc = cc * 17 + buf[j];
			hs[i][j] = cc;
		}
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

