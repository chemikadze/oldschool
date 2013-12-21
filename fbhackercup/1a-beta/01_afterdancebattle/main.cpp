#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

typedef std::pair<int,int> point_t;
const int INF = 100*100;

inline point_t operator+(const point_t f, const point_t s)
{
	return point_t(f.first + s.first, f.second + s.second);
}

int solveMaze(const vector <string>& maze)
{
	list <point_t> wave_front;
	vector < vector<point_t> > coords(10);
	vector < vector<int> > steps(maze.size(), vector<int>(maze.front().size(), INF));
	int start_row = find(maze.front().begin(), maze.front().end(), 'S') - maze.front().begin();
	int end_row = find(maze.back().begin(), maze.back().end(), 'E') - maze.back().begin();
	steps.front()[start_row] = 0;
	for (int i=0; i<maze.size(); ++i) {
		for (int j=0; j<maze[i].size(); ++j) {
			if (maze[i][j]>'0' && maze[i][j]<='9') {
				coords[maze[i][j]-'0'].push_back(point_t(i, j));
			}
		}
	}
	
	wave_front.push_back(point_t(0, start_row));
	while (!wave_front.empty()) {
		point_t curr = wave_front.front();
		wave_front.pop_front();
		static const point_t d[] = { point_t(-1, 0), point_t(1, 0), point_t(0, 1), point_t(0, -1) };
		for (int i = 0; i<4; ++i) {
			point_t nxt = curr + d[i];
			if (nxt.first >= 0 && nxt.first < maze.size() && nxt.second >=0 && nxt.second < maze.front().size() && maze[nxt.first][nxt.second] != 'W' &&
				(steps[curr.first][curr.second]+1 < steps[nxt.first][nxt.second])
			) {
				wave_front.push_back(nxt);
				steps[nxt.first][nxt.second] = steps[curr.first][curr.second]+1;
			}
		}
		if (maze[curr.first][curr.second]>'0' && maze[curr.first][curr.second]<='9') {
			int color = maze[curr.first][curr.second]-'0';
			for (int i = 0; i<coords[color].size(); ++i) {
				point_t nxt = coords[color][i];
				if (coords[color][i]!=curr && steps[curr.first][curr.second]+1 < steps[nxt.first][nxt.second]) {
					wave_front.push_back(nxt);
					steps[nxt.first][nxt.second] = steps[curr.first][curr.second]+1;
				}
			}
		}
	}

	for (int i=0; i<maze.size(); ++i) {
		for (int j=0; j<maze[i].size(); ++j) {
			cerr << steps[i][j] << ' ';
		}
		cerr << endl;
	}
	cerr << endl;
	
	return steps.back()[end_row];
}

int main(int argc, char **argv)
{
	int N;
	cin >> N;
	for (int i=0; i<N; ++i) {
		vector <string> maze;
		int R, C;
		cin >> R >> C;
		for (int j=0; j<R; ++j) {
			string s;
			cin >> s;
			maze.push_back(s);
		}
		cout << solveMaze(maze) << endl;
	}
	return 0;
}
