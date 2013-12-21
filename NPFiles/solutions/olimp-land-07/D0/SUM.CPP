#include <stdio.h>
#include <stdlib.h>

int main()
{FILE* in=fopen("sum.in","r");
 FILE* out=fopen("sum.out","w");

 float a,b,c;

 fscanf(in,"%f %f",&a,&b);
 c=a+b;
 fprintf(out,"%.0f",c);

 fclose(in);
 fclose(out);
 return 0;
}