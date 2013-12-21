#include <stdio.h>
#include <algorithm>

int gcd(int a, int b)
{
		while (b != 0)
		{
				int t = b;
				b = a % b;
				a = t;
		}
		return a;
}


int main(int argc, char *argv[])
{
	int T;
	FILE *in = fopen("input.txt", "r");
	fscanf(in, "%d", &T);

	for (int test = 1; test<=T; ++test)
	{
		int A1, A2, B1, B2;
		int ans = 0;
		fscanf(in, "%d %d %d %d", &A1, &A2, &B1, &B2);
		for (int i=A1; i<=A2; ++i)
			for (int j=B1; j<=B2; ++j)
			{
				int A, B;
				A = std::max(i, j);
				B = std::min(i, j);

				if ()
			}
		printf("Case #%d: %d\n", test, ans);
	}
}
