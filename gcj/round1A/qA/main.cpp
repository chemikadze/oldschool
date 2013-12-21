#include <vector>
#include <stdio.h>
#include <algorithm>

using std::swap;

void clear(bool **w, int N)
{
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			w[i][j] = true;
}

int main(int argc, char *argv[])
{
	int T;
	FILE* in = fopen("input.txt", "r");
	fscanf(in, "%d", &T);

	for (int test=1; test<=T; ++test)
	{
		int N, K;
		bool B, R;
		B = R = false;
		fscanf(in, "%d %d\n", &N, &K);

		char **m = new char*[N];
		bool **w = new bool*[N];
		for (int i=0; i<N; ++i)
		{
			m[i] = new char[N+1];
			w[i] = new bool[N+1];
			fscanf(in, "%s", m[i]);
			m[i][N] = '\0';
			for (int j=0; j<N; ++j)
				w[i][j] = true;
		}

		// columns
		for (int i = 0; i<N; ++i)
		{
			int start, stop, bottom;
			bottom = N-1;
			for (start = N-1; start >=0; --start)
			{
				if (m[i][start] != '.')
				{
					stop = start;
					while (stop>=0 && m[i][stop] != '.')
						--stop;
					for (int j=start; j>stop; --j)
						swap(m[i][bottom - (start-j)], m[i][j]);
					bottom = bottom - (start-stop);
					start = stop;
				}
			}
		}

		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
			{
				int k;
				if (w[i][j] && m[i][j]!='.' && ((m[i][j] == 'B' && !B) || (m[i][j] == 'R' && !R)))
				{
					for (k=i; k<N && m[i][j] == m[k][j] && w[k][j]; ++k)
						w[k][j] = false;
					if (k-i == K)
					{
						if (m[i][j] == 'B')
							B = true;
						else
							R = true;
					}

					clear(w, N);

					for (k=j; k<N && m[i][j] == m[i][k] && w[i][k]; ++k)
						w[i][k] = false;
					if (k-j == K)
					{
						if (m[i][j] == 'B')
							B = true;
						else
							R = true;
					}

					clear(w, N);

					// \
					k = 0;
					for (k = 0; (i+k)<N && (j+k)<N && m[i][j] == m[i+k][j+k] && w[i+k][j+k]; ++k)
						w[i+k][j+k] = false;
					if (k == K)
					{
						if (m[i][j] == 'B')
							B = true;
						else
							R = true;
					}
					clear(w, N);

					// /
					k = 0;
					for (k = 0; i+k<N && j-k>=0 && m[i][j] == m[i+k][j-k] && w[i+k][j-k]; ++k)
						w[i+k][j-k] = false;
					if (k == K)
					{
						if (m[i][j] == 'B')
							B = true;
						else
							R = true;
					}

					clear(w, N);
				}
			}
		if (B && R)
			printf("Case #%d: Both\n", test);
		else if (B)
			printf("Case #%d: Blue\n", test);
		else if (R)
			printf("Case #%d: Red\n", test);
		else
			printf("Case #%d: Neither\n", test);

		for (int i=0; i<N; ++i)
		{
			delete[] w[i];
			delete[] m[i];
		}
		delete[] m;
		delete[] w;
	}

	return 0;
}
