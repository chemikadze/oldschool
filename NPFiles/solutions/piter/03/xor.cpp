//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#define us unsigned

int A;
int N;

int a[32];

#pragma argsused
int main(int argc, char* argv[])
{
  int i,j,k;
  int n;
  us pw2=1;

  #ifndef _DEBUG
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  #endif
  scanf("%d %d",&N,&A);
  if (N==1)
  {
    printf("%d",A);
    goto EXIT;
  }

  n=N;
  for (i=0;i<32 && n>0;i++)
  {
    if ( pw2&A )
    {
      if (!(n%2) || i!=0) n-=n%2+1;
      for (j=0; j<n; j++)
        a[j]+=pw2;
    }
    else
    {
      if (n%2 || i!=0) n-=2-n%2;
      for (j=0; j<n; j++)
        a[j]+=pw2;
    }
    pw2*=2;
  }

  //pw2/=2;
  j=0;
  k=N-1;
  do
  {
    while (j<=N/2 && a[j]!=a[j+1]) j++;
    while (k>=N/2 && a[k]!=a[k-1]) k--;
    if (j>=k)
      break;
    if (a[j]!=a[k])
    {
      a[j]+=pw2;
      a[k]+=pw2;
      pw2*=2;
    }
    else
    {
      int jj=0,kk=N-1;
      while (jj<=N/2 && a[jj]==a[k]) jj++;
      while (kk<=N/2 && a[kk]==a[j]) kk--;
      a[j]+=pw2;
      a[jj]+=pw2;
      a[k]+=pw2*2;
      a[kk]+=pw2*2;
    }
  }
  while (j<k);

  for (i=N-1;i>=0;i--)
    printf( "%d ", a[i] );
EXIT:
  #ifdef _DEBUG
  scanf("%*s");
  #endif

  return 0;
}
//---------------------------------------------------------------------------
