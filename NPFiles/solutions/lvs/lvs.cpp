//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#define max(X, Y) ((X>Y) ? (X) : (Y))

//---------------------------------------------------------------------------

int N;
int a[1001];
int b[1001];
int ans[1001][1001];

int cmp(const void* a, const void* b)
{
  return *((int*)a)-*((int*)b);
}

int main(int argc, char* argv[])
{
  int i, j;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
  {
    scanf("%d", &a[i]);
    b[i]=a[i];
  }
  qsort(b+1, N, sizeof(b[0]), cmp);
  for (i=1; i<=N; i++)
    for (j=1; j<=N; j++)
    {
      if (a[i]==b[j])
        ans[i][j]=ans[i-1][j-1]+1;
      else
        ans[i][j]=max(ans[i][j-1], ans[i-1][j]);
    }
  printf("%d", ans[N][N]);
  #ifdef _DEBUG
  getch();
  #endif  
  return 0;
}
//---------------------------------------------------------------------------
 