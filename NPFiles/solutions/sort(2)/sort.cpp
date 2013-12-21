//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#pragma hdrstop

using namespace std;

//---------------------------------------------------------------------------

#pragma argsused
int N;
int a[65536];

void qsort(int l, int r)
{
  int i=l, j=r;
  int m=a[ rand()%(r-l+1)+l ];

  while (i<=j)
  {
    while (a[i]<m && i<r) i++;
    while (a[j]>m && j>l) j--;

    if (i<=j)
      swap(a[i++], a[j--]);
  }

  if (j>l) qsort(l, j);
  if (r>i) qsort(i, r);
}

int main(int argc, char* argv[])
{
  int i;
  scanf("%d",&N);
  for (i=0; i<N; i++)
    scanf("%d",&a[i]);
  qsort(0,N-1);

  if (N%2)
  {
    for (i=N-1; i>=0; i--)
      if ( (i>0) ? (a[i]!=a[i-1]) : (1) )
        printf("%d ", a[i]);
  }
  else
  {
    for (i=0; i<N; i++)
      if ( (i>0) ? (a[i]!=a[i-1]) : (1) )
        printf("%d ", a[i]);
  }
  getch();

  return 0;
}
//---------------------------------------------------------------------------
 