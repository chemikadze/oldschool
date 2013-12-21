#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char * s=new char[255];
	printf("Enter you string: ");
	gets(s);
	printf("Char\tDec\tHex\t\n");
	for (i=0; i<strlen(s); i++)
		printf("%c\t%d\t0x%x\n", s[i], s[i], s[i]);
	return 0;
}
