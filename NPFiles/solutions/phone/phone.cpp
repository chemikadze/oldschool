//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using std::max;

//---------------------------------------------------------------------------

const int lbase  = 1000000;
const int ldigit = 10;
typedef struct slong
{
  int v[11];
  void plus(struct slong* n);
  void assign(int n);
  void assign(struct slong* n);
  void zero();
  void print();
} tlong;

void tlong::plus(struct slong* n)
{
  tlong* b=new tlong;
  register int i;
  b->zero();
  for (i=1; i<=max(this->v[0], n->v[0]) || b->v[i]; i++)
  {
    b->v[i]+=this->v[i];
    b->v[i]+=n->v[i];
    b->v[i+1]+=b->v[i]/lbase;
    b->v[i]%=lbase;
  }
  b->v[0]=i;
  b->v[0]=i-!(b->v[b->v[0]]);
  this->assign(b);
}

void tlong::zero()
{
  register int i;
  this->v[0]=1;
  for (i=1; i<=ldigit; i++)
    this->v[i]=0;
}

void tlong::assign(int n)
{
  v[1]=n;
  v[0]=1;
}

void tlong::assign(struct slong* n)
{
  register int i;
  for (i=0; i<=n->v[0]; i++)
    this->v[i]=n->v[i];
}

void tlong::print()
{
  register int i;
  printf("%d", this->v[this->v[0]]);
  for (i=v[0]-1; i>0; i--)
    printf("%06d", this->v[i]);
}

void newsum2(tlong* &a, tlong *b, tlong *c)
{
  a=new tlong; a->zero();
  a->plus(b); a->plus(c);
}

int N;
tlong* a[100][10];
tlong* ans;

int main(int argc, char* argv[])
{
  register int i, j;
  scanf("%d", &N);
  for (i=0; i<10; i++)
  {
    a[0][i]=new tlong;
    a[0][i]->zero();
    if (i!=0 && i!=8)
      a[0][i]->assign(1);
  }
  for (i=1; i<N; i++)
  {
    newsum2(a[i][0], a[i-1][4], a[i-1][6]);
    newsum2(a[i][1], a[i-1][8], a[i-1][6]);
    newsum2(a[i][2], a[i-1][7], a[i-1][9]);
    newsum2(a[i][3], a[i-1][4], a[i-1][8]);
    newsum2(a[i][4], a[i-1][9], a[i-1][3]); a[i][4]->plus(a[i-1][0]);
    a[i][5]=new tlong; a[i][5]->zero();
    newsum2(a[i][6], a[i-1][1], a[i-1][7]); a[i][6]->plus(a[i-1][0]);
    newsum2(a[i][7], a[i-1][2], a[i-1][6]); 
    newsum2(a[i][8], a[i-1][1], a[i-1][3]);
    newsum2(a[i][9], a[i-1][4], a[i-1][2]);
  }
  ans=new tlong;
  ans->zero();
  for (i=0; i<10; i++)
    ans->plus(a[N-1][i]);
  ans->print();
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n');fgetc(stdin);
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 