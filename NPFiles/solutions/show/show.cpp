//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#pragma hdrstop

#define MAXM 1000000000

//---------------------------------------------------------------------------

int N;

#pragma argsused
int main(int argc, char* argv[])
{
  long i, j, d;

  scanf("%d",&N);

  for (i=N; i<=MAXM; i++)
  {
    for (d=1, j=1; j<=i/2 && d<=N; j++)
      if (!(i%j))
        d++;
    if (d==N)
      break;
  }

  if (i>MAXM)
    i=0;

  printf("%d",i);
  getch();  

  return 0;
}
//---------------------------------------------------------------------------
