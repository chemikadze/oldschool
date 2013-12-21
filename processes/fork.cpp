#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid, i;
	printf("Starting...\n");
	pid=fork();
	if (pid)
		for (i=0; i<10000; i++)
			putchar('A');
	else
		for (i=0; i<10000; i++)
			putchar('B');
}
