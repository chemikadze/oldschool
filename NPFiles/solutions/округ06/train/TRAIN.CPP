//#define _DEBUG
#ifdef _DEBUG
 #include <conio.h>
#endif
#include <stdio.h>
#include <string.h>

#define llong long long
#define ulong unsigned long

#define MAXN 8000

struct SNode
{
  char* val;
  ulong n;
  struct SNode* less;
  struct SNode* more;
};

typedef struct SNode TNode;

int N;
int a[MAXN];
int b[MAXN];
TNode* tree=NULL;
ulong count=0;
llong ans=0;
char fs[11];

ulong found(TNode* &nod)
{
  static char srav;
  static ulong r;
  if (nod==NULL)
  {
    nod=new TNode;
    nod->val=new char[strlen(fs)+1];
    strcpy(nod->val, fs);
    nod->less=nod->more=NULL;
    nod->n=++count;
  }
  srav=strcmp(fs, nod->val);
  if (srav==0) return nod->n;
  if (srav>0)
    r=found(nod->more)
    ;
  else
    r=found(nod->less);
  return r;
}

int main()
{
  int i, j;
  ulong k;
#ifndef _DEBUG
  freopen("train.in",  "r", stdin);
  freopen("train.out", "w", stdout);
#endif

  scanf("%d", &N);
  for (i=0; i<N; i++)
  {
    scanf("%s", &fs);
    k=found(tree);

    a[i]=k;
  }
  for (i=0; i<N; i++)
  {
    scanf("%s", &fs);
    k=found(tree);

    b[i]=k;
  }
/*---=======CODE=======---*/
  for (i=0; i<N; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");

  for (i=0; i<N; i++)
  {
    printf("%d ", b[i]);
  }
  printf("\n");
  printf("%d\n", ans);
#ifdef _DEBUG
  getch();
#endif
  return 0;
}





