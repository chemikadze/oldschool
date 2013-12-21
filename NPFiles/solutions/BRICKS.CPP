#include <stdio.h>
#include <conio.h>

#define MAXN 100
#define MAXM MAXN


int N, M;
int a[MAXN][MAXM];
int b[MAXN][MAXM];

int C=0;
int S;

int put(const int x, const int y)
{
  int i, j, k;
  int x2, y2;

  b[x][y]=++C;

  for (i=0; i<4; i++)
  {
    x2=x;
    y2=y;
    switch (i)
    {
      case 0:
	x2+=1;
	break;
      case 1:
	y2+=1;
	break;
      case 2:
	x2-=1;
	break;
      case 3:
	y2-=1;
    }

    if (x2>=0 && x2<N && y2>=0 && y2<M)
      if (!b[x2][y2] && a[x][y]!=a[x2][y2])
      {
	b[x2][y2]=C;
	if (C*2==S)
	  return 1;
	for (j=0; j<N; j++)
	  for (k=0; k<M; k++)
	    if (!b[j][k])
	    {
	      if (put(j, k))
		return 1;
	      goto EXIT;
	    }
       EXIT:
	b[x2][y2]=0;
      }
  }

  C--;
  b[x][y]=0;

  return 0;
}

int main()
{
  int i, j;

  printf("enter N, M:\n");
  scanf("%d %d", &N, &M);
  for (i=0; i<N; i++)
    for (j=0; j<M; j++)
      scanf("%d", &a[i][j]);
  S=N*M;
  printf("\n");

  if (put(0, 0))
  {
    printf("input:\n");
    for (i=0; i<N; i++, printf("\n"))
      for (j=0; j<M; j++)
      {
	textcolor(a[i][j]%16);
	cprintf("%2d ", a[i][j]);
      }
    printf("\n");
    printf("output:\n");
    for (i=0; i<N; i++, printf("\n"))
      for (j=0; j<M; j++)
      {
	textcolor(b[i][j]%16);
	cprintf("%2d ", b[i][j]);
      }
  }
  else
    printf("-1\n");
  getch();
  return 0;
}