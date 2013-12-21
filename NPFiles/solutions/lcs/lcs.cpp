//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif

#define max(X, Y) ((X>Y) ? (X) : (Y))

//---------------------------------------------------------------------------

int N;
int M;
int a[1001];
int b[1001];
int ans[1001][1001];

int main(int argc, char* argv[])
{
  int i, j;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
    scanf("%d", &a[i]);
  scanf("%d", &M);  
  for (i=1; i<=M; i++)
    scanf("%d", &b[i]);
  for (i=1; i<=N; i++)
    for (j=1; j<=M; j++)
    {
      if (a[i]==b[j])
        ans[i][j]=ans[i-1][j-1]+1;
      else
        ans[i][j]=max(ans[i][j-1], ans[i-1][j]);
    }
  printf("%d", ans[N][M]);
  #ifdef _DEBUG
  getch();
  #endif  
  return 0;
}
//---------------------------------------------------------------------------
