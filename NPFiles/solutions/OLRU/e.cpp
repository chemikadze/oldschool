//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

#define FILES

//---------------------------------------------------------------------------

int N;
int M;
char A[1000][1000];
char ans[1000][1000];

// 1 >
// 2 ^
// 3 <
// 4 v

char solve(int i,int j)
{
  if (!ans[i][j])
  {
    ans[i][j]=-1;
    switch (A[i][j])
    {
      case 1: if (j<M-1)
                return ans[i][j]=solve(i,j+1);
              else
                return ans[i][j]=1;

      case 2: if (i>0)
                return ans[i][j]=solve(i-1,j);
              else
                return ans[i][j]=1;

      case 3: if (j>0)
                return ans[i][j]=solve(i,j-1);
              else
                return ans[i][j]=1;

      case 4: if (i<N-1)
                return ans[i][j]=solve(i+1,j);
              else
                return ans[i][j]=1;
    }
  }
  else
    return ans[i][j];
  return 10;
}

#pragma argsused
int main(int argc, char* argv[])
{
  int i,j;
  int res=0;
  #ifdef FILES
  freopen("e.in","r",stdin);
  freopen("e.out","w",stdout);
  #endif
  scanf("%d %d",&N,&M);
  for (i=0;i<N;i++)
    for (j=0;j<M;j++)
      scanf("%d",&A[i][j]);
  for (i=0;i<N;i++)
    for (j=0;j<M;j++)
        if (solve(i,j)<0)
          res++;
  printf("%d",res);
  #ifndef FILES
  scanf("%*s");
  #endif       
  return 0;
}
//---------------------------------------------------------------------------
 