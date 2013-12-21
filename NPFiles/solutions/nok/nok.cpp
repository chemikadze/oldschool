//---------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#pragma hdrstop

#define LEN 1000

//---------------------------------------------------------------------------

int N;
int n[1002];
int p[1002];
int ANS[LEN];

int power(const int b, int p)
{
  int ans=1;
  while (p-->0)
    ans*=b;
  return ans;
}

int simple(int k)                                                               
{
  int i;
  for (i=2; i<=k/2; i++)
    if (!(k%i))
      return 0;
  return 1;
}

void mult(int* &a,int b)
{
  int i;
  int buf[LEN];

  for (i=0; i<LEN; i++) { buf[i]=a[i]; a[i]=0; }

  for (i=1; i<=buf[0]; i++)
  {
    a[i]+=buf[i]*b;
    a[i+1]+=a[i]/10;
    a[i]%=10;
  }
  if (!(a[i])) i--;

  while (a[i++]>10)
  {
    a[i]+=a[i-1]/10;
    a[i-1]%=10;
  }
  a[0]=i-1;
}

void print(int* a)
{
  int i;

  for (i=a[0]; i>0; i--)
    printf("%d",a[i]);
}

#pragma argsused
int main(int argc, char* argv[])
{
  int i, j;
  int pwr;
  ANS[0]=ANS[i]=1;

  scanf("%d",&N);
  for (i=1; i<=N; i++)
    n[i]=i;

  for (i=2; i<=N; i++)   //power base
    if (simple(i))
      for (j=i; j<=N; j++) //number
      {
        pwr=0;
        while (!(n[j]%i))
        {
          n[j]/=i;
          pwr++;
        }
        if (pwr>p[i])
          p[i]=pwr;
      }
  for (i=2; i<=N; i++)
    mult(ANS,power(i,p[i]));

  print(ANS);
  getch();

  return 0;
}
//---------------------------------------------------------------------------
