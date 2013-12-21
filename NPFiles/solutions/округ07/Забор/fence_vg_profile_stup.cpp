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

const int SMAX = 18;

int n, k;
int l[NMAX];
int r[NMAX];
long long ans;
vector<int> np, gm;
long long res[1 << SMAX];

void outdata() {
}

void solve() {
	sort(l, l + n);
	sort(r, r + n);
	np.clear();
	forn(i, n) for(int j = l[i]; j <= r[i]; ++j) np.pb(j);
	sort(all(np));
	if ((int)np.size() > SMAX) {
		cerr << "Sorry test too large" << endl;
		exit(0);
	}
	memset(res, 60, sizeof res);
	res[0] = 0;
    forn(msk, 1 << np.size()) {
    	int q = msk, kl = 0;
    	while (q) {
    		q = q & (q - 1);
    		++kl;
    	}
    	if (kl <= k) gm.pb(msk);
    }
    forn(msk, 1 << np.size()) {
		forv(z, gm) {
			int add = gm[z];
    		if ((add > 0) && (msk & add) == 0) {
    			int mx = 0;
    			int q = add;
    			while (q) {
    				++mx;
    				q >>= 1;
    			}
				--mx;
    			if (res[msk ^ add] > res[msk] + np[mx]) {
    				res[msk ^ add] = res[msk] + np[mx];
    			}
    		}
		}
    }
    cout << res[(1 << np.size()) - 1] * 2 << endl;

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

