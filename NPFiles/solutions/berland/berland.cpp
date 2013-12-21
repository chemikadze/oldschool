//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#define INF 100000000

//---------------------------------------------------------------------------

struct SReb
{
  int u, v;
  unsigned int l;
  int t;
  struct SReb* next;
};
typedef struct SReb TReb;

int N, M;
unsigned int wt[4001];
int prev[4001]; //prev min
TReb* w[4001];
unsigned int ans[4001];
unsigned int wm[4001];
bool woz[4001];


void getwt()
{
  int i, u;
  unsigned int minu;
  for (i=1; i<=N; i++) woz[i]=false;
  TReb* p;
  wt[1]=0;
  while (1)
  {
    u=-1;
    minu=INF;
    for (i=1; i<=N; i++)
      if (minu>wt[i] && !woz[i])
        minu=wt[i], u=i;
    if (u<0)
      break;
    woz[u]=true;
    p=w[u];
    while (p!=NULL)
    {
      if (p->t && wt[p->v]>wt[p->u]+p->l)
      {
        wt[p->v]=wt[p->u]+p->l;
        prev[p->v]=u;
      }
      p=p->next;
    }
  }
}

int minp(int a)
{
  int i, u;
  unsigned int minu;
  for (i=1; i<=N; i++)
  {
    woz[i]=false;
    wm[i]=INF;
  }
  TReb* p;
  wm[a]=0;
  while (1)
  {
    u=-1;
    minu=INF;
    for (i=1; i<=N; i++)
      if (minu>wm[i] && !woz[i])
        minu=wm[i], u=i;
    if (u<0)
      break;
    woz[u]=true;
    p=w[u];
    while (p!=NULL)
    {
      if ((!(p->v==prev[a] && p->u==a && p->t)) && wm[p->v]>wm[p->u]+p->l)
        wm[p->v]=wm[p->u]+p->l;
      p=p->next;
    }
  }
  return wm[1];
}

int main(int argc, char* argv[])
{
  int i, j;
  unsigned int u, v, l, t;
  TReb* p;

  #ifndef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  scanf("%d %d", &N, &M);
  for (i=1; i<=N; i++)
    wt[i]=ans[i]=INF;
  for (i=1; i<=M; i++)
  {
    scanf("%d %d %d %d", &u, &v, &l, &t);
    p=new TReb;
    p->next=w[u];
    w[u]=p;
    p->u=u; p->v=v; p->l=l; p->t=t;

    p=new TReb;
    p->next=w[v];
    w[v]=p;
    p->v=u; p->u=v; p->l=l; p->t=t;
  }
  getwt();

  for (i=2; i<=N; i++)
    printf("%d ", minp(i));
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
