#include <string>
#include <iostream>

using namespace std;

const int PRIME1 = 37;

string* s;
int** hash;

bool prefix(int i, int j) {
	if (i != -1 && s[i].size() < s[j].size() && hash[i][s[i].size() - 1] == hash[j][s[i].size() -1]) {
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
	hash = new int*[n];
	for (int i = 0; i < n; ++i) {
		getline(cin, s[i], '\n');
		hash[i] = new int[s[i].size()];
		for (int j = 0; j <s[i].size(); ++j) {
			if (j) {
				hash[i][j] = hash[i][j - 1];
			} else {
				hash[i][j] = 0;
			}
			hash[i][j] = hash[i][j] * PRIME1 + s[i][j] - 'a';
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

