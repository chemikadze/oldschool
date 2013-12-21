//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#define INF 1000000

//---------------------------------------------------------------------------

int N, M, K, V;
char l[101][101];
char r[101][101];
char v[101][101];
int a[101][101]; //sum
char path[101][101];
int max=INF;

void getpath(int x, int y)
{
  if (!x && !y) return;
  switch (path[x][y])
  {
    case 'U': getpath(x, y-1);break;
    case 'D': getpath(x, y+1);break;
    case 'R': getpath(x-1, y);break;
    case 'L': getpath(x+1, y);break;
  }
  printf("%c", path[x][y]);
}

void solv(int x, int y)
{
  if (x==M-K && y==(N-1))
  {
    if (a[x][y]<max)
      max=a[x][y];
    return;
  }
  if (x+1<=M-K)     //R
    if (a[x+1][y]>a[x][y]+r[x+1][y] && a[x][y]+r[x+1][y]<=max)
    {
      a[x+1][y]=a[x][y]+r[x+1][y];
      path[x+1][y]='R';
      solv(x+1, y);
    }
  if (x-1>=0)      //L
    if (a[x-1][y]>a[x][y]+l[x-1][y] && a[x][y]+r[x-1][y]<=max)
    {
      a[x-1][y]=a[x][y]+l[x-1][y];
      path[x-1][y]='L';
      solv(x-1, y);
    }
  if (y+1<N)      //U
    if (a[x][y+1]>a[x][y]+v[x][y+1] && a[x][y]+v[x][y+1]<=max)
    {
      a[x][y+1]=a[x][y]+v[x][y+1];
      path[x][y+1]='U';
      solv(x, y+1);
    }
  if (y-1>=0)    //D
    if (a[x][y-1]>a[x][y]+v[x][y-1] && a[x][y]+v[x][y-1]<=max)
    {
      a[x][y-1]=a[x][y]+v[x][y-1];
      path[x][y-1]='D';
      solv(x, y-1);
    }
}

int main(int argc, char* argv[])
{
  int i, j, k;
  int x, y;
  scanf("%d %d %d", &M, &N, &K);
  scanf("%d", &V);
  for (i=0; i<V; i++)
  {
    scanf("%d %d", &x, &y);
    r[(x-K+1>=0)?(x-K+1):0][y]=1;
    l[x][y]=1;
  }
  for (i=0; i<=N; i++)
    for (j=0; j<=M-K; j++)
      a[j][i]=INF;
  for (i=0; i<N; i++)
  {
    for (k=0; k<K; k++)
      v[0][i]+=l[k][i];
    for (k=1; k<=M-K; k++)
      v[k][i]=v[k-1][i]-l[k-1][i]+r[k][i];
  }
  a[0][0]=0;
  solv(0, 0);
  printf("%d\n", a[M-K][N-1]);
  getpath(M-K, N-1);
  printf("\n");
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
