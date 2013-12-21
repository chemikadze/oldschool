//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

#define UP +10
#define DN -10
#define DOT 11
#define INF 1000000

int X, Y;
int b[4][4];
int g[200][200];
int ans[200];

extern int getav(int n);
extern void dijkstra();

int main(int argc, char* argv[])
{
  int i, j;
  #ifndef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  for (i=0; i<2; i++)
    for (j=0; j<4; j++)
      scanf("%d", &b[i][j]);
  for (j=0; j<3; j++)
    scanf("%d", &b[i][j]);
  for (j=0, i++; j<2; j++)
    scanf("%d", &b[i][j]);
  scanf("%d %d", &X, &Y);

  for (i=0; i<100-1; i++)
  {
    g[i][i+1]=getav(UP);
    g[i+1][i]=getav(DN);
    g[i+100][i+1+100]=getav(UP);
    g[i+1+100][i+100]=getav(DN);
  }
  g[0][99]=getav(DN);
  g[99][0]=getav(UP);
  g[100][199]=getav(DN);
  g[199][100]=getav(UP);
  for (i=0; i<100; i++)
  {
    g[i][i+100]=g[i+100][i]=getav(DOT);
    for (j=0; j<10; j++)
      g[i][j]=(getav(j) && i!=j) || g[i][j];
  }
  for (i=100; i<200; i++)
    for (j=100; j<200; j++)
    {
      g[i][j]=(g[i][j])?(g[i][j]):(2*(getav((j-100)/10) && getav((j-100)%10)));
    }
  for (i=0; i<200; i++)
  {
    ans[i]=INF;
    for (j=0; j<200; j++)
      if (!g[i][j])
        g[i][j]=INF;
  }
  dijkstra();
  printf("%d", (min(ans[Y], ans[Y+100])<INF)?(min(ans[Y], ans[Y+100])):(-1));
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n');
  fgetc(stdin);
  #endif
  return 0;
}

void dijkstra()
{
  int u, v, i;
  int minu;
  int p[200];
  bool w[200];
  for (i=0; i<200; i++)
  {
    w[i]=false;
    p[i]=-1;
  }
  ans[X]=0;
  while (true)
  {
    minu=INF;
    u=-1;
    for (i=0; i<200; i++)
      if (ans[i]<minu && !w[i])
      {
        minu=ans[i];
        u=i;
      }
    if (u<0)
      return;
    w[u]=true;
    for (v=0; v<200; v++)
      if (ans[v] > ans[u]+g[u][v])
      {
        ans[v]=ans[u]+g[u][v];
        p[v]=u;
      }
  }
  return;
}

int getav(int n)
{
  switch (n)
  {
    case UP: return b[0][3];
    case DN: return b[1][3];
    case DOT: return b[3][0];

    case 0: return b[3][1];

    case 1: return b[0][0];
    case 2: return b[0][1];
    case 3: return b[0][2];
    case 4: return b[1][0];
    case 5: return b[1][1];
    case 6: return b[1][2];
    case 7: return b[2][0];
    case 8: return b[2][1];
    case 9: return b[2][2];
  }
}
//---------------------------------------------------------------------------
