#include <stdio.h>
#include <conio.h>

int N, M=0; //N - MARSH, M - VERSH
int RC=0;
char a[201][201];
int path[201];
int len=0;

void euler(int v)
{
  int i;
  for (i=1; i<=M; i++)
    if (a[v][i])
    {
      a[v][i]--;
      euler(i);

    }
  path[len++]=v;
}

int main()
{
  int i, j, k;
  int v, u;
  scanf("%d", &N);
  for (i=0; i<N; i++)
  {
    scanf("%d", &k);
    v=-1;
    for (j=0; j<k+1; j++)
    {
      scanf("%d", &u);
      if (v>0)
	//if (a[v][u])
	{
	  a[v][u]++;
	  RC++;
	}
      if (u>M) M=u;
      v=u;
    }
  }
  euler(1);
  if (len<RC)
    printf("0");
  else
  {
    printf("%d ", len-1);
    while (len>0)
      printf("%d ", path[--len]);
  }
  printf("\n");
  getch();
  return 0;
}