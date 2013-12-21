/*
 Dynamic programming solution using int64.
 Estimated score: 50.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "kitchen"

const int MaxN = 302, MaxK = 103;
typedef long long int64;

int64 f [2] [MaxN] [MaxK + 1];
int w [MaxK];

int main (void)
{
 int i, j, k, l, m, n, p, b, s;
 int64 res;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d %d", &l, &m, &n) != EOF)
 {
  s = 0;
  for (i = 0; i < n; i++)
  {
   scanf (" %d", &w[i]);
   s += w[i];
  }
  b = 0;
  memset (f[b], 0, sizeof (f[b]));
  f[b][0][0] = 1;
  for (i = 1; i <= n; i++)
  {
   b = !b;
   memset (f[b], 0, sizeof (f[b]));
   p = w[i - 1];
   for (j = 0; j <= l; j++)
    for (k = 0; k <= i; k++)
     f[b][j][k] += f[!b][j][k];
   for (j = p; j <= l; j++)
    for (k = 1; k <= i; k++)
     f[b][j][k] += f[!b][j - p][k - 1];
/*
   printf ("After step %d:\n", i);
   for (j = 0; j <= l; j++)
    for (k = 0; k <= i; k++)
     printf ("%I64d%c", f[b][j][k], k < i ? ' ' : '\n');
*/
  }
  res = 0;
  for (j = 0; j <= l; j++)
   if (s - j <= m)
    for (k = 0; k <= n; k++)
    {
     for (i = 2; i <= k; i++)
      f[b][j][k] *= i;
     for (i = 2; i <= n - k; i++)
      f[b][j][k] *= i;
     res += f[b][j][k];
    }
  printf ("%I64d\n", res);
 }
 return 0;
}
