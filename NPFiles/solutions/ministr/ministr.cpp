//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

typedef struct sedge
{
  int u, v;
  struct sedge* next;
} tedge;

int N, M;
int S, E;
tedge* a[20001];
int d[20001];
int pr[20001];
int w1[20001];
int w2[20001];
int ans[20001];int top=0;

inline int cmp(const void* a, const void* b)
{
  return *((int*)a)-*((int*)b);
}

int main(int argc, char* argv[])
{
  register int i, j;
  int u, v;
  int uw;
  tedge* p;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &N, &M);
  for (i=0; i<M; i++)
  {
    scanf("%d %d", &u, &v);
    p=new tedge;
    p->u=u; p->v=v;
    p->next=a[p->u];
    a[p->u]=p;
    p=new tedge;
    p->u=v; p->v=u;
    p->next=a[p->u];
    a[p->u]=p;
  }
  scanf("%d %d", &S, &E);
  for (i=1; i<=N; i++)
    d[i]=200000;
  d[S]=0;
  while (1)
  {
    u=-1;
    uw=200000;
    for (i=1; i<=N; i++)
      if (!w1[i] && d[i]<uw)
      {
        uw=i;
        u=i;
      }
    if (u<0) break;
    w1[u]=true;
    for (p=a[u]; p!=NULL; p=p->next)
      if (!w1[i] && d[p->v]>d[p->u])
      {
        d[p->v]=d[p->u];
        pr[p->v]=p->u;
      }
  }
  for (i=1; i<=N; i++)
  {
    d[i]=200000;
    w1[i]=0;
  }
  for (i=pr[E]; i!=S; i=pr[i])
    w1[i]=1;
  for (i=1; i<=N; i++)
    pr[i]=0;
  d[E]=0;
  while (1)
  {
    u=-1;
    uw=200000;
    for (i=1; i<=N; i++)
      if (!w2[i] && d[i]<uw)
      {
        u=i;
        uw=d[i];
      }
    if (u<0) break;
    w2[u]=true;
    for (p=a[u]; p!=NULL; p=p->next)
      if (!w2[p->v] && d[p->v]>d[p->u]+w1[p->v])
      {
        d[p->v]=d[p->u]+w1[p->v];
        pr[p->v]=p->u;
      }
  }
  for (i=S; i!=E; i=pr[i])
  {
    if (d[pr[i]]<d[i])
      ans[top++]=i;
  }
  qsort(ans, top, sizeof(ans[0]), cmp);
  printf("%d\n", top);
  for (i=0; i<top; i++)
    printf("%d\n", ans[i]);
  return 0;
}
//---------------------------------------------------------------------------
