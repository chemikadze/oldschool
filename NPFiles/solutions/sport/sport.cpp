//---------------------------------------------------------------------------

#include <stdio.h>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------------

int N, p, k;
int a[100001];
char ans[100001];

int main(int argc, char* argv[])
{
  register bool set;
  register int i, j;
  #ifdef _DEBUG
  freopen("sport.in", "r", stdin);
  freopen("sport.out", "w", stdout);
  #endif
  scanf("%d %d %d", &N, &p, &k);
  for (i=1; i<=N; i++)
    scanf("%d", &a[i]);
  for (i=0; i<N-1; i++)
  {
    set=false;
    for (j=1; j<=N-1; j++)
    {
      
      if (j!=p && j+1!=p)
      {
        if (a[j]>a[j+1])
          swap(a[j], a[j+1]);
      }
      else
      {
        if (j+1==p)
        {
          if (a[j]>a[j+1])
          {
            swap(a[j], a[j+1]);
            p=j;
          }
        }
        else
        {
          if (a[j]>a[j+1])
          {
            if (k>0)
            {
              k--;
              set=true;
            }
            else
            {
              swap(a[j], a[j+1]);
              p=j+1;
            }
          }
        }
      }
    }
    ans[i]=set ? '+' : '-';
  }
  ans[i]='\0';
  printf("%d\n%s", p, ans);
  return 0;
}
//---------------------------------------------------------------------------
