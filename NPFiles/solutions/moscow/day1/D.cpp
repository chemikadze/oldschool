//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N,M;
int n[1000];
int m[1000];

int maxans=0;
int ans[1000+1][1000+1];

int main(int argc, char* argv[])
{
  int i,j,k;

  scanf("%d",&N);
  for (i=0;i<N;i++)
    scanf("%d",&n[i]);
  scanf("%d",&M);
  for (i=0;i<M;i++)
    scanf("%d",&m[i]);

  for (i=N-1; i>=0; i--)
    for (j=M-1-maxans; j>=0; j--)
    {
      if (ans[i][j] || n[i]!=m[j])
        continue;
     for (k=0; i+k<N && j+k<M && n[i+k]==m[j+k] && !ans[i+k][j+k]; k++)
        continue;
      ans[i][j]=ans[i+k][j+k]+k;
      if (ans[i][j]>maxans)
        maxans=ans[i][j];
    }
  printf("%d",maxans);
  #ifdef _DEBUG
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------
 