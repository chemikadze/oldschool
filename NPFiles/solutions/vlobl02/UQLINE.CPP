#include <stdio.h>
#include <conio.h>

int N;
int a[100][100];
int path[100];
int length;
int maxlen;

int euler(int u)
{
  int i;
  path[length++]=u;
  if (!a[u][0])
  {
    if ((length-1)*2==maxlen)
      return 1;
    else
    {
      length--;
      return 0;
    }
  }
  for (i=1; i<=N; i++)
    if (a[u][i])
    {
      a[u][i]=a[i][u]=0;
      a[u][0]--;
      if (euler(i))
	return 1;
      a[u][0]++;
      a[u][i]=a[i][u]=1;
    }
 length--;
 return 0;
}

int main()
{
  int i, j;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
    for (j=1; j<=N; j++)
    {
      scanf("%d", &a[i][j]);
      if (a[i][j])
      {
	maxlen++;
	a[i][0]++;
      }
    }
  for (i=1; i<=N; i++)
    if (a[i][0]%2)
      break;
  if (i>N)
    i=1;
  euler(i);
  if (length<(maxlen/2))
    printf("NO\n");
  else
  {
    printf("YES\n");
    while (length>0)
      printf("%d ", path[--length]);
  }
  getch();
  return 0;
}