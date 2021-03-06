/*
 Dumb solution; works in n*n/k. Forward greed.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "fence"
typedef long long int64;

const int MaxN = 60000005, MaxP = 52;

bool a [MaxN];
int b [MaxP], e [MaxP];
int64 res;
int k, m, n;

int main (void)
{
 int i, pos, left, sum;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d", &n, &k) != EOF)
 {
  scanf (" %d", &m);
  for (i = 0; i < m; i++)
   scanf (" %d %d", &b[i], &e[i]);

  memset (a, 0, sizeof (a));
  sum = 0;
  for (i = 0; i < m; i++)
   for (pos = b[i]; pos <= e[i]; pos++)
   {
    assert (!a[pos]);
    a[pos] = true;
    sum++;
   }

  pos = 0;
  left = k;
  res = 0;
  assert (sum);
  while (1)
  {
   if (a[pos])
   {
    a[pos] = false;
    sum--;
    if (sum == 0) break;
    left--;
    if (!left)
    {
     left = k;
     res += pos;
     pos = 0;
    }
    else pos++, res++;
   }
   else pos++, res++;
  }
  res += pos;

  printf ("%I64d\n", res);
 }
 return 0;
}
