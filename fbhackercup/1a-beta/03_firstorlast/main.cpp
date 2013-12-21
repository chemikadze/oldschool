#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
T gcd(T a, T b)
{
	while (b != 0) {
		T t = b;
		b = a % b;
		a = t;
	}
	return a;
}


struct frac_t;
template <class os>
os& operator<<(os& ostrm, const frac_t& frac);

struct frac_t {
	typedef long long _int;
	_int first;
	_int second;
	
	frac_t(uint f, uint s) : first(f), second(s)
	{}

	frac_t() : first(0), second(0)
	{}

	frac_t(const frac_t& s) : first(s.first), second(s.second)
	{}

	frac_t operator*(const int x)const
	{
		return frac_t(first*x, second*x);
	}

	frac_t operator+(const frac_t& sc)const
	{
		frac_t ans = frac_t(((*this)*sc.second).first + (sc*this->second).first, sc.second*this->second);
		_int t = gcd(ans.first, ans.second);
		return frac_t(ans.first/t, ans.second/t);
	}

	frac_t operator*(const frac_t& sc)const
	{
		frac_t ans = frac_t(sc.first * this->first, sc.second * this->second);
		_int t = gcd(ans.first, ans.second);
		return frac_t(ans.first/t, ans.second/t);
	}

	bool operator<(const frac_t& sc) const
	{
		return ((*this)*sc.second).first < (sc*this->second).first;
	}

	frac_t operator-(const frac_t& sc)const
	{
		frac_t ans = frac_t(((*this)*sc.second).first - (sc*this->second).first, sc.second*this->second);
		_int t = gcd(ans.first, ans.second);
		return frac_t(ans.first/t, ans.second/t);
	}
};

template <class os>
os& operator<<(os& ostrm, const frac_t& frac)
{
	return (ostrm << frac.first << '/' << frac.second);
}

typedef pair<frac_t,frac_t> turn_t;

bool cmpmax(const turn_t& a, const turn_t& b)
{
	return  max(b.first, b.second) < max(a.first, a.second);
}

frac_t solve(vector<turn_t>::iterator pos, vector<turn_t>::iterator end, int to_do = 0)
{
	sort(pos, end, cmpmax);
	frac_t ans(1, 1);
	for (vector<turn_t>::iterator it = pos; it != end; ++it) {
		if (to_do && it->second < it->first) {
			ans = ans * it->first;
			--to_do;
		}
		else {
			ans = ans * it->second;
		}
	}
	return ans;
}

int main(int argc, char **argv)
{
	int N;
	cin >> N;
	for (int i=0; i<N; ++i) {
		int R, T;
		cin >> R >> T;
		vector <turn_t> turns;
		turns.reserve(T);
		for (int j=0; j<T; ++j) {
			int over, notover;
			cin >> over >> notover;
			turns.push_back(turn_t( frac_t(1, 1) - frac_t(1, over), frac_t(1, 1) - frac_t(1, notover) ));
		}
		cout << solve(turns.begin(), turns.end(), R-1) << endl;
	}
	
    return 0;
}
