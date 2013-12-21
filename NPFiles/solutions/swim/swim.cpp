//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

int N, K;
int v[800];
int s[800], stop=0, shead=0;
int p[800], ptop=0, phead=0;
long double ans;

inline int cmp(const void* a, const void* b)
{
  return *((int*)b)-*((int*)a);
}

int main(int argc, char* argv[])
{
  register int i, j;
  int a, b;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &N);
  for (i=0; i<N; i++)
    scanf("%d", &v[i]);
  scanf("%d", &K);
  for (i=0; i<K; i++)
  {
    scanf("%d %d", &a, &b);
    if (a==1)
      s[stop++]=b;
    else
      p[ptop++]=b;
  }
  qsort(v, N,    sizeof(v[0]), cmp);
  qsort(s, stop, sizeof(s[0]), cmp);
  qsort(p, ptop, sizeof(p[0]), cmp);
  if (K>N)
  {
    for (i=0; i<N; i++)
    {
      if (shead<stop && phead<ptop)
      {
        if ((long double)(v[i])*(1+(long double)(s[shead])/100) >= v[i]+p[phead])
          ans+=(long double)(v[i])*(1+(long double)(s[shead++])/100);
        else
          ans+=(long double)(v[i])+(long double)(p[phead++]);
      }
      else
      {
        if (shead<stop)
          ans+=(long double)(v[i])*(1+(long double)(s[shead++])/100);
        else
          ans+=(long double)(v[i])+(long double)(p[phead++]);
      }
    }
  }
  else
  {
    for (i=0; i<N; i++)
    {
      if (shead<stop)
        ans+=(long double)(v[i])*(1+(long double)(s[shead++])/100);
      else
        if (phead<ptop)
          ans+=(long double)(v[i])+(long double)(p[phead++]);
        else
          ans+=v[i];
    }
  }
  printf("%.5Lf", ans);
  return 0;
}
//---------------------------------------------------------------------------
 