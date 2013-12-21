//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

//---------------------------------------------------------------------------

int N, M;
int a[10][10];

int main(int argc, char* argv[])
{
  int i, j;
  scanf("%d %d", &N, &M);
  for (i=0; i<N; i++)
    a[i][0]=1;
  for (j=0; j<M; j++)
    a[0][j]=1;
  for (i=1; i<N; i++)
    for (j=1; j<M; j++)
      a[i][j]=a[i][j-1]+a[i-1][j];
  printf("%d", a[N-1][M-1]);
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
