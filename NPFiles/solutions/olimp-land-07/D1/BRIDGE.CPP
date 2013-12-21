#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE* in=fopen("bridge.in","r");
FILE* out=fopen("bridge.out","w");

long N;
long L;
long** p;
//HYPOT
//MAX

long getbrX(L,long &x1,long &x2)
{
}

long

int main()
{int i,j;
 long x1,y1;
 long x2,y2;
 long ln=0,Ln=0;
 long b=0,B=0;
 long y=0,Y=0;
 fscanf(in,"%f %f",&N,&L);
 p=(long**)calloc(N,sizeof(long*));
 for (i=0;i<N;i++)
  {p[i]=(long*)calloc(2,sizeof(long));
   fscanf(in,"%f %f",&p[i][0],&p[i][1]);
  }
 for (i=0;i<N-1;i++)
  if (p[i][1]>1+p[i][1])
   {
   }
 return 0;
}