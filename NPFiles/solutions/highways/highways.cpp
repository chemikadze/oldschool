//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//---------------------------------------------------------------------------

inline int sqr(int i) {return i*i;}

struct stown
{
  int x, y;
};
typedef struct stown ttown;

struct sroad
{
  double len;
  int u, v;
};
typedef struct sroad troad;

int N, M;
ttown* a[750];
troad* r[280875]; int rcount=0;
int g[750][750];
int cmp[750];
troad* ans[280875]; int anscount=0;


int roadcmp(const void* r1, const void* r2)
{
 if (((*((troad**)r1))->len)>((*((troad**)r2))->len)) return 1;
 if (((*((troad**)r1))->len)<((*((troad**)r2))->len)) return -1;
 return 0;
}

int main(int argc, char* argv[])
{
  register int i, j;
  int x, y;
  int bc;
  ttown* t;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &N);
  for (i=0; i<N; i++)
  {
    a[i]=new ttown;
    scanf("%d %d", &(a[i]->x), &(a[i]->y));
    cmp[i]=i;
  }
  scanf("%d", &M);
  for (i=0; i<M; i++)
  {
    scanf("%d %d", &x, &y);
    x--;y--;
    g[x][y]=g[y][x]=1;
    bc=cmp[y];
    for (j=0; j<N; j++)
      if (cmp[j]==bc)
        cmp[j]=cmp[x];
  }
  for (i=0; i<N; i++)
    for (j=i+1; j<N; j++)
    {
      r[rcount]=new troad;
      r[rcount]->u=i;
      r[rcount]->v=j;
      r[rcount]->len=(sqrt(sqr(a[i]->y-a[j]->y)+sqr(a[i]->x-a[j]->x)));
      rcount++;
    }
  qsort(r, rcount, sizeof(r[0]), roadcmp);
  for (i=0; i<rcount; i++)
    if (cmp[r[i]->u]!=cmp[r[i]->v] && !g[r[i]->u][r[i]->v])
    {
       ans[anscount++]=r[i];
       g[r[i]->u][r[i]->v]=g[r[i]->v][r[i]->u]=1;
       bc=cmp[r[i]->v];
       for (j=0; j<N; j++)
         if (cmp[j]==bc)
           cmp[j]=cmp[r[i]->u];
    }
  for (i=0; i<anscount; i++)
    printf("%d %d\n", ans[i]->u+1, ans[i]->v+1);
  return 0;
}
//---------------------------------------------------------------------------
