//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;
char a[1001];
char cnt[1001];
long double s[1001][101];

int main(int argc, char* argv[])
{
  int i, j, k;
  double m, p;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
    scanf("%d", &a[i]);
  for (i=0; i<=a[0]; i++)
    s[1][i]=0;
  for (i=2; i<=N; i++)
    for (j=1; j<=a[i]; j++)
    {
      m=-1;
      for (k=1; k<=a[i-1]; k++)
      {
        p=s[i-1][k]+(long double)(j)/(long double)(k);
        if (p>m)
        {
          m=p;
          cnt[i]=j;
          cnt[i-1]=k;
        }
      }
      s[i][j]=m;
    }
  printf("%Lf\n", s[N][cnt[N]]);
  for (i=1; i<=N; i++)
    printf("%d ", cnt[i]);
  return 0;
}
//---------------------------------------------------------------------------
 