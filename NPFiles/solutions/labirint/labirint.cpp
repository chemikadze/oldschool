//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

struct sdoor
{
  int u, v;
  int w;
};
typedef struct sdoor tdoor;

int N, M;
tdoor* a[2000];
int d[2000];

int main(int argc, char* argv[])
{
  bool good=false;
  bool wN=false;
  register int i, j;
  int u, v, w;
  tdoor* p;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &N, &M);
  for (i=0; i<M; i++)
  {
    scanf("%d %d %d", &u, &v, &w);
    p=new tdoor;
    p->u=u-1; p->v=v-1; p->w=w;
    a[i]=p;
  }
  d[0]=0;
  for (i=0; i<N-1; i++)
    for (j=0; j<M; j++)
      if (d[a[j]->v]<d[a[j]->u]+a[j]->w)
      {
        d[a[j]->v]=d[a[j]->u]+a[j]->w;
        if (a[j]->v==N-1) wN=true;
      }
  for (j=0; j<M; j++)
    if (d[a[j]->v]<d[a[j]->u]+a[j]->w)
    {
      d[a[j]->v]=d[a[j]->u]+a[j]->w;
      if (a[j]->v==N-1)
        good=true;
    }
  if (!wN)
    printf(":(");
  else
    if (good)
      printf(":)");
    else
      printf("%d", d[N-1]);

  return 0;
}
//---------------------------------------------------------------------------
