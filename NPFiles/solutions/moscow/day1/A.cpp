//---------------------------------------------------------------------------

#include <stdio.h>

#define uint unsigned int

//---------------------------------------------------------------------------

uint N;
uint F[45];

uint f(uint x)
{
  if (F[x-1])
    return F[x-1];
  if (x<=2)
    return F[x-1]=1;
  else
    return F[x-1]=(f(x-1)+f(x-2));
}

int main(int argc, char* argv[])
{
  scanf("%d",&N);
  printf("%d",f(N));
  #ifdef _DEBUG
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 