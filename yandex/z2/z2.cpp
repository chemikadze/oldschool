#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;
using std::pair;

typedef std::pair<int, int> edge_t; // direction and length
typedef std::pair<int,int> query_t;

int N;
//vector <int> timeIn;
//vector <int> timeOut;
vector < vector<edge_t> > G;
vector <query_t> queries;
vector < vector<int> > P;
vector <bool> W;

void readGraph()
{
	cin >> N;
	G.resize(N);
	W.resize(N);
	P.resize(N);
	int logN = 0;
	for (int depth = 1; depth<N; depth<<=1, ++logN);
	for (int i = 0; i<N; ++i) {
		P[i].resize(logN);
	}
	std::fill(W.begin(), W.end(), false);
	for (int i = 1; i<N; ++i) {
		int from, to, len;
		edge_t v;
		cin >> from >> to >> len;
		--from; --to;
		G[from].push_back(edge_t(to, len));
		G[to].push_back(edge_t(from, len));
	}
}

void readQueries()
{
	int count;
	std::cin >> count;
	queries.resize(count-1);
	for (int i = 0; i<count; ++i) {
		query_t query;
		cin >> query.first >> query.second;
		--query.first; --query.second;
		queries.push_back(query);
	}
}

void preprocessTree(int vertex, int prev = 0)
{
	W[vertex] = true;
	P[vertex][0] = prev;
	for (int i = 1; i<=P[vertex].size(); ++i) {
		P[vertex][i] = P[P[vertex][i-1]][i-1];
	}
	for (int i = 0; i<G[vertex].size(); ++i) {
		if (!W[G[vertex][i].first])
			preprocessTree(G[vertex][i].first, vertex);
	}
}

bool isUpper(int first, int second)
{
	return std::find(P[second].begin(), P[second].end(), first) != P[second].end();
}

int processQuery(int a, int b)
{
	if (isUpper(a, b))
		return a;
	if (isUpper(b, a))
		return b;
	do {
		int i;
		for (i = 0; !isUpper(P[a][0], b); ++i);
		a = P[a][i-1];
	}
	while (!isUpper(P[a][0], b));
	return a;
}

int pathToUpper(int beg, int end)
{
	int path = 0;
	while (beg != end) {
		for (int i=0; i<G[beg].size(); ++i) {
			if (G[beg][i].first == P[beg][0]) {
				path += G[beg][i].second;
				beg = G[beg][i].first;
				break;
			}
		}
	}
	return path;
}

int main()
{
	readGraph();
	readQueries();
	preprocessTree(0);
	for (int i = 0; i<queries.size(); ++i) {
		const query_t& q = queries[i];
		int top = processQuery(q.first, q.second);
		std::cout << "Top = " << top << std::endl;
		std::cout << pathToUpper(q.first, top) + pathToUpper(q.second, top) << std::endl;
	}
}
