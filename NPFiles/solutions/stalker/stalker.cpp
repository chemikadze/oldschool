//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

#ifndef uint
typedef unsigned int uint;
#endif

typedef struct sroad
{
  uint u, v;
  uint c;
  struct sroad* next;
} troad;

typedef struct shouse
{
  uint c;
  struct shouse* next;
} thouse;

int N, K;
troad* g[300010];
troad* pg[2001];
thouse* c[2001]; uint comp=3;
int w[300010];
int  queue[300010], head=0, tail=0;

void componaize(int u)
{
  troad *e, *p;
  thouse *h;

  w[u]=true;
  for (e=pg[u]; e!=NULL; e=e->next)
  if (!e->c)
  {
    h=new thouse;
    h->c=comp;
    h->next=c[e->u];
    c[e->u]=h;
    for (h=h->next; h!=NULL; h=h->next)
    if (comp!=h->c)
    {
      p=new troad;
      p->u=comp;
      p->v=h->c;
      p->next=g[comp];
      g[comp]=p;
      p=new troad;
      p->v=comp;
      p->u=h->c;
      p->next=g[h->c];
      g[h->c]=p;
    }
    e->c=comp;
    if (!w[e->v])
      componaize(e->v);
  }
}

int main(int argc, char* argv[])
{
  register int i, j, k;
  int l;
  int u, v;
  troad* p, *e;
  thouse *h;
  #ifdef _DEBUG
  freopen("stalker.in", "r", stdin);
  freopen("stalker.out", "w", stdout);
  #endif
  scanf("%d %d", &N, &K);
  h=new thouse;
  h->c=1;
  h->next=c[1];
  c[1]=h;

  h=new thouse;
  h->c=2;
  h->next=c[N];
  c[N]=h;
  
  for (i=1; i<=K; i++)
  {
    scanf("%d", &l);
    for (j=0; j<l; j++)
    {
      scanf("%d %d", &u, &v);
      p=new troad;
      p->u=u; p->v=v; p->c=0;
      p->next=pg[u];
      pg[u]=p;
      p=new troad;
      p->u=v; p->v=u; p->c=0;
      p->next=pg[v];
      pg[v]=p;
    }
    for (j=1; j<=N; j++) w[j]=false;
    for (j=1; j<=N; j++)
      if (!w[j] && pg[j]!=NULL)
      {
        componaize(j);
        comp++;
      }
  }

  for (i=1; i<comp; i++) w[i]=0;
  queue[tail++]=1;
  w[1]=1;
  while (head < tail)
  {
    for (e=g[queue[head++]]; e!=NULL; e=e->next)
      if (!w[e->v])
      {
        w[e->v]=w[e->u]+!(e->u==1 || e->v==2);
        queue[tail++]=e->v;
      }
  }
  printf("%d", (w[2]) ? w[2] : -1);

  return 0;
}
//---------------------------------------------------------------------------
