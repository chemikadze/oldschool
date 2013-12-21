//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N, S, V1, V2;
int a[1000][1000];
int p[1000];
int w[1000];

int main(int argc, char* argv[])
{
  register int i, j, u, v;
  int uw;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d %d %d", &N, &S, &V1, &V2);
  S--;V1--;V2--;
  for (i=0; i<N; i++)
  {
    for (j=0; j<N; j++)
    {
      scanf("%d ", &a[i][j]);
      if (!a[i][j]) a[i][j]=10000;
    }
    p[i]=10000;
    w[i]=0;
  }
  p[S]=0;
  while (1)
  {
    u=-1;
    uw=10000;
    for (i=0; i<N; i++)
      if (!w[i] && p[i]<uw)
      {
        uw=p[i];
        u=i;
      }
    if (u<0) break;
    w[u]=true;
    for (v=0; v<N; v++)
      if (p[v]>p[u]+a[u][v])
        p[v]=p[u]+a[u][v];
  }
  if (p[V1]<p[V2]) printf("1");
  else printf("0");
  return 0;
}
//---------------------------------------------------------------------------
