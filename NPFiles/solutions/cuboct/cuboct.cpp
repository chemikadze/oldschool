//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

#define long_base_num_count 5
#define long_base 1000000
#define long_len  1000000

typedef long long llint;

struct s_long
{
  llint value[long_len];
  int len;
  void zero();
  void plus(llint a);
  void print();
};

typedef struct s_long t_long;

int N;
t_long ans;

void t_long::zero()
{
  register int i;
  for (i=1; i<long_len; i++) value[i]=0;
  len=1;
}

void t_long::plus(llint a)
{
  register int i;
  llint p=0;
  value[1]+=a;
  for (i=1; p; i++)
  {
    value[i]+=p;
    p=value[i]/long_base;
    value[i]%=long_base;
  }
  len=max(i-1, len);
}

void t_long::print()
{
  register int i;
  printf("%Ld", value[len]);
  for (i=len-1; i>0; i--)
    printf("%5Ld", value[i]);
}

int main(int argc, char* argv[])
{
  register llint i, j;
  freopen("cuboct.in", "r", stdin);
  freopen("cuboct.out", "w", stdout);
  scanf("%d", &N);
  ans.zero();
  for (i=0; i<N; i++)
  {
    for (j=0; j<i; j++)
    {
      ans.plus((i+1)*2);
      ans.plus((i+1)*2);
    }
    ans.plus(2);
  }
  for (j=0; j<N; j++)
    ans.plus((N+1)*2);
  ans.plus(1);
  ans.print();
  return 0;
}
//---------------------------------------------------------------------------
