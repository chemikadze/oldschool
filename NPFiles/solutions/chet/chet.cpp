//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

#define WH 1
#define BL 2

int N, M;
int a[101][101];
int col[101];
int cs[101], cmp=1;
int comps[101][3];

void yes()
{
  printf("YES");
  getch();
  exit(0);
}

void dfs(int u, int clr)
{
  int v;
  clr=(clr==WH)?(BL):(WH);
  if (col[u])
  {
    if (col[u]==clr)
      return;
    else
      yes();
  }    
  comps[cmp][clr]++;
  col[u]=clr;
  cs[u]=cmp;
  for (v=1; v<=N; v++)
    if (a[u][v])
      dfs(v, clr);
}

int main(int argc, char* argv[])
{
  int i, j;
  int x, y;
  int X=0;
  int maxcol;
  scanf("%d %d", &N, &M);
  for (i=1; i<=M; i++)
  {
    scanf("%d %d", &x, &y);
    a[x][y]=a[y][x]=1;
  }
  for (i=1; i<=N; i++)
    if (!cs[i])
    {
      dfs(i, WH);
      cmp++;
    }
  for (i=1; i<cmp; i++)
    X+=max(comps[i][WH], comps[i][BL]);
  printf("NO\n%d\n", X);
  for (i=1; i<cmp; i++)
  {
    maxcol=(comps[i][WH]>comps[i][BL])?(WH):(BL);
    for (j=1; j<=N; j++)
      if (col[j]==maxcol && cs[j]==i)
        printf("%d ", j);
  }
  getch();
  return 0;
}
//---------------------------------------------------------------------------
 