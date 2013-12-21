#include <stdio.h>
#include <stdlib.h>

int A[10][15][15];
int R[10][15][15];

int a[5][2];
int r[5][2];

int N;

int main()
{
  int i,j,k;
  scanf("%d",&N);
  for (i=0;i<N;i++)
  {
    scanf("%d %d",&a[i][j]);
    for (j=0; j<a[i][0]; j++)
      for (k=0; k<a[i][1]; k++)
	scanf("%d",A[i][j][k]);
  }
  for (i=0;i<N;i++)
    for (j=0;j<N;j++)
      R[0][i][j]=A[0][i][j];
  r[i][j]=a[i][j];

  for (k=0; k<N-1; k++)
  {
    if (r[k][1]!=a[k+1][0])
    {
      printf("Ne opredeleno\n");
      break;
    }
    for (i=0;i<;i++)
      for (j=0;j<)

  }

}