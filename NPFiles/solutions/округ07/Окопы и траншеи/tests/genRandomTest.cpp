#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAXN = 5;
const int MAXD = 10000;

int main(int argc, char** args) {
	freopen(args[1], "w", stdout);
	srand(time(NULL));
	
	int ax, ay, bx, by;
	
	printf("%d\n", MAXN);
	for (int i = 0; i < MAXN; ++i) {
		int x = (int)(rand() / (double)RAND_MAX * 20000) - 10000;
		int y = (int)(rand() / (double)RAND_MAX * 20000) - 10000;
		if (i == 0) {
			ax = x;
			ay = y;
		}
		if (i == MAXN - 1) {
			bx = x;
			by = y;
		}
		printf("%d %d ", x, y);
		x = (int)(rand() / (double)RAND_MAX * 20000) - 10000;
		y = (int)(rand() / (double)RAND_MAX * 20000) - 10000;		
		printf("%d %d\n", x, y);
	}
	
	printf("%d %d\n", ax, ay);
	
	printf("%d %d\n", bx, by);
	return 0;
}