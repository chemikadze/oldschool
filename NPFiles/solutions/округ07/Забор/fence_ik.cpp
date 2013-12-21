/*
 Fast solution; works in O (m) time. Backward greed.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "fence"
typedef long long int64;

const int MaxP = 52;

int b [MaxP], e [MaxP];
int k, m, n;

int main (void)
{
 int i, j, cur, pos, left, len, num;
 int64 res, sum;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d", &n, &k) != EOF)
 {
  scanf (" %d", &m);
  for (i = 0; i < m; i++)
   scanf (" %d %d", &b[i], &e[i]);

  for (i = 0; i < m - 1; i++)
   for (j = i + 1; j < m; j++)
    if (b[i] < b[j])
    {
     b[i] ^= b[j] ^= b[i] ^= b[j];
     e[i] ^= e[j] ^= e[i] ^= e[j];
    }

  assert (m > 0);
  res = 0;
  cur = 0;
  left = k;
  for (cur = 0; cur < m; cur++)
  {
   if (left == k) res += e[cur] << 1;
   len = e[cur] - b[cur] + 1;
   if (len < left)
   {
    left -= len;
    continue;
   }

   assert (left > 0);
   pos = e[cur] - left;
   num = (pos - (b[cur] - 1)) / k;
   sum = pos + (pos - k * (num - 1));
   sum *= num;
   assert (!(sum & 1));
//   printf ("[%d %d]: %d %I64d\n", b[cur], pos, num, sum);
   res += sum;

   left = k - (pos - k * num - (b[cur] - 1));
   assert (left > 0 && left <= k);
   if (left < k) res += (pos - k * num) << 1;
  }

  printf ("%I64d\n", res);
 }
 return 0;
}
