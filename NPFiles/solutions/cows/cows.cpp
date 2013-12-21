//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

typedef struct svert
{
  long u, v;
  struct svert *next;
} tvert;

typedef struct spoint
{
  long x, y;
} tpoint;

typedef struct sdesk
{
  tpoint *u, *v;
} tdesk;

int N;
sdesk *d[2000];
tpoint *in=new tpoint, *out=new tpoint;
tpoint *pnt[1000];  int pc=0;
tvert* g[2000];
int w[2000];
int U, V;
long ans;

void dfs(int u)
{
  register tvert *v;
  if (u==V)
  {
    ans++; return;
  }
  w[u]=1;
  for (v=g[u]; v!=NULL; v=v->next)
    if (!w[v->v])
    {
      dfs(v->v);
      break;
    }
}

int main(int argc, char* argv[])
{
  register int i, j;
  tvert *p;
  int u, v;
  #ifndef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &N);
  for (i=0; i<N; i++)
  {
    d[i]=new sdesk;
    d[i]->u=new tpoint;
    d[i]->v=new tpoint;
    scanf("%d %d %d %d", &(d[i]->u->x), &(d[i]->u->y), &(d[i]->v->x), &(d[i]->v->y));
  }
  scanf("%d %d %d %d", &(in->x), &(in->y), &(out->x), &(out->y));
  for (j=0; j<pc && !(pnt[j]->x==in->x && pnt[j]->y==in->y); j++);
  if (j==pc)
    pnt[pc++]=in;
  U=j;
  for (j=0; j<pc && !(pnt[j]->x==out->x && pnt[j]->y==out->y); j++);
  if (j==pc)
    pnt[pc++]=out;
  V=j;
  for (i=0; i<N; i++)
  {
    for (j=0; j<pc && !(pnt[j]->x==d[i]->u->x && pnt[j]->y==d[i]->u->y); j++);
    if (j==pc)
      pnt[pc++]=d[i]->u;
    u=j;
    for (j=0; j<pc && !(pnt[j]->x==d[i]->v->x && pnt[j]->y==d[i]->v->y); j++);
    if (j==pc)
      pnt[pc++]=d[i]->v;
    v=j;

    p=new tvert;
    p->u=u; p->v=v;
    p->next=g[u];
    g[u]=p;
    p=new tvert;
    p->u=v; p->v=u;
    p->next=g[v];
    g[v]=p;
  }
  w[U]=1;
  for (p=g[U]; p!=NULL; p=p->next)
    if (!w[p->v])
      dfs(p->v);
  printf("%d", ans);
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n'); fgetc(stdin);
  #endif
  return 0;
}
//---------------------------------------------------------------------------
