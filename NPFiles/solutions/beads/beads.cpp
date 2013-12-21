//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

struct s_chord
{
  int u, v;
  struct s_chord* next;
};

typedef struct s_chord t_chord;

int N;
t_chord* a[2501];
bool w[2501];
int st[2501];
int ans, maxans=1;

void dfs(int u)
{
  int v;
  t_chord *p;
  w[u]=true;
  maxans=max(maxans, ++ans);
  p=a[u];
  while (p!=NULL)
  {
    if (!w[p->v])
      dfs(p->v);
    p=p->next;
  }
  ans--;
}

int main(int argc, char* argv[])
{
  int i, j, x, y, k;
  t_chord* p;
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  scanf("%d", &N);
  while (scanf("%d %d", &x, &y)!=EOF)
  {
    p=new t_chord;
    p->u=x;
    p->v=y;
    p->next=a[x];
    a[x]=p;
    p=new t_chord;
    p->u=y;
    p->v=x;
    p->next=a[y];
    a[y]=p;
    st[x]++; st[y]++;
  }
  for (i=1; i<=N; i++)
  {
    if (st[i]==1)
    {
      for (j=1; j<=N; j++) w[j]=false;
      dfs(i);
    }
  }
  printf("%d", maxans);
  return 0;
}
//---------------------------------------------------------------------------
