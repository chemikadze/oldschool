#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	int i, pid, code;
	printf("Внимание! Большие дети без присмотра быстро становятся маленькими родителями!\n");
	pid=fork();
	if (!pid)
	{
		execlp("echo", "echo" , "Вернее уже стали...\n", NULL);
		if (errno=ENOEXEC)
			 printf("running failed\n");
	}
}
