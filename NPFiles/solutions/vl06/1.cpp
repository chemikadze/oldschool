//---------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#pragma argsused

int N;

int pw10(int i)
{
  int r=1;
  while (i-->0)
    r*=10;
  return r;
}

int main(int argc, char* argv[])
{
  int i;
  int L=0;
  scanf("%d",&N);
  for (i=0;L<N;)
    L+=(int)floor(log(++i)/log(10))+1;
  printf("%d", (i/pw10(L-N))%pw10(L-N+1) );
  scanf("%*s");
  return 0;
}
//---------------------------------------------------------------------------
