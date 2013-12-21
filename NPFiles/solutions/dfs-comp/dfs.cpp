//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

const int WH=0;
const int GR=1;
const int BL=2;

int N, M;
int a[100][100];//matrix
int c[100];     //component
int w[100];     //woz

int C=0;

void dfs(int v, int p)
{
  int i;
  c[v]=C;
  w[v]=GR;
  for (i=0; i<N; i++)
    if (a[v][i] && i!=v && i!=p && !w[i])
      dfs(i, v);
  w[v]=BL;
}

int main(int argc, char* argv[])
{
  int i;
  int x, y;
  printf("Enter N, M: ");
  scanf("%d %d", &N, &M);
  printf("Enter chords:\n");
  for (i=0; i<M; i++)
  {
    scanf("%d %d", &x, &y);
    a[--x][--y]=a[y][x]=1;
  }
  for (i=0; i<N; i++)
    if (!c[i])
    {
      C++;
      dfs(i,-1);
    }
  printf("%d", C);
  getch();
  return 0;
}
//---------------------------------------------------------------------------
