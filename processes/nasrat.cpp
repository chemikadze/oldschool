#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

const int max_rat=1000;

int main()
{
	int rat_status=1;
	pid_t pid;	

	while (rat_status < max_rat)
	{
		pid=fork();
		if (!pid)
		{
			printf("Нас-рать! (вернее-%d)\n", rat_status);
			return 0;
		}
		rat_status++;
	}
	printf("Нас-тыща! (вернее-%d)\n", rat_status);
}
