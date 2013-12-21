//---------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>

#ifdef _DEBUG
#include <conio.h>
#endif

#define MP 6

//---------------------------------------------------------------------------

int N;
long double simps[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int pows[7];
bool woz[8];
int cnt=0;

bool gen(int k)
{
  int i;
  if (k==(MP-MP/2))
  {
    long double n=1;
    for (i=0; i<MP; i++)
      n*=powl(simps[i],pows[i]);
    printf("%.0Lf ", n);
    return ((++cnt)==N);
  }
  for (i=MP; i>=MP/2; i--)
    if (!woz[i])
    {
      pows[k]=i;
      woz[i]=true;
      if (gen(k+1))
        return true;
      woz[i]=false;
    }
  return false;
}

int main(int argc, char* argv[])
{
  int i=0, j=0, k, m;
  int p=1;
  long double n=2;
  long double pn=1;
  #ifndef _DEBUG
  freopen("house.in", "r", stdin);
  freopen("house.out", "w", stdout);
  #endif
  scanf("%d", &N);
  gen(0);
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
