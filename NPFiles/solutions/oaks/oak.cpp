//---------------------------------------------------------------------------
#undef _DEBUG

#include <stdio.h>
#include <string.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#define OUTOAKS for(p=fst->next; p!=lst; p=p->next)printf("(%d) ", p->val);printf("\n");


//---------------------------------------------------------------------------

struct Sdeq
{
  struct Sdeq* last;
  struct Sdeq* next;
  short val;
  short ind;
};

typedef struct Sdeq Tdeq;

int N;
Tdeq *fst, *lst;
int w[201];
int top=0;

int main(int argc, char* argv[])
{
  int i, j;
  bool cutted;
  Tdeq* p;

  #ifndef _DEBUG
  freopen("oaks.in", "r", stdin);
  freopen("oaks.out", "w", stdout);
  #endif

  fst=new Tdeq;
  lst=new Tdeq;
  fst->last=lst->next=NULL;
  fst->next=lst;
  lst->last=fst;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
  {
    p=new Tdeq;
    p->last=lst->last;
    p->next=lst;
    lst->last->next=p;
    lst->last=p;
    scanf("%d", &(p->val));
    p->ind=i;
  }
  if (fst->next->val > lst->last->val)
  {
    top=-1;
    goto END;
  }
  #ifdef _DEBUG
  //  OUTOAKS;
  #endif
  do
  {
    cutted=false;
    p=fst->next->next;
    while (p->next!=lst)
    {
      if ( (p->val < fst->next->val || p->val > lst->last->val) &&
           ((p->val < p->last->val && p->val < p->next->val) ||
            (p->val > p->last->val && p->val > p->next->val)) )
      {
        p->last->next=p->next;
        p->next->last=p->last;
        w[++top]=p->ind;
        cutted=true;
      }
      p=p->next;
    }
  }
  while (cutted);
  #ifdef _DEBUG
  //  OUTOAKS;
  #endif
  do
  {
    cutted=false;
    p=fst->next->next;
    while (p->next!=lst)
    {
      if ( ((p->val < p->last->val && p->val < p->next->val) ||
            (p->val > p->last->val && p->val > p->next->val)) )
      {
        p->last->next=p->next;
        p->next->last=p->last;
        w[++top]=p->ind;
        cutted=true;
      }
      p=p->next;
    }
  }
  while (cutted);
  #ifdef _DEBUG
  //  OUTOAKS;
  #endif
  p=fst->next;
  while (p->next!=lst)
  {
    if (p->val > p->next->val)
    {
      top=-1;
      break;
    }
    p=p->next;
  }
END:
  printf("%d\n", top);
  for (i=1; i<=top; i++)
 #ifdef _DEBUG
    printf("%d ", w[i]);
 #else
    printf("%d\n", w[i]);
 #endif
 #ifdef _DEBUG
  getch();
 #endif
  return 0;
}
//---------------------------------------------------------------------------
/*
5
4 5 5 5 6
> 0

5
3 2 4 8 5
> 2
> 2
> 4

6
400 300 310 300 310 500
> -1

6
1 1 3 3 2 2
> -1
*/