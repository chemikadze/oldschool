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

int N;
tlong* a[101][2];
tlong* ans;

int main(int argc, char* argv[])
{
  register int i, j;
  scanf("%d", &N);
  for (i=0; i<=N; i++)
    for (j=0; j<3; j++)
    {
      a[i][j]=new tlong;
      a[i][j]->zero();
    }
  a[0][0]->v[1]=1;
  for (i=1; i<=N; i++)
  {
    a[i][0]->plus(a[i-1][0]); a[i][0]->plus(a[i-1][1]);
    a[i][1]->plus(a[i-1][0]);
  }
  ans=new tlong;
  ans->zero();
  ans->plus(a[N][0]); ans->plus(a[N][1]);
  ans->print();
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n');
  fgetc(stdin);
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 