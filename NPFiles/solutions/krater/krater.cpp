//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define sqr(X) (double(X)*double(X))

//---------------------------------------------------------------------------

struct skrat
{
  int x, y;
  int r;
  int n;
};

typedef struct skrat tkrat;

int N;
tkrat* krat[501];
int a[501][501];
int p[501];
int prev[501];
bool w[501];
/*
int cmp(const void* a, const void* b)
{
  return ((tkrat*)a)->r-((tkrat*)b)->r;
}
*/
int printpath(int i)
{
  printf("%d ", krat[i]->n);
  if (prev[i])
    printpath(prev[i]);
    
}

int main(int argc, char* argv[])
{
  int i, j;
  int maxi=0;
  scanf("%d", &N);
  for (i=1; i<=N; i++)
  {
    krat[i]=new tkrat;
    scanf("%d %d %d", &krat[i]->x, &krat[i]->y, &krat[i]->r);
    krat[i]->n=i;
  }
  //qsort(krat, N, sizeof(krat[0]), cmp);
  for (i=1; i<=N; i++)
    for (j=i+1; j<=N; j++)
      if (krat[i]->r<krat[j]->r)
        swap(krat[i], krat[j]);
  for (i=1; i<=N; i++)
    for (j=1; j<=N; j++)
      if (i!=j)
        a[i][j]=(sqrt(sqr(krat[i]->x-krat[j]->x)+sqr(krat[i]->y-krat[j]->y))<=krat[i]->r-krat[j]->r);
  for (i=1; i<=N; i++)
    for (j=i+1; j<=N; j++)
      if (a[i][j] && p[j]<p[i]+1)
      {
        p[j]=p[i]+1;
        prev[j]=i;
        if (p[j]>p[maxi])
          maxi=j;
      }
  printf("%d\n", p[maxi]+1);
  printpath(maxi);
  getch();
  return 0;
}
//---------------------------------------------------------------------------
 