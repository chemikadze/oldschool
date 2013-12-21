//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
//---------------------------------------------------------------------------

#define MAXN 100000

struct snode
{
  int i;
  int u,v;
  struct snode *next;
};

struct srebro
{
  int name;
  int leave;
};

typedef struct snode tnode;
typedef struct srebro trebro;

FILE* in=fopen("tree.in","r");
FILE* out=fopen("tree.out","w");

tnode *w[MAXN];
trebro r[MAXN];

int N,K;

void indexate(int uu)
{
  tnode *node;
  bool b[MAXN];
  int q[MAXN];
  int l,r;
  int u,v;
  int i=0;
  l=r=0;
  b[uu]=true;
  q[r++]=uu;
  while (1)
  {
    u=q[l++];
    node=w[u];
    while (node!=NULL)
    {
      if (!b[node->v])
      {
        b[node->v]=true;
        ::r[node->v].leave=++i;
        q[r++]=node->v;
      }
      node=node->next;
    }
    if (l==r)
      return;
  }
}

void qsort(int left,int right)
{
  int i=left,j=right;
  int m=r[ (rand()%(right-left+1)+left) ].leave;
  while (i<=j)
  {
    while (r[i].leave<m) i++;
    while (r[j].leave>m) j--;
    if (i<=j)
      swap(r[i++],r[j--]);
  }
  if (i<right) qsort(i,right);
  if (j>left) qsort(left,j);
}

int getrbcnt(int i)
{
  int r=0;
  tnode* node=w[i];
  while (node!=NULL)
  {
    r++;
    node=node->next;
  }
  return r;
}

int main()
{
  int i,j;
  int u,v;
  int ans=0;
  int ansa[MAXN];
  tnode *node;
  fscanf(in,"%d %d",&N,&K);
  for (i=0;i<N-1;i++)
  {
    fscanf(in,"%d %d",&u,&v);
    node=new tnode;
    node->u=u-1;
    node->v=v-1;
    node->next=w[u-1];
    w[u-1]=node;
    w[u-1]->i=i;
    node=new tnode;
    node->v=u-1;
    node->u=v-1;
    node->next=w[v-1];
    w[v-1]=node;
    w[v-1]->i=i;
    r[i].name=i;
  }
  indexate(0);
  qsort(0,N-1);
  for (i=0;i<N-1;)
  {
    for (j=0; (j<(2*N/K)-1) && ((i+j)<N-1) ;j++)
      if (j>K/2 && getrbcnt(j)<2)
      {
        i+=j;
        j=0;
        ansa[ans++]=r[i].name;
      }
    i+=j;
    if (i<N)
      ansa[ans++]=r[i].name;
  }
  fprintf(out,"%d\n",ans);
  for (i=0;i<ans;i++)
    fprintf(out,"%d ",ansa[i]+1);
  fclose(in);
  fclose(out);
  return 0;
}
//---------------------------------------------------------------------------
