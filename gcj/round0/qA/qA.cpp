#include <stdio.h>

int main()
{
	unsigned int T;
	unsigned int N, K;
	FILE *in;

	in = fopen("input.txt", "r");
	fscanf(in, "%d", &T);

	for (unsigned int i=1; i<=T; ++i)
	{
		fscanf(in, "%d%d", &N, &K);
		K %= (1 << N);
		bool ans = (K+1) == (1 << N);
		printf("Case #%d: %s\n", i, ans ? "ON" : "OFF");
	}

}
