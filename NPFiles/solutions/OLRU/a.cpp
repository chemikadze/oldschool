//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

//#define DEBUG

#ifndef DEBUG
#define FILES
#endif

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  int i;
#ifdef FILES
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
#endif
  scanf("%d",&i);
  printf("%d %d",i,(i-1)*2+1);
#ifndef FILES
  scanf("%*s");
#endif
  return 0;
}
//---------------------------------------------------------------------------
