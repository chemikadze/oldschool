//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;
int a[100][100];
int c[100];
int ans=0;

int main(int argc, char* argv[])
{
  register int i, j;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &N);
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      scanf("%d", &a[i][j]);
  for (i=0; i<N; i++)
    scanf("%d", &c[i]);
  for (i=0; i<N; i++)
    for (j=i+1; j<N; j++)
      if (a[i][j] && c[i]!=c[j])
        ans++;
  printf("%d", ans);
  return 0;
}
//---------------------------------------------------------------------------
 