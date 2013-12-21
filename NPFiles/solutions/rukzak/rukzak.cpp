//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

int N,W; //35, 250
int w[251];//wes
int v[251];//stoimost
int a[36][251]; // num : wes

int main(int argc, char* argv[])
{
  int i, j;

  printf("Enter W, N: \n");
  scanf("%d %d", &W, &N);
  printf("Enter w[i], v[i]: \n");
  for (i=1; i<=N; i++)
    scanf("%d %d", &w[i], &v[i]);

  for (i=0; i<=N; i++) a[i][0]=0;
  for (i=0; i<=W; i++) a[0][i]=0;
  for (j=1; j<=W; j++)
    for (i=1; i<=N; i++)
    {
      if (j>=w[i] && a[i-1][j]<a[i-1][j-w[i]]+v[i])
        a[i][j]=a[i-1][j-w[i]]+v[i];
      else
        a[i][j]=a[i-1][j];
    }

  printf("%d", a[N][W]);
  getch();

  return 0;
}
//---------------------------------------------------------------------------
