//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

const int INF=1000000000;

int N, M;
int S, F;
int a[100][100];
int path[10000];
bool w[10000];
int s[10000];

void printpath(const int u, const int l)
{
  if (u==-1)
    printf("%d\n", l);
  else
  {
    printpath(path[u], l+1);
    printf("%d " , u+1);
  }
}

int main(int argc, char* argv[])
{
  int i;
  int u, v, l;
  //printf("Enter N, M: ");
  scanf("%d %d", &N, &M);
  //printf("Enter start and finish point: ");
  scanf("%d %d", &S, &F);S--;F--;
  //printf("Enter chords: \n");
  for (i=0; i<M; i++)
  {
    scanf("%d %d %d", &u, &v, &l);
    a[--u][--v]=a[v][u]=l;
  }

  for (i=0; i<N; i++)
    s[i]=INF;

  s[S]=0;
  path[S]=-1;
  int min;
  while (true)
  {
    min=INF;
    u=-1;
    for (i=0; i<N; i++)
      if (!w[i] && s[i]<min)
      {
        min=s[i];
        u=i;
      }
    if (u==-1)
      break;
    w[u]=true;  
    for (i=0; i<N; i++)
      if (i!=u && s[i]>s[u]+a[u][i] && a[u][i])
      {
        s[i]=s[u]+a[u][i];
        path[i]=u;
      }
  }

  printf("Length is %d\n", s[F]);
  printpath(F, 0);
  getch();

  return 0;
}
//---------------------------------------------------------------------------
