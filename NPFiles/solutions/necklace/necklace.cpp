//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;

typedef struct snode
{
  int n;
  struct snode* left;
  struct snode* right;
  bool movleft();
} tnode;

bool tnode::movleft()
{
  int i;
  tnode *l, *r;
  if (this->n - this->left->n > 1)
  {
    l=this->left->left;
    r=this->right;

    l->right=this;
    r->left=this->left;
    l->right->left=l;
    r->left->right=r;
    l->right->right=r->left;
    r->left->left=l->right;
    for (i=n; i<=N; i++)
      printf("%d %d\n", r->left->n, i);
    return true;
  }
  return false;
}

tnode* head;

int main(int argc, char* argv[])
{
  tnode *maxnode;
  tnode *newnode;
  register int i, j;
  #ifdef _DEBUG
  freopen("necklace.in", "r", stdin);
  freopen("necklace.out", "w", stdout);
  #endif
  scanf("%d", &N);
  head=new tnode;
  head->left=head->right=head;
  maxnode=head;
  scanf("%d", &(head->n));
  for (i=1; i<N; i++)
  {
    newnode=new tnode;
    newnode->right=head;
    newnode->left=head->left;
    newnode->left->right=newnode;
    head->left=newnode;
    scanf("%d", &(head->left->n));
    if (maxnode->n < newnode->n)
      maxnode=newnode;
  }
  while (maxnode->n != 1)
  {
    while (maxnode->movleft());
    head=maxnode->left;
    maxnode=maxnode->left;
    while (head->right->n > head->n)
    {
      newnode=head->right;
      head->right->right->left=head;
      head->right=head->right->right;
      delete newnode;
    }
  }
  printf("0");
  return 0;
}
//---------------------------------------------------------------------------







