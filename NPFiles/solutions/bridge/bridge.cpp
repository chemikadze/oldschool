//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

typedef struct sedge
{
  int u, v;
  int i;
  struct sedge* next;
} tedge;

typedef struct stimep
{
  int i, t;
} timep;

const int GR=1;
const int BL=2;

int N, M;
timep* tp[20001]; int tm=1;
int c[20001]; int nc=1;
tedge* a[20001];
int st[200001]; int top=0;

inline int tmpcmp(const void* a, const void* b)
{
  return (*(timep**)b)->t-(*(timep**)a)->t;
}

inline int intcmp(const void* a, const void* b)
{
  return (*(int*)a)-(*(int*)b);
}

void dfs2(int u)
{
  register tedge *p;
  c[u]=nc;
  for (p=a[u]; p!=NULL; p=p->next)
    if (!c[p->v] && p->i)
      dfs2(p->v);
}

void dfs1(int u)
{
  register tedge *p=a[u];
  tp[p->u]=new timep;
  for (; p!=NULL; p=p->next)
    if (tp[p->v]==NULL)
    {
      dfs1(p->v);
      p->i=0;
    }
  tp[u]->i=u;
  tp[u]->t=tm++;
}

int main(int argc, char* argv[])
{
  tedge* p;
  int u, v;
  register int i, j;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &N, &M);
  for (i=0; i<M; i++)
  {
    scanf("%d %d", &(u), &(v));
    p=new tedge;
    p->i=i+1;
    p->u=u; p->v=v;
    p->next=a[p->u];
    a[p->u]=p;
    
    p=new tedge;
    p->i=i+1;
    p->v=u; p->u=v;
    p->next=a[p->u];
    a[p->u]=p;
  }
  for (i=1; i<=N; i++)
    if (tp[i]==NULL)
      dfs1(i);
  qsort(tp+1, N, sizeof(tp[0]), tmpcmp);
  for (i=1; i<=N; i++)
    if (!c[tp[i]->i])
    {
      dfs2(tp[i]->i);
      nc++;
    }
  for (i=1; i<=N; i++)
    for (p=a[i]; p!=NULL; p=p->next)
      if (p->i && c[p->u]!=c[p->v])
        st[top++]=p->i;
  qsort(st, top, sizeof(st[0]), intcmp);    
  printf("%d\n", top);
  for (i=0; i<top; i++)
    printf("%d\n", st[i]);
  return 0;
}
//---------------------------------------------------------------------------
