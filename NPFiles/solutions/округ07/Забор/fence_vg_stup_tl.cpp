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

#define C_IN_FILE "fence.in"
#define C_OUT_FILE "fence.out"

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define PII pair<int, int>
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

const int NMAX = 10000;

int n, k;
int l[NMAX];
int r[NMAX];
long long ans;

void outdata() {
	cout << ans * 2 << endl;
}

void solve() {
	sort(l, l + n);
	sort(r, r + n);
	int i = n - 1;
	while (i >= 0) {
		int z = k;
		while (i >= 0 && z > 0) {
			if (r[i] < l[i]) --i; else {
				if (z == k) ans += r[i];
				int dc = min(z, r[i] - l[i] + 1);
				r[i] -= dc;
				z -= dc;
			}
		}
	}
}

void readdata() {
	int len;
	assert(scanf("%d%d%d", &len, &k, &n) == 3);
	assert(1 <= len && len <= 1000000000);
	assert(1 <= k && k <= 100);
	assert(1 <= n && n <= 50);
	forn(i, n) {
		assert(scanf("%d%d", &l[i], &r[i]) == 2);
		assert(1 <= l[i] && l[i] <= r[i] && r[i] <= len);
	}
	forn(i, n) {
		forn(j, i) {
			int cl = max(l[i], l[j]);
			int cr = min(r[i], r[j]);
			assert(cl > cr);
		}
	}
}

int main() {
    freopen(C_IN_FILE, "rt", stdin);
    freopen(C_OUT_FILE, "wt", stdout);
	readdata();
	solve();
	outdata();
	return 0;
}

