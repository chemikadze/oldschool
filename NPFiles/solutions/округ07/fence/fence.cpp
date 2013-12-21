//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

long N, K, M;
long path=0;
long desk;
long a[50][2];

int main(int argc, char* argv[])
{
  long i, j;

  #ifndef _DEBUG
  freopen("fence.in", "r", stdin);
  freopen("fence.out", "w", stdout);
  #endif
  scanf("%d %d %d", &N, &K, &M);
  for (i=0; i<M; i++)
  {
    scanf("%d %d", &a[i][0], &a[i][1]);
    desk+=a[i][1]-a[i][0]+1;
  }

  for (i=0; i<M; i++)
    for (j=1; j<M-i; j++)
      if (a[j-1][0]>a[j][0])
      {
        long b[2];
        b[0]=a[j-1][0];b[1]=a[j-1][1];
        a[j-1][0]=a[j][0];a[j-1][1]=a[j][1];
        a[j][0]=b[0];a[j][1]=b[j];
      }

  long delta, paint=0;
  for (i=M-1, j=0, paint=0; i>=0;)
  {
    if (!paint)
    {
      path+=j;
      j=a[i][1];
      paint=K;
      path+=j;
    }
    while (paint>0 && (a[i][0]<=a[i][1]))
    {
      delta=min(paint, a[i][1]-a[i][0]+1);
      paint-=delta;
      a[i][1]-=delta;
      path+=delta-1;
      j-=delta-1;
    }
    if (a[i][0]>a[i][1])
    {
      i--;
      if (i>=0 && paint>0)
      {
        path+=j-a[i][1];
        j=a[i][1];
      }
    }
  }
  path+=j;

  printf("%d", path);

  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
