//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using std::min;
using std::max;

//---------------------------------------------------------------------------

int N;
int x[100];
int w[100];
int ans=0;

int cmp(const void* a, const void* b)
{
  return *((int*)a)-*((int*)b);
}

int main(int argc, char* argv[])
{
  register int i, j;
  scanf("%d", &N);
  for (i=0; i<N; i++)
    scanf("%d", &x[i]);
  qsort(x, N, sizeof(x[0]), cmp);

  if (N>=3)
  {
    ans+=x[1]-x[0]; ans+=x[N-1]-x[N-2];
    w[1]=w[N-1]=1;
    for (i=2; i<N-2; i++)
      if (x[i]-x[i-1]<x[i+1]-x[i] && !w[i])
      {
        ans+=x[i]-x[i-1];
      }
      else
        if (i+1!=N-2)
        {
          ans+=x[i+1]-x[i];
          w[i+1]=1;
        }
  }
  else
  {
    if (N>1) ans+=x[1]-x[0];
  }
  printf("%d", ans);
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n'); fgetc(stdin);
  #endif
  return 0;
}
//---------------------------------------------------------------------------
