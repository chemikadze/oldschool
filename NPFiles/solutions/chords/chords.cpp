//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

int N;
int a[200002];
int ind[100001][2];
int st[100001]; int top=0;int head=0;
long long ans=0;

int main(int argc, char* argv[])
{
  int i, j;
  int ai, bi;
  int sv;
  #ifndef _DEBUG
  freopen("chords.in", "r", stdin);
  freopen("chords.out", "w", stdout);
  #endif
  scanf("%d", &N);
  for (i=1; i<=N; i++)
  {
    scanf("%d %d", &ai, &bi);
    if (ai>bi) swap(ai, bi);
    ind[i][0]=ai;
    ind[i][1]=bi;
    a[ai]=i;
    a[bi]=-i;
  }
  for (i=0; i<2*N; i++)
  if (a[i]!=0)
  {
    if (a[i]>0)
      st[++top]=a[i];
    else
    {
      sv=-a[i];
      j=top;
      
      while (st[j]!=sv)
      {
        if(st[j])
          ans++;
        j--;
      }
      st[j]=0;
    }
  }
  printf("%ld", ans);
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
