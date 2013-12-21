#include <stdio.h>
#include <math.h>

#ifdef _DEBUG
#include <conio.h>
#endif

int N, K;
int left;
float A, pA;
bool w[20];
float a[20];

bool solv(int p)
{
  //if (left>N-p) return false;
  if (p==N || left==0)
    return ( fabs(pA/(N-K-2)-A)<=0.0059) && left==0;
  if (solv(p+1)) return true;

  if (!w[p])
  {
    w[p]=true;  pA+=a[p]; left--;
    if (solv(p+1)) return true;
    w[p]=false; pA-=a[p]; left++;
  }
  return false;
}

int main()
{
   int i, j;
   int mi=0, Mi=0;
   #ifndef _DEBUG
   freopen("figure.in", "r", stdin);
   freopen("figure.out", "w", stdout);
   #endif
   scanf("%d %d", &N, &K);
   for (i=0; i<N; i++)
   {
     scanf("%f", &a[i]);
     w[i]=false;
     if (a[i]>a[Mi])
       Mi=i;
     if (a[i]<=a[mi] && i!=Mi)
       mi=i;
   }
   w[mi]=w[Mi]=true;
   scanf("%f", &A);
   left=N-K-2;
   pA=0;
   solv(0);
   for (i=0; i<N; i++)
     if (!w[i] || i==Mi || i==mi)
       printf("%.2f ", a[i]);
   #ifdef _DEBUG
   getch();
   #endif
   return 0;
}



