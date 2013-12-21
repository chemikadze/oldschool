//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int lines[10000][3];
int A,B,C;
int N;

int main(int argc, char* argv[])
{
  int i,j,k;
  float x,y;

  freopen("f.in","r",stdin);
  freopen("f.out","w",stdout);

  scanf("%d",&N);
  for (i=0; i<N; i++)
    scanf("%d %d %d",&lines[i][0],&lines[i][1],&lines[i][2]);

  for (i=lines[0][0]; i<=lines[0][1]; i++)
    for (j=lines[N-1][0]; j<=lines[N-1][1]; j++)
    {
      A=lines[N-1][2]-lines[0][2];
      B=i-j;
      C=-A*i-B*lines[0][2];
      for (k=1; k<N-1; k++)
      {
	y=lines[k][2];
	x=-((float)(B*y+C))/A;
	if (x<lines[k][0] || x>lines[k][1])
	  goto NO_ANS;
      }
      printf("%d %d %d",A,B,C);
      return 0;
    NO_ANS:;
    }
  printf("No solution");
  return 0;
}
//---------------------------------------------------------------------------
