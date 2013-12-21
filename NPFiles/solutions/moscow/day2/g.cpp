//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

#define WHITE 0
#define GRAY  1
#define BLACK 2

//---------------------------------------------------------------------------

int N,M;
int a[1000][1000];
int w[1000];

bool tree(int v,int p)
{
  int i;
  w[v]=GRAY;
  for (i=0;i<N;i++)
    if (a[v][i] && i!=p && w[i]!=BLACK)
    {
      if (w[i]==GRAY)
      {
        printf("NO\n");
        #ifdef _DEBUG
        scanf("%*s");
        #endif
        return 0;
      }
      else
        tree(i,v);
    }
  w[v]=BLACK;
}

#pragma argsused
int main(int argc, char* argv[])
{
  int i,j;
  int x,y;
  bool b=false;

  #ifndef _DEBUG
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  scanf("%d %d",&N,&M);
  for (i=0;i<M;i++)
  {
    scanf("%d %d",&x,&y);
    a[--x][--y]=a[y][x]=1;
  }
  if (M!=N-1)
  {
    printf("NO\n");
    #ifdef _DEBUG
    scanf("%*s");
    #endif
    return 0;
  }
  tree(0,-1);
  printf("YES\n");
  #ifdef _DEBUG
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------
