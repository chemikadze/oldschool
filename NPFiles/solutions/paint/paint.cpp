//---------------------------------------------------------------------------

#include <stdio.h>

#ifdef _DEBUG
#include <conio.h>
#endif

//---------------------------------------------------------------------------

int N;
int a[10001];
int m=1;
int simp[10001], sc=0;

bool simple(int a)
{
  int i;
  for (i=2; i<=a/2; i++)
    if (!(a%i))
      return 0;
  return 1;
}

int main(int argc, char* argv[])
{
  int i, j=0;
  int n;
  #ifndef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &N);
  for (i=2; i<=N; i++)
    if (simple(i))
      simp[sc++]=i;
  for (i=2; i<=N; i++)
  {
    n=i;
    for (j=0; j<sc && simp[j]<=i; j++)
    {
      while (!(n%simp[j]))
      {
        n/=simp[j];
        a[i]++;
      }
    }
    if (a[i]+1>m)
      m=a[i]+1;
  }
  printf("%d\n", m);
  for (i=1; i<=N; i++)
    printf("%d ", a[i]+1);
  #ifdef _DEBUG
  getch();
  #endif  
  return 0;
}
//---------------------------------------------------------------------------
