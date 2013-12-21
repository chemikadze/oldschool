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
	cout << ans << endl;
}

void solve() {
	sort(l, l + n);
	sort(r, r + n);
	ans = 0;
	int ps = 0, lk = k;
	for(int i = n - 1; i >= 0; --i) {
		if (ps != 0) {
			ans += ps - r[i];
			ans += min(r[i] - l[i], lk);
			int len = r[i] - l[i];
			r[i] = max(l[i], r[i] - lk);
			lk -= min(len, lk);
			if (r[i] > l[i]) {
				ans += r[i];
				ps = 0;
				lk = k;
				++i;
			} else {
				ps = r[i];
			}
		} else {
			int kc = (r[i] - l[i]) / k;
			if (kc > 0) {
				long long fn = r[i] - (kc - 1) * k;
				ans += kc * (r[i] + fn);
			}
			r[i] -= kc * k;
			if (r[i] > l[i]) {
				lk = k - (r[i] - l[i]);
				ans += r[i];
				ans += r[i] - l[i];
				ps = l[i];
			} else {
				ps = 0;
				lk = k;
			}
		}
	}
	if (ps > 0) ans += ps;
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
		--l[i];
	}
	forn(i, n) {
		forn(j, i) {
			int cl = max(l[i] + 1, l[j] + 1);
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

