/*
 Solution by recursion, multiplying by factorials and using bignum at the end.
 Estimated score: 70.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "kitchen"

const int MaxK = 103, MaxD = 45, Base = 1000000, LogBase = 6;
typedef int bignum [MaxD + 1];

int f [MaxK + 1];
int w [MaxK];
int l, m, n;

void add (bignum & a, const bignum & b, const bignum & c)
{
 int i, l, p;
 l = (b[0] > c[0]) ? b[0] : c[0];
 p = 0;
 for (i = 1; i <= l; i++)
 {
  p += b[i] + c[i];
  if (p >= Base) a[i] = p - Base, p = 1;
            else a[i] = p, p = 0;
 }
 if (p) a[++l] = 1;
 a[0] = l;
}

void multc (bignum & a, const bignum & b, const int c)
{
 int i, p;
 p = 0;
 for (i = 1; i <= b[0]; i++)
 {
  p += b[i] * c;
  a[i] = p % Base;
  p /= Base;
 }
 while (p)
 {
  a[i++] = p % Base;
  p /= Base;
 }
 a[0] = i - 1;
}

void outbln (const bignum & a)
{
 int i;
 printf ("%d", a[a[0]]);
 for (i = a[0] - 1; i >= 1; i--)
  printf ("%0*d", LogBase, a[i]);
 printf ("\n");
}

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
 bignum res, cur;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d %d %d", &l, &m, &n) != EOF)
 {
  for (i = 0; i < n; i++)
   scanf (" %d", &w[i]);
  memset (f, 0, sizeof (f));
  recur (0, 0, 0, 0);
  memset (res, 0, sizeof (res));
  for (k = 0; k <= n; k++)
  {
   memset (cur, 0, sizeof (cur));
   cur[0] = 1;
   cur[1] = f[k];
   for (i = 2; i <= k; i++)
    multc (cur, cur, i);
   for (i = 2; i <= n - k; i++)
    multc (cur, cur, i);
   add (res, res, cur);
  }
  outbln (res);
 }
 return 0;
}
