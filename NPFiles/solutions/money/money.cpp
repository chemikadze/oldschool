//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//---------------------------------------------------------------------------

FILE* in=fopen("money.in","r");
FILE* out=fopen("money.out","w");

unsigned long n;
unsigned long r=0;

int main()
{
  double b;
  fscanf(in,"%d",&n);

  while (n>1)
  {
    if (n>r) r=n;
    if (n%2)
      n+=2*n+1;
    else
      n/=2;
  }

  fprintf(out,"%d",r);
  fclose(in);
  fclose(out);

  return 0;
}
//---------------------------------------------------------------------------
