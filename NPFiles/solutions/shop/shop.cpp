//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

FILE *in=fopen("shop.in","r");
FILE *out=fopen("shop.out","w");

int a[1000];
int N;
int M;

int cmp(const void* a,const void* b)
{return *((int*)a)-*((int*)b);
}

int main(int argc, char* argv[])
{
  int i,j;
  int b=M;
  int r=0;
  fscanf(in,"%d %d",&M,&N);
  for (i=0;i<N;i++)
    fscanf(in,"%d",&a[i]);
  qsort((void*)a,N,sizeof(int),cmp);
  i=0;
  while (a[i]<M && i<=N)
    i++;
  b=a[i];
  while (i<=N)
  {
    if (i<N)
    {
      r++;
      b=a[i];
    }
    while (a[i]-b<3 && i<=N)
      i++;
  }
  fprintf(out,"%d",r);
  fclose(in);
  fclose(out);
  return 0;
}
//---------------------------------------------------------------------------
