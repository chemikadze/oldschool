//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using std::max;
using std::min;

//---------------------------------------------------------------------------

int N;
int l[101];
int a[101][101];

int main(int argc, char* argv[])
{
  register int i, j, k;
  scanf("%d", &N);
  for (i=j=1, k=0; j<=N; i++)
    for (k+=i; j<=k; j++)
      l[j]=i;

  a[0][0]=1;
  a[1][1]=a[1][0]=1;
  a[2][2]=a[2][0]=1;

  for (i=3; i<=N; i++)
    for (j=l[i]; j<=i; j++)
      if ((i-j)>=j)
        for (k=l[i-j]; k<=i-j && k<j; k++)
        {
          a[i][j]+=a[i-j][k];
          a[i][0]+=a[i-j][k];
        }
      else
      {
        a[i][j]+=a[i-j][0];
        a[i][0]+=a[i-j][0];
      }
  printf("%d", a[N][0]);
  #ifdef _DEBUG
  while (fgetc(stdin)!='\n');fgetc(stdin);
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 