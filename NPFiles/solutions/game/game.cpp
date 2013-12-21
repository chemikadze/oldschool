//---------------------------------------------------------------------------

//NOT DONE  page 12

#include <stdio.h>
#include <conio.h>
#include <algorithm>
#pragma hdrstop
using namespace std;

//---------------------------------------------------------------------------

int N;
int R=0;
int L=0;
int a[100];

#pragma argsused
int main(int argc, char* argv[])
{
  int i, j;
  int b;

  scanf("%d", &N);
  for (i=0; i<N; i++)
    scanf("%d", &a[i]);

  i=0; j=N-1;
  step();

  printf("R=%d\nL=%d\n", R, L);
  getch();
  
  return 0;
}
//---------------------------------------------------------------------------
 