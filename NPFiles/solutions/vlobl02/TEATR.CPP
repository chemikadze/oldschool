#include <stdio.h>
#include <conio.h>

int N;
int a[30001];
int man;
int ans=0;

void sit(int i)
{
  int b;
  if (a[i]==0 || a[i]==i)
    return;
  b=a[i];
  a[i]=0;
  sit(b);
  ans++;
}

int main()
{
  int i;
  int b;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
    scanf("%d", &a[i]);
  scanf("%d", &man);
  for (i=1; i<=N; i++)
    if (a[i]==man)
    {
      man=i;break;
    }
  sit(man);
  printf("%d\n", ans);
  getch();

  return 0;
}