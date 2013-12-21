#include <stdio.h>
#include <stdlib.h>

int main()
{FILE* in=fopen("sequence.in","r");
 FILE* out=fopen("sequence.out","w");
 long int n;
 float* a;
 long int i;

 fscanf(in,"%ld",&n);
 a=(float*)calloc(n,sizeof(float));
 for (i=0;i<n;i++)
  fscanf(in,"%f",&a[i]);
 for (i=n-1;i>=0;i--)
  fprintf(out,"%.0f ",a[i]);

 fclose(in);
 fclose(out);
 return 0;
}