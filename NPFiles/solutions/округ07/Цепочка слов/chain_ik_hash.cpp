#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>

#define TASKNAME "chain"

using namespace std;
typedef pair <int, int> tuple;
typedef map <tuple, bool> hash;

const int MaxN = 250007;

string s [MaxN];
int x [MaxN];

int main (void)
{
 hash f;
 char buf [MaxN];
 int i, k, n, max, cur, r;
 unsigned int m;
 freopen (TASKNAME ".in", "rt", stdin);
 freopen (TASKNAME ".out", "wt", stdout);
 while (scanf (" %d", &n) != EOF)
 {
  for (i = 0; i < n; i++)
  {
   scanf (" %s", buf);
   s[i] = buf;
  }
  scanf (" %d", &k);
  for (i = 0; i < k; i++)
  {
   scanf (" %d", &x[i]);
   x[i]--;
  }

  max = 0;
  cur = 0;
  r = 0;
  for (i = 1; i < k; i++)
  {
   string & p = s[x[i - 1]];
   string & q = s[x[i]];
   tuple temp (x[i - 1], x[i]);
   hash::iterator t;
   t = f.find (temp);
   if (t != f.end ())
   {
    m = (*t).second ? p.size () : 0;
   }
   else
   {
    m = 0;
    if (p.size () < q.size ())
     for ( ; m < p.size (); m++)
      if (p[m] != q[m])
       break;
    f.insert (make_pair (temp, m == p.size ()));
   }
   if (m == p.size ())
   {
    cur++;
    if (max < cur)
    {
     max = cur;
     r = i;
    }
   }
   else cur = 0;
  }
  r++;
  printf ("%d %d\n", r - max, r);
 }
 return 0;
}
