//---------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------

int N, K, S;
int a[30000];

int main(int argc, char* argv[])
{
  char si[4];
  int i, j, n, s;
  int bank=0, win1;
  freopen("poker.in", "r", stdin);
  freopen("poker.out", "w", stdout);
  scanf("%d %d %d", &N, &K, &S);
  while (1)
  {
    scanf("%s", &si);
    if (si[0]=='E') break;
    if (si[0]=='W')
    {
      scanf("%d", &n);
      n--;
      win1=bank/K;
      a[n]+=bank%K;
      for (j=n; j<K+n; j++)
        a[j%N]+=win1;
      bank=0;
    }
    else
    {
      scanf("%d %d", &n, &s);
      n--;
      a[n]-=s;
      bank+=s;
    }
  }
  for (i=0; i<N; i++)
    printf("%d ", a[i]+S);
  return 0;
}
//---------------------------------------------------------------------------
 