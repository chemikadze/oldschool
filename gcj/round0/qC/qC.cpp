#include <stdio.h>
#include <queue>

using std::queue;

int main()
{
	int T;
	FILE *f = fopen("input.txt", "r");

	fscanf(f, "%d", &T);
	for (int i=1; i<=T; ++i)
	{
		int R, k, N;
		long long ans = 0ll;
		queue <int> q;
		queue <int> coaster;

		fscanf(f, "%d%d%d", &R, &k, &N);
		for (int j=0; j<N; ++j)
		{
			int b;
			fscanf(f, "%d", &b);
			q.push(b);
		}

		for (int j=0; j<R; ++j)
		{
			int cap = k;
			while ( (cap - q.front() >= 0) && !q.empty())
			{
				cap -= q.front();
				ans += static_cast<long long>(q.front());
				coaster.push(q.front());
				q.pop();
			}
			while (!coaster.empty())
			{
				q.push(coaster.front());
				coaster.pop();
			}
		}

		printf("Case #%d: %lld\n", i, ans);
	}

	return 0;
}
