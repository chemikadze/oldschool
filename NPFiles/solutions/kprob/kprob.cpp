//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
using std::min;

//---------------------------------------------------------------------------

struct shord
{
  int u, v;
  int l;
  struct shord* next;
};
typedef struct shord thord;

int K;
int a[101][101];
thord* g[10203];
int ans[10203];
bool wbg[101]; // [ problem ]

inline void newhord(int u, int v, int l)
{ thord* p=new thord; p->u=u; p->v=v; p->l=l; p->next=g[u]; g[u]=p; }

void bulidgraph(int lvl)
{
  register int i, j;
  if (lvl==K-1)
  {
    for (i=0; i<K; i++)
      newhord(lvl*K+i+1, K*K+1, 0);
    return;
  }
  for (i=0; i<K; i++)
    for (j=0; j<K; j++)
      if (!wbg[j])
      {
        wbg[j]=true;
        newhord(lvl*K+i+1, (lvl+1)*K+j+1, a[j][lvl]);
        bulidgraph(lvl+1);
        wbg[j]=false;
      }
}

int main(int argc, char* argv[])
{
  register int i, j, k;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &K);
 // for (i=0; i<K; i++)
 //   for (j=0; j<K; j++)
 //     scanf("%d", &a[i][j]);

  for (i=0; i<K; i++)
    newhord(0, i, a[i][0]);
  bulidgraph(0);

  //printf("%d", mina);
  return 0;
}
//---------------------------------------------------------------------------
