//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//---------------------------------------------------------------------------

#define L -1
#define R  1
#define MAXN 50001

struct snode
{
  int val;
  struct snode *left,*right;
};

typedef struct snode tnode;

FILE* in=fopen("formation.in","r");
FILE* out=fopen("formation.out","w");

tnode *v[MAXN];
tnode *left;
tnode *right;

tnode* newnode(const int sold,const int ind,const int pos)
{
  tnode *l;
  tnode *r;
  tnode *res=new tnode;
  res->val=sold;

  if (pos==R)
  {
    l=v[ind];
    r=v[ind]->right;
  }
  else
  {
    l=v[ind]->left;
    r=v[ind];
  }

  res->right=r;
  res->left=l;
  l->right=res;
  r->left=res;

  return res;
}

void deletenode(const int sold)
{
  tnode *l=v[sold]->left;
  tnode *r=v[sold]->right;

  l->right=r;
  r->left=l;

  delete v[sold];
  v[sold]=NULL;
}

void name(const int sold)
{
  fprintf(out,"%d %d\n",v[sold]->left->val,v[sold]->right->val);
}

int N,M;

int main()
{
  char s[6];
  int i,j;
  int sold,ind;

  left=new tnode;
  right=new tnode;
  left->left=right->right=NULL;
  left->right=right;
  right->left=left;
  left->val=right->val=0;

  fscanf(in,"%d %d",&N,&M);

  v[0]=left;
  v[1]=newnode(1,0,R);

  for (i=0;i<M;i++)
  {
    fscanf(in,"%s",&s);
    switch (s[0])
    {
      case 'l':
      case 'L':
        if (s[2]=='f')
        {
          fscanf(in,"%d %d",&sold,&ind);
          v[sold]=newnode(sold,ind,L);
        }
        else
        {
          fscanf(in,"%d",&sold);
          deletenode(sold);
        }
        break;

      case 'r':
      case 'R':
        fscanf(in,"%d %d",&sold,&ind);
        v[sold]=newnode(sold,ind,R);
        break;

      case 'n':
      case 'N':
        fscanf(in,"%d",&sold);
        name(sold);
        break;
    }
  }

  for (i=1;i<=N;i++)
    if (v[i]!=NULL)
      delete v[i];

  delete left;
  delete right;

  fclose(in);
  fclose(out);
  return 0;
}
//---------------------------------------------------------------------------
