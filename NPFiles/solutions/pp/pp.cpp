//---------------------------------------------------------------------------

#include <stdio.h>
#ifdef _DEBUG
#include <conio.h>
#endif
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------


int N, K;
char s[5001];
int C[5001][5001];
int ans=0;

int main(int argc, char* argv[])
{
  int i, j;
  scanf("%d %d", &N, &K);
  scanf("%s", &s);
  for (i=0; i<=N; i++)
    C[i][0]=1;
  for (i=1; i<=N; i++)
    for (j=1; j<=min(N, K*2+1); j++)
      C[i][j]=C[i-1][j-1]+C[i-1][j];
  ans+=C[N][min(N, K*2+1)];
  for (i=0; i<N; i++)
  {

  }
  #ifdef _DEBUG
  printf("> ");
  #endif
  printf("%d", ans);
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
//---------------------------------------------------------------------------
