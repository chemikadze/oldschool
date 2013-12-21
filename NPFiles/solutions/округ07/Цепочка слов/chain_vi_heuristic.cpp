#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string* s;
int* bigInd;
int* big;
bool** preCalc;
int nextBigInd = 0;

bool prefix(int i, int j) {
	if (i == -1) {
		return false;
	}
	if (s[i].size() >= 500 && s[j].size() >= 500) {
		return preCalc[bigInd[i]][bigInd[j]];
	}
	if (s[i].size() < s[j].size()) {
		for (int t = 0; t < s[i].size(); ++t) {
			if (s[i][t] != s[j][t]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

int main() {
	freopen("chain.in", "rt", stdin);
	freopen("chain.out", "wt", stdout);
	int n;
	scanf("%d\n", &n);
	s = new string[n];
	bigInd = new int[n];
	big = new int[n];
	int* hash = new int[n];
	for (int i = 0; i < n; ++i) {
		getline(cin, s[i], '\n');
		hash[i] = false;
		for (int j = 0; j < s[i].size(); ++j) {
			hash[i] = hash[i] * 37 + s[i][j] - 'a';
		}
		if (s[i].size() >= 500) {
			bigInd[i] = nextBigInd;
			big[nextBigInd] = i;
			nextBigInd++;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (hash[i] == hash[j] && s[i] == s[j]) {
				//return 0;
			}
		}
	}
	preCalc = new bool*[nextBigInd];
	for (int i = 0; i < nextBigInd; ++i) {
		preCalc[i] = new bool[nextBigInd];
	}
	for (int i = 0; i < nextBigInd; ++i) {
		for (int j = i + 1; j < nextBigInd; ++j) {
			int m = min(s[big[i]].size(), s[big[j]].size());
			preCalc[i][j] = preCalc[j][i] = false;
			for (int t = 0; t < m; ++t) {
				if (s[big[i]][t] != s[big[j]][t]) {
					goto cont;
				}
			}
			if (s[big[i]].size() < s[big[j]].size()) {
				preCalc[i][j] = true;
			}
			if (s[big[j]].size() < s[big[i]].size()) {
				preCalc[j][i] = true;
			}
cont:;
		}
	}
	int k;
	scanf("%d", &k);
	int ansl = 0;
	int ansr = -1;
	int last = -1;
	int l = 0;
	for (int i = 0; i < k; ++i) {
		int cur;
		scanf("%d", &cur);
		--cur;
		if (!prefix(last, cur)) {
			if (i - 1 - l + 1 > ansr - ansl + 1) {
				ansl = l;
				ansr = i - 1;
			}
			l = i;
		}
		last = cur;
	}
	if (k - 1 - l + 1 > ansr - ansl + 1) {
		ansl = l;
		ansr = k - 1;
	}
	printf("%d %d", ansl + 1, ansr + 1);
	return 0;
}