//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N;
int n[1000];

int maxans=0;
int ans[1000+1];

int main(int argc, char* argv[])
{
  int i,j,k;

  scanf("%d",&N);
  for (i=0;i<N;i++)
    scanf("%d",&n[i]);

  for (i=N-1; i>=0; i--)
  {
    for (j=0; i+j<N && n[i+j]<=n[i+j+1] && !ans[i+j] ;j++);
    ans[i]=j+ans[i+j];
    if (ans[i]>maxans)
      maxans=ans[i];
  }

  printf("%d",maxans+1);
  #ifdef _DEBUG
  scanf("%*s");
  #endif
  return 0;
}
//---------------------------------------------------------------------------

