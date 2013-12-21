//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

int N;
int a[501][501];
int s[501];
bool can=true;
int rebc;

int main(int argc, char* argv[])
{
  register int i, j;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &N);
  for (i=0; i<N; i++)

    scanf("%d", &s[i]);
  rebc=0;
  for (i=0; i<N && can; i++)
  {
    for (j=0; j<N && s[i]>0; j++)
      if (!a[i][j] && s[i]>0 && s[j]>0 && i!=j)
      {
        a[i][j]=a[j][i]=1;
        s[i]--;
        s[j]--;
        rebc++;
      }
    if (s[i]>0)
      can=false;
  }
  if (can)
  {
    printf("Yes\n");
    printf("%d\n", rebc);
    for (i=0; i<N; i++)
      for (j=i+1; j<N; j++)
        if (a[i][j] || a[j][i])
          printf("%d %d\n", i+1, j+1);
  }
  else
    printf("No\n");
  return 0;
}
//---------------------------------------------------------------------------
