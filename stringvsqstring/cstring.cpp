#include <cstdio>
#include <cstring>

int main()
{
	char *s=new char[14+5];
	int i;
	for (i=0; i<1000000; i++)
	{
		delete s;
		s=new char[14+5];
		sprintf(s, "%s %s %s %s", "one", "two", "three", "four");
	//	sprintf(s, "%s", "one");
	}
	printf(s);
	return 0;
}
