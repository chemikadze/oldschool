#include <stdio.h>
#include <conio.h>

int N, m=0;
int a[101][101];
int p[100];
int top=0;


void euler(int u)
{
  int i;
  for (i=1; i<=N; i++)
  if (a[u][i])
    {
      a[u][i]=a[i][u]=0;
      euler(i);
      break;
    }
  p[top++]=u;
}

int main()
{
  int i, j;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
    for (j=1; j<=N; j++)
    {
      scanf("%d",&a[i][j]);
      if (a[i][j])
      {
	a[i][0]++;
	m++;
      }
    }
  for (i=1; i<=N; i++)
    if (a[i][0]%2)
      break;
  if (i>N) i=1;
  euler(i);
  if ((top-1)!=(m/2))
    printf("NO");
  else
  {
    printf("YES\n%d\n", top);
    while (top-->0)
      printf("%d ", p[top]);
  }
  printf("\n\n");
  getch();
  return 0;

}