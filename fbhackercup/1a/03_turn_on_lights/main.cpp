#include <iostream>
#include <vector>
#include <set>
#include <deque>
using namespace std;

class Grid: public vector<vector<bool> > {
	int turned_off;

	template <class ref>
	void invert(ref c)
	{
		c = !c;
		if (c)
			--turned_off;
		else
			++turned_off;
	}
	
	void invert(int r, int c)
	{
		invert(this->at(r).at(c));
	}

public:
    Grid()
	{
	}

	Grid(const Grid& g) : vector<vector<bool> > (g), turned_off(g.turnedOff())
	{
	}

	Grid& operator=(const Grid& g)
	{
		this->clear();
		for (const_iterator it = g.begin(); it!=g.end(); ++it) {
			this->push_back(*it);
		}
		return *this;
	}

	Grid(int R, int C) : turned_off(R*C)
	{
		resize(R);
		for (Grid::iterator it = begin(); it != end(); ++it) {
			it->resize(C);
		}
	}

	Grid toggled(int r, int c) const
	{
		Grid g(*this);
		g.invert(r, c);
		if (c-1>=0) g.invert(r, c-1);
		if (c+1<g.front().size()) g.invert(r, c+1);
		if (r-1>=0) g.invert(r-1, c);
		if (r+1<g.size()) g.invert(r+1, c);
		return g;
	}

	void setValue(int r, int c, bool b)
	{
		if (this->at(r).at(c) && !b)
			++turned_off;
		if (!this->at(r).at(c) && b)
			--turned_off;
		this->at(r).at(c) = b;
	}

	int turnedOff() const
	{
		return turned_off;
	}
};

template <class ous>
ous& operator << (ous& os, const Grid& grid)
{
	for (Grid::const_iterator it = grid.begin(); it!=grid.end(); ++it) {
		for (int i=0; i<it->size(); ++i)
			os << ( (it->at(i)) ? 'X' : '.' );
		os << ' ';
	}
	os << endl;
}

int turnOn(const Grid& g)
{
	typedef pair<Grid,int> GridStep;
	set<Grid> grids;
	grids.insert(g);

	if (!g.turnedOff())
		return 0;
	deque<GridStep> deq;
	deq.push_back(GridStep(g, 0));
	while (!deq.empty()) {
		GridStep& currentStep = deq.front();
		Grid& current = currentStep.first;
		//cerr << current;
		for (int i=0; i<current.size(); ++i) {
			for (int j=0; j<current.front().size(); ++j) {
				GridStep next(current.toggled(i, j), currentStep.second+1);
				if (!next.first.turnedOff())
					return next.second;
				else {
					if (grids.find(next.first)==grids.end()) {
						grids.insert(next.first);
						deq.push_back(next);
					}
				}
			}
		}
		deq.pop_front();
	}
	return -1;
}

int main(int argc, char **argv) {
	int N;
	cin >> N;
	for (int test_i=0; test_i<N; ++test_i) {
		int R, C;
		cin >> R >> C;
		Grid g(R, C);
		for (int i=0; i<R; ++i) {
			string row;
			cin >> row;
			for (int j=0; j<C; ++j) {
				g.setValue(i, j, row[j] == 'X');
			}
		}
		cout << turnOn(g) << endl;
	}
    return 0;
}
