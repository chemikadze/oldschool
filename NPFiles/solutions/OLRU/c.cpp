//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//#define DEBUG

#ifndef DEBUG
#define FILES
#endif

//---------------------------------------------------------------------------
int N;
int A[1000];

void qsort(int l,int r)
{
  int i=l,j=r;
  int m=A[l+rand()%(r-l)];
  do
  {
    while (A[i]>m) i++;
    while (A[j]<m) j--;
    if (i<=j)
      swap(A[i++],A[j--]);
  }
  while (i<=j);
  if (i<r) qsort(i,r);
  if (l<j) qsort(l,j);
}

int main(int argc, char* argv[])
{
  int i;
  int res=0;
#ifdef FILES
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
#endif
  scanf("%d",&N);
  for (i=0;i<N;i++)
    scanf("%d",&A[i]);
  if (N>1)
    qsort(0,N-1);
  for (i=0;i<N;i++)
    if ((i+1)%3)
      res+=A[i];
  printf("%d",res);
#ifndef FILES
  scanf("%*s");
#endif
  return 0;
}
//---------------------------------------------------------------------------

