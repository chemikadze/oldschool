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

#define C_IN_FILE "house.in"
#define C_OUT_FILE "house.out"

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forv(i, v) for (int i = 0; i < (int)(v.size()); ++i)
#define fors(i, s) for (int i = 0; i < (int)(s.length()); ++i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define PII pair<int, int>
#define mp make_pair
#define VI vector<int>
#define VS vector<string>

int n;

const int NMAX = 600;
const int PMAX = 15;

long long pr[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int cres;
long long res[1<<20];
int primes, kv;

bool check() {
	long long maxres = 1;
	forn(i, 63) maxres *= 2;
	--maxres;
	long long xr = 1;
	forn(i, primes) xr *= pr[i];
	sort(res, res + cres);
	if (cres < NMAX || maxres / res[NMAX - 1] < xr) return false;
	return true;
}

void outdata() {
	long long xr = 1;
	forn(i, primes) xr *= pr[i];
	sort(res, res + cres);
	forn(i, n) {
		if (i > 0) cout << " ";
		cout << xr * res[i];
	}
	cout << endl;
//	cerr << cres << endl;
}

void go(int v, int k, long long cr) {
	if (v >= primes) {
		if (k == kv) {
			res[cres++] = cr;
		}
		return ;
	}
	if (k < kv) {
		go(v + 1, k + 1, cr * pr[v]);
	}
	go(v + 1, k, cr);
}

void solve(int p1, int p2) {
	primes = p1;
	kv = p2;
	cres = 0;
	go(0, 0, 1);
	if (check()) {
		cerr << p1 << " " << p2 << endl;
		outdata();
	}
}

void readdata() {
	scanf("%d", &n);
	for(int i = 1; i <= PMAX; ++i) for(int j = 1; j <= i; ++j) solve(i, j);
}

int main() {
    freopen(C_IN_FILE, "rt", stdin);
    freopen(C_OUT_FILE, "wt", stdout);
	readdata();
//	solve();
//	outdata();
	return 0;
}

