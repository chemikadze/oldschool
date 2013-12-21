//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <math.h>

//---------------------------------------------------------------------------

int N;
long double a[1000];

int main(int argc, char* argv[])
{
  int i, j;
  freopen("house.in","r",stdin);
  scanf("%d", &N);
  freopen("house.out","r",stdin);
  for (i=0; i<N; i++)
    scanf("%Lf", &a[i]);
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    {
      if (i!=j)
        if ((fmodl(a[i],a[j])==0) || (fmodl((a[i]*a[i]),a[j])!=0) )
        {
          printf("FAILED");
          return 0;
        }
    }
  return 0;
}
//---------------------------------------------------------------------------
 