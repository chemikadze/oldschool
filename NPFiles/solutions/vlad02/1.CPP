#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a,b,c,d;
  for (a=1;a<=3;a++)
    for (b=0;b<=9;b++)
      for (c=0;c<=9;c++)
	for (d=0;d<=9;d++)
	  if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d && ((a*10+b)-(c*10+d)==a+b+c+d))
	   printf("%d%d%d%d\n",a,b,c,d);
  scanf("%*s");
  return 0;
}