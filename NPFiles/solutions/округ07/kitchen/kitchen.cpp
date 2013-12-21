//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#define max(X,Y) ((X>=Y)?(X):(Y))

#define BASE 10000

//---------------------------------------------------------------------------

struct SLONG
{
  int val[201];
  void mult(int x);
  void rav(int x);
  void sumlong(struct SLONG x);
  void print();
};

typedef struct SLONG LONG;

int a, b, n;
int w[100];
int c1, c2;
int l1,l2;
LONG ans;

void addsolut()           //IRREGULAR!!!
{
  int i;
  LONG pans;
  pans.rav(1);
  for (i=2; i<=c1; i++)
    pans.mult(i);
  for (i=2; i<=c2; i++)
    pans.mult(i);
  ans.sumlong(pans);
}

void get(int i)
{
  if (i==(n) && l1<=a && l2<=b)
  {
    addsolut();
    return;
  }
  if (i==(n)) return;
  if (l1>a)
    return;
  get(i+1);
  l1+=w[i];l2-=w[i];c1++;c2--;
  get(i+1);
  l1-=w[i];l2+=w[i];c1--;c2++;
}

int main(int argc, char* argv[])
{
  int i, j;
  #ifndef _DEBUG
  freopen("kitchen.in", "r", stdio);
  freopen("kitchen.out","w",stdout);
  #endif
for (int I=0; I<25; I++)
{
  ans.rav(0);
  scanf("%d %d %d", &a, &b, &n);
  for (i=0; i<n; i++)
    scanf("%d", &w[i]);
  for (i=j=0; i<n && j+w[i]<=a+b; i++)
    j+=w[i];
  if (i<n) goto END;
  l2=j;
  c2=n;
  get(0);


  //2) vibrat 2 esli mogno
  //3) count+=col1! * col2!
  //
END:
  printf("\n");
  ans.print();
}
  #ifdef _DEBUG
  getch();
  #endif

  return 0;
}
//---------------------------------------------------------------------------


void LONG::mult(int x)
{
  int i;
  LONG p;
  p.rav(0);
  for (i=1; i<=val[0] || val[i+1]!=0; i++)
  {
    p.val[i]+=val[i]*x;
    p.val[i+1]+=p.val[i]/BASE;
    p.val[i]%=BASE;
  }
  p.val[0]=i-(p.val[i]==0);
  for (i=0; i<=p.val[0]; i++)
    val[i]=p.val[i];
}

void LONG::rav(int x)
{
  int i;
  for (i=0; i<201; i++) val[i]=0;
  val[1]=x;
  i=1;
  do
  {
    val[i+1]=val[i]/BASE;
    val[i]%=BASE;
  }
  while (val[i+1]);
  val[0]=i;
}

void LONG::sumlong(LONG x)
{
  int i;
  LONG p;
  p.rav(0);
  for (i=1; i<=max(val[0],x.val[0]) || p.val[i+1]!=0; i++)
  {
    p.val[i]+=this->val[i]+x.val[i];
    p.val[i+1]+=p.val[i]/BASE;
    p.val[i]%=BASE;
  }
  p.val[0]=i-(p.val[i]==0);
  for (i=0; i<=p.val[0]; i++)
    val[i]=p.val[i];
}

void LONG::print()
{
  int i;
  printf("%d", val[val[0]]);
  for (i=val[0]-1; i>0; i--)
  {
    printf("%04d", val[i]);
  }
}
