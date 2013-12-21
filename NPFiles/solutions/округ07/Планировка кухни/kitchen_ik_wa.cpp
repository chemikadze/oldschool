/*
 A solution that is trivially wrong.
 Estimated score: 10.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "kitchen"

const int MaxN = 302, MaxK = 103;
typedef long long int64;

int64 f [2] [MaxN] [MaxN];
int w [MaxK];

int main (void)
{
 int i, j, k, l, m, n, p, b;
 int64 res;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d %d", &l, &m, &n) != EOF)
 {
  for (i = 0; i < n; i++)
   scanf (" %d", &w[i]);
  b = 0;
  memset (f[b], 0, sizeof (f[b]));
  f[b][0][0] = 1;
  for (i = 0; i < n; i++)
  {
   b = !b;
   memset (f[b], 0, sizeof (f[b]));
   p = w[i];
   for (j = p; j <= l; j++)
    for (k = 0; k <= m; k++)
     f[b][j][k] += f[!b][j - p][k];
   for (j = 0; j <= l; j++)
    for (k = p; k <= m; k++)
     f[b][j][k] += f[!b][j][k - p];
/*
   printf ("After step %d:\n", i);
   for (j = 0; j <= l; j++)
    for (k = 0; k <= m; k++)
     printf ("%I64d%c", f[b][j][k], k < m ? ' ' : '\n');
*/
  }
  res = 0;
  for (j = 0; j <= l; j++)
   for (k = 0; k <= m; k++)
    res += f[b][j][k];
  printf ("%I64d\n", res);
 }
 return 0;
}
