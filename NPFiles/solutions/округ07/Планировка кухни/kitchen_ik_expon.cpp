/*
 Trivial solution by recursion.
 Estimated score: 25.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "kitchen"

const int MaxK = 103;

int u [MaxK];
int w [MaxK];
int l, m, n;

int recur2 (int a, int b, int k)
{
 int i, res;
 if (k == n) return 1;
 res = 0;
 for (i = 0; i < n; i++) if (!u[i])
  if (b + w[i] <= m)
  {
   u[i] = 2;
   res += recur2 (a, b + w[i], k + 1);
   u[i] = 0;
  }
 return res;
}

int recur (int a, int b, int k)
{
 int i, res;
 if (k == n) return 1;
 res = recur2 (a, b, k);
 for (i = 0; i < n; i++) if (!u[i])
  if (a + w[i] <= l)
  {
   u[i] = 1;
   res += recur (a + w[i], b, k + 1);
   u[i] = 0;
  }
 return res;
}

int main (void)
{
 int i, res;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d %d", &l, &m, &n) != EOF)
 {
  for (i = 0; i < n; i++)
   scanf (" %d", &w[i]);
  res = recur (0, 0, 0);
  printf ("%d\n", res);
 }
 return 0;
}
