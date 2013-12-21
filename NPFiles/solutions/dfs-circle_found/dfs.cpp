//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;

const int WT=0;
const int GR =1;
const int BL=2;

//---------------------------------------------------------------------------

int N, M;
int a[100][100];
int c[100];

void dfs(int v, int p)
{
  int i;
  c[v]=GR;
  for (i=0; i<N; i++)
  if (a[v][i] && i!=v && i!=p)
    {
      if (c[i]==WT)
        dfs(i, v);
      else
        if (c[i]==GR && i!=v)
        {
          printf("There is a circle...\n");
          getch();
          exit(0);
        }
    }
  c[v]=BL;
}

int main(int argc, char* argv[])
{
  int i;
  int x,y;
  printf("Enter N, M: ");
  scanf("%d %d", &N, &M);
  printf("Enter a chord:\n");
  for (i=0; i<M; i++)
  {
    scanf("%d %d", &x, &y);
    a[--x][--y]=a[y][x]=1;
  }
  dfs(0, -1);
  printf("There is not any circles...\n");
  getch();
  return 0;
}
//---------------------------------------------------------------------------
