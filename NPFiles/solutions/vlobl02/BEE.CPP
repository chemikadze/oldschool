#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int N;
int x[4];
int y[4];
int z[4];
int sum[4];

int main()
{
 int i;
 char s[2];
 int ds;
 int mi;
 scanf("%d", &N);
 for (i=0; i<N; i++)
 {
   scanf("%s %d", s, &ds);
   switch (s[0])
   {
     case 'X':
     case 'x': x[0]+=ds;break;

     case 'Y':
     case 'y': y[0]+=ds;break;

     case 'Z':
     case 'z': z[0]+=ds;break;
     default : return 0;
   }
 }
 y[1]=y[0]+x[0];
 z[1]=z[0]-x[0];
 x[1]=0;

 x[2]=x[0]+y[0];
 z[2]=z[0]+y[0];
 y[2]=0;

 x[3]=x[0]-z[0];
 y[3]=y[0]+z[0];
 z[3]=0;


 for (i=0; i<4; i++)
   sum[i]=abs(x[i])+abs(y[i])+abs(z[i]);

 for (i=mi=0; i<4; i++)
   if (sum[i]<sum[mi])
     mi=i;

 printf("\n");

 printf("%d\n", (x[mi]!=0) + (y[mi]!=0) + (z[mi]!=0));
 if (x[mi]!=0)
   printf("X %d\n", -x[mi]);
 if (y[mi]!=0)
   printf("Y %d\n", -y[mi]);
 if (z[mi]!=0)
   printf("Z %d\n", -z[mi]);
 getch();
 return 0;
}