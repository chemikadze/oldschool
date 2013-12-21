/*
 Solution by recursion, multiplying by factorials at the end.
 Estimated score: 55.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "kitchen"

const int MaxK = 103;
typedef long long int64;

int64 f [MaxK + 1];
int w [MaxK];
int l, m, n;

void recur (int a, int b, int c, int k)
{
 if (k == n)
 {
  f[c]++;
  return;
 }
 if (a + w[k] <= l)
  recur (a + w[k], b, c + 1, k + 1);
 if (b + w[k] <= m)
  recur (a, b + w[k], c, k + 1);
}

int main (void)
{
 int i, k;
 int64 res;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d %d", &l, &m, &n) != EOF)
 {
  for (i = 0; i < n; i++)
   scanf (" %d", &w[i]);
  memset (f, 0, sizeof (f));
  recur (0, 0, 0, 0);
  res = 0;
  for (k = 0; k <= n; k++)
  {
   for (i = 2; i <= k; i++)
    f[k] *= i;
   for (i = 2; i <= n - k; i++)
    f[k] *= i;
   res += f[k];
  }
  printf ("%I64d\n", res);
 }
 return 0;
}
