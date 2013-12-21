/*
 Dynamic programming solution using bignum base 10^6.
 Estimated score: 100.
*/
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TASKNAME "kitchen"

const int MaxN = 302, MaxK = 103, MaxD = 45, Base = 1000000, LogBase = 6;
typedef int bignum [MaxD + 1];

bignum f [MaxN] [MaxK + 1];
int w [MaxK];

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

int main (void)
{
 int i, j, k, l, m, n, p, s;
 bignum res;
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
  memset (f, 0, sizeof (f));
  f[0][0][0] = f[0][0][1] = 1;
  for (i = 1; i <= n; i++)
  {
   p = w[i - 1];
   for (j = l; j >= p; j--)
    for (k = i; k >= 1; k--)
     add (f[j][k], f[j][k], f[j - p][k - 1]);
  }
  memset (res, 0, sizeof (res));
  for (j = (s - m > 0) ? s - m : 0; j <= l; j++)
   for (k = 0; k <= n; k++)
   {
    for (i = 2; i <= k; i++)
     multc (f[j][k], f[j][k], i);
    for (i = 2; i <= n - k; i++)
     multc (f[j][k], f[j][k], i);
    add (res, res, f[j][k]);
   }
  outbln (res);
 }
 return 0;
}
