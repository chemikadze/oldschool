#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	for (int i=0; i<10; ++i)
		printf("This is random number: %d. Hell yeah!\n", rand()%10 );
	return 0;
}
