//---------------------------------------------------------------------------

#include <stdio.h>

#define uint unsigned int
//---------------------------------------------------------------------------

uint N;
uint ans[32+1];

uint jump(uint n)
{
  int i;
  if (ans[n] || !n)
    return ans[n];
  for (i=1; i<=3 && i<=n; i++)
    ans[n]+=jump(n-i);
  return ans[n];  
}

int main(int argc, char* argv[])
{
  ans[0]=1;
  scanf("%d",&N);
  printf("%d",jump(N));
  #ifdef _DEBUG
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 