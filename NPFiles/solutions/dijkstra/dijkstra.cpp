//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

const int INF=1000000000;

int N, M;
int in, out;
int a[100][100];
int s[10000];

int main(int argc, char* argv[])
{
  int i;
  int u, v, l;
  printf("Enter N, M: ");
  scanf("%d %d", &N, &M);
  printf("Enter in and out points: ");
  scanf("%d %d", &in, &out);in--;out--;
  printf("Enter chords: \n");
  for (i=0; i<M; i++)
  {
    scanf("%d %d %d", &u, &v, &l);
    a[--u][--v]=a[v][u]=l;
  }

  int min;
  int  s[10000];
  for (i=0; i<10000; s[i++]=INF);
  bool w[10000];
  s[in]=0;
  while (1)
  {
    u=-1;
    min=INF;
    for (i=0; i<N; i++)
      if (!w[i] && s[i]<min)
      {
        u=i;
        min=s[i];
      }
    if (u==-1)
      break;
    w[u]=true;
    for (i=0; i<N; i++)
      if (s[i]>s[u]+a[u][i] && a[u][i])
        s[i]=s[u]+a[u][i];
  }

  printf("%d", s[out]);
  getch();

  return 0;
}
//---------------------------------------------------------------------------
 